# W0 — smoke

Not part of the study. It checks that the whole pipeline works (Rocq →
dune extraction → Scheme → Encore bytecode → firmware → JSONL → oracle
check) and is the template for W1–W8.

- **Program**: `run n = sum (range_from 1 n)`, which builds the list
  `[1; …; n]` and folds it, so the E variant allocates `n` cons cells and
  `n` continuations (`sum` is not tail-recursive).
- **Proved**: `run_spec : forall n, 2 * run n = n * (n + 1)`.
- **N**: 1, 10, 100, 1000. The result must stay below 2^23 (Encore
  integers), so N ≤ 4095; past that the VM traps with `IntOverflow`
  (encore ≥ 0.1.6) instead of returning a wrapped sum.
- **Trust**: `nat` is extracted to VM integers (`EncoreExtraction.v`).
- **Heap**: 32 KiB by default; `cargo xtask minheap` finds 31.5 KiB for N = 1000
  on the lm3s6965 with the CPS optimizer, and N = 1000 does not fit with
  `--cps-optimize off`.

The R variant is `(1..=n).sum()`, which LLVM folds into a closed form: the
instruction count does not depend on N. That is a fair result for
idiomatic Rust, and a reminder that W0 measures nothing about the study.
