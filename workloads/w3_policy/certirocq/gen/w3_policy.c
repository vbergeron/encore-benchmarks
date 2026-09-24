#ifndef W3_POLICY_C
#define W3_POLICY_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "bench_rt.h"
#include "w3_policy.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW3dPolicydrun_wrapper_149(struct thread_info *, value, value);
extern value y_wrapper_148(struct thread_info *, value, value);
extern value f_case_known_147(struct thread_info *, value, value, value);
extern value y_wrapper_146(struct thread_info *, value, value);
extern value y_145(struct thread_info *, value, value);
extern value y_wrapper_144(struct thread_info *, value, value);
extern value y_wrapper_143(struct thread_info *, value, value);
extern value y_wrapper_142(struct thread_info *, value, value);
extern value y_wrapper_141(struct thread_info *, value, value);
extern value y_wrapper_140(struct thread_info *, value, value);
extern value y_wrapper_139(struct thread_info *, value, value);
extern value y_known_138(struct thread_info *, value, value, value);
extern value y_wrapper_137(struct thread_info *, value, value);
extern value y_known_136(struct thread_info *, value, value, value);
extern value y_wrapper_135(struct thread_info *, value, value);
extern value f_case_134(struct thread_info *, value, value);
extern value y_133(struct thread_info *, value, value);
extern value y_wrapper_132(struct thread_info *, value, value);
extern value y_known_131(struct thread_info *, value, value, value, value);
extern value y_wrapper_130(struct thread_info *, value, value);
extern value EncoreBenchdW3dPolicydrun_known_129(struct thread_info *, value);
extern value y_wrapper_128(struct thread_info *, value, value);
extern value y_known_127(struct thread_info *, value, value, value);
extern value y_wrapper_126(struct thread_info *, value, value);
extern value body(struct thread_info *);
value EncoreBenchdW3dPolicydrun_wrapper_149(struct thread_info *, value, value);
value y_wrapper_148(struct thread_info *, value, value);
value f_case_known_147(struct thread_info *, value, value, value);
value y_wrapper_146(struct thread_info *, value, value);
value y_145(struct thread_info *, value, value);
value y_wrapper_144(struct thread_info *, value, value);
value y_wrapper_143(struct thread_info *, value, value);
value y_wrapper_142(struct thread_info *, value, value);
value y_wrapper_141(struct thread_info *, value, value);
value y_wrapper_140(struct thread_info *, value, value);
value y_wrapper_139(struct thread_info *, value, value);
value y_known_138(struct thread_info *, value, value, value);
value y_wrapper_137(struct thread_info *, value, value);
value y_known_136(struct thread_info *, value, value, value);
value y_wrapper_135(struct thread_info *, value, value);
value f_case_134(struct thread_info *, value, value);
value y_133(struct thread_info *, value, value);
value y_wrapper_132(struct thread_info *, value, value);
value y_known_131(struct thread_info *, value, value, value, value);
value y_wrapper_130(struct thread_info *, value, value);
value EncoreBenchdW3dPolicydrun_known_129(struct thread_info *, value);
value y_wrapper_128(struct thread_info *, value, value);
value y_known_127(struct thread_info *, value, value, value);
value y_wrapper_126(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_774[2] = { 3, 0, };

unsigned int const y_wrapper_info_773[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_772[5] = { 9, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_771[4] = { 0, 2, 0, 1, };

unsigned int const EncoreBenchdW3dPolicydrun_known_info_770[3] = { 10, 1, 0,
  };

unsigned int const y_wrapper_info_769[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_768[6] = { 25, 4, 0, 1, 2, 3, };

unsigned int const y_wrapper_info_767[4] = { 0, 2, 0, 1, };

unsigned int const y_info_766[4] = { 15, 2, 0, 1, };

unsigned int const f_case_info_765[4] = { 18, 2, 0, 1, };

unsigned int const y_wrapper_info_764[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_763[5] = { 18, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_762[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_761[5] = { 9, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_760[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_759[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_758[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_757[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_756[4] = { 6, 2, 0, 1, };

unsigned int const y_wrapper_info_755[4] = { 0, 2, 0, 1, };

unsigned int const y_info_754[4] = { 30, 2, 0, 1, };

unsigned int const y_wrapper_info_753[4] = { 10, 2, 0, 1, };

unsigned int const f_case_known_info_752[5] = { 0, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_751[4] = { 0, 2, 0, 1, };

unsigned int const EncoreBenchdW3dPolicydrun_wrapper_info_750[4] = { 0, 2, 0,
  1, };

value EncoreBenchdW3dPolicydrun_wrapper_149(struct thread_info *$tinfo, value $env_431, value $n_432)
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
    ((value (*)(struct thread_info *, value)) EncoreBenchdW3dPolicydrun_known_129)
    ($tinfo, $n_432);
  return $result;
}

value y_wrapper_148(struct thread_info *$tinfo, value $env_425, value $kp_426)
{
  struct stack_frame frame;
  value root[2];
  register value $rules_proj_428;
  register value $n_proj_429;
  register value $qpos_proj_430;
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
  $rules_proj_428 = *((value *) $env_425 + 0);
  $n_proj_429 = *((value *) $env_425 + 1);
  $qpos_proj_430 = *((value *) $env_425 + 2);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value, value)) y_known_131)
    ($tinfo, $kp_426, $rules_proj_428, $n_proj_429, $qpos_proj_430);
  return $result;
}

value f_case_known_147(struct thread_info *$tinfo, value $s_422, value $best_423, value $c_424)
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
  if (($s_422 & 1) == 0) {
    switch (*((value *) $s_422 + -1) & 255) {
      
    }
  } else {
    switch ($s_422 >> 1) {
      case 0:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $c_424;
        break;
      default:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $best_423;
        break;
      
    }
  }
}

value y_wrapper_146(struct thread_info *$tinfo, value $env_411, value $dp_412)
{
  struct stack_frame frame;
  value root[2];
  register value $qpos_proj_413;
  register value $rpos_proj_414;
  register value $qd_proj_415;
  register value $env_416;
  register value $env_417;
  register value $y_wrapper_clo_418;
  register value $y_clo_419;
  register value $prim_420;
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
    *(root + 1) = $dp_412;
    *(root + 0) = $env_411;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 10;
    garbage_collect($tinfo);
    $dp_412 = *(root + 1);
    $env_411 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qpos_proj_413 = *((value *) $env_411 + 0);
  $rpos_proj_414 = *((value *) $env_411 + 1);
  $qd_proj_415 = *((value *) $env_411 + 2);
  $env_416 = 1;
  $env_417 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_417 + -1) = 3072;
  *((value *) $env_417 + 0) = $dp_412;
  *((value *) $env_417 + 1) = $rpos_proj_414;
  *((value *) $env_417 + 2) = $qpos_proj_413;
  $y_wrapper_clo_418 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_418 + -1) = 2048;
  *((value *) $y_wrapper_clo_418 + 0) = y_wrapper_144;
  *((value *) $y_wrapper_clo_418 + 1) = $env_416;
  $y_clo_419 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_clo_419 + -1) = 2048;
  *((value *) $y_clo_419 + 0) = y_145;
  *((value *) $y_clo_419 + 1) = $env_417;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_420 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $qd_proj_415, $y_wrapper_clo_418, $y_clo_419);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_420;
}

value y_145(struct thread_info *$tinfo, value $env_377, value $qdp_378)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_379;
  register value $rpos_proj_380;
  register value $qpos_proj_381;
  register value $env_382;
  register value $env_383;
  register value $y_wrapper_clo_384;
  register value $y_wrapper_clo_385;
  register value $prim_386;
  register value $prim_387;
  register value $qpos_proj_388;
  register value $prim_389;
  register value $rpos_proj_390;
  register value $prim_391;
  register value $env_392;
  register value $env_393;
  register value $y_wrapper_clo_394;
  register value $y_wrapper_clo_395;
  register value $prim_396;
  register value $prim_397;
  register value $rpos_proj_398;
  register value $prim_399;
  register value $prim_400;
  register value $qpos_proj_401;
  register value $prim_402;
  register value $dp_proj_403;
  register value $env_404;
  register value $env_405;
  register value $y_wrapper_clo_406;
  register value $y_wrapper_clo_407;
  register value $prim_408;
  register value $y_409;
  register value $y_410;
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
    *(root + 1) = $qdp_378;
    *(root + 0) = $env_377;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 30;
    garbage_collect($tinfo);
    $qdp_378 = *(root + 1);
    $env_377 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_379 = ((value (*)(void)) bench_lit_4)();
  $rpos_proj_380 = *((value *) $env_377 + 1);
  $qpos_proj_381 = *((value *) $env_377 + 2);
  $env_382 = 1;
  $env_383 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_383 + -1) = 2048;
  *((value *) $env_383 + 0) = $qpos_proj_381;
  *((value *) $env_383 + 1) = $rpos_proj_380;
  $y_wrapper_clo_384 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_384 + -1) = 2048;
  *((value *) $y_wrapper_clo_384 + 0) = y_wrapper_126;
  *((value *) $y_wrapper_clo_384 + 1) = $env_382;
  $y_wrapper_clo_385 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_385 + -1) = 2048;
  *((value *) $y_wrapper_clo_385 + 0) = y_wrapper_128;
  *((value *) $y_wrapper_clo_385 + 1) = $env_383;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $qdp_378;
  *(root + 0) = $env_377;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $prim_386 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_379, $y_wrapper_clo_384, $y_wrapper_clo_385);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(21 <= $limit - $alloc)) {
    *(root + 2) = $prim_386;
    frame.next = root + 3;
    (*$tinfo).nalloc = 21;
    garbage_collect($tinfo);
    $prim_386 = *(root + 2);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qdp_378 = *(root + 1);
  $env_377 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($prim_386 & 1) == 0) {
    switch (*((value *) $prim_386 + -1) & 255) {
      
    }
  } else {
    switch ($prim_386 >> 1) {
      case 0:
        $prim_387 = ((value (*)(void)) bench_lit_4)();
        $qpos_proj_388 = *((value *) $env_377 + 2);
        $prim_389 = ((value (*)(void)) bench_lit_4)();
        $rpos_proj_390 = *((value *) $env_377 + 1);
        $prim_391 =
          ((value (*)(value, value)) bench_nat_add)
          ($rpos_proj_390, $prim_389);
        $env_392 = 1;
        $env_393 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_393 + -1) = 2048;
        *((value *) $env_393 + 0) = $prim_391;
        *((value *) $env_393 + 1) = $qpos_proj_388;
        $y_wrapper_clo_394 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_394 + -1) = 2048;
        *((value *) $y_wrapper_clo_394 + 0) = y_wrapper_126;
        *((value *) $y_wrapper_clo_394 + 1) = $env_392;
        $y_wrapper_clo_395 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_395 + -1) = 2048;
        *((value *) $y_wrapper_clo_395 + 0) = y_wrapper_128;
        *((value *) $y_wrapper_clo_395 + 1) = $env_393;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $qdp_378;
        *(root + 0) = $env_377;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $prim_396 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_387, $y_wrapper_clo_394, $y_wrapper_clo_395);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 2) = $prim_396;
          frame.next = root + 3;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $prim_396 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $qdp_378 = *(root + 1);
        $env_377 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_396 & 1) == 0) {
          switch (*((value *) $prim_396 + -1) & 255) {
            
          }
        } else {
          switch ($prim_396 >> 1) {
            case 0:
              $prim_397 = ((value (*)(void)) bench_lit_8)();
              $rpos_proj_398 = *((value *) $env_377 + 1);
              $prim_399 =
                ((value (*)(value, value)) bench_nat_add)
                ($rpos_proj_398, $prim_397);
              $prim_400 = ((value (*)(void)) bench_lit_4)();
              $qpos_proj_401 = *((value *) $env_377 + 2);
              $prim_402 =
                ((value (*)(value, value)) bench_nat_add)
                ($qpos_proj_401, $prim_400);
              $dp_proj_403 = *((value *) $env_377 + 0);
              $env_404 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $env_404 + -1) = 1024;
              *((value *) $env_404 + 0) = $qdp_378;
              $env_405 = (value) ($alloc + 1);
              $alloc = $alloc + 4;
              *((value *) $env_405 + -1) = 3072;
              *((value *) $env_405 + 0) = $prim_402;
              *((value *) $env_405 + 1) = $prim_399;
              *((value *) $env_405 + 2) = $qdp_378;
              $y_wrapper_clo_406 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_406 + -1) = 2048;
              *((value *) $y_wrapper_clo_406 + 0) = y_wrapper_143;
              *((value *) $y_wrapper_clo_406 + 1) = $env_404;
              $y_wrapper_clo_407 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_407 + -1) = 2048;
              *((value *) $y_wrapper_clo_407 + 0) = y_wrapper_146;
              *((value *) $y_wrapper_clo_407 + 1) = $env_405;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_408 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $dp_proj_403, $y_wrapper_clo_406, $y_wrapper_clo_407);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_408;
              break;
            default:
              $y_409 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_409;
              break;
            
          }
        }
        break;
      default:
        $y_410 = 3;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_410;
        break;
      
    }
  }
}

