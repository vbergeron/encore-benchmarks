# Boards

One TOML file per board. `xtask` and `crates/bench_build` both read
them: the build helper writes `memory.x` from the origins and the RAM/flash
**budget**, the runner picks the target and how to run the ELF.

| Board | Core | Runner | Cycles | Role |
|---|---|---|---|---|
| `qemu-lm3s6965` | Cortex-M3 | QEMU | no (instructions) | continuity with the paper, CI |
| `qemu-an505` | Cortex-M33 | QEMU | no (instructions) | ARMv8-M instruction counts, CI |
| `stm32u585` | Cortex-M33 | probe-rs | DWT | main measurement board |
| `nrf52840` | Cortex-M4 | probe-rs | DWT | core-sensitivity check |

`systick_ns_per_tick` (QEMU boards) is the period of SysTick on the core
clock as QEMU models it. The E firmware uses SysTick to time the Encore
GC in the memory profile when the board has no DWT.

The physical `ram_kb` / `flash_kb` are upper bounds. The linker only gets
the budget (`--ram-kb`, default 50 = ST33J2M0; use 64 for ST33K1M5;
`--flash-kb`, default 256), so a workload that does not fit fails at link
time, which answers Q1 directly.

The ST33 itself (Ledger Flex) is not listed: it is only reachable through the
Ledger SDK and will get its own runner if the hardware becomes available.
