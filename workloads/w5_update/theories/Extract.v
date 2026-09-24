From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W5 Require Import Update.

(** Named constants become VM integer literals (see Update.v). *)
Extract Constant byte_base => "256".
Extract Constant modulus => "65521".
Extract Constant radix => "31".
Extract Constant factory_version => "1".
Extract Constant ev_begin => "1".
Extract Constant ev_chunk => "2".
Extract Constant ev_finish => "3".
Extract Constant ev_confirm => "4".
Extract Constant ev_reboot => "5".
Extract Constant ev_cut => "6".
Extract Constant code_busy => "1".
Extract Constant code_rollback => "2".
Extract Constant code_unexpected => "3".
Extract Constant code_bad_image => "4".
Extract Constant code_bad_event => "5".
Extract Constant code_booted => "8".

Extraction "w5_update.scm" run.
