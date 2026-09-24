(** W2 — Transaction decoder (Ethereum RLP, legacy EIP-155 transaction).

    A hardware wallet receives the bytes it will sign from an untrusted
    host, decodes them, and shows the transaction on its screen; the user
    approves what the screen shows, and the device signs the bytes. The
    property that matters is that the two agree: no two different byte
    strings may show the same screen, otherwise the host can have the user
    approve one transaction and sign another (hidden trailing bytes, a
    non-canonical length, an amount with a leading zero byte, ...).

    Properties proved:
    - [decode_tx_enc]: an accepted payload is exactly the canonical RLP
      encoding of the decoded transaction (so decoding is injective);
    - [show_dec_value]: the decimal amounts on the screen denote the
      big-endian integers of the signed fields;
    - [what_you_see_is_what_you_sign]: two payloads that decode and show the
      same screen are the same bytes. *)

From Stdlib Require Import Arith List Lia Bool.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** Constants. Each one is extracted to a VM integer literal by
    [Extract.v]: a [nat] literal would otherwise extract to a chain of
    successor applications. *)
Definition str_off := 128.         (* 0x80: string header *)
Definition str_long := 184.        (* 0xb8: string with a long length *)
Definition str_long_base := 183.   (* 0xb7: 0xb7 + length of the length *)
Definition list_off := 192.        (* 0xc0: list header *)
Definition list_long := 248.       (* 0xf8: list with a long length *)
Definition list_long_base := 247.  (* 0xf7 *)
Definition short_max := 56.        (* payloads of 0..55 bytes have a short header *)
Definition long_one := 56.         (* header offset for one length byte *)
Definition long_two := 57.         (* header offset for two length bytes *)
Definition byte_base := 256.
Definition max_scalar := 32.       (* integers are at most 256 bits *)
Definition addr_len := 20.
Definition ten := 10.
Definition sixteen := 16.
Definition ascii_zero := 48.       (* '0' *)
Definition ascii_a_off := 87.      (* 'a' - 10 *)

(** * RLP *)

(** [split_n n l] cuts the first [n] elements off [l], or fails if [l] is
    shorter. *)
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

Inductive item : Type :=
| Str (s : list nat)
| Lst (items : list item).

(** Header of a payload of [n] bytes, [off] being [0x80] (string) or
    [0xc0] (list). Payloads of 64 KiB and more are not supported. *)
Definition enc_hdr (off n : nat) : list nat :=
  if n <? short_max then [off + n]
  else if n <? byte_base then [off + long_one; n]
  else [off + long_two; n / byte_base; n mod byte_base].

Fixpoint enc (it : item) : list nat :=
  let fix enc_items (is : list item) : list nat :=
    match is with
    | [] => []
    | i :: is' => enc i ++ enc_items is'
    end in
  match it with
  | Str s =>
      match s with
      | [b] => if b <? str_off then [b] else enc_hdr str_off 1 ++ s
      | _ => enc_hdr str_off (length s) ++ s
      end
  | Lst is => let body := enc_items is in enc_hdr list_off (length body) ++ body
  end.

Fixpoint enc_seq (is : list item) : list nat :=
  match is with
  | [] => []
  | i :: is' => enc i ++ enc_seq is'
  end.

(** Long length of [ll] bytes, in its shortest form: one byte of at least
    56, or two bytes without a leading zero. *)
Definition long_len (ll : nat) (r : list nat) : option (nat * list nat) :=
  if ll =? 1 then
    match r with
    | c :: r' => if short_max <=? c then Some (c, r') else None
    | [] => None
    end
  else if ll =? 2 then
    match r with
    | c1 :: c2 :: r' => if 0 <? c1 then Some (c1 * byte_base + c2, r') else None
    | _ => None
    end
  else None.

(** Strict decoder: every item must be in its canonical encoding (a single
    byte below 0x80 is itself, lengths are minimal), so that the encoding
    of what is decoded is what was read. The fuel bounds the recursion;
    [length l + 1] is enough. *)
