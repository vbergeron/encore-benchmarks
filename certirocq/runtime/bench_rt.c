/* encore-benchmarks: bare-metal support for CertiRocq-generated C.

   - Allocation: the CertiRocq GC mallocs its nursery and each older
     generation (twice the size of the previous one) and never frees
     them. Here malloc is a bump allocator over a fixed arena of
     BENCH_ARENA_BYTES, the C counterpart of the Encore heap budget: a
     program that needs a generation that does not fit aborts.
   - Abort: the runtime calls exit() on a fatal error; bench_rt_exit
     unwinds to bench_rt_run with __builtin_longjmp (no libc needed).
   - nat as machine integers and the input_byte extern: the C functions
     the CertiRocq Register directives of certirocq/theories name. */

#include <stddef.h>
#include "bench_rt.h"

#ifndef BENCH_ARENA_BYTES
#error "BENCH_ARENA_BYTES must be set by the build"
#endif

static value arena[BENCH_ARENA_BYTES / sizeof(value)];
static size_t arena_used, arena_peak;
static void *unwind[5];
static int last_error;

/* Stack guard. Direct-style CertiRocq code recurses on the C stack for
   every non-tail call, so a deep recursion (process over 1000 APDUs)
   can outgrow the stack and silently overwrite the statics below it,
   the arena included. The C helpers the generated code calls at every
   step (nat case analysis, input) check the stack pointer against the
   end of the statics (cortex-m-rt's __sheap) and abort instead. */
extern char __sheap;
#define STACK_MARGIN 512
static inline void stack_check(void) {
  if ((char *)__builtin_frame_address(0) < &__sheap + STACK_MARGIN) {
    last_error = BENCH_RT_STACK;
    __builtin_longjmp(unwind, 1);
  }
}

void *bench_rt_malloc(size_t n) {
  size_t words = (n + sizeof(value) - 1) / sizeof(value);
  if (words > sizeof(arena) / sizeof(value) - arena_used)
    return NULL; /* the runtime turns this into exit() */
  void *p = &arena[arena_used];
  arena_used += words;
  if (arena_used > arena_peak) arena_peak = arena_used;
  return p;
}

void bench_rt_free(void *p) { (void)p; }

_Noreturn void bench_rt_exit(int code) {
  (void)code;
  last_error = BENCH_RT_ABORT;
  __builtin_longjmp(unwind, 1);
}

int bench_rt_last_error(void) { return last_error; }

unsigned bench_rt_arena_peak(void) { return arena_peak * sizeof(value); }

int bench_rt_run(value (*body)(struct thread_info *), value arg, value *out) {
  arena_used = 0;
  last_error = BENCH_RT_OK;
  if (__builtin_setjmp(unwind)) return 0;
  struct thread_info *ti = make_tinfo();
  value entry = body(ti);
  *out = closure_call(ti, entry, arg);
  return 1;
}

/* ---- input ---- */

static const unsigned char *input;
static unsigned input_len;

void bench_rt_set_input(const unsigned char *data, unsigned len) {
  input = data;
  input_len = len;
}

value bench_input_byte(value i) {
  intnat k = Long_val(i);
  stack_check();
  if (k < 0 || (unsigned)k >= input_len) bench_rt_exit(1);
  return Val_long(input[k]);
}

/* ---- nat as machine integers (certirocq/theories/BenchNat.v) ----

   The counterpart of Encore.Extraction.ExtrEncore, and the same
   unproven assumption: a nat fits in a machine integer (31 bits here,
   Encore has 24). Values are tagged: Val_long(n) = 2n + 1. */

/* bool as the generated code expects it: true is the integer 0, false 1.
   (The runtime's own mk_bool, for primitive integers, is the other way
   round; it is not used here.) */
#define BOOL(b) ((b) ? Val_long(0) : Val_long(1))

value bench_nat_zero(void) { return Val_long(0); }
value bench_nat_succ(value n) { return n + 2; }

/* match n with 0 => z tt | S p => s p end, the branches as closures. */
value bench_nat_case(struct thread_info *ti, value n, value z, value s) {
  stack_check();
  if (n == Val_long(0)) return closure_call(ti, z, Val_long(0));
  return closure_call(ti, s, n - 2);
}

value bench_nat_pred(value n) { return n == Val_long(0) ? n : n - 2; }
value bench_nat_add(value a, value b) { return a + b - 1; }
value bench_nat_sub(value a, value b) { return a < b ? Val_long(0) : a - b + 1; }
value bench_nat_mul(value a, value b) { return Val_long(Long_val(a) * Long_val(b)); }
value bench_nat_eqb(value a, value b) { return BOOL(a == b); }
value bench_nat_leb(value a, value b) { return BOOL(a <= b); }
value bench_nat_ltb(value a, value b) { return BOOL(a < b); }

/* Integer literals for the named constants of the workloads (Pin.v,
   Cobs.v): the counterpart of their Extract Constant directives for
   Encore. Otherwise a literal such as 164 would be 164 calls to
   bench_nat_succ. */
#define LIT(n) value bench_lit_##n(void) { return Val_long(n); }
LIT(3) LIT(8) LIT(10) LIT(32) LIT(36) LIT(44) LIT(164) LIT(254)
