(** W8 — CRC-16 and CRC-32 written in Gallina.

    Two checksums of the same block of bytes: CRC-16/MODBUS (polynomial
    x^16 + x^15 + x^2 + 1, reflected, initial register 0xFFFF) and
    CRC-32/ISO-HDLC, the CRC of Ethernet and zip (polynomial 0x04C11DB7,
    reflected, initial register and final XOR 0xFFFFFFFF).

    The program is the usual bit-serial loop of a reflected CRC: XOR the
    byte into the low bits of the register, then eight times shift right
    and XOR the polynomial when a one falls out. It uses [Nat.lxor],
    [Nat.div2] and [Nat.odd], which the extraction maps to the VM's
    bitwise instructions. Encore integers are 24-bit, so the 32-bit
    register of CRC-32 is kept as two 16-bit halves.

    Property proved: both are the polynomial definition of the CRC. The
    message, read as a polynomial over GF(2) (each byte least significant
    bit first), is multiplied by x^w, the initial register is added to its
    w highest coefficients, and the result is the remainder of the
    schoolbook division by the generator polynomial, plus the final XOR.
    The remainder is read with its highest coefficient in bit 0, as in
    every reflected CRC. *)

From Stdlib Require Import Arith Bool List Lia.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** * Constants

    Extracted to integer literals by [Extract.v]. *)

(** CRC-16/MODBUS polynomial, reflected: 0xA001. *)
Definition poly16 := 40961.
(** CRC-32 polynomial, reflected (0xEDB88320), high and low halves. *)
Definition poly32_hi := 60856.
Definition poly32_lo := 33568.
(** 0xFFFF: initial register of both CRCs, final XOR of CRC-32 (per half). *)
Definition half_mask := 65535.
(** 0x8000: the bit that crosses from the high half to the low half. *)
Definition top_bit := 32768.

(** * CRC-16/MODBUS *)

(** One shift of the register, with nothing shifted in. *)
Definition crc16_bit (c : nat) : nat :=
  if Nat.odd c then Nat.lxor (Nat.div2 c) poly16 else Nat.div2 c.

Fixpoint crc16_shift (k c : nat) : nat :=
  match k with
  | O => c
  | S k' => crc16_shift k' (crc16_bit c)
  end.

Definition crc16_byte (c b : nat) : nat := crc16_shift 8 (Nat.lxor c b).

(** CRC of [n] input bytes from [pos], streamed: no list is built. *)
Fixpoint crc16_from (c pos n : nat) : nat :=
  match n with
  | O => c
  | S n' => crc16_from (crc16_byte c (input_byte pos)) (S pos) n'
  end.

Definition crc16_input (n : nat) : nat := crc16_from half_mask 0 n.

(** * CRC-32/ISO-HDLC, on two 16-bit halves *)

