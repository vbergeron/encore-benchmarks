(** W3 — BIP32 derivation-path policy and destination allow-list.

    A hardware wallet signs a request (derivation path, amount,
    destination) only if its policy allows it. The policy is a list of
    rules; a rule gives, for each level of the path, a range of BIP32
    child indices (hardened indices have the top bit set, so "account 0'
    to 4'" is the range [0x80000000, 0x80000004]), the largest amount it
    allows, and the destinations it allows. A request is signed when at
    least one rule allows all three.

    When no rule allows the request, the device says why, taking the rule
    that came closest: 1 the destination is not allowed, 2 the amount is
    over the limit, 3 the path is not allowed.

    Path components (4 bytes) and amounts (8 bytes) are big-endian byte
    strings, compared byte by byte: a BIP32 index goes up to 2^32 - 1 and an
    amount up to 2^64 - 1, far past the 24-bit VM integers, so no
    component or amount is ever converted to a [nat]. The proofs state the
    comparisons over the numbers the bytes denote ([be]).

    Properties proved:
    - [lex_leb_spec]: the byte comparison is the comparison of the
      big-endian numbers;
    - [sign_iff_complies]: a request is signed if and only if some rule of
      the policy allows its path, its amount and its destination;
    - [path_reject], [amount_reject], [dest_reject]: the reason given for a
      refusal is true;
    - [run_spec]: the driver, which reads the requests and the rules in
      place in the input (allocating nothing but its result) and stops at
      the first rule that allows a request, computes [decide] over the
      decoded policy;
    - [run_signs_only_compliant]: the two together, over the input bytes. *)

From Stdlib Require Import Arith List Lia Bool.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** Constants. Each one is extracted to a VM integer literal by
    [Extract.v]: a [nat] literal would otherwise extract to a chain of
    successor applications. *)
Definition elem_len := 4.     (* a BIP32 child index, big-endian *)
Definition range_len := 8.    (* a range: low then high index *)
Definition amount_len := 8.   (* an amount, big-endian *)
Definition addr_len := 20.    (* a destination address *)
Definition hdr_len := 3.      (* input header: request count, rules offset *)
Definition byte_base := 256.

(** Verdicts. *)
Definition code_dest := 1.    (* destination not allowed *)
Definition code_amount := 2.  (* amount over the limit *)
Definition code_path := 3.    (* path not allowed *)

(** * Byte strings *)

Definition bytes (l : list nat) : Prop := Forall (fun b => b < 256) l.

(** The number a big-endian byte string denotes. *)
Fixpoint be (l : list nat) : nat :=
  match l with
  | [] => 0
  | b :: t => b * 256 ^ length t + be t
  end.

(** [a <= b] on two byte strings of the same length. *)
Fixpoint lex_leb (a b : list nat) : bool :=
  match a, b with
  | x :: a', y :: b' =>
      if x <? y then true else if x =? y then lex_leb a' b' else false
  | _, _ => true
  end.

Fixpoint bytes_eqb (a b : list nat) : bool :=
  match a, b with
  | [], [] => true
  | x :: a', y :: b' => if x =? y then bytes_eqb a' b' else false
  | _, _ => false
  end.

Fixpoint mem_addr (a : list nat) (l : list (list nat)) : bool :=
  match l with
  | [] => false
  | x :: l' => if bytes_eqb a x then true else mem_addr a l'
  end.

(** * Policy *)

Record rule := mk_rule {
  pattern : list (list nat * list nat);  (* one index range per level *)
  limit : list nat;                      (* largest amount allowed *)
  dests : list (list nat)                (* destinations allowed *)
}.

Record request := mk_request {
  path : list (list nat);
  amount : list nat;
  dest : list nat
}.

Fixpoint path_matchb (p : list (list nat)) (pat : list (list nat * list nat)) : bool :=
  match p, pat with
  | [], [] => true
  | c :: p', (lo, hi) :: pat' =>
      if lex_leb lo c then if lex_leb c hi then path_matchb p' pat' else false
      else false
  | _, _ => false
  end.

