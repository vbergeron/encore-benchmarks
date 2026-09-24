#ifndef W0_SMOKE_C
#define W0_SMOKE_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "w0_smoke.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW0dSmokedrun_wrapper_118(struct thread_info *, value, value);
extern value sum_known_117(struct thread_info *, value);
extern value y_wrapper_116(struct thread_info *, value, value);
extern value y_wrapper_115(struct thread_info *, value, value);
extern value body(struct thread_info *);
value EncoreBenchdW0dSmokedrun_wrapper_118(struct thread_info *, value, value);
value sum_known_117(struct thread_info *, value);
value y_wrapper_116(struct thread_info *, value, value);
value y_wrapper_115(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_155[2] = { 3, 0, };

unsigned int const y_wrapper_info_154[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_153[4] = { 11, 2, 0, 1, };

unsigned int const sum_known_info_152[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW0dSmokedrun_wrapper_info_151[4] = { 8, 2, 0,
  1, };

value EncoreBenchdW0dSmokedrun_wrapper_118(struct thread_info *$tinfo, value $env_139, value $n_140)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_141;
  register value $prim_142;
  register value $env_143;
  register value $env_144;
  register value $y_wrapper_clo_145;
  register value $y_wrapper_clo_146;
  register value $prim_147;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(8 <= $limit - $alloc)) {
    *(root + 0) = $n_140;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $n_140 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_141 = ((value (*)(void)) bench_nat_zero)();
  $prim_142 = ((value (*)(value)) bench_nat_succ)($prim_141);
  $env_143 = 1;
  $env_144 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_144 + -1) = 1024;
  *((value *) $env_144 + 0) = $prim_142;
  $y_wrapper_clo_145 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_145 + -1) = 2048;
  *((value *) $y_wrapper_clo_145 + 0) = y_wrapper_115;
  *((value *) $y_wrapper_clo_145 + 1) = $env_143;
  $y_wrapper_clo_146 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_146 + -1) = 2048;
  *((value *) $y_wrapper_clo_146 + 0) = y_wrapper_116;
  *((value *) $y_wrapper_clo_146 + 1) = $env_144;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_147 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_140, $y_wrapper_clo_145, $y_wrapper_clo_146);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value)) sum_known_117)
    ($tinfo, $prim_147);
  return $result;
}

value sum_known_117(struct thread_info *$tinfo, value $l_133)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_134;
  register value $x_135;
  register value $xs_136;
  register value $y_137;
  register value $prim_138;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (($l_133 & 1) == 0) {
    switch (*((value *) $l_133 + -1) & 255) {
      default:
        $x_135 = *((value *) $l_133 + 0);
        $xs_136 = *((value *) $l_133 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_135;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_137 =
          ((value (*)(struct thread_info *, value)) sum_known_117)
          ($tinfo, $xs_136);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $x_135 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_138 =
          ((value (*)(value, value)) bench_nat_add)
          ($x_135, $y_137);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_138;
        break;
      
    }
  } else {
    switch ($l_133 >> 1) {
      default:
        $prim_134 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_134;
        break;
      
    }
  }
}

value y_wrapper_116(struct thread_info *$tinfo, value $env_122, value $np_123)
{
  struct stack_frame frame;
  value root[2];
  register value $k_proj_124;
  register value $prim_125;
  register value $env_126;
  register value $env_127;
  register value $y_wrapper_clo_128;
  register value $y_wrapper_clo_129;
  register value $prim_130;
  register value $y_131;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(11 <= $limit - $alloc)) {
    *(root + 1) = $np_123;
    *(root + 0) = $env_122;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $np_123 = *(root + 1);
    $env_122 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $k_proj_124 = *((value *) $env_122 + 0);
  $prim_125 = ((value (*)(value)) bench_nat_succ)($k_proj_124);
  $env_126 = 1;
  $env_127 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_127 + -1) = 1024;
  *((value *) $env_127 + 0) = $prim_125;
  $y_wrapper_clo_128 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_128 + -1) = 2048;
  *((value *) $y_wrapper_clo_128 + 0) = y_wrapper_115;
  *((value *) $y_wrapper_clo_128 + 1) = $env_126;
  $y_wrapper_clo_129 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_129 + -1) = 2048;
  *((value *) $y_wrapper_clo_129 + 0) = y_wrapper_116;
  *((value *) $y_wrapper_clo_129 + 1) = $env_127;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $k_proj_124;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_130 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $np_123, $y_wrapper_clo_128, $y_wrapper_clo_129);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_130;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_130 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $k_proj_124 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_131 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_131 + -1) = 2048;
  *((value *) $y_131 + 0) = $k_proj_124;
  *((value *) $y_131 + 1) = $prim_130;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_131;
}

value y_wrapper_115(struct thread_info *$tinfo, value $env_119, value $anon_120)
{
  struct stack_frame frame;
  value root[0];
  register value $y_121;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  $y_121 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_121;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
  register value $env_149;
  register value $EncoreBenchdW0dSmokedrun_wrapper_clo_150;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(3 <= $limit - $alloc)) {
    /*skip*/;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    /*skip*/;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $env_149 = 1;
  $EncoreBenchdW0dSmokedrun_wrapper_clo_150 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_150 + -1) = 2048;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_150 + 0) =
    EncoreBenchdW0dSmokedrun_wrapper_118;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_150 + 1) = $env_149;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW0dSmokedrun_wrapper_clo_150;
}


#endif /* W0_SMOKE_C */
