(** Variant C of W4: compile [run] (theories/Pin.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W4 Require Import Pin.

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  max_tries => "bench_lit_3",
  max_puk_tries => "bench_lit_10",
  puk_len => "bench_lit_8",
  ins_verify => "bench_lit_32",
  ins_change => "bench_lit_36",
  ins_unblock => "bench_lit_44",
  ins_select => "bench_lit_164"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w4_pin" run.
