# Partial conclusions

Status: **provisional**, written while waiting for the next `encore_vm` 0.1
release, which is expected to add GC instrumentation (pause length, number
of collections). Everything below comes from `benchmarks.jsonl` as of commit
`958feda`: encore_vm 0.1.4, rustc 1.88, two QEMU boards (lm3s6965 / Cortex-M3
and an505 / Cortex-M33), workloads W0, W4 and W6, variants E, C and R.

Every successful E and C row reproduces the R oracle's `out_hash`.

What this evidence can and cannot support:

- QEMU counts **instructions, not cycles**. Ratios below are ratios of
  instructions executed. A VM's dispatch loop (indirect branches, loads from
  flash) usually costs more per instruction on real hardware than straight-line
  native code does, so on a board the E/R and E/C gaps will probably be
  *larger* than the ratios below, not smaller. No hardware numbers yet.
- Two study workloads out of eight (W4, W6), both small. W1, the workload that
  best represents the target domain, is not written yet.
- Numbers are for the lm3s6965 unless stated otherwise. The M33 gives the same
  instruction counts to within 0.1%, so the QEMU boards do not tell the two
  cores apart (see §7).

## 1. Fitting in the budget (Q1)

With the default budget (50 KiB RAM, ST33J2M0):

| Workload, N | R | E | C |
|---|---|---|---|
| W4, 1–100 APDUs | ok | ok | ok |
| W4, 1000 APDUs | ok | ok | **fails** (arena exhausted) |
| W6, 16–64 B | ok | ok | ok |
| W6, 256 B | ok | ok | **fails** (arena exhausted) |
| W6, 1024 B | ok | **fails** (a timed run overflows the 40 KiB heap) | **fails** (C stack exhausted) |

With 64 KiB (ST33K1M5), E passes everything, including W6 at 1024 B
(54 KiB heap). C still fails W4 at 1000 and W6 at 256 and above, now on
**C stack**: CertiRocq's direct-style code recurses once per element (about
94 B of stack per APDU in W4, about 200 B per byte in W6), so more RAM does
not make it scale.

**Provisional conclusion:** at the input sizes of the study, E fits wherever C
fits, and in more cases. E's memory use grows with the heap, which the
integrator sizes; C's grows with the native stack, which depends on N. A
C variant built with `-cps` would lift that limit, but this CertiRocq release
cannot use the `nat` mapping in CPS mode (`certirocq/README.md`).

## 2. Execution cost (instructions)

Median instructions per run, lm3s6965, default budget:

| Workload | N | R | C | E | E / R | C / R | E / C |
|---|---:|---:|---:|---:|---:|---:|---:|
| W4 | 1 | 118 | 3 328 | 13 266 | 112× | 28× | 4.0× |
| W4 | 10 | 694 | 12 406 | 125 798 | 181× | 18× | 10.1× |
| W4 | 100 | 7 003 | 172 367 | 1 628 520 | 233× | 25× | 9.4× |
| W4 | 1000 | 69 692 | — | 18 877 391 | 271× | — | — |
| W6 | 16 | 453 | 14 066 | 72 428 | 160× | 31× | 5.1× |
| W6 | 64 | 1 490 | 57 661 | 276 914 | 186× | 39× | 4.8× |
| W6 | 256 | 6 152 | — | 1 339 096 | 218× | — | — |
| W6 | 1024¹ | 23 331 | — | 11 270 366 | 483× | — | — |

¹ 64 KiB budget, 54 KiB heap; W6 at 1024 B does not fit in 50 KiB.

Marginal cost per element, which removes the fixed setup (C's ~2.2k
instructions of heap setup per run, for instance):

| | R | C | E | E / R | E / C |
|---|---:|---:|---:|---:|---:|
| W4, per APDU (N 10 → 100) | 70 | 1 777 | 16 697 | ~240× | ~9.4× |
| W6, per byte (N 16 → 64) | 22 | 908 | 4 260 | ~200× | ~4.7× |

**Provisional conclusions:**

- E executes **two orders of magnitude** more instructions than idiomatic Rust
  (roughly 110× to 270× on these workloads before the heap fills up), and
  **5× to 10× more than CertiRocq's C**.
- The E/R ratio grows with N. Up to mid-size N this is the cost of
  interpretation plus allocation; past that point, it is the heap filling up
  (§3).
- In absolute terms: one W4 APDU costs about 17k instructions in E, so a
  VERIFY followed by a few commands stays below 100k instructions,
  a few milliseconds at tens of MHz. Whether that is acceptable is
  a judgement per use case; it has to be confirmed in cycles on the STM32U5.

## 3. The heap and the collector: the open question

Instructions per VM operation, from `insns` (timing profile) divided by
`vm_ops` (memory profile):

| Workload | N | heap peak / heap size | insns / VM op |
|---|---:|---|---:|
| W0 | 10 | 612 B / 32 KiB | 26 |
| W0 | 100 | 5.5 KiB / 32 KiB | 26 |
| W0 | 1000 | **full** | **77** |
| W4 | 1 – 10 | ≤ 8.4 KiB / 32 KiB | 27 |
| W4 | 100 | **full** | 30 |
| W4 | 1000 | **full** | 34 |
| W6 | 16 – 64 | ≤ 21 KiB / 40 KiB | 27 |
| W6 | 256 | **full** | 33 |
| W6 | 1024¹ | **full** | **68** |