value y_wrapper_144(struct thread_info *$tinfo, value $env_374, value $anon_375)
{
  struct stack_frame frame;
  value root[0];
  register value $y_376;
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
  $y_376 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_376;
}

value y_wrapper_143(struct thread_info *$tinfo, value $env_366, value $anon_367)
{
  struct stack_frame frame;
  value root[1];
  register value $qd_proj_368;
  register value $env_369;
  register value $env_370;
  register value $y_wrapper_clo_371;
  register value $y_wrapper_clo_372;
  register value $prim_373;
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
    *(root + 0) = $env_366;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 6;
    garbage_collect($tinfo);
    $env_366 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qd_proj_368 = *((value *) $env_366 + 0);
  $env_369 = 1;
  $env_370 = 1;
  $y_wrapper_clo_371 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_371 + -1) = 2048;
  *((value *) $y_wrapper_clo_371 + 0) = y_wrapper_141;
  *((value *) $y_wrapper_clo_371 + 1) = $env_369;
  $y_wrapper_clo_372 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_372 + -1) = 2048;
  *((value *) $y_wrapper_clo_372 + 0) = y_wrapper_142;
  *((value *) $y_wrapper_clo_372 + 1) = $env_370;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_373 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $qd_proj_368, $y_wrapper_clo_371, $y_wrapper_clo_372);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_373;
}

