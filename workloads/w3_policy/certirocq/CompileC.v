(** Variant C of W3: compile [run] (theories/Policy.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W3 Require Import Policy.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  elem_len => "bench_lit_4",
  range_len => "bench_lit_8",
  amount_len => "bench_lit_8",
  addr_len => "bench_lit_20",
  hdr_len => "bench_lit_3",
  byte_base => "bench_lit_256",
  code_dest => "bench_lit_1",
  code_amount => "bench_lit_2",
  code_path => "bench_lit_3"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w3_policy" run.