(** 0 if the rule allows the request, otherwise how far it got. *)
Definition rule_code (r : rule) (q : request) : nat :=
  if path_matchb (path q) (pattern r) then
    if lex_leb (amount q) (limit r) then
      if mem_addr (dest q) (dests r) then 0 else code_dest
    else code_amount
  else code_path.

Definition lower (a b : nat) : nat := if a <=? b then a else b.

(** The verdict of a policy: the best verdict of its rules. *)
Fixpoint decide (pol : list rule) (q : request) : nat :=
  match pol with
  | [] => code_path
  | r :: pol' => lower (rule_code r q) (decide pol' q)
  end.

(** * Decoding *)

(** Input layout: a header [q off_hi off_lo] (number of requests, offset
    of the policy), the [q] requests, then the rules.
    - request: [d], [d] indices of 4 bytes, the amount (8 bytes), the
      destination (20 bytes);
    - rule: [d], [d] ranges (low then high index, 4 bytes each), the limit
      (8 bytes), [k], [k] destinations (20 bytes each).

    The decoders below say what the bytes mean. The driver does not run
    them: it compares the bytes in place (next section), and [run_spec]
    proves that it computes [decide] over what they decode. *)

Fixpoint read_path (d pos : nat) : list (list nat) :=
  match d with
  | O => []
  | S d' => read_bytes pos elem_len :: read_path d' (pos + elem_len)
  end.

Fixpoint read_pattern (d pos : nat) : list (list nat * list nat) :=
  match d with
  | O => []
  | S d' =>
      (read_bytes pos elem_len, read_bytes (pos + elem_len) elem_len)
        :: read_pattern d' (pos + range_len)
  end.

Fixpoint read_addrs (k pos : nat) : list (list nat) :=
  match k with
  | O => []
  | S k' => read_bytes pos addr_len :: read_addrs k' (pos + addr_len)
  end.

(** The rule at [pos], and the position after it. *)
Definition read_rule (pos : nat) : rule * nat :=
  let d := input_byte pos in
  let lim_pos := S pos + d * range_len in
  let k_pos := lim_pos + amount_len in
  let k := input_byte k_pos in
  (mk_rule (read_pattern d (S pos)) (read_bytes lim_pos amount_len)
     (read_addrs k (S k_pos)),
   S k_pos + k * addr_len).

(** The request at [pos], and the position after it. *)
Definition read_request (pos : nat) : request * nat :=
  let d := input_byte pos in
  let amt_pos := S pos + d * elem_len in
  let dst_pos := amt_pos + amount_len in
  (mk_request (read_path d (S pos)) (read_bytes amt_pos amount_len)
     (read_bytes dst_pos addr_len),
   dst_pos + addr_len).

(** The policy (its first [k] rules) and the requests of the input. *)
Fixpoint read_rules (k pos : nat) : list rule :=
  match k with
  | O => []
  | S k' => fst (read_rule pos) :: read_rules k' (snd (read_rule pos))
  end.

Fixpoint read_requests (k pos : nat) : list request :=
  match k with
  | O => []
  | S k' => fst (read_request pos) :: read_requests k' (snd (read_request pos))
  end.

Definition rules_offset : nat := input_byte 1 * byte_base + input_byte 2.
Definition policy (n : nat) : list rule := read_rules n rules_offset.
Definition requests : list request := read_requests (input_byte 0) hdr_len.

(** * Driver: the policy checked in place *)

(** [rule_code], reading the rule at [rpos] and the request at [qpos]
    byte by byte from the input instead of decoding them into lists: the
    driver allocates nothing but its result. *)

(** [n] bytes at [a] <= [n] bytes at [b]. *)
Fixpoint le_at (n a b : nat) : bool :=
  match n with
  | O => true
  | S n' =>
      let x := input_byte a in
      let y := input_byte b in
      if x <? y then true else if x =? y then le_at n' (S a) (S b) else false
  end.