Fixpoint dec_seq (fuel : nat) (l : list nat) : option (list item) :=
  match fuel with
  | O => None
  | S f =>
      match l with
      | [] => Some []
      | _ :: _ =>
          match dec_one f l with
          | Some (i, rest) =>
              match dec_seq f rest with
              | Some is => Some (i :: is)
              | None => None
              end
          | None => None
          end
      end
  end
with dec_one (fuel : nat) (l : list nat) : option (item * list nat) :=
  match fuel with
  | O => None
  | S f =>
      match l with
      | [] => None
      | b :: r =>
          if b <? str_off then Some (Str [b], r)
          else if b <? str_long then
            match split_n (b - str_off) r with
            | Some ([c], rest) => if c <? str_off then None else Some (Str [c], rest)
            | Some (s, rest) => Some (Str s, rest)
            | None => None
            end
          else if b <? list_off then
            match long_len (b - str_long_base) r with
            | Some (n, r2) =>
                match split_n n r2 with
                | Some (s, rest) => Some (Str s, rest)
                | None => None
                end
            | None => None
            end
          else if b <? list_long then
            match split_n (b - list_off) r with
            | Some (body, rest) =>
                match dec_seq f body with
                | Some is => Some (Lst is, rest)
                | None => None
                end
            | None => None
            end
          else
            match long_len (b - list_long_base) r with
            | Some (n, r2) =>
                match split_n n r2 with
                | Some (body, rest) =>
                    match dec_seq f body with
                    | Some is => Some (Lst is, rest)
                    | None => None
                    end
                | None => None
                end
            | None => None
            end
      end
  end.

(** * Legacy transaction, EIP-155 signing payload *)

(** [rlp [nonce; gasPrice; gasLimit; to; value; data; chainId; 0; 0]].
    Integers are big-endian byte strings without leading zeros. *)
Record tx := mk_tx {
  nonce : list nat; gas_price : list nat; gas_limit : list nat;
  to : list nat; value : list nat; data : list nat; chain_id : list nat
}.

Definition scalar (s : list nat) : bool :=
  match s with
  | 0 :: _ => false
  | _ => length s <=? max_scalar
  end.

Definition is_nil (s : list nat) : bool :=
  match s with [] => true | _ => false end.

Definition decode_tx (l : list nat) : option tx :=
  match dec_one (S (length l)) l with
  | Some (Lst [Str n; Str gp; Str gl; Str t; Str v; Str d; Str c; Str r; Str s], []) =>
      if scalar n && scalar gp && scalar gl && (length t =? addr_len) && scalar v &&
         scalar c && is_nil r && is_nil s
      then Some (mk_tx n gp gl t v d c)
      else None
  | _ => None
  end.

Definition encode_tx (x : tx) : list nat :=
  enc (Lst [Str (nonce x); Str (gas_price x); Str (gas_limit x); Str (to x);
            Str (value x); Str (data x); Str (chain_id x); Str []; Str []]).

(** * Display *)

(** Divide a big-endian number by ten, [r] being the remainder carried
    from the bytes before: the quotient, same length, and the remainder. *)
