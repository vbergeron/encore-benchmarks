(** Shared extraction setup for the Encore (E) variant of every workload.

    Importing this module brings the directives below into scope, so each
    workload's extraction file only names its entry points. The same
    directives must be used by every workload: a benchmark that extracts
    [nat] differently from another is not comparable to it.

    Trust assumption (see the plan, "Extraction de nat vers des entiers
    machine"): [nat] becomes a 24-bit VM integer. This is unproven and wrong
    past 2^23 - 1; workloads must keep their values under that bound and say
    so in their README. *)

From Stdlib Require Extraction.

(** [Nat.*] below must be [Init.Nat.*], the constants [+], [*], [=?] ...
    unfold to. Importing [Arith] first would make [Nat] resolve to
    [PeanoNat.Nat], whose constants are distinct, and the directives would
    silently not apply. Hence the fully qualified names. *)

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
