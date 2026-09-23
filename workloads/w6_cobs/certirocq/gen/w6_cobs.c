#ifndef W6_COBS_C
#define W6_COBS_C
#include <gc_stack.h>
#include "bench_rt.h"
#include "bench_rt.h"
#include "w6_cobs.h"
extern struct thread_info *make_tinfo(void);
extern value CompileCdc_roundtrip_wrapper_143(struct thread_info *, value, value);
extern value y_wrapper_142(struct thread_info *, value, value);
extern value y_wrapper_141(struct thread_info *, value, value);
extern value y_known_140(struct thread_info *, value, value, value, value);
extern value y_wrapper_139(struct thread_info *, value, value);
extern value y_wrapper_138(struct thread_info *, value, value);
extern value y_wrapper_137(struct thread_info *, value, value);
extern value y_known_136(struct thread_info *, value, value, value);
extern value y_wrapper_135(struct thread_info *, value, value);
extern value y_wrapper_134(struct thread_info *, value, value);
extern value y_wrapper_133(struct thread_info *, value, value);
extern value dec_uncurried_uncurried_known_132(struct thread_info *, value, value, value);
extern value f_case_known_131(struct thread_info *, value, value);
extern value y_wrapper_130(struct thread_info *, value, value);
extern value y_known_129(struct thread_info *, value, value);
extern value y_wrapper_128(struct thread_info *, value, value);
extern value y_wrapper_127(struct thread_info *, value, value);
extern value y_wrapper_126(struct thread_info *, value, value);
extern value fits_uncurried_known_125(struct thread_info *, value, value);
extern value y_124(struct thread_info *, value, value);
extern value y_wrapper_123(struct thread_info *, value, value);
extern value enc_pieces_known_122(struct thread_info *, value);
extern value y_wrapper_121(struct thread_info *, value, value);
extern value y_known_120(struct thread_info *, value, value);
extern value y_wrapper_119(struct thread_info *, value, value);
extern value split_zero_known_118(struct thread_info *, value);
extern value y_wrapper_117(struct thread_info *, value, value);
extern value y_wrapper_116(struct thread_info *, value, value);
extern value CompileCdc_roundtrip_known_115(struct thread_info *, value);
extern value length_known_114(struct thread_info *, value);
extern value app_uncurried_known_113(struct thread_info *, value, value);
extern value body(struct thread_info *);
value CompileCdc_roundtrip_wrapper_143(struct thread_info *, value, value);
value y_wrapper_142(struct thread_info *, value, value);
value y_wrapper_141(struct thread_info *, value, value);
value y_known_140(struct thread_info *, value, value, value, value);
value y_wrapper_139(struct thread_info *, value, value);
value y_wrapper_138(struct thread_info *, value, value);
value y_wrapper_137(struct thread_info *, value, value);
value y_known_136(struct thread_info *, value, value, value);
value y_wrapper_135(struct thread_info *, value, value);
value y_wrapper_134(struct thread_info *, value, value);
value y_wrapper_133(struct thread_info *, value, value);
value dec_uncurried_uncurried_known_132(struct thread_info *, value, value, value);
value f_case_known_131(struct thread_info *, value, value);
value y_wrapper_130(struct thread_info *, value, value);
value y_known_129(struct thread_info *, value, value);
value y_wrapper_128(struct thread_info *, value, value);
value y_wrapper_127(struct thread_info *, value, value);
value y_wrapper_126(struct thread_info *, value, value);
value fits_uncurried_known_125(struct thread_info *, value, value);
value y_124(struct thread_info *, value, value);
value y_wrapper_123(struct thread_info *, value, value);
value enc_pieces_known_122(struct thread_info *, value);
value y_wrapper_121(struct thread_info *, value, value);
value y_known_120(struct thread_info *, value, value);
value y_wrapper_119(struct thread_info *, value, value);
value split_zero_known_118(struct thread_info *, value);
value y_wrapper_117(struct thread_info *, value, value);
value y_wrapper_116(struct thread_info *, value, value);
value CompileCdc_roundtrip_known_115(struct thread_info *, value);
value length_known_114(struct thread_info *, value);
value app_uncurried_known_113(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned int const body_info_701[2] = { 3, 0, };

unsigned int const app_uncurried_known_info_700[4] = { 0, 2, 0, 1, };

unsigned int const length_known_info_699[3] = { 0, 1, 0, };

unsigned int const CompileCdc_roundtrip_known_info_698[3] = { 8, 1, 0, };

unsigned int const y_wrapper_info_697[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_696[4] = { 11, 2, 0, 1, };

unsigned int const split_zero_known_info_695[3] = { 3, 1, 0, };

unsigned int const y_wrapper_info_694[4] = { 3, 2, 0, 1, };

unsigned int const y_known_info_693[4] = { 6, 2, 0, 1, };

unsigned int const y_wrapper_info_692[4] = { 0, 2, 0, 1, };

unsigned int const enc_pieces_known_info_691[3] = { 0, 1, 0, };

unsigned int const y_wrapper_info_690[4] = { 0, 2, 0, 1, };

unsigned int const y_info_689[4] = { 0, 2, 0, 1, };

unsigned int const fits_uncurried_known_info_688[4] = { 8, 2, 0, 1, };

unsigned int const y_wrapper_info_687[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_686[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_685[4] = { 3, 2, 0, 1, };

unsigned int const y_known_info_684[4] = { 16, 2, 0, 1, };

unsigned int const y_wrapper_info_683[4] = { 0, 2, 0, 1, };

unsigned int const f_case_known_info_682[4] = { 0, 2, 0, 1, };

unsigned int const dec_uncurried_uncurried_known_info_681[5] = { 14, 3, 0, 1,
  2, };

unsigned int const y_wrapper_info_680[4] = { 2, 2, 0, 1, };

unsigned int const y_wrapper_info_679[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_678[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_677[5] = { 0, 3, 0, 1, 2, };

unsigned int const y_wrapper_info_676[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_675[4] = { 9, 2, 0, 1, };

unsigned int const y_wrapper_info_674[4] = { 0, 2, 0, 1, };

unsigned int const y_known_info_673[6] = { 0, 4, 0, 1, 2, 3, };

unsigned int const y_wrapper_info_672[4] = { 0, 2, 0, 1, };

unsigned int const y_wrapper_info_671[4] = { 11, 2, 0, 1, };

unsigned int const CompileCdc_roundtrip_wrapper_info_670[4] = { 0, 2, 0, 1,
  };

value CompileCdc_roundtrip_wrapper_143(struct thread_info *$tinfo, value $env_410, value $n_411)
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
    ((value (*)(struct thread_info *, value)) CompileCdc_roundtrip_known_115)
    ($tinfo, $n_411);
  return $result;
}

value y_wrapper_142(struct thread_info *$tinfo, value $env_400, value $kp_401)
{
  struct stack_frame frame;
  value root[2];
  register value $ff_proj_402;
  register value $x_proj_403;
  register value $t_proj_404;
  register value $env_405;
  register value $env_406;
  register value $y_wrapper_clo_407;
  register value $y_wrapper_clo_408;
  register value $prim_409;
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
    *(root + 1) = $kp_401;
    *(root + 0) = $env_400;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $kp_401 = *(root + 1);
    $env_400 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $ff_proj_402 = *((value *) $env_400 + 0);
  $x_proj_403 = *((value *) $env_400 + 1);
  $t_proj_404 = *((value *) $env_400 + 2);
  $env_405 = 1;
  $env_406 = (value) ($alloc + 1);
  $alloc = $alloc + 5;
  *((value *) $env_406 + -1) = 4096;
  *((value *) $env_406 + 0) = $kp_401;
  *((value *) $env_406 + 1) = $t_proj_404;
  *((value *) $env_406 + 2) = $x_proj_403;
  *((value *) $env_406 + 3) = $ff_proj_402;
  $y_wrapper_clo_407 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_407 + -1) = 2048;
  *((value *) $y_wrapper_clo_407 + 0) = y_wrapper_139;
  *((value *) $y_wrapper_clo_407 + 1) = $env_405;
  $y_wrapper_clo_408 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_408 + -1) = 2048;
  *((value *) $y_wrapper_clo_408 + 0) = y_wrapper_141;
  *((value *) $y_wrapper_clo_408 + 1) = $env_406;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_409 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $x_proj_403, $y_wrapper_clo_407, $y_wrapper_clo_408);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_409;
}

value y_wrapper_141(struct thread_info *$tinfo, value $env_393, value $n_394)
{
  struct stack_frame frame;
  value root[1];
  register value $ff_proj_396;
  register value $x_proj_397;
  register value $t_proj_398;
  register value $kp_proj_399;
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
  $ff_proj_396 = *((value *) $env_393 + 3);
  $x_proj_397 = *((value *) $env_393 + 2);
  $t_proj_398 = *((value *) $env_393 + 1);
  $kp_proj_399 = *((value *) $env_393 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value, value)) y_known_140)
    ($tinfo, $ff_proj_396, $x_proj_397, $t_proj_398, $kp_proj_399);
  return $result;
}

value y_known_140(struct thread_info *$tinfo, value $ff_383, value $x_384, value $t_385, value $kp_386)
{
  struct stack_frame frame;
  value root[4];
  register value $y_388;
  register value $d_389;
  register value $y_390;
  register value $y_391;
  register value $y_392;
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
  *(root + 0) = $x_384;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $y_388 =
    ((value (*)(struct thread_info *, value, value, value)) dec_uncurried_uncurried_known_132)
    ($tinfo, $t_385, $ff_383, $kp_386);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(5 <= $limit - $alloc)) {
    *(root + 1) = $y_388;
    frame.next = root + 2;
    (*$tinfo).nalloc = 5;
    garbage_collect($tinfo);
    $y_388 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $x_384 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_388 & 1) == 0) {
    switch (*((value *) $y_388 + -1) & 255) {
      default:
        $d_389 = *((value *) $y_388 + 0);
        $y_390 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_390 + -1) = 2048;
        *((value *) $y_390 + 0) = $x_384;
        *((value *) $y_390 + 1) = $d_389;
        $y_391 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $y_391 + -1) = 1024;
        *((value *) $y_391 + 0) = $y_390;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_391;
        break;
      
    }
  } else {
    switch ($y_388 >> 1) {
      default:
        $y_392 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_392;
        break;
      
    }
  }
}

