#ifndef W1_APDU_C
#define W1_APDU_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "bench_rt.h"
#include "w1_apdu.h"
extern struct thread_info *make_tinfo(void);
extern value EncoreBenchdW1dApdudrun_wrapper_145(struct thread_info *, value, value);
extern value go_known_144(struct thread_info *, value, value, value);
extern value summ_uncurried_uncurried_known_143(struct thread_info *, value, value, value);
extern value fold_right_known_142(struct thread_info *, value, value, value);
extern value f_case_known_141(struct thread_info *, value);
extern value y_wrapper_140(struct thread_info *, value, value);
extern value f_case_known_139(struct thread_info *, value, value);
extern value f_case_known_138(struct thread_info *, value);
extern value f_case_known_137(struct thread_info *, value);
extern value y_known_136(struct thread_info *, value, value);
extern value y_wrapper_135(struct thread_info *, value, value);
extern value y_wrapper_134(struct thread_info *, value, value);
extern value y_known_133(struct thread_info *, value, value);
extern value y_wrapper_132(struct thread_info *, value, value);
extern value f_case_known_131(struct thread_info *, value);
extern value y_wrapper_130(struct thread_info *, value, value);
extern value y_wrapper_129(struct thread_info *, value, value);
extern value EncoreBenchdW1dApdudrun_known_128(struct thread_info *, value);
extern value EncoreBenchdW1dApduddata_known_127(struct thread_info *, value);
extern value length_known_126(struct thread_info *, value);
extern value y_wrapper_125(struct thread_info *, value, value);
extern value y_known_124(struct thread_info *, value, value);
extern value y_wrapper_123(struct thread_info *, value, value);
extern value body(struct thread_info *);
value EncoreBenchdW1dApdudrun_wrapper_145(struct thread_info *, value, value);
value go_known_144(struct thread_info *, value, value, value);
value summ_uncurried_uncurried_known_143(struct thread_info *, value, value, value);
value fold_right_known_142(struct thread_info *, value, value, value);
value f_case_known_141(struct thread_info *, value);
value y_wrapper_140(struct thread_info *, value, value);
value f_case_known_139(struct thread_info *, value, value);
value f_case_known_138(struct thread_info *, value);
value f_case_known_137(struct thread_info *, value);
value y_known_136(struct thread_info *, value, value);
value y_wrapper_135(struct thread_info *, value, value);
value y_wrapper_134(struct thread_info *, value, value);
value y_known_133(struct thread_info *, value, value);
value y_wrapper_132(struct thread_info *, value, value);
value f_case_known_131(struct thread_info *, value);
value y_wrapper_130(struct thread_info *, value, value);
value y_wrapper_129(struct thread_info *, value, value);
value EncoreBenchdW1dApdudrun_known_128(struct thread_info *, value);
value EncoreBenchdW1dApduddata_known_127(struct thread_info *, value);
value length_known_126(struct thread_info *, value);
value y_wrapper_125(struct thread_info *, value, value);
value y_known_124(struct thread_info *, value, value);
value y_wrapper_123(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_1209[2] = { 3, 0, };

unsigned int const y_wrapper_info_1208[4] = { 5, 2, 0, 1, };

unsigned int const y_known_info_1207[4] = { 18, 2, 0, 1, };

unsigned int const y_wrapper_info_1206[4] = { 0, 2, 0, 1, };

unsigned int const length_known_info_1205[3] = { 0, 1, 0, };

unsigned int const EncoreBenchdW1dApduddata_known_info_1204[3] = { 0, 1, 0,
  };

unsigned int const EncoreBenchdW1dApdudrun_known_info_1203[3] = { 8, 1, 0, };

unsigned int const y_wrapper_info_1202[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_1201[4] = { 11, 2, 0, 1, };

unsigned int const f_case_known_info_1200[3] = { 21, 1, 0, };

unsigned int const y_wrapper_info_1199[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_1198[4] = { 21, 2, 0, 1, };

unsigned int const y_wrapper_info_1197[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_1196[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_1195[4] = { 0, 2, 0, 1, };

unsigned int const f_case_known_info_1194[3] = { 5, 1, 0, };

unsigned int const f_case_known_info_1193[3] = { 5, 1, 0, };

unsigned int const f_case_known_info_1192[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_1191[4] = { 0, 2, 0, 1, };

unsigned int const f_case_known_info_1190[3] = { 0, 1, 0, };

unsigned int const fold_right_known_info_1189[5] = { 0, 3, 0, 1, 2, };

unsigned int const summ_uncurried_uncurried_known_info_1188[5] = { 0, 3, 0,
  1, 2, };

unsigned int const go_known_info_1187[5] = { 0, 3, 0, 1, 2, };

unsigned int const EncoreBenchdW1dApdudrun_wrapper_info_1186[4] = { 0, 2, 0,
  1, };

value EncoreBenchdW1dApdudrun_wrapper_145(struct thread_info *$tinfo, value $env_469, value $n_470)
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
    ((value (*)(struct thread_info *, value)) EncoreBenchdW1dApdudrun_known_128)
    ($tinfo, $n_470);
  return $result;
}

value go_known_144(struct thread_info *$tinfo, value $ks_461, value $acc_462, value $d_463)
{
  struct stack_frame frame;
  value root[3];
  register value $k_464;
  register value $ksp_465;
  register value $prim_466;
  register value $y_467;
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
  if (($ks_461 & 1) == 0) {
    switch (*((value *) $ks_461 + -1) & 255) {
      default:
        $k_464 = *((value *) $ks_461 + 0);
        $ksp_465 = *((value *) $ks_461 + 1);
        $prim_466 = ((value (*)(value)) bench_nat_succ)($d_463);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $prim_466;
        *(root + 0) = $k_464;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_467 =
          ((value (*)(struct thread_info *, value, value, value)) go_known_144)
          ($tinfo, $ksp_465, $acc_462, $d_463);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $prim_466 = *(root + 1);
        $k_464 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        $result =
          ((value (*)(struct thread_info *, value, value, value)) summ_uncurried_uncurried_known_143)
          ($tinfo, $y_467, $k_464, $prim_466);
        return $result;
        break;
      
    }
  } else {
    switch ($ks_461 >> 1) {
      default:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $acc_462;
        break;
      
    }
  }
}

value summ_uncurried_uncurried_known_143(struct thread_info *$tinfo, value $acc_441, value $t_442, value $d_443)
{
  struct stack_frame frame;
  value root[4];
  register value $tg_444;
  register value $v_445;
  register value $y_447;
  register value $y_448;
  register value $y_449;
  register value $y_450;
  register value $tg_451;
  register value $ks_452;
  register value $y_454;
  register value $y_456;
  register value $y_457;
  register value $y_458;
  register value $y_459;
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
  if (($t_442 & 1) == 0) {
    switch (*((value *) $t_442 + -1) & 255) {
      case 0:
        $tg_444 = *((value *) $t_442 + 0);
        $v_445 = *((value *) $t_442 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $tg_444;
        *(root + 1) = $d_443;
        *(root + 0) = $acc_441;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_447 =
          ((value (*)(struct thread_info *, value)) length_known_126)
          ($tinfo, $v_445);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 3) = $y_447;
          frame.next = root + 4;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $y_447 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $tg_444 = *(root + 2);
        $d_443 = *(root + 1);
        $acc_441 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_448 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_448 + -1) = 2048;
        *((value *) $y_448 + 0) = $y_447;
        *((value *) $y_448 + 1) = $acc_441;
        $y_449 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_449 + -1) = 2048;
        *((value *) $y_449 + 0) = $d_443;
        *((value *) $y_449 + 1) = $y_448;
        $y_450 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_450 + -1) = 2048;
        *((value *) $y_450 + 0) = $tg_444;
        *((value *) $y_450 + 1) = $y_449;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_450;
        break;
      default:
        $tg_451 = *((value *) $t_442 + 0);
        $ks_452 = *((value *) $t_442 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 3) = $ks_452;
        *(root + 2) = $tg_451;
        *(root + 1) = $d_443;
        *(root + 0) = $acc_441;
        frame.next = root + 4;
        (*$tinfo).fp = &frame;
        $y_454 =
          ((value (*)(struct thread_info *, value)) length_known_126)
          ($tinfo, $ks_452);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $ks_452 = *(root + 3);
        $tg_451 = *(root + 2);
        $d_443 = *(root + 1);
        $acc_441 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 2) = $y_454;
        *(root + 1) = $tg_451;
        *(root + 0) = $d_443;
        frame.next = root + 3;
        (*$tinfo).fp = &frame;
        $y_456 =
          ((value (*)(struct thread_info *, value, value, value)) go_known_144)
          ($tinfo, $ks_452, $acc_441, $d_443);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(9 <= $limit - $alloc)) {
          *(root + 3) = $y_456;
          frame.next = root + 4;
          (*$tinfo).nalloc = 9;
          garbage_collect($tinfo);
          $y_456 = *(root + 3);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $y_454 = *(root + 2);
        $tg_451 = *(root + 1);
        $d_443 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_457 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_457 + -1) = 2048;
        *((value *) $y_457 + 0) = $y_454;
        *((value *) $y_457 + 1) = $y_456;
        $y_458 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_458 + -1) = 2048;
        *((value *) $y_458 + 0) = $d_443;
        *((value *) $y_458 + 1) = $y_457;
        $y_459 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_459 + -1) = 2048;
        *((value *) $y_459 + 0) = $tg_451;
        *((value *) $y_459 + 1) = $y_458;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_459;
        break;
      
    }
  } else {
    switch ($t_442 >> 1) {
      
    }
  }
}

value fold_right_known_142(struct thread_info *$tinfo, value $l_433, value $prim_434, value $y_435)
{
  struct stack_frame frame;
  value root[3];
  register value $b_436;
  register value $l_437;
  register value $y_439;
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
  if (($l_433 & 1) == 0) {
    switch (*((value *) $l_433 + -1) & 255) {
      default:
        $b_436 = *((value *) $l_433 + 0);
        $l_437 = *((value *) $l_433 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $b_436;
        *(root + 0) = $prim_434;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_439 =
          ((value (*)(struct thread_info *, value, value, value)) fold_right_known_142)
          ($tinfo, $l_437, $prim_434, $y_435);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $b_436 = *(root + 1);
        $prim_434 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        $result =
          ((value (*)(struct thread_info *, value, value, value)) summ_uncurried_uncurried_known_143)
          ($tinfo, $y_439, $b_436, $prim_434);
        return $result;
        break;
      
    }
  } else {
    switch ($l_433 >> 1) {
      default:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_435;
        break;
      
    }
  }
}

value f_case_known_141(struct thread_info *$tinfo, value $s_430)
{
  struct stack_frame frame;
  value root[1];
  register value $ins_431;
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
  if (($s_430 & 1) == 0) {
    switch (*((value *) $s_430 + -1) & 255) {
      default:
        $ins_431 = *((value *) $s_430 + 1);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $ins_431;
        break;
      
    }
  } else {
    switch ($s_430 >> 1) {
      
    }
  }
}

value y_wrapper_140(struct thread_info *$tinfo, value $env_425, value $f_426)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_428;
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
  $l_proj_428 = *((value *) $env_425 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_136)
    ($tinfo, $f_426, $l_proj_428);
  return $result;
}

value f_case_known_139(struct thread_info *$tinfo, value $s_421, value $tg_422)
{
  struct stack_frame frame;
  value root[2];
  register value $prim_423;
  register value $prim_424;
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
  if (($s_421 & 1) == 0) {
    switch (*((value *) $s_421 + -1) & 255) {
      
    }
  } else {
    switch ($s_421 >> 1) {
      case 0:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $tg_422;
        break;
      default:
        $prim_423 = ((value (*)(void)) bench_lit_256)();
        $prim_424 =
          ((value (*)(value, value)) bench_nat_div)
          ($tg_422, $prim_423);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_424;
        break;
      
    }
  }
}

