# W3 — BIP32 path policy and destination allow-list

What a hardware wallet checks before it signs: a signing request names a
BIP32 derivation path, an amount and a destination, and the device's
policy decides whether to sign it. The policy is a list of rules; a rule
gives one range of child indices per level of the path (a hardened index
has its top bit set, so "accounts 0' to 3'" is `[0x80000000, 0x80000003]`),
the largest amount it allows and the destinations it allows. A request is
signed when one rule allows all three. Otherwise the device reports the
reason from the rule that came closest.

- **Program**: `run n` checks every request of the input against the
  first `n` rules of its policy and returns one verdict per request: 0 sign,
  1 destination not allowed, 2 amount over the limit, 3 path not allowed.
  It reads the requests and the rules in place in the input, byte by byte,
  stops at the first rule that allows a request, and allocates nothing but
  its result.
- **Proved** (`theories/Policy.v`):
  - `lex_leb_spec`: comparing two big-endian byte strings byte by byte is
    comparing the numbers they denote;
  - `sign_iff_complies`: `decide` signs a request if and only if some rule
    of the policy allows its path (every index in its level's range, same
    depth), its amount and its destination;
  - `path_reject`, `amount_reject`, `dest_reject`: the reason given for a
    refusal is true (for instance "amount over the limit" means that some
    rule allows the path and every rule that allows it has a lower limit);
  - `run_spec`: the in-place driver computes `decide` over the policy and
    the requests that the decoders of `Policy.v` read from the input;
  - `run_signs_only_compliant`: the two together. If the input is bytes,
    the `i`-th verdict of `run n` is "sign" exactly when one of the first
    `n` rules allows the `i`-th request, and "path not allowed" exactly
    when none of them allows its path.
- **N**: number of rules, 1, 4, 16, 64 (`vectors/vectors.rs`). The 16
  requests are the same for every N; each targets a rule (between the 1st
  and the 64th) and is either compliant, at the edge of every range and
  at the limit, or off by one: one over the limit, index one past its
  range, one level deeper, a non-hardened account, an unknown destination.
  Paths have 3 to 5 levels. Two consecutive rules share a coin type, so a
  request can match the path of several rules. The more rules, the more
  requests reach the rule that signs them: the verdicts, hence the hashes,
  differ for each N.
- **Input**: the header, the requests and the policy (5.8 KiB, of which
  5.1 KiB for the 64 rules) are in flash and read byte by byte through
  the `input_byte` extern (`vendor/encore-extraction/ExtrEncoreInput.v`).
  R reads the same bytes from a slice, and compares indices as `u32` and
  amounts as `u64`.
- **Trust**: `nat` as VM integers (`ExtrEncore.v`), used only for bytes,
  counts and positions in the input: no index or amount is ever a VM
  integer (they reach 2^32 and 2^64), they stay byte strings. `input_byte`
  realised by the host and returning bytes (`run_signs_only_compliant`
  takes it as its hypothesis `input_bytes`); the constants of `Policy.v`
  extracted to literals in `Extract.v`. One extern, no argument beyond N.
- **Heap**: 32 KiB by default (E), as the other workloads. The heap peak
  reaches the whole heap only because the collector runs when it is full:
  `cargo xtask minheap` finds 1 KiB for the whole case list.
- **C** (CertiRocq, `certirocq/`): 20 KiB arena, 2^10-word nursery. The
  in-place driver allocates little, but the direct-style C makes a C call
  per rule tried (the tail call of `eval_rules` is not a C tail call, about
  100 bytes of C stack per rule), and the live values of those frames push
  the 64 rules of N = 64 past the arena (it passes with a 40 KiB arena and
  `--ram-kb 64`). C therefore runs only N = 1, 4 and 16 (`CASES` in
  `certirocq/src/main.rs`).

Not modelled: the key derivation itself and the signature (they stay in
the Rust layer, which derives the key of the path the Gallina accepted),
address encoding (destinations are 20 raw bytes), and cumulative limits
(each request is checked on its own; a per-period spending cap would need
state, as W4 has).