value y_wrapper_142(struct thread_info *$tinfo, value $env_363, value $n_364)
{
  struct stack_frame frame;
  value root[0];
  register value $y_365;
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
  $y_365 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_365;
}

value y_wrapper_141(struct thread_info *$tinfo, value $env_360, value $anon_361)
{
  struct stack_frame frame;
  value root[0];
  register value $y_362;
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
  $y_362 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_362;
}

value y_wrapper_140(struct thread_info *$tinfo, value $env_355, value $kp_356)
{
  struct stack_frame frame;
  value root[2];
  register value $q_proj_358;
  register value $pos_proj_359;
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
  $q_proj_358 = *((value *) $env_355 + 0);
  $pos_proj_359 = *((value *) $env_355 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_136)
    ($tinfo, $kp_356, $q_proj_358, $pos_proj_359);
  return $result;
}

value y_wrapper_139(struct thread_info *$tinfo, value $env_350, value $np_351)
{
  struct stack_frame frame;
  value root[2];
  register value $b_proj_353;
  register value $a_proj_354;
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
  $b_proj_353 = *((value *) $env_350 + 0);
  $a_proj_354 = *((value *) $env_350 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_138)
    ($tinfo, $np_351, $b_proj_353, $a_proj_354);
  return $result;
}

value y_known_138(struct thread_info *$tinfo, value $np_336, value $b_337, value $a_338)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_339;
  register value $prim_340;
  register value $prim_341;
  register value $prim_342;
  register value $prim_343;
  register value $env_344;
  register value $env_345;
  register value $y_wrapper_clo_346;
  register value $y_wrapper_clo_347;
  register value $prim_348;
  register value $y_349;
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
    *(root + 2) = $a_338;
    *(root + 1) = $b_337;
    *(root + 0) = $np_336;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $a_338 = *(root + 2);
    $b_337 = *(root + 1);
    $np_336 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_339 = ((value (*)(value)) bench_input_byte)($a_338);
  $prim_340 = ((value (*)(value)) bench_input_byte)($b_337);
  $prim_341 =
    ((value (*)(value, value)) bench_nat_eqb)
    ($prim_339, $prim_340);
  if (($prim_341 & 1) == 0) {
    switch (*((value *) $prim_341 + -1) & 255) {
      
    }
  } else {
    switch ($prim_341 >> 1) {
      case 0:
        $prim_342 = ((value (*)(value)) bench_nat_succ)($a_338);
        $prim_343 = ((value (*)(value)) bench_nat_succ)($b_337);
        $env_344 = 1;
        $env_345 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_345 + -1) = 2048;
        *((value *) $env_345 + 0) = $prim_343;
        *((value *) $env_345 + 1) = $prim_342;
        $y_wrapper_clo_346 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_346 + -1) = 2048;
        *((value *) $y_wrapper_clo_346 + 0) = y_wrapper_137;
        *((value *) $y_wrapper_clo_346 + 1) = $env_344;
        $y_wrapper_clo_347 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_347 + -1) = 2048;
        *((value *) $y_wrapper_clo_347 + 0) = y_wrapper_139;
        *((value *) $y_wrapper_clo_347 + 1) = $env_345;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_348 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $np_336, $y_wrapper_clo_346, $y_wrapper_clo_347);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_348;
        break;
      default:
        $y_349 = 3;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_349;
        break;
      
    }
  }
}

value y_wrapper_137(struct thread_info *$tinfo, value $env_332, value $anon_333)
{
  struct stack_frame frame;
  value root[0];
  register value $y_334;
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
  $y_334 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_334;
}

