#ifndef W4_PIN_C
#define W4_PIN_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "bench_rt.h"
#include "w4_pin.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW4dPindrun_wrapper_142(struct thread_info *, value, value);
extern value f_case_known_141(struct thread_info *, value);
extern value y_140(struct thread_info *, value, value);
extern value y_wrapper_139(struct thread_info *, value, value);
extern value f_case_known_138(struct thread_info *, value);
extern value y_137(struct thread_info *, value, value);
extern value y_136(struct thread_info *, value, value);
extern value f_case_135(struct thread_info *, value, value);
extern value y_wrapper_134(struct thread_info *, value, value);
extern value y_known_133(struct thread_info *, value, value);
extern value y_wrapper_132(struct thread_info *, value, value);
extern value y_wrapper_131(struct thread_info *, value, value);
extern value y_known_130(struct thread_info *, value, value);
extern value y_wrapper_129(struct thread_info *, value, value);
extern value f_case_known_128(struct thread_info *, value, value, value);
extern value y_wrapper_127(struct thread_info *, value, value);
extern value y_wrapper_126(struct thread_info *, value, value);
extern value y_125(struct thread_info *, value, value);
extern value y_wrapper_124(struct thread_info *, value, value);
extern value digits_eqb_uncurried_known_123(struct thread_info *, value, value);
extern value EncoreBenchdW4dPindpuk_tries_known_122(struct thread_info *, value);
extern value EncoreBenchdW4dPindpuk_known_121(struct thread_info *, value);
extern value EncoreBenchdW4dPindpin_known_120(struct thread_info *, value);
extern value EncoreBenchdW4dPindtries_known_119(struct thread_info *, value);
extern value body(struct thread_info *);
value EncoreBenchdW4dPindrun_wrapper_142(struct thread_info *, value, value);
value f_case_known_141(struct thread_info *, value);
value y_140(struct thread_info *, value, value);
value y_wrapper_139(struct thread_info *, value, value);
value f_case_known_138(struct thread_info *, value);
value y_137(struct thread_info *, value, value);
value y_136(struct thread_info *, value, value);
value f_case_135(struct thread_info *, value, value);
value y_wrapper_134(struct thread_info *, value, value);
value y_known_133(struct thread_info *, value, value);
value y_wrapper_132(struct thread_info *, value, value);
value y_wrapper_131(struct thread_info *, value, value);
value y_known_130(struct thread_info *, value, value);
value y_wrapper_129(struct thread_info *, value, value);
value f_case_known_128(struct thread_info *, value, value, value);
value y_wrapper_127(struct thread_info *, value, value);
value y_wrapper_126(struct thread_info *, value, value);
value y_125(struct thread_info *, value, value);
value y_wrapper_124(struct thread_info *, value, value);
value digits_eqb_uncurried_known_123(struct thread_info *, value, value);
value EncoreBenchdW4dPindpuk_tries_known_122(struct thread_info *, value);
value EncoreBenchdW4dPindpuk_known_121(struct thread_info *, value);
value EncoreBenchdW4dPindpin_known_120(struct thread_info *, value);
value EncoreBenchdW4dPindtries_known_119(struct thread_info *, value);
value body(struct thread_info *);
unsigned int const body_info_871[2] = { 47, 0, };