value y_wrapper_139(struct thread_info *$tinfo, value $env_378, value $anon_379)
{
  struct stack_frame frame;
  value root[0];
  register value $y_380;
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
  $y_380 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_380;
}

value y_wrapper_138(struct thread_info *$tinfo, value $env_368, value $anon_369)
{
  struct stack_frame frame;
  value root[1];
  register value $ff_proj_370;
  register value $x_proj_371;
  register value $t_proj_372;
  register value $env_373;
  register value $env_374;
  register value $y_wrapper_clo_375;
  register value $y_wrapper_clo_376;
  register value $prim_377;
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
    *(root + 0) = $env_368;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 9;
    garbage_collect($tinfo);
    $env_368 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $ff_proj_370 = *((value *) $env_368 + 0);
  $x_proj_371 = *((value *) $env_368 + 1);
  $t_proj_372 = *((value *) $env_368 + 2);
  $env_373 = 1;
  $env_374 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $env_374 + -1) = 2048;
  *((value *) $env_374 + 0) = $t_proj_372;
  *((value *) $env_374 + 1) = $ff_proj_370;
  $y_wrapper_clo_375 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_375 + -1) = 2048;
  *((value *) $y_wrapper_clo_375 + 0) = y_wrapper_135;
  *((value *) $y_wrapper_clo_375 + 1) = $env_373;
  $y_wrapper_clo_376 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_376 + -1) = 2048;
  *((value *) $y_wrapper_clo_376 + 0) = y_wrapper_137;
  *((value *) $y_wrapper_clo_376 + 1) = $env_374;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_377 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $x_proj_371, $y_wrapper_clo_375, $y_wrapper_clo_376);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_377;
}

value y_wrapper_137(struct thread_info *$tinfo, value $env_363, value $n_364)
{
  struct stack_frame frame;
  value root[2];
  register value $ff_proj_366;
  register value $t_proj_367;
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
  $ff_proj_366 = *((value *) $env_363 + 1);
  $t_proj_367 = *((value *) $env_363 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value, value)) y_known_136)
    ($tinfo, $n_364, $ff_proj_366, $t_proj_367);
  return $result;
}

