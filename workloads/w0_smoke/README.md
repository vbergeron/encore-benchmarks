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
- **Trust**: `nat` is extracted to VM integers (`vendor/encore-extraction/ExtrEncore.v`).
- **Heap**: 32 KiB by default; `cargo xtask minheap` finds 31.5 KiB for N = 1000
  on the lm3s6965 with the CPS optimizer, and N = 1000 does not fit with
  `--cps-optimize off`.

- **C** (CertiRocq, `certirocq/`): the arena gets the same 32 KiB as the E
  heap, 2^10-word nursery by default, and C runs every N. The direct-style
  C recurses once per element in `range_from` and `sum`. RAM in all
  (statics + peak stack) at the smallest arena that passes, with the best
  nursery of 2^6 to 2^10 words (`cargo xtask minheap -v c --c-log-nursery
  k`, results/minheap.jsonl, lm3s6965): N = 1: 5.2 KiB (2^6, 8.9 with the
  default 2^10; E 5.1); N = 10: 6.0 KiB (2^7, 9.5 with the default 2^10; E
  5.4); N = 100: 14.1 KiB (2^8, 23.1 with the default 2^10; E 8.1). N =
  1000 fails at every arena and nursery size: the C stack runs out, and a
  larger arena only leaves it less of the RAM budget.

The R variant is `(1..=n).sum()`, which LLVM folds into a closed form: the
instruction count does not depend on N. That is a fair result for
idiomatic Rust, and a reminder that W0 measures nothing about the study.
