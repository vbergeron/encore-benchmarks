(** W4 — PIN state machine (ISO 7816-4 VERIFY, CHANGE REFERENCE DATA,
    RESET RETRY COUNTER), driven by a stream of command APDUs.

    The card holds a PIN with a retry counter and a PUK with its own retry
    counter. A wrong PIN decrements the PIN counter; at zero the PIN is
    blocked and only the PUK can reset it; a wrong PUK decrements the PUK
    counter, and at zero the card is dead. The property that matters is the
    one a fault attack or a logic bug would break: a counter never goes
    back up without the matching secret. *)

From Stdlib Require Import Arith List Lia Bool.
Import ListNotations.
From EncoreBench.Common Require Import EncoreInput.

(** Constants. Each one is extracted to a VM integer literal by
    [Extract.v]: a [nat] literal would otherwise extract to a chain of
    successor applications. *)
Definition max_tries := 3.
Definition max_puk_tries := 10.
Definition puk_len := 8.
Definition ins_verify := 32.     (* 0x20 VERIFY *)
Definition ins_change := 36.     (* 0x24 CHANGE REFERENCE DATA *)
Definition ins_unblock := 44.    (* 0x2C RESET RETRY COUNTER *)
Definition ins_select := 164.    (* 0xA4 SELECT: resets the security status *)

Record state := mk_state {
  pin : list nat;
  puk : list nat;
  tries : nat;       (* PIN attempts left *)
  puk_tries : nat;   (* PUK attempts left *)
  auth : bool        (* PIN verified in this session *)
}.

Inductive cmd :=
| Verify (guess : list nat)
| Change (new_pin : list nat)
| Unblock (puk_guess new_pin : list nat)
| Select
| Unknown.

Inductive resp :=
| Ok
| Wrong (left : nat)   (* SW 63Cx *)
| Blocked              (* SW 6983 *)
| Denied               (* SW 6982 *)
| BadIns.              (* SW 6D00 *)

Fixpoint digits_eqb (a b : list nat) : bool :=
  match a, b with
  | [], [] => true
  | x :: a', y :: b' => if x =? y then digits_eqb a' b' else false
  | _, _ => false
  end.

Definition step (s : state) (c : cmd) : state * resp :=
  match c with
  | Verify g =>
      match tries s with
      | O => (mk_state (pin s) (puk s) 0 (puk_tries s) false, Blocked)
      | S t =>
          if digits_eqb g (pin s)
          then (mk_state (pin s) (puk s) max_tries (puk_tries s) true, Ok)
          else (mk_state (pin s) (puk s) t (puk_tries s) false, Wrong t)
      end
  | Change p =>
      if auth s then (mk_state p (puk s) (tries s) (puk_tries s) true, Ok)
      else (s, Denied)
  | Unblock k p =>
      match puk_tries s with
      | O => (s, Blocked)
      | S t =>
          if digits_eqb k (puk s)
          then (mk_state p (puk s) max_tries max_puk_tries false, Ok)
          else (mk_state (pin s) (puk s) (tries s) t false, Wrong t)
      end
  | Select => (mk_state (pin s) (puk s) (tries s) (puk_tries s) false, Ok)
  | Unknown => (s, BadIns)
  end.

(** * Driver: APDUs from the input buffer *)

(** An APDU is [INS Lc data(Lc)] (CLA, P1 and P2 are left out). For
    RESET RETRY COUNTER the data is the PUK followed by the new PIN. *)
Definition decode_cmd (ins : nat) (data : list nat) : cmd :=
  if ins =? ins_verify then Verify data
  else if ins =? ins_change then Change data
  else if ins =? ins_unblock then Unblock (firstn puk_len data) (skipn puk_len data)
  else if ins =? ins_select then Select
  else Unknown.

(** Response code written to the output list: 0 ok, 1 blocked, 2 denied,
    3 bad instruction, [4 + n] wrong secret with [n] attempts left. *)
Definition code (r : resp) : nat :=
  match r with
  | Ok => 0
  | Blocked => 1
  | Denied => 2
  | BadIns => 3
  | Wrong n => 4 + n
  end.