value y_known_136(struct thread_info *$tinfo, value $n_351, value $ff_352, value $t_353)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_354;
  register value $prim_355;
  register value $r_357;
  register value $d_358;
  register value $prim_359;
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
  $prim_354 = ((value (*)(void)) bench_lit_254)();
  $prim_355 = ((value (*)(value, value)) bench_nat_eqb)($n_351, $prim_354);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $ff_352;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $r_357 =
    ((value (*)(struct thread_info *, value, value, value)) dec_uncurried_uncurried_known_132)
    ($tinfo, $t_353, $prim_355, $n_351);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(5 <= $limit - $alloc)) {
    *(root + 1) = $r_357;
    frame.next = root + 2;
    (*$tinfo).nalloc = 5;
    garbage_collect($tinfo);
    $r_357 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $ff_352 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($ff_352 & 1) == 0) {
    switch (*((value *) $ff_352 + -1) & 255) {
      
    }
  } else {
    switch ($ff_352 >> 1) {
      case 0:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $r_357;
        break;
      default:
        if (($r_357 & 1) == 0) {
          switch (*((value *) $r_357 + -1) & 255) {
            default:
              $d_358 = *((value *) $r_357 + 0);
              $prim_359 = ((value (*)(void)) bench_nat_zero)();
              $y_360 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_360 + -1) = 2048;
              *((value *) $y_360 + 0) = $prim_359;
              *((value *) $y_360 + 1) = $d_358;
              $y_361 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $y_361 + -1) = 1024;
              *((value *) $y_361 + 0) = $y_360;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_361;
              break;
            
          }
        } else {
          switch ($r_357 >> 1) {
            default:
              $y_362 = 1;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_362;
              break;
            
          }
        }
        break;
      
    }
  }
}

value y_wrapper_135(struct thread_info *$tinfo, value $env_347, value $anon_348)
{
  struct stack_frame frame;
  value root[0];
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
  $y_349 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_349;
}

value y_wrapper_134(struct thread_info *$tinfo, value $env_344, value $n_345)
{
  struct stack_frame frame;
  value root[0];
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
  $y_346 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_346;
}

value y_wrapper_133(struct thread_info *$tinfo, value $env_340, value $anon_341)
{
  struct stack_frame frame;
  value root[0];
  register value $y_342;
  register value $y_343;
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
  if (!(2 <= $limit - $alloc)) {
    /*skip*/;
    (*$tinfo).nalloc = 2;
    garbage_collect($tinfo);
    /*skip*/;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $y_342 = 1;
  $y_343 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $y_343 + -1) = 1024;
  *((value *) $y_343 + 0) = $y_342;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_343;
}

value dec_uncurried_uncurried_known_132(struct thread_info *$tinfo, value $l_325, value $ff_326, value $k_327)
{
  struct stack_frame frame;
  value root[3];
  register value $env_328;
  register value $env_329;
  register value $y_wrapper_clo_330;
  register value $y_wrapper_clo_331;
  register value $prim_332;
  register value $x_333;
  register value $t_334;
  register value $env_335;
  register value $env_336;
  register value $y_wrapper_clo_337;
  register value $y_wrapper_clo_338;
  register value $prim_339;
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
  if (!(14 <= $limit - $alloc)) {
    *(root + 2) = $k_327;
    *(root + 1) = $ff_326;
    *(root + 0) = $l_325;
    frame.next = root + 3;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 14;
    garbage_collect($tinfo);
    $k_327 = *(root + 2);
    $ff_326 = *(root + 1);
    $l_325 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_325 & 1) == 0) {
    switch (*((value *) $l_325 + -1) & 255) {
      default:
        $x_333 = *((value *) $l_325 + 0);
        $t_334 = *((value *) $l_325 + 1);
        $env_335 = (value) ($alloc + 1);
        $alloc = $alloc + 4;
        *((value *) $env_335 + -1) = 3072;
        *((value *) $env_335 + 0) = $ff_326;
        *((value *) $env_335 + 1) = $x_333;
        *((value *) $env_335 + 2) = $t_334;
        $env_336 = (value) ($alloc + 1);
        $alloc = $alloc + 4;
        *((value *) $env_336 + -1) = 3072;
        *((value *) $env_336 + 0) = $ff_326;
        *((value *) $env_336 + 1) = $x_333;
        *((value *) $env_336 + 2) = $t_334;
        $y_wrapper_clo_337 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_337 + -1) = 2048;
        *((value *) $y_wrapper_clo_337 + 0) = y_wrapper_138;
        *((value *) $y_wrapper_clo_337 + 1) = $env_335;
        $y_wrapper_clo_338 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_338 + -1) = 2048;
        *((value *) $y_wrapper_clo_338 + 0) = y_wrapper_142;
        *((value *) $y_wrapper_clo_338 + 1) = $env_336;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_339 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $k_327, $y_wrapper_clo_337, $y_wrapper_clo_338);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_339;
        break;
      
    }
  } else {
    switch ($l_325 >> 1) {
      default:
        $env_328 = 1;
        $env_329 = 1;
        $y_wrapper_clo_330 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_330 + -1) = 2048;
        *((value *) $y_wrapper_clo_330 + 0) = y_wrapper_133;
        *((value *) $y_wrapper_clo_330 + 1) = $env_328;
        $y_wrapper_clo_331 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_331 + -1) = 2048;
        *((value *) $y_wrapper_clo_331 + 0) = y_wrapper_134;
        *((value *) $y_wrapper_clo_331 + 1) = $env_329;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_332 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $k_327, $y_wrapper_clo_330, $y_wrapper_clo_331);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_332;
        break;
      
    }
  }
}

value f_case_known_131(struct thread_info *$tinfo, value $s_318, value $e_319)
{
  struct stack_frame frame;
  value root[2];
  register value $y_320;
  register value $prim_321;
  register value $y_322;
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
  if (($s_318 & 1) == 0) {
    switch (*((value *) $s_318 + -1) & 255) {
      default:
        $prim_321 = ((value (*)(void)) bench_nat_zero)();
        $y_322 = 1;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        $result =
          ((value (*)(struct thread_info *, value, value, value)) dec_uncurried_uncurried_known_132)
          ($tinfo, $e_319, $y_322, $prim_321);
        return $result;
        break;
      
    }
  } else {
    switch ($s_318 >> 1) {
      default:
        $y_320 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_320;
        break;
      
    }
  }
}

value y_wrapper_130(struct thread_info *$tinfo, value $env_313, value $kp_314)
{
  struct stack_frame frame;
  value root[2];
  register value $l_proj_316;
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
  $l_proj_316 = *((value *) $env_313 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_129)
    ($tinfo, $kp_314, $l_proj_316);
  return $result;
}

