/* encore-benchmarks: bare-metal stand-in for <stdlib.h>, seen only by the
   CertiRocq runtime and generated code. Allocation comes from the fixed
   arena of bench_rt.c; exit() unwinds to the caller of bench_rt_run(). */
#ifndef BENCH_SHIM_STDLIB_H
#define BENCH_SHIM_STDLIB_H
#include <stddef.h>
void *bench_rt_malloc(size_t n);
void bench_rt_free(void *p);
_Noreturn void bench_rt_exit(int code);
#define malloc(n) bench_rt_malloc(n)
#define free(p) bench_rt_free(p)
#define exit(c) bench_rt_exit(c)
#endif
