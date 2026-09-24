#ifndef W3_POLICY_C
#define W3_POLICY_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "bench_rt.h"
#include "w3_policy.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW3dPolicydrun_wrapper_147(struct thread_info *, value, value);
extern value y_wrapper_146(struct thread_info *, value, value);
extern value f_case_known_145(struct thread_info *, value, value, value);
extern value y_wrapper_144(struct thread_info *, value, value);
extern value y_143(struct thread_info *, value, value);
extern value y_wrapper_142(struct thread_info *, value, value);
extern value y_wrapper_141(struct thread_info *, value, value);
extern value y_wrapper_140(struct thread_info *, value, value);
extern value y_wrapper_139(struct thread_info *, value, value);
extern value y_wrapper_138(struct thread_info *, value, value);
extern value y_wrapper_137(struct thread_info *, value, value);
extern value y_known_136(struct thread_info *, value, value, value);
extern value y_wrapper_135(struct thread_info *, value, value);
extern value y_known_134(struct thread_info *, value, value, value);
extern value y_wrapper_133(struct thread_info *, value, value);
extern value f_case_132(struct thread_info *, value, value);
extern value y_131(struct thread_info *, value, value);
extern value y_wrapper_130(struct thread_info *, value, value);
extern value y_known_129(struct thread_info *, value, value, value, value);
extern value y_wrapper_128(struct thread_info *, value, value);
extern value EncoreBenchdW3dPolicydrun_known_127(struct thread_info *, value);
extern value y_wrapper_126(struct thread_info *, value, value);
extern value y_known_125(struct thread_info *, value, value, value);
extern value y_wrapper_124(struct thread_info *, value, value);
extern value body(struct thread_info *);
value EncoreBenchdW3dPolicydrun_wrapper_147(struct thread_info *, value, value);
value y_wrapper_146(struct thread_info *, value, value);
value f_case_known_145(struct thread_info *, value, value, value);
value y_wrapper_144(struct thread_info *, value, value);
value y_143(struct thread_info *, value, value);
value y_wrapper_142(struct thread_info *, value, value);
value y_wrapper_141(struct thread_info *, value, value);
value y_wrapper_140(struct thread_info *, value, value);
value y_wrapper_139(struct thread_info *, value, value);
value y_wrapper_138(struct thread_info *, value, value);
value y_wrapper_137(struct thread_info *, value, value);
value y_known_136(struct thread_info *, value, value, value);
value y_wrapper_135(struct thread_info *, value, value);
value y_known_134(struct thread_info *, value, value, value);
value y_wrapper_133(struct thread_info *, value, value);
value f_case_132(struct thread_info *, value, value);
value y_131(struct thread_info *, value, value);
value y_wrapper_130(struct thread_info *, value, value);
value y_known_129(struct thread_info *, value, value, value, value);
value y_wrapper_128(struct thread_info *, value, value);
value EncoreBenchdW3dPolicydrun_known_127(struct thread_info *, value);
value y_wrapper_126(struct thread_info *, value, value);
value y_known_125(struct thread_info *, value, value, value);
value y_wrapper_124(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_772[2] = { 3, 0, };

unsigned int const y_wrapper_info_771[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_770[5] = { 9, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_769[4] = { 0, 2, 0, 1, };

unsigned int const EncoreBenchdW3dPolicydrun_known_info_768[3] = { 10, 1, 0,
  };

unsigned int const y_wrapper_info_767[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_766[6] = { 25, 4, 0, 1, 2, 3, };

unsigned int const y_wrapper_info_765[4] = { 0, 2, 0, 1, };

unsigned int const y_info_764[4] = { 15, 2, 0, 1, };

unsigned int const f_case_info_763[4] = { 18, 2, 0, 1, };

unsigned int const y_wrapper_info_762[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_761[5] = { 18, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_760[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_759[5] = { 9, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_758[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_757[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_756[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_755[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_754[4] = { 6, 2, 0, 1, };

unsigned int const y_wrapper_info_753[4] = { 0, 2, 0, 1, };

unsigned int const y_info_752[4] = { 30, 2, 0, 1, };

unsigned int const y_wrapper_info_751[4] = { 10, 2, 0, 1, };

unsigned int const f_case_known_info_750[5] = { 0, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_749[4] = { 0, 2, 0, 1, };

unsigned int const EncoreBenchdW3dPolicydrun_wrapper_info_748[4] = { 0, 2, 0,
  1, };

value EncoreBenchdW3dPolicydrun_wrapper_147(struct thread_info *$tinfo, value $env_429, value $n_430)
{
  struct stack_frame frame;
  value root[1];
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
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW3dPolicydrun_known_127)
    ($tinfo, $n_430);
  return $result;
}

value y_wrapper_146(struct thread_info *$tinfo, value $env_423, value $kp_424)
{
  struct stack_frame frame;
  value root[2];
  register value $rules_proj_426;
  register value $n_proj_427;
  register value $qpos_proj_428;
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
  $rules_proj_426 = *((value *) $env_423 + 0);
  $n_proj_427 = *((value *) $env_423 + 1);
  $qpos_proj_428 = *((value *) $env_423 + 2);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value, value)) y_known_129)
    ($tinfo, $kp_424, $rules_proj_426, $n_proj_427, $qpos_proj_428);
  return $result;
}

value f_case_known_145(struct thread_info *$tinfo, value $s_420, value $best_421, value $c_422)
{
  struct stack_frame frame;
  value root[3];
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
  if (($s_420 & 1) == 0) {
    switch (*((value *) $s_420 + -1) & 255) {
      
    }
  } else {
    switch ($s_420 >> 1) {
      case 0:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $c_422;
        break;
      default:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $best_421;
        break;
      
    }
  }
}

value y_wrapper_144(struct thread_info *$tinfo, value $env_409, value $dp_410)
{
  struct stack_frame frame;
  value root[2];
  register value $qpos_proj_411;
  register value $rpos_proj_412;
  register value $qd_proj_413;
  register value $env_414;
  register value $env_415;
  register value $y_wrapper_clo_416;
  register value $y_clo_417;
  register value $prim_418;
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
  if (!(10 <= $limit - $alloc)) {
    *(root + 1) = $dp_410;
    *(root + 0) = $env_409;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 10;
    garbage_collect($tinfo);
    $dp_410 = *(root + 1);
    $env_409 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qpos_proj_411 = *((value *) $env_409 + 0);
  $rpos_proj_412 = *((value *) $env_409 + 1);
  $qd_proj_413 = *((value *) $env_409 + 2);
  $env_414 = 1;
  $env_415 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_415 + -1) = 3072;
  *((value *) $env_415 + 0) = $dp_410;
  *((value *) $env_415 + 1) = $rpos_proj_412;
  *((value *) $env_415 + 2) = $qpos_proj_411;
  $y_wrapper_clo_416 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_416 + -1) = 2048;
  *((value *) $y_wrapper_clo_416 + 0) = y_wrapper_142;
  *((value *) $y_wrapper_clo_416 + 1) = $env_414;
  $y_clo_417 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_clo_417 + -1) = 2048;
  *((value *) $y_clo_417 + 0) = y_143;
  *((value *) $y_clo_417 + 1) = $env_415;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_418 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $qd_proj_413, $y_wrapper_clo_416, $y_clo_417);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_418;
}

value y_143(struct thread_info *$tinfo, value $env_375, value $qdp_376)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_377;
  register value $rpos_proj_378;
  register value $qpos_proj_379;
  register value $env_380;
  register value $env_381;
  register value $y_wrapper_clo_382;
  register value $y_wrapper_clo_383;
  register value $prim_384;
  register value $prim_385;
  register value $qpos_proj_386;
  register value $prim_387;
  register value $rpos_proj_388;
  register value $prim_389;
  register value $env_390;
  register value $env_391;
  register value $y_wrapper_clo_392;
  register value $y_wrapper_clo_393;
  register value $prim_394;
  register value $prim_395;
  register value $rpos_proj_396;
  register value $prim_397;
  register value $prim_398;
  register value $qpos_proj_399;
  register value $prim_400;
  register value $dp_proj_401;
  register value $env_402;
  register value $env_403;
  register value $y_wrapper_clo_404;
  register value $y_wrapper_clo_405;
  register value $prim_406;
  register value $y_407;
  register value $y_408;
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
  if (!(30 <= $limit - $alloc)) {
    *(root + 1) = $qdp_376;
    *(root + 0) = $env_375;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 30;
    garbage_collect($tinfo);
    $qdp_376 = *(root + 1);
    $env_375 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_377 = ((value (*)(void)) bench_lit_4)();
  $rpos_proj_378 = *((value *) $env_375 + 1);
  $qpos_proj_379 = *((value *) $env_375 + 2);
  $env_380 = 1;
  $env_381 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_381 + -1) = 2048;
  *((value *) $env_381 + 0) = $qpos_proj_379;
  *((value *) $env_381 + 1) = $rpos_proj_378;
  $y_wrapper_clo_382 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_382 + -1) = 2048;
  *((value *) $y_wrapper_clo_382 + 0) = y_wrapper_124;
  *((value *) $y_wrapper_clo_382 + 1) = $env_380;
  $y_wrapper_clo_383 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_383 + -1) = 2048;
  *((value *) $y_wrapper_clo_383 + 0) = y_wrapper_126;
  *((value *) $y_wrapper_clo_383 + 1) = $env_381;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $qdp_376;
  *(root + 0) = $env_375;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $prim_384 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_377, $y_wrapper_clo_382, $y_wrapper_clo_383);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(21 <= $limit - $alloc)) {
    *(root + 2) = $prim_384;
    frame.next = root + 3;
    (*$tinfo).nalloc = 21;
    garbage_collect($tinfo);
    $prim_384 = *(root + 2);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qdp_376 = *(root + 1);
  $env_375 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($prim_384 & 1) == 0) {
    switch (*((value *) $prim_384 + -1) & 255) {
      
    }
  } else {
    switch ($prim_384 >> 1) {
      case 0:
        $prim_385 = ((value (*)(void)) bench_lit_4)();
        $qpos_proj_386 = *((value *) $env_375 + 2);
        $prim_387 = ((value (*)(void)) bench_lit_4)();
        $rpos_proj_388 = *((value *) $env_375 + 1);
        $prim_389 =
          ((value (*)(value, value)) bench_nat_add)
          ($rpos_proj_388, $prim_387);
        $env_390 = 1;
        $env_391 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_391 + -1) = 2048;
        *((value *) $env_391 + 0) = $prim_389;
        *((value *) $env_391 + 1) = $qpos_proj_386;
        $y_wrapper_clo_392 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_392 + -1) = 2048;
        *((value *) $y_wrapper_clo_392 + 0) = y_wrapper_124;
        *((value *) $y_wrapper_clo_392 + 1) = $env_390;
        $y_wrapper_clo_393 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_393 + -1) = 2048;
        *((value *) $y_wrapper_clo_393 + 0) = y_wrapper_126;
        *((value *) $y_wrapper_clo_393 + 1) = $env_391;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $qdp_376;
        *(root + 0) = $env_375;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $prim_394 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_385, $y_wrapper_clo_392, $y_wrapper_clo_393);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 2) = $prim_394;
          frame.next = root + 3;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $prim_394 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $qdp_376 = *(root + 1);
        $env_375 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_394 & 1) == 0) {
          switch (*((value *) $prim_394 + -1) & 255) {
            
          }
        } else {
          switch ($prim_394 >> 1) {
            case 0:
              $prim_395 = ((value (*)(void)) bench_lit_8)();
              $rpos_proj_396 = *((value *) $env_375 + 1);
              $prim_397 =
                ((value (*)(value, value)) bench_nat_add)
                ($rpos_proj_396, $prim_395);
              $prim_398 = ((value (*)(void)) bench_lit_4)();
              $qpos_proj_399 = *((value *) $env_375 + 2);
              $prim_400 =
                ((value (*)(value, value)) bench_nat_add)
                ($qpos_proj_399, $prim_398);
              $dp_proj_401 = *((value *) $env_375 + 0);
              $env_402 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $env_402 + -1) = 1024;
              *((value *) $env_402 + 0) = $qdp_376;
              $env_403 = (value) ($alloc + 1);
              $alloc = $alloc + 4;
              *((value *) $env_403 + -1) = 3072;
              *((value *) $env_403 + 0) = $prim_400;
              *((value *) $env_403 + 1) = $prim_397;
              *((value *) $env_403 + 2) = $qdp_376;
              $y_wrapper_clo_404 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_404 + -1) = 2048;
              *((value *) $y_wrapper_clo_404 + 0) = y_wrapper_141;
              *((value *) $y_wrapper_clo_404 + 1) = $env_402;
              $y_wrapper_clo_405 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_405 + -1) = 2048;
              *((value *) $y_wrapper_clo_405 + 0) = y_wrapper_144;
              *((value *) $y_wrapper_clo_405 + 1) = $env_403;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_406 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $dp_proj_401, $y_wrapper_clo_404, $y_wrapper_clo_405);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_406;
              break;
            default:
              $y_407 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_407;
              break;
            
          }
        }
        break;
      default:
        $y_408 = 3;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_408;
        break;
      
    }
  }
}

