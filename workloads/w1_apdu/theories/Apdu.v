(** W1 — APDU and BER-TLV parser (ISO 7816-4, ISO 8825 / X.690).

    A secure element receives command APDUs from an untrusted reader. The
    command's data field often carries a BER-TLV structure (an EMV record,
    a card-verifiable certificate, an FCI template), which the card parses
    before acting on it. A bug there is a bug on untrusted input: a length
    field believed without checking, a nested template that runs past its
    parent, two encodings accepted for the same object.

    Properties proved:
    - Totality: [parse_apdu] and [dec_seq] are total functions; every input
      gets a verdict. The decoder's fuel is [length + 1], which never runs
      out ([dec_seq_fuel]): no well-formed input is rejected for lack of
      fuel.
    - No out-of-bounds access: the parsers work on the list of the [n]
      bytes read, never on indices; a length field that runs past its
      parent is rejected by [split_n], not read.
    - Round trip [encode (decode x) = x] ([run_roundtrip]): an accepted
      APDU is exactly the encoding of what was parsed. The decoder is
      strict (DER-style minimal lengths), so no two byte strings parse to
      the same command. And [decode (encode t) = t] for every well-formed
      tree ([dec_seq_enc]). *)

From Stdlib Require Import Arith List Lia Bool.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** Constants. Each one is extracted to a VM integer literal by
    [Extract.v]: a [nat] literal would otherwise extract to a chain of
    successor applications. *)
Definition tag_mask := 31.         (* 0x1F: low five bits of a tag byte *)
Definition constructed_bit := 32.  (* 0x20: constructed encoding *)
Definition high_bit := 128.        (* 0x80 *)
Definition len_one := 129.         (* 0x81: one length byte follows *)
Definition len_two := 130.         (* 0x82: two length bytes follow *)
Definition byte_base := 256.

(** * Byte-level pieces *)

(** [split_n n l] cuts the first [n] elements off [l], or fails if [l] is
    shorter: this is where a length field that runs past its parent is
    caught. *)
Fixpoint split_n (n : nat) (l : list nat) : option (list nat * list nat) :=
  match n with
  | O => Some ([], l)
  | S n' =>
      match l with
      | [] => None
      | x :: t =>
          match split_n n' t with
          | Some (a, b) => Some (x :: a, b)
          | None => None
          end
      end
  end.

(** Tags of one or two bytes: low five bits all set in the first byte
    mean one more byte follows, which must not have its high bit set
    (tags of three bytes and more are not supported). The tag number is
    [b0 * 256 + b1]. *)
Definition parse_tag (l : list nat) : option (nat * list nat) :=
  match l with
  | [] => None
  | b :: r =>
      if Nat.land b tag_mask =? tag_mask then
        match r with
        | c :: r' => if c <? high_bit then Some (b * byte_base + c, r') else None
        | [] => None
        end
      else Some (b, r)
  end.

Definition enc_tag (t : nat) : list nat :=
  if t <? byte_base then [t] else [t / byte_base; t mod byte_base].

(** Definite lengths in their shortest form: [0..127] in one byte,
    [128..255] as [0x81 n], [256..65535] as [0x82 hi lo]. The indefinite
    form ([0x80]) and non-minimal forms are rejected. *)
Definition parse_len (l : list nat) : option (nat * list nat) :=
  match l with
  | [] => None
  | b :: r =>
      if b <? high_bit then Some (b, r)
      else if b =? len_one then
        match r with
        | c :: r' => if high_bit <=? c then Some (c, r') else None
        | [] => None
        end
      else if b =? len_two then
        match r with
        | c1 :: c2 :: r' => if 0 <? c1 then Some (c1 * byte_base + c2, r') else None
        | _ => None
        end
      else None
  end.

Definition enc_len (n : nat) : list nat :=
  if n <? high_bit then [n]
  else if n <? byte_base then [len_one; n]
  else [len_two; n / byte_base; n mod byte_base].

(** * BER-TLV trees *)

Inductive tlv : Type :=
| Prim (tag : nat) (value : list nat)
| Constr (tag : nat) (children : list tlv).

(** Bit 6 of the first tag byte says whether the value is itself a
    sequence of TLVs. *)