value y_known_136(struct thread_info *$tinfo, value $kp_315, value $q_316, value $pos_317)
{
  struct stack_frame frame;
  value root[4];
  register value $prim_318;
  register value $env_319;
  register value $env_320;
  register value $y_wrapper_clo_321;
  register value $y_wrapper_clo_322;
  register value $prim_323;
  register value $y_324;
  register value $prim_325;
  register value $prim_326;
  register value $env_327;
  register value $env_328;
  register value $y_wrapper_clo_329;
  register value $y_wrapper_clo_330;
  register value $prim_331;
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
    *(root + 2) = $pos_317;
    *(root + 1) = $q_316;
    *(root + 0) = $kp_315;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18;
    garbage_collect($tinfo);
    $pos_317 = *(root + 2);
    $q_316 = *(root + 1);
    $kp_315 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_318 = ((value (*)(void)) bench_lit_20)();
  $env_319 = 1;
  $env_320 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_320 + -1) = 2048;
  *((value *) $env_320 + 0) = $pos_317;
  *((value *) $env_320 + 1) = $q_316;
  $y_wrapper_clo_321 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_321 + -1) = 2048;
  *((value *) $y_wrapper_clo_321 + 0) = y_wrapper_137;
  *((value *) $y_wrapper_clo_321 + 1) = $env_319;
  $y_wrapper_clo_322 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_322 + -1) = 2048;
  *((value *) $y_wrapper_clo_322 + 0) = y_wrapper_139;
  *((value *) $y_wrapper_clo_322 + 1) = $env_320;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $pos_317;
  *(root + 1) = $q_316;
  *(root + 0) = $kp_315;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $prim_323 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_318, $y_wrapper_clo_321, $y_wrapper_clo_322);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(9 <= $limit - $alloc)) {
    *(root + 3) = $prim_323;
    frame.next = root + 4;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $prim_323 = *(root + 3);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_317 = *(root + 2);
  $q_316 = *(root + 1);
  $kp_315 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($prim_323 & 1) == 0) {
    switch (*((value *) $prim_323 + -1) & 255) {
      
    }
  } else {
    switch ($prim_323 >> 1) {
      case 0:
        $y_324 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_324;
        break;
      default:
        $prim_325 = ((value (*)(void)) bench_lit_20)();
        $prim_326 =
          ((value (*)(value, value)) bench_nat_add)
          ($pos_317, $prim_325);
        $env_327 = 1;
        $env_328 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_328 + -1) = 2048;
        *((value *) $env_328 + 0) = $q_316;
        *((value *) $env_328 + 1) = $prim_326;
        $y_wrapper_clo_329 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_329 + -1) = 2048;
        *((value *) $y_wrapper_clo_329 + 0) = y_wrapper_135;
        *((value *) $y_wrapper_clo_329 + 1) = $env_327;
        $y_wrapper_clo_330 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_330 + -1) = 2048;
        *((value *) $y_wrapper_clo_330 + 0) = y_wrapper_140;
        *((value *) $y_wrapper_clo_330 + 1) = $env_328;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_331 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_315, $y_wrapper_clo_329, $y_wrapper_clo_330);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_331;
        break;
      
    }
  }
}

value y_wrapper_135(struct thread_info *$tinfo, value $env_311, value $anon_312)
{
  struct stack_frame frame;
  value root[0];
  register value $y_313;
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
  $y_313 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_313;
}

value f_case_134(struct thread_info *$tinfo, value $env_284, value $s_285)
{
  struct stack_frame frame;
  value root[2];
  register value $prim_286;
  register value $prim_proj_287;
  register value $prim_proj_288;
  register value $env_289;
  register value $env_290;
  register value $y_wrapper_clo_291;
  register value $y_wrapper_clo_292;
  register value $prim_293;
  register value $prim_294;
  register value $prim_proj_295;
  register value $prim_296;
  register value $prim_297;
  register value $prim_298;
  register value $prim_299;
  register value $prim_proj_300;
  register value $prim_301;
  register value $env_302;
  register value $env_303;
  register value $y_wrapper_clo_304;
  register value $y_wrapper_clo_305;
  register value $prim_306;
  register value $prim_307;
  register value $prim_308;
  register value $prim_309;
  register value $prim_310;
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
    *(root + 1) = $s_285;
    *(root + 0) = $env_284;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18;
    garbage_collect($tinfo);
    $s_285 = *(root + 1);
    $env_284 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_285 & 1) == 0) {
    switch (*((value *) $s_285 + -1) & 255) {
      
    }
  } else {
    switch ($s_285 >> 1) {
      case 0:
        $prim_286 = ((value (*)(void)) bench_lit_8)();
        $prim_proj_287 = *((value *) $env_284 + 1);
        $prim_proj_288 = *((value *) $env_284 + 0);
        $env_289 = 1;
        $env_290 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_290 + -1) = 2048;
        *((value *) $env_290 + 0) = $prim_proj_288;
        *((value *) $env_290 + 1) = $prim_proj_287;
        $y_wrapper_clo_291 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_291 + -1) = 2048;
        *((value *) $y_wrapper_clo_291 + 0) = y_wrapper_126;
        *((value *) $y_wrapper_clo_291 + 1) = $env_289;
        $y_wrapper_clo_292 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_292 + -1) = 2048;
        *((value *) $y_wrapper_clo_292 + 0) = y_wrapper_128;
        *((value *) $y_wrapper_clo_292 + 1) = $env_290;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_284;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_293 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_286, $y_wrapper_clo_291, $y_wrapper_clo_292);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 1) = $prim_293;
          frame.next = root + 2;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $prim_293 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $env_284 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_293 & 1) == 0) {
          switch (*((value *) $prim_293 + -1) & 255) {
            
          }
        } else {
          switch ($prim_293 >> 1) {
            case 0:
              $prim_294 = ((value (*)(void)) bench_lit_8)();
              $prim_proj_295 = *((value *) $env_284 + 0);
              $prim_296 =
                ((value (*)(value, value)) bench_nat_add)
                ($prim_proj_295, $prim_294);
              $prim_297 = ((value (*)(value)) bench_input_byte)($prim_296);
              $prim_298 = ((value (*)(value)) bench_nat_succ)($prim_296);
              $prim_299 = ((value (*)(void)) bench_lit_8)();
              $prim_proj_300 = *((value *) $env_284 + 1);
              $prim_301 =
                ((value (*)(value, value)) bench_nat_add)
                ($prim_proj_300, $prim_299);
              $env_302 = 1;
              $env_303 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $env_303 + -1) = 2048;
              *((value *) $env_303 + 0) = $prim_301;
              *((value *) $env_303 + 1) = $prim_298;
              $y_wrapper_clo_304 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_304 + -1) = 2048;
              *((value *) $y_wrapper_clo_304 + 0) = y_wrapper_135;
              *((value *) $y_wrapper_clo_304 + 1) = $env_302;
              $y_wrapper_clo_305 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_305 + -1) = 2048;
              *((value *) $y_wrapper_clo_305 + 0) = y_wrapper_140;
              *((value *) $y_wrapper_clo_305 + 1) = $env_303;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_306 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $prim_297, $y_wrapper_clo_304, $y_wrapper_clo_305);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              if (($prim_306 & 1) == 0) {
                switch (*((value *) $prim_306 + -1) & 255) {
                  
                }
              } else {
                switch ($prim_306 >> 1) {
                  case 0:
                    $prim_307 = ((value (*)(void)) bench_nat_zero)();
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $prim_307;
                    break;
                  default:
                    $prim_308 = ((value (*)(void)) bench_lit_1)();
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $prim_308;
                    break;
                  
                }
              }
              break;
            default:
              $prim_309 = ((value (*)(void)) bench_lit_2)();
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_309;
              break;
            
          }
        }
        break;
      default:
        $prim_310 = ((value (*)(void)) bench_lit_3)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_310;
        break;
      
    }
  }
}