Fixpoint eq_at (n a b : nat) : bool :=
  match n with
  | O => true
  | S n' => if input_byte a =? input_byte b then eq_at n' (S a) (S b) else false
  end.

(** The destination at [q] is one of the [k] at [pos]. *)
Fixpoint mem_at (k pos q : nat) : bool :=
  match k with
  | O => false
  | S k' => if eq_at addr_len q pos then true else mem_at k' (pos + addr_len) q
  end.

(** The [qd] indices at [qpos] are in the [d] ranges at [rpos]. *)
Fixpoint path_at (d qd rpos qpos : nat) : bool :=
  match d, qd with
  | O, O => true
  | S d', S qd' =>
      if le_at elem_len rpos qpos then
        if le_at elem_len qpos (rpos + elem_len)
        then path_at d' qd' (rpos + range_len) (qpos + elem_len)
        else false
      else false
  | _, _ => false
  end.

Definition rule_code_at (rpos qpos : nat) : nat :=
  let d := input_byte rpos in
  let lim := S rpos + d * range_len in
  let amt := S qpos + input_byte qpos * elem_len in
  if path_at d (input_byte qpos) (S rpos) (S qpos) then
    if le_at amount_len amt lim then
      let k_pos := lim + amount_len in
      if mem_at (input_byte k_pos) (S k_pos) (amt + amount_len) then 0
      else code_dest
    else code_amount
  else code_path.

(** Position after the rule at [pos], and after the request at [pos]. *)
Definition rule_end (pos : nat) : nat :=
  let k_pos := S pos + input_byte pos * range_len + amount_len in
  S k_pos + input_byte k_pos * addr_len.

Definition request_end (pos : nat) : nat :=
  S pos + input_byte pos * elem_len + amount_len + addr_len.

(** Check the request at [qpos] against the [k] rules from [rpos]; [best]
    is the best verdict so far. Stops at the first rule that allows the
    request. *)
Fixpoint eval_rules (k rpos qpos best : nat) : nat :=
  match k with
  | O => best
  | S k' =>
      let c := rule_code_at rpos qpos in
      if c =? 0 then 0 else eval_rules k' (rule_end rpos) qpos (lower c best)
  end.

(** The verdicts of the [k] requests from [qpos] under the first [n] rules
    at [rules]. *)
Fixpoint process (k qpos n rules : nat) : list nat :=
  match k with
  | O => []
  | S k' => eval_rules n rules qpos code_path :: process k' (request_end qpos) n rules
  end.

(** The verdict of every request of the input under the first [n] rules of
    its policy. *)
Definition run (n : nat) : list nat :=
  process (input_byte 0) hdr_len n (input_byte 1 * byte_base + input_byte 2).

(** * Specification *)

Definition elem (c : list nat) : Prop := length c = elem_len /\ bytes c.
Definition wf_range (r : list nat * list nat) : Prop := elem (fst r) /\ elem (snd r).

Definition wf_rule (r : rule) : Prop :=
  Forall wf_range (pattern r) /\ length (limit r) = amount_len /\ bytes (limit r).

Definition wf_request (q : request) : Prop :=
  Forall elem (path q) /\ length (amount q) = amount_len /\ bytes (amount q).

Definition in_range (c : list nat) (r : list nat * list nat) : Prop :=
  be (fst r) <= be c <= be (snd r).

Definition path_ok (r : rule) (q : request) : Prop := Forall2 in_range (path q) (pattern r).
Definition amount_ok (r : rule) (q : request) : Prop := be (amount q) <= be (limit r).

(** What it means for a rule to allow a request. *)
Definition complies (r : rule) (q : request) : Prop :=
  path_ok r q /\ amount_ok r q /\ In (dest q) (dests r).

(** * Proofs *)