unsigned int const EncoreBenchdW4dPindtries_known_info_870[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW4dPindpin_known_info_869[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW4dPindpuk_known_info_868[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW4dPindpuk_tries_known_info_867[3] = { 0, 1,
  0, };

unsigned int const digits_eqb_uncurried_known_info_866[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_865[4] = { 0, 2, 0, 1, };

unsigned int const y_info_864[4] = { 8, 2, 0, 1, };

unsigned int const y_wrapper_info_863[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_862[4] = { 11, 2, 0, 1, };

unsigned int const f_case_known_info_861[5] = { 21, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_860[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_859[4] = { 11, 2, 0, 1, };

unsigned int const y_wrapper_info_858[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_857[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_856[4] = { 10, 2, 0, 1, };

unsigned int const y_wrapper_info_855[4] = { 0, 2, 0, 1, };

unsigned int const f_case_info_854[4] = { 3, 2, 0, 1, };

unsigned int const y_info_853[4] = { 0, 2, 0, 1, };

unsigned int const y_info_852[4] = { 0, 2, 0, 1, };

unsigned int const f_case_known_info_851[3] = { 0, 1, 0, };

unsigned int const y_wrapper_info_850[4] = { 3, 2, 0, 1, };

unsigned int const y_info_849[4] = { 0, 2, 0, 1, };

unsigned int const f_case_known_info_848[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW4dPindrun_wrapper_info_847[4] = { 9, 2, 0, 1,
  };

value EncoreBenchdW4dPindrun_wrapper_142(struct thread_info *$tinfo, value $env_456, value $n_457)
{
  struct stack_frame frame;
  value root[2];
  register value $EncoreBenchdW4dPindinit_proj_458;
  register value $prim_459;
  register value $env_460;
  register value $env_461;
  register value $y_wrapper_clo_462;
  register value $y_clo_463;
  register value $prim_464;
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
    *(root + 1) = $n_457;
    *(root + 0) = $env_456;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $n_457 = *(root + 1);
    $env_456 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $EncoreBenchdW4dPindinit_proj_458 = *((value *) $env_456 + 0);
  $prim_459 = ((value (*)(void)) bench_nat_zero)();
  $env_460 = 1;
  $env_461 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_461 + -1) = 2048;
  *((value *) $env_461 + 0) = $prim_459;
  *((value *) $env_461 + 1) = $EncoreBenchdW4dPindinit_proj_458;
  $y_wrapper_clo_462 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_462 + -1) = 2048;
  *((value *) $y_wrapper_clo_462 + 0) = y_wrapper_124;
  *((value *) $y_wrapper_clo_462 + 1) = $env_460;
  $y_clo_463 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_clo_463 + -1) = 2048;
  *((value *) $y_clo_463 + 0) = y_125;
  *((value *) $y_clo_463 + 1) = $env_461;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_464 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_457, $y_wrapper_clo_462, $y_clo_463);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_464;
}

value f_case_known_141(struct thread_info *$tinfo, value $s_438)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_439;
  register value $n_440;
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
  if (($s_438 & 1) == 0) {
    switch (*((value *) $s_438 + -1) & 255) {
      default:
        $n_440 = *((value *) $s_438 + 0);
        $prim_441 = ((value (*)(void)) bench_nat_zero)();
        $prim_442 = ((value (*)(value)) bench_nat_succ)($prim_441);
        $prim_443 = ((value (*)(value)) bench_nat_succ)($prim_442);
        $prim_444 = ((value (*)(value)) bench_nat_succ)($prim_443);
        $prim_445 = ((value (*)(value)) bench_nat_succ)($prim_444);
        $prim_446 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_445, $n_440);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_446;
        break;
      
    }
  } else {
    switch ($s_438 >> 1) {
      case 0:
        $prim_439 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_439;
        break;
      case 1:
        $prim_447 = ((value (*)(void)) bench_nat_zero)();
        $prim_448 = ((value (*)(value)) bench_nat_succ)($prim_447);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_448;
        break;
      case 2:
        $prim_449 = ((value (*)(void)) bench_nat_zero)();
        $prim_450 = ((value (*)(value)) bench_nat_succ)($prim_449);
        $prim_451 = ((value (*)(value)) bench_nat_succ)($prim_450);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_451;
        break;
      default:
        $prim_452 = ((value (*)(void)) bench_nat_zero)();
        $prim_453 = ((value (*)(value)) bench_nat_succ)($prim_452);
        $prim_454 = ((value (*)(value)) bench_nat_succ)($prim_453);
        $prim_455 = ((value (*)(value)) bench_nat_succ)($prim_454);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_455;
        break;
      
    }
  }
}

value y_140(struct thread_info *$tinfo, value $env_406, value $t_407)
{
  struct stack_frame frame;
  value root[4];
  register value $k_proj_408;
  register value $s_proj_410;
  register value $y_411;
  register value $y_413;
  register value $s_proj_415;
  register value $y_416;
  register value $prim_417;
  register value $prim_418;
  register value $y_419;
  register value $p_proj_420;
  register value $y_421;
  register value $y_422;
  register value $y_423;
  register value $s_proj_425;
  register value $y_426;
  register value $s_proj_428;
  register value $y_429;
  register value $s_proj_431;
  register value $y_432;
  register value $y_433;
  register value $y_434;
  register value $y_435;
  register value $y_436;
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
  $k_proj_408 = *((value *) $env_406 + 1);
  $s_proj_410 = *((value *) $env_406 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $k_proj_408;
  *(root + 1) = $t_407;
  *(root + 0) = $env_406;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $y_411 =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
    ($tinfo, $s_proj_410);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $k_proj_408 = *(root + 2);
  $t_407 = *(root + 1);
  $env_406 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $t_407;
  *(root + 0) = $env_406;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $y_413 =
    ((value (*)(struct thread_info *, value, value)) digits_eqb_uncurried_known_123)
    ($tinfo, $y_411, $k_proj_408);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $t_407 = *(root + 1);
  $env_406 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_413 & 1) == 0) {
    switch (*((value *) $y_413 + -1) & 255) {
      
    }
  } else {
    switch ($y_413 >> 1) {
      case 0:
        $s_proj_415 = *((value *) $env_406 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_406;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_416 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
          ($tinfo, $s_proj_415);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 1) = $y_416;
          frame.next = root + 2;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $y_416 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $env_406 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_417 = ((value (*)(void)) bench_lit_3)();
        $prim_418 = ((value (*)(void)) bench_lit_10)();
        $y_419 = 3;
        $p_proj_420 = *((value *) $env_406 + 2);
        $y_421 = (value) ($alloc + 1);
        $alloc = $alloc + 6;
        *((value *) $y_421 + -1) = 5120;
        *((value *) $y_421 + 0) = $p_proj_420;
        *((value *) $y_421 + 1) = $y_416;
        *((value *) $y_421 + 2) = $prim_417;
        *((value *) $y_421 + 3) = $prim_418;
        *((value *) $y_421 + 4) = $y_419;
        $y_422 = 1;
        $y_423 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_423 + -1) = 2048;
        *((value *) $y_423 + 0) = $y_421;
        *((value *) $y_423 + 1) = $y_422;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_423;
        break;
      default:
        $s_proj_425 = *((value *) $env_406 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $t_407;
        *(root + 0) = $env_406;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_426 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
          ($tinfo, $s_proj_425);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $t_407 = *(root + 1);
        $env_406 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_428 = *((value *) $env_406 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_426;
        *(root + 1) = $t_407;
        *(root + 0) = $env_406;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_429 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
          ($tinfo, $s_proj_428);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $y_426 = *(root + 2);
        $t_407 = *(root + 1);
        $env_406 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_431 = *((value *) $env_406 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_429;
        *(root + 1) = $y_426;
        *(root + 0) = $t_407;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_432 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindtries_known_119)
          ($tinfo, $s_proj_431);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(11 <= $limit - $alloc)) {
          *(root + 3) = $y_432;
          frame.next = root + 4;
          (*$tinfo).nalloc = 11;
          garbage_collect($tinfo);
          $y_432 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $y_429 = *(root + 2);
        $y_426 = *(root + 1);
        $t_407 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_433 = 3;
        $y_434 = (value) ($alloc + 1);
        $alloc = $alloc + 6;
        *((value *) $y_434 + -1) = 5120;
        *((value *) $y_434 + 0) = $y_426;
        *((value *) $y_434 + 1) = $y_429;
        *((value *) $y_434 + 2) = $y_432;
        *((value *) $y_434 + 3) = $t_407;
        *((value *) $y_434 + 4) = $y_433;
        $y_435 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $y_435 + -1) = 1024;
        *((value *) $y_435 + 0) = $t_407;
        $y_436 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_436 + -1) = 2048;
        *((value *) $y_436 + 0) = $y_434;
        *((value *) $y_436 + 1) = $y_435;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_436;
        break;
      
    }
  }
}

value y_wrapper_139(struct thread_info *$tinfo, value $env_401, value $anon_402)
{
  struct stack_frame frame;
  value root[1];
  register value $s_proj_403;
  register value $y_404;
  register value $y_405;
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
  if (!(3 <= $limit - $alloc)) {
    *(root + 0) = $env_401;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $env_401 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $s_proj_403 = *((value *) $env_401 + 0);
  $y_404 = 3;
  $y_405 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_405 + -1) = 2048;
  *((value *) $y_405 + 0) = $s_proj_403;
  *((value *) $y_405 + 1) = $y_404;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_405;
}

value f_case_known_138(struct thread_info *$tinfo, value $s_399)
{
  struct stack_frame frame;
  value root[1];
  register value $auth_400;
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
  if (($s_399 & 1) == 0) {
    switch (*((value *) $s_399 + -1) & 255) {
      default:
        $auth_400 = *((value *) $s_399 + 4);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $auth_400;
        break;
      
    }
  } else {
    switch ($s_399 >> 1) {
      
    }
  }
}

value y_137(struct thread_info *$tinfo, value $env_363, value $t_364)
{
  struct stack_frame frame;
  value root[4];
  register value $g_proj_365;
  register value $s_proj_367;
  register value $y_368;
  register value $y_370;
  register value $s_proj_372;
  register value $y_373;
  register value $s_proj_375;
  register value $y_376;
  register value $prim_377;
  register value $s_proj_379;
  register value $y_380;
  register value $y_381;
  register value $y_382;
  register value $y_383;
  register value $y_384;
  register value $s_proj_386;
  register value $y_387;
  register value $s_proj_389;
  register value $y_390;
  register value $s_proj_392;
  register value $y_393;
  register value $y_394;
  register value $y_395;
  register value $y_396;
  register value $y_397;
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
  $g_proj_365 = *((value *) $env_363 + 1);
  $s_proj_367 = *((value *) $env_363 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $g_proj_365;
  *(root + 1) = $t_364;
  *(root + 0) = $env_363;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $y_368 =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
    ($tinfo, $s_proj_367);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $g_proj_365 = *(root + 2);
  $t_364 = *(root + 1);
  $env_363 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $t_364;
  *(root + 0) = $env_363;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $y_370 =
    ((value (*)(struct thread_info *, value, value)) digits_eqb_uncurried_known_123)
    ($tinfo, $y_368, $g_proj_365);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $t_364 = *(root + 1);
  $env_363 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_370 & 1) == 0) {
    switch (*((value *) $y_370 + -1) & 255) {
      
    }
  } else {
    switch ($y_370 >> 1) {
      case 0:
        $s_proj_372 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_363;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_373 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
          ($tinfo, $s_proj_372);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $env_363 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_375 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $y_373;
        *(root + 0) = $env_363;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_376 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
          ($tinfo, $s_proj_375);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $y_373 = *(root + 1);
        $env_363 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_377 = ((value (*)(void)) bench_lit_3)();
        $s_proj_379 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $prim_377;
        *(root + 1) = $y_376;
        *(root + 0) = $y_373;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_380 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
          ($tinfo, $s_proj_379);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 3) = $y_380;
          frame.next = root + 4;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $y_380 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $prim_377 = *(root + 2);
        $y_376 = *(root + 1);
        $y_373 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_381 = 1;
        $y_382 = (value) ($alloc + 1);
        $alloc = $alloc + 6;
        *((value *) $y_382 + -1) = 5120;
        *((value *) $y_382 + 0) = $y_373;
        *((value *) $y_382 + 1) = $y_376;
        *((value *) $y_382 + 2) = $prim_377;
        *((value *) $y_382 + 3) = $y_380;
        *((value *) $y_382 + 4) = $y_381;
        $y_383 = 1;
        $y_384 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_384 + -1) = 2048;
        *((value *) $y_384 + 0) = $y_382;
        *((value *) $y_384 + 1) = $y_383;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_384;
        break;
      default:
        $s_proj_386 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $t_364;
        *(root + 0) = $env_363;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_387 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
          ($tinfo, $s_proj_386);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $t_364 = *(root + 1);
        $env_363 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_389 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_387;
        *(root + 1) = $t_364;
        *(root + 0) = $env_363;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_390 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
          ($tinfo, $s_proj_389);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $y_387 = *(root + 2);
        $t_364 = *(root + 1);
        $env_363 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_392 = *((value *) $env_363 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_390;
        *(root + 1) = $y_387;
        *(root + 0) = $t_364;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_393 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
          ($tinfo, $s_proj_392);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(11 <= $limit - $alloc)) {
          *(root + 3) = $y_393;
          frame.next = root + 4;
          (*$tinfo).nalloc = 11;
          garbage_collect($tinfo);
          $y_393 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $y_390 = *(root + 2);
        $y_387 = *(root + 1);
        $t_364 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_394 = 3;
        $y_395 = (value) ($alloc + 1);
        $alloc = $alloc + 6;
        *((value *) $y_395 + -1) = 5120;
        *((value *) $y_395 + 0) = $y_387;
        *((value *) $y_395 + 1) = $y_390;
        *((value *) $y_395 + 2) = $t_364;
        *((value *) $y_395 + 3) = $y_393;
        *((value *) $y_395 + 4) = $y_394;
        $y_396 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $y_396 + -1) = 1024;
        *((value *) $y_396 + 0) = $t_364;
        $y_397 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_397 + -1) = 2048;
        *((value *) $y_397 + 0) = $y_395;
        *((value *) $y_397 + 1) = $y_396;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_397;
        break;
      
    }
  }
}