value y_wrapper_142(struct thread_info *$tinfo, value $env_372, value $anon_373)
{
  struct stack_frame frame;
  value root[0];
  register value $y_374;
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
  $y_374 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_374;
}

value y_wrapper_141(struct thread_info *$tinfo, value $env_364, value $anon_365)
{
  struct stack_frame frame;
  value root[1];
  register value $qd_proj_366;
  register value $env_367;
  register value $env_368;
  register value $y_wrapper_clo_369;
  register value $y_wrapper_clo_370;
  register value $prim_371;
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
  if (!(6 <= $limit - $alloc)) {
    *(root + 0) = $env_364;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 6;
    garbage_collect($tinfo);
    $env_364 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qd_proj_366 = *((value *) $env_364 + 0);
  $env_367 = 1;
  $env_368 = 1;
  $y_wrapper_clo_369 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_369 + -1) = 2048;
  *((value *) $y_wrapper_clo_369 + 0) = y_wrapper_139;
  *((value *) $y_wrapper_clo_369 + 1) = $env_367;
  $y_wrapper_clo_370 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_370 + -1) = 2048;
  *((value *) $y_wrapper_clo_370 + 0) = y_wrapper_140;
  *((value *) $y_wrapper_clo_370 + 1) = $env_368;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_371 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $qd_proj_366, $y_wrapper_clo_369, $y_wrapper_clo_370);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_371;
}

value y_wrapper_140(struct thread_info *$tinfo, value $env_361, value $n_362)
{
  struct stack_frame frame;
  value root[0];
  register value $y_363;
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
  $y_363 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_363;
}

value y_wrapper_139(struct thread_info *$tinfo, value $env_358, value $anon_359)
{
  struct stack_frame frame;
  value root[0];
  register value $y_360;
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
  $y_360 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_360;
}

value y_wrapper_138(struct thread_info *$tinfo, value $env_353, value $kp_354)
{
  struct stack_frame frame;
  value root[2];
  register value $q_proj_356;
  register value $pos_proj_357;
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
  $q_proj_356 = *((value *) $env_353 + 0);
  $pos_proj_357 = *((value *) $env_353 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_134)
    ($tinfo, $kp_354, $q_proj_356, $pos_proj_357);
  return $result;
}

value y_wrapper_137(struct thread_info *$tinfo, value $env_348, value $np_349)
{
  struct stack_frame frame;
  value root[2];
  register value $b_proj_351;
  register value $a_proj_352;
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
  $b_proj_351 = *((value *) $env_348 + 0);
  $a_proj_352 = *((value *) $env_348 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_136)
    ($tinfo, $np_349, $b_proj_351, $a_proj_352);
  return $result;
}

value y_known_136(struct thread_info *$tinfo, value $np_334, value $b_335, value $a_336)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_337;
  register value $prim_338;
  register value $prim_339;
  register value $prim_340;
  register value $prim_341;
  register value $env_342;
  register value $env_343;
  register value $y_wrapper_clo_344;
  register value $y_wrapper_clo_345;
  register value $prim_346;
  register value $y_347;
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
  if (!(9 <= $limit - $alloc)) {
    *(root + 2) = $a_336;
    *(root + 1) = $b_335;
    *(root + 0) = $np_334;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $a_336 = *(root + 2);
    $b_335 = *(root + 1);
    $np_334 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_337 = ((value (*)(value)) bench_input_byte)($a_336);
  $prim_338 = ((value (*)(value)) bench_input_byte)($b_335);
  $prim_339 =
    ((value (*)(value, value)) bench_nat_eqb)
    ($prim_337, $prim_338);
  if (($prim_339 & 1) == 0) {
    switch (*((value *) $prim_339 + -1) & 255) {
      
    }
  } else {
    switch ($prim_339 >> 1) {
      case 0:
        $prim_340 = ((value (*)(value)) bench_nat_succ)($a_336);
        $prim_341 = ((value (*)(value)) bench_nat_succ)($b_335);
        $env_342 = 1;
        $env_343 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_343 + -1) = 2048;
        *((value *) $env_343 + 0) = $prim_341;
        *((value *) $env_343 + 1) = $prim_340;
        $y_wrapper_clo_344 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_344 + -1) = 2048;
        *((value *) $y_wrapper_clo_344 + 0) = y_wrapper_135;
        *((value *) $y_wrapper_clo_344 + 1) = $env_342;
        $y_wrapper_clo_345 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_345 + -1) = 2048;
        *((value *) $y_wrapper_clo_345 + 0) = y_wrapper_137;
        *((value *) $y_wrapper_clo_345 + 1) = $env_343;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_346 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $np_334, $y_wrapper_clo_344, $y_wrapper_clo_345);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_346;
        break;
      default:
        $y_347 = 3;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_347;
        break;
      
    }
  }
}

value y_wrapper_135(struct thread_info *$tinfo, value $env_330, value $anon_331)
{
  struct stack_frame frame;
  value root[0];
  register value $y_332;
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
  $y_332 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_332;
}

