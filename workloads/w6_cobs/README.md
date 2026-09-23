# W6 — COBS stream framing

Consistent Overhead Byte Stuffing, which removes every zero from a frame so
that zero can delimit frames on a serial link. Each run of the benchmark
encodes a frame, then decodes the encoding.

- **Program**: `encode_input n` encodes the first `n` bytes of the input
  frame; `cobs_decode` is a streaming decoder that returns `None` on an
  invalid encoding (zero byte, truncated block, empty input).
- **Proved** (`theories/Cobs.v`):
  - `cobs_roundtrip : forall l, cobs_decode (cobs_encode l) = Some l`;
  - `cobs_encode_no_zero : forall l, Forall (fun x => x <> 0) (cobs_encode l)`.
- **N**: frame size, 16, 64, 256, 1024 bytes. The frame is pseudo-random
  with about one zero in 16, plus a 300-byte zero-free run at offset 600 so
  that the 1024-byte frame exercises the 254-byte block limit (code 0xFF).
- **Input**: the frame is in flash and read byte by byte through the
  `input_byte` extern (`theories/EncoreInput.v`). The E output is the
  encoded list and the decoded list, hashed in that order, as in R.
- **Trust**: `nat` as VM integers; `input_byte` returns bytes; the proof
  holds for any `nat` values, so it does not need the bytes to be < 256.
  `block_max = 254` is extracted to a literal in `Extract.v`.
- **Heap**: 40 KiB by default. At 1024 bytes the input list, the pieces,
  the encoding and the decoded frame are all cons lists (12 bytes per
  element), and the 32 KiB default of W0 overflows.

The R variant is the classic single-pass encoder and a bounds-checked
decoder into static buffers; it allocates nothing.