(** ** Byte strings *)

Lemma be_bound : forall l, bytes l -> be l < 256 ^ length l.
Proof.
  induction l as [|b t IH]; intro H; cbn; [lia|].
  inversion H; subst. specialize (IH H3).
  assert (b * 256 ^ length t <= 255 * 256 ^ length t) by (apply Nat.mul_le_mono_r; lia).
  lia.
Qed.

Theorem lex_leb_spec : forall a b,
  length a = length b -> bytes a -> bytes b ->
  lex_leb a b = true <-> be a <= be b.
Proof.
  induction a as [|x a IH]; intros [|y b] Hl Ha Hb; cbn [length lex_leb be] in Hl |- *;
    try discriminate; [split; auto|].
  injection Hl as Hl. inversion Ha as [|? ? Hx Ha']; inversion Hb as [|? ? Hy Hb']; subst.
  pose proof (be_bound a Ha') as Ba. pose proof (be_bound b Hb') as Bb.
  rewrite <- Hl in Bb |- *. set (P := 256 ^ length a) in *.
  destruct (Nat.ltb_spec x y) as [Hxy|Hxy].
  - split; [intros _|reflexivity].
    assert ((x + 1) * P <= y * P) by (apply Nat.mul_le_mono_r; lia). nia.
  - destruct (Nat.eqb_spec x y) as [->|Hne].
    + rewrite (IH b Hl Ha' Hb'). lia.
    + split; [discriminate|intro H].
      assert ((y + 1) * P <= x * P) by (apply Nat.mul_le_mono_r; lia). nia.
Qed.

Lemma bytes_eqb_eq : forall a b, bytes_eqb a b = true <-> a = b.
Proof.
  induction a as [|x a IH]; intros [|y b]; cbn; split; intro H;
    try discriminate; try reflexivity.
  - destruct (Nat.eqb_spec x y); [|discriminate].
    apply IH in H. subst. reflexivity.
  - injection H as -> ->. rewrite Nat.eqb_refl. apply IH. reflexivity.
Qed.

Lemma mem_addr_spec : forall a l, mem_addr a l = true <-> In a l.
Proof.
  induction l as [|x l IH]; cbn; [split; [discriminate|tauto]|].
  destruct (bytes_eqb a x) eqn:E.
  - apply bytes_eqb_eq in E. subst. tauto.
  - rewrite IH. split; [tauto|]. intros [->|H]; [|exact H].
    rewrite (proj2 (bytes_eqb_eq a a) eq_refl) in E. discriminate.
Qed.

(** ** Rules *)

Lemma path_matchb_spec : forall p pat,
  Forall elem p -> Forall wf_range pat ->
  path_matchb p pat = true <-> Forall2 in_range p pat.
Proof.
  induction p as [|c p IH]; intros [|[lo hi] pat] Hp Hpat; cbn.
  - split; auto.
  - split; [discriminate|intro H; inversion H].
  - split; [discriminate|intro H; inversion H].
  - inversion Hp as [|? ? [Hcl Hcb] Hp']; inversion Hpat as [|? ? [[Hll Hlb] [Hhl Hhb]] Hpat']; subst.
    cbn in *. unfold in_range; cbn.
    destruct (lex_leb lo c) eqn:E1; [destruct (lex_leb c hi) eqn:E2|].
    + rewrite (IH pat Hp' Hpat'). split.
      * intro H. constructor; [|exact H]. split.
        -- apply (lex_leb_spec lo c); auto; congruence.
        -- apply (lex_leb_spec c hi); auto; congruence.
      * intro H. inversion H. assumption.
    + split; [discriminate|intro H; inversion H as [|? ? ? ? [_ Hh]]; subst].
      apply (lex_leb_spec c hi) in Hh; [congruence|congruence|auto|auto].
    + split; [discriminate|intro H; inversion H as [|? ? ? ? [Hl _]]; subst].
      apply (lex_leb_spec lo c) in Hl; [congruence|congruence|auto|auto].