Definition first_byte (t : nat) : nat :=
  if t <? byte_base then t else t / byte_base.

Definition constructed (t : nat) : bool :=
  Nat.land (first_byte t) constructed_bit =? constructed_bit.

(** Decoder. [dec_seq] reads a sequence of TLVs up to the end of its
    input; [dec_one] reads one TLV and returns what follows it. The fuel
    bounds the recursion; [length l + 1] is enough ([dec_seq_fuel]). *)
Fixpoint dec_seq (fuel : nat) (l : list nat) : option (list tlv) :=
  match fuel with
  | O => None
  | S f =>
      match l with
      | [] => Some []
      | _ :: _ =>
          match dec_one f l with
          | Some (t, rest) =>
              match dec_seq f rest with
              | Some ts => Some (t :: ts)
              | None => None
              end
          | None => None
          end
      end
  end
with dec_one (fuel : nat) (l : list nat) : option (tlv * list nat) :=
  match fuel with
  | O => None
  | S f =>
      match parse_tag l with
      | None => None
      | Some (tg, r1) =>
          match parse_len r1 with
          | None => None
          | Some (n, r2) =>
              match split_n n r2 with
              | None => None
              | Some (v, rest) =>
                  if constructed tg then
                    match dec_seq f v with
                    | Some ks => Some (Constr tg ks, rest)
                    | None => None
                    end
                  else Some (Prim tg v, rest)
              end
          end
      end
  end.

Fixpoint enc (t : tlv) : list nat :=
  let fix enc_kids (ks : list tlv) : list nat :=
    match ks with
    | [] => []
    | k :: ks' => enc k ++ enc_kids ks'
    end in
  match t with
  | Prim tg v => enc_tag tg ++ enc_len (length v) ++ v
  | Constr tg ks => let body := enc_kids ks in enc_tag tg ++ enc_len (length body) ++ body
  end.

Fixpoint enc_seq (ts : list tlv) : list nat :=
  match ts with
  | [] => []
  | t :: ts' => enc t ++ enc_seq ts'
  end.

(** * Command APDUs (short form) *)

(** [CLA INS P1 P2], then case 1: nothing; case 2: [Le]; case 3:
    [Lc data(Lc)]; case 4: [Lc data(Lc) Le], with [Lc] in [1..255]. *)
Record apdu := mk_apdu {
  cla : nat; ins : nat; p1 : nat; p2 : nat;
  data : list nat;
  le : option nat
}.

Definition parse_apdu (l : list nat) : option apdu :=
  match l with
  | c :: i :: a :: b :: body =>
      match body with
      | [] => Some (mk_apdu c i a b [] None)
      | [e] => Some (mk_apdu c i a b [] (Some e))
      | lc :: rest =>
          if lc =? 0 then None
          else
            match split_n lc rest with
            | Some (d, []) => Some (mk_apdu c i a b d None)
            | Some (d, [e]) => Some (mk_apdu c i a b d (Some e))
            | _ => None
            end
      end
  | _ => None
  end.

Definition enc_apdu (x : apdu) : list nat :=
  [cla x; ins x; p1 x; p2 x] ++
  match data x with [] => [] | d => length d :: d end ++
  match le x with None => [] | Some e => [e] end.

(** * Benchmark entry point *)

(** Pre-order summary of a tree: for each node its tag, its depth, and
    the length of its value (primitive) or its number of children
    (constructed). *)
Fixpoint summ (d : nat) (t : tlv) (acc : list nat) : list nat :=
  match t with
  | Prim tg v => tg :: d :: length v :: acc
  | Constr tg ks =>
      tg :: d :: length ks ::
        (fix go (ks : list tlv) : list nat :=
           match ks with
           | [] => acc
           | k :: ks' => summ (S d) k (go ks')
           end) ks
  end.

(** Parse the [n]-byte command APDU of the input, then the BER-TLV
    structure of its data field. Output: [0; INS] followed by the summary
    of the tree, or [1] (malformed APDU), or [2] (malformed TLV). *)
Definition run (n : nat) : list nat :=
  match parse_apdu (read_bytes 0 n) with
  | None => [1]
  | Some x =>
      match dec_seq (S (length (data x))) (data x) with
      | None => [2]
      | Some ts => 0 :: ins x :: fold_right (summ 0) [] ts
      end
  end.

