From Encore.Extraction Require Import ExtrEncore ExtrEncoreInput.
From EncoreBench.W8 Require Import Crc.

(** Named constants become VM integer literals (see Crc.v). *)
Extract Constant poly16 => "40961".
Extract Constant poly32_hi => "60856".
Extract Constant poly32_lo => "33568".
Extract Constant half_mask => "65535".
Extract Constant top_bit => "32768".

Extraction "w8_crc.scm" run.
