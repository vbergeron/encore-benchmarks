//! Device-side measurement harness, shared by every variant (E, C, R, R+V).
//!
//! A firmware measures one workload like this:
//!
//! ```ignore
//! let mut h = Harness::new(cycles::for_board(DWT, core_peripherals), out);
//! h.calibrate(&mut samples);
//! stack::paint();
//! let s = h.time(&mut samples, || black_box(run(input)));
//! h.record("case").str("workload", "w0").u32("n", n).timing(&s).stack(stack::peak()).finish();
//! ```
//!
//! Every measured call is a **region**, bracketed by [`region_begin`] and
//! [`region_end`]. On boards with a DWT the harness reads `CYCCNT` around
//! it. On QEMU, where cycles mean nothing, `scripts/bench.py` counts the
//! instructions executed between the two markers from QEMU's execution
//! trace. Records say how many regions they cover (`"regions"`), so the
//! runner can match counts to records in order.
//!
//! Records are single JSON objects on one line, prefixed by [`RECORD_PREFIX`]
//! so they can be picked out of other output. The device only writes what it
//! knows (workload, variant, N, measurements); the runner adds the commit,
//! board, toolchain and ELF sizes before appending to `results/*.jsonl`.

#![no_std]

pub mod cycles;
pub mod hash;
pub mod record;
pub mod session;
pub mod stack;
pub mod summary;

#[cfg(all(feature = "semihosting", target_arch = "arm", target_os = "none"))]
pub mod semihosting;

use core::fmt::Write;

pub use cycles::CycleCounter;
pub use hash::Fnv1a;
pub use record::{FmtBuf, Record};
pub use session::Session;
pub use summary::Summary;

/// Prefix of every record line.
pub const RECORD_PREFIX: &str = "@@BENCH ";

/// Start of a measured region. Its address is looked up in the ELF by the
/// runner; the body only has to differ from [`region_end`] so the linker
/// cannot fold them together.
#[inline(never)]
#[unsafe(no_mangle)]
pub extern "C" fn bench_region_begin() {
    core::sync::atomic::compiler_fence(core::sync::atomic::Ordering::SeqCst);
    marker_body(1);
}

/// End of a measured region. See [`bench_region_begin`].
#[inline(never)]
#[unsafe(no_mangle)]
pub extern "C" fn bench_region_end() {
    marker_body(2);
    core::sync::atomic::compiler_fence(core::sync::atomic::Ordering::SeqCst);
}

#[inline(always)]
fn marker_body(tag: u32) {
    core::hint::black_box(tag);
}

pub use bench_region_begin as region_begin;
pub use bench_region_end as region_end;

/// Ties a cycle source to an output sink.
pub struct Harness<C: CycleCounter, W: Write> {
    counter: C,
    out: W,
    /// Cycles spent by an empty region, subtracted from every sample.
    overhead: u32,
}

impl<C: CycleCounter, W: Write> Harness<C, W> {
    pub fn new(counter: C, out: W) -> Self {
        Harness { counter, out, overhead: 0 }
    }

    /// Whether [`time`](Self::time) returns real cycle counts.
    pub fn has_cycles(&self) -> bool {
        self.counter.is_real()
    }

    /// Measure an empty region `samples.len()` times, remember its median as
    /// the fixed overhead, and emit a `calibration` record. The runner uses
    /// the same record to subtract the instruction overhead on QEMU.
    pub fn calibrate(&mut self, samples: &mut [u32]) {
        self.overhead = 0;
        let s = self.time(samples, || ());
        self.overhead = s.median;
        self.record("calibration").timing(&s).finish();
    }

    /// Run `f` once per slot of `samples`, each run in its own region, and
    /// summarise the cycle counts (all zero without a DWT). Keep the result
    /// of `f` alive with `core::hint::black_box` so it is not optimised out.
    pub fn time<F: FnMut()>(&mut self, samples: &mut [u32], mut f: F) -> Summary {
        for slot in samples.iter_mut() {
            region_begin();
            let start = self.counter.now();
            f();
            let end = self.counter.now();
            region_end();
            *slot = end.wrapping_sub(start).saturating_sub(self.overhead);
        }
        Summary::from_samples(samples, self.counter.is_real())
    }

    /// Start a record of the given kind (`"case"`, `"build"`, ...).
    pub fn record(&mut self, kind: &str) -> Record<'_, W> {
        Record::new(&mut self.out, kind)
    }

    /// Free-form diagnostic output, ignored by the runner.
    pub fn log(&mut self, args: core::fmt::Arguments<'_>) {
        let _ = self.out.write_fmt(args);
        let _ = self.out.write_char('\n');
    }
}
