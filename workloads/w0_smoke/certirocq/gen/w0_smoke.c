#ifndef W0_SMOKE_C
#define W0_SMOKE_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "w0_smoke.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW0dSmokedrun_wrapper_120(struct thread_info *, value, value);
extern value sum_known_119(struct thread_info *, value);
extern value y_wrapper_118(struct thread_info *, value, value);
extern value y_wrapper_117(struct thread_info *, value, value);
extern value body(struct thread_info *);
value EncoreBenchdW0dSmokedrun_wrapper_120(struct thread_info *, value, value);
value sum_known_119(struct thread_info *, value);
value y_wrapper_118(struct thread_info *, value, value);
value y_wrapper_117(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_157[2] = { 3, 0, };

unsigned int const y_wrapper_info_156[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_155[4] = { 11, 2, 0, 1, };

unsigned int const sum_known_info_154[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW0dSmokedrun_wrapper_info_153[4] = { 8, 2, 0,
  1, };

value EncoreBenchdW0dSmokedrun_wrapper_120(struct thread_info *$tinfo, value $env_141, value $n_142)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_143;
  register value $prim_144;
  register value $env_145;
  register value $env_146;
  register value $y_wrapper_clo_147;
  register value $y_wrapper_clo_148;
  register value $prim_149;
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
    *(root + 0) = $n_142;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $n_142 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_143 = ((value (*)(void)) bench_nat_zero)();
  $prim_144 = ((value (*)(value)) bench_nat_succ)($prim_143);
  $env_145 = 1;
  $env_146 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_146 + -1) = 1024;
  *((value *) $env_146 + 0) = $prim_144;
  $y_wrapper_clo_147 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_147 + -1) = 2048;
  *((value *) $y_wrapper_clo_147 + 0) = y_wrapper_117;
  *((value *) $y_wrapper_clo_147 + 1) = $env_145;
  $y_wrapper_clo_148 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_148 + -1) = 2048;
  *((value *) $y_wrapper_clo_148 + 0) = y_wrapper_118;
  *((value *) $y_wrapper_clo_148 + 1) = $env_146;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_149 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_142, $y_wrapper_clo_147, $y_wrapper_clo_148);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value)) sum_known_119)
    ($tinfo, $prim_149);
  return $result;
}

value sum_known_119(struct thread_info *$tinfo, value $l_135)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_136;
  register value $x_137;
  register value $xs_138;
  register value $y_139;
  register value $prim_140;
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
  if (($l_135 & 1) == 0) {
    switch (*((value *) $l_135 + -1) & 255) {
      default:
        $x_137 = *((value *) $l_135 + 0);
        $xs_138 = *((value *) $l_135 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_137;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_139 =
          ((value (*)(struct thread_info *, value)) sum_known_119)
          ($tinfo, $xs_138);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $x_137 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_140 =
          ((value (*)(value, value)) bench_nat_add)
          ($x_137, $y_139);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_140;
        break;
      
    }
  } else {
    switch ($l_135 >> 1) {
      default:
        $prim_136 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_136;
        break;
      
    }
  }
}

value y_wrapper_118(struct thread_info *$tinfo, value $env_124, value $np_125)
{
  struct stack_frame frame;
  value root[2];
  register value $k_proj_126;
  register value $prim_127;
  register value $env_128;
  register value $env_129;
  register value $y_wrapper_clo_130;
  register value $y_wrapper_clo_131;
  register value $prim_132;
  register value $y_133;
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
    *(root + 1) = $np_125;
    *(root + 0) = $env_124;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $np_125 = *(root + 1);
    $env_124 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $k_proj_126 = *((value *) $env_124 + 0);
  $prim_127 = ((value (*)(value)) bench_nat_succ)($k_proj_126);
  $env_128 = 1;
  $env_129 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_129 + -1) = 1024;
  *((value *) $env_129 + 0) = $prim_127;
  $y_wrapper_clo_130 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_130 + -1) = 2048;
  *((value *) $y_wrapper_clo_130 + 0) = y_wrapper_117;
  *((value *) $y_wrapper_clo_130 + 1) = $env_128;
  $y_wrapper_clo_131 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_131 + -1) = 2048;
  *((value *) $y_wrapper_clo_131 + 0) = y_wrapper_118;
  *((value *) $y_wrapper_clo_131 + 1) = $env_129;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $k_proj_126;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_132 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $np_125, $y_wrapper_clo_130, $y_wrapper_clo_131);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_132;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_132 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $k_proj_126 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_133 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_133 + -1) = 2048;
  *((value *) $y_133 + 0) = $k_proj_126;
  *((value *) $y_133 + 1) = $prim_132;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_133;
}

value y_wrapper_117(struct thread_info *$tinfo, value $env_121, value $anon_122)
{
  struct stack_frame frame;
  value root[0];
  register value $y_123;
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
  $y_123 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_123;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
  register value $env_151;
  register value $EncoreBenchdW0dSmokedrun_wrapper_clo_152;
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
  $env_151 = 1;
  $EncoreBenchdW0dSmokedrun_wrapper_clo_152 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_152 + -1) = 2048;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_152 + 0) =
    EncoreBenchdW0dSmokedrun_wrapper_120;
  *((value *) $EncoreBenchdW0dSmokedrun_wrapper_clo_152 + 1) = $env_151;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW0dSmokedrun_wrapper_clo_152;
}


#endif /* W0_SMOKE_C */