value y_136(struct thread_info *$tinfo, value $env_347, value $anon_348)
{
  struct stack_frame frame;
  value root[4];
  register value $s_proj_350;
  register value $y_351;
  register value $s_proj_353;
  register value $y_354;
  register value $prim_355;
  register value $s_proj_357;
  register value $y_358;
  register value $y_359;
  register value $y_360;
  register value $y_361;
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
  $s_proj_350 = *((value *) $env_347 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $env_347;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $y_351 =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
    ($tinfo, $s_proj_350);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $env_347 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $s_proj_353 = *((value *) $env_347 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $y_351;
  *(root + 0) = $env_347;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $y_354 =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
    ($tinfo, $s_proj_353);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $y_351 = *(root + 1);
  $env_347 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_355 = ((value (*)(void)) bench_nat_zero)();
  $s_proj_357 = *((value *) $env_347 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $prim_355;
  *(root + 1) = $y_354;
  *(root + 0) = $y_351;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $y_358 =
    ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
    ($tinfo, $s_proj_357);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(9 <= $limit - $alloc)) {
    *(root + 3) = $y_358;
    frame.next = root + 4;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $y_358 = *(root + 3);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_355 = *(root + 2);
  $y_354 = *(root + 1);
  $y_351 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_359 = 3;
  $y_360 = (value) ($alloc + 1);
  $alloc = $alloc + 6;
  *((value *) $y_360 + -1) = 5120;
  *((value *) $y_360 + 0) = $y_351;
  *((value *) $y_360 + 1) = $y_354;
  *((value *) $y_360 + 2) = $prim_355;
  *((value *) $y_360 + 3) = $y_358;
  *((value *) $y_360 + 4) = $y_359;
  $y_361 = 3;
  $y_362 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_362 + -1) = 2048;
  *((value *) $y_362 + 0) = $y_360;
  *((value *) $y_362 + 1) = $y_361;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_362;
}

value f_case_135(struct thread_info *$tinfo, value $env_283, value $s_284)
{
  struct stack_frame frame;
  value root[4];
  register value $g_285;
  register value $s_proj_287;
  register value $y_288;
  register value $s_proj_289;
  register value $env_290;
  register value $s_proj_291;
  register value $env_292;
  register value $y_clo_293;
  register value $y_clo_294;
  register value $prim_295;
  register value $p_296;
  register value $s_proj_298;
  register value $y_299;
  register value $s_proj_301;
  register value $y_302;
  register value $s_proj_304;
  register value $y_305;
  register value $s_proj_307;
  register value $y_308;
  register value $y_309;
  register value $y_310;
  register value $y_311;
  register value $y_312;
  register value $y_313;
  register value $s_proj_314;
  register value $y_315;
  register value $k_316;
  register value $p_317;
  register value $s_proj_319;
  register value $y_320;
  register value $s_proj_321;
  register value $env_322;
  register value $s_proj_323;
  register value $env_324;
  register value $y_wrapper_clo_325;
  register value $y_clo_326;
  register value $prim_327;
  register value $s_proj_329;
  register value $y_330;
  register value $s_proj_332;
  register value $y_333;
  register value $s_proj_335;
  register value $y_336;
  register value $s_proj_338;
  register value $y_339;
  register value $y_340;
  register value $y_341;
  register value $y_342;
  register value $y_343;
  register value $y_344;
  register value $s_proj_345;
  register value $y_346;
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
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $s_284;
    *(root + 0) = $env_283;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $s_284 = *(root + 1);
    $env_283 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_284 & 1) == 0) {
    switch (*((value *) $s_284 + -1) & 255) {
      case 0:
        $g_285 = *((value *) $s_284 + 0);
        $s_proj_287 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $g_285;
        *(root + 0) = $env_283;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_288 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindtries_known_119)
          ($tinfo, $s_proj_287);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(11 <= $limit - $alloc)) {
          *(root + 2) = $y_288;
          frame.next = root + 3;
          (*$tinfo).nalloc = 11;
          garbage_collect($tinfo);
          $y_288 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $g_285 = *(root + 1);
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_289 = *((value *) $env_283 + 0);
        $env_290 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_290 + -1) = 1024;
        *((value *) $env_290 + 0) = $s_proj_289;
        $s_proj_291 = *((value *) $env_283 + 0);
        $env_292 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_292 + -1) = 2048;
        *((value *) $env_292 + 0) = $s_proj_291;
        *((value *) $env_292 + 1) = $g_285;
        $y_clo_293 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_293 + -1) = 2048;
        *((value *) $y_clo_293 + 0) = y_136;
        *((value *) $y_clo_293 + 1) = $env_290;
        $y_clo_294 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_294 + -1) = 2048;
        *((value *) $y_clo_294 + 0) = y_137;
        *((value *) $y_clo_294 + 1) = $env_292;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_295 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $y_288, $y_clo_293, $y_clo_294);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_295;
        break;
      case 1:
        $p_296 = *((value *) $s_284 + 0);
        $s_proj_298 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $p_296;
        *(root + 0) = $env_283;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_299 =
          ((value (*)(struct thread_info *, value)) f_case_known_138)
          ($tinfo, $s_proj_298);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 2) = $y_299;
          frame.next = root + 3;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $y_299 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $p_296 = *(root + 1);
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($y_299 & 1) == 0) {
          switch (*((value *) $y_299 + -1) & 255) {
            
          }
        } else {
          switch ($y_299 >> 1) {
            case 0:
              $s_proj_301 = *((value *) $env_283 + 0);
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 1) = $p_296;
              *(root + 0) = $env_283;
              frame.next = root + 2;
              (*$tinfo).fp = &frame;
              $y_302 =
                ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
                ($tinfo, $s_proj_301);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              $p_296 = *(root + 1);
              $env_283 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $s_proj_304 = *((value *) $env_283 + 0);
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 2) = $y_302;
              *(root + 1) = $p_296;
              *(root + 0) = $env_283;
              frame.next = root + 3;
              (*$tinfo).fp = &frame;
              $y_305 =
                ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindtries_known_119)
                ($tinfo, $s_proj_304);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              $y_302 = *(root + 2);
              $p_296 = *(root + 1);
              $env_283 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $s_proj_307 = *((value *) $env_283 + 0);
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 2) = $y_305;
              *(root + 1) = $y_302;
              *(root + 0) = $p_296;
              frame.next = root + 3;
              (*$tinfo).fp = &frame;
              $y_308 =
                ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
                ($tinfo, $s_proj_307);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              if (!(9 <= $limit - $alloc)) {
                *(root + 3) = $y_308;
                frame.next = root + 4;
                (*$tinfo).nalloc = 9;
                garbage_collect($tinfo);
                $y_308 = *(root + 3);
                $alloc = (*$tinfo).alloc;
                $limit = (*$tinfo).limit;
              }
              $y_305 = *(root + 2);
              $y_302 = *(root + 1);
              $p_296 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $y_309 = 1;
              $y_310 = (value) ($alloc + 1);
              $alloc = $alloc + 6;
              *((value *) $y_310 + -1) = 5120;
              *((value *) $y_310 + 0) = $p_296;
              *((value *) $y_310 + 1) = $y_302;
              *((value *) $y_310 + 2) = $y_305;
              *((value *) $y_310 + 3) = $y_308;
              *((value *) $y_310 + 4) = $y_309;
              $y_311 = 1;
              $y_312 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_312 + -1) = 2048;
              *((value *) $y_312 + 0) = $y_310;
              *((value *) $y_312 + 1) = $y_311;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_312;
              break;
            default:
              $y_313 = 5;
              $s_proj_314 = *((value *) $env_283 + 0);
              $y_315 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_315 + -1) = 2048;
              *((value *) $y_315 + 0) = $s_proj_314;
              *((value *) $y_315 + 1) = $y_313;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_315;
              break;
            
          }
        }
        break;
      default:
        $k_316 = *((value *) $s_284 + 0);
        $p_317 = *((value *) $s_284 + 1);
        $s_proj_319 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $p_317;
        *(root + 1) = $k_316;
        *(root + 0) = $env_283;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_320 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
          ($tinfo, $s_proj_319);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 3) = $y_320;
          frame.next = root + 4;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $y_320 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $p_317 = *(root + 2);
        $k_316 = *(root + 1);
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_321 = *((value *) $env_283 + 0);
        $env_322 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_322 + -1) = 1024;
        *((value *) $env_322 + 0) = $s_proj_321;
        $s_proj_323 = *((value *) $env_283 + 0);
        $env_324 = (value) ($alloc + 1);
        $alloc = $alloc + 4;
        *((value *) $env_324 + -1) = 3072;
        *((value *) $env_324 + 0) = $s_proj_323;
        *((value *) $env_324 + 1) = $k_316;
        *((value *) $env_324 + 2) = $p_317;
        $y_wrapper_clo_325 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_325 + -1) = 2048;
        *((value *) $y_wrapper_clo_325 + 0) = y_wrapper_139;
        *((value *) $y_wrapper_clo_325 + 1) = $env_322;
        $y_clo_326 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_326 + -1) = 2048;
        *((value *) $y_clo_326 + 0) = y_140;
        *((value *) $y_clo_326 + 1) = $env_324;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_327 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $y_320, $y_wrapper_clo_325, $y_clo_326);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_327;
        break;
      
    }
  } else {
    switch ($s_284 >> 1) {
      case 0:
        $s_proj_329 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_283;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_330 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpin_known_120)
          ($tinfo, $s_proj_329);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_332 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $y_330;
        *(root + 0) = $env_283;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_333 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_known_121)
          ($tinfo, $s_proj_332);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $y_330 = *(root + 1);
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_335 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_333;
        *(root + 1) = $y_330;
        *(root + 0) = $env_283;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_336 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindtries_known_119)
          ($tinfo, $s_proj_335);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $y_333 = *(root + 2);
        $y_330 = *(root + 1);
        $env_283 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $s_proj_338 = *((value *) $env_283 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_336;
        *(root + 1) = $y_333;
        *(root + 0) = $y_330;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_339 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW4dPindpuk_tries_known_122)
          ($tinfo, $s_proj_338);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 3) = $y_339;
          frame.next = root + 4;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $y_339 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $y_336 = *(root + 2);
        $y_333 = *(root + 1);
        $y_330 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_340 = 3;
        $y_341 = (value) ($alloc + 1);
        $alloc = $alloc + 6;
        *((value *) $y_341 + -1) = 5120;
        *((value *) $y_341 + 0) = $y_330;
        *((value *) $y_341 + 1) = $y_333;
        *((value *) $y_341 + 2) = $y_336;
        *((value *) $y_341 + 3) = $y_339;
        *((value *) $y_341 + 4) = $y_340;
        $y_342 = 1;
        $y_343 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_343 + -1) = 2048;
        *((value *) $y_343 + 0) = $y_341;
        *((value *) $y_343 + 1) = $y_342;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_343;
        break;
      default:
        $y_344 = 7;
        $s_proj_345 = *((value *) $env_283 + 0);
        $y_346 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_346 + -1) = 2048;
        *((value *) $y_346 + 0) = $s_proj_345;
        *((value *) $y_346 + 1) = $y_344;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_346;
        break;
      
    }
  }
}

