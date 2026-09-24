(** Variant C of W0: compile [run] (theories/Smoke.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W0 Require Import Smoke.

CertiRocq Compile -unsafe-erasure -file "w0_smoke" run.
