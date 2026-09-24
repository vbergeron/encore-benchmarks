(** CertiRocq setup shared by the C variant of every workload: the
    counterpart of Encore.Extraction.ExtrEncore and ExtrEncoreInput
    (vendor/encore-extraction) for Encore, so that C and E run the same
    Gallina under the same trust assumptions.

    - [nat] becomes a machine integer (31 bits), through three axioms
      realised in C by certirocq/runtime/bench_rt.c: zero, successor and
      case analysis. Unproven, like the Encore mapping, and wrong past
      2^30 - 1.
    - [Nat.add], [sub], [mul], [pred], [eqb], [leb], [ltb], [div],
      [modulo] and [land] become C functions on those integers instead of
      recursive Gallina.
    - [input_byte] (ExtrEncoreInput.v) reads the host's input buffer.

    ExtrEncore maps more [Nat] operations than this file (min, max, lor,
    shifts, ...). No workload uses them yet; one that does must register
    them here too, or C would run them as recursive Gallina.

    The nat mapping is applied by an erasure pass that MetaRocq only runs
    with [-unsafe-erasure] (it is not verified), so every CompileC.v
    passes that flag. Without this file CertiRocq would compile [nat] as
    unary constructors, which needs no assumption but makes every byte a
    chain of up to 255 heap cells. *)

From CertiRocq.Plugin Require Import CertiRocq.
From Encore.Extraction Require Import ExtrEncoreInput.

Axiom nat_zero : nat.
Axiom nat_succ : nat -> nat.
Axiom nat_case : forall {A : Type}, nat -> (unit -> A) -> (nat -> A) -> A.

CertiRocq Extract Inductive To Constants [
  nat => [ [ nat_zero nat_succ | nat_case ] ] ].

CertiRocq Register [
  nat_zero => "bench_nat_zero",
  nat_succ => "bench_nat_succ",
  nat_case => "bench_nat_case" 3 with tinfo,
  Corelib.Init.Nat.pred => "bench_nat_pred",
  Corelib.Init.Nat.add => "bench_nat_add",
  Corelib.Init.Nat.sub => "bench_nat_sub",
  Corelib.Init.Nat.mul => "bench_nat_mul",
  Corelib.Init.Nat.eqb => "bench_nat_eqb",
  Corelib.Init.Nat.leb => "bench_nat_leb",
  Corelib.Init.Nat.ltb => "bench_nat_ltb",
  Corelib.Init.Nat.div => "bench_nat_div",
  Corelib.Init.Nat.modulo => "bench_nat_mod",
  Corelib.Init.Nat.land => "bench_nat_land",
  input_byte => "bench_input_byte"
] Include [ "bench_rt.h" ].
