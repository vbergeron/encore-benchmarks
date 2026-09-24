From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W3 Require Import Policy.

(** Named constants become VM integer literals (see Policy.v). *)
Extract Constant elem_len => "4".
Extract Constant range_len => "8".
Extract Constant amount_len => "8".
Extract Constant addr_len => "20".
Extract Constant hdr_len => "3".
Extract Constant byte_base => "256".
Extract Constant code_dest => "1".
Extract Constant code_amount => "2".
Extract Constant code_path => "3".

Extraction "w3_policy.scm" run.