value y_133(struct thread_info *$tinfo, value $env_227, value $kp_228)
{
  struct stack_frame frame;
  value root[4];
  register value $rpos_proj_229;
  register value $prim_230;
  register value $rpos_proj_231;
  register value $prim_232;
  register value $prim_233;
  register value $prim_234;
  register value $prim_235;
  register value $qpos_proj_236;
  register value $prim_237;
  register value $qpos_proj_238;
  register value $prim_239;
  register value $prim_240;
  register value $prim_241;
  register value $prim_242;
  register value $env_243;
  register value $qpos_proj_244;
  register value $prim_245;
  register value $rpos_proj_246;
  register value $prim_247;
  register value $qpos_proj_248;
  register value $prim_249;
  register value $env_250;
  register value $env_251;
  register value $y_wrapper_clo_252;
  register value $y_wrapper_clo_253;
  register value $prim_254;
  register value $c_255;
  register value $prim_256;
  register value $prim_257;
  register value $prim_258;
  register value $rpos_proj_259;
  register value $prim_260;
  register value $rpos_proj_261;
  register value $prim_262;
  register value $prim_263;
  register value $prim_264;
  register value $prim_265;
  register value $prim_266;
  register value $prim_267;
  register value $prim_268;
  register value $prim_269;
  register value $prim_270;
  register value $prim_271;
  register value $prim_272;
  register value $best_proj_274;
  register value $prim_275;
  register value $best_proj_276;
  register value $y_277;
  register value $qpos_proj_278;
  register value $env_279;
  register value $env_280;
  register value $y_wrapper_clo_281;
  register value $y_clo_282;
  register value $prim_283;
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
    *(root + 1) = $kp_228;
    *(root + 0) = $env_227;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 15;
    garbage_collect($tinfo);
    $kp_228 = *(root + 1);
    $env_227 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $rpos_proj_229 = *((value *) $env_227 + 2);
  $prim_230 = ((value (*)(value)) bench_input_byte)($rpos_proj_229);
  $rpos_proj_231 = *((value *) $env_227 + 2);
  $prim_232 = ((value (*)(value)) bench_nat_succ)($rpos_proj_231);
  $prim_233 = ((value (*)(void)) bench_lit_8)();
  $prim_234 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_230, $prim_233);
  $prim_235 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_232, $prim_234);
  $qpos_proj_236 = *((value *) $env_227 + 1);
  $prim_237 = ((value (*)(value)) bench_nat_succ)($qpos_proj_236);
  $qpos_proj_238 = *((value *) $env_227 + 1);
  $prim_239 = ((value (*)(value)) bench_input_byte)($qpos_proj_238);
  $prim_240 = ((value (*)(void)) bench_lit_4)();
  $prim_241 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_239, $prim_240);
  $prim_242 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_237, $prim_241);
  $env_243 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_243 + -1) = 2048;
  *((value *) $env_243 + 0) = $prim_235;
  *((value *) $env_243 + 1) = $prim_242;
  $qpos_proj_244 = *((value *) $env_227 + 1);
  $prim_245 = ((value (*)(value)) bench_input_byte)($qpos_proj_244);
  $rpos_proj_246 = *((value *) $env_227 + 2);
  $prim_247 = ((value (*)(value)) bench_nat_succ)($rpos_proj_246);
  $qpos_proj_248 = *((value *) $env_227 + 1);
  $prim_249 = ((value (*)(value)) bench_nat_succ)($qpos_proj_248);
  $env_250 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_250 + -1) = 1024;
  *((value *) $env_250 + 0) = $prim_245;
  $env_251 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_251 + -1) = 3072;
  *((value *) $env_251 + 0) = $prim_249;
  *((value *) $env_251 + 1) = $prim_247;
  *((value *) $env_251 + 2) = $prim_245;
  $y_wrapper_clo_252 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_252 + -1) = 2048;
  *((value *) $y_wrapper_clo_252 + 0) = y_wrapper_143;
  *((value *) $y_wrapper_clo_252 + 1) = $env_250;
  $y_wrapper_clo_253 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_253 + -1) = 2048;
  *((value *) $y_wrapper_clo_253 + 0) = y_wrapper_146;
  *((value *) $y_wrapper_clo_253 + 1) = $env_251;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $env_243;
  *(root + 1) = $kp_228;
  *(root + 0) = $env_227;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $prim_254 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_230, $y_wrapper_clo_252, $y_wrapper_clo_253);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $env_243 = *(root + 2);
  $kp_228 = *(root + 1);
  $env_227 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $kp_228;
  *(root + 0) = $env_227;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $c_255 =
    ((value (*)(struct thread_info *, value, value)) f_case_134)
    ($tinfo, $env_243, $prim_254);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $kp_228 = *(root + 1);
  $env_227 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_256 = ((value (*)(void)) bench_nat_zero)();
  $prim_257 = ((value (*)(value, value)) bench_nat_eqb)($c_255, $prim_256);
  if (($prim_257 & 1) == 0) {
    switch (*((value *) $prim_257 + -1) & 255) {
      
    }
  } else {
    switch ($prim_257 >> 1) {
      case 0:
        $prim_258 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_258;
        break;
      default:
        $rpos_proj_259 = *((value *) $env_227 + 2);
        $prim_260 = ((value (*)(value)) bench_nat_succ)($rpos_proj_259);
        $rpos_proj_261 = *((value *) $env_227 + 2);
        $prim_262 = ((value (*)(value)) bench_input_byte)($rpos_proj_261);
        $prim_263 = ((value (*)(void)) bench_lit_8)();
        $prim_264 =
          ((value (*)(value, value)) bench_nat_mul)
          ($prim_262, $prim_263);
        $prim_265 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_260, $prim_264);
        $prim_266 = ((value (*)(void)) bench_lit_8)();
        $prim_267 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_265, $prim_266);
        $prim_268 = ((value (*)(value)) bench_nat_succ)($prim_267);
        $prim_269 = ((value (*)(value)) bench_input_byte)($prim_267);
        $prim_270 = ((value (*)(void)) bench_lit_20)();
        $prim_271 =
          ((value (*)(value, value)) bench_nat_mul)
          ($prim_269, $prim_270);
        $prim_272 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_268, $prim_271);
        $best_proj_274 = *((value *) $env_227 + 0);
        $prim_275 =
          ((value (*)(value, value)) bench_nat_leb)
          ($c_255, $best_proj_274);
        $best_proj_276 = *((value *) $env_227 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $prim_272;
        *(root + 1) = $kp_228;
        *(root + 0) = $env_227;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_277 =
          ((value (*)(struct thread_info *, value, value, value)) f_case_known_147)
          ($tinfo, $prim_275, $best_proj_276, $c_255);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 3) = $y_277;
          frame.next = root + 4;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $y_277 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $prim_272 = *(root + 2);
        $kp_228 = *(root + 1);
        $env_227 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $qpos_proj_278 = *((value *) $env_227 + 1);
        $env_279 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_279 + -1) = 1024;
        *((value *) $env_279 + 0) = $y_277;
        $env_280 = (value) ($alloc + 1);
        $alloc = $alloc + 4;
        *((value *) $env_280 + -1) = 3072;
        *((value *) $env_280 + 0) = $y_277;
        *((value *) $env_280 + 1) = $qpos_proj_278;
        *((value *) $env_280 + 2) = $prim_272;
        $y_wrapper_clo_281 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_281 + -1) = 2048;
        *((value *) $y_wrapper_clo_281 + 0) = y_wrapper_132;
        *((value *) $y_wrapper_clo_281 + 1) = $env_279;
        $y_clo_282 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_282 + -1) = 2048;
        *((value *) $y_clo_282 + 0) = y_133;
        *((value *) $y_clo_282 + 1) = $env_280;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_283 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_228, $y_wrapper_clo_281, $y_clo_282);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_283;
        break;
      
    }
  }
}