value y_wrapper_134(struct thread_info *$tinfo, value $env_279, value $n_280)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_282;
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
  $l_proj_282 = *((value *) $env_279 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_133)
    ($tinfo, $n_280, $l_proj_282);
  return $result;
}

value y_known_133(struct thread_info *$tinfo, value $n_270, value $l_271)
{
  struct stack_frame frame;
  value root[2];
  register value $y_272;
  register value $l_273;
  register value $env_274;
  register value $env_275;
  register value $y_wrapper_clo_276;
  register value $y_wrapper_clo_277;
  register value $prim_278;
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
    *(root + 1) = $l_271;
    *(root + 0) = $n_270;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 10;
    garbage_collect($tinfo);
    $l_271 = *(root + 1);
    $n_270 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_271 & 1) == 0) {
    switch (*((value *) $l_271 + -1) & 255) {
      default:
        $l_273 = *((value *) $l_271 + 1);
        $env_274 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_274 + -1) = 1024;
        *((value *) $env_274 + 0) = $l_273;
        $env_275 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_275 + -1) = 1024;
        *((value *) $env_275 + 0) = $l_273;
        $y_wrapper_clo_276 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_276 + -1) = 2048;
        *((value *) $y_wrapper_clo_276 + 0) = y_wrapper_132;
        *((value *) $y_wrapper_clo_276 + 1) = $env_274;
        $y_wrapper_clo_277 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_277 + -1) = 2048;
        *((value *) $y_wrapper_clo_277 + 0) = y_wrapper_134;
        *((value *) $y_wrapper_clo_277 + 1) = $env_275;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_278 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $n_270, $y_wrapper_clo_276, $y_wrapper_clo_277);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_278;
        break;
      
    }
  } else {
    switch ($l_271 >> 1) {
      default:
        $y_272 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_272;
        break;
      
    }
  }
}

value y_wrapper_132(struct thread_info *$tinfo, value $env_266, value $anon_267)
{
  struct stack_frame frame;
  value root[1];
  register value $l_proj_268;
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
  $l_proj_268 = *((value *) $env_266 + 0);
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $l_proj_268;
}

value y_wrapper_131(struct thread_info *$tinfo, value $env_262, value $n_263)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_265;
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
  $l_proj_265 = *((value *) $env_262 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_130)
    ($tinfo, $n_263, $l_proj_265);
  return $result;
}

value y_known_130(struct thread_info *$tinfo, value $n_251, value $l_252)
{
  struct stack_frame frame;
  value root[2];
  register value $y_253;
  register value $a_254;
  register value $l_255;
  register value $env_256;
  register value $env_257;
  register value $y_wrapper_clo_258;
  register value $y_wrapper_clo_259;
  register value $prim_260;
  register value $y_261;
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
    *(root + 1) = $l_252;
    *(root + 0) = $n_251;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $l_252 = *(root + 1);
    $n_251 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_252 & 1) == 0) {
    switch (*((value *) $l_252 + -1) & 255) {
      default:
        $a_254 = *((value *) $l_252 + 0);
        $l_255 = *((value *) $l_252 + 1);
        $env_256 = 1;
        $env_257 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_257 + -1) = 1024;
        *((value *) $env_257 + 0) = $l_255;
        $y_wrapper_clo_258 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_258 + -1) = 2048;
        *((value *) $y_wrapper_clo_258 + 0) = y_wrapper_129;
        *((value *) $y_wrapper_clo_258 + 1) = $env_256;
        $y_wrapper_clo_259 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_259 + -1) = 2048;
        *((value *) $y_wrapper_clo_259 + 0) = y_wrapper_131;
        *((value *) $y_wrapper_clo_259 + 1) = $env_257;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $a_254;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_260 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $n_251, $y_wrapper_clo_258, $y_wrapper_clo_259);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 1) = $prim_260;
          frame.next = root + 2;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $prim_260 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $a_254 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_261 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_261 + -1) = 2048;
        *((value *) $y_261 + 0) = $a_254;
        *((value *) $y_261 + 1) = $prim_260;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_261;
        break;
      
    }
  } else {
    switch ($l_252 >> 1) {
      default:
        $y_253 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_253;
        break;
      
    }
  }
}

value y_wrapper_129(struct thread_info *$tinfo, value $env_247, value $anon_248)
{
  struct stack_frame frame;
  value root[0];
  register value $y_249;
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
  $y_249 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_249;
}