value y_known_134(struct thread_info *$tinfo, value $kp_313, value $q_314, value $pos_315)
{
  struct stack_frame frame;
  value root[4];
  register value $prim_316;
  register value $env_317;
  register value $env_318;
  register value $y_wrapper_clo_319;
  register value $y_wrapper_clo_320;
  register value $prim_321;
  register value $y_322;
  register value $prim_323;
  register value $prim_324;
  register value $env_325;
  register value $env_326;
  register value $y_wrapper_clo_327;
  register value $y_wrapper_clo_328;
  register value $prim_329;
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
  if (!(18 <= $limit - $alloc)) {
    *(root + 2) = $pos_315;
    *(root + 1) = $q_314;
    *(root + 0) = $kp_313;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18;
    garbage_collect($tinfo);
    $pos_315 = *(root + 2);
    $q_314 = *(root + 1);
    $kp_313 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_316 = ((value (*)(void)) bench_lit_20)();
  $env_317 = 1;
  $env_318 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_318 + -1) = 2048;
  *((value *) $env_318 + 0) = $pos_315;
  *((value *) $env_318 + 1) = $q_314;
  $y_wrapper_clo_319 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_319 + -1) = 2048;
  *((value *) $y_wrapper_clo_319 + 0) = y_wrapper_135;
  *((value *) $y_wrapper_clo_319 + 1) = $env_317;
  $y_wrapper_clo_320 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_320 + -1) = 2048;
  *((value *) $y_wrapper_clo_320 + 0) = y_wrapper_137;
  *((value *) $y_wrapper_clo_320 + 1) = $env_318;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $pos_315;
  *(root + 1) = $q_314;
  *(root + 0) = $kp_313;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $prim_321 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_316, $y_wrapper_clo_319, $y_wrapper_clo_320);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(9 <= $limit - $alloc)) {
    *(root + 3) = $prim_321;
    frame.next = root + 4;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $prim_321 = *(root + 3);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_315 = *(root + 2);
  $q_314 = *(root + 1);
  $kp_313 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($prim_321 & 1) == 0) {
    switch (*((value *) $prim_321 + -1) & 255) {
      
    }
  } else {
    switch ($prim_321 >> 1) {
      case 0:
        $y_322 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_322;
        break;
      default:
        $prim_323 = ((value (*)(void)) bench_lit_20)();
        $prim_324 =
          ((value (*)(value, value)) bench_nat_add)
          ($pos_315, $prim_323);
        $env_325 = 1;
        $env_326 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_326 + -1) = 2048;
        *((value *) $env_326 + 0) = $q_314;
        *((value *) $env_326 + 1) = $prim_324;
        $y_wrapper_clo_327 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_327 + -1) = 2048;
        *((value *) $y_wrapper_clo_327 + 0) = y_wrapper_133;
        *((value *) $y_wrapper_clo_327 + 1) = $env_325;
        $y_wrapper_clo_328 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_328 + -1) = 2048;
        *((value *) $y_wrapper_clo_328 + 0) = y_wrapper_138;
        *((value *) $y_wrapper_clo_328 + 1) = $env_326;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_329 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_313, $y_wrapper_clo_327, $y_wrapper_clo_328);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_329;
        break;
      
    }
  }
}

value y_wrapper_133(struct thread_info *$tinfo, value $env_309, value $anon_310)
{
  struct stack_frame frame;
  value root[0];
  register value $y_311;
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
  $y_311 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_311;
}

value f_case_132(struct thread_info *$tinfo, value $env_282, value $s_283)
{
  struct stack_frame frame;
  value root[2];
  register value $prim_284;
  register value $prim_proj_285;
  register value $prim_proj_286;
  register value $env_287;
  register value $env_288;
  register value $y_wrapper_clo_289;
  register value $y_wrapper_clo_290;
  register value $prim_291;
  register value $prim_292;
  register value $prim_proj_293;
  register value $prim_294;
  register value $prim_295;
  register value $prim_296;
  register value $prim_297;
  register value $prim_proj_298;
  register value $prim_299;
  register value $env_300;
  register value $env_301;
  register value $y_wrapper_clo_302;
  register value $y_wrapper_clo_303;
  register value $prim_304;
  register value $prim_305;
  register value $prim_306;
  register value $prim_307;
  register value $prim_308;
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
  if (!(18 <= $limit - $alloc)) {
    *(root + 1) = $s_283;
    *(root + 0) = $env_282;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18;
    garbage_collect($tinfo);
    $s_283 = *(root + 1);
    $env_282 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_283 & 1) == 0) {
    switch (*((value *) $s_283 + -1) & 255) {
      
    }
  } else {
    switch ($s_283 >> 1) {
      case 0:
        $prim_284 = ((value (*)(void)) bench_lit_8)();
        $prim_proj_285 = *((value *) $env_282 + 1);
        $prim_proj_286 = *((value *) $env_282 + 0);
        $env_287 = 1;
        $env_288 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_288 + -1) = 2048;
        *((value *) $env_288 + 0) = $prim_proj_286;
        *((value *) $env_288 + 1) = $prim_proj_285;
        $y_wrapper_clo_289 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_289 + -1) = 2048;
        *((value *) $y_wrapper_clo_289 + 0) = y_wrapper_124;
        *((value *) $y_wrapper_clo_289 + 1) = $env_287;
        $y_wrapper_clo_290 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_290 + -1) = 2048;
        *((value *) $y_wrapper_clo_290 + 0) = y_wrapper_126;
        *((value *) $y_wrapper_clo_290 + 1) = $env_288;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_282;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_291 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_284, $y_wrapper_clo_289, $y_wrapper_clo_290);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 1) = $prim_291;
          frame.next = root + 2;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $prim_291 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $env_282 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_291 & 1) == 0) {
          switch (*((value *) $prim_291 + -1) & 255) {
            
          }
        } else {
          switch ($prim_291 >> 1) {
            case 0:
              $prim_292 = ((value (*)(void)) bench_lit_8)();
              $prim_proj_293 = *((value *) $env_282 + 0);
              $prim_294 =
                ((value (*)(value, value)) bench_nat_add)
                ($prim_proj_293, $prim_292);
              $prim_295 = ((value (*)(value)) bench_input_byte)($prim_294);
              $prim_296 = ((value (*)(value)) bench_nat_succ)($prim_294);
              $prim_297 = ((value (*)(void)) bench_lit_8)();
              $prim_proj_298 = *((value *) $env_282 + 1);
              $prim_299 =
                ((value (*)(value, value)) bench_nat_add)
                ($prim_proj_298, $prim_297);
              $env_300 = 1;
              $env_301 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $env_301 + -1) = 2048;
              *((value *) $env_301 + 0) = $prim_299;
              *((value *) $env_301 + 1) = $prim_296;
              $y_wrapper_clo_302 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_302 + -1) = 2048;
              *((value *) $y_wrapper_clo_302 + 0) = y_wrapper_133;
              *((value *) $y_wrapper_clo_302 + 1) = $env_300;
              $y_wrapper_clo_303 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_303 + -1) = 2048;
              *((value *) $y_wrapper_clo_303 + 0) = y_wrapper_138;
              *((value *) $y_wrapper_clo_303 + 1) = $env_301;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_304 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $prim_295, $y_wrapper_clo_302, $y_wrapper_clo_303);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              if (($prim_304 & 1) == 0) {
                switch (*((value *) $prim_304 + -1) & 255) {
                  
                }
              } else {
                switch ($prim_304 >> 1) {
                  case 0:
                    $prim_305 = ((value (*)(void)) bench_nat_zero)();
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $prim_305;
                    break;
                  default:
                    $prim_306 = ((value (*)(void)) bench_lit_1)();
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $prim_306;
                    break;
                  
                }
              }
              break;
            default:
              $prim_307 = ((value (*)(void)) bench_lit_2)();
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_307;
              break;
            
          }
        }
        break;
      default:
        $prim_308 = ((value (*)(void)) bench_lit_3)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_308;
        break;
      
    }
  }
}

