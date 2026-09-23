//! Cycle sources.

/// Something that counts CPU cycles.
pub trait CycleCounter {
    fn now(&self) -> u32;
    /// `false` for [`NoCycles`]: the values are placeholders.
    fn is_real(&self) -> bool;
}

/// For QEMU: cycles are not modelled, so the runner counts instructions
/// between region markers instead.
pub struct NoCycles;

impl CycleCounter for NoCycles {
    #[inline(always)]
    fn now(&self) -> u32 {
        0
    }
    fn is_real(&self) -> bool {
        false
    }
}

#[cfg(all(target_arch = "arm", target_os = "none"))]
pub use arm::*;

#[cfg(all(target_arch = "arm", target_os = "none"))]
mod arm {
    use super::{CycleCounter, NoCycles};
    use cortex_m::peripheral::{DCB, DWT};

    /// The DWT `CYCCNT` register. 32 bits: wraps after 2^32 cycles (about
    /// 27 s at 160 MHz), far above any single region we measure.
    pub struct Dwt(());

    impl Dwt {
        /// Enable trace and the cycle counter. On ARMv8-M the DWT may need
        /// unlocking first on some parts; `DWT::unlock` handles the Cortex-M7
        /// lock and is a no-op elsewhere.
        pub fn enable(dcb: &mut DCB, dwt: &mut DWT) -> Dwt {
            dcb.enable_trace();
            DWT::unlock();
            dwt.set_cycle_count(0);
            dwt.enable_cycle_counter();
            Dwt(())
        }
    }

    impl CycleCounter for Dwt {
        #[inline(always)]
        fn now(&self) -> u32 {
            DWT::cycle_count()
        }
        fn is_real(&self) -> bool {
            true
        }
    }

    /// The board's cycle source: the DWT when `dwt` (from `bench_config.rs`)
    /// says it is trustworthy, [`NoCycles`] otherwise.
    pub enum BoardCycles {
        Dwt(Dwt),
        None(NoCycles),
    }

    impl BoardCycles {
        pub fn new(dwt: bool, p: &mut cortex_m::Peripherals) -> Self {
            if dwt {
                BoardCycles::Dwt(Dwt::enable(&mut p.DCB, &mut p.DWT))
            } else {
                BoardCycles::None(NoCycles)
            }
        }
    }

    impl CycleCounter for BoardCycles {
        #[inline(always)]
        fn now(&self) -> u32 {
            match self {
                BoardCycles::Dwt(d) => d.now(),
                BoardCycles::None(n) => n.now(),
            }
        }
        fn is_real(&self) -> bool {
            matches!(self, BoardCycles::Dwt(_))
        }
    }
}
