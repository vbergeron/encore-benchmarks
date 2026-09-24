From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W2 Require Import Rlp.

(** Named constants become VM integer literals (see Rlp.v). *)
Extract Constant str_off => "128".
Extract Constant str_long => "184".
Extract Constant str_long_base => "183".
Extract Constant list_off => "192".
Extract Constant list_long => "248".
Extract Constant list_long_base => "247".
Extract Constant short_max => "56".
Extract Constant long_one => "56".
Extract Constant long_two => "57".
Extract Constant byte_base => "256".
Extract Constant max_scalar => "32".
Extract Constant addr_len => "20".
Extract Constant ten => "10".
Extract Constant sixteen => "16".
Extract Constant ascii_zero => "48".
Extract Constant ascii_a_off => "87".

Extraction "w2_rlp.scm" run.
