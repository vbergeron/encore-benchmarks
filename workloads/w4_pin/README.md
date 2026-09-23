# W4 — PIN state machine

The ISO 7816-4 PIN logic of a secure element: VERIFY (0x20), CHANGE
REFERENCE DATA (0x24), RESET RETRY COUNTER with a PUK (0x2C) and SELECT
(0xA4, which drops the security status), driven by a stream of command
APDUs `INS Lc data(Lc)` (CLA, P1, P2 left out). Unknown INS gets "bad
instruction".

- **Program**: `run n` handles the first `n` APDUs of the input stream
  from a fresh card (PIN 1234, 3 tries; PUK 12345678, 10 tries) and returns
  one response code per APDU: 0 ok, 1 blocked, 2 denied, 3 bad INS, `4 + k`
  wrong secret with `k` tries left.
- **Proved** (`theories/Pin.v`, about `step`):
  - `tries_up_only_with_secret`: the PIN counter only goes up on a correct
    PIN while not blocked, or a correct PUK while the PUK is not blocked;
  - `puk_tries_up_only_with_puk`: the PUK counter only goes up on a
    correct PUK;
  - `auth_only_with_pin`: the security status is never gained without the
    PIN;
  - `counters_bounded`: both counters stay within their maximum;
  - `locked_forever`: with both counters at zero, no sequence of commands
    authenticates or brings a counter back.
- **N**: number of APDUs, 1, 10, 100, 1000. The stream repeats a 16-APDU
  cycle that goes through every transition (`vectors/vectors.rs`), about
  6.5 bytes per APDU.
- **Input**: the stream is in flash and read byte by byte through the
  `input_byte` extern (`theories/EncoreInput.v`); the E run includes that
  FFI cost, the R run reads the same bytes from a slice.
- **Trust**: `nat` as VM integers (`EncoreExtraction.v`); `input_byte`
  realised by the host (`EncoreInput.v`); the constants of `Pin.v` (INS
  bytes, counter maxima) extracted to literals in `Extract.v`.
- **Heap**: 32 KiB by default (E). C: 20 KiB arena, 2^10-word nursery.
- **C** (CertiRocq, `certirocq/`): the direct-style C recurses once per
  APDU (`process` is not tail-recursive), about 94 bytes of C stack each;
  1000 APDUs do not fit in the RAM budget (the runtime aborts with the
  20 KiB arena exhausted). C therefore runs only N = 1, 10 and 100
  (`CASES` in `certirocq/src/main.rs`), and has no row for N = 1000.

Not modelled: constant-time comparison (the Gallina and the Rust both stop
at the first differing digit), and anti-tearing (real cards decrement the
counter before comparing, so that a power cut cannot yield a free try).
