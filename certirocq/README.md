# Variant C: CertiRocq

The C variant compiles the same Gallina as E with
[CertiRocq](https://github.com/CertiRocq/certirocq) v0.9.1 (Rocq 9.1) to C,
then with `arm-none-eabi-gcc -Os`, and runs it on CertiRocq's runtime from
the same Rust driver and harness as the other variants.

```
workloads/<w>/certirocq/
  CompileC.v      what to compile, and the workload's named constants as literals
  gen/            the generated C, committed (regenerate with generate.sh)
  src/main.rs     driver (package <w>-c)
certirocq/
  theories/BenchNat.v   nat as machine integers, Nat.* and input_byte as C functions
  runtime/              CertiRocq's GC (vendored) and bench_rt.c, the bare-metal glue
  generate.sh           regenerate gen/, all or the workloads named (needs the toolchain)
  toolchain.sh          build CertiRocq and its dependencies from source
```

Building firmware needs `gcc-arm-none-eabi` only. Regenerating the C needs
CertiRocq: `opam install rocq-certirocq`, or `toolchain.sh` where opam's
repository is not reachable (it applies `certirocq-no-wasm.patch`, which
drops the Wasm backend and its dependencies; the C backend is untouched).
`generate.sh w1_apdu w2_rlp` regenerates only the workloads named.
Without a local toolchain, `docker/rocq.sh certirocq [w ...]` runs it in
the image the `certirocq-image` workflow publishes on GHCR, and CI runs
`docker/rocq.sh certirocq-check`, which fails if a committed `gen/`
differs from what CertiRocq produces (see the main README, Rocq in
Docker).
`BenchNat.v` takes `input_byte` from `Encore.Extraction.ExtrEncoreInput`.
The committed `gen/` of W4 and W6 predates that import (it was generated
when `input_byte` came from this repository's own `EncoreInput.v`) and was
kept verbatim: `input_byte` is registered as `bench_input_byte` and no
other name from that module reaches the C, so only the module path
differs. W0, W1, W2, W3, W5 and W7 were generated with the current
`BenchNat.v`. W4 and W6 were not regenerated for its `tail_add` and
`tail_mul` either: they have no literal that needs them (below), and
adding a registration only renumbers the identifiers of the generated C.
CI's `certirocq-check` leaves W4 and W6 out for that reason; once they
are regenerated, add them back to its list in `.github/workflows/ci.yml`.

## Same program, same assumptions as E

- **Same Gallina**: the entry points of `theories/` (`run` for every
  workload but W6; W6 the encoder and decoder, wrapped in `c_roundtrip`,
  which returns both results because the heap is reset between calls).
- **`nat` as machine integers**: `BenchNat.v` maps `nat` to 31-bit
  integers (zero, successor and case analysis realised in C) and
  `Nat.add`, `sub`, `mul`, `pred`, `eqb`, `leb`, `ltb`, `div`, `modulo`,
  `land` to C functions, and `tail_add` and `tail_mul` to the same C as
  `add` and `mul` (no workload calls them, but Rocq writes a literal of
  5000 or more, W5's `modulus` = 65521, as `Nat.of_num_uint` of its
  digits, which computes with them): the
  counterpart of Encore's `ExtrEncore.v` for E, and the same unproven
  assumption. The mapping is applied by an erasure pass MetaRocq only runs
  with `-unsafe-erasure`, which is therefore on: that pass, too, is
  trusted.
- **Named constants as literals** (`CompileC.v`), as in E's `Extract.v`.
  `Register` replaces their uses, but `body` still evaluates their
  definitions at start-up (see below).
- **Input** through `input_byte`, realised by `bench_input_byte`.

## Runtime on a microcontroller

`runtime/` holds CertiRocq's `gc_stack.c` and headers (MIT, see
`LICENSE-certirocq.md`; changes: `m.h` for 32-bit ARM, `LOG_NURSERY_SIZE`
settable) and `bench_rt.c`:

- The GC mallocs a nursery and then generations of twice the previous
  size, and never frees them. `malloc` here is a bump allocator over a
  fixed **arena** (`--heap-bytes`), which also holds the 4 KiB
  `thread_info`. By default the arena gets the same bytes as the
  workload's Encore heap (32 KiB, 40 KiB for W6), and the C stack what is
  left of the RAM budget. The nursery is 2^`--c-log-nursery` words
  (default 10, 4 KiB). With a 4 KiB nursery the arena a run needs is a
  step function: about 8.5 KiB (`thread_info` and nursery), 16.5 KiB (a
  first 8 KiB generation), 32.5 KiB (a second one of 16 KiB).
- Each run starts on a fresh arena: CertiRocq's model is one heap per
  program execution. It costs about 2.2k instructions per run (heap setup,
  and `body` re-evaluating the top-level definitions, including the
  successor chains of the literals that `Register` replaced but that stay
  in the environment; for W5's 65521, a `Nat.of_num_uint` over five
  digits, which without the `tail_add` and `tail_mul` mapping recursed
  thousands of calls deep and exhausted the C stack). E, by contrast,
  keeps its heap across runs.
- The code is **direct style**: every non-tail call is a C call, so a
  recursion over N elements takes O(N) C stack (about 94 bytes per APDU in
  W4 and 200 per byte in W6). A stack guard in the C helpers aborts the
  run (`C stack exhausted`) instead of letting the stack overwrite the
  arena. `-cps` would move the recursion to the heap, as in Encore, but in
  this release CPS code needs the old `gc.c` runtime and calls registered
  primitives, `nat_case` among them, in direct style, so it cannot use the
  nat mapping.
- `exit()` from the runtime (arena exhausted) unwinds to the driver with
  `__builtin_longjmp`; the case is recorded as failed.
- Each driver runs every case of `vectors::CASES`, as E and R do; a case
  that does not fit is recorded as failed with its reason. Since the
  arena and the C stack share the RAM budget, a case can need an arena
  larger than E's heap (W1 N = 128, W3 N = 64, W7 N = 100 need 32.5 KiB)
  or a smaller one, to leave stack (W6 N = 64 passes up to 38 KiB, not
  with 40 KiB). `cargo xtask minheap -v c` finds, per case, the smallest
  arena that passes, the largest one tried that still passes, and the RAM
  in all (statics + peak stack); the results are in
  `results/minheap.jsonl`. A 36 KiB arena passes every case that fits at
  some size: the rows labelled `c-arena-36k` were run with it, so the
  instruction counts cover them. The cases that fit at no size, all
  because the C stack runs out: W0 N = 1000, W1 N = 261, W2 N = 260,
  W4 N = 1000, W5 N = 1000, W6 N = 256 and 1024, W7 N = 500. The workload
  READMEs give the figures.

## RAM against Encore, by nursery size

RAM in all, in KiB (statics with the smallest arena that passes, plus the
peak stack), for nurseries of 2^6 to 2^10 words, against E's at its
smallest heap (`cargo xtask minheap`, `results/minheap.jsonl`,
lm3s6965; the AN505 gives the same figures). Bold: the best nursery for
the case. ✗: the case passes at no arena size within 50 KiB, with any
nursery. W8 has no C variant yet.

| Workload | N | E | C 2^6 | C 2^7 | C 2^8 | C 2^9 | C 2^10 | best C / E |
|---|---|---|---|---|---|---|---|---|
| w0_smoke | 1 | 5.1 | **5.2** | 5.4 | 5.9 | 6.9 | 8.9 | 1.0× |
| w0_smoke | 10 | 5.4 | 6.2 | **6.0** | 6.5 | 7.5 | 9.5 | 1.1× |
| w0_smoke | 100 | 8.1 | 14.9 | 14.6 | **14.1** | 17.1 | 23.1 | 1.7× |
| w0_smoke | 1000 | 36.4 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w1_apdu | 5 | 5.6 | 6.0 | **5.8** | 6.2 | 7.2 | 9.2 | 1.0× |
| w1_apdu | 32 | 6.6 | 10.9 | 10.6 | **10.2** | 13.1 | 19.1 | 1.5× |
| w1_apdu | 128 | 10.4 | 29.6 | 29.4 | 28.9 | **27.9** | 41.9 | 2.7× |
| w1_apdu | 261 | 15.4 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w2_rlp | 0 | 7.6 | 15.8 | 15.7 | **15.1** | 22.1 | 20.1 | 2.0× |
| w2_rlp | 4 | 7.4 | 15.5 | 15.2 | **14.7** | 21.7 | 19.7 | 2.0× |
| w2_rlp | 68 | 10.6 | 28.2 | 27.9 | 27.4 | 26.4 | **24.4** | 2.3× |
| w2_rlp | 260 | 21.6 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w3_policy | 1 | 5.9 | **9.0** | 10.7 | 10.2 | 13.2 | 19.2 | 1.5× |
| w3_policy | 4 | 5.9 | 11.2 | **11.0** | 14.5 | 13.5 | 19.5 | 1.9× |
| w3_policy | 16 | 5.9 | **12.3** | 16.0 | 15.5 | 22.5 | 20.5 | 2.1× |
| w3_policy | 64 | 5.9 | **17.0** | 20.8 | 20.3 | 27.3 | 41.3 | 2.9× |
| w4_pin | 1 | 5.6 | **6.0** | 6.8 | 6.2 | 7.2 | 9.2 | 1.1× |
| w4_pin | 10 | 5.9 | **7.8** | 9.5 | 9.0 | 12.0 | 10.0 | 1.3× |
| w4_pin | 100 | 7.4 | 21.5 | 21.3 | **20.7** | 27.7 | 25.8 | 2.8× |
| w4_pin | 1000 | 32.9 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w5_update | 10 | 5.9 | **8.8** | 10.5 | 10.0 | 13.0 | 19.0 | 1.5× |
| w5_update | 100 | 7.4 | **19.9** | 23.7 | 23.1 | 30.1 | 28.1 | 2.7× |
| w5_update | 1000 | 32.9 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w6_cobs | 16 | 5.9 | 9.5 | **9.2** | 10.7 | 13.7 | 19.7 | 1.6× |
| w6_cobs | 64 | 7.7 | 23.3 | 23.0 | 22.5 | **21.5** | 27.5 | 2.8× |
| w6_cobs | 256 | 13.2 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w6_cobs | 1024 | 37.2 | ✗ | ✗ | ✗ | ✗ | ✗ | — |
| w7_store | 10 | 6.4 | 11.1 | 10.9 | **10.4** | 13.4 | 11.4 | 1.6× |
| w7_store | 50 | 7.4 | 25.3 | 24.9 | **16.4** | 23.4 | 21.4 | 2.2× |
| w7_store | 100 | 8.4 | 45.2 | 28.9 | **28.4** | 43.4 | 41.6 | 3.4× |
| w7_store | 500 | 17.6 | ✗ | ✗ | ✗ | ✗ | ✗ | — |

- The default 2^10 is the best nursery for one case only (W2 N = 68); a
  smaller one (2^6 to 2^9) saves 20 to 60 % on the others. No size is best
  everywhere: with generations that double, the arena a run needs is a
  step function of the nursery size, and where the steps fall depends on
  the live data. The timing rows use 2^10.
- With its best nursery, C needs 1.5 to 3.4 times E's RAM once N is not
  trivial. It is level with E (1.0 to 1.1×) only on the smallest cases,
  where the Encore VM's fixed stack (about 4.9 KiB: driver and VM frames)
  dominates.
- The nursery does not change which cases fail.

## Why the failing cases fail

With a 512 KiB RAM budget on the AN505 (`--ram-kb 512 --heap-bytes 65536
--c-log-nursery 8`), the cases that fail at 50 KiB pass, except two, and
show what they need:

| Case | C stack | arena peak | E, RAM in all |
|---|---|---|---|
| W0 N = 1000 | 62.8 KiB | 35.3 KiB | 36.4 KiB |
| W1 N = 261 | 18.7 KiB | 35.3 KiB | 15.4 KiB |
| W2 N = 260 | 22.6 KiB | 35.3 KiB | 21.6 KiB |
| W4 N = 1000 | 86.6 KiB | 35.3 KiB | 32.9 KiB |
| W5 N = 1000 | 102.6 KiB | 35.3 KiB | 32.9 KiB |
| W6 N = 256 | 42.3 KiB | 35.3 KiB | 13.2 KiB |
| W6 N = 1024, W7 N = 500 | — | more than 64 KiB | 37.2, 17.6 KiB |

What comes from CertiRocq (v0.9.1, with a `nat` mapping):

- **Direct style.** Every non-tail call is a C call with its
  `stack_frame`, its GC roots and its saved registers: about 64 to 100
  bytes per level of recursion. For W0, W4 and W5 at N = 1000 the stack
  alone exceeds the 50 KiB budget. E keeps its continuations on the heap
  (CPS), so its stack does not depend on N. CertiRocq's `-cps` mode would
  do the same, but in this release it needs the old `gc.c` runtime and
  calls registered primitives in direct style, so it cannot take a `nat`
  mapping (see above).
- **Generations that double and are never freed** (`gc_stack.c`): the
  arena jumps to the next step as soon as the live data outgrows one. W1
  N = 261 and W2 N = 260 fail on stack plus that step.

What comes from this repository, and how much it weighs:

- **The Gallina is not tail-recursive** (`sum`, `range_from`, `process`,
  `read_bytes`). It is the program E runs too: rewriting it with
  accumulators would help C, but would compare a different program.
- **`bench_nat_case` takes the branches as closures**: one more C frame
  (about 24 bytes) per level of a recursion on a `nat`, and two closures
  and an environment allocated per level. Without it W0 N = 1000 would
  still need about 40 KiB of stack plus its arena. A unary `nat` would be
  far worse.
- **The nursery size**: it does not decide which cases fit, but the
  default 2^10 overstates C's RAM (table above).
- **`thread_info`** takes about 4 KiB of the arena (the runtime's `args`
  array), which the vendored runtime could shrink.