value y_131(struct thread_info *$tinfo, value $env_225, value $kp_226)
{
  struct stack_frame frame;
  value root[4];
  register value $rpos_proj_227;
  register value $prim_228;
  register value $rpos_proj_229;
  register value $prim_230;
  register value $prim_231;
  register value $prim_232;
  register value $prim_233;
  register value $qpos_proj_234;
  register value $prim_235;
  register value $qpos_proj_236;
  register value $prim_237;
  register value $prim_238;
  register value $prim_239;
  register value $prim_240;
  register value $env_241;
  register value $qpos_proj_242;
  register value $prim_243;
  register value $rpos_proj_244;
  register value $prim_245;
  register value $qpos_proj_246;
  register value $prim_247;
  register value $env_248;
  register value $env_249;
  register value $y_wrapper_clo_250;
  register value $y_wrapper_clo_251;
  register value $prim_252;
  register value $c_253;
  register value $prim_254;
  register value $prim_255;
  register value $prim_256;
  register value $rpos_proj_257;
  register value $prim_258;
  register value $rpos_proj_259;
  register value $prim_260;
  register value $prim_261;
  register value $prim_262;
  register value $prim_263;
  register value $prim_264;
  register value $prim_265;
  register value $prim_266;
  register value $prim_267;
  register value $prim_268;
  register value $prim_269;
  register value $prim_270;
  register value $best_proj_272;
  register value $prim_273;
  register value $best_proj_274;
  register value $y_275;
  register value $qpos_proj_276;
  register value $env_277;
  register value $env_278;
  register value $y_wrapper_clo_279;
  register value $y_clo_280;
  register value $prim_281;
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
  if (!(15 <= $limit - $alloc)) {
    *(root + 1) = $kp_226;
    *(root + 0) = $env_225;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 15;
    garbage_collect($tinfo);
    $kp_226 = *(root + 1);
    $env_225 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $rpos_proj_227 = *((value *) $env_225 + 2);
  $prim_228 = ((value (*)(value)) bench_input_byte)($rpos_proj_227);
  $rpos_proj_229 = *((value *) $env_225 + 2);
  $prim_230 = ((value (*)(value)) bench_nat_succ)($rpos_proj_229);
  $prim_231 = ((value (*)(void)) bench_lit_8)();
  $prim_232 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_228, $prim_231);
  $prim_233 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_230, $prim_232);
  $qpos_proj_234 = *((value *) $env_225 + 1);
  $prim_235 = ((value (*)(value)) bench_nat_succ)($qpos_proj_234);
  $qpos_proj_236 = *((value *) $env_225 + 1);
  $prim_237 = ((value (*)(value)) bench_input_byte)($qpos_proj_236);
  $prim_238 = ((value (*)(void)) bench_lit_4)();
  $prim_239 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_237, $prim_238);
  $prim_240 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_235, $prim_239);
  $env_241 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_241 + -1) = 2048;
  *((value *) $env_241 + 0) = $prim_233;
  *((value *) $env_241 + 1) = $prim_240;
  $qpos_proj_242 = *((value *) $env_225 + 1);
  $prim_243 = ((value (*)(value)) bench_input_byte)($qpos_proj_242);
  $rpos_proj_244 = *((value *) $env_225 + 2);
  $prim_245 = ((value (*)(value)) bench_nat_succ)($rpos_proj_244);
  $qpos_proj_246 = *((value *) $env_225 + 1);
  $prim_247 = ((value (*)(value)) bench_nat_succ)($qpos_proj_246);
  $env_248 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_248 + -1) = 1024;
  *((value *) $env_248 + 0) = $prim_243;
  $env_249 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_249 + -1) = 3072;
  *((value *) $env_249 + 0) = $prim_247;
  *((value *) $env_249 + 1) = $prim_245;
  *((value *) $env_249 + 2) = $prim_243;
  $y_wrapper_clo_250 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_250 + -1) = 2048;
  *((value *) $y_wrapper_clo_250 + 0) = y_wrapper_141;
  *((value *) $y_wrapper_clo_250 + 1) = $env_248;
  $y_wrapper_clo_251 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_251 + -1) = 2048;
  *((value *) $y_wrapper_clo_251 + 0) = y_wrapper_144;
  *((value *) $y_wrapper_clo_251 + 1) = $env_249;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $env_241;
  *(root + 1) = $kp_226;
  *(root + 0) = $env_225;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $prim_252 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_228, $y_wrapper_clo_250, $y_wrapper_clo_251);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $env_241 = *(root + 2);
  $kp_226 = *(root + 1);
  $env_225 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $kp_226;
  *(root + 0) = $env_225;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $c_253 =
    ((value (*)(struct thread_info *, value, value)) f_case_132)
    ($tinfo, $env_241, $prim_252);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $kp_226 = *(root + 1);
  $env_225 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_254 = ((value (*)(void)) bench_nat_zero)();
  $prim_255 = ((value (*)(value, value)) bench_nat_eqb)($c_253, $prim_254);
  if (($prim_255 & 1) == 0) {
    switch (*((value *) $prim_255 + -1) & 255) {
      
    }
  } else {
    switch ($prim_255 >> 1) {
      case 0:
        $prim_256 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_256;
        break;
      default:
        $rpos_proj_257 = *((value *) $env_225 + 2);
        $prim_258 = ((value (*)(value)) bench_nat_succ)($rpos_proj_257);
        $rpos_proj_259 = *((value *) $env_225 + 2);
        $prim_260 = ((value (*)(value)) bench_input_byte)($rpos_proj_259);
        $prim_261 = ((value (*)(void)) bench_lit_8)();
        $prim_262 =
          ((value (*)(value, value)) bench_nat_mul)
          ($prim_260, $prim_261);
        $prim_263 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_258, $prim_262);
        $prim_264 = ((value (*)(void)) bench_lit_8)();
        $prim_265 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_263, $prim_264);
        $prim_266 = ((value (*)(value)) bench_nat_succ)($prim_265);
        $prim_267 = ((value (*)(value)) bench_input_byte)($prim_265);
        $prim_268 = ((value (*)(void)) bench_lit_20)();
        $prim_269 =
          ((value (*)(value, value)) bench_nat_mul)
          ($prim_267, $prim_268);
        $prim_270 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_266, $prim_269);
        $best_proj_272 = *((value *) $env_225 + 0);
        $prim_273 =
          ((value (*)(value, value)) bench_nat_leb)
          ($c_253, $best_proj_272);
        $best_proj_274 = *((value *) $env_225 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $prim_270;
        *(root + 1) = $kp_226;
        *(root + 0) = $env_225;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_275 =
          ((value (*)(struct thread_info *, value, value, value)) f_case_known_145)
          ($tinfo, $prim_273, $best_proj_274, $c_253);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 3) = $y_275;
          frame.next = root + 4;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $y_275 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $prim_270 = *(root + 2);
        $kp_226 = *(root + 1);
        $env_225 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $qpos_proj_276 = *((value *) $env_225 + 1);
        $env_277 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_277 + -1) = 1024;
        *((value *) $env_277 + 0) = $y_275;
        $env_278 = (value) ($alloc + 1);
        $alloc = $alloc + 4;
        *((value *) $env_278 + -1) = 3072;
        *((value *) $env_278 + 0) = $y_275;
        *((value *) $env_278 + 1) = $qpos_proj_276;
        *((value *) $env_278 + 2) = $prim_270;
        $y_wrapper_clo_279 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_279 + -1) = 2048;
        *((value *) $y_wrapper_clo_279 + 0) = y_wrapper_130;
        *((value *) $y_wrapper_clo_279 + 1) = $env_277;
        $y_clo_280 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_280 + -1) = 2048;
        *((value *) $y_clo_280 + 0) = y_131;
        *((value *) $y_clo_280 + 1) = $env_278;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_281 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_226, $y_wrapper_clo_279, $y_clo_280);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_281;
        break;
      
    }
  }
}

value y_wrapper_130(struct thread_info *$tinfo, value $env_222, value $anon_223)
{
  struct stack_frame frame;
  value root[1];
  register value $best_proj_224;
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
  $best_proj_224 = *((value *) $env_222 + 0);
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $best_proj_224;
}

value y_known_129(struct thread_info *$tinfo, value $kp_197, value $rules_198, value $n_199, value $qpos_200)
{
  struct stack_frame frame;
  value root[5];
  register value $prim_201;
  register value $env_202;
  register value $env_203;
  register value $y_wrapper_clo_204;
  register value $y_clo_205;
  register value $prim_206;
  register value $prim_207;
  register value $prim_208;
  register value $prim_209;
  register value $prim_210;
  register value $prim_211;
  register value $prim_212;
  register value $prim_213;
  register value $prim_214;
  register value $prim_215;
  register value $env_216;
  register value $env_217;
  register value $y_wrapper_clo_218;
  register value $y_wrapper_clo_219;
  register value $prim_220;
  register value $y_221;
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
  if (!(25 <= $limit - $alloc)) {
    *(root + 3) = $qpos_200;
    *(root + 2) = $n_199;
    *(root + 1) = $rules_198;
    *(root + 0) = $kp_197;
    frame.next = root + 4;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 25;
    garbage_collect($tinfo);
    $qpos_200 = *(root + 3);
    $n_199 = *(root + 2);
    $rules_198 = *(root + 1);
    $kp_197 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_201 = ((value (*)(void)) bench_lit_3)();
  $env_202 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_202 + -1) = 1024;
  *((value *) $env_202 + 0) = $prim_201;
  $env_203 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_203 + -1) = 3072;
  *((value *) $env_203 + 0) = $prim_201;
  *((value *) $env_203 + 1) = $qpos_200;
  *((value *) $env_203 + 2) = $rules_198;
  $y_wrapper_clo_204 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_204 + -1) = 2048;
  *((value *) $y_wrapper_clo_204 + 0) = y_wrapper_130;
  *((value *) $y_wrapper_clo_204 + 1) = $env_202;
  $y_clo_205 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_clo_205 + -1) = 2048;
  *((value *) $y_clo_205 + 0) = y_131;
  *((value *) $y_clo_205 + 1) = $env_203;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 3) = $qpos_200;
  *(root + 2) = $n_199;
  *(root + 1) = $rules_198;
  *(root + 0) = $kp_197;
  frame.next = root + 4;
  (*$tinfo).fp = &frame;
  $prim_206 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_199, $y_wrapper_clo_204, $y_clo_205);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(13 <= $limit - $alloc)) {
    *(root + 4) = $prim_206;
    frame.next = root + 5;
    (*$tinfo).nalloc = 13;
    garbage_collect($tinfo);
    $prim_206 = *(root + 4);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qpos_200 = *(root + 3);
  $n_199 = *(root + 2);
  $rules_198 = *(root + 1);
  $kp_197 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_207 = ((value (*)(value)) bench_nat_succ)($qpos_200);
  $prim_208 = ((value (*)(value)) bench_input_byte)($qpos_200);
  $prim_209 = ((value (*)(void)) bench_lit_4)();
  $prim_210 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_208, $prim_209);
  $prim_211 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_207, $prim_210);
  $prim_212 = ((value (*)(void)) bench_lit_8)();
  $prim_213 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_211, $prim_212);
  $prim_214 = ((value (*)(void)) bench_lit_20)();
  $prim_215 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_213, $prim_214);
  $env_216 = 1;
  $env_217 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_217 + -1) = 3072;
  *((value *) $env_217 + 0) = $rules_198;
  *((value *) $env_217 + 1) = $n_199;
  *((value *) $env_217 + 2) = $prim_215;
  $y_wrapper_clo_218 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_218 + -1) = 2048;
  *((value *) $y_wrapper_clo_218 + 0) = y_wrapper_128;
  *((value *) $y_wrapper_clo_218 + 1) = $env_216;
  $y_wrapper_clo_219 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_219 + -1) = 2048;
  *((value *) $y_wrapper_clo_219 + 0) = y_wrapper_146;
  *((value *) $y_wrapper_clo_219 + 1) = $env_217;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $prim_206;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_220 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $kp_197, $y_wrapper_clo_218, $y_wrapper_clo_219);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_220;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_220 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_206 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_221 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_221 + -1) = 2048;
  *((value *) $y_221 + 0) = $prim_206;
  *((value *) $y_221 + 1) = $prim_220;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_221;
}

value y_wrapper_128(struct thread_info *$tinfo, value $env_193, value $anon_194)
{
  struct stack_frame frame;
  value root[0];
  register value $y_195;
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
  $y_195 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_195;
}