value y_known_129(struct thread_info *$tinfo, value $kp_297, value $l_298)
{
  struct stack_frame frame;
  value root[2];
  register value $y_299;
  register value $y_300;
  register value $y_301;
  register value $x_302;
  register value $t_303;
  register value $env_304;
  register value $env_305;
  register value $y_wrapper_clo_306;
  register value $y_wrapper_clo_307;
  register value $prim_308;
  register value $a_309;
  register value $b_310;
  register value $y_311;
  register value $y_312;
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
  if (!(16 <= $limit - $alloc)) {
    *(root + 1) = $l_298;
    *(root + 0) = $kp_297;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 16;
    garbage_collect($tinfo);
    $l_298 = *(root + 1);
    $kp_297 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_298 & 1) == 0) {
    switch (*((value *) $l_298 + -1) & 255) {
      default:
        $x_302 = *((value *) $l_298 + 0);
        $t_303 = *((value *) $l_298 + 1);
        $env_304 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_304 + -1) = 1024;
        *((value *) $env_304 + 0) = $t_303;
        $env_305 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_305 + -1) = 1024;
        *((value *) $env_305 + 0) = $t_303;
        $y_wrapper_clo_306 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_306 + -1) = 2048;
        *((value *) $y_wrapper_clo_306 + 0) = y_wrapper_128;
        *((value *) $y_wrapper_clo_306 + 1) = $env_304;
        $y_wrapper_clo_307 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_307 + -1) = 2048;
        *((value *) $y_wrapper_clo_307 + 0) = y_wrapper_130;
        *((value *) $y_wrapper_clo_307 + 1) = $env_305;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_302;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_308 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $kp_297, $y_wrapper_clo_306, $y_wrapper_clo_307);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(6 <= $limit - $alloc)) {
          *(root + 1) = $prim_308;
          frame.next = root + 2;
          (*$tinfo).nalloc = 6;
          garbage_collect($tinfo);
          $prim_308 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $x_302 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_308 & 1) == 0) {
          switch (*((value *) $prim_308 + -1) & 255) {
            default:
              $a_309 = *((value *) $prim_308 + 0);
              $b_310 = *((value *) $prim_308 + 1);
              $y_311 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_311 + -1) = 2048;
              *((value *) $y_311 + 0) = $x_302;
              *((value *) $y_311 + 1) = $a_309;
              $y_312 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_312 + -1) = 2048;
              *((value *) $y_312 + 0) = $y_311;
              *((value *) $y_312 + 1) = $b_310;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_312;
              break;
            
          }
        } else {
          switch ($prim_308 >> 1) {
            
          }
        }
        break;
      
    }
  } else {
    switch ($l_298 >> 1) {
      default:
        $y_299 = 1;
        $y_300 = 1;
        $y_301 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_301 + -1) = 2048;
        *((value *) $y_301 + 0) = $y_299;
        *((value *) $y_301 + 1) = $y_300;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_301;
        break;
      
    }
  }
}

value y_wrapper_128(struct thread_info *$tinfo, value $env_291, value $anon_292)
{
  struct stack_frame frame;
  value root[1];
  register value $l_proj_293;
  register value $y_294;
  register value $y_295;
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
    *(root + 0) = $env_291;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $env_291 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $l_proj_293 = *((value *) $env_291 + 0);
  $y_294 = 1;
  $y_295 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_295 + -1) = 2048;
  *((value *) $y_295 + 0) = $y_294;
  *((value *) $y_295 + 1) = $l_proj_293;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_295;
}

value y_wrapper_127(struct thread_info *$tinfo, value $env_287, value $kp_288)
{
  struct stack_frame frame;
  value root[2];
  register value $t_proj_289;
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
  $t_proj_289 = *((value *) $env_287 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) fits_uncurried_known_125)
    ($tinfo, $t_proj_289, $kp_288);
  return $result;
}

value y_wrapper_126(struct thread_info *$tinfo, value $env_284, value $anon_285)
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
  $y_286 = 3;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_286;
}

value fits_uncurried_known_125(struct thread_info *$tinfo, value $l_275, value $k_276)
{
  struct stack_frame frame;
  value root[2];
  register value $y_277;
  register value $t_278;
  register value $env_279;
  register value $env_280;
  register value $y_wrapper_clo_281;
  register value $y_wrapper_clo_282;
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
  if (!(8 <= $limit - $alloc)) {
    *(root + 1) = $k_276;
    *(root + 0) = $l_275;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $k_276 = *(root + 1);
    $l_275 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_275 & 1) == 0) {
    switch (*((value *) $l_275 + -1) & 255) {
      default:
        $t_278 = *((value *) $l_275 + 1);
        $env_279 = 1;
        $env_280 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_280 + -1) = 1024;
        *((value *) $env_280 + 0) = $t_278;
        $y_wrapper_clo_281 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_281 + -1) = 2048;
        *((value *) $y_wrapper_clo_281 + 0) = y_wrapper_126;
        *((value *) $y_wrapper_clo_281 + 1) = $env_279;
        $y_wrapper_clo_282 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_282 + -1) = 2048;
        *((value *) $y_wrapper_clo_282 + 0) = y_wrapper_127;
        *((value *) $y_wrapper_clo_282 + 1) = $env_280;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_283 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $k_276, $y_wrapper_clo_281, $y_wrapper_clo_282);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_283;
        break;
      
    }
  } else {
    switch ($l_275 >> 1) {
      default:
        $y_277 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_277;
        break;
      
    }
  }
}

