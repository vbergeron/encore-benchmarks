//! W0 smoke, variant C: the Gallina `run` compiled by CertiRocq to C
//! (gcc -Os), on the CertiRocq runtime over a fixed arena.

#![no_std]
#![no_main]

use bench_harness::certirocq::{self as crq, Value};
use bench_harness::cycles::BoardCycles;
use bench_harness::semihosting::{exit, Stdout};
use bench_harness::{Fnv1a, Harness, Session};
use core::cell::Cell;
use core::hint::black_box;
use cortex_m_rt::entry;
use panic_halt as _;

mod config {
    include!(concat!(env!("OUT_DIR"), "/bench_config.rs"));
}

#[allow(dead_code)]
mod vectors {
    include!("../../vectors/vectors.rs");
}

unsafe extern "C" {
    /// Top level of the generated program (gen/): the closure of `run`.
    fn body(tinfo: *mut core::ffi::c_void) -> Value;
}

/// The cases of `vectors::CASES` that fit the RAM budget. The direct-style
/// C recurses once per list element in `range_from` and `sum`, so N = 1000
/// exhausts the C stack; see the README.
const CASES: &[u32] = &[1, 10, 100];

fn run(n: u32) -> Result<Value, &'static str> {
    crq::run(body, crq::int(n as isize))
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w0_smoke", "C", samples, |r| {
        r.u32("heap_bytes", config::HEAP_BYTES as u32)
            .u32("c_log_nursery", config::C_LOG_NURSERY)
    });

    for &n in CASES {
        let sum = match run(n) {
            Ok(v) => v,
            Err(reason) => {
                s.fail(n, reason);
                continue;
            }
        };
        let hash = Fnv1a::new().int(crq::int_val(sum) as i64).finish();
        let arena_peak = crq::arena_peak();

        let timed_ok = Cell::new(true);
        s.case(
            n,
            hash,
            || {
                if black_box(run(black_box(n))).is_err() {
                    timed_ok.set(false);
                }
            },
            |r| r.bool("timed_ok", timed_ok.get()).u32("heap_peak_bytes", arena_peak),
        );
    }
    exit(true)
}