(** * Properties *)

(** Closes a goal with a hypothesis [None = Some _] (or another
    constructor clash) once its matches are reduced. *)
Ltac bad := match goal with H : _ = Some _ |- _ => solve [cbn in H; congruence] end.

(** Input bytes are below 256 (the [input_byte] trust assumption). *)
Definition bytes (l : list nat) : Prop := Forall (fun b => b < 256) l.

Lemma bytes_app : forall a b, bytes (a ++ b) <-> bytes a /\ bytes b.
Proof. intros. apply Forall_app. Qed.

Lemma read_bytes_length : forall n p, length (read_bytes p n) = n.
Proof. induction n; intro p; cbn; [reflexivity|]. rewrite IHn. reflexivity. Qed.

Lemma split_n_spec : forall n l a b,
  split_n n l = Some (a, b) -> l = a ++ b /\ length a = n.
Proof.
  induction n as [|n IH]; intros l a b H; cbn in H.
  - injection H as <- <-. auto.
  - destruct l as [|x t]; [bad|].
    destruct (split_n n t) as [[a' b']|] eqn:E; [|bad].
    injection H as <- <-. destruct (IH _ _ _ E) as [-> <-]. auto.
Qed.

Lemma split_n_app : forall a b, split_n (length a) (a ++ b) = Some (a, b).
Proof. induction a as [|x a IH]; intro b; cbn; [reflexivity|]. rewrite IH. reflexivity. Qed.

Lemma div_mod_256 : forall b c, c < 256 ->
  (b * 256 + c) / 256 = b /\ (b * 256 + c) mod 256 = c.
Proof.
  intros b c Hc. split.
  - symmetry. apply Nat.div_unique with c; lia.
  - symmetry. apply Nat.mod_unique with b; lia.
Qed.

Lemma parse_tag_enc : forall l tg r,
  bytes l -> parse_tag l = Some (tg, r) -> enc_tag tg ++ r = l.
Proof.
  intros [|b r0] tg r Hb H; [bad|]. unfold parse_tag in H.
  inversion Hb as [|? ? Hb0 Hr0]; subst.
  unfold enc_tag, byte_base, high_bit, tag_mask in *.
  destruct (Nat.land b 31 =? 31) eqn:E.
  - destruct r0 as [|c r1]; [bad|].
    destruct (c <? 128) eqn:Ec; [|bad].
    injection H as <- <-. apply Nat.ltb_lt in Ec.
    assert (b <> 0) by (intros ->; cbv in E; discriminate E).
    destruct (div_mod_256 b c) as [-> ->]; [lia|].
    replace (b * 256 + c <? 256) with false by (symmetry; apply Nat.ltb_ge; lia).
    reflexivity.
  - injection H as <- <-. replace (b <? 256) with true by (symmetry; apply Nat.ltb_lt; lia).
    reflexivity.
Qed.

Lemma parse_len_enc : forall l n r,
  bytes l -> parse_len l = Some (n, r) -> enc_len n ++ r = l.
Proof.
  intros [|b r0] n r Hb H; [bad|]. unfold parse_len in H.
  inversion Hb as [|? ? Hb0 Hr0]; subst.
  unfold enc_len, byte_base, high_bit, len_one, len_two in *.
  destruct (b <? 128) eqn:E0.
  - injection H as <- <-. rewrite E0. reflexivity.
  - destruct (b =? 129) eqn:E1.
    + apply Nat.eqb_eq in E1. subst.
      destruct r0 as [|c r1]; [bad|].
      destruct (128 <=? c) eqn:Ec; [|bad].
      injection H as <- <-. apply Nat.leb_le in Ec. inversion Hr0; subst.
      replace (c <? 128) with false by (symmetry; apply Nat.ltb_ge; lia).
      replace (c <? 256) with true by (symmetry; apply Nat.ltb_lt; lia).
      reflexivity.
    + destruct (b =? 130) eqn:E2; [|bad].
      apply Nat.eqb_eq in E2. subst.
      destruct r0 as [|c1 [|c2 r1]]; try bad.
      destruct (0 <? c1) eqn:Ec; [|bad].
      injection H as <- <-. apply Nat.ltb_lt in Ec.
      inversion Hr0 as [|? ? Hc1 Hr1]; subst. inversion Hr1; subst.
      replace (c1 * 256 + c2 <? 128) with false by (symmetry; apply Nat.ltb_ge; lia).
      replace (c1 * 256 + c2 <? 256) with false by (symmetry; apply Nat.ltb_ge; lia).
      destruct (div_mod_256 c1 c2) as [-> ->]; [lia|]. reflexivity.
