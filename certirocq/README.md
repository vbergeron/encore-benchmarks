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
  fixed **arena** (`--heap-bytes`, default 20 KiB), which also holds the
  4 KiB `thread_info`. The nursery is 2^`--c-log-nursery` words (default
  10, 4 KiB).
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
- With the 20 KiB arena the largest cases do not fit, in the arena or in
  the C stack, and each driver runs only the cases that do (its `CASES`):
  W0 up to N = 100, W1 up to 32-byte APDUs, W2 up to 68 bytes of calldata,
  W3 up to 16 rules, W4 up to 100 APDUs, W5 up to 100 events, W6 up to 64
  bytes, W7 up to 50 credentials. The workload READMEs say which limit the
  larger cases hit.