Fixpoint divmod10 (r : nat) (l : list nat) : list nat * nat :=
  match l with
  | [] => ([], r)
  | b :: t =>
      let x := r * byte_base + b in
      let (q, r') := divmod10 (x mod ten) t in
      (x / ten :: q, r')
  end.

Fixpoint strip (l : list nat) : list nat :=
  match l with
  | 0 :: t => strip t
  | _ => l
  end.

(** Decimal digits of [l], most significant first, prepended to [acc]. *)
Fixpoint digits_rev (fuel : nat) (l acc : list nat) : list nat :=
  match fuel with
  | O => acc
  | S f =>
      match strip l with
      | [] => acc
      | l' => let (q, d) := divmod10 0 l' in digits_rev f q (d :: acc)
      end
  end.

(** An amount in decimal ASCII. Every byte gives at most three digits. *)
Definition show_dec (l : list nat) : list nat :=
  match digits_rev (3 * length l) l [] with
  | [] => [ascii_zero]
  | ds => map (Nat.add ascii_zero) ds
  end.

Definition hex_digit (d : nat) : nat :=
  if d <? ten then ascii_zero + d else ascii_a_off + d.

(** An address or calldata in lowercase hexadecimal ASCII. *)
Fixpoint hex (l : list nat) : list nat :=
  match l with
  | [] => []
  | b :: t => hex_digit (b / sixteen) :: hex_digit (b mod sixteen) :: hex t
  end.

(** What the screen shows, one line per field. *)
Definition display (x : tx) : list (list nat) :=
  [show_dec (chain_id x); hex (to x); show_dec (value x); show_dec (nonce x);
   show_dec (gas_price x); show_dec (gas_limit x); hex (data x)].

(** Decode the [n]-byte signing payload of the input and show it; an
    empty screen means the payload is rejected. *)
Definition run (n : nat) : list (list nat) :=
  match decode_tx (read_bytes 0 n) with
  | None => []
  | Some x => display x
  end.

(** * Properties *)

(** Closes a goal with a hypothesis [None = Some _] (or another
    constructor clash) once its matches are reduced. *)
Ltac bad := match goal with H : _ = Some _ |- _ => solve [cbn in H; congruence] end.

(** Input bytes are below 256 (the [input_byte] trust assumption). *)
Definition bytes (l : list nat) : Prop := Forall (fun b => b < 256) l.

Lemma bytes_app : forall a b, bytes (a ++ b) <-> bytes a /\ bytes b.
Proof. intros. apply Forall_app. Qed.

Lemma split_n_spec : forall n l a b,
  split_n n l = Some (a, b) -> l = a ++ b /\ length a = n.
Proof.
  induction n as [|n IH]; intros l a b H; cbn in H.
  - injection H as <- <-. auto.
  - destruct l as [|x t]; [discriminate|].
    destruct (split_n n t) as [[a' b']|] eqn:E; [|discriminate].
    injection H as <- <-. destruct (IH _ _ _ E) as [-> <-]. auto.
Qed.

Lemma div_mod_256 : forall b c, c < 256 ->
  (b * 256 + c) / 256 = b /\ (b * 256 + c) mod 256 = c.
Proof.
  intros b c Hc. split.
  - symmetry. apply Nat.div_unique with c; lia.
  - symmetry. apply Nat.mod_unique with b; lia.
Qed.

Lemma enc_lst : forall is,
  enc (Lst is) = enc_hdr list_off (length (enc_seq is)) ++ enc_seq is.
Proof. reflexivity. Qed.

(** Header round trip for a long length. *)
Lemma long_len_enc : forall off b r n r2,
  bytes (b :: r) -> off + short_max <= b ->
  long_len (b - (off + short_max - 1)) r = Some (n, r2) ->
  enc_hdr off n ++ r2 = b :: r.
Proof.
  intros off b r n r2 Hb Hle H.
  inversion Hb as [|? ? Hb0 Hr]; subst.
  unfold long_len, enc_hdr, short_max, byte_base, long_one, long_two in *.
  destruct (b - (off + 56 - 1) =? 1) eqn:E1.
  - apply Nat.eqb_eq in E1.
    destruct r as [|c r']; [bad|]. destruct (56 <=? c) eqn:Ec; [|bad].
    injection H as <- <-. apply Nat.leb_le in Ec. inversion Hr; subst.
    replace (c <? 56) with false by (symmetry; apply Nat.ltb_ge; lia).
    replace (c <? 256) with true by (symmetry; apply Nat.ltb_lt; lia).
    cbn. f_equal. lia.
  - destruct (b - (off + 56 - 1) =? 2) eqn:E2; [|bad]. apply Nat.eqb_eq in E2.
    destruct r as [|c1 [|c2 r']]; try bad. destruct (0 <? c1) eqn:Ec; [|bad].
    injection H as <- <-. apply Nat.ltb_lt in Ec.
    inversion Hr as [|? ? Hc1 Hr']; subst. inversion Hr'; subst.
    replace (c1 * 256 + c2 <? 56) with false by (symmetry; apply Nat.ltb_ge; lia).
    replace (c1 * 256 + c2 <? 256) with false by (symmetry; apply Nat.ltb_ge; lia).
    destruct (div_mod_256 c1 c2) as [-> ->]; [lia|]. cbn. f_equal. lia.
Qed.

(** ** Round trip: what is accepted is the encoding of what was decoded *)

Lemma dec_enc : forall fuel,
  (forall l is, bytes l -> dec_seq fuel l = Some is -> enc_seq is = l) /\
  (forall l i r, bytes l -> dec_one fuel l = Some (i, r) -> enc i ++ r = l).
Proof.
  induction fuel as [|f [IHs IHo]]; (split; [intros l is Hb H | intros l i r Hb H]);
    cbn [dec_seq dec_one] in H; try bad.
  - destruct l as [|x l']; [injection H as <-; reflexivity|].
    destruct (dec_one f (x :: l')) as [[i r]|] eqn:E1; [|bad].
    destruct (dec_seq f r) as [is'|] eqn:E2; [|bad].
    injection H as <-.
    pose proof (IHo _ _ _ Hb E1) as H1.
    rewrite <- H1 in Hb. apply bytes_app in Hb as [_ Hr].
    cbn [enc_seq]. rewrite (IHs _ _ Hr E2). exact H1.
  - destruct l as [|b r0]; [bad|].
    pose proof Hb as Hb'. inversion Hb' as [|? ? Hb0 Hr0]; subst.
    unfold str_off, str_long, list_off, list_long, str_long_base, list_long_base in H.
    destruct (b <? 128) eqn:E0.
    { injection H as <- <-. cbn [enc]. unfold str_off. rewrite E0. reflexivity. }
    apply Nat.ltb_ge in E0.
    destruct (b <? 184) eqn:E1.
    { apply Nat.ltb_lt in E1.
      destruct (split_n (b - 128) r0) as [[s rest]|] eqn:S; [|bad].
      destruct (split_n_spec _ _ _ _ S) as [S1 S2]. subst r0.
      destruct s as [|c [|c' s']].
      - injection H as <- <-. cbn. unfold enc_hdr, str_off, short_max.
        cbn in S2. replace b with 128 by lia. reflexivity.
      - destruct (c <? 128) eqn:Ec; [bad|]. injection H as <- <-.
        cbn in S2. cbn [enc]. unfold str_off. rewrite Ec.
        unfold enc_hdr, short_max. cbn. f_equal. lia.
      - injection H as <- <-. cbn [enc]. unfold enc_hdr, str_off, short_max.
        rewrite S2.
        replace (b - 128 <? 56) with true by (symmetry; apply Nat.ltb_lt; lia).
        cbn [app]. f_equal. lia. }
    apply Nat.ltb_ge in E1.
    destruct (b <? 192) eqn:E2.
    { apply Nat.ltb_lt in E2.
      destruct (long_len (b - 183) r0) as [[n r2]|] eqn:L; [|bad].
      destruct (split_n n r2) as [[s rest]|] eqn:S; [|bad].
      injection H as <- <-.
      destruct (split_n_spec _ _ _ _ S) as [S1 S2]. subst r2.
      pose proof (long_len_enc 128 b r0 n (s ++ rest) Hb ltac:(unfold short_max; lia)
                    ltac:(unfold short_max; replace (128 + 56 - 1) with 183 by lia; exact L)) as HL.
      assert (Hn : 56 <= n).
      { unfold long_len, short_max, byte_base in L.
        destruct (b - 183 =? 1); [destruct r0 as [|c ?]; [bad|];
          destruct (56 <=? c) eqn:Ec; [|bad]; injection L as <- _; apply Nat.leb_le in Ec; lia|].
        destruct (b - 183 =? 2); [|bad]. destruct r0 as [|c1 [|c2 ?]]; try bad.
        destruct (0 <? c1) eqn:Ec; [|bad]. injection L as <- _. apply Nat.ltb_lt in Ec. lia. }
      cbn [enc]. destruct s as [|c [|c' s']]; cbn in S2; try lia;
        rewrite <- app_assoc; rewrite <- S2 in HL; exact HL. }
    apply Nat.ltb_ge in E2.
    destruct (b <? 248) eqn:E3.
    { apply Nat.ltb_lt in E3.
      destruct (split_n (b - 192) r0) as [[body rest]|] eqn:S; [|bad].
      destruct (dec_seq f body) as [is|] eqn:D; [|bad].
      injection H as <- <-.
      destruct (split_n_spec _ _ _ _ S) as [S1 S2]. subst r0.
      apply bytes_app in Hr0 as [Hbody _].
      rewrite enc_lst, (IHs _ _ Hbody D), S2. unfold enc_hdr, list_off, short_max.
      replace (b - 192 <? 56) with true by (symmetry; apply Nat.ltb_lt; lia).
      cbn. f_equal. lia. }
    apply Nat.ltb_ge in E3.
    destruct (long_len (b - 247) r0) as [[n r2]|] eqn:L; [|bad].
    destruct (split_n n r2) as [[body rest]|] eqn:S; [|bad].
    destruct (dec_seq f body) as [is|] eqn:D; [|bad].
    injection H as <- <-.
    destruct (split_n_spec _ _ _ _ S) as [S1 S2]. subst r2.
    pose proof (long_len_enc 192 b r0 n (body ++ rest) Hb ltac:(unfold short_max; lia)
                  ltac:(unfold short_max; replace (192 + 56 - 1) with 247 by lia; exact L)) as HL.
    assert (Hbody : bytes body).
    { rewrite <- HL in Hb. apply bytes_app in Hb as [_ Hb]. apply bytes_app in Hb. tauto. }
    rewrite enc_lst, (IHs _ _ Hbody D), S2, <- app_assoc. exact HL.
Qed.

Lemma bytes_in_seq : forall is s, bytes (enc_seq is) -> In (Str s) is -> bytes s.
Proof.
  induction is as [|i is IH]; intros s Hb Hin; [destruct Hin|].
  cbn [enc_seq] in Hb. apply bytes_app in Hb as [Hi Hr].
  destruct Hin as [-> | Hin]; [|exact (IH _ Hr Hin)].
  cbn [enc] in Hi. destruct s as [|b [|b' s']].
  - constructor.
  - destruct (b <? str_off); [exact Hi|]. apply bytes_app in Hi. tauto.
  - apply bytes_app in Hi. tauto.
Qed.

Lemma scalar_ok : forall s, scalar s = true ->
  match s with 0 :: _ => False | _ => True end.
Proof. intros [|[|x] t] H; cbn in *; auto. discriminate. Qed.

(** What [decode_tx] accepts: the canonical encoding of a transaction
    whose integers have no leading zero. *)
Lemma decode_tx_spec : forall l x, bytes l -> decode_tx l = Some x ->
  encode_tx x = l /\
  Forall (fun s => bytes s /\ match s with 0 :: _ => False | _ => True end)
    [nonce x; gas_price x; gas_limit x; value x; chain_id x] /\
  bytes (to x) /\ bytes (data x).
Proof.
  intros l x Hb H. unfold decode_tx in H.
  destruct (dec_one (S (length l)) l) as [[it rest]|] eqn:D; [|bad].
  pose proof (proj2 (dec_enc _) _ _ _ Hb D) as E.
  repeat match type of H with
  | context [match ?y with _ => _ end] => destruct y eqn:?; try bad
  end.
  subst.
  repeat match goal with Hc : (_ && _) = true |- _ => apply andb_true_iff in Hc as [? ?] end.
  repeat match goal with Hn : is_nil ?r = true |- _ => destruct r; [clear Hn | discriminate Hn] end.
  injection H as <-. rewrite app_nil_r in *.
  pose proof Hb as Hs. rewrite enc_lst in Hs. apply bytes_app in Hs as [_ Hs].
  unfold encode_tx. cbn [nonce gas_price gas_limit to value data chain_id].
  split; [reflexivity|].
  split; [repeat constructor | split];
    first [apply scalar_ok; assumption | apply (bytes_in_seq _ _ Hs); cbn; tauto].
Qed.

Theorem decode_tx_enc : forall l x, bytes l -> decode_tx l = Some x -> encode_tx x = l.
Proof. intros l x Hb H. apply (decode_tx_spec l x Hb H). Qed.

(** ** The screen: decimal amounts *)

Fixpoint be (l : list nat) : nat :=
  match l with
  | [] => 0
  | b :: t => b * 256 ^ length t + be t
  end.

Fixpoint dv (l : list nat) : nat :=
  match l with
  | [] => 0
  | d :: t => d * 10 ^ length t + dv t
  end.

Lemma be_bound : forall l, bytes l -> be l < 256 ^ length l.
Proof.
  induction l as [|b t IH]; intro H; cbn; [lia|].
  inversion H; subst. specialize (IH H3).
  assert (b * 256 ^ length t <= 255 * 256 ^ length t) by (apply Nat.mul_le_mono_r; lia).
  lia.
Qed.

Lemma divmod10_spec : forall l r, bytes l -> r < 10 ->
  let (q, r') := divmod10 r l in
  r * 256 ^ length l + be l = 10 * be q + r' /\ r' < 10 /\
  length q = length l /\ bytes q.
Proof.
  induction l as [|b t IH]; intros r Hb Hr; cbn [divmod10].
  - cbn. repeat split; [lia | lia | constructor].
  - inversion Hb as [|? ? Hb0 Ht]; subst.
    unfold byte_base, ten.
    pose proof (Nat.div_mod_eq (r * 256 + b) 10) as Hx.
    pose proof (Nat.mod_upper_bound (r * 256 + b) 10 ltac:(lia)) as Hm.
    specialize (IH ((r * 256 + b) mod 10) Ht Hm).
    destruct (divmod10 ((r * 256 + b) mod 10) t) as [q r'].
    destruct IH as (H1 & H2 & H3 & H4).
    assert (Hq : (r * 256 + b) / 10 < 256) by (apply Nat.Div0.div_lt_upper_bound; lia).
    cbn [be length]. rewrite H3.
    split; [|split; [lia|split; [reflexivity|constructor; auto]]].
    rewrite Nat.pow_succ_r'. nia.
Qed.

Lemma strip_spec : forall l, bytes l ->
  be (strip l) = be l /\ bytes (strip l) /\
  match strip l with 0 :: _ => False | _ => True end.
Proof.
  induction l as [|b t IH]; intro H; [cbn; auto|].
  inversion H; subst. destruct b as [|b]; cbn [strip].
  - destruct (IH H3) as (-> & ? & ?). cbn. auto.
  - cbn. auto.
Qed.

Lemma digits_rev_spec : forall f l acc, bytes l -> be l < 10 ^ f ->
  Forall (fun d => d < 10) acc ->
  dv (digits_rev f l acc) = be l * 10 ^ length acc + dv acc /\
  Forall (fun d => d < 10) (digits_rev f l acc).
Proof.
  induction f as [|f IH]; intros l acc Hb Hlt Hacc; cbn [digits_rev].
  - cbn in Hlt. split; [nia | exact Hacc].
  - destruct (strip_spec l Hb) as (Hbe & Hbs & _).
    destruct (strip l) as [|b t] eqn:E.
    + cbn in Hbe. split; [nia | exact Hacc].
    + pose proof (divmod10_spec (b :: t) 0 Hbs ltac:(lia)) as Hd.
      destruct (divmod10 0 (b :: t)) as [q d]. destruct Hd as (H1 & H2 & _ & H4).
      rewrite Hbe in H1. cbn [Nat.pow] in Hlt.
      destruct (IH q (d :: acc) H4 ltac:(lia) ltac:(constructor; auto)) as [IH1 IH2].
      split; [|exact IH2].
      rewrite IH1. cbn [dv length]. rewrite Nat.pow_succ_r'. nia.
Qed.

(** The decimal digits shown for an amount denote its value. *)
Theorem show_dec_value : forall l, bytes l ->
  exists ds, show_dec l = map (Nat.add ascii_zero) ds /\
             Forall (fun d => d < 10) ds /\ dv ds = be l.
Proof.
  intros l Hb.
  assert (Hlt : be l < 10 ^ (3 * length l)).
  { pose proof (be_bound l Hb).
    assert (256 ^ length l <= 10 ^ (3 * length l)).
    { rewrite Nat.pow_mul_r. apply Nat.pow_le_mono_l. cbn. lia. }
    lia. }
  destruct (digits_rev_spec (3 * length l) l [] Hb Hlt ltac:(constructor)) as [H1 H2].
  cbn [length dv Nat.pow] in H1. unfold show_dec.
  destruct (digits_rev (3 * length l) l []) as [|d ds] eqn:E.
  - exists [0]. repeat split; [repeat constructor | cbn in *; lia].
  - exists (d :: ds). repeat split; [exact H2 | lia].
Qed.

(** ** Injectivity of the screen *)

Lemma pos_digit_inj : forall a b c d P, c < P -> d < P ->
  a * P + c = b * P + d -> a = b /\ c = d.
Proof.
  intros a b c d P Hc Hd H.
  assert (a = b).
  { destruct (Nat.lt_trichotomy a b) as [Hab | [Hab | Hab]]; [|exact Hab|]; exfalso.
    - assert (a * P + P <= b * P) by nia. lia.
    - assert (b * P + P <= a * P) by nia. lia. }
  subst. split; [reflexivity | lia].
Qed.

Lemma be_inj_len : forall a b, bytes a -> bytes b -> length a = length b ->
  be a = be b -> a = b.
Proof.
  induction a as [|x a IH]; intros [|y b] Ha Hb Hl H; try discriminate; [reflexivity|].
  inversion Ha; inversion Hb; subst. cbn in Hl, H. injection Hl as Hl.
  rewrite Hl in H.
  assert (Ha' : be a < 256 ^ length b) by (rewrite <- Hl; apply be_bound; assumption).
  destruct (pos_digit_inj _ _ _ _ _ Ha' (be_bound b ltac:(assumption)) H) as [-> Hbe].
  f_equal. apply IH; auto.
Qed.

Lemma be_lower : forall b t, 0 < b -> 256 ^ length t <= be (b :: t).
Proof. intros b t H. cbn. nia. Qed.

(** Integers without a leading zero byte are determined by their value. *)
Lemma be_canonical_inj : forall a b, bytes a -> bytes b ->
  match a with 0 :: _ => False | _ => True end ->
  match b with 0 :: _ => False | _ => True end ->
  be a = be b -> a = b.
Proof.
  intros a b Ha Hb Na Nb H.
  destruct (Nat.lt_trichotomy (length a) (length b)) as [Hl | [Hl | Hl]].
  - exfalso. destruct b as [|y b]; [cbn in Hl; lia|].
    destruct y as [|y]; [contradiction|].
    pose proof (be_lower (S y) b ltac:(lia)). pose proof (be_bound a Ha).
    assert (256 ^ length a <= 256 ^ length b) by (apply Nat.pow_le_mono_r; cbn in Hl; lia).
    lia.
  - apply be_inj_len; assumption.
  - exfalso. destruct a as [|x a]; [cbn in Hl; lia|].
    destruct x as [|x]; [contradiction|].
    pose proof (be_lower (S x) a ltac:(lia)). pose proof (be_bound b Hb).
    assert (256 ^ length b <= 256 ^ length a) by (apply Nat.pow_le_mono_r; cbn in Hl; lia).
    lia.
Qed.

Lemma map_add_inj : forall k a b, map (Nat.add k) a = map (Nat.add k) b -> a = b.
Proof.
  intro k. induction a as [|x a IH]; intros [|y b] H; cbn in H; try discriminate; auto.
  injection H as H1 H2. f_equal; [lia | auto].
Qed.

Lemma show_dec_inj : forall a b, bytes a -> bytes b ->
  match a with 0 :: _ => False | _ => True end ->
  match b with 0 :: _ => False | _ => True end ->
  show_dec a = show_dec b -> a = b.
Proof.
  intros a b Ha Hb Na Nb H.
  destruct (show_dec_value a Ha) as (da & Ea & _ & Va).
  destruct (show_dec_value b Hb) as (db & Eb & _ & Vb).
  rewrite Ea, Eb in H.
  apply map_add_inj in H.
  apply be_canonical_inj; auto. congruence.
Qed.

Lemma hex_digit_inj : forall a b, a < 16 -> b < 16 -> hex_digit a = hex_digit b -> a = b.
Proof.
  intros a b Ha Hb H. unfold hex_digit, ten, ascii_zero, ascii_a_off in H.
  destruct (a <? 10) eqn:E1, (b <? 10) eqn:E2;
    apply Nat.ltb_lt in E1 + apply Nat.ltb_ge in E1;
    apply Nat.ltb_lt in E2 + apply Nat.ltb_ge in E2; lia.
Qed.

Lemma hex_inj : forall a b, bytes a -> bytes b -> hex a = hex b -> a = b.
Proof.
  induction a as [|x a IH]; intros [|y b] Ha Hb H; try discriminate; [reflexivity|].
  inversion Ha; inversion Hb; subst. cbn [hex] in H.
  pose proof (f_equal (hd 0) H) as Q1. pose proof (f_equal (fun l => hd 0 (tl l)) H) as Q2.
  pose proof (f_equal (fun l => tl (tl l)) H) as Q3. cbn [hd tl] in Q1, Q2, Q3.
  unfold sixteen in *.
  apply hex_digit_inj in Q1; [|apply Nat.Div0.div_lt_upper_bound; lia ..].
  apply hex_digit_inj in Q2; [|apply Nat.mod_upper_bound; lia ..].
  f_equal; [|apply IH; auto].
  rewrite (Nat.div_mod_eq x 16), (Nat.div_mod_eq y 16). lia.
Qed.

(** What is displayed is what is signed: two payloads that the device
    accepts and that show the same screen are the same bytes. *)
Theorem what_you_see_is_what_you_sign : forall l1 l2 x1 x2,
  bytes l1 -> bytes l2 ->
  decode_tx l1 = Some x1 -> decode_tx l2 = Some x2 ->
  display x1 = display x2 -> l1 = l2.
Proof.
  intros l1 l2 x1 x2 Hb1 Hb2 D1 D2 Hd.
  destruct (decode_tx_spec _ _ Hb1 D1) as (E1 & F1 & T1 & A1).
  destruct (decode_tx_spec _ _ Hb2 D2) as (E2 & F2 & T2 & A2).
  rewrite <- E1, <- E2. f_equal.
  destruct x1 as [n1 gp1 gl1 t1 v1 d1 c1], x2 as [n2 gp2 gl2 t2 v2 d2 c2].
  unfold display in Hd; cbn in *.
  injection Hd as Hc Ht Hv Hn Hgp Hgl Hdat.
  repeat match goal with H : Forall _ (_ :: _) |- _ => inversion H; subst; clear H end.
  repeat match goal with H : _ /\ _ |- _ => destruct H end.
  repeat f_equal;
    first [ apply show_dec_inj; assumption | apply hex_inj; assumption ].
Qed.