value f_case_known_128(struct thread_info *$tinfo, value $s_221, value $prim_222, value $y_223)
{
  struct stack_frame frame;
  value root[3];
  register value $y_224;
  register value $prim_225;
  register value $prim_226;
  register value $y_227;
  register value $prim_228;
  register value $prim_229;
  register value $prim_230;
  register value $env_231;
  register value $env_232;
  register value $y_wrapper_clo_233;
  register value $y_wrapper_clo_234;
  register value $prim_235;
  register value $prim_236;
  register value $env_237;
  register value $env_238;
  register value $y_wrapper_clo_239;
  register value $y_wrapper_clo_240;
  register value $prim_241;
  register value $y_242;
  register value $prim_243;
  register value $prim_244;
  register value $y_245;
  register value $y_246;
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
  if (!(21 <= $limit - $alloc)) {
    *(root + 2) = $y_223;
    *(root + 1) = $prim_222;
    *(root + 0) = $s_221;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 21;
    garbage_collect($tinfo);
    $y_223 = *(root + 2);
    $prim_222 = *(root + 1);
    $s_221 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_221 & 1) == 0) {
    switch (*((value *) $s_221 + -1) & 255) {
      
    }
  } else {
    switch ($s_221 >> 1) {
      case 0:
        $y_224 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $y_224 + -1) = 1024;
        *((value *) $y_224 + 0) = $y_223;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_224;
        break;
      default:
        $prim_225 = ((value (*)(void)) bench_lit_36)();
        $prim_226 =
          ((value (*)(value, value)) bench_nat_eqb)
          ($prim_222, $prim_225);
        if (($prim_226 & 1) == 0) {
          switch (*((value *) $prim_226 + -1) & 255) {
            
          }
        } else {
          switch ($prim_226 >> 1) {
            case 0:
              $y_227 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $y_227 + -1) = 1025;
              *((value *) $y_227 + 0) = $y_223;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_227;
              break;
            default:
              $prim_228 = ((value (*)(void)) bench_lit_44)();
              $prim_229 =
                ((value (*)(value, value)) bench_nat_eqb)
                ($prim_222, $prim_228);
              if (($prim_229 & 1) == 0) {
                switch (*((value *) $prim_229 + -1) & 255) {
                  
                }
              } else {
                switch ($prim_229 >> 1) {
                  case 0:
                    $prim_230 = ((value (*)(void)) bench_lit_8)();
                    $env_231 = 1;
                    $env_232 = (value) ($alloc + 1);
                    $alloc = $alloc + 2;
                    *((value *) $env_232 + -1) = 1024;
                    *((value *) $env_232 + 0) = $y_223;
                    $y_wrapper_clo_233 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_233 + -1) = 2048;
                    *((value *) $y_wrapper_clo_233 + 0) = y_wrapper_129;
                    *((value *) $y_wrapper_clo_233 + 1) = $env_231;
                    $y_wrapper_clo_234 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_234 + -1) = 2048;
                    *((value *) $y_wrapper_clo_234 + 0) = y_wrapper_131;
                    *((value *) $y_wrapper_clo_234 + 1) = $env_232;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    *(root + 0) = $y_223;
                    frame.next = root + 1;
                    (*$tinfo).fp = &frame;
                    $prim_235 =
                      ((value (*)(struct thread_info *, value, value, value)) 
                        bench_nat_case)
                      ($tinfo, $prim_230, $y_wrapper_clo_233,
                       $y_wrapper_clo_234);
                    $alloc = (*$tinfo).alloc;
                    $limit = (*$tinfo).limit;
                    if (!(13 <= $limit - $alloc)) {
                      *(root + 1) = $prim_235;
                      frame.next = root + 2;
                      (*$tinfo).nalloc = 13;
                      garbage_collect($tinfo);
                      $prim_235 = *(root + 1);
                      $alloc = (*$tinfo).alloc;
                      $limit = (*$tinfo).limit;
                    }
                    $y_223 = *(root + 0);
                    (*$tinfo).fp = frame.prev;
                    $prim_236 = ((value (*)(void)) bench_lit_8)();
                    $env_237 = (value) ($alloc + 1);
                    $alloc = $alloc + 2;
                    *((value *) $env_237 + -1) = 1024;
                    *((value *) $env_237 + 0) = $y_223;
                    $env_238 = (value) ($alloc + 1);
                    $alloc = $alloc + 2;
                    *((value *) $env_238 + -1) = 1024;
                    *((value *) $env_238 + 0) = $y_223;
                    $y_wrapper_clo_239 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_239 + -1) = 2048;
                    *((value *) $y_wrapper_clo_239 + 0) = y_wrapper_132;
                    *((value *) $y_wrapper_clo_239 + 1) = $env_237;
                    $y_wrapper_clo_240 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_240 + -1) = 2048;
                    *((value *) $y_wrapper_clo_240 + 0) = y_wrapper_134;
                    *((value *) $y_wrapper_clo_240 + 1) = $env_238;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    *(root + 0) = $prim_235;
                    frame.next = root + 1;
                    (*$tinfo).fp = &frame;
                    $prim_241 =
                      ((value (*)(struct thread_info *, value, value, value)) 
                        bench_nat_case)
                      ($tinfo, $prim_236, $y_wrapper_clo_239,
                       $y_wrapper_clo_240);
                    $alloc = (*$tinfo).alloc;
                    $limit = (*$tinfo).limit;
                    if (!(3 <= $limit - $alloc)) {
                      *(root + 1) = $prim_241;
                      frame.next = root + 2;
                      (*$tinfo).nalloc = 3;
                      garbage_collect($tinfo);
                      $prim_241 = *(root + 1);
                      $alloc = (*$tinfo).alloc;
                      $limit = (*$tinfo).limit;
                    }
                    $prim_235 = *(root + 0);
                    (*$tinfo).fp = frame.prev;
                    $y_242 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_242 + -1) = 2050;
                    *((value *) $y_242 + 0) = $prim_235;
                    *((value *) $y_242 + 1) = $prim_241;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_242;
                    break;
                  default:
                    $prim_243 = ((value (*)(void)) bench_lit_164)();
                    $prim_244 =
                      ((value (*)(value, value)) bench_nat_eqb)
                      ($prim_222, $prim_243);
                    if (($prim_244 & 1) == 0) {
                      switch (*((value *) $prim_244 + -1) & 255) {
                        
                      }
                    } else {
                      switch ($prim_244 >> 1) {
                        case 0:
                          $y_245 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_245;
                          break;
                        default:
                          $y_246 = 3;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_246;
                          break;
                        
                      }
                    }
                    break;
                  
                }
              }
              break;
            
          }
        }
        break;
      
    }
  }
}

value y_wrapper_127(struct thread_info *$tinfo, value $env_209, value $np_210)
{
  struct stack_frame frame;
  value root[2];
  register value $pos_proj_211;
  register value $prim_212;
  register value $prim_213;
  register value $env_214;
  register value $env_215;
  register value $y_wrapper_clo_216;
  register value $y_wrapper_clo_217;
  register value $prim_218;
  register value $y_219;
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
    *(root + 1) = $np_210;
    *(root + 0) = $env_209;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $np_210 = *(root + 1);
    $env_209 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_proj_211 = *((value *) $env_209 + 0);
  $prim_212 = ((value (*)(value)) bench_input_byte)($pos_proj_211);
  $prim_213 = ((value (*)(value)) bench_nat_succ)($pos_proj_211);
  $env_214 = 1;
  $env_215 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_215 + -1) = 1024;
  *((value *) $env_215 + 0) = $prim_213;
  $y_wrapper_clo_216 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_216 + -1) = 2048;
  *((value *) $y_wrapper_clo_216 + 0) = y_wrapper_126;
  *((value *) $y_wrapper_clo_216 + 1) = $env_214;
  $y_wrapper_clo_217 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_217 + -1) = 2048;
  *((value *) $y_wrapper_clo_217 + 0) = y_wrapper_127;
  *((value *) $y_wrapper_clo_217 + 1) = $env_215;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $prim_212;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_218 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $np_210, $y_wrapper_clo_216, $y_wrapper_clo_217);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_218;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_218 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_212 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_219 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_219 + -1) = 2048;
  *((value *) $y_219 + 0) = $prim_212;
  *((value *) $y_219 + 1) = $prim_218;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_219;
}

value y_wrapper_126(struct thread_info *$tinfo, value $env_206, value $anon_207)
{
  struct stack_frame frame;
  value root[0];
  register value $y_208;
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
  $y_208 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_208;
}