value f_case_known_138(struct thread_info *$tinfo, value $s_385)
{
  struct stack_frame frame;
  value root[1];
  register value $y_386;
  register value $b_387;
  register value $r_388;
  register value $prim_389;
  register value $prim_390;
  register value $y_391;
  register value $y_392;
  register value $prim_393;
  register value $prim_394;
  register value $y_395;
  register value $c_396;
  register value $rp_397;
  register value $prim_398;
  register value $prim_399;
  register value $y_400;
  register value $y_401;
  register value $y_402;
  register value $prim_403;
  register value $prim_404;
  register value $y_405;
  register value $c1_406;
  register value $l0_407;
  register value $y_408;
  register value $c2_409;
  register value $rp_410;
  register value $prim_411;
  register value $prim_412;
  register value $prim_413;
  register value $prim_414;
  register value $prim_415;
  register value $y_416;
  register value $y_417;
  register value $y_418;
  register value $y_419;
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
  if (!(5 <= $limit - $alloc)) {
    *(root + 0) = $s_385;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 5;
    garbage_collect($tinfo);
    $s_385 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_385 & 1) == 0) {
    switch (*((value *) $s_385 + -1) & 255) {
      default:
        $b_387 = *((value *) $s_385 + 0);
        $r_388 = *((value *) $s_385 + 1);
        $prim_389 = ((value (*)(void)) bench_lit_128)();
        $prim_390 =
          ((value (*)(value, value)) bench_nat_ltb)
          ($b_387, $prim_389);
        if (($prim_390 & 1) == 0) {
          switch (*((value *) $prim_390 + -1) & 255) {
            
          }
        } else {
          switch ($prim_390 >> 1) {
            case 0:
              $y_391 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_391 + -1) = 2048;
              *((value *) $y_391 + 0) = $b_387;
              *((value *) $y_391 + 1) = $r_388;
              $y_392 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $y_392 + -1) = 1024;
              *((value *) $y_392 + 0) = $y_391;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_392;
              break;
            default:
              $prim_393 = ((value (*)(void)) bench_lit_129)();
              $prim_394 =
                ((value (*)(value, value)) bench_nat_eqb)
                ($b_387, $prim_393);
              if (($prim_394 & 1) == 0) {
                switch (*((value *) $prim_394 + -1) & 255) {
                  
                }
              } else {
                switch ($prim_394 >> 1) {
                  case 0:
                    if (($r_388 & 1) == 0) {
                      switch (*((value *) $r_388 + -1) & 255) {
                        default:
                          $c_396 = *((value *) $r_388 + 0);
                          $rp_397 = *((value *) $r_388 + 1);
                          $prim_398 = ((value (*)(void)) bench_lit_128)();
                          $prim_399 =
                            ((value (*)(value, value)) bench_nat_leb)
                            ($prim_398, $c_396);
                          if (($prim_399 & 1) == 0) {
                            switch (*((value *) $prim_399 + -1) & 255) {
                              
                            }
                          } else {
                            switch ($prim_399 >> 1) {
                              case 0:
                                $y_400 = (value) ($alloc + 1);
                                $alloc = $alloc + 3;
                                *((value *) $y_400 + -1) = 2048;
                                *((value *) $y_400 + 0) = $c_396;
                                *((value *) $y_400 + 1) = $rp_397;
                                $y_401 = (value) ($alloc + 1);
                                $alloc = $alloc + 2;
                                *((value *) $y_401 + -1) = 1024;
                                *((value *) $y_401 + 0) = $y_400;
                                (*$tinfo).alloc = $alloc;
                                (*$tinfo).limit = $limit;
                                return $y_401;
                                break;
                              default:
                                $y_402 = 1;
                                (*$tinfo).alloc = $alloc;
                                (*$tinfo).limit = $limit;
                                return $y_402;
                                break;
                              
                            }
                          }
                          break;
                        
                      }
                    } else {
                      switch ($r_388 >> 1) {
                        default:
                          $y_395 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_395;
                          break;
                        
                      }
                    }
                    break;
                  default:
                    $prim_403 = ((value (*)(void)) bench_lit_130)();
                    $prim_404 =
                      ((value (*)(value, value)) bench_nat_eqb)
                      ($b_387, $prim_403);
                    if (($prim_404 & 1) == 0) {
                      switch (*((value *) $prim_404 + -1) & 255) {
                        
                      }
                    } else {
                      switch ($prim_404 >> 1) {
                        case 0:
                          if (($r_388 & 1) == 0) {
                            switch (*((value *) $r_388 + -1) & 255) {
                              default:
                                $c1_406 = *((value *) $r_388 + 0);
                                $l0_407 = *((value *) $r_388 + 1);
                                if (($l0_407 & 1) == 0) {
                                  switch (*((value *) $l0_407 + -1) & 255) {
                                    default:
                                      $c2_409 = *((value *) $l0_407 + 0);
                                      $rp_410 = *((value *) $l0_407 + 1);
                                      $prim_411 =
                                        ((value (*)(void)) bench_nat_zero)
                                        ();
                                      $prim_412 =
                                        ((value (*)(value, value)) bench_nat_ltb)
                                        ($prim_411, $c1_406);
                                      if (($prim_412 & 1) == 0) {
                                        switch (*((value *) $prim_412 + -1)
                                                  & 255) {
                                          
                                        }
                                      } else {
                                        switch ($prim_412 >> 1) {
                                          case 0:
                                            $prim_413 =
                                              ((value (*)(void)) bench_lit_256)
                                              ();
                                            $prim_414 =
                                              ((value (*)(value, value)) 
                                                bench_nat_mul)
                                              ($c1_406, $prim_413);
                                            $prim_415 =
                                              ((value (*)(value, value)) 
                                                bench_nat_add)
                                              ($prim_414, $c2_409);
                                            $y_416 = (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_416 + -1) = 2048;
                                            *((value *) $y_416 + 0) =
                                              $prim_415;
                                            *((value *) $y_416 + 1) =
                                              $rp_410;
                                            $y_417 = (value) ($alloc + 1);
                                            $alloc = $alloc + 2;
                                            *((value *) $y_417 + -1) = 1024;
                                            *((value *) $y_417 + 0) = $y_416;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            return $y_417;
                                            break;
                                          default:
                                            $y_418 = 1;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            return $y_418;
                                            break;
                                          
                                        }
                                      }
                                      break;
                                    
                                  }
                                } else {
                                  switch ($l0_407 >> 1) {
                                    default:
                                      $y_408 = 1;
                                      (*$tinfo).alloc = $alloc;
                                      (*$tinfo).limit = $limit;
                                      return $y_408;
                                      break;
                                    
                                  }
                                }
                                break;
                              
                            }
                          } else {
                            switch ($r_388 >> 1) {
                              default:
                                $y_405 = 1;
                                (*$tinfo).alloc = $alloc;
                                (*$tinfo).limit = $limit;
                                return $y_405;
                                break;
                              
                            }
                          }
                          break;
                        default:
                          $y_419 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_419;
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
  } else {
    switch ($s_385 >> 1) {
      default:
        $y_386 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_386;
        break;
      
    }
  }
}

value f_case_known_137(struct thread_info *$tinfo, value $s_363)
{
  struct stack_frame frame;
  value root[1];
  register value $y_364;
  register value $b_365;
  register value $r_366;
  register value $prim_367;
  register value $prim_368;
  register value $prim_369;
  register value $prim_370;
  register value $y_371;
  register value $c_372;
  register value $rp_373;
  register value $prim_374;
  register value $prim_375;
  register value $prim_376;
  register value $prim_377;
  register value $prim_378;
  register value $y_379;
  register value $y_380;
  register value $y_381;
  register value $y_382;
  register value $y_383;
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
  if (!(5 <= $limit - $alloc)) {
    *(root + 0) = $s_363;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 5;
    garbage_collect($tinfo);
    $s_363 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_363 & 1) == 0) {
    switch (*((value *) $s_363 + -1) & 255) {
      default:
        $b_365 = *((value *) $s_363 + 0);
        $r_366 = *((value *) $s_363 + 1);
        $prim_367 = ((value (*)(void)) bench_lit_31)();
        $prim_368 =
          ((value (*)(value, value)) bench_nat_land)
          ($b_365, $prim_367);
        $prim_369 = ((value (*)(void)) bench_lit_31)();
        $prim_370 =
          ((value (*)(value, value)) bench_nat_eqb)
          ($prim_368, $prim_369);
        if (($prim_370 & 1) == 0) {
          switch (*((value *) $prim_370 + -1) & 255) {
            
          }
        } else {
          switch ($prim_370 >> 1) {
            case 0:
              if (($r_366 & 1) == 0) {
                switch (*((value *) $r_366 + -1) & 255) {
                  default:
                    $c_372 = *((value *) $r_366 + 0);
                    $rp_373 = *((value *) $r_366 + 1);
                    $prim_374 = ((value (*)(void)) bench_lit_128)();
                    $prim_375 =
                      ((value (*)(value, value)) bench_nat_ltb)
                      ($c_372, $prim_374);
                    if (($prim_375 & 1) == 0) {
                      switch (*((value *) $prim_375 + -1) & 255) {
                        
                      }
                    } else {
                      switch ($prim_375 >> 1) {
                        case 0:
                          $prim_376 = ((value (*)(void)) bench_lit_256)();
                          $prim_377 =
                            ((value (*)(value, value)) bench_nat_mul)
                            ($b_365, $prim_376);
                          $prim_378 =
                            ((value (*)(value, value)) bench_nat_add)
                            ($prim_377, $c_372);
                          $y_379 = (value) ($alloc + 1);
                          $alloc = $alloc + 3;
                          *((value *) $y_379 + -1) = 2048;
                          *((value *) $y_379 + 0) = $prim_378;
                          *((value *) $y_379 + 1) = $rp_373;
                          $y_380 = (value) ($alloc + 1);
                          $alloc = $alloc + 2;
                          *((value *) $y_380 + -1) = 1024;
                          *((value *) $y_380 + 0) = $y_379;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_380;
                          break;
                        default:
                          $y_381 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_381;
                          break;
                        
                      }
                    }
                    break;
                  
                }
              } else {
                switch ($r_366 >> 1) {
                  default:
                    $y_371 = 1;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_371;
                    break;
                  
                }
              }
              break;
            default:
              $y_382 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_382 + -1) = 2048;
              *((value *) $y_382 + 0) = $b_365;
              *((value *) $y_382 + 1) = $r_366;
              $y_383 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $y_383 + -1) = 1024;
              *((value *) $y_383 + 0) = $y_382;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_383;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($s_363 >> 1) {
      default:
        $y_364 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_364;
        break;
      
    }
  }
}

value y_known_136(struct thread_info *$tinfo, value $f_318, value $l_319)
{
  struct stack_frame frame;
  value root[5];
  register value $y_321;
  register value $p_322;
  register value $tg_323;
  register value $r1_324;
  register value $y_326;
  register value $p_327;
  register value $n_328;
  register value $r2_329;
  register value $env_330;
  register value $env_331;
  register value $y_wrapper_clo_332;
  register value $y_wrapper_clo_333;
  register value $prim_334;
  register value $p_335;
  register value $v_336;
  register value $rest_337;
  register value $prim_339;
  register value $prim_340;
  register value $y_341;
  register value $prim_342;
  register value $prim_343;
  register value $prim_344;
  register value $prim_345;
  register value $env_346;
  register value $env_347;
  register value $y_wrapper_clo_348;
  register value $y_wrapper_clo_349;
  register value $prim_350;
  register value $ks_351;
  register value $y_352;
  register value $y_353;
  register value $y_354;
  register value $y_355;
  register value $y_356;
  register value $y_357;
  register value $y_358;
  register value $y_359;
  register value $y_360;
  register value $y_361;
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
  *(root + 0) = $f_318;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $y_321 =
    ((value (*)(struct thread_info *, value)) f_case_known_137)
    ($tinfo, $l_319);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $f_318 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_321 & 1) == 0) {
    switch (*((value *) $y_321 + -1) & 255) {
      default:
        $p_322 = *((value *) $y_321 + 0);
        if (($p_322 & 1) == 0) {
          switch (*((value *) $p_322 + -1) & 255) {
            default:
              $tg_323 = *((value *) $p_322 + 0);
              $r1_324 = *((value *) $p_322 + 1);
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 1) = $tg_323;
              *(root + 0) = $f_318;
              frame.next = root + 2;
              (*$tinfo).fp = &frame;
              $y_326 =
                ((value (*)(struct thread_info *, value)) f_case_known_138)
                ($tinfo, $r1_324);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              if (!(10 <= $limit - $alloc)) {
                *(root + 2) = $y_326;
                frame.next = root + 3;
                (*$tinfo).nalloc = 10;
                garbage_collect($tinfo);
                $y_326 = *(root + 2);
                $alloc = (*$tinfo).alloc;
                $limit = (*$tinfo).limit;
              }
              $tg_323 = *(root + 1);
              $f_318 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              if (($y_326 & 1) == 0) {
                switch (*((value *) $y_326 + -1) & 255) {
                  default:
                    $p_327 = *((value *) $y_326 + 0);
                    if (($p_327 & 1) == 0) {
                      switch (*((value *) $p_327 + -1) & 255) {
                        default:
                          $n_328 = *((value *) $p_327 + 0);
                          $r2_329 = *((value *) $p_327 + 1);
                          $env_330 = (value) ($alloc + 1);
                          $alloc = $alloc + 2;
                          *((value *) $env_330 + -1) = 1024;
                          *((value *) $env_330 + 0) = $r2_329;
                          $env_331 = (value) ($alloc + 1);
                          $alloc = $alloc + 2;
                          *((value *) $env_331 + -1) = 1024;
                          *((value *) $env_331 + 0) = $r2_329;
                          $y_wrapper_clo_332 = (value) ($alloc + 1);
                          $alloc = $alloc + 3;
                          *((value *) $y_wrapper_clo_332 + -1) = 2048;
                          *((value *) $y_wrapper_clo_332 + 0) =
                            y_wrapper_123;
                          *((value *) $y_wrapper_clo_332 + 1) = $env_330;
                          $y_wrapper_clo_333 = (value) ($alloc + 1);
                          $alloc = $alloc + 3;
                          *((value *) $y_wrapper_clo_333 + -1) = 2048;
                          *((value *) $y_wrapper_clo_333 + 0) =
                            y_wrapper_125;
                          *((value *) $y_wrapper_clo_333 + 1) = $env_331;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          *(root + 1) = $tg_323;
                          *(root + 0) = $f_318;
                          frame.next = root + 2;
                          (*$tinfo).fp = &frame;
                          $prim_334 =
                            ((value (*)(struct thread_info *, value, value, value)) 
                              bench_nat_case)
                            ($tinfo, $n_328, $y_wrapper_clo_332,
                             $y_wrapper_clo_333);
                          $alloc = (*$tinfo).alloc;
                          $limit = (*$tinfo).limit;
                          $tg_323 = *(root + 1);
                          $f_318 = *(root + 0);
                          (*$tinfo).fp = frame.prev;
                          if (($prim_334 & 1) == 0) {
                            switch (*((value *) $prim_334 + -1) & 255) {
                              default:
                                $p_335 = *((value *) $prim_334 + 0);
                                if (($p_335 & 1) == 0) {
                                  switch (*((value *) $p_335 + -1) & 255) {
                                    default:
                                      $v_336 = *((value *) $p_335 + 0);
                                      $rest_337 = *((value *) $p_335 + 1);
                                      $prim_339 =
                                        ((value (*)(void)) bench_lit_256)
                                        ();
                                      $prim_340 =
                                        ((value (*)(value, value)) bench_nat_ltb)
                                        ($tg_323, $prim_339);
                                      $args = (*$tinfo).args;
                                      (*$tinfo).alloc = $alloc;
                                      (*$tinfo).limit = $limit;
                                      *(root + 3) = $rest_337;
                                      *(root + 2) = $v_336;
                                      *(root + 1) = $tg_323;
                                      *(root + 0) = $f_318;
                                      frame.next = root + 4;
                                      (*$tinfo).fp = &frame;
                                      $y_341 =
                                        ((value (*)(struct thread_info *, value, value)) 
                                          f_case_known_139)
                                        ($tinfo, $prim_340, $tg_323);
                                      $alloc = (*$tinfo).alloc;
                                      $limit = (*$tinfo).limit;
                                      if (!(16 <= $limit - $alloc)) {
                                        *(root + 4) = $y_341;
                                        frame.next = root + 5;
                                        (*$tinfo).nalloc = 16;
                                        garbage_collect($tinfo);
                                        $y_341 = *(root + 4);
                                        $alloc = (*$tinfo).alloc;
                                        $limit = (*$tinfo).limit;
                                      }
                                      $rest_337 = *(root + 3);
                                      $v_336 = *(root + 2);
                                      $tg_323 = *(root + 1);
                                      $f_318 = *(root + 0);
                                      (*$tinfo).fp = frame.prev;
                                      $prim_342 =
                                        ((value (*)(void)) bench_lit_32)
                                        ();
                                      $prim_343 =
                                        ((value (*)(value, value)) bench_nat_land)
                                        ($y_341, $prim_342);
                                      $prim_344 =
                                        ((value (*)(void)) bench_lit_32)
                                        ();
                                      $prim_345 =
                                        ((value (*)(value, value)) bench_nat_eqb)
                                        ($prim_343, $prim_344);
                                      if (($prim_345 & 1) == 0) {
                                        switch (*((value *) $prim_345 + -1)
                                                  & 255) {
                                          
                                        }
                                      } else {
                                        switch ($prim_345 >> 1) {
                                          case 0:
                                            $env_346 = 1;
                                            $env_347 = (value) ($alloc + 1);
                                            $alloc = $alloc + 2;
                                            *((value *) $env_347 + -1) =
                                              1024;
                                            *((value *) $env_347 + 0) =
                                              $v_336;
                                            $y_wrapper_clo_348 =
                                              (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_wrapper_clo_348
                                               + -1) =
                                              2048;
                                            *((value *) $y_wrapper_clo_348
                                               + 0) =
                                              y_wrapper_132;
                                            *((value *) $y_wrapper_clo_348
                                               + 1) =
                                              $env_346;
                                            $y_wrapper_clo_349 =
                                              (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_wrapper_clo_349
                                               + -1) =
                                              2048;
                                            *((value *) $y_wrapper_clo_349
                                               + 0) =
                                              y_wrapper_134;
                                            *((value *) $y_wrapper_clo_349
                                               + 1) =
                                              $env_347;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            *(root + 1) = $rest_337;
                                            *(root + 0) = $tg_323;
                                            frame.next = root + 2;
                                            (*$tinfo).fp = &frame;
                                            $prim_350 =
                                              ((value (*)(struct thread_info *, value, value, value)) 
                                                bench_nat_case)
                                              ($tinfo, $f_318,
                                               $y_wrapper_clo_348,
                                               $y_wrapper_clo_349);
                                            $alloc = (*$tinfo).alloc;
                                            $limit = (*$tinfo).limit;
                                            if (!(8 <= $limit - $alloc)) {
                                              *(root + 2) = $prim_350;
                                              frame.next = root + 3;
                                              (*$tinfo).nalloc = 8;
                                              garbage_collect($tinfo);
                                              $prim_350 = *(root + 2);
                                              $alloc = (*$tinfo).alloc;
                                              $limit = (*$tinfo).limit;
                                            }
                                            $rest_337 = *(root + 1);
                                            $tg_323 = *(root + 0);
                                            (*$tinfo).fp = frame.prev;
                                            if (($prim_350 & 1) == 0) {
                                              switch (*((value *) $prim_350
                                                         + -1) & 255) {
                                                default:
                                                  $ks_351 =
                                                    *((value *) $prim_350
                                                       + 0);
                                                  $y_352 =
                                                    (value) ($alloc + 1);
                                                  $alloc = $alloc + 3;
                                                  *((value *) $y_352 + -1) =
                                                    2049;
                                                  *((value *) $y_352 + 0) =
                                                    $tg_323;
                                                  *((value *) $y_352 + 1) =
                                                    $ks_351;
                                                  $y_353 =
                                                    (value) ($alloc + 1);
                                                  $alloc = $alloc + 3;
                                                  *((value *) $y_353 + -1) =
                                                    2048;
                                                  *((value *) $y_353 + 0) =
                                                    $y_352;
                                                  *((value *) $y_353 + 1) =
                                                    $rest_337;
                                                  $y_354 =
                                                    (value) ($alloc + 1);
                                                  $alloc = $alloc + 2;
                                                  *((value *) $y_354 + -1) =
                                                    1024;
                                                  *((value *) $y_354 + 0) =
                                                    $y_353;
                                                  (*$tinfo).alloc = $alloc;
                                                  (*$tinfo).limit = $limit;
                                                  return $y_354;
                                                  break;
                                                
                                              }
                                            } else {
                                              switch ($prim_350 >> 1) {
                                                default:
                                                  $y_355 = 1;
                                                  (*$tinfo).alloc = $alloc;
                                                  (*$tinfo).limit = $limit;
                                                  return $y_355;
                                                  break;
                                                
                                              }
                                            }
                                            break;
                                          default:
                                            $y_356 = (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_356 + -1) = 2048;
                                            *((value *) $y_356 + 0) =
                                              $tg_323;
                                            *((value *) $y_356 + 1) = $v_336;
                                            $y_357 = (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_357 + -1) = 2048;
                                            *((value *) $y_357 + 0) = $y_356;
                                            *((value *) $y_357 + 1) =
                                              $rest_337;
                                            $y_358 = (value) ($alloc + 1);
                                            $alloc = $alloc + 2;
                                            *((value *) $y_358 + -1) = 1024;
                                            *((value *) $y_358 + 0) = $y_357;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            return $y_358;
                                            break;
                                          
                                        }
                                      }
                                      break;
                                    
                                  }
                                } else {
                                  switch ($p_335 >> 1) {
                                    
                                  }
                                }
                                break;
                              
                            }
                          } else {
                            switch ($prim_334 >> 1) {
                              default:
                                $y_359 = 1;
                                (*$tinfo).alloc = $alloc;
                                (*$tinfo).limit = $limit;
                                return $y_359;
                                break;
                              
                            }
                          }
                          break;
                        
                      }
                    } else {
                      switch ($p_327 >> 1) {
                        
                      }
                    }
                    break;
                  
                }
              } else {
                switch ($y_326 >> 1) {
                  default:
                    $y_360 = 1;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_360;
                    break;
                  
                }
              }
              break;
            
          }
        } else {
          switch ($p_322 >> 1) {
            
          }
        }
        break;
      
    }
  } else {
    switch ($y_321 >> 1) {
      default:
        $y_361 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_361;
        break;
      
    }
  }
}

value y_wrapper_135(struct thread_info *$tinfo, value $env_314, value $anon_315)
{
  struct stack_frame frame;
  value root[0];
  register value $y_316;
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
  $y_316 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_316;
}

value y_wrapper_134(struct thread_info *$tinfo, value $env_310, value $f_311)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_313;
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
  $l_proj_313 = *((value *) $env_310 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_133)
    ($tinfo, $f_311, $l_proj_313);
  return $result;
}

