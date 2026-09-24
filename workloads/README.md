# Workloads

Each workload is a `step`-style function whose bugs would be security
holes or field failures, with one precise property proved in Rocq. W0 is a
smoke test for the pipeline; W1–W8 are the study, as chosen in
[PLAN.md](../PLAN.md#workloads).

| # | Workload | Property proved | N | Status |
|---|---|---|---|---|
| W0 | Smoke: sum of `[1..N]` | closed form `2·run n = n(n+1)` | list length | E, R, C |
| W1 | APDU + BER-TLV parser (ISO 7816) | totality, no out-of-bounds, `encode (decode x) = x` | APDU 5 → 261 B, TLV depth | E, R, C |
| W2 | Transaction decoder (Ethereum RLP) | what is displayed is what is signed | calldata 0 → 260 B | E, R, C |
| W3 | BIP32 path policy and allow-list | signed iff a rule allows path, amount and destination | 1 → 64 rules | E, R, C |
| W4 | PIN state machine (ISO 7816 VERIFY) | counter never goes up without a successful verify | trace length | E, R, C |
| W5 | A/B firmware update, anti-rollback | version never decreases; a valid slot always exists | 10 → 1000 events, 4–5 power cuts per 40 | E, R, C |
| W6 | COBS stream framing | round trip; no zero in the output | frame 16 → 1024 B | E, R, C |
| W7 | FIDO credential store (persistent RB tree) | balance invariants; `lookup` after `insert` | 10 → 500 entries | E, R, C |
| W8 | CRC-16 / CRC-32 in Gallina | equals the polynomial definition | block 16 → 1024 B | E, R |

Order, per [the plan](../PLAN.md#priorities-and-steps): W4 then W1 (in all three variants), then W2 and W7,
then W3, W5, W6, W8.

## Layout of a workload

Copy `w0_smoke/` and rename. Everything below `<w>/` is optional except
`vectors/` and `rust/`, since R is the oracle.

```
workloads/<w>/
  README.md             property, N range, trust assumptions (e.g. values < 2^23)
  theories/
    dune                rocq.theory EncoreBench.<W> + extraction rule (promote)
    <Spec>.v            program, specification, proofs
    Extract.v           imports Encore.Extraction.ExtrEncore, extracts the entry points
    <w>.scm             promoted by `dune build`, committed
  vectors/vectors.rs    frozen inputs, `include!`d by every variant
  rust/                 R   — package `<w>-r`  (oracle)
  encore/               E   — package `<w>-e`, feature `stats`
  certirocq/            C   — package `<w>-c`: CompileC.v, gen/ (see certirocq/README.md)
```

Rules that keep the variants comparable:

- Same inputs: every variant includes the same `vectors/vectors.rs` and
  loops over it in the same order.
- Same outputs: every variant hashes its output with `Fnv1a` in the same
  way (for example `.int(v)` for each integer, in order), so the hashes can
  be compared with the oracle's.
- Same driver: use `bench_harness::Session`. Only the body of `run` differs.
- Same build: packages take their dependency versions from the workspace
  and share the release profile (`opt-level = "s"`, LTO, one codegen unit).
- R is written without looking at the Gallina, so that it is not a copy of
  the functional structure.
- The package name must be `<w>-<variant>`: that is how `cargo xtask`
  finds it.