Qed.

(** The four verdicts of a rule, and what each one means. *)
Lemma rule_code_cases : forall r q, wf_rule r -> wf_request q ->
  (rule_code r q = 0 /\ path_ok r q /\ amount_ok r q /\ In (dest q) (dests r)) \/
  (rule_code r q = code_dest /\ path_ok r q /\ amount_ok r q /\ ~ In (dest q) (dests r)) \/
  (rule_code r q = code_amount /\ path_ok r q /\ ~ amount_ok r q) \/
  (rule_code r q = code_path /\ ~ path_ok r q).
Proof.
  intros r q [Hpat [Hll Hlb]] [Hp [Hal Hab]]. unfold rule_code, path_ok, amount_ok.
  pose proof (path_matchb_spec (path q) (pattern r) Hp Hpat) as Pm.
  pose proof (lex_leb_spec (amount q) (limit r) ltac:(congruence) Hab Hlb) as Am.
  pose proof (mem_addr_spec (dest q) (dests r)) as Mm.
  destruct (path_matchb (path q) (pattern r)); [|right; right; right; split; [reflexivity|]].
  - destruct (lex_leb (amount q) (limit r)); [|right; right; left].
    + destruct (mem_addr (dest q) (dests r)); [left|right; left].
      * repeat split; [apply Pm|apply Am|apply Mm]; reflexivity.
      * repeat split; [apply Pm|apply Am|]; auto. intro H. apply Mm in H. discriminate.
    + repeat split; [apply Pm; reflexivity|]. intro H. apply Am in H. discriminate.
  - intro H. apply Pm in H. discriminate.
Qed.

Lemma rule_code_le : forall r q, rule_code r q <= code_path.
Proof.
  intros r q. unfold rule_code, code_dest, code_amount, code_path.
  destruct (path_matchb _ _); [destruct (lex_leb _ _); [destruct (mem_addr _ _)|]|]; lia.
Qed.

Lemma lower_min : forall a b, lower a b = Nat.min a b.
Proof. intros a b. unfold lower. destruct (Nat.leb_spec a b); lia. Qed.

Lemma decide_le : forall pol q, decide pol q <= code_path.
Proof.
  induction pol as [|r pol IH]; intro q; cbn; [unfold code_path; lia|].
  rewrite lower_min. pose proof (rule_code_le r q). specialize (IH q). lia.
Qed.