value EncoreBenchdW3dPolicydrun_known_127(struct thread_info *$tinfo, value $n_174)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_175;
  register value $prim_176;
  register value $prim_177;
  register value $prim_178;
  register value $prim_179;
  register value $prim_180;
  register value $prim_181;
  register value $prim_182;
  register value $prim_183;
  register value $prim_184;
  register value $prim_185;
  register value $prim_186;
  register value $prim_187;
  register value $env_188;
  register value $env_189;
  register value $y_wrapper_clo_190;
  register value $y_wrapper_clo_191;
  register value $prim_192;
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
  if (!(10 <= $limit - $alloc)) {
    *(root + 0) = $n_174;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 10;
    garbage_collect($tinfo);
    $n_174 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_175 = ((value (*)(void)) bench_nat_zero)();
  $prim_176 = ((value (*)(value)) bench_input_byte)($prim_175);
  $prim_177 = ((value (*)(void)) bench_lit_3)();
  $prim_178 = ((value (*)(void)) bench_nat_zero)();
  $prim_179 = ((value (*)(value)) bench_nat_succ)($prim_178);
  $prim_180 = ((value (*)(value)) bench_input_byte)($prim_179);
  $prim_181 = ((value (*)(void)) bench_lit_256)();
  $prim_182 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_180, $prim_181);
  $prim_183 = ((value (*)(void)) bench_nat_zero)();
  $prim_184 = ((value (*)(value)) bench_nat_succ)($prim_183);
  $prim_185 = ((value (*)(value)) bench_nat_succ)($prim_184);
  $prim_186 = ((value (*)(value)) bench_input_byte)($prim_185);
  $prim_187 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_182, $prim_186);
  $env_188 = 1;
  $env_189 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_189 + -1) = 3072;
  *((value *) $env_189 + 0) = $prim_187;
  *((value *) $env_189 + 1) = $n_174;
  *((value *) $env_189 + 2) = $prim_177;
  $y_wrapper_clo_190 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_190 + -1) = 2048;
  *((value *) $y_wrapper_clo_190 + 0) = y_wrapper_128;
  *((value *) $y_wrapper_clo_190 + 1) = $env_188;
  $y_wrapper_clo_191 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_191 + -1) = 2048;
  *((value *) $y_wrapper_clo_191 + 0) = y_wrapper_146;
  *((value *) $y_wrapper_clo_191 + 1) = $env_189;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_192 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_176, $y_wrapper_clo_190, $y_wrapper_clo_191);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_192;
}

value y_wrapper_126(struct thread_info *$tinfo, value $env_168, value $np_169)
{
  struct stack_frame frame;
  value root[2];
  register value $b_proj_171;
  register value $a_proj_172;
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
  $b_proj_171 = *((value *) $env_168 + 0);
  $a_proj_172 = *((value *) $env_168 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_125)
    ($tinfo, $np_169, $b_proj_171, $a_proj_172);
  return $result;
}

value y_known_125(struct thread_info *$tinfo, value $np_152, value $b_153, value $a_154)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_155;
  register value $prim_156;
  register value $prim_157;
  register value $y_158;
  register value $prim_159;
  register value $prim_160;
  register value $prim_161;
  register value $env_162;
  register value $env_163;
  register value $y_wrapper_clo_164;
  register value $y_wrapper_clo_165;
  register value $prim_166;
  register value $y_167;
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
  if (!(9 <= $limit - $alloc)) {
    *(root + 2) = $a_154;
    *(root + 1) = $b_153;
    *(root + 0) = $np_152;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $a_154 = *(root + 2);
    $b_153 = *(root + 1);
    $np_152 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_155 = ((value (*)(value)) bench_input_byte)($a_154);
  $prim_156 = ((value (*)(value)) bench_input_byte)($b_153);
  $prim_157 =
    ((value (*)(value, value)) bench_nat_ltb)
    ($prim_155, $prim_156);
  if (($prim_157 & 1) == 0) {
    switch (*((value *) $prim_157 + -1) & 255) {
      
    }
  } else {
    switch ($prim_157 >> 1) {
      case 0:
        $y_158 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_158;
        break;
      default:
        $prim_159 =
          ((value (*)(value, value)) bench_nat_eqb)
          ($prim_155, $prim_156);
        if (($prim_159 & 1) == 0) {
          switch (*((value *) $prim_159 + -1) & 255) {
            
          }
        } else {
          switch ($prim_159 >> 1) {
            case 0:
              $prim_160 = ((value (*)(value)) bench_nat_succ)($a_154);
              $prim_161 = ((value (*)(value)) bench_nat_succ)($b_153);
              $env_162 = 1;
              $env_163 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $env_163 + -1) = 2048;
              *((value *) $env_163 + 0) = $prim_161;
              *((value *) $env_163 + 1) = $prim_160;
              $y_wrapper_clo_164 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_164 + -1) = 2048;
              *((value *) $y_wrapper_clo_164 + 0) = y_wrapper_124;
              *((value *) $y_wrapper_clo_164 + 1) = $env_162;
              $y_wrapper_clo_165 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_165 + -1) = 2048;
              *((value *) $y_wrapper_clo_165 + 0) = y_wrapper_126;
              *((value *) $y_wrapper_clo_165 + 1) = $env_163;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_166 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $np_152, $y_wrapper_clo_164, $y_wrapper_clo_165);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_166;
              break;
            default:
              $y_167 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_167;
              break;
            
          }
        }
        break;
      
    }
  }
}