value y_125(struct thread_info *$tinfo, value $env_170, value $kp_171)
{
  struct stack_frame frame;
  value root[5];
  register value $pos_proj_172;
  register value $prim_173;
  register value $pos_proj_174;
  register value $prim_175;
  register value $prim_176;
  register value $pos_proj_177;
  register value $prim_178;
  register value $prim_179;
  register value $env_180;
  register value $env_181;
  register value $y_wrapper_clo_182;
  register value $y_wrapper_clo_183;
  register value $prim_184;
  register value $prim_186;
  register value $prim_187;
  register value $y_188;
  register value $s_proj_189;
  register value $env_190;
  register value $y_191;
  register value $sp_192;
  register value $r_193;
  register value $y_195;
  register value $pos_proj_196;
  register value $prim_197;
  register value $prim_198;
  register value $prim_199;
  register value $env_200;
  register value $env_201;
  register value $y_wrapper_clo_202;
  register value $y_clo_203;
  register value $prim_204;
  register value $y_205;
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
    *(root + 1) = $kp_171;
    *(root + 0) = $env_170;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $kp_171 = *(root + 1);
    $env_170 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_proj_172 = *((value *) $env_170 + 0);
  $prim_173 = ((value (*)(value)) bench_input_byte)($pos_proj_172);
  $pos_proj_174 = *((value *) $env_170 + 0);
  $prim_175 = ((value (*)(value)) bench_nat_succ)($pos_proj_174);
  $prim_176 = ((value (*)(value)) bench_input_byte)($prim_175);
  $pos_proj_177 = *((value *) $env_170 + 0);
  $prim_178 = ((value (*)(value)) bench_nat_succ)($pos_proj_177);
  $prim_179 = ((value (*)(value)) bench_nat_succ)($prim_178);
  $env_180 = 1;
  $env_181 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_181 + -1) = 1024;
  *((value *) $env_181 + 0) = $prim_179;
  $y_wrapper_clo_182 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_182 + -1) = 2048;
  *((value *) $y_wrapper_clo_182 + 0) = y_wrapper_126;
  *((value *) $y_wrapper_clo_182 + 1) = $env_180;
  $y_wrapper_clo_183 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_183 + -1) = 2048;
  *((value *) $y_wrapper_clo_183 + 0) = y_wrapper_127;
  *((value *) $y_wrapper_clo_183 + 1) = $env_181;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 3) = $prim_176;
  *(root + 2) = $prim_173;
  *(root + 1) = $kp_171;
  *(root + 0) = $env_170;
  frame.next = root + 4;
  (*$tinfo).fp = &frame;
  $prim_184 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $prim_176, $y_wrapper_clo_182, $y_wrapper_clo_183);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $prim_176 = *(root + 3);
  $prim_173 = *(root + 2);
  $kp_171 = *(root + 1);
  $env_170 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_186 = ((value (*)(void)) bench_lit_32)();
  $prim_187 =
    ((value (*)(value, value)) bench_nat_eqb)
    ($prim_173, $prim_186);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $prim_176;
  *(root + 1) = $kp_171;
  *(root + 0) = $env_170;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $y_188 =
    ((value (*)(struct thread_info *, value, value, value)) f_case_known_128)
    ($tinfo, $prim_187, $prim_173, $prim_184);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(2 <= $limit - $alloc)) {
    *(root + 3) = $y_188;
    frame.next = root + 4;
    (*$tinfo).nalloc = 2;
    garbage_collect($tinfo);
    $y_188 = *(root + 3);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_176 = *(root + 2);
  $kp_171 = *(root + 1);
  $env_170 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $s_proj_189 = *((value *) $env_170 + 1);
  $env_190 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_190 + -1) = 1024;
  *((value *) $env_190 + 0) = $s_proj_189;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 2) = $prim_176;
  *(root + 1) = $kp_171;
  *(root + 0) = $env_170;
  frame.next = root + 3;
  (*$tinfo).fp = &frame;
  $y_191 =
    ((value (*)(struct thread_info *, value, value)) f_case_135)
    ($tinfo, $env_190, $y_188);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $prim_176 = *(root + 2);
  $kp_171 = *(root + 1);
  $env_170 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_191 & 1) == 0) {
    switch (*((value *) $y_191 + -1) & 255) {
      default:
        $sp_192 = *((value *) $y_191 + 0);
        $r_193 = *((value *) $y_191 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 3) = $sp_192;
        *(root + 2) = $prim_176;
        *(root + 1) = $kp_171;
        *(root + 0) = $env_170;
        frame.next = root + 4;
        (*$tinfo).fp = &frame;
        $y_195 =
          ((value (*)(struct thread_info *, value)) f_case_known_141)
          ($tinfo, $r_193);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(12 <= $limit - $alloc)) {
          *(root + 4) = $y_195;
          frame.next = root + 5;
          (*$tinfo).nalloc = 12;
          garbage_collect($tinfo);
          $y_195 = *(root + 4);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $sp_192 = *(root + 3);
        $prim_176 = *(root + 2);
        $kp_171 = *(root + 1);
        $env_170 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $pos_proj_196 = *((value *) $env_170 + 0);
        $prim_197 = ((value (*)(value)) bench_nat_succ)($pos_proj_196);
        $prim_198 = ((value (*)(value)) bench_nat_succ)($prim_197);
        $prim_199 =
          ((value (*)(value, value)) bench_nat_add)
          ($prim_198, $prim_176);
        $env_200 = 1;
        $env_201 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_201 + -1) = 2048;
        *((value *) $env_201 + 0) = $prim_199;
        *((value *) $env_201 + 1) = $sp_192;
        $y_wrapper_clo_202 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_202 + -1) = 2048;
        *((value *) $y_wrapper_clo_202 + 0) = y_wrapper_124;
        *((value *) $y_wrapper_clo_202 + 1) = $env_200;
        $y_clo_203 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_203 + -1) = 2048;
        *((value *) $y_clo_203 + 0) = y_125;
        *((value *) $y_clo_203 + 1) = $env_201;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $y_195;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_204 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_171, $y_wrapper_clo_202, $y_clo_203);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 1) = $prim_204;
          frame.next = root + 2;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $prim_204 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $y_195 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_205 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_205 + -1) = 2048;
        *((value *) $y_205 + 0) = $y_195;
        *((value *) $y_205 + 1) = $prim_204;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_205;
        break;
      
    }
  } else {
    switch ($y_191 >> 1) {
      
    }
  }
}

value y_wrapper_124(struct thread_info *$tinfo, value $env_167, value $anon_168)
{
  struct stack_frame frame;
  value root[0];
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
  $y_169 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_169;
}

