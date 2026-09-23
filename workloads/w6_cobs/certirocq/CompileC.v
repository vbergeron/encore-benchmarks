(** Variant C of W6: compile the COBS encoder and decoder (theories/Cobs.v)
    to C with CertiRocq. Run by certirocq/generate.sh, which writes the C
    into gen/.

    E calls [encode_input] and [cobs_decode] one after the other; here the
    heap is reset before each call to the program, so one entry point does
    both and returns the pair.

    [-unsafe-erasure] enables MetaRocq's unverified erasure passes, among
    which the one that applies the nat mapping of BenchNat.v. *)

From EncoreBench.CertiRocq Require Import BenchNat.
From EncoreBench.W6 Require Import Cobs.

(** Named constant becomes an integer literal, as in Extract.v for E. *)
CertiRocq Register [ block_max => "bench_lit_254" ] Include [ "bench_rt.h" ].

Definition c_roundtrip (n : nat) : list nat * option (list nat) :=
  let e := encode_input n in (e, cobs_decode e).

CertiRocq Compile -unsafe-erasure -file "w6_cobs" c_roundtrip.
