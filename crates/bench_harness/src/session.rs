//! The common driver loop of a benchmark firmware.

use crate::{stack, CycleCounter, Harness, Record};
use core::fmt::Write;

/// One firmware run of one (workload, variant): a `start` record, a
/// calibration, then one `case` record per input vector.
pub struct Session<'s, C: CycleCounter, W: Write> {
    h: Harness<C, W>,
    workload: &'static str,
    variant: &'static str,
    samples: &'s mut [u32],
}

impl<'s, C: CycleCounter, W: Write> Session<'s, C, W> {
    /// Emit the `start` record (plus whatever `extra` adds, e.g. the
    /// bytecode size) and calibrate the region overhead.
    pub fn start(
        mut h: Harness<C, W>,
        workload: &'static str,
        variant: &'static str,
        samples: &'s mut [u32],
        extra: impl FnOnce(Record<'_, W>) -> Record<'_, W>,
    ) -> Self {
        let cycles = h.has_cycles();
        let r = h
            .record("start")
            .str("workload", workload)
            .str("variant", variant)
            .u32("reps", samples.len() as u32)
            .bool("cycles", cycles);
        extra(r).finish();
        h.calibrate(samples);
        Session { h, workload, variant, samples }
    }

    /// Measure one input vector.
    ///
    /// `n` is the workload's size parameter, `out_hash` the [`crate::Fnv1a`]
    /// of the output of an untimed run (checked against the R oracle by the
    /// runner), and `run` performs one timed run. The stack is painted
    /// before the timed runs and read after them.
    pub fn case(
        &mut self,
        n: u32,
        out_hash: u32,
        run: impl FnMut(),
        extra: impl FnOnce(Record<'_, W>) -> Record<'_, W>,
    ) {
        stack::paint();
        let s = self.h.time(self.samples, run);
        let peak = stack::peak();
        let r = self
            .h
            .record("case")
            .str("workload", self.workload)
            .str("variant", self.variant)
            .u32("n", n)
            .hex("out_hash", out_hash)
            .timing(&s)
            .stack(peak);
        extra(r).finish();
    }

    /// Report a failed case (e.g. out of heap) instead of measuring it.
    pub fn fail(&mut self, n: u32, reason: &str) {
        self.h
            .record("fail")
            .str("workload", self.workload)
            .str("variant", self.variant)
            .u32("n", n)
            .str("reason", reason)
            .finish();
    }

    pub fn harness(&mut self) -> &mut Harness<C, W> {
        &mut self.h
    }
}