value y_124(struct thread_info *$tinfo, value $env_242, value $f_243)
{
  struct stack_frame frame;
  value root[3];
  register value $prim_244;
  register value $prim_245;
  register value $p_proj_247;
  register value $y_248;
  register value $p_proj_249;
  register value $y_251;
  register value $prim_252;
  register value $p_proj_253;
  register value $y_254;
  register value $prim_255;
  register value $p_proj_256;
  register value $env_257;
  register value $env_258;
  register value $y_wrapper_clo_259;
  register value $y_wrapper_clo_260;
  register value $prim_261;
  register value $a_262;
  register value $b_263;
  register value $prim_264;
  register value $prim_265;
  register value $env_266;
  register value $env_267;
  register value $y_wrapper_clo_268;
  register value $y_clo_269;
  register value $prim_270;
  register value $y_272;
  register value $y_273;
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
  $prim_244 = ((value (*)(void)) bench_lit_254)();
  $prim_245 = ((value (*)(value)) bench_nat_pred)($prim_244);
  $p_proj_247 = *((value *) $env_242 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 1) = $f_243;
  *(root + 0) = $env_242;
  frame.next = root + 2;
  (*$tinfo).fp = &frame;
  $y_248 =
    ((value (*)(struct thread_info *, value, value)) fits_uncurried_known_125)
    ($tinfo, $p_proj_247, $prim_245);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(20 <= $limit - $alloc)) {
    *(root + 2) = $y_248;
    frame.next = root + 3;
    (*$tinfo).nalloc = 20;
    garbage_collect($tinfo);
    $y_248 = *(root + 2);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $f_243 = *(root + 1);
  $env_242 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  if (($y_248 & 1) == 0) {
    switch (*((value *) $y_248 + -1) & 255) {
      
    }
  } else {
    switch ($y_248 >> 1) {
      case 0:
        $p_proj_249 = *((value *) $env_242 + 0);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $env_242;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_251 =
          ((value (*)(struct thread_info *, value)) length_known_114)
          ($tinfo, $p_proj_249);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 1) = $y_251;
          frame.next = root + 2;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $y_251 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $env_242 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $prim_252 = ((value (*)(value)) bench_nat_succ)($y_251);
        $p_proj_253 = *((value *) $env_242 + 0);
        $y_254 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_254 + -1) = 2048;
        *((value *) $y_254 + 0) = $prim_252;
        *((value *) $y_254 + 1) = $p_proj_253;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_254;
        break;
      default:
        $prim_255 = ((value (*)(void)) bench_lit_254)();
        $p_proj_256 = *((value *) $env_242 + 0);
        $env_257 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_257 + -1) = 1024;
        *((value *) $env_257 + 0) = $p_proj_256;
        $env_258 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_258 + -1) = 1024;
        *((value *) $env_258 + 0) = $p_proj_256;
        $y_wrapper_clo_259 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_259 + -1) = 2048;
        *((value *) $y_wrapper_clo_259 + 0) = y_wrapper_128;
        *((value *) $y_wrapper_clo_259 + 1) = $env_257;
        $y_wrapper_clo_260 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_260 + -1) = 2048;
        *((value *) $y_wrapper_clo_260 + 0) = y_wrapper_130;
        *((value *) $y_wrapper_clo_260 + 1) = $env_258;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $f_243;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_261 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $prim_255, $y_wrapper_clo_259, $y_wrapper_clo_260);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(10 <= $limit - $alloc)) {
          *(root + 1) = $prim_261;
          frame.next = root + 2;
          (*$tinfo).nalloc = 10;
          garbage_collect($tinfo);
          $prim_261 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $f_243 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        if (($prim_261 & 1) == 0) {
          switch (*((value *) $prim_261 + -1) & 255) {
            default:
              $a_262 = *((value *) $prim_261 + 0);
              $b_263 = *((value *) $prim_261 + 1);
              $prim_264 = ((value (*)(void)) bench_lit_254)();
              $prim_265 = ((value (*)(value)) bench_nat_succ)($prim_264);
              $env_266 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $env_266 + -1) = 1024;
              *((value *) $env_266 + 0) = $b_263;
              $env_267 = (value) ($alloc + 1);
              $alloc = $alloc + 2;
              *((value *) $env_267 + -1) = 1024;
              *((value *) $env_267 + 0) = $b_263;
              $y_wrapper_clo_268 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_wrapper_clo_268 + -1) = 2048;
              *((value *) $y_wrapper_clo_268 + 0) = y_wrapper_123;
              *((value *) $y_wrapper_clo_268 + 1) = $env_266;
              $y_clo_269 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_clo_269 + -1) = 2048;
              *((value *) $y_clo_269 + 0) = y_124;
              *((value *) $y_clo_269 + 1) = $env_267;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 1) = $prim_265;
              *(root + 0) = $a_262;
              frame.next = root + 2;
              (*$tinfo).fp = &frame;
              $prim_270 =
                ((value (*)(struct thread_info *, value, value, value)) 
                  bench_nat_case)
                ($tinfo, $f_243, $y_wrapper_clo_268, $y_clo_269);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              $prim_265 = *(root + 1);
              $a_262 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $args = (*$tinfo).args;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              *(root + 0) = $prim_265;
              frame.next = root + 1;
              (*$tinfo).fp = &frame;
              $y_272 =
                ((value (*)(struct thread_info *, value, value)) app_uncurried_known_113)
                ($tinfo, $prim_270, $a_262);
              $alloc = (*$tinfo).alloc;
              $limit = (*$tinfo).limit;
              if (!(3 <= $limit - $alloc)) {
                *(root + 1) = $y_272;
                frame.next = root + 2;
                (*$tinfo).nalloc = 3;
                garbage_collect($tinfo);
                $y_272 = *(root + 1);
                $alloc = (*$tinfo).alloc;
                $limit = (*$tinfo).limit;
              }
              $prim_265 = *(root + 0);
              (*$tinfo).fp = frame.prev;
              $y_273 = (value) ($alloc + 1);
              $alloc = $alloc + 3;
              *((value *) $y_273 + -1) = 2048;
              *((value *) $y_273 + 0) = $prim_265;
              *((value *) $y_273 + 1) = $y_272;
              (*$tinfo).alloc = $alloc;
              (*$tinfo).limit = $limit;
              return $y_273;
              break;
            
          }
        } else {
          switch ($prim_261 >> 1) {
            
          }
        }
        break;
      
    }
  }
}

value y_wrapper_123(struct thread_info *$tinfo, value $env_235, value $anon_236)
{
  struct stack_frame frame;
  value root[2];
  register value $p_proj_237;
  register value $y_239;
  register value $prim_240;
  register value $y_241;
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
  $p_proj_237 = *((value *) $env_235 + 0);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $p_proj_237;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $y_239 =
    ((value (*)(struct thread_info *, value)) length_known_114)
    ($tinfo, $p_proj_237);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $y_239;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $y_239 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $p_proj_237 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $prim_240 = ((value (*)(value)) bench_nat_succ)($y_239);
  $y_241 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_241 + -1) = 2048;
  *((value *) $y_241 + 0) = $prim_240;
  *((value *) $y_241 + 1) = $p_proj_237;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_241;
}