value y_wrapper_132(struct thread_info *$tinfo, value $env_224, value $anon_225)
{
  struct stack_frame frame;
  value root[1];
  register value $best_proj_226;
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
  $best_proj_226 = *((value *) $env_224 + 0);
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $best_proj_226;
}

value y_known_131(struct thread_info *$tinfo, value $kp_199, value $rules_200, value $n_201, value $qpos_202)
{
  struct stack_frame frame;
  value root[5];
  register value $prim_203;
  register value $env_204;
  register value $env_205;
  register value $y_wrapper_clo_206;
  register value $y_clo_207;
  register value $prim_208;
  register value $prim_209;
  register value $prim_210;
  register value $prim_211;
  register value $prim_212;
  register value $prim_213;
  register value $prim_214;
  register value $prim_215;
  register value $prim_216;
  register value $prim_217;
  register value $env_218;
  register value $env_219;
  register value $y_wrapper_clo_220;
  register value $y_wrapper_clo_221;
  register value $prim_222;
  register value $y_223;
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
    *(root + 3) = $qpos_202;
    *(root + 2) = $n_201;
    *(root + 1) = $rules_200;
    *(root + 0) = $kp_199;
    frame.next = root + 4;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 25;
    garbage_collect($tinfo);
    $qpos_202 = *(root + 3);
    $n_201 = *(root + 2);
    $rules_200 = *(root + 1);
    $kp_199 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_203 = ((value (*)(void)) bench_lit_3)();
  $env_204 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_204 + -1) = 1024;
  *((value *) $env_204 + 0) = $prim_203;
  $env_205 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_205 + -1) = 3072;
  *((value *) $env_205 + 0) = $prim_203;
  *((value *) $env_205 + 1) = $qpos_202;
  *((value *) $env_205 + 2) = $rules_200;
  $y_wrapper_clo_206 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_206 + -1) = 2048;
  *((value *) $y_wrapper_clo_206 + 0) = y_wrapper_132;
  *((value *) $y_wrapper_clo_206 + 1) = $env_204;
  $y_clo_207 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_clo_207 + -1) = 2048;
  *((value *) $y_clo_207 + 0) = y_133;
  *((value *) $y_clo_207 + 1) = $env_205;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 3) = $qpos_202;
  *(root + 2) = $n_201;
  *(root + 1) = $rules_200;
  *(root + 0) = $kp_199;
  frame.next = root + 4;
  (*$tinfo).fp = &frame;
  $prim_208 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_201, $y_wrapper_clo_206, $y_clo_207);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(13 <= $limit - $alloc)) {
    *(root + 4) = $prim_208;
    frame.next = root + 5;
    (*$tinfo).nalloc = 13;
    garbage_collect($tinfo);
    $prim_208 = *(root + 4);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $qpos_202 = *(root + 3);
  $n_201 = *(root + 2);
  $rules_200 = *(root + 1);
  $kp_199 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_209 = ((value (*)(value)) bench_nat_succ)($qpos_202);
  $prim_210 = ((value (*)(value)) bench_input_byte)($qpos_202);
  $prim_211 = ((value (*)(void)) bench_lit_4)();
  $prim_212 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_210, $prim_211);
  $prim_213 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_209, $prim_212);
  $prim_214 = ((value (*)(void)) bench_lit_8)();
  $prim_215 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_213, $prim_214);
  $prim_216 = ((value (*)(void)) bench_lit_20)();
  $prim_217 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_215, $prim_216);
  $env_218 = 1;
  $env_219 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_219 + -1) = 3072;
  *((value *) $env_219 + 0) = $rules_200;
  *((value *) $env_219 + 1) = $n_201;
  *((value *) $env_219 + 2) = $prim_217;
  $y_wrapper_clo_220 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_220 + -1) = 2048;
  *((value *) $y_wrapper_clo_220 + 0) = y_wrapper_130;
  *((value *) $y_wrapper_clo_220 + 1) = $env_218;
  $y_wrapper_clo_221 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_221 + -1) = 2048;
  *((value *) $y_wrapper_clo_221 + 0) = y_wrapper_148;
  *((value *) $y_wrapper_clo_221 + 1) = $env_219;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $prim_208;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_222 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $kp_199, $y_wrapper_clo_220, $y_wrapper_clo_221);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_222;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_222 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_208 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_223 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_223 + -1) = 2048;
  *((value *) $y_223 + 0) = $prim_208;
  *((value *) $y_223 + 1) = $prim_222;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_223;
}