(** Handle [k] APDUs starting at byte [pos] of the input. *)
Fixpoint process (k : nat) (s : state) (pos : nat) : list nat :=
  match k with
  | O => []
  | S k' =>
      let ins := input_byte pos in
      let lc := input_byte (S pos) in
      let (s', r) := step s (decode_cmd ins (read_bytes (S (S pos)) lc)) in
      code r :: process k' s' (S (S pos) + lc)
  end.

Definition init : state :=
  mk_state [1; 2; 3; 4] [1; 2; 3; 4; 5; 6; 7; 8] max_tries max_puk_tries false.

Definition run (n : nat) : list nat := process n init 0.

(** * Properties *)

Lemma digits_eqb_eq : forall a b, digits_eqb a b = true <-> a = b.
Proof.
  induction a as [|x a IH]; intros [|y b]; cbn; split; intro H;
    try discriminate; try reflexivity.
  - destruct (Nat.eqb_spec x y); [|discriminate].
    apply IH in H. subst. reflexivity.
  - injection H as -> ->. rewrite Nat.eqb_refl. apply IH. reflexivity.
Qed.

Ltac step_cases :=
  intros [pn pk t pt a] c; destruct c as [g|p|k p| |]; cbn in *;
  [ destruct t as [|t]; [|destruct (digits_eqb g pn) eqn:E]
  | destruct a
  | destruct pt as [|pt]; [|destruct (digits_eqb k pk) eqn:E]
  | | ]; cbn in *.

(** The PIN counter only goes up on a correct PIN (while not blocked) or
    a correct PUK (while the PUK is not blocked). *)
Theorem tries_up_only_with_secret : forall s c,
  tries s < tries (fst (step s c)) ->
  (exists g, c = Verify g /\ g = pin s /\ 0 < tries s) \/
  (exists k p, c = Unblock k p /\ k = puk s /\ 0 < puk_tries s).
Proof.
  step_cases; intro H; try lia.
  - left. exists g. apply digits_eqb_eq in E. repeat split; auto; lia.
  - right. exists k, p. apply digits_eqb_eq in E. repeat split; auto; lia.
Qed.

(** The PUK counter only goes up on a correct PUK. *)
Theorem puk_tries_up_only_with_puk : forall s c,
  puk_tries s < puk_tries (fst (step s c)) ->
  exists k p, c = Unblock k p /\ k = puk s /\ 0 < puk_tries s.
Proof.
  step_cases; intro H; try lia.
  exists k, p. apply digits_eqb_eq in E. repeat split; auto; lia.
Qed.

(** Authentication is never gained without presenting the PIN. *)
Theorem auth_only_with_pin : forall s c,
  auth (fst (step s c)) = true ->
  (exists g, c = Verify g /\ g = pin s /\ 0 < tries s) \/ auth s = true.
Proof.
  step_cases; intro H; try discriminate; auto.
  left. exists g. apply digits_eqb_eq in E. repeat split; auto; lia.
Qed.

(** The counters stay within their bounds. *)
Theorem counters_bounded : forall s c,
  tries s <= max_tries -> puk_tries s <= max_puk_tries ->
  tries (fst (step s c)) <= max_tries /\
  puk_tries (fst (step s c)) <= max_puk_tries.
Proof. step_cases; unfold max_tries, max_puk_tries in *; lia. Qed.

Fixpoint run_cmds (s : state) (cs : list cmd) : state :=
  match cs with
  | [] => s
  | c :: cs' => run_cmds (fst (step s c)) cs'
  end.

(** With both counters at zero the card is dead: no sequence of commands
    authenticates or brings a counter back. *)
Theorem locked_forever : forall cs s,
  tries s = 0 -> puk_tries s = 0 -> auth s = false ->
  tries (run_cmds s cs) = 0 /\ puk_tries (run_cmds s cs) = 0 /\
  auth (run_cmds s cs) = false.
Proof.
  induction cs as [|c cs IH]; intros s Ht Hp Ha; cbn; [auto|].
  apply IH; revert Ht Hp Ha; revert s c; step_cases; intros; subst;
    first [discriminate | reflexivity].
Qed.