Fixpoint crc32_shift (k h l : nat) : nat * nat :=
  match k with
  | O => (h, l)
  | S k' =>
      let h' := Nat.div2 h in
      let l' := if Nat.odd h then Nat.div2 l + top_bit else Nat.div2 l in
      if Nat.odd l then crc32_shift k' (Nat.lxor h' poly32_hi) (Nat.lxor l' poly32_lo)
      else crc32_shift k' h' l'
  end.

Definition crc32_byte (hl : nat * nat) (b : nat) : nat * nat :=
  let (h, l) := hl in crc32_shift 8 h (Nat.lxor l b).

Fixpoint crc32_from (h l pos n : nat) : nat * nat :=
  match n with
  | O => (h, l)
  | S n' =>
      let (h', l') := crc32_shift 8 h (Nat.lxor l (input_byte pos)) in
      crc32_from h' l' (S pos) n'
  end.

(** The CRC-32 of [n] input bytes, as (high half, low half). *)
Definition crc32_input (n : nat) : nat * nat :=
  let (h, l) := crc32_from half_mask half_mask 0 n in
  (Nat.lxor h half_mask, Nat.lxor l half_mask).

(** Benchmark entry point: both CRCs of the first [n] input bytes. *)
Definition run (n : nat) : nat * (nat * nat) := (crc16_input n, crc32_input n).

(** * Polynomials over GF(2)

    A polynomial is the list of its coefficients, highest degree first.
    Addition is [xorl], which aligns the lists on their heads: it adds
    polynomials of the same length, and adds a shorter one to the highest
    coefficients of a longer one. *)

Fixpoint xorl (a b : list bool) : list bool :=
  match a, b with
  | [], _ => b
  | _, [] => a
  | x :: a', y :: b' => xorb x y :: xorl a' b'
  end.

Definition zeros (k : nat) : list bool := repeat false k.

(** Schoolbook division by the generator [x^w + g], where [g] holds the
    [w] coefficients below the leading one: while the degree is at least
    [w], drop the leading coefficient, and when it is 1 subtract (add)
    [g] at the coefficients just below it. [fuel] bounds the steps. *)
Fixpoint pmod (fuel : nat) (g p : list bool) : list bool :=
  match fuel, p with
  | O, _ => p
  | _, [] => []
  | S f, c :: p' =>
      if length p' <? length g then p
      else pmod f g (if c then xorl g p' else p')
  end.

Definition poly_rem (g p : list bool) : list bool := pmod (length p) g p.

(** The coefficients of [x^(w-1)] down to [x^0] of a sum of powers of x. *)
Definition poly (w : nat) (exps : list nat) : list bool :=
  map (fun i => existsb (Nat.eqb (w - 1 - i)) exps) (seq 0 w).

(** The CRC of the bit string [m]: [(m · x^w + init · x^|m|) mod G],
    plus [xorout]. *)
Definition crc_spec (g init xorout m : list bool) : list bool :=
  xorl (poly_rem g (xorl init (m ++ zeros (length g)))) xorout.

(** The [k] low bits of [n], least significant first. *)
Fixpoint bits (k n : nat) : list bool :=
  match k with
  | O => []
  | S k' => Nat.odd n :: bits k' (Nat.div2 n)
  end.

(** A byte string as a bit string, each byte least significant bit first
    (a reflected CRC). *)
Definition message (l : list nat) : list bool := flat_map (bits 8) l.

(** The integer whose bit [i] is the [i]-th element of the list. *)
Fixpoint val (r : list bool) : nat :=
  match r with
  | [] => 0
  | b :: r' => Nat.b2n b + 2 * val r'
  end.

Definition g16 := poly 16 [15; 2; 0].
Definition g32 := poly 32 [26; 23; 22; 16; 12; 11; 10; 8; 7; 5; 4; 2; 1; 0].
Definition ones (k : nat) : list bool := repeat true k.

(** The check values of the CRC catalogue (the CRC of "123456789"),
    computed from the specification: 0x4B37 and 0xCBF43926. *)
Definition check_string := [49; 50; 51; 52; 53; 54; 55; 56; 57].

Example crc16_spec_check :
  crc_spec g16 (ones 16) (zeros 16) (message check_string) = bits 16 19255.
Proof. vm_compute. reflexivity. Qed.

Example crc32_spec_check :
  crc_spec g32 (ones 32) (ones 32) (message check_string)
  = bits 16 14630 ++ bits 16 52212.
Proof. vm_compute. reflexivity. Qed.

(** * Lists of coefficients *)

Lemma xorl_nil_r : forall a, xorl a [] = a.
Proof. destruct a; reflexivity. Qed.

Lemma xorl_comm : forall a b, xorl a b = xorl b a.
Proof.
  induction a as [|x a IH]; intros [|y b]; cbn; auto; try (rewrite xorb_comm, IH; reflexivity).
Qed.

Lemma xorl_assoc : forall a b c, xorl a (xorl b c) = xorl (xorl a b) c.
Proof.
  induction a as [|x a IH]; intros [|y b] [|z c]; cbn; auto; try (rewrite xorb_assoc, IH; reflexivity).
Qed.

Lemma xorl_length : forall a b, length (xorl a b) = Nat.max (length a) (length b).
Proof.
  induction a as [|x a IH]; intros [|y b]; cbn; auto.
Qed.

(** Adding a polynomial to the highest coefficients only. *)
Lemma xorl_app_short : forall a1 a2 b,
  length b <= length a1 -> xorl (a1 ++ a2) b = xorl a1 b ++ a2.
Proof.
  induction a1 as [|x a1 IH]; intros a2 [|y b] Hb; cbn in *; auto; try lia;
    try (rewrite xorl_nil_r; reflexivity); try (rewrite IH by lia; reflexivity).
Qed.

Lemma xorl_app : forall a1 a2 b1 b2,
  length a1 = length b1 -> xorl (a1 ++ a2) (b1 ++ b2) = xorl a1 b1 ++ xorl a2 b2.
Proof.
  induction a1 as [|x a1 IH]; intros a2 [|y b1] b2 H; cbn in *; try lia; auto; try (rewrite IH by lia; reflexivity).
Qed.

Lemma firstn_xorl : forall k a b,
  length a = length b -> firstn k (xorl a b) = xorl (firstn k a) (firstn k b).
Proof.
  induction k as [|k IH]; intros [|x a] [|y b] H; cbn in *; try lia; auto; try (rewrite IH by lia; reflexivity).
Qed.

Lemma skipn_xorl : forall k a b,
  length a = length b -> skipn k (xorl a b) = xorl (skipn k a) (skipn k b).
Proof.
  induction k as [|k IH]; intros [|x a] [|y b] H; cbn in *; try lia; auto; try (apply IH; lia).
Qed.

Lemma firstn_xorl_short : forall k a m,
  length m <= k -> firstn k (xorl a m) = xorl (firstn k a) m.
Proof.
  induction k as [|k IH]; intros [|x a] [|y m] H; cbn in *; try lia; auto; try (rewrite xorl_nil_r; reflexivity); try (rewrite IH by lia; reflexivity);
    try (f_equal; apply firstn_all2; lia).
Qed.

Lemma skipn_xorl_short : forall k a m,
  length m <= k -> skipn k (xorl a m) = skipn k a.
Proof.
  induction k as [|k IH]; intros [|x a] [|y m] H; cbn in *; try lia; auto; try (rewrite skipn_nil; reflexivity); try (rewrite xorl_nil_r; reflexivity);
    try (apply skipn_all2; lia); try (apply IH; lia).
Qed.

Lemma firstn_S_nth : forall k (l : list bool) d,
  k < length l -> firstn (S k) l = firstn k l ++ [nth k l d].
Proof.
  induction k as [|k IH]; intros [|x l] d H; cbn in *; try lia; auto; try (rewrite <- IH by lia; reflexivity).
Qed.

Lemma skipn_nth : forall k (l : list bool) d,
  k < length l -> skipn k l = nth k l d :: skipn (S k) l.
Proof.
  induction k as [|k IH]; intros [|x l] d H; cbn in *; try lia; auto; try (apply IH; lia).
Qed.

(** * Division as a shift register

    [ldiv] is the division read one coefficient at a time: the register
    holds the [w] highest coefficients not yet reduced. *)

Definition ldiv_step (g r : list bool) (b : bool) : list bool :=
  let s := tl r ++ [b] in if hd false r then xorl g s else s.

Fixpoint ldiv (g r p : list bool) : list bool :=
  match p with
  | [] => r
  | b :: p' => ldiv g (ldiv_step g r b) p'
  end.

Lemma ldiv_step_length : forall g r b,
  length r = length g -> 0 < length g -> length (ldiv_step g r b) = length g.
Proof.
  intros g [|c r] b H Hg; [cbn in H; lia|].
  unfold ldiv_step; cbn [tl hd length] in *.
  destruct c; [rewrite xorl_length|]; rewrite length_app; cbn [length]; lia.
Qed.

Lemma pmod_ldiv : forall g q r f,
  length r = length g -> 0 < length g -> length q < f ->
  pmod f g (r ++ q) = ldiv g r q.
Proof.
  intros g q; induction q as [|b q IH]; intros r f Hr Hg Hf;
    (destruct f as [|f]; [cbn in Hf; lia|]);
    (destruct r as [|c r]; [cbn in Hr; lia|]); cbn [length] in Hr.
  - cbn [app pmod ldiv]. rewrite app_nil_r.
    replace (length r <? length g) with true; [reflexivity|].
    symmetry. apply Nat.ltb_lt. lia.
  - cbn [app pmod ldiv].
    replace (length (r ++ b :: q) <? length g) with false
      by (symmetry; apply Nat.ltb_ge; rewrite length_app; cbn; lia).
    replace (r ++ b :: q) with ((r ++ [b]) ++ q) by (rewrite <- app_assoc; reflexivity).
    replace (if c then xorl g ((r ++ [b]) ++ q) else (r ++ [b]) ++ q)
      with (ldiv_step g (c :: r) b ++ q).
    + apply IH; [apply ldiv_step_length; cbn; lia | lia | cbn in Hf; lia].
    + unfold ldiv_step; cbn [tl hd]. destruct c; [|reflexivity].
      rewrite (xorl_comm g ((r ++ [b]) ++ q)), xorl_app_short, (xorl_comm (r ++ [b]) g);
        [reflexivity|].
      rewrite length_app; cbn [length]; lia.
Qed.

(** * The direct algorithm

    What CRC code runs: the message bits are added at the top of the
    register as they come, instead of being shifted through it, which
    saves the [w] trailing zero coefficients of [m · x^w]. *)

Definition dstep (g r : list bool) (b : bool) : list bool :=
  let s := tl r ++ [false] in if xorb (hd false r) b then xorl g s else s.

Fixpoint direct (g r m : list bool) : list bool :=
  match m with
  | [] => r
  | b :: m' => direct g (dstep g r b) m'
  end.

Lemma dstep_length : forall g r b,
  length r = length g -> 0 < length g -> length (dstep g r b) = length g.
Proof.
  intros g [|c r] b H Hg; [cbn in H; lia|].
  unfold dstep; cbn [tl hd length] in *.
  destruct (xorb c b); [rewrite xorl_length|]; rewrite length_app; cbn [length]; lia.
Qed.

Lemma direct_length : forall g m r,
  length r = length g -> 0 < length g -> length (direct g r m) = length g.
Proof.
  intros g m; induction m as [|b m IH]; intros r H Hg; cbn; auto.
  apply IH; [apply dstep_length|]; auto.
Qed.

Lemma direct_app : forall g m1 m2 r,
  direct g r (m1 ++ m2) = direct g (direct g r m1) m2.
Proof. intros g m1; induction m1; intros; cbn; auto. Qed.

Lemma xorl_zeros : forall k a, k <= length a -> xorl a (zeros k) = a.
Proof.
  induction k as [|k IH]; intros [|x a] H; cbn in *; try lia; auto using xorl_nil_r.
  rewrite xorb_false_r, IH by lia. reflexivity.
Qed.

Lemma direct_ldiv : forall g m r,
  length r = length g -> 0 < length g ->
  direct g r m =
  ldiv g (xorl r (firstn (length g) (m ++ zeros (length g))))
         (skipn (length g) (m ++ zeros (length g))).
Proof.
  intros g m. remember (length g) as w eqn:Hw.
  induction m as [|b m IH]; intros r Hr Hg.
  - cbn [app direct]. unfold zeros.
    rewrite firstn_all2, skipn_all2 by (rewrite repeat_length; lia).
    cbn. rewrite xorl_zeros by lia. reflexivity.
  - destruct w as [|w']; [lia|].
    set (X := m ++ zeros (S w')).
    assert (HX : S w' <= length X) by (subst X; unfold zeros; rewrite length_app, repeat_length; lia).
    destruct r as [|c r]; [cbn in Hr; lia|]. cbn [length] in Hr.
    cbn [direct app]. fold X.
    replace (firstn (S w') (b :: X)) with (b :: firstn w' X) by reflexivity.
    replace (skipn (S w') (b :: X)) with (skipn w' X) by reflexivity.
    rewrite (skipn_nth w' X false) by lia. cbn [ldiv].
    assert (Hd : length (dstep g (c :: r) b) = S w')
      by (rewrite dstep_length; cbn [length]; lia).
    rewrite IH by lia. fold X.
    f_equal.
    unfold ldiv_step, dstep; cbn [xorl tl hd].
    rewrite (firstn_S_nth w' X false) by lia.
    assert (Hf : length (firstn w' X) = w') by (rewrite length_firstn; lia).
    assert (Hx : xorl (r ++ [false]) (firstn w' X ++ [nth w' X false])
                 = xorl r (firstn w' X) ++ [nth w' X false])
      by (rewrite xorl_app by lia; reflexivity).
    destruct (xorb c b); [|exact Hx].
    rewrite <- xorl_assoc, Hx. reflexivity.
Qed.

(** The direct algorithm computes the polynomial definition. *)
Theorem direct_spec : forall g init xorout m,
  length init = length g -> 0 < length g ->
  crc_spec g init xorout m = xorl (direct g init m) xorout.
Proof.
  intros g init xorout m Hi Hg. unfold crc_spec, poly_rem. f_equal.
  set (Y := m ++ zeros (length g)).
  assert (HY : length Y = length m + length g)
    by (subst Y; unfold zeros; rewrite length_app, repeat_length; reflexivity).
  set (F := firstn (length g) Y). set (K := skipn (length g) Y).
  assert (HF : length F = length g) by (subst F; rewrite length_firstn; lia).
  assert (HK : length K = length m) by (subst K; rewrite length_skipn; lia).
  assert (E : Y = F ++ K) by (symmetry; apply firstn_skipn).
  rewrite E, (xorl_comm init), xorl_app_short, (xorl_comm F) by lia.
  rewrite pmod_ldiv; [| rewrite xorl_length; lia | exact Hg
                      | rewrite length_app, xorl_length; lia].
  symmetry. apply direct_ldiv; lia.
Qed.

(** Adding [m] to the top of the register and shifting in zeros is the
    same as shifting [m] in: what the byte-at-a-time code does. *)
Lemma direct_xor_in : forall g m r,
  length m <= length r -> length r = length g -> 0 < length g ->
  direct g r m = direct g (xorl r m) (zeros (length m)).
Proof.
  intros g m; induction m as [|b m IH]; intros r Hm Hr Hg.
  - rewrite xorl_nil_r. reflexivity.
  - destruct r as [|c r]; [cbn in Hm; lia|]. cbn [length] in Hm, Hr.
    assert (Hd : length (dstep g (c :: r) b) = length g)
      by (apply dstep_length; cbn [length]; lia).
    cbn [direct xorl length]. unfold zeros at 1; cbn [repeat direct]. fold (zeros (length m)).
    rewrite IH by lia.
    f_equal.
    unfold dstep; cbn [hd tl]. rewrite xorb_false_r.
    assert (Hx : xorl (r ++ [false]) m = xorl r m ++ [false])
      by (apply xorl_app_short; lia).
    destruct (xorb c b); [|exact Hx].
    rewrite <- xorl_assoc, Hx. reflexivity.
Qed.

(** * Registers as integers *)

Lemma lxor_b2n_double : forall x y a b,
  Nat.lxor (Nat.b2n x + 2 * a) (Nat.b2n y + 2 * b) = Nat.b2n (xorb x y) + 2 * Nat.lxor a b.
Proof.
  intros x y a b. rewrite !(Nat.add_comm (Nat.b2n _)).
  apply Nat.bits_inj. intros [|n]; rewrite Nat.lxor_spec.
  - rewrite !Nat.testbit_0_r. reflexivity.
  - rewrite !Nat.testbit_succ_r, Nat.lxor_spec. reflexivity.
Qed.

Lemma val_xorl : forall a b, val (xorl a b) = Nat.lxor (val a) (val b).
Proof.
  induction a as [|x a IH]; intros [|y b]; cbn [xorl val].
  - reflexivity.
  - rewrite Nat.lxor_0_l. reflexivity.
  - rewrite Nat.lxor_0_r. reflexivity.
  - rewrite lxor_b2n_double, IH. reflexivity.
Qed.

Lemma val_app : forall a b, val (a ++ b) = val a + 2 ^ length a * val b.
Proof.
  induction a as [|x a IH]; intros b; cbn [app val length].
  - cbn. lia.
  - rewrite IH, Nat.pow_succ_r'. lia.
Qed.

Lemma val_tl : forall r, val (tl r) = Nat.div2 (val r).
Proof.
  intros [|b r]; cbn [tl val]; [reflexivity|].
  rewrite Nat.div2_div. symmetry. apply Nat.add_b2n_double_div2.
Qed.

Lemma val_hd : forall r, hd false r = Nat.odd (val r).
Proof.
  intros [|b r]; cbn [hd val]; [reflexivity|].
  rewrite <- Nat.bit0_odd, Nat.add_b2n_double_bit0. reflexivity.
Qed.

Lemma val_shift : forall r, val (tl r ++ [false]) = Nat.div2 (val r).
Proof.
  intro r. rewrite val_app, val_tl. replace (val [false]) with 0 by reflexivity.
  rewrite Nat.mul_0_r, Nat.add_0_r. reflexivity.
Qed.

Lemma val_zeros : forall k, val (zeros k) = 0.
Proof.
  induction k as [|k IH]; [reflexivity|].
  unfold zeros in *; cbn [repeat val]. rewrite IH. reflexivity.
Qed.

Lemma length_bits : forall k n, length (bits k n) = k.
Proof. induction k; intros; cbn; auto. Qed.

Lemma val_bits : forall k n, n < 2 ^ k -> val (bits k n) = n.
Proof.
  induction k as [|k IH]; intros n H; cbn [bits val].
  - cbn in H. lia.
  - rewrite IH.
    + rewrite (Nat.div2_odd n) at 3. lia.
    + rewrite Nat.div2_div. apply Nat.Div0.div_lt_upper_bound. cbn in H |- *. lia.
Qed.

(** Equalities between closed [nat]s of up to 16 bits, decided by
    [Nat.eqb]: comparing unary numbers of this size directly overflows
    the stack of the conversion check. *)
Ltac nat_eq := apply Nat.eqb_eq; vm_compute; reflexivity.

(** * CRC-16/MODBUS is the polynomial definition *)

Lemma length_g16 : length g16 = 16.
Proof. reflexivity. Qed.

Lemma val_g16 : val g16 = poly16.
Proof. nat_eq. Qed.

Lemma crc16_bit_spec : forall r, crc16_bit (val r) = val (dstep g16 r false).
Proof.
  intro r. unfold crc16_bit, dstep. rewrite xorb_false_r, val_hd.
  destruct (Nat.odd (val r)).
  - rewrite val_xorl, val_shift, val_g16, Nat.lxor_comm. reflexivity.
  - rewrite val_shift. reflexivity.
Qed.

Lemma crc16_shift_spec : forall k r,
  crc16_shift k (val r) = val (direct g16 r (zeros k)).
Proof.
  induction k as [|k IH]; intro r; cbn [crc16_shift zeros repeat direct]; auto.
  rewrite crc16_bit_spec. apply IH.
Qed.

Lemma crc16_fold : forall l r,
  Forall (fun b => b < 256) l -> length r = 16 ->
  fold_left crc16_byte l (val r) = val (direct g16 r (message l)).
Proof.
  induction l as [|b l IH]; intros r Hl Hr; cbn [fold_left message flat_map]; auto.
  inversion Hl as [|? ? Hb Hl']; subst.
  rewrite direct_app.
  replace (crc16_byte (val r) b) with (val (direct g16 r (bits 8 b))).
  - apply IH; [exact Hl'|]. apply direct_length; rewrite ?length_g16; lia.
  - unfold crc16_byte.
    rewrite <- (val_bits 8 b) at 2 by (cbn; lia).
    rewrite <- val_xorl, crc16_shift_spec.
    rewrite (direct_xor_in g16 (bits 8 b) r) by (rewrite ?length_bits, ?length_g16; lia).
    rewrite length_bits. reflexivity.
Qed.

Lemma crc16_from_fold : forall n c pos,
  crc16_from c pos n = fold_left crc16_byte (read_bytes pos n) c.
Proof. induction n; intros; cbn; auto. Qed.

(** The CRC-16 of a byte string is its CRC-16/MODBUS. *)
Theorem crc16_correct : forall l,
  Forall (fun b => b < 256) l ->
  fold_left crc16_byte l half_mask = val (crc_spec g16 (ones 16) (zeros 16) (message l)).
Proof.
  intros l Hl.
  rewrite direct_spec by (rewrite ?length_g16; reflexivity || lia).
  rewrite val_xorl, val_zeros, Nat.lxor_0_r.
  replace half_mask with (val (ones 16)) by nat_eq.
  apply crc16_fold; [exact Hl | reflexivity].
Qed.

Corollary crc16_input_correct : forall n,
  Forall (fun b => b < 256) (read_bytes 0 n) ->
  crc16_input n = val (crc_spec g16 (ones 16) (zeros 16) (message (read_bytes 0 n))).
Proof.
  intros n H. unfold crc16_input. rewrite crc16_from_fold. apply crc16_correct, H.
Qed.

(** * CRC-32/ISO-HDLC is the polynomial definition *)

(** A 32-coefficient register as the (high, low) halves of its integer. *)
Definition halves (r : list bool) : nat * nat := (val (skipn 16 r), val (firstn 16 r)).

Lemma val_halves : forall r, length r = 32 ->
  val r = snd (halves r) + 65536 * fst (halves r).
Proof.
  intros r H. unfold halves; cbn [fst snd].
  rewrite <- (firstn_skipn 16 r) at 1. rewrite val_app, length_firstn.
  replace (Nat.min 16 (length r)) with 16 by lia. reflexivity.
Qed.

Lemma length_g32 : length g32 = 32.
Proof. reflexivity. Qed.

Lemma val_g32_lo : val (firstn 16 g32) = poly32_lo.
Proof. nat_eq. Qed.

Lemma val_g32_hi : val (skipn 16 g32) = poly32_hi.
Proof. nat_eq. Qed.

(** Shifting the register moves the lowest coefficient of the high half
    to the top of the low half. *)
Lemma shift_halves : forall r, length r = 32 ->
  firstn 16 (tl r ++ [false]) = tl (firstn 16 r) ++ [hd false (skipn 16 r)] /\
  skipn 16 (tl r ++ [false]) = tl (skipn 16 r) ++ [false].
Proof.
  intros [|c r] H; cbn [length] in H; [lia|].
  change (tl (c :: r)) with r.
  change (firstn 16 (c :: r)) with (c :: firstn 15 r).
  change (skipn 16 (c :: r)) with (skipn 15 r).
  rewrite firstn_app, skipn_app. replace (16 - length r) with 0 by lia.
  rewrite firstn_O, skipn_O, app_nil_r.
  rewrite (skipn_nth 15 r false) by lia.
  split; [|reflexivity].
  apply firstn_S_nth. lia.
Qed.

Lemma crc32_shift_spec : forall k r, length r = 32 ->
  crc32_shift k (val (skipn 16 r)) (val (firstn 16 r)) = halves (direct g32 r (zeros k)).
Proof.
  induction k as [|k IH]; intros r Hr; [reflexivity|].
  cbn [zeros repeat direct].
  rewrite <- IH by (apply dstep_length; rewrite ?length_g32; lia).
  set (s := tl r ++ [false]).
  assert (Hs : length s = 32)
    by (subst s; destruct r; cbn [tl length] in *; rewrite ?length_app; cbn [length]; lia).
  destruct (shift_halves r Hr) as [F S]. fold s in F, S.
  assert (E1 : val (firstn 16 s) =
    if Nat.odd (val (skipn 16 r)) then Nat.div2 (val (firstn 16 r)) + top_bit
    else Nat.div2 (val (firstn 16 r))).
  { rewrite F, val_app, val_tl, val_hd.
    replace (length (tl (firstn 16 r))) with 15
      by (assert (length (firstn 16 r) = 16) by (rewrite length_firstn; lia);
          destruct (firstn 16 r); cbn in *; lia).
    replace top_bit with (2 ^ 15) by (symmetry; nat_eq).
    destruct (Nat.odd (val (skipn 16 r))); cbn [val Nat.b2n]; lia. }
  assert (E2 : val (skipn 16 s) = Nat.div2 (val (skipn 16 r))).
  { rewrite S, val_shift. reflexivity. }
  assert (E3 : hd false r = Nat.odd (val (firstn 16 r))).
  { rewrite <- val_hd. destruct r; reflexivity. }
  unfold dstep. rewrite xorb_false_r, E3. fold s. cbn [crc32_shift].
  destruct (Nat.odd (val (firstn 16 r))).
  - rewrite firstn_xorl, skipn_xorl, !val_xorl, E1, E2, val_g32_lo, val_g32_hi
      by (rewrite length_g32; lia).
    rewrite (Nat.lxor_comm poly32_hi), (Nat.lxor_comm poly32_lo). reflexivity.
  - rewrite E1, E2. reflexivity.
Qed.

Lemma crc32_fold : forall l r,
  Forall (fun b => b < 256) l -> length r = 32 ->
  fold_left crc32_byte l (halves r) = halves (direct g32 r (message l)).
Proof.
  induction l as [|b l IH]; intros r Hl Hr; cbn [fold_left message flat_map]; auto.
  inversion Hl as [|? ? Hb Hl']; subst.
  rewrite direct_app.
  replace (crc32_byte (halves r) b) with (halves (direct g32 r (bits 8 b))).
  - apply IH; [exact Hl'|]. apply direct_length; rewrite ?length_g32; lia.
  - change (halves (direct g32 r (bits 8 b))
            = crc32_shift 8 (val (skipn 16 r)) (Nat.lxor (val (firstn 16 r)) b)).
    replace (Nat.lxor (val (firstn 16 r)) b) with (val (firstn 16 (xorl r (bits 8 b))))
      by (rewrite firstn_xorl_short, val_xorl, val_bits by (rewrite ?length_bits; cbn; lia);
          reflexivity).
    replace (val (skipn 16 r)) with (val (skipn 16 (xorl r (bits 8 b))))
      by (rewrite skipn_xorl_short by (rewrite length_bits; lia); reflexivity).
    rewrite crc32_shift_spec by (rewrite xorl_length, length_bits; lia).
    rewrite (direct_xor_in g32 (bits 8 b) r) by (rewrite ?length_bits, ?length_g32; lia).
    rewrite length_bits. reflexivity.
Qed.

Lemma crc32_from_fold : forall n h l pos,
  crc32_from h l pos n = fold_left crc32_byte (read_bytes pos n) (h, l).
Proof.
  induction n as [|n IH]; intros h l pos; cbn [crc32_from read_bytes fold_left]; auto.
  cbn [crc32_byte]. destruct (crc32_shift 8 h (Nat.lxor l (input_byte pos))) as [h' l'].
  apply IH.
Qed.

(** The CRC-32 of a byte string, as (high half, low half). *)
Definition crc32 (l : list nat) : nat * nat :=
  let (h, lo) := fold_left crc32_byte l (half_mask, half_mask) in
  (Nat.lxor h half_mask, Nat.lxor lo half_mask).

(** The CRC-32 of a byte string is its CRC-32/ISO-HDLC. *)
Theorem crc32_correct : forall l,
  Forall (fun b => b < 256) l ->
  crc32 l = halves (crc_spec g32 (ones 32) (ones 32) (message l)).
Proof.
  intros l Hl. unfold crc32.
  rewrite direct_spec by (rewrite ?length_g32; reflexivity || lia).
  replace (half_mask, half_mask) with (halves (ones 32))
    by (unfold halves; f_equal; nat_eq).
  rewrite crc32_fold by (auto; reflexivity).
  assert (Hd : length (direct g32 (ones 32) (message l)) = 32)
    by (apply direct_length; rewrite ?length_g32; reflexivity || lia).
  unfold halves.
  rewrite firstn_xorl, skipn_xorl, !val_xorl by (rewrite Hd; reflexivity).
  replace (val (skipn 16 (ones 32))) with half_mask by nat_eq.
  replace (val (firstn 16 (ones 32))) with half_mask by nat_eq.
  reflexivity.
Qed.

Corollary crc32_input_correct : forall n,
  Forall (fun b => b < 256) (read_bytes 0 n) ->
  crc32_input n = halves (crc_spec g32 (ones 32) (ones 32) (message (read_bytes 0 n))).
Proof.
  intros n H. unfold crc32_input. rewrite crc32_from_fold. apply crc32_correct, H.
Qed.

(** Nothing but [input_byte] (a parameter, realised by the host) is
    assumed. *)
Print Assumptions crc16_input_correct.
Print Assumptions crc32_input_correct.
