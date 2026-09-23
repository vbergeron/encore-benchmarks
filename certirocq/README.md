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
  generate.sh           regenerate every gen/ (needs the toolchain)
  toolchain.sh          build CertiRocq and its dependencies from source
```

Building firmware needs `gcc-arm-none-eabi` only. Regenerating the C needs
CertiRocq: `opam install rocq-certirocq`, or `toolchain.sh` where opam's
repository is not reachable (it applies `certirocq-no-wasm.patch`, which
drops the Wasm backend and its dependencies; the C backend is untouched).

## Same program, same assumptions as E

- **Same Gallina**: the entry points of `theories/` (W4 `run`; W6 the
  encoder and decoder, wrapped in `c_roundtrip`, which returns both
  results because the heap is reset between calls).
- **`nat` as machine integers**: `BenchNat.v` maps `nat` to 31-bit
  integers (zero, successor and case analysis realised in C) and
  `Nat.add`, `sub`, `mul`, `pred`, `eqb`, `leb`, `ltb` to C functions: the
  counterpart of `theories/EncoreExtraction.v`, and the same unproven
  assumption. The mapping is applied by an erasure pass MetaRocq only runs
  with `-unsafe-erasure`, which is therefore on: that pass, too, is
  trusted.
- **Named constants as literals** (`CompileC.v`), as in E's `Extract.v`.
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
  in the environment). E, by contrast, keeps its heap across runs.
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