value y_known_133(struct thread_info *$tinfo, value $f_288, value $l_289)
{
  struct stack_frame frame;
  value root[2];
  register value $y_290;
  register value $y_291;
  register value $env_292;
  register value $env_293;
  register value $y_wrapper_clo_294;
  register value $y_wrapper_clo_295;
  register value $prim_296;
  register value $p_297;
  register value $t_298;
  register value $rest_299;
  register value $env_300;
  register value $env_301;
  register value $y_wrapper_clo_302;
  register value $y_wrapper_clo_303;
  register value $prim_304;
  register value $ts_305;
  register value $y_306;
  register value $y_307;
  register value $y_308;
  register value $y_309;
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
    *(root + 1) = $l_289;
    *(root + 0) = $f_288;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 21;
    garbage_collect($tinfo);
    $l_289 = *(root + 1);
    $f_288 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_289 & 1) == 0) {
    switch (*((value *) $l_289 + -1) & 255) {
      default:
        $env_292 = 1;
        $env_293 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_293 + -1) = 1024;
        *((value *) $env_293 + 0) = $l_289;
        $y_wrapper_clo_294 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_294 + -1) = 2048;
        *((value *) $y_wrapper_clo_294 + 0) = y_wrapper_135;
        *((value *) $y_wrapper_clo_294 + 1) = $env_292;
        $y_wrapper_clo_295 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_295 + -1) = 2048;
        *((value *) $y_wrapper_clo_295 + 0) = y_wrapper_140;
        *((value *) $y_wrapper_clo_295 + 1) = $env_293;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $f_288;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_296 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $f_288, $y_wrapper_clo_294, $y_wrapper_clo_295);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(13 <= $limit - $alloc)) {
          *(root + 1) = $prim_296;
          frame.next = root + 2;
          (*$tinfo).nalloc = 13;
          garbage_collect($tinfo);
          $prim_296 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $f_288 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_296 & 1) == 0) {
          switch (*((value *) $prim_296 + -1) & 255) {
            default:
              $p_297 = *((value *) $prim_296 + 0);
              if (($p_297 & 1) == 0) {
                switch (*((value *) $p_297 + -1) & 255) {
                  default:
                    $t_298 = *((value *) $p_297 + 0);
                    $rest_299 = *((value *) $p_297 + 1);
                    $env_300 = 1;
                    $env_301 = (value) ($alloc + 1);
                    $alloc = $alloc + 2;
                    *((value *) $env_301 + -1) = 1024;
                    *((value *) $env_301 + 0) = $rest_299;
                    $y_wrapper_clo_302 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_302 + -1) = 2048;
                    *((value *) $y_wrapper_clo_302 + 0) = y_wrapper_132;
                    *((value *) $y_wrapper_clo_302 + 1) = $env_300;
                    $y_wrapper_clo_303 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_wrapper_clo_303 + -1) = 2048;
                    *((value *) $y_wrapper_clo_303 + 0) = y_wrapper_134;
                    *((value *) $y_wrapper_clo_303 + 1) = $env_301;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    *(root + 0) = $t_298;
                    frame.next = root + 1;
                    (*$tinfo).fp = &frame;
                    $prim_304 =
                      ((value (*)(struct thread_info *, value, value, value)) 
                        bench_nat_case)
                      ($tinfo, $f_288, $y_wrapper_clo_302, $y_wrapper_clo_303);
                    $alloc = (*$tinfo).alloc;
                    $limit = (*$tinfo).limit;
                    if (!(5 <= $limit - $alloc)) {
                      *(root + 1) = $prim_304;
                      frame.next = root + 2;
                      (*$tinfo).nalloc = 5;
                      garbage_collect($tinfo);
                      $prim_304 = *(root + 1);
                      $alloc = (*$tinfo).alloc;
                      $limit = (*$tinfo).limit;
                    }
                    $t_298 = *(root + 0);
                    (*$tinfo).fp = frame.prev;
                    if (($prim_304 & 1) == 0) {
                      switch (*((value *) $prim_304 + -1) & 255) {
                        default:
                          $ts_305 = *((value *) $prim_304 + 0);
                          $y_306 = (value) ($alloc + 1);
                          $alloc = $alloc + 3;
                          *((value *) $y_306 + -1) = 2048;
                          *((value *) $y_306 + 0) = $t_298;
                          *((value *) $y_306 + 1) = $ts_305;
                          $y_307 = (value) ($alloc + 1);
                          $alloc = $alloc + 2;
                          *((value *) $y_307 + -1) = 1024;
                          *((value *) $y_307 + 0) = $y_306;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_307;
                          break;
                        
                      }
                    } else {
                      switch ($prim_304 >> 1) {
                        default:
                          $y_308 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_308;
                          break;
                        
                      }
                    }
                    break;
                  
                }
              } else {
                switch ($p_297 >> 1) {
                  
                }
              }
              break;
            
          }
        } else {
          switch ($prim_296 >> 1) {
            default:
              $y_309 = 1;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_309;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($l_289 >> 1) {
      default:
        $y_290 = 1;
        $y_291 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $y_291 + -1) = 1024;
        *((value *) $y_291 + 0) = $y_290;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_291;
        break;
      
    }
  }
}

value y_wrapper_132(struct thread_info *$tinfo, value $env_284, value $anon_285)
{
  struct stack_frame frame;
  value root[0];
  register value $y_286;
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
  $y_286 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_286;
}

