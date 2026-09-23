//! W0 smoke, variant R. Also the oracle: its `out_hash` values are the
//! reference every other variant must reproduce.

#![no_std]
#![no_main]

use bench_harness::cycles::BoardCycles;
use bench_harness::semihosting::{exit, Stdout};
use bench_harness::{Fnv1a, Harness, Session};
use core::hint::black_box;
use cortex_m_rt::entry;
use panic_halt as _;

mod config {
    include!(concat!(env!("OUT_DIR"), "/bench_config.rs"));
}

mod vectors {
    include!("../../vectors/vectors.rs");
}

/// Sum of 1..=n, the way a firmware developer would write it.
fn run(n: u32) -> u32 {
    (1..=n).sum()
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w0_smoke", "R", samples, |r| r);
    for &n in vectors::CASES {
        let hash = Fnv1a::new().int(run(n) as i64).finish();
        s.case(n, hash, || { black_box(run(black_box(n))); }, |r| r);
    }
    exit(true)
}
