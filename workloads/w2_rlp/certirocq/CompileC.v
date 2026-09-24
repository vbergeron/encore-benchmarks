(** Variant C of W2: compile [run] (theories/Rlp.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W2 Require Import Rlp.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  str_off => "bench_lit_128",
  str_long => "bench_lit_184",
  str_long_base => "bench_lit_183",
  list_off => "bench_lit_192",
  list_long => "bench_lit_248",
  list_long_base => "bench_lit_247",
  short_max => "bench_lit_56",
  long_one => "bench_lit_56",
  long_two => "bench_lit_57",
  byte_base => "bench_lit_256",
  max_scalar => "bench_lit_32",
  addr_len => "bench_lit_20",
  ten => "bench_lit_10",
  sixteen => "bench_lit_16",
  ascii_zero => "bench_lit_48",
  ascii_a_off => "bench_lit_87"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w2_rlp" run.
