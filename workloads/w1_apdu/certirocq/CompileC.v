(** Variant C of W1: compile [run] (theories/Apdu.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W1 Require Import Apdu.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  tag_mask => "bench_lit_31",
  constructed_bit => "bench_lit_32",
  high_bit => "bench_lit_128",
  len_one => "bench_lit_129",
  len_two => "bench_lit_130",
  byte_base => "bench_lit_256"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w1_apdu" run.