value y_wrapper_130(struct thread_info *$tinfo, value $env_195, value $anon_196)
{
  struct stack_frame frame;
  value root[0];
  register value $y_197;
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
  $y_197 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_197;
}

value EncoreBenchdW3dPolicydrun_known_129(struct thread_info *$tinfo, value $n_176)
{
  struct stack_frame frame;
  value root[1];
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
  register value $prim_188;
  register value $prim_189;
  register value $env_190;
  register value $env_191;
  register value $y_wrapper_clo_192;
  register value $y_wrapper_clo_193;
  register value $prim_194;
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
    *(root + 0) = $n_176;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 10;
    garbage_collect($tinfo);
    $n_176 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_177 = ((value (*)(void)) bench_nat_zero)();
  $prim_178 = ((value (*)(value)) bench_input_byte)($prim_177);
  $prim_179 = ((value (*)(void)) bench_lit_3)();
  $prim_180 = ((value (*)(void)) bench_nat_zero)();
  $prim_181 = ((value (*)(value)) bench_nat_succ)($prim_180);
  $prim_182 = ((value (*)(value)) bench_input_byte)($prim_181);
  $prim_183 = ((value (*)(void)) bench_lit_256)();
  $prim_184 =
    ((value (*)(value, value)) bench_nat_mul)
    ($prim_182, $prim_183);
  $prim_185 = ((value (*)(void)) bench_nat_zero)();
  $prim_186 = ((value (*)(value)) bench_nat_succ)($prim_185);
  $prim_187 = ((value (*)(value)) bench_nat_succ)($prim_186);
  $prim_188 = ((value (*)(value)) bench_input_byte)($prim_187);
  $prim_189 =
    ((value (*)(value, value)) bench_nat_add)
    ($prim_184, $prim_188);
  $env_190 = 1;
  $env_191 = (value) ($alloc + 1);
  $alloc = $alloc + 4;
  *((value *) $env_191 + -1) = 3072;
  *((value *) $env_191 + 0) = $prim_189;
  *((value *) $env_191 + 1) = $n_176;
  *((value *) $env_191 + 2) = $prim_179;
  $y_wrapper_clo_192 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_192 + -1) = 2048;
  *((value *) $y_wrapper_clo_192 + 0) = y_wrapper_130;
  *((value *) $y_wrapper_clo_192 + 1) = $env_190;
  $y_wrapper_clo_193 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_193 + -1) = 2048;
  *((value *) $y_wrapper_clo_193 + 0) = y_wrapper_148;
  *((value *) $y_wrapper_clo_193 + 1) = $env_191;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_194 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_178, $y_wrapper_clo_192, $y_wrapper_clo_193);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_194;
}

value y_wrapper_128(struct thread_info *$tinfo, value $env_170, value $np_171)
{
  struct stack_frame frame;
  value root[2];
  register value $b_proj_173;
  register value $a_proj_174;
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
  $b_proj_173 = *((value *) $env_170 + 0);
  $a_proj_174 = *((value *) $env_170 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_127)
    ($tinfo, $np_171, $b_proj_173, $a_proj_174);
  return $result;
}

