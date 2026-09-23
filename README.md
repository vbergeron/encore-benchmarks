# encore-benchmarks

Benchmarks for [Encore](https://github.com/vbergeron/encore), a bytecode VM
that runs Rocq-extracted, formally verified logic on microcontrollers. The
study compares four ways of shipping the same firmware logic:

| Variant | Toolchain | Role |
|---|---|---|
| **E** | Gallina → Scheme → Encore bytecode → `encore_vm` | system under study |
| **C** | Gallina → CertiRocq → Clight → gcc -Os | closest verified competitor |
| **R** | idiomatic Rust `no_std`, no allocator | performance ceiling, **output oracle** |
| **R+V** | Rust + Kani or Verus | "verify the Rust directly" |

The full experiment plan is *Encore — plan d'expérience comparatif* (in
French): research questions Q1–Q5, metrics, workloads W1–W8, boards and
threats to validity. This repository implements it.

## Status

| Piece | State |
|---|---|
| Device harness (`crates/bench_harness`) | done: regions, DWT cycles, stack painting, JSONL records |
| Build helper (`crates/bench_build`) | done: board budgets → `memory.x`, Encore bytecode |
| Runner (`scripts/bench.py`) | done: QEMU instruction counts per region, sizes, oracle check, min-heap search |
| Rocq with dune (`theories/`, `workloads/*/theories`) | done: shared extraction setup, extraction promoted to `.scm` |
| QEMU boards (M3 and M33) | done |
| W0 smoke workload, variants E and R | done, runs on both QEMU boards |
| Real boards (STM32U5, nRF52840) | board files and DWT path written, **not validated on hardware** |
| GC pause and GC count metrics | need instrumentation in `encore_vm` (not in 0.1.4) |
| Variants C and R+V | not started |
| Workloads W1–W8 | not started (W4 then W1 first, per the plan) |

## Layout

```
boards/              one TOML per board: target, memory origins, runner
crates/bench_harness no_std, on the device: regions, cycles, stack, records
crates/bench_build   build.rs helper: memory.x from budget, bench_config.rs, bytecode
theories/            Rocq, shared: EncoreExtraction.v (nat → VM integers, ...)
workloads/<w>/       one directory per workload, see workloads/README.md
scripts/bench.py     build, run, record, check
results/             benchmarks.jsonl (one row per case), see results/README.md
```

## Quick start

Requirements: rustup (the toolchain is pinned to Rust 1.88 by
`rust-toolchain.toml`), `qemu-system-arm`, `arm-none-eabi-binutils` (for
`nm` and `size`), Python ≥ 3.11. For the Rocq side: Rocq 9.1 with its Stdlib 9.1,
and dune ≥ 3.21 (`opam install --deps-only .` installs them).

```bash
# Rocq: check the proofs, and re-extract the Scheme (promoted into the tree)
dune build

# Host unit tests of the harness
cargo test

# Run W0 on QEMU (Cortex-M3), both variants, and record the results
scripts/bench.py run -w w0_smoke -v r
scripts/bench.py run -w w0_smoke -v e
scripts/bench.py run -w w0_smoke -v e -b qemu-an505          # Cortex-M33
scripts/bench.py run -w w0_smoke -v e --cps-optimize off     # isolate the optimizer
scripts/bench.py run -w w0_smoke -v e --profile memory       # heap peak, VM ops

# Every variant must reproduce the R oracle's outputs
scripts/bench.py check

# Smallest Encore heap at which every case still passes
scripts/bench.py minheap -w w0_smoke -v e
```

`--dry-run` prints the records without appending to `results/`.

## How a measurement works

1. `bench_build` reads `boards/<board>.toml` and writes a `memory.x` whose
   RAM and flash lengths are the **budget** (default 50 KiB RAM, the
   ST33J2M0; `--ram-kb 64` for the ST33K1M5), not the physical size. A
   workload that does not fit fails at link time, which is recorded as a
   failed row: that answers Q1.
2. The firmware calls `Session::case` once per input vector. It runs the
   workload once untimed and hashes the output (FNV-1a), paints the stack,
   then runs it `reps` times, each run bracketed by `bench_region_begin` /
   `bench_region_end`, and prints a `@@BENCH {...}` JSON line.
3. On boards with a DWT, the harness reads `CYCCNT` around each run and
   reports min / median / p99 / max cycles, minus the overhead of an empty
   region measured at start-up.
4. On QEMU, cycles do not exist. The runner traces execution
   (`-d in_asm,exec,nochain`, streamed through a FIFO) and counts the
   instructions executed between the two markers of each region, minus the
   same calibration. The count is exact and reproducible, but it is
   instructions, not time: speed conclusions come from boards only.
5. The runner adds what only the host knows (commit, Encore and rustc
   versions, board, budget, ELF section sizes and a per-crate flash
   breakdown) and appends one row per case to `results/benchmarks.jsonl`.
6. `bench.py check` compares each variant's `out_hash` with the latest R
   row for the same workload and N. A mismatch is a bug to fix before
   measuring.

The `stats` feature of `encore_vm` (heap peak, op count) puts a counter in
the dispatch loop, so it is only enabled with `--profile memory`, never
when counting instructions or cycles.

## Rocq

The Rocq side builds with dune (`dune-project` at the root, `rocq.theory`
stanzas). `theories/EncoreExtraction.v` holds the extraction directives
shared by every workload: `nat` becomes a 24-bit VM integer, and
`Init.Nat.{add,mul,sub,eqb,leb,ltb}` become VM primitives. Every workload
imports it, so they all rest on the same (documented, unproven) assumption.

Each workload's `theories/dune` has a rule that runs its `Extract.v` and
**promotes** the resulting `.scm` into the source tree. The `.scm` is
committed, so building firmware needs Rust only, and CI checks that
`dune build` leaves it unchanged.
