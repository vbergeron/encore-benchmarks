(** Variant C of W8: compile [run] (theories/Crc.v) to C with CertiRocq.
    Run by certirocq/generate.sh, which writes the C into gen/.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W8 Require Import Crc.

(** The bitwise operations of the CRC loop become C functions on the
    integers of BenchNat.v, as ExtrEncore maps them to the VM's int-xor,
    int-shr and int-and for E. Otherwise [Nat.lxor] would run as the
    Gallina recursion over the bits and [Nat.div2] and [Nat.odd] as unary
    recursions. They are registered here rather than in BenchNat.v, which
    would renumber the generated C of every other workload. *)
CertiRocq Register [
  Corelib.Init.Nat.lxor => "bench_nat_lxor",
  Corelib.Init.Nat.div2 => "bench_nat_div2",
  Corelib.Init.Nat.odd => "bench_nat_odd"
] Include [ "bench_rt.h" ].

(** Named constants become integer literals, as in Extract.v for E. *)
CertiRocq Register [
  poly16 => "bench_lit_40961",
  poly32_hi => "bench_lit_60856",
  poly32_lo => "bench_lit_33568",
  half_mask => "bench_lit_65535",
  top_bit => "bench_lit_32768"
] Include [ "bench_rt.h" ].

CertiRocq Compile -unsafe-erasure -file "w8_crc" run.
