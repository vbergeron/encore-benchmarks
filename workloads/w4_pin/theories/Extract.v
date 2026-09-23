From EncoreBench.Common Require Import EncoreExtraction EncoreInput.
From EncoreBench.W4 Require Import Pin.

(** Named constants become VM integer literals (see Pin.v). *)
Extract Constant max_tries => "3".
Extract Constant max_puk_tries => "10".
Extract Constant puk_len => "8".
Extract Constant ins_verify => "32".
Extract Constant ins_change => "36".
Extract Constant ins_unblock => "44".
Extract Constant ins_select => "164".

Extraction "w4_pin.scm" run.
