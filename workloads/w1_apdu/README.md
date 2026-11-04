# W1 — APDU and BER-TLV parser

The first thing a secure element does with a command from the reader:
split the ISO 7816-4 command APDU (`CLA INS P1 P2 [Lc data] [Le]`, short
form, cases 1 to 4), then parse the BER-TLV structure (X.690) of its data
field: tags of one or two bytes, definite lengths in their shortest form
(`0..127`, `0x81 n`, `0x82 hi lo`), constructed values parsed recursively.

- **Program**: `run n` parses the `n`-byte command APDU of the input and
  returns `[0; INS]` followed by a pre-order summary of the TLV tree, three
  numbers per node (tag, depth, and value length for a primitive or
  number of children for a constructed node); `[1]` for a malformed APDU
  (Lc of 0, data shorter than Lc, bytes after Le), `[2]` for a malformed
  TLV (truncated value, indefinite or non-minimal length, tag of three
  bytes or more).
- **Proved** (`theories/Apdu.v`):
  - `run_roundtrip`: an accepted APDU is exactly `enc_apdu` of the parsed
    command, and its data field exactly the encoding of the parsed trees
    (`encode (decode x) = x`); hence `parse_apdu_injective`: no two byte
    strings are accepted as the same command;
  - `dec_seq_enc`: `decode (encode t) = t` for every well-formed tree;
  - `dec_seq_fuel`: the decoder's fuel (`length + 1`) never runs out, so an
    input is rejected only because it is malformed (totality);
  - no out-of-bounds access by construction: the parsers work on the list
    of the `n` bytes read, and a length that runs past its parent is
    rejected by `split_n` rather than read.
- **N**: APDU size, 5, 32, 128, 261 bytes (`vectors/vectors.rs`): a bare
  case-2 GET DATA, then case-4 commands carrying an EMV record, an FCI
  template and a card-verifiable certificate with the maximal 255-byte data
  field. TLV depth goes up to 3; the 261-byte case uses `0x81` lengths.
- **Input**: each case's APDU is in flash and read byte by byte through the
  `input_byte` extern (`vendor/encore-extraction/ExtrEncoreInput.v`); the E
  and C runs include that FFI cost, the R run reads the same bytes from a
  slice.
- **Trust**: `nat` as VM integers (`ExtrEncore.v`; tag numbers stay below
  2^16); `input_byte` realised by the host and returning bytes (the proofs
  assume `bytes l`, every element below 256); the constants of `Apdu.v`
  extracted to literals in `Extract.v`.
- **Heap**: 32 KiB by default (E). `cargo xtask minheap` finds 10.5 KiB
  for the whole case list, so every N fits the ST33J2M0 budget.
- **C** (CertiRocq, `certirocq/`): the arena gets the same 32 KiB as the E
  heap, 2^10-word nursery by default, and C runs every N. The direct-style
  C recurses on the C stack through `read_bytes`, `split_n` and the
  decoder, and its GC needs room for a next generation of twice the
  previous size. RAM in all (statics + peak stack) at the smallest arena
  that passes, with the best nursery of 2^6 to 2^10 words (`cargo xtask
  minheap -v c --c-log-nursery k`, results/minheap.jsonl, lm3s6965): N =
  5: 5.8 KiB (2^7, 9.2 with the default 2^10; E 5.6); N = 32: 10.2 KiB
  (2^8, 19.1 with the default 2^10; E 6.6); N = 128: 27.9 KiB (2^9, 41.9
  with the default 2^10; E 10.4). N = 261 fails at every arena and nursery
  size: the C stack runs out, and a larger arena only leaves it less of
  the RAM budget. With the aligned arena, N = 128 (arena exhausted) fails;
  the rows labelled `c-arena-36k` (36 KiB arena) pass every N that fits at
  some size.

The R variant is a recursive-descent parser over slices that writes the
summary into a static buffer; it allocates nothing.
