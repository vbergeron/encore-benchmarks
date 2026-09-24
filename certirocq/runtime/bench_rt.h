/* encore-benchmarks: the interface the Rust driver of a C (CertiRocq)
   variant uses. See bench_rt.c. */
#ifndef BENCH_RT_H
#define BENCH_RT_H
#include "gc_stack.h"

/* Run the compiled program on a fresh heap: reset the arena, build a
   thread_info, evaluate `body` (the program's top-level definitions,
   which yields the entry point's closure) and apply it to `arg`.
   Returns 1 and stores the result in *out, or 0 if the runtime aborted
   (arena exhausted, input out of range). The result lives in the arena
   until the next call. */
int bench_rt_run(value (*body)(struct thread_info *), value arg, value *out);

/* Why the latest bench_rt_run returned 0. */
#define BENCH_RT_OK 0
#define BENCH_RT_ABORT 1 /* runtime exit(): arena exhausted, bad input index */
#define BENCH_RT_STACK 2 /* C stack exhausted */
int bench_rt_last_error(void);

/* Bytes of the arena in use (high-water mark since the last reset). */
unsigned bench_rt_arena_peak(void);

/* Input buffer read by the input_byte axiom (vendor/encore-extraction/ExtrEncoreInput.v). */
void bench_rt_set_input(const unsigned char *data, unsigned len);

/* The C realisations named by certirocq/theories/BenchNat.v. */
value bench_input_byte(value i);
value bench_nat_zero(void);
value bench_nat_succ(value n);
value bench_nat_case(struct thread_info *ti, value n, value z, value s);
value bench_nat_pred(value n);
value bench_nat_add(value a, value b);
value bench_nat_sub(value a, value b);
value bench_nat_mul(value a, value b);
value bench_nat_eqb(value a, value b);
value bench_nat_leb(value a, value b);
value bench_nat_ltb(value a, value b);
value bench_nat_div(value a, value b);
value bench_nat_mod(value a, value b);
value bench_nat_land(value a, value b);
value bench_lit_1(void), bench_lit_2(void), bench_lit_3(void), bench_lit_4(void),
  bench_lit_8(void), bench_lit_10(void), bench_lit_16(void),
  bench_lit_20(void), bench_lit_31(void), bench_lit_32(void), bench_lit_36(void),
  bench_lit_44(void), bench_lit_48(void), bench_lit_56(void), bench_lit_57(void),
  bench_lit_87(void), bench_lit_128(void), bench_lit_129(void), bench_lit_130(void),
  bench_lit_164(void), bench_lit_183(void), bench_lit_184(void), bench_lit_192(void),
  bench_lit_247(void), bench_lit_248(void), bench_lit_254(void), bench_lit_256(void);
#endif