value f_case_known_131(struct thread_info *$tinfo, value $s_240)
{
  struct stack_frame frame;
  value root[5];
  register value $y_241;
  register value $c_242;
  register value $l0_243;
  register value $y_244;
  register value $i_245;
  register value $l1_246;
  register value $y_247;
  register value $a_248;
  register value $l2_249;
  register value $y_250;
  register value $b_251;
  register value $body_252;
  register value $y_253;
  register value $y_254;
  register value $y_255;
  register value $y_256;
  register value $lc_257;
  register value $rest_258;
  register value $y_259;
  register value $y_260;
  register value $y_261;
  register value $y_262;
  register value $prim_263;
  register value $prim_264;
  register value $y_265;
  register value $env_266;
  register value $env_267;
  register value $y_wrapper_clo_268;
  register value $y_wrapper_clo_269;
  register value $prim_270;
  register value $p_271;
  register value $d_272;
  register value $l0_273;
  register value $y_274;
  register value $y_275;
  register value $y_276;
  register value $e_277;
  register value $l1_278;
  register value $y_279;
  register value $y_280;
  register value $y_281;
  register value $y_282;
  register value $y_283;
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
    *(root + 0) = $s_240;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 21;
    garbage_collect($tinfo);
    $s_240 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($s_240 & 1) == 0) {
    switch (*((value *) $s_240 + -1) & 255) {
      default:
        $c_242 = *((value *) $s_240 + 0);
        $l0_243 = *((value *) $s_240 + 1);
        if (($l0_243 & 1) == 0) {
          switch (*((value *) $l0_243 + -1) & 255) {
            default:
              $i_245 = *((value *) $l0_243 + 0);
              $l1_246 = *((value *) $l0_243 + 1);
              if (($l1_246 & 1) == 0) {
                switch (*((value *) $l1_246 + -1) & 255) {
                  default:
                    $a_248 = *((value *) $l1_246 + 0);
                    $l2_249 = *((value *) $l1_246 + 1);
                    if (($l2_249 & 1) == 0) {
                      switch (*((value *) $l2_249 + -1) & 255) {
                        default:
                          $b_251 = *((value *) $l2_249 + 0);
                          $body_252 = *((value *) $l2_249 + 1);
                          if (($body_252 & 1) == 0) {
                            switch (*((value *) $body_252 + -1) & 255) {
                              default:
                                $lc_257 = *((value *) $body_252 + 0);
                                $rest_258 = *((value *) $body_252 + 1);
                                if (($rest_258 & 1) == 0) {
                                  switch (*((value *) $rest_258 + -1) & 255) {
                                    default:
                                      $prim_263 =
                                        ((value (*)(void)) bench_nat_zero)
                                        ();
                                      $prim_264 =
                                        ((value (*)(value, value)) bench_nat_eqb)
                                        ($lc_257, $prim_263);
                                      if (($prim_264 & 1) == 0) {
                                        switch (*((value *) $prim_264 + -1)
                                                  & 255) {
                                          
                                        }
                                      } else {
                                        switch ($prim_264 >> 1) {
                                          case 0:
                                            $y_265 = 1;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            return $y_265;
                                            break;
                                          default:
                                            $env_266 = (value) ($alloc + 1);
                                            $alloc = $alloc + 2;
                                            *((value *) $env_266 + -1) =
                                              1024;
                                            *((value *) $env_266 + 0) =
                                              $rest_258;
                                            $env_267 = (value) ($alloc + 1);
                                            $alloc = $alloc + 2;
                                            *((value *) $env_267 + -1) =
                                              1024;
                                            *((value *) $env_267 + 0) =
                                              $rest_258;
                                            $y_wrapper_clo_268 =
                                              (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_wrapper_clo_268
                                               + -1) =
                                              2048;
                                            *((value *) $y_wrapper_clo_268
                                               + 0) =
                                              y_wrapper_123;
                                            *((value *) $y_wrapper_clo_268
                                               + 1) =
                                              $env_266;
                                            $y_wrapper_clo_269 =
                                              (value) ($alloc + 1);
                                            $alloc = $alloc + 3;
                                            *((value *) $y_wrapper_clo_269
                                               + -1) =
                                              2048;
                                            *((value *) $y_wrapper_clo_269
                                               + 0) =
                                              y_wrapper_125;
                                            *((value *) $y_wrapper_clo_269
                                               + 1) =
                                              $env_267;
                                            (*$tinfo).alloc = $alloc;
                                            (*$tinfo).limit = $limit;
                                            *(root + 3) = $b_251;
                                            *(root + 2) = $a_248;
                                            *(root + 1) = $i_245;
                                            *(root + 0) = $c_242;
                                            frame.next = root + 4;
                                            (*$tinfo).fp = &frame;
                                            $prim_270 =
                                              ((value (*)(struct thread_info *, value, value, value)) 
                                                bench_nat_case)
                                              ($tinfo, $lc_257,
                                               $y_wrapper_clo_268,
                                               $y_wrapper_clo_269);
                                            $alloc = (*$tinfo).alloc;
                                            $limit = (*$tinfo).limit;
                                            if (!(11 <= $limit - $alloc)) {
                                              *(root + 4) = $prim_270;
                                              frame.next = root + 5;
                                              (*$tinfo).nalloc = 11;
                                              garbage_collect($tinfo);
                                              $prim_270 = *(root + 4);
                                              $alloc = (*$tinfo).alloc;
                                              $limit = (*$tinfo).limit;
                                            }
                                            $b_251 = *(root + 3);
                                            $a_248 = *(root + 2);
                                            $i_245 = *(root + 1);
                                            $c_242 = *(root + 0);
                                            (*$tinfo).fp = frame.prev;
                                            if (($prim_270 & 1) == 0) {
                                              switch (*((value *) $prim_270
                                                         + -1) & 255) {
                                                default:
                                                  $p_271 =
                                                    *((value *) $prim_270
                                                       + 0);
                                                  if (($p_271 & 1) == 0) {
                                                    switch (*((value *) 
                                                                $p_271 + 
                                                               -1) & 
                                                              255) {
                                                      default:
                                                        $d_272 =
                                                          *((value *) $p_271
                                                             + 0);
                                                        $l0_273 =
                                                          *((value *) $p_271
                                                             + 1);
                                                        if (($l0_273 & 1)
                                                              == 0) {
                                                          switch (*((value *) 
                                                                    $l0_273
                                                                    + 
                                                                    -1) & 
                                                                    255) {
                                                            default:
                                                              $e_277 =
                                                                *((value *) 
                                                                    $l0_273
                                                                   + 
                                                                   0);
                                                              $l1_278 =
                                                                *((value *) 
                                                                    $l0_273
                                                                   + 
                                                                   1);
                                                              if (($l1_278
                                                                    & 
                                                                    1) == 
                                                                    0) {
                                                                switch (
                                                                  *((value *) 
                                                                    $l1_278
                                                                    + 
                                                                    -1) & 
                                                                    255) {
                                                                  default:
                                                                    $y_282 =
                                                                    1;
                                                                    (*$tinfo).alloc =
                                                                    $alloc;
                                                                    (*$tinfo).limit =
                                                                    $limit;
                                                                    return 
                                                                    $y_282;
                                                                    break;
                                                                  
                                                                }
                                                              } else {
                                                                switch (
                                                                  $l1_278
                                                                    >> 
                                                                    1) {
                                                                  default:
                                                                    $y_279 =
                                                                    (value) 
                                                                    ($alloc
                                                                    + 1);
                                                                    $alloc =
                                                                    $alloc
                                                                    + 2;
                                                                    *((value *) 
                                                                    $y_279
                                                                    + -1) =
                                                                    1024;
                                                                    *((value *) 
                                                                    $y_279
                                                                    + 0) =
                                                                    $e_277;
                                                                    $y_280 =
                                                                    (value) 
                                                                    ($alloc
                                                                    + 1);
                                                                    $alloc =
                                                                    $alloc
                                                                    + 7;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + -1) =
                                                                    6144;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 0) =
                                                                    $c_242;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 1) =
                                                                    $i_245;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 2) =
                                                                    $a_248;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 3) =
                                                                    $b_251;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 4) =
                                                                    $d_272;
                                                                    *((value *) 
                                                                    $y_280
                                                                    + 5) =
                                                                    $y_279;
                                                                    $y_281 =
                                                                    (value) 
                                                                    ($alloc
                                                                    + 1);
                                                                    $alloc =
                                                                    $alloc
                                                                    + 2;
                                                                    *((value *) 
                                                                    $y_281
                                                                    + -1) =
                                                                    1024;
                                                                    *((value *) 
                                                                    $y_281
                                                                    + 0) =
                                                                    $y_280;
                                                                    (*$tinfo).alloc =
                                                                    $alloc;
                                                                    (*$tinfo).limit =
                                                                    $limit;
                                                                    return 
                                                                    $y_281;
                                                                    break;
                                                                  
                                                                }
                                                              }
                                                              break;
                                                            
                                                          }
                                                        } else {
                                                          switch ($l0_273
                                                                    >> 
                                                                    1) {
                                                            default:
                                                              $y_274 = 1;
                                                              $y_275 =
                                                                (value) 
                                                                  ($alloc
                                                                    + 
                                                                    1);
                                                              $alloc =
                                                                $alloc + 7;
                                                              *((value *) 
                                                                  $y_275
                                                                 + -1) =
                                                                6144;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 0) =
                                                                $c_242;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 1) =
                                                                $i_245;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 2) =
                                                                $a_248;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 3) =
                                                                $b_251;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 4) =
                                                                $d_272;
                                                              *((value *) 
                                                                  $y_275 + 
                                                                 5) =
                                                                $y_274;
                                                              $y_276 =
                                                                (value) 
                                                                  ($alloc
                                                                    + 
                                                                    1);
                                                              $alloc =
                                                                $alloc + 2;
                                                              *((value *) 
                                                                  $y_276
                                                                 + -1) =
                                                                1024;
                                                              *((value *) 
                                                                  $y_276 + 
                                                                 0) =
                                                                $y_275;
                                                              (*$tinfo).alloc =
                                                                $alloc;
                                                              (*$tinfo).limit =
                                                                $limit;
                                                              return 
                                                              $y_276;
                                                              break;
                                                            
                                                          }
                                                        }
                                                        break;
                                                      
                                                    }
                                                  } else {
                                                    switch ($p_271 >> 1) {
                                                      
                                                    }
                                                  }
                                                  break;
                                                
                                              }
                                            } else {
                                              switch ($prim_270 >> 1) {
                                                default:
                                                  $y_283 = 1;
                                                  (*$tinfo).alloc = $alloc;
                                                  (*$tinfo).limit = $limit;
                                                  return $y_283;
                                                  break;
                                                
                                              }
                                            }
                                            break;
                                          
                                        }
                                      }
                                      break;
                                    
                                  }
                                } else {
                                  switch ($rest_258 >> 1) {
                                    default:
                                      $y_259 = 1;
                                      $y_260 = (value) ($alloc + 1);
                                      $alloc = $alloc + 2;
                                      *((value *) $y_260 + -1) = 1024;
                                      *((value *) $y_260 + 0) = $lc_257;
                                      $y_261 = (value) ($alloc + 1);
                                      $alloc = $alloc + 7;
                                      *((value *) $y_261 + -1) = 6144;
                                      *((value *) $y_261 + 0) = $c_242;
                                      *((value *) $y_261 + 1) = $i_245;
                                      *((value *) $y_261 + 2) = $a_248;
                                      *((value *) $y_261 + 3) = $b_251;
                                      *((value *) $y_261 + 4) = $y_259;
                                      *((value *) $y_261 + 5) = $y_260;
                                      $y_262 = (value) ($alloc + 1);
                                      $alloc = $alloc + 2;
                                      *((value *) $y_262 + -1) = 1024;
                                      *((value *) $y_262 + 0) = $y_261;
                                      (*$tinfo).alloc = $alloc;
                                      (*$tinfo).limit = $limit;
                                      return $y_262;
                                      break;
                                    
                                  }
                                }
                                break;
                              
                            }
                          } else {
                            switch ($body_252 >> 1) {
                              default:
                                $y_253 = 1;
                                $y_254 = 1;
                                $y_255 = (value) ($alloc + 1);
                                $alloc = $alloc + 7;
                                *((value *) $y_255 + -1) = 6144;
                                *((value *) $y_255 + 0) = $c_242;
                                *((value *) $y_255 + 1) = $i_245;
                                *((value *) $y_255 + 2) = $a_248;
                                *((value *) $y_255 + 3) = $b_251;
                                *((value *) $y_255 + 4) = $y_253;
                                *((value *) $y_255 + 5) = $y_254;
                                $y_256 = (value) ($alloc + 1);
                                $alloc = $alloc + 2;
                                *((value *) $y_256 + -1) = 1024;
                                *((value *) $y_256 + 0) = $y_255;
                                (*$tinfo).alloc = $alloc;
                                (*$tinfo).limit = $limit;
                                return $y_256;
                                break;
                              
                            }
                          }
                          break;
                        
                      }
                    } else {
                      switch ($l2_249 >> 1) {
                        default:
                          $y_250 = 1;
                          (*$tinfo).alloc = $alloc;
                          (*$tinfo).limit = $limit;
                          return $y_250;
                          break;
                        
                      }
                    }
                    break;
                  
                }
              } else {
                switch ($l1_246 >> 1) {
                  default:
                    $y_247 = 1;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_247;
                    break;
                  
                }
              }
              break;
            
          }
        } else {
          switch ($l0_243 >> 1) {
            default:
              $y_244 = 1;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_244;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($s_240 >> 1) {
      default:
        $y_241 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_241;
        break;
      
    }
  }
}

value y_wrapper_130(struct thread_info *$tinfo, value $env_228, value $np_229)
{
  struct stack_frame frame;
  value root[2];
  register value $pos_proj_230;
  register value $prim_231;
  register value $prim_232;
  register value $env_233;
  register value $env_234;
  register value $y_wrapper_clo_235;
  register value $y_wrapper_clo_236;
  register value $prim_237;
  register value $y_238;
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
    *(root + 1) = $np_229;
    *(root + 0) = $env_228;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $np_229 = *(root + 1);
    $env_228 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_proj_230 = *((value *) $env_228 + 0);
  $prim_231 = ((value (*)(value)) bench_input_byte)($pos_proj_230);
  $prim_232 = ((value (*)(value)) bench_nat_succ)($pos_proj_230);
  $env_233 = 1;
  $env_234 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_234 + -1) = 1024;
  *((value *) $env_234 + 0) = $prim_232;
  $y_wrapper_clo_235 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_235 + -1) = 2048;
  *((value *) $y_wrapper_clo_235 + 0) = y_wrapper_129;
  *((value *) $y_wrapper_clo_235 + 1) = $env_233;
  $y_wrapper_clo_236 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_236 + -1) = 2048;
  *((value *) $y_wrapper_clo_236 + 0) = y_wrapper_130;
  *((value *) $y_wrapper_clo_236 + 1) = $env_234;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $prim_231;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_237 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $np_229, $y_wrapper_clo_235, $y_wrapper_clo_236);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_237;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_237 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_231 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_238 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_238 + -1) = 2048;
  *((value *) $y_238 + 0) = $prim_231;
  *((value *) $y_238 + 1) = $prim_237;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_238;
}

value y_wrapper_129(struct thread_info *$tinfo, value $env_225, value $anon_226)
{
  struct stack_frame frame;
  value root[0];
  register value $y_227;
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
  $y_227 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_227;
}

