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
  `input_byte` extern (`vendor/encore-extraction/ExtrEncoreInput.v`). The E output is the
  encoded list and the decoded list, hashed in that order, as in R.
- **Trust**: `nat` as VM integers; `input_byte` returns bytes; the proof
  holds for any `nat` values, so it does not need the bytes to be < 256.
  `block_max = 254` is extracted to a literal in `Extract.v`.
- **Heap**: 40 KiB by default, the most that fits the 50 KiB RAM budget
  next to the driver. `cargo xtask minheap` finds 32.25 KiB for the whole
  case list, so every N fits the ST33J2M0 budget. Before encore 0.1.6 it
  found 53.5 KiB and N = 1024 did not fit: the VM kept the previous call's
  lists reachable from its registers, and the timed run overflowed. The
  input list, the pieces, the encoding and the decoded frame are all cons
  lists at 12 bytes per element, where R uses two static buffers (2 KiB).

- **C** (CertiRocq, `certirocq/`): the arena gets the same 40 KiB as the E
  heap, 2^10-word nursery, and C runs every N. The entry point
  `c_roundtrip` returns the encoding and the decoding (the heap is reset
  between calls). The direct-style C recurses once per byte in
  `read_bytes`, `split_zero` and `dec`, about 200 bytes of C stack per
  byte. Smallest arena per case (`cargo xtask minheap -v c`,
  results/minheap.jsonl, lm3s6965), and RAM in all (statics + peak stack):
  N = 16: 16.5 KiB, 19.71 KiB in all; N = 64: 16.5 KiB, 27.54 KiB in all.
  N = 256, 1024 fail at every arena size: the C stack runs out, and a
  larger arena only leaves it less of the RAM budget. With the aligned
  arena, N = 64 (C stack exhausted) fails; the rows labelled `c-arena-36k`
  (36 KiB arena) pass every N that fits at some size. E for comparison: N
  = 16: 1 KiB, 5.91 KiB in all; N = 64: 2.75 KiB, 7.66 KiB in all; N =
  256: 8.25 KiB, 13.16 KiB in all; N = 1024: 32.25 KiB, 37.16 KiB in all.

The R variant is the classic single-pass encoder and a bounds-checked
decoder into static buffers; it allocates nothing.
