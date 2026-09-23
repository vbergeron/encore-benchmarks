# Results

`benchmarks.jsonl` holds one JSON object per line, one line per (run, case).
Rows are only appended; `cargo xtask check` and any analysis use the
latest row for each (workload, variant, board, N).

| Field | Meaning |
|---|---|
| `schema` | row format version (1) |
| `timestamp`, `label` | when, and a free-form tag (`--label`) |
| `commit`, `dirty` | this repository's commit; `dirty` = uncommitted changes to tracked files |
| `encore_version`, `rustc` | from `Cargo.lock` and `rustc --version` |
| `workload`, `variant`, `n` | what was measured (`E`, `C`, `R`) |
| `board`, `core`, `target` | where (see `boards/`) |
| `profile` | `timing` (instructions/cycles, no VM stats) or `memory` (VM stats on) |
| `ok`, `reason` | `false` with a reason when the case failed (VM error, budget exceeded at link time, or a timed run failed) |
| `timed_ok` | E only: every timed run returned without a VM error. `false` makes the row `ok: false`: its counts measure a partial run |
| `out_hash` | FNV-1a of the output; must equal the R row's (`cargo xtask check`) |
| `insns` | QEMU only: `{min, median, p99, max}` instructions per run, calibration subtracted |
| `cycles` | DWT boards only: `{min, median, p99, max}` cycles per run, calibration subtracted |
| `stack_peak_bytes` | stack painting; the Encore VM has no call stack, so for E this is the Rust driver and the VM's own frames |
| `heap_peak_bytes`, `vm_ops` | E, memory profile: heap high-water mark since boot, and VM instructions for one run. C, every profile: arena high-water mark since boot (nursery, generations and the 4 KiB `thread_info`) |
| `build` | `ram_kb`, `flash_kb` (linker budget), `reps`, `heap_bytes` (E heap, C arena), `program_bytes` (bytecode), `cps_optimize`, `c_log_nursery` (C), `features` |
| `size` | `flash_bytes` (vector table + text + rodata + data), `ram_static_bytes` (data + bss, **includes the Encore heap**), allocated `sections`, `flash_by_crate`, largest `ram_symbols` |
| `calibration` | overhead of an empty region, already subtracted |

Things to keep in mind when reading them:

- `insns` are instructions, not cycles. Speed claims come from boards only.
- `flash_by_crate` is an estimate: with LTO, code inlined into a caller
  counts for the caller's crate. `core` is mostly `core::fmt` pulled in by
  the harness's output, the same for every variant.
- `heap_peak_bytes` is a running maximum since boot (encore_vm has no way
  to reset it), which is why cases run by increasing N.