value y_known_127(struct thread_info *$tinfo, value $np_154, value $b_155, value $a_156)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_157;
  register value $prim_158;
  register value $prim_159;
  register value $y_160;
  register value $prim_161;
  register value $prim_162;
  register value $prim_163;
  register value $env_164;
  register value $env_165;
  register value $y_wrapper_clo_166;
  register value $y_wrapper_clo_167;
  register value $prim_168;
  register value $y_169;
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
    *(root + 2) = $a_156;
    *(root + 1) = $b_155;
    *(root + 0) = $np_154;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $a_156 = *(root + 2);
    $b_155 = *(root + 1);
    $np_154 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_157 = ((value (*)(value)) bench_input_byte)($a_156);
  $prim_158 = ((value (*)(value)) bench_input_byte)($b_155);
  $prim_159 =
    ((value (*)(value, value)) bench_nat_ltb)
    ($prim_157, $prim_158);
  if (($prim_159 & 1) == 0) {
    switch (*((value *) $prim_159 + -1) & 255) {
      
    }
  } else {
    switch ($prim_159 >> 1) {
      case 0:
        $y_160 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_160;
        break;
      default:
        $prim_161 =
          ((value (*)(value, value)) bench_nat_eqb)
          ($prim_157, $prim_158);
        if (($prim_161 & 1) == 0) {
          switch (*((value *) $prim_161 + -1) & 255) {
            
          }
        } else {
          switch ($prim_161 >> 1) {
            case 0:
              $prim_162 = ((value (*)(value)) bench_nat_succ)($a_156);
              $prim_163 = ((value (*)(value)) bench_nat_succ)($b_155);
              $env_164 = 1;
              $env_165 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $env_165 + -1) = 2048;
              *((value *) $env_165 + 0) = $prim_163;
              *((value *) $env_165 + 1) = $prim_162;
              $y_wrapper_clo_166 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_166 + -1) = 2048;
              *((value *) $y_wrapper_clo_166 + 0) = y_wrapper_126;
              *((value *) $y_wrapper_clo_166 + 1) = $env_164;
              $y_wrapper_clo_167 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_167 + -1) = 2048;
              *((value *) $y_wrapper_clo_167 + 0) = y_wrapper_128;
              *((value *) $y_wrapper_clo_167 + 1) = $env_165;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              /*skip*/;
              $prim_168 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $np_154, $y_wrapper_clo_166, $y_wrapper_clo_167);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              /*skip*/;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $prim_168;
              break;
            default:
              $y_169 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_169;
              break;
            
          }
        }
        break;
      
    }
  }
}

value y_wrapper_126(struct thread_info *$tinfo, value $env_150, value $anon_151)
{
  struct stack_frame frame;
  value root[0];
  register value $y_152;
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
  $y_152 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_152;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
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
  register value $prim_746;
  register value $prim_747;
  register value $env_748;
  register value $EncoreBenchdW3dPolicydrun_wrapper_clo_749;
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
  $prim_434 = ((value (*)(void)) bench_nat_zero)();
  $prim_435 = ((value (*)(value)) bench_nat_succ)($prim_434);
  $prim_436 = ((value (*)(value)) bench_nat_succ)($prim_435);
  $prim_437 = ((value (*)(value)) bench_nat_succ)($prim_436);
  $prim_438 = ((value (*)(value)) bench_nat_succ)($prim_437);
  $prim_439 = ((value (*)(value)) bench_nat_succ)($prim_438);
  $prim_440 = ((value (*)(value)) bench_nat_succ)($prim_439);
  $prim_441 = ((value (*)(value)) bench_nat_succ)($prim_440);
  $prim_442 = ((value (*)(value)) bench_nat_succ)($prim_441);
  $prim_443 = ((value (*)(void)) bench_nat_zero)();
  $prim_444 = ((value (*)(value)) bench_nat_succ)($prim_443);
  $prim_445 = ((value (*)(value)) bench_nat_succ)($prim_444);
  $prim_446 = ((value (*)(value)) bench_nat_succ)($prim_445);
  $prim_447 = ((value (*)(value)) bench_nat_succ)($prim_446);
  $prim_448 = ((value (*)(void)) bench_nat_zero)();
  $prim_449 = ((value (*)(value)) bench_nat_succ)($prim_448);
  $prim_450 = ((value (*)(value)) bench_nat_succ)($prim_449);
  $prim_451 = ((value (*)(value)) bench_nat_succ)($prim_450);
  $prim_452 = ((value (*)(value)) bench_nat_succ)($prim_451);
  $prim_453 = ((value (*)(value)) bench_nat_succ)($prim_452);
  $prim_454 = ((value (*)(value)) bench_nat_succ)($prim_453);
  $prim_455 = ((value (*)(value)) bench_nat_succ)($prim_454);
  $prim_456 = ((value (*)(value)) bench_nat_succ)($prim_455);
  $prim_457 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_476 = ((value (*)(value)) bench_nat_succ)($prim_475);
  $prim_477 = ((value (*)(value)) bench_nat_succ)($prim_476);
  $prim_478 = ((value (*)(void)) bench_nat_zero)();
  $prim_479 = ((value (*)(value)) bench_nat_succ)($prim_478);
  $prim_480 = ((value (*)(void)) bench_nat_zero)();
  $prim_481 = ((value (*)(value)) bench_nat_succ)($prim_480);
  $prim_482 = ((value (*)(value)) bench_nat_succ)($prim_481);
  $prim_483 = ((value (*)(void)) bench_nat_zero)();
  $prim_484 = ((value (*)(value)) bench_nat_succ)($prim_483);
  $prim_485 = ((value (*)(value)) bench_nat_succ)($prim_484);
  $prim_486 = ((value (*)(value)) bench_nat_succ)($prim_485);
  $prim_487 = ((value (*)(void)) bench_nat_zero)();
  $prim_488 = ((value (*)(value)) bench_nat_succ)($prim_487);
  $prim_489 = ((value (*)(value)) bench_nat_succ)($prim_488);
  $prim_490 = ((value (*)(value)) bench_nat_succ)($prim_489);
  $prim_491 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_746 = ((value (*)(value)) bench_nat_succ)($prim_745);
  $prim_747 = ((value (*)(value)) bench_nat_succ)($prim_746);
  $env_748 = 1;
  $EncoreBenchdW3dPolicydrun_wrapper_clo_749 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_749 + -1) = 2048;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_749 + 0) =
    EncoreBenchdW3dPolicydrun_wrapper_149;
  *((value *) $EncoreBenchdW3dPolicydrun_wrapper_clo_749 + 1) = $env_748;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW3dPolicydrun_wrapper_clo_749;
}


#endif /* W3_POLICY_C */