Qed.

Lemma enc_constr : forall tg ks,
  enc (Constr tg ks) = enc_tag tg ++ enc_len (length (enc_seq ks)) ++ enc_seq ks.
Proof. reflexivity. Qed.

(** ** Round trip: what is accepted is the encoding of what was parsed *)

Lemma dec_enc : forall fuel,
  (forall l ts, bytes l -> dec_seq fuel l = Some ts -> enc_seq ts = l) /\
  (forall l t r, bytes l -> dec_one fuel l = Some (t, r) -> enc t ++ r = l).
Proof.
  induction fuel as [|f [IHs IHo]]; (split; [intros l ts Hb H | intros l t r Hb H]);
    cbn [dec_seq dec_one] in H; try bad.
  - destruct l as [|x l']; [injection H as <-; reflexivity|].
    destruct (dec_one f (x :: l')) as [[t r]|] eqn:E1; [|bad].
    destruct (dec_seq f r) as [ts'|] eqn:E2; [|bad].
    injection H as <-.
    pose proof (IHo _ _ _ Hb E1) as H1.
    rewrite <- H1 in Hb. apply bytes_app in Hb as [_ Hr].
    cbn [enc_seq]. rewrite (IHs _ _ Hr E2). exact H1.
  - destruct (parse_tag l) as [[tg r1]|] eqn:E1; [|bad].
    destruct (parse_len r1) as [[n r2]|] eqn:E2; [|bad].
    destruct (split_n n r2) as [[v rest]|] eqn:E3; [|bad].
    pose proof (parse_tag_enc _ _ _ Hb E1) as H1.
    assert (Hb1 : bytes r1) by (rewrite <- H1 in Hb; apply bytes_app in Hb; tauto).
    pose proof (parse_len_enc _ _ _ Hb1 E2) as H2.
    assert (Hb2 : bytes r2) by (rewrite <- H2 in Hb1; apply bytes_app in Hb1; tauto).
    destruct (split_n_spec _ _ _ _ E3) as [H3 H4].
    assert (Hbv : bytes v) by (rewrite H3 in Hb2; apply bytes_app in Hb2; tauto).
    destruct (constructed tg).
    + destruct (dec_seq f v) as [ks|] eqn:E4; [|bad].
      injection H as <- <-.
      rewrite enc_constr, (IHs _ _ Hbv E4), H4.
      subst. rewrite <- !app_assoc. reflexivity.
    + injection H as <- <-. cbn [enc]. rewrite H4.
      subst. rewrite <- !app_assoc. reflexivity.
Qed.

Lemma parse_apdu_enc : forall l x, parse_apdu l = Some x -> enc_apdu x = l.
Proof.
  intros l x H.
  destruct l as [|c [|i [|a [|b body]]]]; try bad. cbn in H.
  destruct body as [|lc [|r0 rest]].
  - injection H as <-. reflexivity.
  - injection H as <-. reflexivity.
  - destruct (lc =? 0) eqn:E; [bad|]. apply Nat.eqb_neq in E.
    destruct (split_n lc (r0 :: rest)) as [[d [|e [|e' t]]]|] eqn:S; try bad;
      injection H as <-; destruct (split_n_spec _ _ _ _ S) as [S1 S2];
      (destruct d as [|y d]; [cbn in S2; lia|]);
      unfold enc_apdu; cbn [cla ins p1 p2 data le]; rewrite S2, S1;
      cbn; rewrite ?app_nil_r; reflexivity.
Qed.

Lemma bytes_data : forall x, bytes (enc_apdu x) -> bytes (data x).
Proof.
  intros x H. unfold enc_apdu in H. apply bytes_app in H as [_ H].
  apply bytes_app in H as [H _]. destruct (data x) as [|y d]; [constructor|].
  inversion H; assumption.
Qed.

(** The benchmark's parse is a round trip: an accepted APDU is exactly
    the encoding of the parsed command, and its data field exactly the
    encoding of the parsed trees. *)
Theorem run_roundtrip : forall l x ts,
  bytes l ->
  parse_apdu l = Some x ->
  dec_seq (S (length (data x))) (data x) = Some ts ->
  enc_apdu x = l /\ enc_seq ts = data x.
Proof.
  intros l x ts Hb Hx Hts. pose proof (parse_apdu_enc _ _ Hx) as E.
  split; [exact E|].
  apply (proj1 (dec_enc (S (length (data x)))) _ _); [|exact Hts].
  apply bytes_data. rewrite E. exact Hb.
Qed.

(** Two command byte strings that parse to the same APDU are equal: no
    alternative encoding of a command is accepted. *)
Corollary parse_apdu_injective : forall l1 l2 x,
  parse_apdu l1 = Some x -> parse_apdu l2 = Some x -> l1 = l2.
Proof.
  intros l1 l2 x H1 H2.
  rewrite <- (parse_apdu_enc _ _ H1), <- (parse_apdu_enc _ _ H2). reflexivity.
Qed.

(** ** The other direction: well-formed trees decode, and the fuel is
    enough *)

(** A tree is well formed when its tags are valid one- or two-byte tags
    whose constructed bit matches the constructor, and every value fits
    the length forms. *)
Definition tag_ok (t : nat) : Prop :=
  (t < 256 /\ Nat.land t tag_mask <> tag_mask) \/
  (exists b c, t = b * 256 + c /\ b < 256 /\ c < 128 /\ Nat.land b tag_mask = tag_mask).

Fixpoint wf (t : tlv) : Prop :=
  match t with
  | Prim tg v => tag_ok tg /\ constructed tg = false /\ bytes v /\ length v < 256 * 256
  | Constr tg ks =>
      tag_ok tg /\ constructed tg = true /\ length (enc_seq ks) < 256 * 256 /\
      (fix wfs (ks : list tlv) : Prop :=
         match ks with [] => True | k :: ks' => wf k /\ wfs ks' end) ks
  end.

Fixpoint wf_seq (ts : list tlv) : Prop :=
  match ts with
  | [] => True
  | t :: ts' => wf t /\ wf_seq ts'
  end.

Lemma wf_constr : forall tg ks,
  wf (Constr tg ks) <->
  tag_ok tg /\ constructed tg = true /\ length (enc_seq ks) < 256 * 256 /\ wf_seq ks.
Proof. reflexivity. Qed.

Lemma parse_tag_ok : forall t r, tag_ok t -> parse_tag (enc_tag t ++ r) = Some (t, r).
Proof.
  intros t r [[Ht Hm] | (b & c & -> & Hb & Hc & Hm)]; unfold enc_tag.
  - replace (t <? byte_base) with true by (symmetry; apply Nat.ltb_lt; unfold byte_base; lia).
    cbn [app parse_tag]. apply Nat.eqb_neq in Hm. rewrite Hm. reflexivity.
  - assert (b <> 0) by (intros ->; cbv in Hm; discriminate Hm).
    unfold byte_base.
    replace (b * 256 + c <? 256) with false by (symmetry; apply Nat.ltb_ge; lia).
    destruct (div_mod_256 b c) as [-> ->]; [lia|]. cbn [app parse_tag].
    rewrite Hm, Nat.eqb_refl. unfold high_bit, byte_base.
    replace (c <? 128) with true by (symmetry; apply Nat.ltb_lt; exact Hc).
    reflexivity.
Qed.

Lemma parse_len_ok : forall n r, n < 256 * 256 -> parse_len (enc_len n ++ r) = Some (n, r).
Proof.
  intros n r Hn. unfold enc_len.
  destruct (n <? high_bit) eqn:E0; [cbn [app parse_len]; rewrite E0; reflexivity|].
  unfold high_bit in E0. apply Nat.ltb_ge in E0.
  destruct (n <? byte_base) eqn:E1; cbn [app parse_len];
    unfold high_bit, byte_base, len_one, len_two in *.
  - replace (129 <? 128) with false by reflexivity. rewrite Nat.eqb_refl.
    replace (128 <=? n) with true by (symmetry; apply Nat.leb_le; lia). reflexivity.
  - apply Nat.ltb_ge in E1.
    replace (130 <? 128) with false by reflexivity.
    replace (130 =? 129) with false by reflexivity. rewrite Nat.eqb_refl.
    replace (0 <? n / 256) with true
      by (symmetry; apply Nat.ltb_lt; apply Nat.div_str_pos; lia).
    rewrite (Nat.mul_comm (n / 256)), <- Nat.div_mod_eq. reflexivity.
Qed.

Lemma enc_tag_length : forall t, length (enc_tag t) >= 1.
Proof. intro t. unfold enc_tag. destruct (t <? byte_base); cbn; lia. Qed.

Lemma enc_len_length : forall n, length (enc_len n) >= 1.
Proof.
  intro n. unfold enc_len. destruct (n <? high_bit), (n <? byte_base); cbn; lia.
Qed.

Lemma enc_nonempty : forall t, length (enc t) >= 2.
Proof.
  intros [tg v | tg ks]; [cbn [enc] | rewrite enc_constr];
    rewrite !length_app; unfold enc_tag, enc_len;
    repeat match goal with |- context [if ?b then _ else _] => destruct b end;
    cbn [length]; lia.
Qed.

(** Decoding the encoding of well-formed trees gives them back, with any
    fuel above the length of the input. *)
Lemma enc_dec : forall fuel,
  (forall ts, wf_seq ts -> length (enc_seq ts) < fuel -> dec_seq fuel (enc_seq ts) = Some ts) /\
  (forall t r, wf t -> length (enc t) <= fuel -> dec_one fuel (enc t ++ r) = Some (t, r)).
Proof.
  induction fuel as [|f [IHs IHo]]; split.
  - intros ts _ H. lia.
  - intros t r _ H. pose proof (enc_nonempty t). lia.
  - intros [|t ts] Hwf Hlen; [reflexivity|].
    destruct Hwf as [Ht Hts]. cbn [enc_seq] in *. rewrite length_app in Hlen.
    pose proof (enc_nonempty t) as Hne.
    cbn [dec_seq].
    destruct (enc t ++ enc_seq ts) as [|y l] eqn:E;
      [destruct (enc t); cbn in Hne; [lia|discriminate]|].
    rewrite <- E, IHo by (auto; lia).
    rewrite IHs by (auto; lia). reflexivity.
  - intros [tg v | tg ks] r Hwf Hlen; cbn [dec_one].
    + destruct Hwf as (Htag & Hc & _ & Hv).
      cbn [enc]. rewrite <- !app_assoc, parse_tag_ok by exact Htag.
      rewrite parse_len_ok by exact Hv. rewrite split_n_app, Hc. reflexivity.
    + apply wf_constr in Hwf as (Htag & Hc & Hv & Hks).
      rewrite enc_constr in *. rewrite <- !app_assoc, parse_tag_ok by exact Htag.
      rewrite parse_len_ok by exact Hv. rewrite split_n_app, Hc.
      rewrite !length_app in Hlen.
      pose proof (enc_tag_length tg). pose proof (enc_len_length (length (enc_seq ks))).
      rewrite IHs by (auto; lia).
      reflexivity.
Qed.

Theorem dec_seq_enc : forall ts, wf_seq ts ->
  dec_seq (S (length (enc_seq ts))) (enc_seq ts) = Some ts.
Proof. intros ts H. apply (proj1 (enc_dec _)); auto. Qed.

Lemma parse_tag_wf : forall l tg r,
  bytes l -> parse_tag l = Some (tg, r) -> tag_ok tg.
Proof.
  intros [|b r0] tg r Hb H; [bad|]. unfold parse_tag in H.
  inversion Hb as [|? ? Hb0 Hr0]; subst.
  destruct (Nat.land b tag_mask =? tag_mask) eqn:E.
  - destruct r0 as [|c r1]; [bad|].
    destruct (c <? high_bit) eqn:Ec; [|bad].
    injection H as <- <-. apply Nat.ltb_lt in Ec. apply Nat.eqb_eq in E.
    right. exists b, c. unfold byte_base, high_bit in *. auto.
  - injection H as <- <-. apply Nat.eqb_neq in E. left. auto.
Qed.

Lemma parse_len_bound : forall l n r,
  bytes l -> parse_len l = Some (n, r) -> n < 256 * 256.
Proof.
  intros [|b r0] n r Hb H; [bad|]. unfold parse_len in H.
  inversion Hb as [|? ? Hb0 Hr0]; subst.
  destruct (b <? high_bit) eqn:E0; [injection H as <- <-; lia|].
  destruct (b =? len_one) eqn:E1.
  - destruct r0 as [|c r1]; [bad|]. destruct (high_bit <=? c); [|bad].
    injection H as <- <-. inversion Hr0; lia.
  - destruct (b =? len_two); [|bad].
    destruct r0 as [|c1 [|c2 r1]]; try bad. destruct (0 <? c1); [|bad].
    injection H as <- <-. inversion Hr0 as [|? ? H1 H2]; inversion H2; unfold byte_base; nia.
Qed.

(** Every tree the decoder returns is well formed. *)
Lemma dec_wf : forall fuel,
  (forall l ts, bytes l -> dec_seq fuel l = Some ts -> wf_seq ts) /\
  (forall l t r, bytes l -> dec_one fuel l = Some (t, r) -> wf t).
Proof.
  induction fuel as [|f [IHs IHo]]; (split; [intros l ts Hb H | intros l t r Hb H]);
    cbn [dec_seq dec_one] in H; try bad.
  - destruct l as [|x l']; [injection H as <-; exact I|].
    destruct (dec_one f (x :: l')) as [[t r]|] eqn:E1; [|bad].
    destruct (dec_seq f r) as [ts'|] eqn:E2; [|bad].
    injection H as <-.
    pose proof (proj2 (dec_enc f) _ _ _ Hb E1) as H1.
    split; [exact (IHo _ _ _ Hb E1)|].
    rewrite <- H1 in Hb. apply bytes_app in Hb as [_ Hr]. exact (IHs _ _ Hr E2).
  - destruct (parse_tag l) as [[tg r1]|] eqn:E1; [|bad].
    destruct (parse_len r1) as [[n r2]|] eqn:E2; [|bad].
    destruct (split_n n r2) as [[v rest]|] eqn:E3; [|bad].
    pose proof (parse_tag_enc _ _ _ Hb E1) as H1.
    pose proof (parse_tag_wf _ _ _ Hb E1) as Htag.
    assert (Hb1 : bytes r1) by (rewrite <- H1 in Hb; apply bytes_app in Hb; tauto).
    pose proof (parse_len_enc _ _ _ Hb1 E2) as H2.
    pose proof (parse_len_bound _ _ _ Hb1 E2) as Hn.
    assert (Hb2 : bytes r2) by (rewrite <- H2 in Hb1; apply bytes_app in Hb1; tauto).
    destruct (split_n_spec _ _ _ _ E3) as [H3 H4].
    assert (Hbv : bytes v) by (rewrite H3 in Hb2; apply bytes_app in Hb2; tauto).
    destruct (constructed tg) eqn:Hc.
    + destruct (dec_seq f v) as [ks|] eqn:E4; [|bad].
      injection H as <- <-. apply wf_constr.
      rewrite (proj1 (dec_enc f) _ _ Hbv E4). repeat split; auto; [lia|].
      exact (IHs _ _ Hbv E4).
    + injection H as <- <-. cbn [wf]. repeat split; auto. lia.
Qed.

(** The fuel of [run] never runs out: whenever some fuel accepts the
    data field, [length + 1] accepts it too, with the same result. So
    the decoder rejects an input only because it is malformed. *)
Theorem dec_seq_fuel : forall fuel l ts, bytes l ->
  dec_seq fuel l = Some ts -> dec_seq (S (length l)) l = Some ts.
Proof.
  intros fuel l ts Hb H.
  pose proof (proj1 (dec_enc fuel) l ts Hb H) as E.
  pose proof (proj1 (dec_wf fuel) l ts Hb H) as Hwf.
  subst l. apply dec_seq_enc. exact Hwf.
Qed.
