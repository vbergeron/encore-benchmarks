From EncoreBench.Common Require Import EncoreExtraction EncoreInput.
From EncoreBench.W6 Require Import Cobs.

(** Named constant becomes a VM integer literal (see Cobs.v). *)
Extract Constant block_max => "254".

Extraction "w6_cobs.scm" encode_input cobs_decode.
