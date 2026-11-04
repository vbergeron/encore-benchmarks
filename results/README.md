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
| `heap_peak_bytes`, `vm_ops` | E, memory profile: heap high-water mark since boot, and VM instructions for one run. C, every profile: arena high-water mark of the untimed run (nursery, generations and the 4 KiB `thread_info`; the arena is reset per run) |
| `gc` | E, memory profile: garbage collection during the untimed run. `count`, `reclaimed_bytes`, `live_bytes` (live after the latest collection since boot); `unit` (`insns` on QEMU, `cycles` with a DWT), `run_time` (time inside the VM for that run, collections included), `pct` (added by the runner: `pause_total / run_time` in percent), `pause_total`, `pause_max_since_boot` and the time per collector phase (`mark`, `forward`, `update`, `compact`, summing to `pause_total`) |
| `build` | `ram_kb`, `flash_kb` (linker budget), `reps`, `heap_bytes` (E heap, C arena), `program_bytes` (bytecode), `cps_optimize`, `c_log_nursery` (C), `features` |
| `size` | `flash_bytes` (vector table + text + rodata + data), `ram_static_bytes` (data + bss, **includes the Encore heap**), allocated `sections`, `flash_by_crate`, largest `ram_symbols` |
| `calibration` | overhead of an empty region, already subtracted |

Things to keep in mind when reading them:

- `insns` are instructions, not cycles. Speed claims come from boards only.
- `flash_by_crate` is an estimate: with LTO, code inlined into a caller
  counts for the caller's crate. `core` is mostly `core::fmt` pulled in by
  the harness's output, the same for every variant.
- `heap_peak_bytes` is not the memory a case needs, for either variant.
  E's collector runs only when the heap is full, so once it has run the
  peak is the heap size; C's GC allocates whole generations, so its peak
  is a step (8.5, 16.5, 32.5 KiB). Compare `minheap.jsonl` instead (below).
- E's `heap_peak_bytes` and `gc.pause_max_since_boot` are running maxima since
  boot (encore_vm has no way to reset them), which is why cases run by
  increasing N. The other `gc` counts are for the untimed run alone; they
  depend on the heap left by the previous case, since the heap is not reset
  between runs either.
- `gc` times on QEMU are instructions (`-icount shift=0`, SysTick), at the
  resolution of one SysTick tick: 80 instructions on the LM3S6965, 50 on the
  AN505.

## minheap.jsonl

`cargo xtask minheap -w <w> -v e|c` appends one row per (workload, variant,
board, N): the RAM a case needs, comparable between E and C. Use the
latest row for each key.

| Field | Meaning |
|---|---|
| `ok`, `reason` | `false` when the case passes at no heap size up to the RAM budget, with the reason at the largest size tried |
| `min_heap_bytes` | smallest E heap or C arena (multiple of `search.step`) at which the case passes, its output checked against the R oracle |
| `max_heap_pass_bytes`, `fails_above`, `reason_above` | largest size of the sweep that passes, and whether a larger one fails (it does for both: the larger the heap, the less stack is left; for C, whose recursion is on the stack, that bounds what fits) |
| `stack_peak_bytes` | peak stack at the minimum heap: for C the recursion, for E the driver and the VM |
| `ram_static_bytes`, `ram_total_bytes` | `.data` + `.bss` at the minimum heap (heap included), and that plus the peak stack: the RAM the case needs in all |
| `build`, `search` | `ram_kb`, `flash_kb`, `cps_optimize`, `c_log_nursery`; the sweep's `coarse` step, the `step` of the binary search, and `max_heap_tried` |

The probes run without the `stats` feature and without instruction
tracing. For E the heap is not reset between cases, which run by
increasing N, so a case's minimum includes what the previous cases left
reachable (nothing, once collected).