value y_wrapper_124(struct thread_info *$tinfo, value $env_148, value $anon_149)
{
  struct stack_frame frame;
  value root[0];
  register value $y_150;
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
  $y_150 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_150;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
  register value $prim_432;
  register value $prim_433;
  register value $prim_434;
  register value $prim_435;
  register value $prim_436;
  register value $prim_437;
  register value $prim_438;
  register value $prim_439;
  register value $prim_440;
  register value $prim_441;
  register value $prim_442;
  register value $prim_443;
  register value $prim_444;
  register value $prim_445;
  register value $prim_446;
  register value $prim_447;
  register value $prim_448;
  register value $prim_449;
  register value $prim_450;
  register value $prim_451;
  register value $prim_452;
  register value $prim_453;
  register value $prim_454;
  register value $prim_455;
  register value $prim_456;
  register value $prim_457;
  register value $prim_458;
  register value $prim_459;
  register value $prim_460;
  register value $prim_461;
  register value $prim_462;
  register value $prim_463;
  register value $prim_464;
  register value $prim_465;
  register value $prim_466;
  register value $prim_467;
  register value $prim_468;
  register value $prim_469;
  register value $prim_470;
  register value $prim_471;
  register value $prim_472;
  register value $prim_473;
  register value $prim_474;
  register value $prim_475;
  register value $prim_476;
  register value $prim_477;
  register value $prim_478;
  register value $prim_479;
  register value $prim_480;
  register value $prim_481;
  register value $prim_482;
  register value $prim_483;
  register value $prim_484;
  register value $prim_485;
  register value $prim_486;
  register value $prim_487;
  register value $prim_488;
  register value $prim_489;
  register value $prim_490;
  register value $prim_491;
  register value $prim_492;
  register value $prim_493;
  register value $prim_494;
  register value $prim_495;
  register value $prim_496;
  register value $prim_497;
  register value $prim_498;
  register value $prim_499;
  register value $prim_500;
  register value $prim_501;
  register value $prim_502;
  register value $prim_503;
  register value $prim_504;
  register value $prim_505;
  register value $prim_506;
  register value $prim_507;
  register value $prim_508;
  register value $prim_509;
  register value $prim_510;
  register value $prim_511;
  register value $prim_512;
  register value $prim_513;
  register value $prim_514;
  register value $prim_515;
  register value $prim_516;
  register value $prim_517;
  register value $prim_518;
  register value $prim_519;
  register value $prim_520;
  register value $prim_521;
  register value $prim_522;
  register value $prim_523;
  register value $prim_524;
  register value $prim_525;
  register value $prim_526;
  register value $prim_527;
  register value $prim_528;
  register value $prim_529;
  register value $prim_530;
  register value $prim_531;
  register value $prim_532;
  register value $prim_533;
  register value $prim_534;
  register value $prim_535;
  register value $prim_536;
  register value $prim_537;
  register value $prim_538;
  register value $prim_539;
  register value $prim_540;
  register value $prim_541;
  register value $prim_542;
  register value $prim_543;
  register value $prim_544;
  register value $prim_545;
  register value $prim_546;
  register value $prim_547;
  register value $prim_548;
  register value $prim_549;
  register value $prim_550;
  register value $prim_551;
  register value $prim_552;
  register value $prim_553;
  register value $prim_554;
  register value $prim_555;
  register value $prim_556;
  register value $prim_557;
  register value $prim_558;
  register value $prim_559;
  register value $prim_560;
  register value $prim_561;
  register value $prim_562;
  register value $prim_563;
  register value $prim_564;
  register value $prim_565;
  register value $prim_566;
  register value $prim_567;
  register value $prim_568;
  register value $prim_569;
  register value $prim_570;
  register value $prim_571;
  register value $prim_572;
  register value $prim_573;
  register value $prim_574;
  register value $prim_575;
  register value $prim_576;
  register value $prim_577;
  register value $prim_578;
  register value $prim_579;
  register value $prim_580;
  register value $prim_581;
  register value $prim_582;
  register value $prim_583;
  register value $prim_584;
  register value $prim_585;
  register value $prim_586;
  register value $prim_587;
  register value $prim_588;
  register value $prim_589;
  register value $prim_590;
  register value $prim_591;
  register value $prim_592;
  register value $prim_593;
  register value $prim_594;
  register value $prim_595;
  register value $prim_596;
  register value $prim_597;
  register value $prim_598;
  register value $prim_599;
  register value $prim_600;
  register value $prim_601;
  register value $prim_602;
  register value $prim_603;
  register value $prim_604;
  register value $prim_605;
  register value $prim_606;
  register value $prim_607;
  register value $prim_608;
  register value $prim_609;
  register value $prim_610;
  register value $prim_611;
  register value $prim_612;
  register value $prim_613;
  register value $prim_614;
  register value $prim_615;
  register value $prim_616;
  register value $prim_617;
  register value $prim_618;
  register value $prim_619;
  register value $prim_620;
  register value $prim_621;
  register value $prim_622;
  register value $prim_623;
  register value $prim_624;
  register value $prim_625;
  register value $prim_626;
  register value $prim_627;
  register value $prim_628;
  register value $prim_629;
  register value $prim_630;
  register value $prim_631;
  register value $prim_632;
  register value $prim_633;
  register value $prim_634;
  register value $prim_635;
  register value $prim_636;
  register value $prim_637;
  register value $prim_638;
  register value $prim_639;
  register value $prim_640;
  register value $prim_641;
  register value $prim_642;
  register value $prim_643;
  register value $prim_644;
  register value $prim_645;
  register value $prim_646;
  register value $prim_647;
  register value $prim_648;
  register value $prim_649;
  register value $prim_650;
  register value $prim_651;
  register value $prim_652;
  register value $prim_653;
  register value $prim_654;
  register value $prim_655;
  register value $prim_656;
  register value $prim_657;
  register value $prim_658;
  register value $prim_659;
  register value $prim_660;
  register value $prim_661;
  register value $prim_662;
  register value $prim_663;
  register value $prim_664;
  register value $prim_665;
  register value $prim_666;
  register value $prim_667;
  register value $prim_668;
  register value $prim_669;
  register value $prim_670;
  register value $prim_671;
  register value $prim_672;
  register value $prim_673;
  register value $prim_674;
  register value $prim_675;
  register value $prim_676;
  register value $prim_677;
  register value $prim_678;
  register value $prim_679;
  register value $prim_680;
  register value $prim_681;
  register value $prim_682;
  register value $prim_683;
  register value $prim_684;
  register value $prim_685;
  register value $prim_686;
  register value $prim_687;
  register value $prim_688;
  register value $prim_689;
  register value $prim_690;
  register value $prim_691;
  register value $prim_692;
  register value $prim_693;
  register value $prim_694;
  register value $prim_695;
  register value $prim_696;
  register value $prim_697;
  register value $prim_698;
  register value $prim_699;
  register value $prim_700;
  register value $prim_701;
  register value $prim_702;
  register value $prim_703;
  register value $prim_704;
  register value $prim_705;
  register value $prim_706;
  register value $prim_707;
  register value $prim_708;
  register value $prim_709;
  register value $prim_710;
  register value $prim_711;
  register value $prim_712;
  register value $prim_713;
  register value $prim_714;
  register value $prim_715;
  register value $prim_716;
  register value $prim_717;
  register value $prim_718;
  register value $prim_719;
  register value $prim_720;
  register value $prim_721;
  register value $prim_722;
  register value $prim_723;
  register value $prim_724;
  register value $prim_725;
  register value $prim_726;
  register value $prim_727;
  register value $prim_728;
  register value $prim_729;
  register value $prim_730;
  register value $prim_731;
  register value $prim_732;
  register value $prim_733;
  register value $prim_734;
  register value $prim_735;
  register value $prim_736;
  register value $prim_737;
  register value $prim_738;
  register value $prim_739;
  register value $prim_740;
  register value $prim_741;
  register value $prim_742;
  register value $prim_743;
  register value $prim_744;
  register value $prim_745;
  register value $env_746;
  register value $EncoreBenchdW3dPolicydrun_wrapper_clo_747;
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
  $prim_432 = ((value (*)(void)) bench_nat_zero)();
  $prim_433 = ((value (*)(value)) bench_nat_succ)($prim_432);
  $prim_434 = ((value (*)(value)) bench_nat_succ)($prim_433);
  $prim_435 = ((value (*)(value)) bench_nat_succ)($prim_434);
  $prim_436 = ((value (*)(value)) bench_nat_succ)($prim_435);
  $prim_437 = ((value (*)(value)) bench_nat_succ)($prim_436);
  $prim_438 = ((value (*)(value)) bench_nat_succ)($prim_437);
  $prim_439 = ((value (*)(value)) bench_nat_succ)($prim_438);
  $prim_440 = ((value (*)(value)) bench_nat_succ)($prim_439);
  $prim_441 = ((value (*)(void)) bench_nat_zero)();
  $prim_442 = ((value (*)(value)) bench_nat_succ)($prim_441);
  $prim_443 = ((value (*)(value)) bench_nat_succ)($prim_442);
  $prim_444 = ((value (*)(value)) bench_nat_succ)($prim_443);
  $prim_445 = ((value (*)(value)) bench_nat_succ)($prim_444);
  $prim_446 = ((value (*)(void)) bench_nat_zero)();
  $prim_447 = ((value (*)(value)) bench_nat_succ)($prim_446);
  $prim_448 = ((value (*)(value)) bench_nat_succ)($prim_447);
  $prim_449 = ((value (*)(value)) bench_nat_succ)($prim_448);
  $prim_450 = ((value (*)(value)) bench_nat_succ)($prim_449);
  $prim_451 = ((value (*)(value)) bench_nat_succ)($prim_450);
  $prim_452 = ((value (*)(value)) bench_nat_succ)($prim_451);
  $prim_453 = ((value (*)(value)) bench_nat_succ)($prim_452);
  $prim_454 = ((value (*)(value)) bench_nat_succ)($prim_453);
  $prim_455 = ((value (*)(void)) bench_nat_zero)();
  $prim_456 = ((value (*)(value)) bench_nat_succ)($prim_455);
  $prim_457 = ((value (*)(value)) bench_nat_succ)($prim_456);
  $prim_458 = ((value (*)(value)) bench_nat_succ)($prim_457);
  $prim_459 = ((value (*)(value)) bench_nat_succ)($prim_458);
  $prim_460 = ((value (*)(value)) bench_nat_succ)($prim_459);
  $prim_461 = ((value (*)(value)) bench_nat_succ)($prim_460);
  $prim_462 = ((value (*)(value)) bench_nat_succ)($prim_461);
  $prim_463 = ((value (*)(value)) bench_nat_succ)($prim_462);
  $prim_464 = ((value (*)(value)) bench_nat_succ)($prim_463);
  $prim_465 = ((value (*)(value)) bench_nat_succ)($prim_464);
  $prim_466 = ((value (*)(value)) bench_nat_succ)($prim_465);
  $prim_467 = ((value (*)(value)) bench_nat_succ)($prim_466);
  $prim_468 = ((value (*)(value)) bench_nat_succ)($prim_467);
  $prim_469 = ((value (*)(value)) bench_nat_succ)($prim_468);
  $prim_470 = ((value (*)(value)) bench_nat_succ)($prim_469);
  $prim_471 = ((value (*)(value)) bench_nat_succ)($prim_470);
  $prim_472 = ((value (*)(value)) bench_nat_succ)($prim_471);
  $prim_473 = ((value (*)(value)) bench_nat_succ)($prim_472);
  $prim_474 = ((value (*)(value)) bench_nat_succ)($prim_473);
  $prim_475 = ((value (*)(value)) bench_nat_succ)($prim_474);
  $prim_476 = ((value (*)(void)) bench_nat_zero)();
  $prim_477 = ((value (*)(value)) bench_nat_succ)($prim_476);
  $prim_478 = ((value (*)(void)) bench_nat_zero)();
  $prim_479 = ((value (*)(value)) bench_nat_succ)($prim_478);
  $prim_480 = ((value (*)(value)) bench_nat_succ)($prim_479);
  $prim_481 = ((value (*)(void)) bench_nat_zero)();
  $prim_482 = ((value (*)(value)) bench_nat_succ)($prim_481);
  $prim_483 = ((value (*)(value)) bench_nat_succ)($prim_482);
  $prim_484 = ((value (*)(value)) bench_nat_succ)($prim_483);
  $prim_485 = ((value (*)(void)) bench_nat_zero)();
  $prim_486 = ((value (*)(value)) bench_nat_succ)($prim_485);
  $prim_487 = ((value (*)(value)) bench_nat_succ)($prim_486);
  $prim_488 = ((value (*)(value)) bench_nat_succ)($prim_487);
  $prim_489 = ((value (*)(void)) bench_nat_zero)();
  $prim_490 = ((value (*)(value)) bench_nat_succ)($prim_489);
  $prim_491 = ((value (*)(value)) bench_nat_succ)($prim_490);
  $prim_492 = ((value (*)(value)) bench_nat_succ)($prim_491);
  $prim_493 = ((value (*)(value)) bench_nat_succ)($prim_492);
  $prim_494 = ((value (*)(value)) bench_nat_succ)($prim_493);
  $prim_495 = ((value (*)(value)) bench_nat_succ)($prim_494);
  $prim_496 = ((value (*)(value)) bench_nat_succ)($prim_495);
  $prim_497 = ((value (*)(value)) bench_nat_succ)($prim_496);
  $prim_498 = ((value (*)(value)) bench_nat_succ)($prim_497);
  $prim_499 = ((value (*)(value)) bench_nat_succ)($prim_498);
  $prim_500 = ((value (*)(value)) bench_nat_succ)($prim_499);
  $prim_501 = ((value (*)(value)) bench_nat_succ)($prim_500);
  $prim_502 = ((value (*)(value)) bench_nat_succ)($prim_501);
  $prim_503 = ((value (*)(value)) bench_nat_succ)($prim_502);
  $prim_504 = ((value (*)(value)) bench_nat_succ)($prim_503);
  $prim_505 = ((value (*)(value)) bench_nat_succ)($prim_504);
  $prim_506 = ((value (*)(value)) bench_nat_succ)($prim_505);
  $prim_507 = ((value (*)(value)) bench_nat_succ)($prim_506);
  $prim_508 = ((value (*)(value)) bench_nat_succ)($prim_507);
  $prim_509 = ((value (*)(value)) bench_nat_succ)($prim_508);
  $prim_510 = ((value (*)(value)) bench_nat_succ)($prim_509);
  $prim_511 = ((value (*)(value)) bench_nat_succ)($prim_510);
  $prim_512 = ((value (*)(value)) bench_nat_succ)($prim_511);
  $prim_513 = ((value (*)(value)) bench_nat_succ)($prim_512);
  $prim_514 = ((value (*)(value)) bench_nat_succ)($prim_513);
  $prim_515 = ((value (*)(value)) bench_nat_succ)($prim_514);
  $prim_516 = ((value (*)(value)) bench_nat_succ)($prim_515);
  $prim_517 = ((value (*)(value)) bench_nat_succ)($prim_516);
  $prim_518 = ((value (*)(value)) bench_nat_succ)($prim_517);
  $prim_519 = ((value (*)(value)) bench_nat_succ)($prim_518);
  $prim_520 = ((value (*)(value)) bench_nat_succ)($prim_519);
  $prim_521 = ((value (*)(value)) bench_nat_succ)($prim_520);
  $prim_522 = ((value (*)(value)) bench_nat_succ)($prim_521);
  $prim_523 = ((value (*)(value)) bench_nat_succ)($prim_522);
  $prim_524 = ((value (*)(value)) bench_nat_succ)($prim_523);
  $prim_525 = ((value (*)(value)) bench_nat_succ)($prim_524);
  $prim_526 = ((value (*)(value)) bench_nat_succ)($prim_525);
  $prim_527 = ((value (*)(value)) bench_nat_succ)($prim_526);
  $prim_528 = ((value (*)(value)) bench_nat_succ)($prim_527);
  $prim_529 = ((value (*)(value)) bench_nat_succ)($prim_528);
  $prim_530 = ((value (*)(value)) bench_nat_succ)($prim_529);
  $prim_531 = ((value (*)(value)) bench_nat_succ)($prim_530);
  $prim_532 = ((value (*)(value)) bench_nat_succ)($prim_531);
  $prim_533 = ((value (*)(value)) bench_nat_succ)($prim_532);
  $prim_534 = ((value (*)(value)) bench_nat_succ)($prim_533);
  $prim_535 = ((value (*)(value)) bench_nat_succ)($prim_534);
  $prim_536 = ((value (*)(value)) bench_nat_succ)($prim_535);
  $prim_537 = ((value (*)(value)) bench_nat_succ)($prim_536);
  $prim_538 = ((value (*)(value)) bench_nat_succ)($prim_537);
  $prim_539 = ((value (*)(value)) bench_nat_succ)($prim_538);
  $prim_540 = ((value (*)(value)) bench_nat_succ)($prim_539);
  $prim_541 = ((value (*)(value)) bench_nat_succ)($prim_540);
  $prim_542 = ((value (*)(value)) bench_nat_succ)($prim_541);
  $prim_543 = ((value (*)(value)) bench_nat_succ)($prim_542);
  $prim_544 = ((value (*)(value)) bench_nat_succ)($prim_543);
  $prim_545 = ((value (*)(value)) bench_nat_succ)($prim_544);
  $prim_546 = ((value (*)(value)) bench_nat_succ)($prim_545);
  $prim_547 = ((value (*)(value)) bench_nat_succ)($prim_546);
  $prim_548 = ((value (*)(value)) bench_nat_succ)($prim_547);
  $prim_549 = ((value (*)(value)) bench_nat_succ)($prim_548);
  $prim_550 = ((value (*)(value)) bench_nat_succ)($prim_549);
  $prim_551 = ((value (*)(value)) bench_nat_succ)($prim_550);
  $prim_552 = ((value (*)(value)) bench_nat_succ)($prim_551);
  $prim_553 = ((value (*)(value)) bench_nat_succ)($prim_552);
  $prim_554 = ((value (*)(value)) bench_nat_succ)($prim_553);
  $prim_555 = ((value (*)(value)) bench_nat_succ)($prim_554);
  $prim_556 = ((value (*)(value)) bench_nat_succ)($prim_555);
  $prim_557 = ((value (*)(value)) bench_nat_succ)($prim_556);
  $prim_558 = ((value (*)(value)) bench_nat_succ)($prim_557);
  $prim_559 = ((value (*)(value)) bench_nat_succ)($prim_558);
  $prim_560 = ((value (*)(value)) bench_nat_succ)($prim_559);
  $prim_561 = ((value (*)(value)) bench_nat_succ)($prim_560);
  $prim_562 = ((value (*)(value)) bench_nat_succ)($prim_561);
  $prim_563 = ((value (*)(value)) bench_nat_succ)($prim_562);
  $prim_564 = ((value (*)(value)) bench_nat_succ)($prim_563);
  $prim_565 = ((value (*)(value)) bench_nat_succ)($prim_564);
  $prim_566 = ((value (*)(value)) bench_nat_succ)($prim_565);
  $prim_567 = ((value (*)(value)) bench_nat_succ)($prim_566);
  $prim_568 = ((value (*)(value)) bench_nat_succ)($prim_567);
  $prim_569 = ((value (*)(value)) bench_nat_succ)($prim_568);
  $prim_570 = ((value (*)(value)) bench_nat_succ)($prim_569);
  $prim_571 = ((value (*)(value)) bench_nat_succ)($prim_570);
  $prim_572 = ((value (*)(value)) bench_nat_succ)($prim_571);
  $prim_573 = ((value (*)(value)) bench_nat_succ)($prim_572);
  $prim_574 = ((value (*)(value)) bench_nat_succ)($prim_573);
  $prim_575 = ((value (*)(value)) bench_nat_succ)($prim_574);
  $prim_576 = ((value (*)(value)) bench_nat_succ)($prim_575);
  $prim_577 = ((value (*)(value)) bench_nat_succ)($prim_576);
  $prim_578 = ((value (*)(value)) bench_nat_succ)($prim_577);
  $prim_579 = ((value (*)(value)) bench_nat_succ)($prim_578);
  $prim_580 = ((value (*)(value)) bench_nat_succ)($prim_579);
  $prim_581 = ((value (*)(value)) bench_nat_succ)($prim_580);
  $prim_582 = ((value (*)(value)) bench_nat_succ)($prim_581);
  $prim_583 = ((value (*)(value)) bench_nat_succ)($prim_582);
  $prim_584 = ((value (*)(value)) bench_nat_succ)($prim_583);
  $prim_585 = ((value (*)(value)) bench_nat_succ)($prim_584);
  $prim_586 = ((value (*)(value)) bench_nat_succ)($prim_585);
  $prim_587 = ((value (*)(value)) bench_nat_succ)($prim_586);
  $prim_588 = ((value (*)(value)) bench_nat_succ)($prim_587);
  $prim_589 = ((value (*)(value)) bench_nat_succ)($prim_588);
  $prim_590 = ((value (*)(value)) bench_nat_succ)($prim_589);
  $prim_591 = ((value (*)(value)) bench_nat_succ)($prim_590);
  $prim_592 = ((value (*)(value)) bench_nat_succ)($prim_591);
  $prim_593 = ((value (*)(value)) bench_nat_succ)($prim_592);
  $prim_594 = ((value (*)(value)) bench_nat_succ)($prim_593);
  $prim_595 = ((value (*)(value)) bench_nat_succ)($prim_594);
  $prim_596 = ((value (*)(value)) bench_nat_succ)($prim_595);
  $prim_597 = ((value (*)(value)) bench_nat_succ)($prim_596);
  $prim_598 = ((value (*)(value)) bench_nat_succ)($prim_597);
  $prim_599 = ((value (*)(value)) bench_nat_succ)($prim_598);
  $prim_600 = ((value (*)(value)) bench_nat_succ)($prim_599);
  $prim_601 = ((value (*)(value)) bench_nat_succ)($prim_600);
  $prim_602 = ((value (*)(value)) bench_nat_succ)($prim_601);
  $prim_603 = ((value (*)(value)) bench_nat_succ)($prim_602);
  $prim_604 = ((value (*)(value)) bench_nat_succ)($prim_603);
  $prim_605 = ((value (*)(value)) bench_nat_succ)($prim_604);
  $prim_606 = ((value (*)(value)) bench_nat_succ)($prim_605);
  $prim_607 = ((value (*)(value)) bench_nat_succ)($prim_606);
  $prim_608 = ((value (*)(value)) bench_nat_succ)($prim_607);
  $prim_609 = ((value (*)(value)) bench_nat_succ)($prim_608);
  $prim_610 = ((value (*)(value)) bench_nat_succ)($prim_609);
  $prim_611 = ((value (*)(value)) bench_nat_succ)($prim_610);
  $prim_612 = ((value (*)(value)) bench_nat_succ)($prim_611);
  $prim_613 = ((value (*)(value)) bench_nat_succ)($prim_612);
  $prim_614 = ((value (*)(value)) bench_nat_succ)($prim_613);
  $prim_615 = ((value (*)(value)) bench_nat_succ)($prim_614);
  $prim_616 = ((value (*)(value)) bench_nat_succ)($prim_615);
  $prim_617 = ((value (*)(value)) bench_nat_succ)($prim_616);
  $prim_618 = ((value (*)(value)) bench_nat_succ)($prim_617);
  $prim_619 = ((value (*)(value)) bench_nat_succ)($prim_618);
  $prim_620 = ((value (*)(value)) bench_nat_succ)($prim_619);
  $prim_621 = ((value (*)(value)) bench_nat_succ)($prim_620);
  $prim_622 = ((value (*)(value)) bench_nat_succ)($prim_621);
  $prim_623 = ((value (*)(value)) bench_nat_succ)($prim_622);
  $prim_624 = ((value (*)(value)) bench_nat_succ)($prim_623);
  $prim_625 = ((value (*)(value)) bench_nat_succ)($prim_624);
  $prim_626 = ((value (*)(value)) bench_nat_succ)($prim_625);
  $prim_627 = ((value (*)(value)) bench_nat_succ)($prim_626);
  $prim_628 = ((value (*)(value)) bench_nat_succ)($prim_627);
  $prim_629 = ((value (*)(value)) bench_nat_succ)($prim_628);
  $prim_630 = ((value (*)(value)) bench_nat_succ)($prim_629);
  $prim_631 = ((value (*)(value)) bench_nat_succ)($prim_630);
  $prim_632 = ((value (*)(value)) bench_nat_succ)($prim_631);
  $prim_633 = ((value (*)(value)) bench_nat_succ)($prim_632);
  $prim_634 = ((value (*)(value)) bench_nat_succ)($prim_633);
  $prim_635 = ((value (*)(value)) bench_nat_succ)($prim_634);
  $prim_636 = ((value (*)(value)) bench_nat_succ)($prim_635);
  $prim_637 = ((value (*)(value)) bench_nat_succ)($prim_636);
  $prim_638 = ((value (*)(value)) bench_nat_succ)($prim_637);
  $prim_639 = ((value (*)(value)) bench_nat_succ)($prim_638);
  $prim_640 = ((value (*)(value)) bench_nat_succ)($prim_639);
  $prim_641 = ((value (*)(value)) bench_nat_succ)($prim_640);
  $prim_642 = ((value (*)(value)) bench_nat_succ)($prim_641);
  $prim_643 = ((value (*)(value)) bench_nat_succ)($prim_642);
  $prim_644 = ((value (*)(value)) bench_nat_succ)($prim_643);
  $prim_645 = ((value (*)(value)) bench_nat_succ)($prim_644);
  $prim_646 = ((value (*)(value)) bench_nat_succ)($prim_645);
  $prim_647 = ((value (*)(value)) bench_nat_succ)($prim_646);
  $prim_648 = ((value (*)(value)) bench_nat_succ)($prim_647);
  $prim_649 = ((value (*)(value)) bench_nat_succ)($prim_648);
  $prim_650 = ((value (*)(value)) bench_nat_succ)($prim_649);
  $prim_651 = ((value (*)(value)) bench_nat_succ)($prim_650);
  $prim_652 = ((value (*)(value)) bench_nat_succ)($prim_651);
  $prim_653 = ((value (*)(value)) bench_nat_succ)($prim_652);
  $prim_654 = ((value (*)(value)) bench_nat_succ)($prim_653);
  $prim_655 = ((value (*)(value)) bench_nat_succ)($prim_654);
  $prim_656 = ((value (*)(value)) bench_nat_succ)($prim_655);
  $prim_657 = ((value (*)(value)) bench_nat_succ)($prim_656);
  $prim_658 = ((value (*)(value)) bench_nat_succ)($prim_657);
  $prim_659 = ((value (*)(value)) bench_nat_succ)($prim_658);
  $prim_660 = ((value (*)(value)) bench_nat_succ)($prim_659);
  $prim_661 = ((value (*)(value)) bench_nat_succ)($prim_660);
  $prim_662 = ((value (*)(value)) bench_nat_succ)($prim_661);
  $prim_663 = ((value (*)(value)) bench_nat_succ)($prim_662);
  $prim_664 = ((value (*)(value)) bench_nat_succ)($prim_663);
  $prim_665 = ((value (*)(value)) bench_nat_succ)($prim_664);
  $prim_666 = ((value (*)(value)) bench_nat_succ)($prim_665);
  $prim_667 = ((value (*)(value)) bench_nat_succ)($prim_666);
  $prim_668 = ((value (*)(value)) bench_nat_succ)($prim_667);
  $prim_669 = ((value (*)(value)) bench_nat_succ)($prim_668);
  $prim_670 = ((value (*)(value)) bench_nat_succ)($prim_669);
  $prim_671 = ((value (*)(value)) bench_nat_succ)($prim_670);
  $prim_672 = ((value (*)(value)) bench_nat_succ)($prim_671);
  $prim_673 = ((value (*)(value)) bench_nat_succ)($prim_672);
  $prim_674 = ((value (*)(value)) bench_nat_succ)($prim_673);
  $prim_675 = ((value (*)(value)) bench_nat_succ)($prim_674);
  $prim_676 = ((value (*)(value)) bench_nat_succ)($prim_675);
  $prim_677 = ((value (*)(value)) bench_nat_succ)($prim_676);
  $prim_678 = ((value (*)(value)) bench_nat_succ)($prim_677);
  $prim_679 = ((value (*)(value)) bench_nat_succ)($prim_678);
  $prim_680 = ((value (*)(value)) bench_nat_succ)($prim_679);
  $prim_681 = ((value (*)(value)) bench_nat_succ)($prim_680);
  $prim_682 = ((value (*)(value)) bench_nat_succ)($prim_681);
  $prim_683 = ((value (*)(value)) bench_nat_succ)($prim_682);
  $prim_684 = ((value (*)(value)) bench_nat_succ)($prim_683);
  $prim_685 = ((value (*)(value)) bench_nat_succ)($prim_684);
  $prim_686 = ((value (*)(value)) bench_nat_succ)($prim_685);
  $prim_687 = ((value (*)(value)) bench_nat_succ)($prim_686);
  $prim_688 = ((value (*)(value)) bench_nat_succ)($prim_687);
  $prim_689 = ((value (*)(value)) bench_nat_succ)($prim_688);
  $prim_690 = ((value (*)(value)) bench_nat_succ)($prim_689);
  $prim_691 = ((value (*)(value)) bench_nat_succ)($prim_690);
  $prim_692 = ((value (*)(value)) bench_nat_succ)($prim_691);
  $prim_693 = ((value (*)(value)) bench_nat_succ)($prim_692);
  $prim_694 = ((value (*)(value)) bench_nat_succ)($prim_693);
  $prim_695 = ((value (*)(value)) bench_nat_succ)($prim_694);
  $prim_696 = ((value (*)(value)) bench_nat_succ)($prim_695);
  $prim_697 = ((value (*)(value)) bench_nat_succ)($prim_696);
  $prim_698 = ((value (*)(value)) bench_nat_succ)($prim_697);
  $prim_699 = ((value (*)(value)) bench_nat_succ)($prim_698);
  $prim_700 = ((value (*)(value)) bench_nat_succ)($prim_699);
  $prim_701 = ((value (*)(value)) bench_nat_succ)($prim_700);
  $prim_702 = ((value (*)(value)) bench_nat_succ)($prim_701);
  $prim_703 = ((value (*)(value)) bench_nat_succ)($prim_702);
  $prim_704 = ((value (*)(value)) bench_nat_succ)($prim_703);
  $prim_705 = ((value (*)(value)) bench_nat_succ)($prim_704);
  $prim_706 = ((value (*)(value)) bench_nat_succ)($prim_705);
  $prim_707 = ((value (*)(value)) bench_nat_succ)($prim_706);
  $prim_708 = ((value (*)(value)) bench_nat_succ)($prim_707);
  $prim_709 = ((value (*)(value)) bench_nat_succ)($prim_708);
  $prim_710 = ((value (*)(value)) bench_nat_succ)($prim_709);
  $prim_711 = ((value (*)(value)) bench_nat_succ)($prim_710);
  $prim_712 = ((value (*)(value)) bench_nat_succ)($prim_711);
  $prim_713 = ((value (*)(value)) bench_nat_succ)($prim_712);
  $prim_714 = ((value (*)(value)) bench_nat_succ)($prim_713);
  $prim_715 = ((value (*)(value)) bench_nat_succ)($prim_714);
  $prim_716 = ((value (*)(value)) bench_nat_succ)($prim_715);
  $prim_717 = ((value (*)(value)) bench_nat_succ)($prim_716);
  $prim_718 = ((value (*)(value)) bench_nat_succ)($prim_717);
  $prim_719 = ((value (*)(value)) bench_nat_succ)($prim_718);
  $prim_720 = ((value (*)(value)) bench_nat_succ)($prim_719);
  $prim_721 = ((value (*)(value)) bench_nat_succ)($prim_720);
  $prim_722 = ((value (*)(value)) bench_nat_succ)($prim_721);
  $prim_723 = ((value (*)(value)) bench_nat_succ)($prim_722);
  $prim_724 = ((value (*)(value)) bench_nat_succ)($prim_723);
  $prim_725 = ((value (*)(value)) bench_nat_succ)($prim_724);
  $prim_726 = ((value (*)(value)) bench_nat_succ)($prim_725);
  $prim_727 = ((value (*)(value)) bench_nat_succ)($prim_726);
  $prim_728 = ((value (*)(value)) bench_nat_succ)($prim_727);
  $prim_729 = ((value (*)(value)) bench_nat_succ)($prim_728);
  $prim_730 = ((value (*)(value)) bench_nat_succ)($prim_729);
  $prim_731 = ((value (*)(value)) bench_nat_succ)($prim_730);
  $prim_732 = ((value (*)(value)) bench_nat_succ)($prim_731);
  $prim_733 = ((value (*)(value)) bench_nat_succ)($prim_732);
  $prim_734 = ((value (*)(value)) bench_nat_succ)($prim_733);
  $prim_735 = ((value (*)(value)) bench_nat_succ)($prim_734);
  $prim_736 = ((value (*)(value)) bench_nat_succ)($prim_735);
  $prim_737 = ((value (*)(value)) bench_nat_succ)($prim_736);
  $prim_738 = ((value (*)(value)) bench_nat_succ)($prim_737);
  $prim_739 = ((value (*)(value)) bench_nat_succ)($prim_738);
  $prim_740 = ((value (*)(value)) bench_nat_succ)($prim_739);
  $prim_741 = ((value (*)(value)) bench_nat_succ)($prim_740);
  $prim_742 = ((value (*)(value)) bench_nat_succ)($prim_741);
  $prim_743 = ((value (*)(value)) bench_nat_succ)($prim_742);
  $prim_744 = ((value (*)(value)) bench_nat_succ)($prim_743);
  $prim_745 = ((value (*)(value)) bench_nat_succ)($prim_744);
  $env_746 = 1;
  $EncoreBenchdW3dPolicydrun_wrapper_clo_747 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_747 + -1) = 2048;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_747 + 0) =
    EncoreBenchdW3dPolicydrun_wrapper_147;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_747 + 1) = $env_746;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW3dPolicydrun_wrapper_clo_747;
}


#endif /* W3_POLICY_C */