As long as the heap never fills up, the VM costs a steady **~26–27 host
instructions per VM operation**, on every workload. Once the high-water mark
reaches the heap size, that rises, up to 2.5–3× on W0 at N = 1000 and W6 at
1024 B. The most likely cause is garbage collection, which then becomes
the largest part of the run time, but encore_vm 0.1.4 cannot confirm it: it
reports neither GC count nor GC time.

Other signs that point the same way, still to be explained:

- W6 at 256 B costs 1.9% *more* with a 54 KiB heap than with 40 KiB
  (1 364 135 vs 1 339 096 instructions), which suggests a collection cost
  that grows with the heap size, not only with the live data.
- W6 at 1024 B with a 40 KiB heap: the first, untimed run succeeds with the
  right output, then the timed run overflows. Something survives between runs
  (E keeps its heap across runs), or fragmentation builds up.
- `heap_peak_bytes` is a peak *allocation* figure until the first collection,
  not a live-data figure. W4 allocates about 850 B per APDU and W6 about
  380 B per byte (cons lists at 12 B per element), but how much of that is
  live, and therefore the true minimum heap, is unknown.

**What the next encore_vm 0.1 release should settle:** the number and length
of GC pauses per run (worst-case latency matters for a card that must answer
within the protocol's timeouts), the share of run time spent in the collector,
and whether the E/R ratio from §2 flattens once GC is taken out.

## 4. Code size (flash)

Total flash, lm3s6965, timing profile:

| Workload | R | C | E | E − R | C − R |
|---|---:|---:|---:|---:|---:|
| W0 | 8 044 | — | 22 812 | +14.4 KiB | — |
| W4 | 15 244 | 22 068 | 32 072 | +16.4 KiB | +6.7 KiB |
| W6 | 9 692 | 15 440 | 26 340 | +16.3 KiB | +5.6 KiB |

The Encore bytecode itself is small: 335 B (W0), 2 911 B (W4), 2 132 B (W6).
Most of E's overhead is fixed: `encore_vm` (4.6 KiB), about 5.4 KiB more of
`core` than R (mostly formatting, pulled in by the VM's error paths; not yet
investigated), and larger C/asm support.

**Provisional conclusion:** E pays a fixed ~14–15 KiB and then ~2–3 KiB of
bytecode per workload. For one workload it is the largest variant, about 10 KiB
more than C. The fixed cost is paid once per firmware, so E should overtake C
when several verified components ship in the same image, but that is an
extrapolation from two workloads, and C's per-workload code has not been
isolated from its runtime yet.

## 5. The CPS optimizer

Effect of `--cps-optimize off` on E, lm3s6965:

| Workload | bytecode (on / off) | instructions, off ÷ on | largest N with the optimizer off |
|---|---|---|---|
| W0 | 335 / 621 B | 3.2× – 4.0× | 100 (1000 overflows) |
| W4 | 2 911 / 5 509 B | 2.3× – 2.7× | 100 (1000 overflows) |
| W6 | 2 132 / 4 825 B | 3.2× – 4.1× | 64 (256 fails a timed run) |

**Conclusion (solid):** the optimizer is not optional. It halves the bytecode,
divides the instruction count by 2.3 to 4, and is what makes the larger N fit
in the heap at all. All the E figures above are measured with it on.

## 6. Stack and RAM besides the heap

- E needs ~4.5 KiB of native stack whatever N is (the Rust driver plus the
  VM's own frames; the VM has no call stack of its own). R needs 0.2–0.3 KiB.
  C's stack grows with N (0.7 KiB at 1 APDU, 9.4 KiB at 100 APDUs).
- E's static RAM is its heap: the whole budget question is heap sizing.
  R uses 1 KiB (W4) or 2 KiB (W6) of static buffers.

## 7. Cortex-M3 vs Cortex-M33

Instruction counts are identical, or within 0.1%, between the two QEMU
boards for every variant. Flash is ~960 B larger on the M33, all of it in
startup/vector code, the same for every variant. The QEMU boards are
therefore interchangeable for instruction counts; core sensitivity needs the
cycle counts of the real boards (STM32U5 and nRF52840).

## Summary

| Question | Answer so far | Confidence |
|---|---|---|
| Does E fit a 50 KiB secure element? | Yes for W4 and W6 up to mid-size inputs; W6 at 1 KiB needs 64 KiB. Fits more cases than C. | medium |
| Cost vs native Rust | ~110–270× instructions before the heap fills up, more once it does | medium (instructions only) |
| Cost vs CertiRocq C | ~5–10× instructions | medium |
| Flash overhead | ~15 KiB fixed + ~2–3 KiB bytecode per workload | medium |
| GC impact | probably dominant once the heap fills up | **low: waiting for encore_vm instrumentation** |
| CPS optimizer | essential: 2–4× speed, 2× smaller bytecode | high |

## Next, once the new encore_vm is released

1. Bump `encore_vm`, re-run W0, W4 and W6 on both QEMU boards, and record
   the GC counts and pauses.
2. Split the E cost into interpretation vs collection, and redo §2 and §3.
3. Explain W6 at 1024 B failing on its second run, and the higher cost with
   the larger heap.
4. Then W1 (APDU + BER-TLV), in all three variants, and the first cycle
   counts on the STM32U5.