value enc_pieces_known_122(struct thread_info *$tinfo, value $ps_222)
{
  struct stack_frame frame;
  value root[3];
  register value $y_223;
  register value $p_224;
  register value $psp_225;
  register value $y_227;
  register value $env_228;
  register value $env_229;
  register value $y_wrapper_clo_230;
  register value $y_clo_231;
  register value $prim_232;
  register value $y_233;
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
  if (($ps_222 & 1) == 0) {
    switch (*((value *) $ps_222 + -1) & 255) {
      default:
        $p_224 = *((value *) $ps_222 + 0);
        $psp_225 = *((value *) $ps_222 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 1) = $psp_225;
        *(root + 0) = $p_224;
        frame.next = root + 2;
        (*$tinfo).fp = &frame;
        $y_227 =
          ((value (*)(struct thread_info *, value)) length_known_114)
          ($tinfo, $p_224);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(10 <= $limit - $alloc)) {
          *(root + 2) = $y_227;
          frame.next = root + 3;
          (*$tinfo).nalloc = 10;
          garbage_collect($tinfo);
          $y_227 = *(root + 2);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $psp_225 = *(root + 1);
        $p_224 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $env_228 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_228 + -1) = 1024;
        *((value *) $env_228 + 0) = $p_224;
        $env_229 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_229 + -1) = 1024;
        *((value *) $env_229 + 0) = $p_224;
        $y_wrapper_clo_230 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_230 + -1) = 2048;
        *((value *) $y_wrapper_clo_230 + 0) = y_wrapper_123;
        *((value *) $y_wrapper_clo_230 + 1) = $env_228;
        $y_clo_231 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_clo_231 + -1) = 2048;
        *((value *) $y_clo_231 + 0) = y_124;
        *((value *) $y_clo_231 + 1) = $env_229;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $psp_225;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $prim_232 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $y_227, $y_wrapper_clo_230, $y_clo_231);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $psp_225 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $prim_232;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_233 =
          ((value (*)(struct thread_info *, value)) enc_pieces_known_122)
          ($tinfo, $psp_225);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        $prim_232 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        $result =
          ((value (*)(struct thread_info *, value, value)) app_uncurried_known_113)
          ($tinfo, $y_233, $prim_232);
        return $result;
        break;
      
    }
  } else {
    switch ($ps_222 >> 1) {
      default:
        $y_223 = 1;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_223;
        break;
      
    }
  }
}

value y_wrapper_121(struct thread_info *$tinfo, value $env_216, value $n_217)
{
  struct stack_frame frame;
  value root[1];
  register value $x_proj_219;
  register value $ps_proj_220;
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
  $x_proj_219 = *((value *) $env_216 + 0);
  $ps_proj_220 = *((value *) $env_216 + 1);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_120)
    ($tinfo, $x_proj_219, $ps_proj_220);
  return $result;
}

value y_known_120(struct thread_info *$tinfo, value $x_206, value $ps_207)
{
  struct stack_frame frame;
  value root[2];
  register value $y_208;
  register value $y_209;
  register value $y_210;
  register value $y_211;
  register value $p_212;
  register value $psp_213;
  register value $y_214;
  register value $y_215;
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
    *(root + 1) = $ps_207;
    *(root + 0) = $x_206;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 6;
    garbage_collect($tinfo);
    $ps_207 = *(root + 1);
    $x_206 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($ps_207 & 1) == 0) {
    switch (*((value *) $ps_207 + -1) & 255) {
      default:
        $p_212 = *((value *) $ps_207 + 0);
        $psp_213 = *((value *) $ps_207 + 1);
        $y_214 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_214 + -1) = 2048;
        *((value *) $y_214 + 0) = $x_206;
        *((value *) $y_214 + 1) = $p_212;
        $y_215 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_215 + -1) = 2048;
        *((value *) $y_215 + 0) = $y_214;
        *((value *) $y_215 + 1) = $psp_213;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_215;
        break;
      
    }
  } else {
    switch ($ps_207 >> 1) {
      default:
        $y_208 = 1;
        $y_209 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_209 + -1) = 2048;
        *((value *) $y_209 + 0) = $x_206;
        *((value *) $y_209 + 1) = $y_208;
        $y_210 = 1;
        $y_211 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_211 + -1) = 2048;
        *((value *) $y_211 + 0) = $y_209;
        *((value *) $y_211 + 1) = $y_210;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_211;
        break;
      
    }
  }
}

value y_wrapper_119(struct thread_info *$tinfo, value $env_199, value $anon_200)
{
  struct stack_frame frame;
  value root[1];
  register value $ps_proj_201;
  register value $y_202;
  register value $y_203;
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
    *(root + 0) = $env_199;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $env_199 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $ps_proj_201 = *((value *) $env_199 + 0);
  $y_202 = 1;
  $y_203 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_203 + -1) = 2048;
  *((value *) $y_203 + 0) = $y_202;
  *((value *) $y_203 + 1) = $ps_proj_201;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_203;
}

value split_zero_known_118(struct thread_info *$tinfo, value $l_187)
{
  struct stack_frame frame;
  value root[2];
  register value $y_188;
  register value $y_189;
  register value $y_190;
  register value $x_191;
  register value $t_192;
  register value $ps_193;
  register value $env_194;
  register value $env_195;
  register value $y_wrapper_clo_196;
  register value $y_wrapper_clo_197;
  register value $prim_198;
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
    *(root + 0) = $l_187;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $l_187 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  if (($l_187 & 1) == 0) {
    switch (*((value *) $l_187 + -1) & 255) {
      default:
        $x_191 = *((value *) $l_187 + 0);
        $t_192 = *((value *) $l_187 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $x_191;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $ps_193 =
          ((value (*)(struct thread_info *, value)) split_zero_known_118)
          ($tinfo, $t_192);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(11 <= $limit - $alloc)) {
          *(root + 1) = $ps_193;
          frame.next = root + 2;
          (*$tinfo).nalloc = 11;
          garbage_collect($tinfo);
          $ps_193 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $x_191 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $env_194 = (value) ($alloc + 1);
        $alloc = $alloc + 2;
        *((value *) $env_194 + -1) = 1024;
        *((value *) $env_194 + 0) = $ps_193;
        $env_195 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $env_195 + -1) = 2048;
        *((value *) $env_195 + 0) = $x_191;
        *((value *) $env_195 + 1) = $ps_193;
        $y_wrapper_clo_196 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_196 + -1) = 2048;
        *((value *) $y_wrapper_clo_196 + 0) = y_wrapper_119;
        *((value *) $y_wrapper_clo_196 + 1) = $env_194;
        $y_wrapper_clo_197 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_wrapper_clo_197 + -1) = 2048;
        *((value *) $y_wrapper_clo_197 + 0) = y_wrapper_121;
        *((value *) $y_wrapper_clo_197 + 1) = $env_195;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $prim_198 =
          ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
          ($tinfo, $x_191, $y_wrapper_clo_196, $y_wrapper_clo_197);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_198;
        break;
      
    }
  } else {
    switch ($l_187 >> 1) {
      default:
        $y_188 = 1;
        $y_189 = 1;
        $y_190 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_190 + -1) = 2048;
        *((value *) $y_190 + 0) = $y_188;
        *((value *) $y_190 + 1) = $y_189;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_190;
        break;
      
    }
  }
}