value digits_eqb_uncurried_known_123(struct thread_info *$tinfo, value $b_156, value $a_157)
{
  struct stack_frame frame;
  value root[2];
  register value $y_158;
  register value $y_159;
  register value $x_160;
  register value $ap_161;
  register value $y_162;
  register value $y_163;
  register value $bp_164;
  register value $prim_165;
  register value $y_166;
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
  if (($a_157 & 1) == 0) {
    switch (*((value *) $a_157 + -1) & 255) {
      default:
        $x_160 = *((value *) $a_157 + 0);
        $ap_161 = *((value *) $a_157 + 1);
        if (($b_156 & 1) == 0) {
          switch (*((value *) $b_156 + -1) & 255) {
            default:
              $y_163 = *((value *) $b_156 + 0);
              $bp_164 = *((value *) $b_156 + 1);
              $prim_165 =
                ((value (*)(value, value)) bench_nat_eqb)
                ($x_160, $y_163);
              if (($prim_165 & 1) == 0) {
                switch (*((value *) $prim_165 + -1) & 255) {
                  
                }
              } else {
                switch ($prim_165 >> 1) {
                  case 0:
                    $args = (*$tinfo).args;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    $result =
                      ((value (*)(struct thread_info *, value, value)) 
                        digits_eqb_uncurried_known_123)
                      ($tinfo, $bp_164, $ap_161);
                    return $result;
                    break;
                  default:
                    $y_166 = 3;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_166;
                    break;
                  
                }
              }
              break;
            
          }
        } else {
          switch ($b_156 >> 1) {
            default:
              $y_162 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_162;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($a_157 >> 1) {
      default:
        if (($b_156 & 1) == 0) {
          switch (*((value *) $b_156 + -1) & 255) {
            default:
              $y_159 = 3;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_159;
              break;
            
          }
        } else {
          switch ($b_156 >> 1) {
            default:
              $y_158 = 1;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_158;
              break;
            
          }
        }
        break;
      
    }
  }
}

value EncoreBenchdW4dPindpuk_tries_known_122(struct thread_info *$tinfo, value $s_153)
{
  struct stack_frame frame;
  value root[1];
  register value $puk_tries_154;
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
  if (($s_153 & 1) == 0) {
    switch (*((value *) $s_153 + -1) & 255) {
      default:
        $puk_tries_154 = *((value *) $s_153 + 3);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $puk_tries_154;
        break;
      
    }
  } else {
    switch ($s_153 >> 1) {
      
    }
  }
}

value EncoreBenchdW4dPindpuk_known_121(struct thread_info *$tinfo, value $s_150)
{
  struct stack_frame frame;
  value root[1];
  register value $puk_151;
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
  if (($s_150 & 1) == 0) {
    switch (*((value *) $s_150 + -1) & 255) {
      default:
        $puk_151 = *((value *) $s_150 + 1);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $puk_151;
        break;
      
    }
  } else {
    switch ($s_150 >> 1) {
      
    }
  }
}

value EncoreBenchdW4dPindpin_known_120(struct thread_info *$tinfo, value $s_147)
{
  struct stack_frame frame;
  value root[1];
  register value $pin_148;
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
  if (($s_147 & 1) == 0) {
    switch (*((value *) $s_147 + -1) & 255) {
      default:
        $pin_148 = *((value *) $s_147 + 0);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $pin_148;
        break;
      
    }
  } else {
    switch ($s_147 >> 1) {
      
    }
  }
}

value EncoreBenchdW4dPindtries_known_119(struct thread_info *$tinfo, value $s_144)
{
  struct stack_frame frame;
  value root[1];
  register value $tries_145;
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
  if (($s_144 & 1) == 0) {
    switch (*((value *) $s_144 + -1) & 255) {
      default:
        $tries_145 = *((value *) $s_144 + 2);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $tries_145;
        break;
      
    }
  } else {
    switch ($s_144 >> 1) {
      
    }
  }
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
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
  register value $prim_748;
  register value $prim_749;
  register value $prim_750;
  register value $prim_751;
  register value $prim_752;
  register value $prim_753;
  register value $prim_754;
  register value $prim_755;
  register value $prim_756;
  register value $prim_757;
  register value $prim_758;
  register value $prim_759;
  register value $prim_760;
  register value $prim_761;
  register value $prim_762;
  register value $prim_763;
  register value $prim_764;
  register value $prim_765;
  register value $prim_766;
  register value $prim_767;
  register value $prim_768;
  register value $prim_769;
  register value $prim_770;
  register value $prim_771;
  register value $prim_772;
  register value $prim_773;
  register value $prim_774;
  register value $prim_775;
  register value $prim_776;
  register value $prim_777;
  register value $prim_778;
  register value $prim_779;
  register value $prim_780;
  register value $prim_781;
  register value $prim_782;
  register value $y_783;
  register value $y_784;
  register value $y_785;
  register value $y_786;
  register value $y_787;
  register value $prim_788;
  register value $prim_789;
  register value $prim_790;
  register value $prim_791;
  register value $prim_792;
  register value $prim_793;
  register value $prim_794;
  register value $prim_795;
  register value $prim_796;
  register value $prim_797;
  register value $prim_798;
  register value $prim_799;
  register value $prim_800;
  register value $prim_801;
  register value $prim_802;
  register value $prim_803;
  register value $prim_804;
  register value $prim_805;
  register value $prim_806;
  register value $prim_807;
  register value $prim_808;
  register value $prim_809;
  register value $prim_810;
  register value $prim_811;
  register value $prim_812;
  register value $prim_813;
  register value $prim_814;
  register value $prim_815;
  register value $prim_816;
  register value $prim_817;
  register value $prim_818;
  register value $prim_819;
  register value $prim_820;
  register value $prim_821;
  register value $prim_822;
  register value $prim_823;
  register value $prim_824;
  register value $prim_825;
  register value $prim_826;
  register value $prim_827;
  register value $prim_828;
  register value $prim_829;
  register value $prim_830;
  register value $prim_831;
  register value $y_832;
  register value $y_833;
  register value $y_834;
  register value $y_835;
  register value $y_836;
  register value $y_837;
  register value $y_838;
  register value $y_839;
  register value $y_840;
  register value $prim_841;
  register value $prim_842;
  register value $y_843;
  register value $EncoreBenchdW4dPindinit_844;
  register value $env_845;
  register value $EncoreBenchdW4dPindrun_wrapper_clo_846;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(47 <= $limit - $alloc)) {
    /*skip*/;
    (*$tinfo).nalloc = 47;
    garbage_collect($tinfo);
    /*skip*/;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_465 = ((value (*)(void)) bench_nat_zero)();
  $prim_466 = ((value (*)(value)) bench_nat_succ)($prim_465);
  $prim_467 = ((value (*)(value)) bench_nat_succ)($prim_466);
  $prim_468 = ((value (*)(value)) bench_nat_succ)($prim_467);
  $prim_469 = ((value (*)(void)) bench_nat_zero)();
  $prim_470 = ((value (*)(value)) bench_nat_succ)($prim_469);
  $prim_471 = ((value (*)(value)) bench_nat_succ)($prim_470);
  $prim_472 = ((value (*)(value)) bench_nat_succ)($prim_471);
  $prim_473 = ((value (*)(value)) bench_nat_succ)($prim_472);
  $prim_474 = ((value (*)(value)) bench_nat_succ)($prim_473);
  $prim_475 = ((value (*)(value)) bench_nat_succ)($prim_474);
  $prim_476 = ((value (*)(value)) bench_nat_succ)($prim_475);
  $prim_477 = ((value (*)(value)) bench_nat_succ)($prim_476);
  $prim_478 = ((value (*)(value)) bench_nat_succ)($prim_477);
  $prim_479 = ((value (*)(value)) bench_nat_succ)($prim_478);
  $prim_480 = ((value (*)(void)) bench_nat_zero)();
  $prim_481 = ((value (*)(value)) bench_nat_succ)($prim_480);
  $prim_482 = ((value (*)(value)) bench_nat_succ)($prim_481);
  $prim_483 = ((value (*)(value)) bench_nat_succ)($prim_482);
  $prim_484 = ((value (*)(value)) bench_nat_succ)($prim_483);
  $prim_485 = ((value (*)(value)) bench_nat_succ)($prim_484);
  $prim_486 = ((value (*)(value)) bench_nat_succ)($prim_485);
  $prim_487 = ((value (*)(value)) bench_nat_succ)($prim_486);
  $prim_488 = ((value (*)(value)) bench_nat_succ)($prim_487);
  $prim_489 = ((value (*)(value)) bench_nat_succ)($prim_488);
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
  $prim_513 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_550 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_595 = ((value (*)(void)) bench_nat_zero)();
  $prim_596 = ((value (*)(value)) bench_nat_succ)($prim_595);
  $prim_597 = ((value (*)(value)) bench_nat_succ)($prim_596);
  $prim_598 = ((value (*)(value)) bench_nat_succ)($prim_597);
  $prim_599 = ((value (*)(value)) bench_nat_succ)($prim_598);
  $prim_600 = ((value (*)(value)) bench_nat_succ)($prim_599);
  $prim_601 = ((value (*)(value)) bench_nat_succ)($prim_600);
  $prim_602 = ((value (*)(value)) bench_nat_succ)($prim_601);
  $prim_603 = ((value (*)(value)) bench_nat_succ)($prim_602);
  $prim_604 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_748 = ((value (*)(value)) bench_nat_succ)($prim_747);
  $prim_749 = ((value (*)(value)) bench_nat_succ)($prim_748);
  $prim_750 = ((value (*)(value)) bench_nat_succ)($prim_749);
  $prim_751 = ((value (*)(value)) bench_nat_succ)($prim_750);
  $prim_752 = ((value (*)(value)) bench_nat_succ)($prim_751);
  $prim_753 = ((value (*)(value)) bench_nat_succ)($prim_752);
  $prim_754 = ((value (*)(value)) bench_nat_succ)($prim_753);
  $prim_755 = ((value (*)(value)) bench_nat_succ)($prim_754);
  $prim_756 = ((value (*)(value)) bench_nat_succ)($prim_755);
  $prim_757 = ((value (*)(value)) bench_nat_succ)($prim_756);
  $prim_758 = ((value (*)(value)) bench_nat_succ)($prim_757);
  $prim_759 = ((value (*)(value)) bench_nat_succ)($prim_758);
  $prim_760 = ((value (*)(value)) bench_nat_succ)($prim_759);
  $prim_761 = ((value (*)(value)) bench_nat_succ)($prim_760);
  $prim_762 = ((value (*)(value)) bench_nat_succ)($prim_761);
  $prim_763 = ((value (*)(value)) bench_nat_succ)($prim_762);
  $prim_764 = ((value (*)(value)) bench_nat_succ)($prim_763);
  $prim_765 = ((value (*)(value)) bench_nat_succ)($prim_764);
  $prim_766 = ((value (*)(value)) bench_nat_succ)($prim_765);
  $prim_767 = ((value (*)(value)) bench_nat_succ)($prim_766);
  $prim_768 = ((value (*)(value)) bench_nat_succ)($prim_767);
  $prim_769 = ((value (*)(void)) bench_nat_zero)();
  $prim_770 = ((value (*)(value)) bench_nat_succ)($prim_769);
  $prim_771 = ((value (*)(void)) bench_nat_zero)();
  $prim_772 = ((value (*)(value)) bench_nat_succ)($prim_771);
  $prim_773 = ((value (*)(value)) bench_nat_succ)($prim_772);
  $prim_774 = ((value (*)(void)) bench_nat_zero)();
  $prim_775 = ((value (*)(value)) bench_nat_succ)($prim_774);
  $prim_776 = ((value (*)(value)) bench_nat_succ)($prim_775);
  $prim_777 = ((value (*)(value)) bench_nat_succ)($prim_776);
  $prim_778 = ((value (*)(void)) bench_nat_zero)();
  $prim_779 = ((value (*)(value)) bench_nat_succ)($prim_778);
  $prim_780 = ((value (*)(value)) bench_nat_succ)($prim_779);
  $prim_781 = ((value (*)(value)) bench_nat_succ)($prim_780);
  $prim_782 = ((value (*)(value)) bench_nat_succ)($prim_781);
  $y_783 = 1;
  $y_784 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_784 + -1) = 2048;
  *((value *) $y_784 + 0) = $prim_782;
  *((value *) $y_784 + 1) = $y_783;
  $y_785 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_785 + -1) = 2048;
  *((value *) $y_785 + 0) = $prim_777;
  *((value *) $y_785 + 1) = $y_784;
  $y_786 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_786 + -1) = 2048;
  *((value *) $y_786 + 0) = $prim_773;
  *((value *) $y_786 + 1) = $y_785;
  $y_787 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_787 + -1) = 2048;
  *((value *) $y_787 + 0) = $prim_770;
  *((value *) $y_787 + 1) = $y_786;
  $prim_788 = ((value (*)(void)) bench_nat_zero)();
  $prim_789 = ((value (*)(value)) bench_nat_succ)($prim_788);
  $prim_790 = ((value (*)(void)) bench_nat_zero)();
  $prim_791 = ((value (*)(value)) bench_nat_succ)($prim_790);
  $prim_792 = ((value (*)(value)) bench_nat_succ)($prim_791);
  $prim_793 = ((value (*)(void)) bench_nat_zero)();
  $prim_794 = ((value (*)(value)) bench_nat_succ)($prim_793);
  $prim_795 = ((value (*)(value)) bench_nat_succ)($prim_794);
  $prim_796 = ((value (*)(value)) bench_nat_succ)($prim_795);
  $prim_797 = ((value (*)(void)) bench_nat_zero)();
  $prim_798 = ((value (*)(value)) bench_nat_succ)($prim_797);
  $prim_799 = ((value (*)(value)) bench_nat_succ)($prim_798);
  $prim_800 = ((value (*)(value)) bench_nat_succ)($prim_799);
  $prim_801 = ((value (*)(value)) bench_nat_succ)($prim_800);
  $prim_802 = ((value (*)(void)) bench_nat_zero)();
  $prim_803 = ((value (*)(value)) bench_nat_succ)($prim_802);
  $prim_804 = ((value (*)(value)) bench_nat_succ)($prim_803);
  $prim_805 = ((value (*)(value)) bench_nat_succ)($prim_804);
  $prim_806 = ((value (*)(value)) bench_nat_succ)($prim_805);
  $prim_807 = ((value (*)(value)) bench_nat_succ)($prim_806);
  $prim_808 = ((value (*)(void)) bench_nat_zero)();
  $prim_809 = ((value (*)(value)) bench_nat_succ)($prim_808);
  $prim_810 = ((value (*)(value)) bench_nat_succ)($prim_809);
  $prim_811 = ((value (*)(value)) bench_nat_succ)($prim_810);
  $prim_812 = ((value (*)(value)) bench_nat_succ)($prim_811);
  $prim_813 = ((value (*)(value)) bench_nat_succ)($prim_812);
  $prim_814 = ((value (*)(value)) bench_nat_succ)($prim_813);
  $prim_815 = ((value (*)(void)) bench_nat_zero)();
  $prim_816 = ((value (*)(value)) bench_nat_succ)($prim_815);
  $prim_817 = ((value (*)(value)) bench_nat_succ)($prim_816);
  $prim_818 = ((value (*)(value)) bench_nat_succ)($prim_817);
  $prim_819 = ((value (*)(value)) bench_nat_succ)($prim_818);
  $prim_820 = ((value (*)(value)) bench_nat_succ)($prim_819);
  $prim_821 = ((value (*)(value)) bench_nat_succ)($prim_820);
  $prim_822 = ((value (*)(value)) bench_nat_succ)($prim_821);
  $prim_823 = ((value (*)(void)) bench_nat_zero)();
  $prim_824 = ((value (*)(value)) bench_nat_succ)($prim_823);
  $prim_825 = ((value (*)(value)) bench_nat_succ)($prim_824);
  $prim_826 = ((value (*)(value)) bench_nat_succ)($prim_825);
  $prim_827 = ((value (*)(value)) bench_nat_succ)($prim_826);
  $prim_828 = ((value (*)(value)) bench_nat_succ)($prim_827);
  $prim_829 = ((value (*)(value)) bench_nat_succ)($prim_828);
  $prim_830 = ((value (*)(value)) bench_nat_succ)($prim_829);
  $prim_831 = ((value (*)(value)) bench_nat_succ)($prim_830);
  $y_832 = 1;
  $y_833 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_833 + -1) = 2048;
  *((value *) $y_833 + 0) = $prim_831;
  *((value *) $y_833 + 1) = $y_832;
  $y_834 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_834 + -1) = 2048;
  *((value *) $y_834 + 0) = $prim_822;
  *((value *) $y_834 + 1) = $y_833;
  $y_835 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_835 + -1) = 2048;
  *((value *) $y_835 + 0) = $prim_814;
  *((value *) $y_835 + 1) = $y_834;
  $y_836 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_836 + -1) = 2048;
  *((value *) $y_836 + 0) = $prim_807;
  *((value *) $y_836 + 1) = $y_835;
  $y_837 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_837 + -1) = 2048;
  *((value *) $y_837 + 0) = $prim_801;
  *((value *) $y_837 + 1) = $y_836;
  $y_838 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_838 + -1) = 2048;
  *((value *) $y_838 + 0) = $prim_796;
  *((value *) $y_838 + 1) = $y_837;
  $y_839 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_839 + -1) = 2048;
  *((value *) $y_839 + 0) = $prim_792;
  *((value *) $y_839 + 1) = $y_838;
  $y_840 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_840 + -1) = 2048;
  *((value *) $y_840 + 0) = $prim_789;
  *((value *) $y_840 + 1) = $y_839;
  $prim_841 = ((value (*)(void)) bench_lit_3)();
  $prim_842 = ((value (*)(void)) bench_lit_10)();
  $y_843 = 3;
  $EncoreBenchdW4dPindinit_844 = (value) ($alloc + 1);
  $alloc = $alloc + 6;
  *((value *) $EncoreBenchdW4dPindinit_844 + -1) = 5120;
  *((value *) $EncoreBenchdW4dPindinit_844 + 0) = $y_787;
  *((value *) $EncoreBenchdW4dPindinit_844 + 1) = $y_840;
  *((value *) $EncoreBenchdW4dPindinit_844 + 2) = $prim_841;
  *((value *) $EncoreBenchdW4dPindinit_844 + 3) = $prim_842;
  *((value *) $EncoreBenchdW4dPindinit_844 + 4) = $y_843;
  $env_845 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_845 + -1) = 1024;
  *((value *) $env_845 + 0) = $EncoreBenchdW4dPindinit_844;
  $EncoreBenchdW4dPindrun_wrapper_clo_846 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW4dPindrun_wrapper_clo_846 + -1) = 2048;
  *((value *) $EncoreBenchdW4dPindrun_wrapper_clo_846 + 0) =
    EncoreBenchdW4dPindrun_wrapper_142;
  *((value *) $EncoreBenchdW4dPindrun_wrapper_clo_846 + 1) = $env_845;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW4dPindrun_wrapper_clo_846;
}


#endif /* W4_PIN_C */
