From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W1 Require Import Apdu.

(** Named constants become VM integer literals (see Apdu.v). *)
Extract Constant tag_mask => "31".
Extract Constant constructed_bit => "32".
Extract Constant high_bit => "128".
Extract Constant len_one => "129".
Extract Constant len_two => "130".
Extract Constant byte_base => "256".

Extraction "w1_apdu.scm" run.
