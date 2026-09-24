# encore-benchmarks

Benchmarks for [Encore](https://github.com/vbergeron/encore), a bytecode VM
that runs Rocq-extracted, formally verified logic on microcontrollers. The
study compares three ways of shipping the same firmware logic:

| Variant | Toolchain | Role |
|---|---|---|
| **E** | Gallina → Scheme → Encore bytecode → `encore_vm` | system under study |
| **C** | Gallina → CertiRocq → Clight → gcc -Os | closest verified competitor |
| **R** | idiomatic Rust `no_std`, no allocator | performance ceiling, **output oracle** |

The experiment plan is in [PLAN.md](PLAN.md): research questions Q1–Q5,
metrics, workloads W1–W8, boards and threats to validity. This repository
implements it, with one change: the plan's fourth variant, **R+V** (the Rust checked with Kani or Verus, "verify
the Rust directly"), is not measured. It is an alternative to the approach
under study rather than a point of comparison: it proves properties of
hand-written Rust, not the Gallina that E and C compile, so it would answer a
different question. Its runtime cost is R's, since the checks happen at build
time.

## Status

| Piece | State |
|---|---|
| Device harness (`crates/bench_harness`) | done: regions, DWT cycles, stack painting, JSONL records |
| Build helper (`crates/bench_build`) | done: board budgets → `memory.x`, Encore bytecode |
| Runner (`xtask`, run as `cargo xtask`) | done: QEMU instruction counts per region, sizes, oracle check, min-heap search |
| Rocq with dune (`theories/`, `workloads/*/theories`) | done: shared extraction setup, extraction promoted to `.scm` |
| QEMU boards (M3 and M33) | done |
| W0 smoke workload, variants E, R and C | done, runs on both QEMU boards |
| Real boards (STM32U5, nRF52840) | board files and DWT path written, **not validated on hardware** |
| GC pause and GC count metrics | `encore_vm` exposes them since 0.1.5 (`stats` feature, `GcStats`); not yet recorded by the workloads |
| Variant C (CertiRocq), W0, W1, W2, W4 and W6 | done, run on both QEMU boards; see `certirocq/` |
| W1 (APDU + BER-TLV), W2 (RLP transaction decoder), variants E, R and C | done, run on both QEMU boards |
| W4 (PIN state machine), W6 (COBS), variants E, R and C | done, run on both QEMU boards |
| Workloads W3, W5, W7, W8 | not started (W7 next, per [the plan](PLAN.md#priorities-and-steps)) |

## Layout

```
PLAN.md              the experiment plan: questions, metrics, workloads, boards
boards/              one TOML per board: target, memory origins, runner
crates/bench_harness no_std, on the device: regions, cycles, stack, records
crates/bench_build   build.rs helper: memory.x from budget, bench_config.rs, bytecode
vendor/              Encore's Rocq extraction theory (Encore.Extraction), verbatim
workloads/<w>/       one directory per workload, see workloads/README.md
certirocq/           C variant: CertiRocq nat mapping, runtime, generation scripts
xtask/               host runner (`cargo xtask`): build, run, record, check
results/             benchmarks.jsonl (one row per case), see results/README.md
```

## Quick start

Requirements: rustup (the toolchain is pinned to Rust 1.88 by
`rust-toolchain.toml`) and `qemu-system-arm`; the runner is the `xtask`
crate of the workspace, so there is nothing else to install. For the Rocq
side: Rocq 9.1 with its Stdlib 9.1, and dune ≥ 3.21 (`opam install
--deps-only .` installs them).

```bash
# Rocq: check the proofs, and re-extract the Scheme (promoted into the tree)
dune build

# Host unit tests of the harness, the build helper and the runner
cargo test

# Run W0 on QEMU (Cortex-M3), both variants, and record the results
cargo xtask run -w w0_smoke -v r
cargo xtask run -w w0_smoke -v e
cargo xtask run -w w0_smoke -v e -b qemu-an505          # Cortex-M33
cargo xtask run -w w0_smoke -v e --cps-optimize off     # isolate the optimizer
cargo xtask run -w w0_smoke -v e --profile memory       # heap peak, VM ops

# Every variant must reproduce the R oracle's outputs
cargo xtask check

# Smallest Encore heap at which every case still passes
cargo xtask minheap -w w0_smoke -v e
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
   (`-d in_asm,exec,nochain`, read from QEMU's stderr as it runs) and
   counts the instructions executed between the two markers of each
   region, minus the same calibration. The count is exact and reproducible, but it is
   instructions, not time: speed conclusions come from boards only.
5. The runner adds what only the host knows (commit, Encore and rustc
   versions, board, budget, ELF section sizes and a per-crate flash
   breakdown) and appends one row per case to `results/benchmarks.jsonl`.
6. `cargo xtask check` compares each variant's `out_hash` with the latest R
   row for the same workload and N. A mismatch is a bug to fix before
   measuring.

The `stats` feature of `encore_vm` (heap peak, op count) puts a counter in
the dispatch loop, so it is only enabled with `--profile memory`, never
when counting instructions or cycles.

## Rocq

The Rocq side builds with dune (`dune-project` at the root, `rocq.theory`
stanzas). The extraction directives come from Encore itself: the
theory `Encore.Extraction` from Encore's `rocq/`, copied verbatim into
`vendor/encore-extraction/` at the same release as the Rust crates.
`ExtrEncore.v` makes `nat` a 24-bit VM integer (an operation that leaves
that range traps with `IntOverflow`), maps `Nat.add`, `sub`, `mul`,
`pred`, `min`, `max`, the comparisons, `div`, `modulo` and the bitwise
operations to VM primitives, and pins `bool`, `list` and `prod` to the
constructor tags the VM pre-registers. Every workload imports it, so they
all rest on the same (documented, unproven) assumptions, listed in
Encore's `SCHEME.md`. `ExtrEncoreInput.v` declares `input_byte`, an axiom
realised by an Encore extern in slot 0, through which workloads read their
input buffer (APDU stream, frame) from the host instead of having Rust
build lists on the VM heap.

Each workload's `theories/dune` has a rule that runs its `Extract.v` and
**promotes** the resulting `.scm` into the source tree. The `.scm` is
committed, so building firmware needs Rust only, and CI checks that
`dune build` leaves it unchanged.
