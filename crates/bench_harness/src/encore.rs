//! `encore_vm` statistics for the E variants' memory profile: what one run
//! cost in VM instructions, heap and garbage collection, and the clock that
//! times the collector.
//!
//! ```ignore
//! let before = Snapshot::of(&vm);
//! let out = run(&mut vm, n)?;
//! let st = RunStats::between(&before, &Snapshot::of(&vm));
//! // ... in the `case` record:
//! st.record(r, config::VM_CLOCK_UNIT)
//! ```
//!
//! `VmStats` accumulate from boot and cannot be reset, so counts and times
//! are differences between two snapshots, while the heap peak and the
//! longest GC pause are running maxima since boot.

use crate::Record;
use core::fmt::Write;
use encore_vm::stats::{GcStats, VmStats};
use encore_vm::vm::Vm;

/// Bytes per heap word.
const WORD: u64 = core::mem::size_of::<encore_vm::value::Value>() as u64;

/// The part of [`VmStats`] that [`RunStats`] needs: without the 64 opcode
/// counters, so that keeping one across a run costs the firmware's stack
/// (measured by `stack_peak_bytes`) about 100 bytes rather than 600.
#[derive(Clone, Copy, Debug, Default)]
pub struct Snapshot {
    pub op_count: u64,
    pub peak_heap: usize,
    pub gc: GcStats,
}

impl Snapshot {
    /// Not inlined, so the full `VmStats` copy lives in this frame only.
    #[inline(never)]
    pub fn of(vm: &Vm<'_>) -> Snapshot {
        Snapshot::from(&vm.stats())
    }
}

impl From<&VmStats> for Snapshot {
    fn from(st: &VmStats) -> Snapshot {
        Snapshot { op_count: st.op_count, peak_heap: st.arena.peak_heap, gc: st.gc }
    }
}

/// What happened in the VM between two [`Snapshot`]s.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct RunStats {
    /// VM instructions executed.
    pub ops: u64,
    /// Heap high-water mark since boot, in bytes.
    pub heap_peak_bytes: u64,
    /// Collections.
    pub gc_count: u64,
    /// Bytes freed by those collections.
    pub gc_reclaimed_bytes: u64,
    /// Live bytes after the most recent collection since boot.
    pub gc_live_bytes: u64,
    /// Sum of the pauses, in clock units.
    pub gc_pause_total: u64,
    /// Longest pause since boot, in clock units.
    pub gc_pause_max_since_boot: u64,
    /// Time per collector phase: mark, forward, update, compact.
    pub gc_phases: [u64; 4],
}

impl RunStats {
    pub fn between(before: &Snapshot, after: &Snapshot) -> RunStats {
        let (b, a) = (&before.gc, &after.gc);
        RunStats {
            ops: after.op_count - before.op_count,
            heap_peak_bytes: after.peak_heap as u64 * WORD,
            gc_count: a.count - b.count,
            gc_reclaimed_bytes: (a.reclaimed - b.reclaimed) * WORD,
            gc_live_bytes: a.last_live as u64 * WORD,
            gc_pause_total: a.total_pause - b.total_pause,
            gc_pause_max_since_boot: a.max_pause,
            gc_phases: [
                a.phases.mark - b.phases.mark,
                a.phases.forward - b.phases.forward,
                a.phases.update - b.phases.update,
                a.phases.compact - b.phases.compact,
            ],
        }
    }

    /// Adds `vm_ops`, `heap_peak_bytes` and `gc` to a record. `unit` is the
    /// clock's (`config::VM_CLOCK_UNIT`); with `"none"` the GC times are
    /// left out, since they would all read 0.
    pub fn record<'w, W: Write>(&self, r: Record<'w, W>, unit: &str) -> Record<'w, W> {
        r.u64("vm_ops", self.ops)
            .u32("heap_peak_bytes", self.heap_peak_bytes as u32)
            .obj("gc", |o| {
                o.u64("count", self.gc_count)
                    .u64("reclaimed_bytes", self.gc_reclaimed_bytes)
                    .u64("live_bytes", self.gc_live_bytes);
                if unit != "none" {
                    let [mark, forward, update, compact] = self.gc_phases;
                    o.str("unit", unit)
                        .u64("pause_total", self.gc_pause_total)
                        .u64("pause_max_since_boot", self.gc_pause_max_since_boot)
                        .u64("mark", mark)
                        .u64("forward", forward)
                        .u64("update", update)
                        .u64("compact", compact);
                }
            })
    }
}

