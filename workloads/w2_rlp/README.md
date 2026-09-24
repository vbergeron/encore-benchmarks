# W2 — Transaction decoder (Ethereum RLP)

What a hardware wallet does before it signs: decode the payload the host
sent, and show the user what they are about to approve. The payload is
the EIP-155 signing payload of a legacy Ethereum transaction,
`rlp([nonce, gasPrice, gasLimit, to, value, data, chainId, 0, 0])`. The
screen shows the chain id, the recipient and the calldata in hexadecimal,
and the value, nonce, gas price and gas limit in decimal.

- **Program**: `run n` decodes the `n`-byte payload of the input with a
  strict RLP decoder (canonical encodings only: a byte below `0x80` is
  itself, lengths are minimal, integers have no leading zero and at most
  32 bytes, the recipient has 20 bytes, nothing follows the list) and
  returns the screen, one list of ASCII characters per field; an empty
  screen means the payload is rejected. Amounts are converted to decimal
  by repeated long division of the big-endian bytes by ten.
- **Proved** (`theories/Rlp.v`):
  - `decode_tx_enc`: an accepted payload is exactly the RLP encoding of
    the decoded transaction;
  - `show_dec_value`: the decimal digits shown for an amount denote the
    big-endian integer of the signed bytes;
  - `what_you_see_is_what_you_sign`: two payloads that are accepted and
    show the same screen are the same bytes. The host cannot have the user
    approve one transaction and sign another.
- **N**: calldata size, 0, 4, 68, 260 bytes (`vectors/vectors.rs`): an ETH
  transfer, a call without arguments, an ERC-20 `transfer`, and a contract
  call with eight arguments on Sepolia. The payloads are 45 to 317 bytes
  and use every RLP form (single bytes, short and long strings, short and
  long lists, empty strings for zero).
- **Input**: the payload is in flash and read byte by byte through the
  `input_byte` extern (`vendor/encore-extraction/ExtrEncoreInput.v`). The
  output is hashed field by field, each field's characters then `-1`, in
  every variant.
- **Trust**: `nat` as VM integers (`ExtrEncore.v`). No amount is ever a
  VM integer: they stay byte lists, and the decimal conversion only
  handles numbers below 2560, so 256-bit values fit the 24-bit VM. Also
  `input_byte` realised by the host and returning bytes (the proofs assume
  `bytes l`); the constants of `Rlp.v` extracted to literals in
  `Extract.v`.
- **Heap**: 32 KiB by default (E). `cargo xtask minheap` finds 16.75 KiB
  for the whole case list, so every N fits the ST33J2M0 budget.
- **C** (CertiRocq, `certirocq/`): 20 KiB arena, 2^10-word nursery. The
  direct-style C recurses once per byte in `read_bytes`, `split_n` and
  `hex`: the 317-byte payload of N = 260 exhausts the arena, and the C
  stack with a larger arena. C therefore runs only N = 0, 4 and 68
  (`CASES` in `certirocq/src/main.rs`).

Not modelled: the signature itself (Keccak and secp256k1 stay in the Rust
layer, which signs the bytes the Gallina accepted), typed transactions
(EIP-2718/1559) and unit formatting (the screen shows wei).

The R variant decodes over slices and renders the screen into a static
buffer, with its own long division on a 32-byte copy; it allocates
nothing.
