/* encore-benchmarks: bare-metal stand-in for <stdio.h>. The runtime only
   prints diagnostics; they are dropped. */
#ifndef BENCH_SHIM_STDIO_H
#define BENCH_SHIM_STDIO_H
typedef struct bench_file FILE;
#define stderr ((FILE *)0)
#define stdout ((FILE *)0)
#define fprintf(...) ((void)0)
#define printf(...) ((void)0)
#endif