#[cfg(all(target_arch = "arm", target_os = "none"))]
pub use clock::start_clock;

/// The clock given to `Vm::set_clock`. `encore_vm` reads it a few times per
/// collection and around each call into the VM, never per instruction.
#[cfg(all(target_arch = "arm", target_os = "none"))]
mod clock {
    use core::sync::atomic::{AtomicU32, Ordering};
    use cortex_m::peripheral::syst::SystClkSource;
    use cortex_m::peripheral::{DWT, SYST};
    use cortex_m_rt::exception;
    use encore_vm::stats::Clock;

    /// Start the clock named by `config::VM_CLOCK` and return it:
    ///
    /// - `"dwt"`: `CYCCNT`, extended to 64 bits in software (the VM reads
    ///   it far more often than every 2^32 cycles);
    /// - `"systick"`: SysTick free-running on the core clock, its 24 bits
    ///   extended by counting wraps in the `SysTick` handler, times `scale`
    ///   ns per tick. Under QEMU's `-icount shift=0` that is one unit per
    ///   instruction;
    /// - anything else: no clock, GC times stay 0.
    pub fn start_clock(source: &str, scale: u32, p: &mut cortex_m::Peripherals) -> Option<Clock> {
        match source {
            "dwt" => {
                p.DCB.enable_trace();
                DWT::unlock();
                p.DWT.enable_cycle_counter();
                Some(dwt_now)
            }
            "systick" => {
                NS_PER_TICK.store(scale, Ordering::Relaxed);
                let syst = &mut p.SYST;
                syst.set_clock_source(SystClkSource::Core);
                syst.set_reload(RELOAD);
                syst.clear_current();
                syst.enable_interrupt();
                syst.enable_counter();
                Some(systick_now)
            }
            _ => None,
        }
    }

    static DWT_LAST: AtomicU32 = AtomicU32::new(0);
    static DWT_HIGH: AtomicU32 = AtomicU32::new(0);

    fn dwt_now() -> u64 {
        let now = DWT::cycle_count();
        if now < DWT_LAST.load(Ordering::Relaxed) {
            DWT_HIGH.fetch_add(1, Ordering::Relaxed);
        }
        DWT_LAST.store(now, Ordering::Relaxed);
        ((DWT_HIGH.load(Ordering::Relaxed) as u64) << 32) | now as u64
    }

    const RELOAD: u32 = 0x00FF_FFFF;
    static NS_PER_TICK: AtomicU32 = AtomicU32::new(0);
    static WRAPS: AtomicU32 = AtomicU32::new(0);

    #[exception]
    fn SysTick() {
        WRAPS.fetch_add(1, Ordering::Relaxed);
    }

    fn systick_now() -> u64 {
        loop {
            let wraps = WRAPS.load(Ordering::Relaxed);
            let elapsed = RELOAD - SYST::get_current();
            // Retry if the wrap interrupt ran between the two reads.
            if WRAPS.load(Ordering::Relaxed) == wraps {
                let ticks = ((wraps as u64) << 24) | elapsed as u64;
                return ticks * NS_PER_TICK.load(Ordering::Relaxed) as u64;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn differences_and_maxima() {
        let mut before = VmStats::default();
        before.op_count = 100;
        before.gc.count = 1;
        before.gc.reclaimed = 10;
        before.gc.total_pause = 50;
        before.gc.max_pause = 50;
        before.gc.phases.mark = 5;
        let mut after = before;
        after.op_count = 350;
        after.arena.peak_heap = 64;
        after.gc.count = 4;
        after.gc.reclaimed = 40;
        after.gc.last_live = 8;
        after.gc.total_pause = 170;
        after.gc.max_pause = 60;
        after.gc.phases.mark = 25;
        after.gc.phases.compact = 7;
        let st = RunStats::between(&(&before).into(), &(&after).into());
        assert_eq!(
            st,
            RunStats {
                ops: 250,
                heap_peak_bytes: 64 * WORD,
                gc_count: 3,
                gc_reclaimed_bytes: 30 * WORD,
                gc_live_bytes: 8 * WORD,
                gc_pause_total: 120,
                gc_pause_max_since_boot: 60,
                gc_phases: [20, 0, 0, 7],
            }
        );
    }
}