(** [c] is below every verdict of the policy's rules exactly when it is
    below the policy's verdict. *)
Lemma decide_ge : forall pol q c, c <= code_path ->
  c <= decide pol q <-> Forall (fun r => c <= rule_code r q) pol.
Proof.
  induction pol as [|r pol IH]; intros q c Hc; cbn.
  - split; auto.
  - rewrite lower_min, Forall_cons_iff, <- (IH q c Hc). lia.
Qed.

(** The policy's verdict is the verdict of one of its rules, or "path not
    allowed" for an empty policy. *)
Lemma decide_attained : forall pol q,
  decide pol q = code_path \/ exists r, In r pol /\ decide pol q = rule_code r q.
Proof.
  induction pol as [|r pol IH]; intro q; cbn; [auto|].
  rewrite lower_min. destruct (Nat.min_spec (rule_code r q) (decide pol q)) as [[_ ->]|[_ ->]].
  - right. exists r. auto.
  - destruct (IH q) as [H|[r' [Hin H]]]; [left; exact H|right; exists r'; auto].
Qed.

Ltac wf_of pol Hpol r Hin :=
  let H := fresh in pose proof (proj1 (Forall_forall _ pol) Hpol r Hin) as H.

(** A request is signed if and only if some rule of the policy allows its
    path, its amount and its destination. *)
Theorem sign_iff_complies : forall pol q,
  Forall wf_rule pol -> wf_request q ->
  decide pol q = 0 <-> exists r, In r pol /\ complies r q.
Proof.
  intros pol q Hpol Hq. split.
  - intro H0. destruct (decide_attained pol q) as [H|[r [Hin H]]].
    + unfold code_path in H. lia.
    + exists r. split; [exact Hin|].
      wf_of pol Hpol r Hin.
      destruct (rule_code_cases r q H1 Hq) as [(_ & ? & ? & ?)|[(C & _)|[(C & _)|(C & _)]]];
        [repeat split; assumption|..]; unfold code_dest, code_amount, code_path in C; lia.
  - intros [r [Hin (Hp & Ha & Hd)]].
    enough (decide pol q <= 0) by lia.
    destruct (Nat.le_gt_cases (decide pol q) 0) as [H|H]; [exact H|exfalso].
    apply (decide_ge pol q 1) in H; [|unfold code_path; lia].
    rewrite Forall_forall in H. specialize (H r Hin).
    wf_of pol Hpol r Hin.
    destruct (rule_code_cases r q H0 Hq) as [(C & _)|[(_ & _ & _ & N)|[(_ & _ & N)|(_ & N)]]];
      [rewrite C in H; lia|tauto..].
Qed.

(** "Path not allowed" means that no rule allows the path. *)
Theorem path_reject : forall pol q,
  Forall wf_rule pol -> wf_request q ->
  decide pol q = code_path <-> forall r, In r pol -> ~ path_ok r q.
Proof.
  intros pol q Hpol Hq. pose proof (decide_le pol q) as Hle.
  assert (E : decide pol q = code_path <-> code_path <= decide pol q) by lia.
  rewrite E, (decide_ge pol q code_path (le_n _)), Forall_forall.
  split; intros H r Hin; specialize (H r Hin); wf_of pol Hpol r Hin;
    destruct (rule_code_cases r q H0 Hq) as [(C & P & _)|[(C & P & _)|[(C & P & _)|(C & P)]]];
    unfold code_dest, code_amount, code_path in *; try lia; try tauto.
Qed.

(** "Amount over the limit" means that some rule allows the path, and every
    rule that allows the path has a lower limit. *)
Theorem amount_reject : forall pol q,
  Forall wf_rule pol -> wf_request q -> decide pol q = code_amount ->
  (exists r, In r pol /\ path_ok r q) /\
  (forall r, In r pol -> path_ok r q -> ~ amount_ok r q).
Proof.
  intros pol q Hpol Hq H. split.
  - destruct (decide_attained pol q) as [C|[r [Hin C]]];
      [rewrite H in C; discriminate|].
    exists r. split; [exact Hin|]. wf_of pol Hpol r Hin.
    destruct (rule_code_cases r q H0 Hq) as [(C' & P & _)|[(C' & P & _)|[(C' & P & _)|(C' & P)]]];
      try exact P; rewrite C' in C; rewrite H in C; discriminate.
  - pose proof (proj1 (decide_ge pol q code_amount ltac:(unfold code_amount, code_path; lia))
      ltac:(lia)) as G.
    intros r Hin Hp Ha. rewrite Forall_forall in G. specialize (G r Hin).
    wf_of pol Hpol r Hin.
    destruct (rule_code_cases r q H0 Hq) as [(C & _)|[(C & _)|[(_ & _ & N)|(_ & N)]]];
      [rewrite C in G|rewrite C in G|tauto|tauto]; unfold code_dest, code_amount in G; lia.
Qed.

(** "Destination not allowed" means that some rule allows the path and the
    amount, and none of the rules that do allows the destination. *)
Theorem dest_reject : forall pol q,
  Forall wf_rule pol -> wf_request q -> decide pol q = code_dest ->
  (exists r, In r pol /\ path_ok r q /\ amount_ok r q) /\
  (forall r, In r pol -> path_ok r q -> amount_ok r q -> ~ In (dest q) (dests r)).
Proof.
  intros pol q Hpol Hq H. split.
  - destruct (decide_attained pol q) as [C|[r [Hin C]]];
      [rewrite H in C; discriminate|].
    exists r. split; [exact Hin|]. wf_of pol Hpol r Hin.
    destruct (rule_code_cases r q H0 Hq) as [(C' & P & A & _)|[(C' & P & A & _)|[(C' & _)|(C' & _)]]];
      try (split; assumption); rewrite C' in C; rewrite H in C; discriminate.
  - pose proof (proj1 (decide_ge pol q code_dest ltac:(unfold code_dest, code_path; lia))
      ltac:(lia)) as G.
    intros r Hin Hp Ha Hd. rewrite Forall_forall in G. specialize (G r Hin).
    wf_of pol Hpol r Hin.
    destruct (rule_code_cases r q H0 Hq) as [(C & _)|[(_ & _ & _ & N)|[(_ & _ & N)|(_ & N)]]];
      [rewrite C in G; unfold code_dest in G; lia|tauto..].
Qed.

(** ** The driver *)

Lemma le_at_spec : forall n a b, le_at n a b = lex_leb (read_bytes a n) (read_bytes b n).
Proof.
  induction n as [|n IH]; intros a b; cbn [le_at read_bytes lex_leb]; [reflexivity|].
  rewrite IH. reflexivity.
Qed.

Lemma eq_at_spec : forall n a b, eq_at n a b = bytes_eqb (read_bytes a n) (read_bytes b n).
Proof.
  induction n as [|n IH]; intros a b; cbn [eq_at read_bytes bytes_eqb]; [reflexivity|].
  rewrite IH. reflexivity.
Qed.

Lemma mem_at_spec : forall k pos q,
  mem_at k pos q = mem_addr (read_bytes q addr_len) (read_addrs k pos).
Proof.
  induction k as [|k IH]; intros pos q; cbn [mem_at read_addrs mem_addr]; [reflexivity|].
  rewrite eq_at_spec, IH. reflexivity.
Qed.

Lemma path_at_spec : forall d qd rpos qpos,
  path_at d qd rpos qpos = path_matchb (read_path qd qpos) (read_pattern d rpos).
Proof.
  induction d as [|d IH]; intros [|qd] rpos qpos;
    cbn [path_at read_path read_pattern path_matchb]; try reflexivity.
  rewrite !le_at_spec, IH. reflexivity.
Qed.

Lemma rule_code_at_spec : forall rpos qpos,
  rule_code_at rpos qpos = rule_code (fst (read_rule rpos)) (fst (read_request qpos)).
Proof.
  intros rpos qpos. unfold rule_code_at, rule_code, read_rule, read_request.
  cbn beta iota zeta delta [fst pattern limit dests path amount dest].
  rewrite path_at_spec, le_at_spec, mem_at_spec. reflexivity.
Qed.

Lemma eval_rules_decide : forall k rpos qpos best, best <= code_path ->
  eval_rules k rpos qpos best =
  Nat.min best (decide (read_rules k rpos) (fst (read_request qpos))).
Proof.
  induction k as [|k IH]; intros rpos qpos best Hb; cbn [eval_rules read_rules decide].
  - unfold code_path in *. lia.
  - rewrite rule_code_at_spec. change (rule_end rpos) with (snd (read_rule rpos)).
    set (q := fst (read_request qpos)). set (r := fst (read_rule rpos)).
    rewrite lower_min. pose proof (rule_code_le r q) as Hc.
    destruct (Nat.eqb_spec (rule_code r q) 0) as [->|Hne]; [cbn; lia|].
    rewrite IH by (rewrite ?lower_min; lia). unfold q, r in *. rewrite ?lower_min. lia.
Qed.

Lemma process_spec : forall k qpos n rules,
  process k qpos n rules = map (decide (read_rules n rules)) (read_requests k qpos).
Proof.
  induction k as [|k IH]; intros qpos n rules; cbn [process read_requests map]; [reflexivity|].
  rewrite eval_rules_decide by (unfold code_path; lia).
  change (request_end qpos) with (snd (read_request qpos)).
  rewrite IH. f_equal.
  pose proof (decide_le (read_rules n rules) (fst (read_request qpos))). unfold code_path in *. lia.
Qed.

(** The driver computes [decide] over the decoded policy. *)
Theorem run_spec : forall n, run n = map (decide (policy n)) requests.
Proof. intro n. unfold run, policy, rules_offset, requests. apply process_spec. Qed.

(** ** Decoded data is well formed *)

(** The host returns bytes (the assumption of ExtrEncoreInput.v). *)
Definition input_bytes : Prop := forall i, input_byte i < 256.

Lemma read_bytes_length : forall n pos, length (read_bytes pos n) = n.
Proof. induction n; intro pos; cbn; auto. Qed.

Lemma read_bytes_bytes : input_bytes -> forall n pos, bytes (read_bytes pos n).
Proof. intro Hi. unfold input_bytes in Hi. unfold bytes. induction n; intro pos; cbn; constructor; auto. Qed.

Lemma read_rule_wf : input_bytes -> forall pos, wf_rule (fst (read_rule pos)).
Proof.
  intros Hi pos. unfold read_rule, wf_rule.
  cbn beta iota zeta delta [fst pattern limit dests].
  split; [|split; [apply read_bytes_length|apply read_bytes_bytes, Hi]].
  generalize (S pos). generalize (input_byte pos).
  induction n as [|d IH]; intro p; cbn [read_pattern]; constructor; auto.
  unfold wf_range, elem; cbn [fst snd].
  repeat split; (apply read_bytes_length || apply read_bytes_bytes, Hi).
Qed.

Lemma read_request_wf : input_bytes -> forall pos, wf_request (fst (read_request pos)).
Proof.
  intros Hi pos. unfold read_request, wf_request.
  cbn beta iota zeta delta [fst path amount dest].
  split; [|split; [apply read_bytes_length|apply read_bytes_bytes, Hi]].
  generalize (S pos). generalize (input_byte pos).
  induction n as [|d IH]; intro p; cbn [read_path]; constructor; auto.
  split; [apply read_bytes_length|apply read_bytes_bytes, Hi].
Qed.

Lemma read_rules_wf : input_bytes -> forall k pos, Forall wf_rule (read_rules k pos).
Proof. intro Hi. induction k; intro pos; cbn [read_rules]; constructor; auto using read_rule_wf. Qed.

Lemma read_requests_wf : input_bytes -> forall k pos, Forall wf_request (read_requests k pos).
Proof. intro Hi. induction k; intro pos; cbn [read_requests]; constructor; auto using read_request_wf. Qed.

(** The end-to-end property: the [i]-th verdict of [run n] is "sign" if and
    only if one of the first [n] rules of the policy allows the [i]-th
    request, and a refusal gives a true reason. *)
Theorem run_signs_only_compliant : input_bytes -> forall n i q c,
  nth_error requests i = Some q -> nth_error (run n) i = Some c ->
  (c = 0 <-> exists r, In r (policy n) /\ complies r q) /\
  (c = code_path <-> forall r, In r (policy n) -> ~ path_ok r q).
Proof.
  intros Hi n i q c Hq Hc.
  rewrite run_spec, nth_error_map, Hq in Hc. injection Hc as <-.
  pose proof (read_rules_wf Hi n rules_offset) as Hpol.
  pose proof (proj1 (Forall_forall _ _) (read_requests_wf Hi (input_byte 0) hdr_len) q
                (nth_error_In _ _ Hq)) as Hwq.
  split; [apply sign_iff_complies|apply path_reject]; assumption.
Qed.

(** Nothing but [input_byte] (a parameter, realised by the host) is
    assumed. *)
Print Assumptions run_signs_only_compliant.