value y_wrapper_117(struct thread_info *$tinfo, value $env_175, value $np_176)
{
  struct stack_frame frame;
  value root[2];
  register value $pos_proj_177;
  register value $prim_178;
  register value $prim_179;
  register value $env_180;
  register value $env_181;
  register value $y_wrapper_clo_182;
  register value $y_wrapper_clo_183;
  register value $prim_184;
  register value $y_185;
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
    *(root + 1) = $np_176;
    *(root + 0) = $env_175;
    frame.next = root + 2;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 11;
    garbage_collect($tinfo);
    $np_176 = *(root + 1);
    $env_175 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $pos_proj_177 = *((value *) $env_175 + 0);
  $prim_178 = ((value (*)(value)) bench_input_byte)($pos_proj_177);
  $prim_179 = ((value (*)(value)) bench_nat_succ)($pos_proj_177);
  $env_180 = 1;
  $env_181 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_181 + -1) = 1024;
  *((value *) $env_181 + 0) = $prim_179;
  $y_wrapper_clo_182 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_182 + -1) = 2048;
  *((value *) $y_wrapper_clo_182 + 0) = y_wrapper_116;
  *((value *) $y_wrapper_clo_182 + 1) = $env_180;
  $y_wrapper_clo_183 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_183 + -1) = 2048;
  *((value *) $y_wrapper_clo_183 + 0) = y_wrapper_117;
  *((value *) $y_wrapper_clo_183 + 1) = $env_181;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $prim_178;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $prim_184 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $np_176, $y_wrapper_clo_182, $y_wrapper_clo_183);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $prim_184;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $prim_184 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_178 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_185 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_185 + -1) = 2048;
  *((value *) $y_185 + 0) = $prim_178;
  *((value *) $y_185 + 1) = $prim_184;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_185;
}

value y_wrapper_116(struct thread_info *$tinfo, value $env_172, value $anon_173)
{
  struct stack_frame frame;
  value root[0];
  register value $y_174;
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
  $y_174 = 1;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_174;
}

value CompileCdc_roundtrip_known_115(struct thread_info *$tinfo, value $n_158)
{
  struct stack_frame frame;
  value root[2];
  register value $prim_159;
  register value $env_160;
  register value $env_161;
  register value $y_wrapper_clo_162;
  register value $y_wrapper_clo_163;
  register value $prim_164;
  register value $y_166;
  register value $e_168;
  register value $y_170;
  register value $y_171;
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
    *(root + 0) = $n_158;
    frame.next = root + 1;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 8;
    garbage_collect($tinfo);
    $n_158 = *(root + 0);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $prim_159 = ((value (*)(void)) bench_nat_zero)();
  $env_160 = 1;
  $env_161 = (value) ($alloc + 1);
  $alloc = $alloc + 2;
  *((value *) $env_161 + -1) = 1024;
  *((value *) $env_161 + 0) = $prim_159;
  $y_wrapper_clo_162 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_162 + -1) = 2048;
  *((value *) $y_wrapper_clo_162 + 0) = y_wrapper_116;
  *((value *) $y_wrapper_clo_162 + 1) = $env_160;
  $y_wrapper_clo_163 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_wrapper_clo_163 + -1) = 2048;
  *((value *) $y_wrapper_clo_163 + 0) = y_wrapper_117;
  *((value *) $y_wrapper_clo_163 + 1) = $env_161;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_164 =
    ((value (*)(struct thread_info *, value, value, value)) bench_nat_case)
    ($tinfo, $n_158, $y_wrapper_clo_162, $y_wrapper_clo_163);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $y_166 =
    ((value (*)(struct thread_info *, value)) split_zero_known_118)
    ($tinfo, $prim_164);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $e_168 =
    ((value (*)(struct thread_info *, value)) enc_pieces_known_122)
    ($tinfo, $y_166);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  *(root + 0) = $e_168;
  frame.next = root + 1;
  (*$tinfo).fp = &frame;
  $y_170 =
    ((value (*)(struct thread_info *, value, value)) f_case_known_131)
    ($tinfo, $e_168, $e_168);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  if (!(3 <= $limit - $alloc)) {
    *(root + 1) = $y_170;
    frame.next = root + 2;
    (*$tinfo).nalloc = 3;
    garbage_collect($tinfo);
    $y_170 = *(root + 1);
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $e_168 = *(root + 0);
  (*$tinfo).fp = frame.prev;
  $y_171 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $y_171 + -1) = 2048;
  *((value *) $y_171 + 0) = $e_168;
  *((value *) $y_171 + 1) = $y_170;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_171;
}

value length_known_114(struct thread_info *$tinfo, value $l_152)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_153;
  register value $lp_154;
  register value $y_155;
  register value $prim_156;
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
  if (($l_152 & 1) == 0) {
    switch (*((value *) $l_152 + -1) & 255) {
      default:
        $lp_154 = *((value *) $l_152 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        /*skip*/;
        $y_155 =
          ((value (*)(struct thread_info *, value)) length_known_114)
          ($tinfo, $lp_154);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        /*skip*/;
        $prim_156 = ((value (*)(value)) bench_nat_succ)($y_155);
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_156;
        break;
      
    }
  } else {
    switch ($l_152 >> 1) {
      default:
        $prim_153 = ((value (*)(void)) bench_nat_zero)();
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $prim_153;
        break;
      
    }
  }
}

