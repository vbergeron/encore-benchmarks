From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W7 Require Import Store.

(** Named constants become VM integer literals (see Store.v). *)
Extract Constant byte_base => "256".
Extract Constant key_len => "2".
Extract Constant reg_len => "4".

Extraction "w7_store.scm" run.