value EncoreBenchdW1dApdudrun_known_128(struct thread_info *$tinfo, value $n_184)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_185;
  register value $env_186;
  register value $env_187;
  register value $y_wrapper_clo_188;
  register value $y_wrapper_clo_189;
  register value $prim_190;
  register value $y_192;
  register value $x_193;
  register value $y_195;
  register value $y_197;
  register value $prim_198;
  register value $y_200;
  register value $env_201;
  register value $env_202;
  register value $y_wrapper_clo_203;
  register value $y_wrapper_clo_204;
  register value $prim_205;
  register value $ts_206;
  register value $prim_207;
  register value $y_209;
  register value $prim_210;
  register value $y_211;
  register value $y_213;
  register value $y_214;
  register value $y_215;
  register value $prim_216;
  register value $prim_217;
  register value $prim_218;
  register value $y_219;
  register value $y_220;
  register value $prim_221;
  register value $prim_222;
  register value $y_223;
  register value $y_224;
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
    *(root + 0) = $n_184;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $n_184 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_185 = ((value (*)(void)) bench_nat_zero)();
  $env_186 = 1;
  $env_187 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_187 + -1) = 1024;
  *((value *) $env_187 + 0) = $prim_185;
  $y_wrapper_clo_188 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_188 + -1) = 2048;
  *((value *) $y_wrapper_clo_188 + 0) = y_wrapper_129;
  *((value *) $y_wrapper_clo_188 + 1) = $env_186;
  $y_wrapper_clo_189 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_189 + -1) = 2048;
  *((value *) $y_wrapper_clo_189 + 0) = y_wrapper_130;
  *((value *) $y_wrapper_clo_189 + 1) = $env_187;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_190 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_184, $y_wrapper_clo_188, $y_wrapper_clo_189);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $y_192 =
    ((value (*)(struct thread_info *, value)) f_case_known_131)
    ($tinfo, $prim_190);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 0) = $y_192;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $y_192 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  /*skip*/;
  if (($y_192 & 1) == 0) {
    switch (*((value *) $y_192 + -1) & 255) {
      default:
        $x_193 = *((value *) $y_192 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_193;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_195 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW1dApduddata_known_127)
          ($tinfo, $x_193);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $x_193 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_193;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_197 =
          ((value (*)(struct thread_info *, value)) length_known_126)
          ($tinfo, $y_195);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $x_193 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_198 = ((value (*)(value)) bench_nat_succ)($y_197);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $prim_198;
        *(root + 0) = $x_193;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_200 =
          ((value (*)(struct thread_info *, value)) EncoreBenchdW1dApduddata_known_127)
          ($tinfo, $x_193);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(11 <= $limit - $alloc)) {
          *(root + 2) = $y_200;
          frame.next = root + 3;
          (*$tinfo).nalloc = 11;
          garbage_collect($tinfo);
          $y_200 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $prim_198 = *(root + 1);
        $x_193 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $env_201 = 1;
        $env_202 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_202 + -1) = 1024;
        *((value *) $env_202 + 0) = $y_200;
        $y_wrapper_clo_203 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_203 + -1) = 2048;
        *((value *) $y_wrapper_clo_203 + 0) = y_wrapper_132;
        *((value *) $y_wrapper_clo_203 + 1) = $env_201;
        $y_wrapper_clo_204 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_204 + -1) = 2048;
        *((value *) $y_wrapper_clo_204 + 0) = y_wrapper_134;
        *((value *) $y_wrapper_clo_204 + 1) = $env_202;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_193;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_205 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_198, $y_wrapper_clo_203, $y_wrapper_clo_204);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 1) = $prim_205;
          frame.next = root + 2;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $prim_205 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $x_193 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_205 & 1) == 0) {
          switch (*((value *) $prim_205 + -1) & 255) {
            default:
              $ts_206 = *((value *) $prim_205 + 0);
              $prim_207 = ((value (*)(void)) bench_nat_zero)();
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 1) = $prim_207;
              *(root + 0) = $ts_206;
              frame.next = root + 2;
              (*$tinfo).fp = &frame;
              $y_209 =
                ((value (*)(struct thread_info *, value)) f_case_known_141)
                ($tinfo, $x_193);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              $prim_207 = *(root + 1);
              $ts_206 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $prim_210 = ((value (*)(void)) bench_nat_zero)();
              $y_211 = 1;
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 1) = $y_209;
              *(root + 0) = $prim_207;
              frame.next = root + 2;
              (*$tinfo).fp = &frame;
              $y_213 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  fold_right_known_142)
                ($tinfo, $ts_206, $prim_210, $y_211);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              if (!(6 <= $limit - $alloc)) {
                *(root + 2) = $y_213;
                frame.next = root + 3;
                (*$tinfo).nalloc = 6;
                garbage_collect($tinfo);
                $y_213 = *(root + 2);
                $alloc = (*$tinfo).alloc;
                $limit = (*$tinfo).limit;
              }
              $y_209 = *(root + 1);
              $prim_207 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $y_214 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_214 + -1) = 2048;
              *((value *) $y_214 + 0) = $y_209;
              *((value *) $y_214 + 1) = $y_213;
              $y_215 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_215 + -1) = 2048;
              *((value *) $y_215 + 0) = $prim_207;
              *((value *) $y_215 + 1) = $y_214;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_215;
              break;
            
          }
        } else {
          switch ($prim_205 >> 1) {
            default:
              $prim_216 = ((value (*)(void)) bench_nat_zero)();
              $prim_217 = ((value (*)(value)) bench_nat_succ)($prim_216);
              $prim_218 = ((value (*)(value)) bench_nat_succ)($prim_217);
              $y_219 = 1;
              $y_220 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_220 + -1) = 2048;
              *((value *) $y_220 + 0) = $prim_218;
              *((value *) $y_220 + 1) = $y_219;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_220;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($y_192 >> 1) {
      default:
        $prim_221 = ((value (*)(void)) bench_nat_zero)();
        $prim_222 = ((value (*)(value)) bench_nat_succ)($prim_221);
        $y_223 = 1;
        $y_224 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_224 + -1) = 2048;
        *((value *) $y_224 + 0) = $prim_222;
        *((value *) $y_224 + 1) = $y_223;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_224;
        break;
      
    }
  }
}

value EncoreBenchdW1dApduddata_known_127(struct thread_info *$tinfo, value $a_181)
{
  struct stack_frame frame;
  value root[1];
  register value $data_182;
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
  if (($a_181 & 1) == 0) {
    switch (*((value *) $a_181 + -1) & 255) {
      default:
        $data_182 = *((value *) $a_181 + 4);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $data_182;
        break;
      
    }
  } else {
    switch ($a_181 >> 1) {
      
    }
  }
}

value length_known_126(struct thread_info *$tinfo, value $l_175)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_176;
  register value $lp_177;
  register value $y_178;
  register value $prim_179;
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
  if (($l_175 & 1) == 0) {
    switch (*((value *) $l_175 + -1) & 255) {
      default:
        $lp_177 = *((value *) $l_175 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $y_178 =
          ((value (*)(struct thread_info *, value)) length_known_126)
          ($tinfo, $lp_177);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        $prim_179 = ((value (*)(value)) bench_nat_succ)($y_178);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_179;
        break;
      
    }
  } else {
    switch ($l_175 >> 1) {
      default:
        $prim_176 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_176;
        break;
      
    }
  }
}

value y_wrapper_125(struct thread_info *$tinfo, value $env_170, value $np_171)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_173;
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
  $l_proj_173 = *((value *) $env_170 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_124)
    ($tinfo, $np_171, $l_proj_173);
  return $result;
}

value y_known_124(struct thread_info *$tinfo, value $np_153, value $l_154)
{
  struct stack_frame frame;
  value root[2];
  register value $y_155;
  register value $x_156;
  register value $t_157;
  register value $env_158;
  register value $env_159;
  register value $y_wrapper_clo_160;
  register value $y_wrapper_clo_161;
  register value $prim_162;
  register value $p_163;
  register value $a_164;
  register value $b_165;
  register value $y_166;
  register value $y_167;
  register value $y_168;
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
  if (!(18 <= $limit - $alloc)) {
    *(root + 1) = $l_154;
    *(root + 0) = $np_153;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18;
    garbage_collect($tinfo);
    $l_154 = *(root + 1);
    $np_153 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_154 & 1) == 0) {
    switch (*((value *) $l_154 + -1) & 255) {
      default:
        $x_156 = *((value *) $l_154 + 0);
        $t_157 = *((value *) $l_154 + 1);
        $env_158 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_158 + -1) = 1024;
        *((value *) $env_158 + 0) = $t_157;
        $env_159 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_159 + -1) = 1024;
        *((value *) $env_159 + 0) = $t_157;
        $y_wrapper_clo_160 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_160 + -1) = 2048;
        *((value *) $y_wrapper_clo_160 + 0) = y_wrapper_123;
        *((value *) $y_wrapper_clo_160 + 1) = $env_158;
        $y_wrapper_clo_161 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_161 + -1) = 2048;
        *((value *) $y_wrapper_clo_161 + 0) = y_wrapper_125;
        *((value *) $y_wrapper_clo_161 + 1) = $env_159;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_156;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_162 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $np_153, $y_wrapper_clo_160, $y_wrapper_clo_161);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(8 <= $limit - $alloc)) {
          *(root + 1) = $prim_162;
          frame.next = root + 2;
          (*$tinfo).nalloc = 8;
          garbage_collect($tinfo);
          $prim_162 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $x_156 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_162 & 1) == 0) {
          switch (*((value *) $prim_162 + -1) & 255) {
            default:
              $p_163 = *((value *) $prim_162 + 0);
              if (($p_163 & 1) == 0) {
                switch (*((value *) $p_163 + -1) & 255) {
                  default:
                    $a_164 = *((value *) $p_163 + 0);
                    $b_165 = *((value *) $p_163 + 1);
                    $y_166 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_166 + -1) = 2048;
                    *((value *) $y_166 + 0) = $x_156;
                    *((value *) $y_166 + 1) = $a_164;
                    $y_167 = (value) ($alloc + 1);
                    $alloc = $alloc + 3;
                    *((value *) $y_167 + -1) = 2048;
                    *((value *) $y_167 + 0) = $y_166;
                    *((value *) $y_167 + 1) = $b_165;
                    $y_168 = (value) ($alloc + 1);
                    $alloc = $alloc + 2;
                    *((value *) $y_168 + -1) = 1024;
                    *((value *) $y_168 + 0) = $y_167;
                    (*$tinfo).alloc = $alloc;
                    (*$tinfo).limit = $limit;
                    return $y_168;
                    break;
                  
                }
              } else {
                switch ($p_163 >> 1) {
                  
                }
              }
              break;
            
          }
        } else {
          switch ($prim_162 >> 1) {
            default:
              $y_169 = 1;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_169;
              break;
            
          }
        }
        break;
      
    }
  } else {
    switch ($l_154 >> 1) {
      default:
        $y_155 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_155;
        break;
      
    }
  }
}

