(** W0 — smoke workload. Not part of the study: it exists to exercise the
    whole pipeline (Rocq → Scheme → Encore bytecode → firmware → JSONL) and
    serves as the template for W1–W8.

    [run n] builds the list [1; ...; n] and folds it, so it allocates [n]
    cons cells and gives the GC something to do. *)

From Stdlib Require Import Arith List Lia.
Import ListNotations.

Fixpoint range_from (k n : nat) : list nat :=
  match n with
  | O => []
  | S n' => k :: range_from (S k) n'
  end.

Fixpoint sum (l : list nat) : nat :=
  match l with
  | [] => 0
  | x :: xs => x + sum xs
  end.

Definition run (n : nat) : nat := sum (range_from 1 n).

(** Proved property: [run] computes the closed form. *)
Lemma sum_range_from : forall n k,
  2 * sum (range_from k n) + n = n * (2 * k + n).
Proof.
  induction n as [|n IH]; intro k; cbn [range_from sum].
  - reflexivity.
  - specialize (IH (S k)). nia.
Qed.

Theorem run_spec : forall n, 2 * run n = n * (n + 1).
Proof. intro n. unfold run. pose proof (sum_range_from n 1). nia. Qed.
