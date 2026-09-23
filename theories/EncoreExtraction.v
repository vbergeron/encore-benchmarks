(** Shared extraction setup for the Encore (E) variant of every workload.

    Importing this module brings the directives below into scope, so each
    workload's extraction file only names its entry points. The same
    directives must be used by every workload: a benchmark that extracts
    [nat] differently from another is not comparable to it.

    Trust assumption (see PLAN.md, "Threats to validity", extraction of
    [nat] to machine integers): [nat] becomes a 24-bit VM integer. This is unproven and wrong
    past 2^23 - 1; workloads must keep their values under that bound and say
    so in their README. *)

From Stdlib Require Extraction.

(** The directives name [Init.Nat.*], the constants [+], [*], [-] unfold
    to, and also [PeanoNat.Nat.*]: importing [Arith] makes [Nat] and the
    [=?], [<=?], [<?] notations resolve to [PeanoNat.Nat], whose constants
    are aliases that extraction treats as distinct. Without the second set
    the directives would silently not apply and [=?] would extract to a
    recursive Gallina [eqb]. Hence the fully qualified names. *)

From Stdlib Require Arith.PeanoNat.

Extraction Language Scheme.

Extract Inductive nat => "integer"
  ["0" "(lambda (x) (+ x 1))"]
  "(lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))".

(** Arithmetic and comparisons map to VM primitives. The VM has no division
    and no bitwise operations, so [Nat.div], [Nat.modulo], [Nat.land], ...
    stay as extracted Gallina (slow, but honest). *)
Extract Constant Init.Nat.add => "(lambda (n) (lambda (m) (+ n m)))".
Extract Constant Init.Nat.mul => "(lambda (n) (lambda (m) (* n m)))".
Extract Constant Init.Nat.sub =>
  "(lambda (n) (lambda (m) (if (< n m) 0 (- n m))))".
Extract Constant Init.Nat.eqb =>
  "(lambda (a) (lambda (b) (if (= a b) `(True) `(False))))".
Extract Constant Init.Nat.leb =>
  "(lambda (a) (lambda (b) (if (< b a) `(False) `(True))))".
Extract Constant Init.Nat.ltb =>
  "(lambda (a) (lambda (b) (if (< a b) `(True) `(False))))".

Extract Constant PeanoNat.Nat.add => "(lambda (n) (lambda (m) (+ n m)))".
Extract Constant PeanoNat.Nat.mul => "(lambda (n) (lambda (m) (* n m)))".
Extract Constant PeanoNat.Nat.sub =>
  "(lambda (n) (lambda (m) (if (< n m) 0 (- n m))))".
Extract Constant PeanoNat.Nat.eqb =>
  "(lambda (a) (lambda (b) (if (= a b) `(True) `(False))))".
Extract Constant PeanoNat.Nat.leb =>
  "(lambda (a) (lambda (b) (if (< b a) `(False) `(True))))".
Extract Constant PeanoNat.Nat.ltb =>
  "(lambda (a) (lambda (b) (if (< a b) `(True) `(False))))".
