(** W6 — COBS stream framing (Consistent Overhead Byte Stuffing).

    COBS removes every zero byte from a frame so that zero can delimit
    frames on a serial link. The frame is cut at its zeros into pieces;
    each piece is sent as blocks [code, data...] where [code - 1] is the
    number of data bytes and a code below 255 stands for "data, then a
    zero". A code of 255 carries 254 data bytes and no zero, so long runs
    without zeros cost one byte per 254.

    Properties proved: the encoder never emits a zero, and decoding an
    encoded frame gives the frame back. A framing bug is a desynchronised
    link, or worse, a buffer overrun in the decoder of the other side. *)

From Stdlib Require Import Arith List Lia.
Import ListNotations.
From EncoreBench.Common Require Import EncoreInput.

(** Largest number of data bytes in one block. Extracted to an integer
    literal by [Extract.v]. *)
Definition block_max := 254.

(** * Encoder *)

(** [fits k l] is [length l <=? k], without walking more than [k + 1]
    cells of [l]. *)
Fixpoint fits (k : nat) (l : list nat) : bool :=
  match l with
  | [] => true
  | _ :: t => match k with O => false | S k' => fits k' t end
  end.

Fixpoint split_at (k : nat) (l : list nat) : list nat * list nat :=
  match k with
  | O => ([], l)
  | S k' =>
      match l with
      | [] => ([], [])
      | x :: t => let (a, b) := split_at k' t in (x :: a, b)
      end
  end.

(** Blocks of one zero-free piece: full 255-blocks while at least 254
    bytes remain, then one final block (possibly empty). *)
Fixpoint chunks (fuel : nat) (p : list nat) : list nat :=
  match fuel with
  | O => S (length p) :: p
  | S f =>
      if fits (pred block_max) p then S (length p) :: p
      else let (a, b) := split_at block_max p in S block_max :: a ++ chunks f b
  end.

Definition enc_piece (p : list nat) : list nat := chunks (length p) p.

(** The zero-free pieces between the zeros of a frame: [n] zeros give
    [n + 1] pieces. *)
Fixpoint split_zero (l : list nat) : list (list nat) :=
  match l with
  | [] => [[]]
  | x :: t =>
      let ps := split_zero t in
      match x with
      | O => [] :: ps
      | S _ =>
          match ps with
          | p :: ps' => (x :: p) :: ps'
          | [] => [[x]]
          end
      end
  end.

Fixpoint enc_pieces (ps : list (list nat)) : list nat :=
  match ps with
  | [] => []
  | p :: ps' => enc_piece p ++ enc_pieces ps'
  end.

Definition cobs_encode (l : list nat) : list nat := enc_pieces (split_zero l).

(** * Decoder *)

(** Streaming decoder. [k] data bytes remain in the current block; [ff]
    says whether the previous block was a 255-block, in which case no zero
    is emitted before the next one. *)
Fixpoint dec (k : nat) (ff : bool) (l : list nat) : option (list nat) :=
  match l with
  | [] => match k with O => Some [] | S _ => None end
  | x :: t =>
      match k with
      | S k' =>
          match x with
          | O => None
          | S _ => match dec k' ff t with Some d => Some (x :: d) | None => None end
          end
      | O =>
          match x with
          | O => None
          | S n =>
              let r := dec n (n =? block_max) t in
              if ff then r else match r with Some d => Some (0 :: d) | None => None end
          end
      end
  end.

Definition cobs_decode (l : list nat) : option (list nat) :=
  match l with
  | [] => None
  | _ => dec 0 true l
  end.

(** Benchmark entry point: encode the [n]-byte frame of the input. *)
Definition encode_input (n : nat) : list nat := cobs_encode (read_bytes 0 n).

(** * Properties *)

Definition nz (x : nat) : Prop := x <> 0.

Lemma fits_spec : forall k l, fits k l = true <-> length l <= k.
Proof.
  intros k l; revert k; induction l as [|x t IH]; intros [|k]; cbn;
    split; intro H; auto; try lia; try discriminate.
  - apply IH in H. lia.
  - apply IH. lia.
Qed.

Lemma split_at_spec : forall k l, split_at k l = (firstn k l, skipn k l).
Proof.
  induction k as [|k IH]; intros [|x t]; cbn; auto.
  rewrite IH. reflexivity.
Qed.

Lemma Forall_nz_split : forall k p,
  Forall nz p -> Forall nz (firstn k p) /\ Forall nz (skipn k p).
Proof.
  intros k p H. rewrite <- (firstn_skipn k p) in H.
  apply Forall_app in H. exact H.
Qed.

(** Decoding the data bytes of a block. *)
Lemma dec_data : forall d k ff r,
  Forall nz d ->
  dec (length d + k) ff (d ++ r) = option_map (app d) (dec k ff r).
