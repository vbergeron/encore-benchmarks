# Experiment plan

This is the plan this repository implements, translated from the original
French document *Encore — plan d'expérience comparatif*. The plan states
what the study commits to. What has been built so far is in the
[README's status table](README.md#status).

**Where the repository departs from the plan**

- **R+V is not measured.** The plan's fourth variant, Rust checked with Kani
  or Verus, proves properties of hand-written Rust, not of the Gallina that
  E and C compile. It answers a different question, and its runtime cost is
  R's, since the checks run at build time. See the [README](README.md).
  The plan's text below still mentions R+V; it is kept as written.
- **W6 uses COBS**, one of the two codecs the plan allowed (COBS or HDLC).
- **W8 uses the VM's bitwise instructions.** Encore gained them after the
  plan was written, so W8 no longer tests their absence; see
  [its README](workloads/w8_crc/README.md).
- **The runner is `cargo xtask`** (`xtask/`). It takes over what the plan
  describes with `scripts/benchmark.sh`, the QEMU instruction-count script
  of the [Encore repository](https://github.com/vbergeron/encore).
- **C's GC runs over a static arena**, as the plan asks. How it is set up is
  described in [`certirocq/README.md`](certirocq/README.md).

---

## Goal and research questions

Show, on realistic firmware workloads, what logic proved in Rocq costs when
Encore executes it, compared with CertiRocq and with hand-written Rust
`no_std`. The paper
[From Rocq to Metal](https://arxiv.org/html/2606.02651) already covers flash
size, heap and build time against CertiRocq, on 7 micro-benchmarks. This
plan fills four gaps:

- no measurement of execution speed;
- no Rust baseline;
- no realistic workload (the paper calls its Ledger app a "toy");
- a handicapped CertiRocq (GC disabled, Peano integers).

The five research questions:

- **Q1 — Feasibility.** Which workloads fit in 50 KB of RAM and 256 KB of
  flash, for each toolchain?
- **Q2 — Cost.** What is the overhead in flash, RAM, cycles and worst-case
  latency compared with Rust `no_std`? Where is the crossover point between
  VM + bytecode flash and native code?
- **Q3 — Predictability.** Do the GC and the CPS style give a bounded,
  measurable latency, compatible with soft real time (APDU, USB)?
- **Q4 — Value of the proof.** For each workload: which property is proved,
  how many lines of specification and proof, and how much of the code
  remains in the trusted computing base (TCB)?
- **Q5 — Integration effort.** Size of the unverified Rust layer, number of
  externs, how easy it is to evolve the logic.

## Systems compared

Four main variants, all linked against the same Rust I/O layer (USB/APDU,
display, crypto), so that only the logic changes.

| Variant | Toolchain | Role in the study | Watch out for |
|---|---|---|---|
| **E — Encore** | Gallina → Scheme → bytecode → `no_std` VM | System under study | Measure with and without the CPS optimizer (`--cps-optimize=off`) to isolate its contribution |
| **C — CertiRocq** | Gallina → Clight → gcc -Os (and CompCert if possible) | Closest verified competitor | Enable a real GC on a static buffer, not the paper's "abort" mode; same heap budget as Encore |
| **R — idiomatic Rust `no_std`** | Rust, `heapless`, no allocator | Performance ceiling, no proof | Written by someone who does not know the Gallina version, so that it does not copy the functional structure |
| **R+V — verified Rust** | Rust + Kani (bounded model checking) or Verus | The "prove the Rust directly" alternative | Mostly for comparing effort and strength of guarantee, not performance |

Secondary variants, to add if time allows:

- **E-AOT**: the Thumb-2 backend described in `AOT.md` (Encore repository),
  once it exists. It will tell whether the cycle gap comes from
  interpretation or from the CPS/GC model.
- **R-alloc**: Rust with `alloc` and a fixed-heap allocator
  (`embedded-alloc`), reproducing the functional style (`Box`, linked
  lists). It separates the cost of dynamic allocation from the cost of the
  VM.
- **Crane** ([Rocq → C++, Bloomberg](https://bloomberg.github.io/crane/papers/crane-rocqpl26.pdf)):
  to cite as related work. It targets C++ with the standard library and
  smart pointers, which is a priori over budget on Cortex-M.

## Metrics and measurement protocol

Every metric is measured on a real board. QEMU is used only for
reproducible instruction counts.

| Metric | Unit | How | Detail to isolate |
|---|---|---|---|
| Flash | bytes | `arm-none-eabi-size`, `cargo bloat` | Runtime (VM or CertiRocq runtime) separate from the program (bytecode or generated code) |
| Static RAM | bytes | `.data` + `.bss` | Encore registers (256 × 4 B = 1 KB) and globals (64 × 4 B) included |
| Peak heap | bytes | Max of the `hp` counter (`stats` feature); CertiRocq equivalent | Also: the smallest heap at which the program still passes (binary search) |
| Peak stack | bytes | Stack painting (pattern `0xDEADBEEF`) | Mostly for R and C; Encore has no call stack |
| Cycles | CPU cycles | DWT `CYCCNT` around each call | Median and p99 over 1,000 runs, caches disabled or fixed |
| Worst-case latency | µs | Max GC pause + max duration of one `step` | Critical for APDU/USB deadlines |
| GC count | counter | GC instrumentation | Relate to pauses and heap size |
| Energy | µJ per operation | Otii Arc or PPK2 (optional) | Derived from cycles if no instrument |
| Build time | s | Wall clock, 5 runs | Already in the paper; redo on the new workloads |
| Proof effort | lines | `coqwc`: spec, proof, program | Also for R+V (Kani/Verus annotations) |
| TCB | lines | Unverified Rust + VM + compiler + externs | Show what remains to be trusted for each variant |

Common protocol:

1. Same Gallina source for E and C. Same calling interface and same input
   vectors for all four variants.
2. Input vectors frozen in the repository, with an oracle: R's output is the
   reference, and any divergence is a bug to fix before measuring.
3. Each workload is parameterised by a size N (input bytes, number of
   elements, trace length), to plot curves, not just points.
4. RAM budgets imposed at link time: 50 KB (ST33J2M0), then 64 KB
   (ST33K1M5), which answers Q1 directly.
5. Results appended to `benchmarks.jsonl` with the commit, the variant, the
   board and N.

## Workloads

Eight workloads, chosen because an error in them is a security hole or a
field failure, and because a precise property can be proved about them. All
follow the paper's `step : State × Event → State × list Effect` model, which
keeps the Rust layer identical from one workload to the next.

| # | Workload | Property proved | Parameter N | What it exercises |
|---|---|---|---|---|
| W1 | APDU + BER-TLV parser (ISO 7816) | Totality (never stuck), no out-of-bounds access, round trip `encode (decode x) = x` | APDU size 5 → 261 B, TLV depth | Byte operations, recursion |
| W2 | Transaction decoder (Ethereum RLP or Bitcoin transaction) | "What is displayed is what is signed": the displayed fields are exactly those of the signed hash | Number of fields, calldata size | List allocation, strings |
| W3 | BIP32 derivation-path policy and address allow-list | Only paths and amounts that comply with the policy are signed | Number of rules, path depth | Filters, comparisons |
| W4 | PIN state machine (ISO 7816 VERIFY, retry counter) | The counter never goes back up without a successful verification; no sensitive operation outside the authenticated state | Event trace length | Per-event latency, little allocation |
| W5 | A/B firmware update with anti-rollback | The installed version never decreases; a valid slot always exists after a power cut at any step | Number of steps, of injected power cuts | Trace invariants, flash effects |
| W6 | Streaming COBS or HDLC frame codec | Round trip; bounded expansion (COBS: at most 1 byte per 254) | Frame size 16 → 1,024 B | Throughput, tight byte loops |
| W7 | Credential key-value store (FIDO, persistent red-black tree) | Balanced-tree invariants; `lookup` after `insert` is correct | Number of entries 10 → 500 | GC pressure, peak heap |
| W8 | CRC-16 / CRC-32 written in Gallina | Equivalence with the polynomial definition | Block size | Heavy arithmetic; tests the "no bitwise operations in the VM" limit |

Why these choices:

- **W1, W2, W6** parse untrusted input, the first source of vulnerabilities
  in secure elements. Rust brings memory safety, but not the round trip or
  the display/signature correspondence.
- **W3, W4, W5** are security policies. There, a proof is worth more than a
  test: the bugs live in rare event sequences, which fuzzing reaches poorly.
- **W7** takes the paper's red-black tree, but with a real use and a scale-up
  to 500 entries.
- **W8** is deliberately unfavourable to Encore. It measures the cost of a
  pure computation without bitwise operations, and justifies (or not) adding
  them to the VM rather than going through an extern.

The existing micro-benchmarks (sum, fibonacci, gcd, ackermann, fsm, rbtree)
are kept for continuity with the paper. They move to an appendix.

## Hardware platforms

The real target is a Cortex-M35P (ST33, ARMv8-M Mainline); an off-the-shelf
Cortex-M33 board is the closest approximation. The ST33 memory budgets are
imposed at link time.

| Platform | Core | Role | Possible measurements |
|---|---|---|---|
| QEMU `lm3s6965evb` (current) | Cortex-M3 (ARMv7-M) | Continuous integration, instruction counts | Instructions, flash, heap; no reliable cycles |
| Cortex-M33 board (e.g. STM32U5 or nRF5340) | Cortex-M33 (ARMv8-M) | Main measurement platform | DWT cycles, GC pauses, energy |
| Cortex-M4 board (e.g. STM32F4 or nRF52840) | Cortex-M4 (ARMv7E-M) | Sensitivity check across cores | DWT cycles |
| ST33 (Ledger Flex, if accessible) | Cortex-M35P | Final validation on W2 and W4 | End-to-end APDU response time |

Points of rigour:

- Fix the clock frequency, and disable or freeze the caches and flash
  prefetch; otherwise flash wait states skew the interpreter-versus-native
  comparison.
- Move the compilation target from `thumbv7m-none-eabi` to
  `thumbv8m.main-none-eabi` for the M33 boards, and check that the QEMU
  figures stay comparable.
- Use the same gcc version for the C part of CertiRocq, and the same Rust
  version (1.88, as in the paper) everywhere.

## Known limits and threats to validity

The limits below, found in the code of Encore 0.1.3, determine which
workloads can run, and must be stated in the paper.

| Encore limit | Value | Workloads affected | Proposed handling |
|---|---|---|---|
| Integers | 24-bit signed (±8 M), modular arithmetic | W2 (amounts), W8 | Amounts as bytes or through an extern; report it as a trust assumption |
| Integer operations | add, sub, mul, eq, lt: no division, no bitwise operations | W6, W8 | Measure as is, then with added opcodes |
| Heap address | 16 bits, so at most 256 KB of heap | None under 50 KB | Mention only |
| Bytecode size | 64 KB (`code_len` on 16 bits) | W2 if many formats | Check W2's size early |
| Globals, externs, arguments | 64 globals, 32 externs, 8 arguments | W2, W3 | Count per workload |

Threats to validity to address explicitly:

- **Extraction of `nat` to machine integers.** It is faster, but unproven,
  and wrong beyond 2^23. To be fair, measure E and C with the same
  representation, and add a variant on bounded integers defined in Gallina
  (for example `Z` with a bound proof), which makes the assumption explicit.
- **CertiRocq's handicap.** In the paper its GC is disabled and it uses
  Peano integers. The new figures must use its real GC on a static buffer,
  and its primitive integers if version 0.9.1 supports them (to check).
  Otherwise, say so clearly.
- **Quality of the Rust baseline.** A poorly optimised baseline flatters
  Encore. Have it reviewed by a firmware developer, and publish its code.
- **Workload selection bias.** Keep W8 (unfavourable) in the main results,
  not in the appendix.
- **Trusted base.** Encore's compiler and VM are not verified, unlike a large
  part of CertiRocq. The TCB comparison must show this, not only the
  performance.
- **Measurements on QEMU.** They count instructions, not cycles: conclusions
  about speed come from the boards only.

## Priorities and steps

Start with the two workloads that answer Q1–Q4 fastest: W4 (PIN state
machine, small and very telling) and W1 (APDU/TLV parser, representative of
untrusted input).

1. **Measurement bench.** Cortex-M33 board, DWT instrumentation and GC pauses
   in `encore_vm` (`stats` feature), stack painting, JSONL output.
2. **Bring CertiRocq up to level.** Real GC on a static buffer; check support
   for primitive integers in version 0.9.1.
3. **W4, then W1**, in the four variants E, C, R, R+V, with Rocq proofs and
   frozen input vectors.
4. **W2 and W7**, for heap scale-up and the real Ledger case.
5. **W3, W5, W6, W8**, then the secondary variants (R-alloc, E-AOT if the
   backend exists).
6. **Validation on ST33** of W2 and W4, if the hardware is accessible.

Open questions:

- [ ] Does CertiRocq 0.9.1 accept primitive integers (`PrimInt63`) on a
      32-bit target?
- [ ] Should bitwise operations and division be added to the VM before
      measuring W6 and W8, or measure without them first?
- [ ] Kani or Verus for the R+V variant?
- [ ] Access to an ST33 development device?

## Sources

- [From Rocq to Metal: A Pipeline for Formally Verified Microcontroller Firmware (arXiv 2606.02651)](https://arxiv.org/html/2606.02651)
- [Encore repository (vbergeron/encore)](https://github.com/vbergeron/encore)
- [CertiRocq repository](https://github.com/CertiRocq/certirocq)
- [Crane Lowers Rocq Safely into C++](https://bloomberg.github.io/crane/papers/crane-rocqpl26.pdf)
