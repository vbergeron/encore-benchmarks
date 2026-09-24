(** Variant C of W5: compile [run] (theories/Update.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W5 Require Import Update.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  byte_base => "bench_lit_256",
  modulus => "bench_lit_65521",
  radix => "bench_lit_31",
  factory_version => "bench_lit_1",
  ev_begin => "bench_lit_1",
  ev_chunk => "bench_lit_2",
  ev_finish => "bench_lit_3",
  ev_confirm => "bench_lit_4",
  ev_reboot => "bench_lit_5",
  ev_cut => "bench_lit_6",
  code_busy => "bench_lit_1",
  code_rollback => "bench_lit_2",
  code_unexpected => "bench_lit_3",
  code_bad_image => "bench_lit_4",
  code_bad_event => "bench_lit_5",
  code_booted => "bench_lit_8"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w5_update" run.