value y_wrapper_123(struct thread_info *$tinfo, value $env_146, value $anon_147)
{
  struct stack_frame frame;
  value root[1];
  register value $l_proj_148;
  register value $y_149;
  register value $y_150;
  register value $y_151;
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
  if (!(5 <= $limit - $alloc)) {
    *(root + 0) = $env_146;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 5;
    garbage_collect($tinfo);
    $env_146 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $l_proj_148 = *((value *) $env_146 + 0);
  $y_149 = 1;
  $y_150 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_150 + -1) = 2048;
  *((value *) $y_150 + 0) = $y_149;
  *((value *) $y_150 + 1) = $l_proj_148;
  $y_151 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $y_151 + -1) = 1024;
  *((value *) $y_151 + 0) = $y_150;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_151;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
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
  register value $prim_783;
  register value $prim_784;
  register value $prim_785;
  register value $prim_786;
  register value $prim_787;
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
  register value $prim_832;
  register value $prim_833;
  register value $prim_834;
  register value $prim_835;
  register value $prim_836;
  register value $prim_837;
  register value $prim_838;
  register value $prim_839;
  register value $prim_840;
  register value $prim_841;
  register value $prim_842;
  register value $prim_843;
  register value $prim_844;
  register value $prim_845;
  register value $prim_846;
  register value $prim_847;
  register value $prim_848;
  register value $prim_849;
  register value $prim_850;
  register value $prim_851;
  register value $prim_852;
  register value $prim_853;
  register value $prim_854;
  register value $prim_855;
  register value $prim_856;
  register value $prim_857;
  register value $prim_858;
  register value $prim_859;
  register value $prim_860;
  register value $prim_861;
  register value $prim_862;
  register value $prim_863;
  register value $prim_864;
  register value $prim_865;
  register value $prim_866;
  register value $prim_867;
  register value $prim_868;
  register value $prim_869;
  register value $prim_870;
  register value $prim_871;
  register value $prim_872;
  register value $prim_873;
  register value $prim_874;
  register value $prim_875;
  register value $prim_876;
  register value $prim_877;
  register value $prim_878;
  register value $prim_879;
  register value $prim_880;
  register value $prim_881;
  register value $prim_882;
  register value $prim_883;
  register value $prim_884;
  register value $prim_885;
  register value $prim_886;
  register value $prim_887;
  register value $prim_888;
  register value $prim_889;
  register value $prim_890;
  register value $prim_891;
  register value $prim_892;
  register value $prim_893;
  register value $prim_894;
  register value $prim_895;
  register value $prim_896;
  register value $prim_897;
  register value $prim_898;
  register value $prim_899;
  register value $prim_900;
  register value $prim_901;
  register value $prim_902;
  register value $prim_903;
  register value $prim_904;
  register value $prim_905;
  register value $prim_906;
  register value $prim_907;
  register value $prim_908;
  register value $prim_909;
  register value $prim_910;
  register value $prim_911;
  register value $prim_912;
  register value $prim_913;
  register value $prim_914;
  register value $prim_915;
  register value $prim_916;
  register value $prim_917;
  register value $prim_918;
  register value $prim_919;
  register value $prim_920;
  register value $prim_921;
  register value $prim_922;
  register value $prim_923;
  register value $prim_924;
  register value $prim_925;
  register value $prim_926;
  register value $prim_927;
  register value $prim_928;
  register value $prim_929;
  register value $prim_930;
  register value $prim_931;
  register value $prim_932;
  register value $prim_933;
  register value $prim_934;
  register value $prim_935;
  register value $prim_936;
  register value $prim_937;
  register value $prim_938;
  register value $prim_939;
  register value $prim_940;
  register value $prim_941;
  register value $prim_942;
  register value $prim_943;
  register value $prim_944;
  register value $prim_945;
  register value $prim_946;
  register value $prim_947;
  register value $prim_948;
  register value $prim_949;
  register value $prim_950;
  register value $prim_951;
  register value $prim_952;
  register value $prim_953;
  register value $prim_954;
  register value $prim_955;
  register value $prim_956;
  register value $prim_957;
  register value $prim_958;
  register value $prim_959;
  register value $prim_960;
  register value $prim_961;
  register value $prim_962;
  register value $prim_963;
  register value $prim_964;
  register value $prim_965;
  register value $prim_966;
  register value $prim_967;
  register value $prim_968;
  register value $prim_969;
  register value $prim_970;
  register value $prim_971;
  register value $prim_972;
  register value $prim_973;
  register value $prim_974;
  register value $prim_975;
  register value $prim_976;
  register value $prim_977;
  register value $prim_978;
  register value $prim_979;
  register value $prim_980;
  register value $prim_981;
  register value $prim_982;
  register value $prim_983;
  register value $prim_984;
  register value $prim_985;
  register value $prim_986;
  register value $prim_987;
  register value $prim_988;
  register value $prim_989;
  register value $prim_990;
  register value $prim_991;
  register value $prim_992;
  register value $prim_993;
  register value $prim_994;
  register value $prim_995;
  register value $prim_996;
  register value $prim_997;
  register value $prim_998;
  register value $prim_999;
  register value $prim_1000;
  register value $prim_1001;
  register value $prim_1002;
  register value $prim_1003;
  register value $prim_1004;
  register value $prim_1005;
  register value $prim_1006;
  register value $prim_1007;
  register value $prim_1008;
  register value $prim_1009;
  register value $prim_1010;
  register value $prim_1011;
  register value $prim_1012;
  register value $prim_1013;
  register value $prim_1014;
  register value $prim_1015;
  register value $prim_1016;
  register value $prim_1017;
  register value $prim_1018;
  register value $prim_1019;
  register value $prim_1020;
  register value $prim_1021;
  register value $prim_1022;
  register value $prim_1023;
  register value $prim_1024;
  register value $prim_1025;
  register value $prim_1026;
  register value $prim_1027;
  register value $prim_1028;
  register value $prim_1029;
  register value $prim_1030;
  register value $prim_1031;
  register value $prim_1032;
  register value $prim_1033;
  register value $prim_1034;
  register value $prim_1035;
  register value $prim_1036;
  register value $prim_1037;
  register value $prim_1038;
  register value $prim_1039;
  register value $prim_1040;
  register value $prim_1041;
  register value $prim_1042;
  register value $prim_1043;
  register value $prim_1044;
  register value $prim_1045;
  register value $prim_1046;
  register value $prim_1047;
  register value $prim_1048;
  register value $prim_1049;
  register value $prim_1050;
  register value $prim_1051;
  register value $prim_1052;
  register value $prim_1053;
  register value $prim_1054;
  register value $prim_1055;
  register value $prim_1056;
  register value $prim_1057;
  register value $prim_1058;
  register value $prim_1059;
  register value $prim_1060;
  register value $prim_1061;
  register value $prim_1062;
  register value $prim_1063;
  register value $prim_1064;
  register value $prim_1065;
  register value $prim_1066;
  register value $prim_1067;
  register value $prim_1068;
  register value $prim_1069;
  register value $prim_1070;
  register value $prim_1071;
  register value $prim_1072;
  register value $prim_1073;
  register value $prim_1074;
  register value $prim_1075;
  register value $prim_1076;
  register value $prim_1077;
  register value $prim_1078;
  register value $prim_1079;
  register value $prim_1080;
  register value $prim_1081;
  register value $prim_1082;
  register value $prim_1083;
  register value $prim_1084;
  register value $prim_1085;
  register value $prim_1086;
  register value $prim_1087;
  register value $prim_1088;
  register value $prim_1089;
  register value $prim_1090;
  register value $prim_1091;
  register value $prim_1092;
  register value $prim_1093;
  register value $prim_1094;
  register value $prim_1095;
  register value $prim_1096;
  register value $prim_1097;
  register value $prim_1098;
  register value $prim_1099;
  register value $prim_1100;
  register value $prim_1101;
  register value $prim_1102;
  register value $prim_1103;
  register value $prim_1104;
  register value $prim_1105;
  register value $prim_1106;
  register value $prim_1107;
  register value $prim_1108;
  register value $prim_1109;
  register value $prim_1110;
  register value $prim_1111;
  register value $prim_1112;
  register value $prim_1113;
  register value $prim_1114;
  register value $prim_1115;
  register value $prim_1116;
  register value $prim_1117;
  register value $prim_1118;
  register value $prim_1119;
  register value $prim_1120;
  register value $prim_1121;
  register value $prim_1122;
  register value $prim_1123;
  register value $prim_1124;
  register value $prim_1125;
  register value $prim_1126;
  register value $prim_1127;
  register value $prim_1128;
  register value $prim_1129;
  register value $prim_1130;
  register value $prim_1131;
  register value $prim_1132;
  register value $prim_1133;
  register value $prim_1134;
  register value $prim_1135;
  register value $prim_1136;
  register value $prim_1137;
  register value $prim_1138;
  register value $prim_1139;
  register value $prim_1140;
  register value $prim_1141;
  register value $prim_1142;
  register value $prim_1143;
  register value $prim_1144;
  register value $prim_1145;
  register value $prim_1146;
  register value $prim_1147;
  register value $prim_1148;
  register value $prim_1149;
  register value $prim_1150;
  register value $prim_1151;
  register value $prim_1152;
  register value $prim_1153;
  register value $prim_1154;
  register value $prim_1155;
  register value $prim_1156;
  register value $prim_1157;
  register value $prim_1158;
  register value $prim_1159;
  register value $prim_1160;
  register value $prim_1161;
  register value $prim_1162;
  register value $prim_1163;
  register value $prim_1164;
  register value $prim_1165;
  register value $prim_1166;
  register value $prim_1167;
  register value $prim_1168;
  register value $prim_1169;
  register value $prim_1170;
  register value $prim_1171;
  register value $prim_1172;
  register value $prim_1173;
  register value $prim_1174;
  register value $prim_1175;
  register value $prim_1176;
  register value $prim_1177;
  register value $prim_1178;
  register value $prim_1179;
  register value $prim_1180;
  register value $prim_1181;
  register value $prim_1182;
  register value $prim_1183;
  register value $env_1184;
  register value $EncoreBenchdW1dApdudrun_wrapper_clo_1185;
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
  $prim_472 = ((value (*)(void)) bench_nat_zero)();
  $prim_473 = ((value (*)(value)) bench_nat_succ)($prim_472);
  $prim_474 = ((value (*)(value)) bench_nat_succ)($prim_473);
  $prim_475 = ((value (*)(value)) bench_nat_succ)($prim_474);
  $prim_476 = ((value (*)(value)) bench_nat_succ)($prim_475);
  $prim_477 = ((value (*)(value)) bench_nat_succ)($prim_476);
  $prim_478 = ((value (*)(value)) bench_nat_succ)($prim_477);
  $prim_479 = ((value (*)(value)) bench_nat_succ)($prim_478);
  $prim_480 = ((value (*)(value)) bench_nat_succ)($prim_479);
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
  $prim_504 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_633 = ((value (*)(void)) bench_nat_zero)();
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
  $prim_769 = ((value (*)(value)) bench_nat_succ)($prim_768);
  $prim_770 = ((value (*)(value)) bench_nat_succ)($prim_769);
  $prim_771 = ((value (*)(value)) bench_nat_succ)($prim_770);
  $prim_772 = ((value (*)(value)) bench_nat_succ)($prim_771);
  $prim_773 = ((value (*)(value)) bench_nat_succ)($prim_772);
  $prim_774 = ((value (*)(value)) bench_nat_succ)($prim_773);
  $prim_775 = ((value (*)(value)) bench_nat_succ)($prim_774);
  $prim_776 = ((value (*)(value)) bench_nat_succ)($prim_775);
  $prim_777 = ((value (*)(value)) bench_nat_succ)($prim_776);
  $prim_778 = ((value (*)(value)) bench_nat_succ)($prim_777);
  $prim_779 = ((value (*)(value)) bench_nat_succ)($prim_778);
  $prim_780 = ((value (*)(value)) bench_nat_succ)($prim_779);
  $prim_781 = ((value (*)(value)) bench_nat_succ)($prim_780);
  $prim_782 = ((value (*)(value)) bench_nat_succ)($prim_781);
  $prim_783 = ((value (*)(value)) bench_nat_succ)($prim_782);
  $prim_784 = ((value (*)(value)) bench_nat_succ)($prim_783);
  $prim_785 = ((value (*)(value)) bench_nat_succ)($prim_784);
  $prim_786 = ((value (*)(value)) bench_nat_succ)($prim_785);
  $prim_787 = ((value (*)(value)) bench_nat_succ)($prim_786);
  $prim_788 = ((value (*)(value)) bench_nat_succ)($prim_787);
  $prim_789 = ((value (*)(value)) bench_nat_succ)($prim_788);
  $prim_790 = ((value (*)(value)) bench_nat_succ)($prim_789);
  $prim_791 = ((value (*)(value)) bench_nat_succ)($prim_790);
  $prim_792 = ((value (*)(value)) bench_nat_succ)($prim_791);
  $prim_793 = ((value (*)(value)) bench_nat_succ)($prim_792);
  $prim_794 = ((value (*)(value)) bench_nat_succ)($prim_793);
  $prim_795 = ((value (*)(value)) bench_nat_succ)($prim_794);
  $prim_796 = ((value (*)(value)) bench_nat_succ)($prim_795);
  $prim_797 = ((value (*)(value)) bench_nat_succ)($prim_796);
  $prim_798 = ((value (*)(value)) bench_nat_succ)($prim_797);
  $prim_799 = ((value (*)(value)) bench_nat_succ)($prim_798);
  $prim_800 = ((value (*)(value)) bench_nat_succ)($prim_799);
  $prim_801 = ((value (*)(value)) bench_nat_succ)($prim_800);
  $prim_802 = ((value (*)(value)) bench_nat_succ)($prim_801);
  $prim_803 = ((value (*)(value)) bench_nat_succ)($prim_802);
  $prim_804 = ((value (*)(value)) bench_nat_succ)($prim_803);
  $prim_805 = ((value (*)(value)) bench_nat_succ)($prim_804);
  $prim_806 = ((value (*)(value)) bench_nat_succ)($prim_805);
  $prim_807 = ((value (*)(value)) bench_nat_succ)($prim_806);
  $prim_808 = ((value (*)(value)) bench_nat_succ)($prim_807);
  $prim_809 = ((value (*)(value)) bench_nat_succ)($prim_808);
  $prim_810 = ((value (*)(value)) bench_nat_succ)($prim_809);
  $prim_811 = ((value (*)(value)) bench_nat_succ)($prim_810);
  $prim_812 = ((value (*)(value)) bench_nat_succ)($prim_811);
  $prim_813 = ((value (*)(value)) bench_nat_succ)($prim_812);
  $prim_814 = ((value (*)(value)) bench_nat_succ)($prim_813);
  $prim_815 = ((value (*)(value)) bench_nat_succ)($prim_814);
  $prim_816 = ((value (*)(value)) bench_nat_succ)($prim_815);
  $prim_817 = ((value (*)(value)) bench_nat_succ)($prim_816);
  $prim_818 = ((value (*)(value)) bench_nat_succ)($prim_817);
  $prim_819 = ((value (*)(value)) bench_nat_succ)($prim_818);
  $prim_820 = ((value (*)(value)) bench_nat_succ)($prim_819);
  $prim_821 = ((value (*)(value)) bench_nat_succ)($prim_820);
  $prim_822 = ((value (*)(value)) bench_nat_succ)($prim_821);
  $prim_823 = ((value (*)(value)) bench_nat_succ)($prim_822);
  $prim_824 = ((value (*)(value)) bench_nat_succ)($prim_823);
  $prim_825 = ((value (*)(value)) bench_nat_succ)($prim_824);
  $prim_826 = ((value (*)(value)) bench_nat_succ)($prim_825);
  $prim_827 = ((value (*)(value)) bench_nat_succ)($prim_826);
  $prim_828 = ((value (*)(value)) bench_nat_succ)($prim_827);
  $prim_829 = ((value (*)(value)) bench_nat_succ)($prim_828);
  $prim_830 = ((value (*)(value)) bench_nat_succ)($prim_829);
  $prim_831 = ((value (*)(value)) bench_nat_succ)($prim_830);
  $prim_832 = ((value (*)(value)) bench_nat_succ)($prim_831);
  $prim_833 = ((value (*)(value)) bench_nat_succ)($prim_832);
  $prim_834 = ((value (*)(value)) bench_nat_succ)($prim_833);
  $prim_835 = ((value (*)(value)) bench_nat_succ)($prim_834);
  $prim_836 = ((value (*)(value)) bench_nat_succ)($prim_835);
  $prim_837 = ((value (*)(value)) bench_nat_succ)($prim_836);
  $prim_838 = ((value (*)(value)) bench_nat_succ)($prim_837);
  $prim_839 = ((value (*)(value)) bench_nat_succ)($prim_838);
  $prim_840 = ((value (*)(value)) bench_nat_succ)($prim_839);
  $prim_841 = ((value (*)(value)) bench_nat_succ)($prim_840);
  $prim_842 = ((value (*)(value)) bench_nat_succ)($prim_841);
  $prim_843 = ((value (*)(value)) bench_nat_succ)($prim_842);
  $prim_844 = ((value (*)(value)) bench_nat_succ)($prim_843);
  $prim_845 = ((value (*)(value)) bench_nat_succ)($prim_844);
  $prim_846 = ((value (*)(value)) bench_nat_succ)($prim_845);
  $prim_847 = ((value (*)(value)) bench_nat_succ)($prim_846);
  $prim_848 = ((value (*)(value)) bench_nat_succ)($prim_847);
  $prim_849 = ((value (*)(value)) bench_nat_succ)($prim_848);
  $prim_850 = ((value (*)(value)) bench_nat_succ)($prim_849);
  $prim_851 = ((value (*)(value)) bench_nat_succ)($prim_850);
  $prim_852 = ((value (*)(value)) bench_nat_succ)($prim_851);
  $prim_853 = ((value (*)(value)) bench_nat_succ)($prim_852);
  $prim_854 = ((value (*)(value)) bench_nat_succ)($prim_853);
  $prim_855 = ((value (*)(value)) bench_nat_succ)($prim_854);
  $prim_856 = ((value (*)(value)) bench_nat_succ)($prim_855);
  $prim_857 = ((value (*)(value)) bench_nat_succ)($prim_856);
  $prim_858 = ((value (*)(value)) bench_nat_succ)($prim_857);
  $prim_859 = ((value (*)(value)) bench_nat_succ)($prim_858);
  $prim_860 = ((value (*)(value)) bench_nat_succ)($prim_859);
  $prim_861 = ((value (*)(value)) bench_nat_succ)($prim_860);
  $prim_862 = ((value (*)(value)) bench_nat_succ)($prim_861);
  $prim_863 = ((value (*)(value)) bench_nat_succ)($prim_862);
  $prim_864 = ((value (*)(value)) bench_nat_succ)($prim_863);
  $prim_865 = ((value (*)(value)) bench_nat_succ)($prim_864);
  $prim_866 = ((value (*)(value)) bench_nat_succ)($prim_865);
  $prim_867 = ((value (*)(value)) bench_nat_succ)($prim_866);
  $prim_868 = ((value (*)(value)) bench_nat_succ)($prim_867);
  $prim_869 = ((value (*)(value)) bench_nat_succ)($prim_868);
  $prim_870 = ((value (*)(value)) bench_nat_succ)($prim_869);
  $prim_871 = ((value (*)(value)) bench_nat_succ)($prim_870);
  $prim_872 = ((value (*)(value)) bench_nat_succ)($prim_871);
  $prim_873 = ((value (*)(value)) bench_nat_succ)($prim_872);
  $prim_874 = ((value (*)(value)) bench_nat_succ)($prim_873);
  $prim_875 = ((value (*)(value)) bench_nat_succ)($prim_874);
  $prim_876 = ((value (*)(value)) bench_nat_succ)($prim_875);
  $prim_877 = ((value (*)(value)) bench_nat_succ)($prim_876);
  $prim_878 = ((value (*)(value)) bench_nat_succ)($prim_877);
  $prim_879 = ((value (*)(value)) bench_nat_succ)($prim_878);
  $prim_880 = ((value (*)(value)) bench_nat_succ)($prim_879);
  $prim_881 = ((value (*)(value)) bench_nat_succ)($prim_880);
  $prim_882 = ((value (*)(value)) bench_nat_succ)($prim_881);
  $prim_883 = ((value (*)(value)) bench_nat_succ)($prim_882);
  $prim_884 = ((value (*)(value)) bench_nat_succ)($prim_883);
  $prim_885 = ((value (*)(value)) bench_nat_succ)($prim_884);
  $prim_886 = ((value (*)(value)) bench_nat_succ)($prim_885);
  $prim_887 = ((value (*)(value)) bench_nat_succ)($prim_886);
  $prim_888 = ((value (*)(value)) bench_nat_succ)($prim_887);
  $prim_889 = ((value (*)(value)) bench_nat_succ)($prim_888);
  $prim_890 = ((value (*)(void)) bench_nat_zero)();
  $prim_891 = ((value (*)(value)) bench_nat_succ)($prim_890);
  $prim_892 = ((value (*)(value)) bench_nat_succ)($prim_891);
  $prim_893 = ((value (*)(value)) bench_nat_succ)($prim_892);
  $prim_894 = ((value (*)(value)) bench_nat_succ)($prim_893);
  $prim_895 = ((value (*)(value)) bench_nat_succ)($prim_894);
  $prim_896 = ((value (*)(value)) bench_nat_succ)($prim_895);
  $prim_897 = ((value (*)(value)) bench_nat_succ)($prim_896);
  $prim_898 = ((value (*)(value)) bench_nat_succ)($prim_897);
  $prim_899 = ((value (*)(value)) bench_nat_succ)($prim_898);
  $prim_900 = ((value (*)(value)) bench_nat_succ)($prim_899);
  $prim_901 = ((value (*)(value)) bench_nat_succ)($prim_900);
  $prim_902 = ((value (*)(value)) bench_nat_succ)($prim_901);
  $prim_903 = ((value (*)(value)) bench_nat_succ)($prim_902);
  $prim_904 = ((value (*)(value)) bench_nat_succ)($prim_903);
  $prim_905 = ((value (*)(value)) bench_nat_succ)($prim_904);
  $prim_906 = ((value (*)(value)) bench_nat_succ)($prim_905);
  $prim_907 = ((value (*)(value)) bench_nat_succ)($prim_906);
  $prim_908 = ((value (*)(value)) bench_nat_succ)($prim_907);
  $prim_909 = ((value (*)(value)) bench_nat_succ)($prim_908);
  $prim_910 = ((value (*)(value)) bench_nat_succ)($prim_909);
  $prim_911 = ((value (*)(value)) bench_nat_succ)($prim_910);
  $prim_912 = ((value (*)(value)) bench_nat_succ)($prim_911);
  $prim_913 = ((value (*)(value)) bench_nat_succ)($prim_912);
  $prim_914 = ((value (*)(value)) bench_nat_succ)($prim_913);
  $prim_915 = ((value (*)(value)) bench_nat_succ)($prim_914);
  $prim_916 = ((value (*)(value)) bench_nat_succ)($prim_915);
  $prim_917 = ((value (*)(value)) bench_nat_succ)($prim_916);
  $prim_918 = ((value (*)(value)) bench_nat_succ)($prim_917);
  $prim_919 = ((value (*)(value)) bench_nat_succ)($prim_918);
  $prim_920 = ((value (*)(value)) bench_nat_succ)($prim_919);
  $prim_921 = ((value (*)(value)) bench_nat_succ)($prim_920);
  $prim_922 = ((value (*)(value)) bench_nat_succ)($prim_921);
  $prim_923 = ((value (*)(value)) bench_nat_succ)($prim_922);
  $prim_924 = ((value (*)(value)) bench_nat_succ)($prim_923);
  $prim_925 = ((value (*)(value)) bench_nat_succ)($prim_924);
  $prim_926 = ((value (*)(value)) bench_nat_succ)($prim_925);
  $prim_927 = ((value (*)(value)) bench_nat_succ)($prim_926);
  $prim_928 = ((value (*)(value)) bench_nat_succ)($prim_927);
  $prim_929 = ((value (*)(value)) bench_nat_succ)($prim_928);
  $prim_930 = ((value (*)(value)) bench_nat_succ)($prim_929);
  $prim_931 = ((value (*)(value)) bench_nat_succ)($prim_930);
  $prim_932 = ((value (*)(value)) bench_nat_succ)($prim_931);
  $prim_933 = ((value (*)(value)) bench_nat_succ)($prim_932);
  $prim_934 = ((value (*)(value)) bench_nat_succ)($prim_933);
  $prim_935 = ((value (*)(value)) bench_nat_succ)($prim_934);
  $prim_936 = ((value (*)(value)) bench_nat_succ)($prim_935);
  $prim_937 = ((value (*)(value)) bench_nat_succ)($prim_936);
  $prim_938 = ((value (*)(value)) bench_nat_succ)($prim_937);
  $prim_939 = ((value (*)(value)) bench_nat_succ)($prim_938);
  $prim_940 = ((value (*)(value)) bench_nat_succ)($prim_939);
  $prim_941 = ((value (*)(value)) bench_nat_succ)($prim_940);
  $prim_942 = ((value (*)(value)) bench_nat_succ)($prim_941);
  $prim_943 = ((value (*)(value)) bench_nat_succ)($prim_942);
  $prim_944 = ((value (*)(value)) bench_nat_succ)($prim_943);
  $prim_945 = ((value (*)(value)) bench_nat_succ)($prim_944);
  $prim_946 = ((value (*)(value)) bench_nat_succ)($prim_945);
  $prim_947 = ((value (*)(value)) bench_nat_succ)($prim_946);
  $prim_948 = ((value (*)(value)) bench_nat_succ)($prim_947);
  $prim_949 = ((value (*)(value)) bench_nat_succ)($prim_948);
  $prim_950 = ((value (*)(value)) bench_nat_succ)($prim_949);
  $prim_951 = ((value (*)(value)) bench_nat_succ)($prim_950);
  $prim_952 = ((value (*)(value)) bench_nat_succ)($prim_951);
  $prim_953 = ((value (*)(value)) bench_nat_succ)($prim_952);
  $prim_954 = ((value (*)(value)) bench_nat_succ)($prim_953);
  $prim_955 = ((value (*)(value)) bench_nat_succ)($prim_954);
  $prim_956 = ((value (*)(value)) bench_nat_succ)($prim_955);
  $prim_957 = ((value (*)(value)) bench_nat_succ)($prim_956);
  $prim_958 = ((value (*)(value)) bench_nat_succ)($prim_957);
  $prim_959 = ((value (*)(value)) bench_nat_succ)($prim_958);
  $prim_960 = ((value (*)(value)) bench_nat_succ)($prim_959);
  $prim_961 = ((value (*)(value)) bench_nat_succ)($prim_960);
  $prim_962 = ((value (*)(value)) bench_nat_succ)($prim_961);
  $prim_963 = ((value (*)(value)) bench_nat_succ)($prim_962);
  $prim_964 = ((value (*)(value)) bench_nat_succ)($prim_963);
  $prim_965 = ((value (*)(value)) bench_nat_succ)($prim_964);
  $prim_966 = ((value (*)(value)) bench_nat_succ)($prim_965);
  $prim_967 = ((value (*)(value)) bench_nat_succ)($prim_966);
  $prim_968 = ((value (*)(value)) bench_nat_succ)($prim_967);
  $prim_969 = ((value (*)(value)) bench_nat_succ)($prim_968);
  $prim_970 = ((value (*)(value)) bench_nat_succ)($prim_969);
  $prim_971 = ((value (*)(value)) bench_nat_succ)($prim_970);
  $prim_972 = ((value (*)(value)) bench_nat_succ)($prim_971);
  $prim_973 = ((value (*)(value)) bench_nat_succ)($prim_972);
  $prim_974 = ((value (*)(value)) bench_nat_succ)($prim_973);
  $prim_975 = ((value (*)(value)) bench_nat_succ)($prim_974);
  $prim_976 = ((value (*)(value)) bench_nat_succ)($prim_975);
  $prim_977 = ((value (*)(value)) bench_nat_succ)($prim_976);
  $prim_978 = ((value (*)(value)) bench_nat_succ)($prim_977);
  $prim_979 = ((value (*)(value)) bench_nat_succ)($prim_978);
  $prim_980 = ((value (*)(value)) bench_nat_succ)($prim_979);
  $prim_981 = ((value (*)(value)) bench_nat_succ)($prim_980);
  $prim_982 = ((value (*)(value)) bench_nat_succ)($prim_981);
  $prim_983 = ((value (*)(value)) bench_nat_succ)($prim_982);
  $prim_984 = ((value (*)(value)) bench_nat_succ)($prim_983);
  $prim_985 = ((value (*)(value)) bench_nat_succ)($prim_984);
  $prim_986 = ((value (*)(value)) bench_nat_succ)($prim_985);
  $prim_987 = ((value (*)(value)) bench_nat_succ)($prim_986);
  $prim_988 = ((value (*)(value)) bench_nat_succ)($prim_987);
  $prim_989 = ((value (*)(value)) bench_nat_succ)($prim_988);
  $prim_990 = ((value (*)(value)) bench_nat_succ)($prim_989);
  $prim_991 = ((value (*)(value)) bench_nat_succ)($prim_990);
  $prim_992 = ((value (*)(value)) bench_nat_succ)($prim_991);
  $prim_993 = ((value (*)(value)) bench_nat_succ)($prim_992);
  $prim_994 = ((value (*)(value)) bench_nat_succ)($prim_993);
  $prim_995 = ((value (*)(value)) bench_nat_succ)($prim_994);
  $prim_996 = ((value (*)(value)) bench_nat_succ)($prim_995);
  $prim_997 = ((value (*)(value)) bench_nat_succ)($prim_996);
  $prim_998 = ((value (*)(value)) bench_nat_succ)($prim_997);
  $prim_999 = ((value (*)(value)) bench_nat_succ)($prim_998);
  $prim_1000 = ((value (*)(value)) bench_nat_succ)($prim_999);
  $prim_1001 = ((value (*)(value)) bench_nat_succ)($prim_1000);
  $prim_1002 = ((value (*)(value)) bench_nat_succ)($prim_1001);
  $prim_1003 = ((value (*)(value)) bench_nat_succ)($prim_1002);
  $prim_1004 = ((value (*)(value)) bench_nat_succ)($prim_1003);
  $prim_1005 = ((value (*)(value)) bench_nat_succ)($prim_1004);
  $prim_1006 = ((value (*)(value)) bench_nat_succ)($prim_1005);
  $prim_1007 = ((value (*)(value)) bench_nat_succ)($prim_1006);
  $prim_1008 = ((value (*)(value)) bench_nat_succ)($prim_1007);
  $prim_1009 = ((value (*)(value)) bench_nat_succ)($prim_1008);
  $prim_1010 = ((value (*)(value)) bench_nat_succ)($prim_1009);
  $prim_1011 = ((value (*)(value)) bench_nat_succ)($prim_1010);
  $prim_1012 = ((value (*)(value)) bench_nat_succ)($prim_1011);
  $prim_1013 = ((value (*)(value)) bench_nat_succ)($prim_1012);
  $prim_1014 = ((value (*)(value)) bench_nat_succ)($prim_1013);
  $prim_1015 = ((value (*)(value)) bench_nat_succ)($prim_1014);
  $prim_1016 = ((value (*)(value)) bench_nat_succ)($prim_1015);
  $prim_1017 = ((value (*)(value)) bench_nat_succ)($prim_1016);
  $prim_1018 = ((value (*)(value)) bench_nat_succ)($prim_1017);
  $prim_1019 = ((value (*)(value)) bench_nat_succ)($prim_1018);
  $prim_1020 = ((value (*)(void)) bench_nat_zero)();
  $prim_1021 = ((value (*)(value)) bench_nat_succ)($prim_1020);
  $prim_1022 = ((value (*)(value)) bench_nat_succ)($prim_1021);
  $prim_1023 = ((value (*)(value)) bench_nat_succ)($prim_1022);
  $prim_1024 = ((value (*)(value)) bench_nat_succ)($prim_1023);
  $prim_1025 = ((value (*)(value)) bench_nat_succ)($prim_1024);
  $prim_1026 = ((value (*)(value)) bench_nat_succ)($prim_1025);
  $prim_1027 = ((value (*)(value)) bench_nat_succ)($prim_1026);
  $prim_1028 = ((value (*)(value)) bench_nat_succ)($prim_1027);
  $prim_1029 = ((value (*)(value)) bench_nat_succ)($prim_1028);
  $prim_1030 = ((value (*)(value)) bench_nat_succ)($prim_1029);
  $prim_1031 = ((value (*)(value)) bench_nat_succ)($prim_1030);
  $prim_1032 = ((value (*)(value)) bench_nat_succ)($prim_1031);
  $prim_1033 = ((value (*)(value)) bench_nat_succ)($prim_1032);
  $prim_1034 = ((value (*)(value)) bench_nat_succ)($prim_1033);
  $prim_1035 = ((value (*)(value)) bench_nat_succ)($prim_1034);
  $prim_1036 = ((value (*)(value)) bench_nat_succ)($prim_1035);
  $prim_1037 = ((value (*)(value)) bench_nat_succ)($prim_1036);
  $prim_1038 = ((value (*)(value)) bench_nat_succ)($prim_1037);
  $prim_1039 = ((value (*)(value)) bench_nat_succ)($prim_1038);
  $prim_1040 = ((value (*)(value)) bench_nat_succ)($prim_1039);
  $prim_1041 = ((value (*)(value)) bench_nat_succ)($prim_1040);
  $prim_1042 = ((value (*)(value)) bench_nat_succ)($prim_1041);
  $prim_1043 = ((value (*)(value)) bench_nat_succ)($prim_1042);
  $prim_1044 = ((value (*)(value)) bench_nat_succ)($prim_1043);
  $prim_1045 = ((value (*)(value)) bench_nat_succ)($prim_1044);
  $prim_1046 = ((value (*)(value)) bench_nat_succ)($prim_1045);
  $prim_1047 = ((value (*)(value)) bench_nat_succ)($prim_1046);
  $prim_1048 = ((value (*)(value)) bench_nat_succ)($prim_1047);
  $prim_1049 = ((value (*)(value)) bench_nat_succ)($prim_1048);
  $prim_1050 = ((value (*)(value)) bench_nat_succ)($prim_1049);
  $prim_1051 = ((value (*)(value)) bench_nat_succ)($prim_1050);
  $prim_1052 = ((value (*)(value)) bench_nat_succ)($prim_1051);
  $prim_1053 = ((value (*)(value)) bench_nat_succ)($prim_1052);
  $prim_1054 = ((value (*)(value)) bench_nat_succ)($prim_1053);
  $prim_1055 = ((value (*)(value)) bench_nat_succ)($prim_1054);
  $prim_1056 = ((value (*)(value)) bench_nat_succ)($prim_1055);
  $prim_1057 = ((value (*)(value)) bench_nat_succ)($prim_1056);
  $prim_1058 = ((value (*)(value)) bench_nat_succ)($prim_1057);
  $prim_1059 = ((value (*)(value)) bench_nat_succ)($prim_1058);
  $prim_1060 = ((value (*)(value)) bench_nat_succ)($prim_1059);
  $prim_1061 = ((value (*)(value)) bench_nat_succ)($prim_1060);
  $prim_1062 = ((value (*)(value)) bench_nat_succ)($prim_1061);
  $prim_1063 = ((value (*)(value)) bench_nat_succ)($prim_1062);
  $prim_1064 = ((value (*)(value)) bench_nat_succ)($prim_1063);
  $prim_1065 = ((value (*)(value)) bench_nat_succ)($prim_1064);
  $prim_1066 = ((value (*)(value)) bench_nat_succ)($prim_1065);
  $prim_1067 = ((value (*)(value)) bench_nat_succ)($prim_1066);
  $prim_1068 = ((value (*)(value)) bench_nat_succ)($prim_1067);
  $prim_1069 = ((value (*)(value)) bench_nat_succ)($prim_1068);
  $prim_1070 = ((value (*)(value)) bench_nat_succ)($prim_1069);
  $prim_1071 = ((value (*)(value)) bench_nat_succ)($prim_1070);
  $prim_1072 = ((value (*)(value)) bench_nat_succ)($prim_1071);
  $prim_1073 = ((value (*)(value)) bench_nat_succ)($prim_1072);
  $prim_1074 = ((value (*)(value)) bench_nat_succ)($prim_1073);
  $prim_1075 = ((value (*)(value)) bench_nat_succ)($prim_1074);
  $prim_1076 = ((value (*)(value)) bench_nat_succ)($prim_1075);
  $prim_1077 = ((value (*)(value)) bench_nat_succ)($prim_1076);
  $prim_1078 = ((value (*)(value)) bench_nat_succ)($prim_1077);
  $prim_1079 = ((value (*)(value)) bench_nat_succ)($prim_1078);
  $prim_1080 = ((value (*)(value)) bench_nat_succ)($prim_1079);
  $prim_1081 = ((value (*)(value)) bench_nat_succ)($prim_1080);
  $prim_1082 = ((value (*)(value)) bench_nat_succ)($prim_1081);
  $prim_1083 = ((value (*)(value)) bench_nat_succ)($prim_1082);
  $prim_1084 = ((value (*)(value)) bench_nat_succ)($prim_1083);
  $prim_1085 = ((value (*)(value)) bench_nat_succ)($prim_1084);
  $prim_1086 = ((value (*)(value)) bench_nat_succ)($prim_1085);
  $prim_1087 = ((value (*)(value)) bench_nat_succ)($prim_1086);
  $prim_1088 = ((value (*)(value)) bench_nat_succ)($prim_1087);
  $prim_1089 = ((value (*)(value)) bench_nat_succ)($prim_1088);
  $prim_1090 = ((value (*)(value)) bench_nat_succ)($prim_1089);
  $prim_1091 = ((value (*)(value)) bench_nat_succ)($prim_1090);
  $prim_1092 = ((value (*)(value)) bench_nat_succ)($prim_1091);
  $prim_1093 = ((value (*)(value)) bench_nat_succ)($prim_1092);
  $prim_1094 = ((value (*)(value)) bench_nat_succ)($prim_1093);
  $prim_1095 = ((value (*)(value)) bench_nat_succ)($prim_1094);
  $prim_1096 = ((value (*)(value)) bench_nat_succ)($prim_1095);
  $prim_1097 = ((value (*)(value)) bench_nat_succ)($prim_1096);
  $prim_1098 = ((value (*)(value)) bench_nat_succ)($prim_1097);
  $prim_1099 = ((value (*)(value)) bench_nat_succ)($prim_1098);
  $prim_1100 = ((value (*)(value)) bench_nat_succ)($prim_1099);
  $prim_1101 = ((value (*)(value)) bench_nat_succ)($prim_1100);
  $prim_1102 = ((value (*)(value)) bench_nat_succ)($prim_1101);
  $prim_1103 = ((value (*)(value)) bench_nat_succ)($prim_1102);
  $prim_1104 = ((value (*)(value)) bench_nat_succ)($prim_1103);
  $prim_1105 = ((value (*)(value)) bench_nat_succ)($prim_1104);
  $prim_1106 = ((value (*)(value)) bench_nat_succ)($prim_1105);
  $prim_1107 = ((value (*)(value)) bench_nat_succ)($prim_1106);
  $prim_1108 = ((value (*)(value)) bench_nat_succ)($prim_1107);
  $prim_1109 = ((value (*)(value)) bench_nat_succ)($prim_1108);
  $prim_1110 = ((value (*)(value)) bench_nat_succ)($prim_1109);
  $prim_1111 = ((value (*)(value)) bench_nat_succ)($prim_1110);
  $prim_1112 = ((value (*)(value)) bench_nat_succ)($prim_1111);
  $prim_1113 = ((value (*)(value)) bench_nat_succ)($prim_1112);
  $prim_1114 = ((value (*)(value)) bench_nat_succ)($prim_1113);
  $prim_1115 = ((value (*)(value)) bench_nat_succ)($prim_1114);
  $prim_1116 = ((value (*)(value)) bench_nat_succ)($prim_1115);
  $prim_1117 = ((value (*)(value)) bench_nat_succ)($prim_1116);
  $prim_1118 = ((value (*)(value)) bench_nat_succ)($prim_1117);
  $prim_1119 = ((value (*)(value)) bench_nat_succ)($prim_1118);
  $prim_1120 = ((value (*)(value)) bench_nat_succ)($prim_1119);
  $prim_1121 = ((value (*)(value)) bench_nat_succ)($prim_1120);
  $prim_1122 = ((value (*)(value)) bench_nat_succ)($prim_1121);
  $prim_1123 = ((value (*)(value)) bench_nat_succ)($prim_1122);
  $prim_1124 = ((value (*)(value)) bench_nat_succ)($prim_1123);
  $prim_1125 = ((value (*)(value)) bench_nat_succ)($prim_1124);
  $prim_1126 = ((value (*)(value)) bench_nat_succ)($prim_1125);
  $prim_1127 = ((value (*)(value)) bench_nat_succ)($prim_1126);
  $prim_1128 = ((value (*)(value)) bench_nat_succ)($prim_1127);
  $prim_1129 = ((value (*)(value)) bench_nat_succ)($prim_1128);
  $prim_1130 = ((value (*)(value)) bench_nat_succ)($prim_1129);
  $prim_1131 = ((value (*)(value)) bench_nat_succ)($prim_1130);
  $prim_1132 = ((value (*)(value)) bench_nat_succ)($prim_1131);
  $prim_1133 = ((value (*)(value)) bench_nat_succ)($prim_1132);
  $prim_1134 = ((value (*)(value)) bench_nat_succ)($prim_1133);
  $prim_1135 = ((value (*)(value)) bench_nat_succ)($prim_1134);
  $prim_1136 = ((value (*)(value)) bench_nat_succ)($prim_1135);
  $prim_1137 = ((value (*)(value)) bench_nat_succ)($prim_1136);
  $prim_1138 = ((value (*)(value)) bench_nat_succ)($prim_1137);
  $prim_1139 = ((value (*)(value)) bench_nat_succ)($prim_1138);
  $prim_1140 = ((value (*)(value)) bench_nat_succ)($prim_1139);
  $prim_1141 = ((value (*)(value)) bench_nat_succ)($prim_1140);
  $prim_1142 = ((value (*)(value)) bench_nat_succ)($prim_1141);
  $prim_1143 = ((value (*)(value)) bench_nat_succ)($prim_1142);
  $prim_1144 = ((value (*)(value)) bench_nat_succ)($prim_1143);
  $prim_1145 = ((value (*)(value)) bench_nat_succ)($prim_1144);
  $prim_1146 = ((value (*)(value)) bench_nat_succ)($prim_1145);
  $prim_1147 = ((value (*)(value)) bench_nat_succ)($prim_1146);
  $prim_1148 = ((value (*)(value)) bench_nat_succ)($prim_1147);
  $prim_1149 = ((value (*)(value)) bench_nat_succ)($prim_1148);
  $prim_1150 = ((value (*)(value)) bench_nat_succ)($prim_1149);
  $prim_1151 = ((value (*)(void)) bench_nat_zero)();
  $prim_1152 = ((value (*)(value)) bench_nat_succ)($prim_1151);
  $prim_1153 = ((value (*)(value)) bench_nat_succ)($prim_1152);
  $prim_1154 = ((value (*)(value)) bench_nat_succ)($prim_1153);
  $prim_1155 = ((value (*)(value)) bench_nat_succ)($prim_1154);
  $prim_1156 = ((value (*)(value)) bench_nat_succ)($prim_1155);
  $prim_1157 = ((value (*)(value)) bench_nat_succ)($prim_1156);
  $prim_1158 = ((value (*)(value)) bench_nat_succ)($prim_1157);
  $prim_1159 = ((value (*)(value)) bench_nat_succ)($prim_1158);
  $prim_1160 = ((value (*)(value)) bench_nat_succ)($prim_1159);
  $prim_1161 = ((value (*)(value)) bench_nat_succ)($prim_1160);
  $prim_1162 = ((value (*)(value)) bench_nat_succ)($prim_1161);
  $prim_1163 = ((value (*)(value)) bench_nat_succ)($prim_1162);
  $prim_1164 = ((value (*)(value)) bench_nat_succ)($prim_1163);
  $prim_1165 = ((value (*)(value)) bench_nat_succ)($prim_1164);
  $prim_1166 = ((value (*)(value)) bench_nat_succ)($prim_1165);
  $prim_1167 = ((value (*)(value)) bench_nat_succ)($prim_1166);
  $prim_1168 = ((value (*)(value)) bench_nat_succ)($prim_1167);
  $prim_1169 = ((value (*)(value)) bench_nat_succ)($prim_1168);
  $prim_1170 = ((value (*)(value)) bench_nat_succ)($prim_1169);
  $prim_1171 = ((value (*)(value)) bench_nat_succ)($prim_1170);
  $prim_1172 = ((value (*)(value)) bench_nat_succ)($prim_1171);
  $prim_1173 = ((value (*)(value)) bench_nat_succ)($prim_1172);
  $prim_1174 = ((value (*)(value)) bench_nat_succ)($prim_1173);
  $prim_1175 = ((value (*)(value)) bench_nat_succ)($prim_1174);
  $prim_1176 = ((value (*)(value)) bench_nat_succ)($prim_1175);
  $prim_1177 = ((value (*)(value)) bench_nat_succ)($prim_1176);
  $prim_1178 = ((value (*)(value)) bench_nat_succ)($prim_1177);
  $prim_1179 = ((value (*)(value)) bench_nat_succ)($prim_1178);
  $prim_1180 = ((value (*)(value)) bench_nat_succ)($prim_1179);
  $prim_1181 = ((value (*)(value)) bench_nat_succ)($prim_1180);
  $prim_1182 = ((value (*)(value)) bench_nat_succ)($prim_1181);
  $prim_1183 = ((value (*)(value)) bench_nat_succ)($prim_1182);
  $env_1184 = 1;
  $EncoreBenchdW1dApdudrun_wrapper_clo_1185 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $EncoreBenchdW1dApdudrun_wrapper_clo_1185 + -1) = 2048;
  *((value *) $EncoreBenchdW1dApdudrun_wrapper_clo_1185 + 0) =
    EncoreBenchdW1dApdudrun_wrapper_145;
  *((value *) $EncoreBenchdW1dApdudrun_wrapper_clo_1185 + 1) = $env_1184;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $EncoreBenchdW1dApdudrun_wrapper_clo_1185;
}


#endif /* W1_APDU_C */
