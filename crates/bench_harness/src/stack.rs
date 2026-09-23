//! Peak stack use by stack painting.
//!
//! [`paint`] fills the free RAM between the end of static data (`__sheap`,
//! from cortex-m-rt's `link.x`) and the current stack pointer with
//! [`PATTERN`]. After the measured code has run, [`peak`] finds the lowest
//! word that no longer holds the pattern: everything above it has been used
//! as stack. The Encore VM has no call stack, so for E this mostly measures
//! the Rust driver; for R and C it is the real figure.

/// Paint pattern.
pub const PATTERN: u32 = 0xDEAD_BEEF;

#[cfg(all(target_arch = "arm", target_os = "none"))]
mod imp {
    use super::PATTERN;
    use core::ptr::{read_volatile, write_volatile};

    /// Bytes left unpainted below the stack pointer inside [`paint`], so
    /// that it never overwrites its own frame.
    const MARGIN: usize = 64;

    unsafe extern "C" {
        static __sheap: u32;
        static _stack_start: u32;
    }

    fn bottom() -> usize {
        (&raw const __sheap) as usize
    }

    fn top() -> usize {
        (&raw const _stack_start) as usize
    }

    #[inline(always)]
    fn sp() -> usize {
        let sp: usize;
        unsafe { core::arch::asm!("mov {}, sp", out(reg) sp, options(nomem, nostack)) };
        sp
    }

    #[inline(never)]
    pub fn paint() {
        let end = (sp() - MARGIN) & !3;
        let mut p = (bottom() + 3) & !3;
        while p < end {
            unsafe { write_volatile(p as *mut u32, PATTERN) };
            p += 4;
        }
    }

    #[inline(never)]
    pub fn peak() -> Option<usize> {
        let mut p = (bottom() + 3) & !3;
        let limit = sp();
        while p < limit && unsafe { read_volatile(p as *const u32) } == PATTERN {
            p += 4;
        }
        // Nothing painted left at the bottom: the stack reached static data
        // (or `paint` was never called), so the figure would be a lie.
        if p == (bottom() + 3) & !3 { None } else { Some(top() - p) }
    }
}

#[cfg(not(all(target_arch = "arm", target_os = "none")))]
mod imp {
    pub fn paint() {}
    pub fn peak() -> Option<usize> {
        None
    }
}

/// Paint free stack. Call right before the measured code.
pub use imp::paint;

/// Peak stack use in bytes since the last [`paint`], or `None` if it cannot
/// be trusted (never painted, or the stack overflowed into static data).
pub use imp::peak;
