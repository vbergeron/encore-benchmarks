(** Variant C of W7: compile [run] (theories/Store.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W7 Require Import Store.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  byte_base => "bench_lit_256",
  key_len => "bench_lit_2",
  reg_len => "bench_lit_4"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w7_store" run.