Proof.
  induction d as [|x d IH]; intros k ff r Hd; cbn.
  - destruct (dec k ff r); reflexivity.
  - inversion Hd as [|? ? Hx Hd']; subst.
    destruct x as [|x]; [contradiction|].
    rewrite IH by exact Hd'. destruct (dec k ff r); reflexivity.
Qed.

Definition after (ff : bool) (o : option (list nat)) : option (list nat) :=
  if ff then o else option_map (cons 0) o.

(** Decoding one block. *)
Lemma dec_block : forall d ff r,
  Forall nz d ->
  dec 0 ff (S (length d) :: d ++ r) =
  after ff (option_map (app d) (dec 0 (length d =? block_max) r)).
Proof.
  intros d ff r Hd. cbn [dec].
  pose proof (dec_data d 0 (length d =? block_max) r Hd) as H.
  rewrite Nat.add_0_r in H. rewrite H.
  destruct ff; cbn; [reflexivity|].
  destruct (dec 0 _ r); reflexivity.
Qed.

(** Decoding the blocks of one piece. *)
Lemma chunks_dec : forall fuel p ff r,
  length p <= fuel -> Forall nz p ->
  dec 0 ff (chunks fuel p ++ r) =
  after ff (option_map (app p) (dec 0 false r)).
Proof.
  induction fuel as [|f IH]; intros p ff r Hlen Hp.
  - destruct p; [|cbn in Hlen; lia].
    cbn [chunks app length]. apply (dec_block [] ff r). constructor.
  - cbn [chunks].
    destruct (fits (pred block_max) p) eqn:Hfits.
    + apply fits_spec in Hfits.
      cbn [app]. rewrite dec_block by exact Hp.
      replace (length p =? block_max) with false; [reflexivity|].
      symmetry. apply Nat.eqb_neq. unfold block_max in *. cbn in Hfits. lia.
    + assert (Hlong : block_max <= length p).
      { destruct (Nat.le_gt_cases block_max (length p)); [assumption|].
        exfalso. assert (fits (pred block_max) p = true) by (apply fits_spec; lia).
        congruence. }
      rewrite split_at_spec.
      destruct (Forall_nz_split block_max p Hp) as [Ha Hb].
      assert (Hla : length (firstn block_max p) = block_max)
        by (rewrite length_firstn; lia).
      cbn [app]. rewrite <- app_assoc.
      rewrite <- Hla at 1. rewrite dec_block by exact Ha.
      rewrite Hla, Nat.eqb_refl.
      rewrite IH; [| rewrite length_skipn; unfold block_max in *; lia | exact Hb].
      destruct (dec 0 false r); cbn [option_map after];
        [rewrite app_assoc, firstn_skipn|]; reflexivity.
Qed.

Fixpoint join (ps : list (list nat)) : list nat :=
  match ps with
  | [] => []
  | [p] => p
  | p :: ps' => p ++ 0 :: join ps'
  end.

Lemma split_zero_ok : forall l,
  split_zero l <> [] /\ Forall (Forall nz) (split_zero l) /\
  join (split_zero l) = l.
Proof.
  induction l as [|x t (Hne & Hnz & Hj)]; cbn.
  - repeat split; [discriminate | repeat constructor].
  - destruct x as [|x].
    + repeat split; [discriminate | constructor; auto |].
      destruct (split_zero t); [contradiction|]. cbn. rewrite <- Hj. reflexivity.
    + destruct (split_zero t) as [|p ps]; [contradiction|].
      inversion Hnz as [|? ? Hp Hps]; subst.
      repeat split; [discriminate | constructor; [constructor; [unfold nz; lia|exact Hp] | exact Hps] |].
      destruct ps; reflexivity.
Qed.

Lemma enc_pieces_dec : forall ps ff,
  ps <> [] -> Forall (Forall nz) ps ->
  dec 0 ff (enc_pieces ps) = after ff (Some (join ps)).
Proof.
  induction ps as [|p ps IH]; intros ff Hne Hnz; [contradiction|].
  inversion Hnz as [|? ? Hp Hps]; subst.
  cbn [enc_pieces]. unfold enc_piece.
  rewrite chunks_dec by (auto; lia).
  destruct ps as [|q qs].
  - cbn. rewrite app_nil_r. reflexivity.
  - rewrite IH by (auto; discriminate). reflexivity.
Qed.

Lemma chunks_not_nil : forall fuel p, chunks fuel p <> [].
Proof.
  intros [|f] p; cbn [chunks]; [discriminate|].
  destruct (fits (pred block_max) p); [discriminate|].
  destruct (split_at block_max p); discriminate.
Qed.

(** Decoding an encoded frame gives the frame back. *)
Theorem cobs_roundtrip : forall l, cobs_decode (cobs_encode l) = Some l.
Proof.
  intro l. destruct (split_zero_ok l) as (Hne & Hnz & Hj).
  unfold cobs_encode. destruct (split_zero l) as [|p ps] eqn:E; [contradiction|].
  assert (Hdec := enc_pieces_dec (p :: ps) true Hne Hnz).
  cbn [after] in Hdec. rewrite <- Hj.
  unfold cobs_decode. destruct (enc_pieces (p :: ps)) eqn:En.
  - exfalso. cbn in En. unfold enc_piece in En.
    apply app_eq_nil in En. destruct En as [En _].
    exact (chunks_not_nil _ _ En).
  - exact Hdec.
Qed.

Lemma chunks_nz : forall fuel p, Forall nz p -> Forall nz (chunks fuel p).
Proof.
  induction fuel as [|f IH]; intros p Hp; cbn [chunks].
  - constructor; [unfold nz; lia | exact Hp].
  - destruct (fits _ p); [constructor; [unfold nz; lia | exact Hp]|].
    rewrite split_at_spec. destruct (Forall_nz_split block_max p Hp) as [Ha Hb].
    constructor; [unfold nz; lia|]. apply Forall_app. auto.
Qed.

(** The encoder never emits a zero, so zero can delimit frames. *)
Theorem cobs_encode_no_zero : forall l, Forall nz (cobs_encode l).
Proof.
  intro l. destruct (split_zero_ok l) as (_ & Hnz & _).
  unfold cobs_encode. induction (split_zero l) as [|p ps IH]; cbn; [constructor|].
  inversion Hnz; subst. apply Forall_app. split; [apply chunks_nz; assumption | auto].
Qed.