value app_uncurried_known_113(struct thread_info *$tinfo, value $m_145, value $l_146)
{
  struct stack_frame frame;
  value root[2];
  register value $a_147;
  register value $l1_148;
  register value $y_149;
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
  if (($l_146 & 1) == 0) {
    switch (*((value *) $l_146 + -1) & 255) {
      default:
        $a_147 = *((value *) $l_146 + 0);
        $l1_148 = *((value *) $l_146 + 1);
        $args = (*$tinfo).args;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        *(root + 0) = $a_147;
        frame.next = root + 1;
        (*$tinfo).fp = &frame;
        $y_149 =
          ((value (*)(struct thread_info *, value, value)) app_uncurried_known_113)
          ($tinfo, $m_145, $l1_148);
        $alloc = (*$tinfo).alloc;
        $limit = (*$tinfo).limit;
        if (!(3 <= $limit - $alloc)) {
          *(root + 1) = $y_149;
          frame.next = root + 2;
          (*$tinfo).nalloc = 3;
          garbage_collect($tinfo);
          $y_149 = *(root + 1);
          $alloc = (*$tinfo).alloc;
          $limit = (*$tinfo).limit;
        }
        $a_147 = *(root + 0);
        (*$tinfo).fp = frame.prev;
        $y_150 = (value) ($alloc + 1);
        $alloc = $alloc + 3;
        *((value *) $y_150 + -1) = 2048;
        *((value *) $y_150 + 0) = $a_147;
        *((value *) $y_150 + 1) = $y_149;
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $y_150;
        break;
      
    }
  } else {
    switch ($l_146 >> 1) {
      default:
        (*$tinfo).alloc = $alloc;
        (*$tinfo).limit = $limit;
        return $m_145;
        break;
      
    }
  }
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
  register value $prim_413;
  register value $prim_414;
  register value $prim_415;
  register value $prim_416;
  register value $prim_417;
  register value $prim_418;
  register value $prim_419;
  register value $prim_420;
  register value $prim_421;
  register value $prim_422;
  register value $prim_423;
  register value $prim_424;
  register value $prim_425;
  register value $prim_426;
  register value $prim_427;
  register value $prim_428;
  register value $prim_429;
  register value $prim_430;
  register value $prim_431;
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
  register value $env_668;
  register value $CompileCdc_roundtrip_wrapper_clo_669;
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
  $prim_413 = ((value (*)(void)) bench_nat_zero)();
  $prim_414 = ((value (*)(value)) bench_nat_succ)($prim_413);
  $prim_415 = ((value (*)(value)) bench_nat_succ)($prim_414);
  $prim_416 = ((value (*)(value)) bench_nat_succ)($prim_415);
  $prim_417 = ((value (*)(value)) bench_nat_succ)($prim_416);
  $prim_418 = ((value (*)(value)) bench_nat_succ)($prim_417);
  $prim_419 = ((value (*)(value)) bench_nat_succ)($prim_418);
  $prim_420 = ((value (*)(value)) bench_nat_succ)($prim_419);
  $prim_421 = ((value (*)(value)) bench_nat_succ)($prim_420);
  $prim_422 = ((value (*)(value)) bench_nat_succ)($prim_421);
  $prim_423 = ((value (*)(value)) bench_nat_succ)($prim_422);
  $prim_424 = ((value (*)(value)) bench_nat_succ)($prim_423);
  $prim_425 = ((value (*)(value)) bench_nat_succ)($prim_424);
  $prim_426 = ((value (*)(value)) bench_nat_succ)($prim_425);
  $prim_427 = ((value (*)(value)) bench_nat_succ)($prim_426);
  $prim_428 = ((value (*)(value)) bench_nat_succ)($prim_427);
  $prim_429 = ((value (*)(value)) bench_nat_succ)($prim_428);
  $prim_430 = ((value (*)(value)) bench_nat_succ)($prim_429);
  $prim_431 = ((value (*)(value)) bench_nat_succ)($prim_430);
  $prim_432 = ((value (*)(value)) bench_nat_succ)($prim_431);
  $prim_433 = ((value (*)(value)) bench_nat_succ)($prim_432);
  $prim_434 = ((value (*)(value)) bench_nat_succ)($prim_433);
  $prim_435 = ((value (*)(value)) bench_nat_succ)($prim_434);
  $prim_436 = ((value (*)(value)) bench_nat_succ)($prim_435);
  $prim_437 = ((value (*)(value)) bench_nat_succ)($prim_436);
  $prim_438 = ((value (*)(value)) bench_nat_succ)($prim_437);
  $prim_439 = ((value (*)(value)) bench_nat_succ)($prim_438);
  $prim_440 = ((value (*)(value)) bench_nat_succ)($prim_439);
  $prim_441 = ((value (*)(value)) bench_nat_succ)($prim_440);
  $prim_442 = ((value (*)(value)) bench_nat_succ)($prim_441);
  $prim_443 = ((value (*)(value)) bench_nat_succ)($prim_442);
  $prim_444 = ((value (*)(value)) bench_nat_succ)($prim_443);
  $prim_445 = ((value (*)(value)) bench_nat_succ)($prim_444);
  $prim_446 = ((value (*)(value)) bench_nat_succ)($prim_445);
  $prim_447 = ((value (*)(value)) bench_nat_succ)($prim_446);
  $prim_448 = ((value (*)(value)) bench_nat_succ)($prim_447);
  $prim_449 = ((value (*)(value)) bench_nat_succ)($prim_448);
  $prim_450 = ((value (*)(value)) bench_nat_succ)($prim_449);
  $prim_451 = ((value (*)(value)) bench_nat_succ)($prim_450);
  $prim_452 = ((value (*)(value)) bench_nat_succ)($prim_451);
  $prim_453 = ((value (*)(value)) bench_nat_succ)($prim_452);
  $prim_454 = ((value (*)(value)) bench_nat_succ)($prim_453);
  $prim_455 = ((value (*)(value)) bench_nat_succ)($prim_454);
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
  $env_668 = 1;
  $CompileCdc_roundtrip_wrapper_clo_669 = (value) ($alloc + 1);
  $alloc = $alloc + 3;
  *((value *) $CompileCdc_roundtrip_wrapper_clo_669 + -1) = 2048;
  *((value *) $CompileCdc_roundtrip_wrapper_clo_669 + 0) =
    CompileCdc_roundtrip_wrapper_143;
  *((value *) $CompileCdc_roundtrip_wrapper_clo_669 + 1) = $env_668;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $CompileCdc_roundtrip_wrapper_clo_669;
}


#endif /* W6_COBS_C */
