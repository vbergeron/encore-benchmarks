(** Input of a workload, shared by every workload that reads a buffer.

    A workload's input (a frame, a stream of APDUs) lives in a byte buffer
    on the device. The E variant does not copy it into the VM heap from
    Rust: a list built by the host is not a GC root while it is being built,
    and a 1 KiB frame as a cons list would not fit the heap budget anyway.
    Instead the Gallina reads it one byte at a time through an Encore
    extern, the way firmware reads a receive buffer.

    Trust assumption: [input_byte] is an axiom, realised by the host's
    extern in slot 0. The host must return a value in [0, 255] for every
    index the workload reads, and the same value every time. Proofs never
    rely on its behaviour: they are stated over the lists it produces. *)

From Stdlib Require Extraction.
From Stdlib Require Import List.
Import ListNotations.

Parameter input_byte : nat -> nat.

Extract Constant input_byte => "(extern (slot 0) i)".

(** [read_bytes pos n] is the list of the [n] input bytes from [pos]. *)
Fixpoint read_bytes (pos n : nat) : list nat :=
  match n with
  | O => []
  | S n' => input_byte pos :: read_bytes (S pos) n'
  end.
