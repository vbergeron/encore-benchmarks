//! W2 transaction decoder (Ethereum RLP), variant C: the Gallina `run`
//! compiled by CertiRocq to C (gcc -Os), on the CertiRocq runtime over a
//! fixed arena. The signing payload is read through the input_byte extern,
//! as in E.

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

/// Run the case with `n` bytes of calldata: decode its payload and render
/// the screen.
fn run(n: u32) -> Result<Value, &'static str> {
    crq::run(body, crq::int(vectors::payload(n).len() as isize))
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w2_rlp", "C", samples, |r| {
        r.u32("heap_bytes", config::HEAP_BYTES as u32)
            .u32("c_log_nursery", config::C_LOG_NURSERY)
    });

    // Every case of the other variants, so that E, C and R are compared on
    // the same N. A case that does not fit (arena or C stack exhausted) is
    // recorded as failed, with the reason.
    for &n in vectors::CASES {
        crq::set_input(vectors::payload(n));
        let screen = match run(n) {
            Ok(v) => v,
            Err(reason) => {
                s.fail(n, reason);
                continue;
            }
        };
        let mut hash = Fnv1a::new();
        // SAFETY: `screen` is the result of the latest run. Each field's
        // characters, then -1, as in R.
        for field in unsafe { crq::list(screen) } {
            for c in unsafe { crq::list(field) } {
                hash.int(crq::int_val(c) as i64);
            }
            hash.int(-1);
        }
        let arena_peak = crq::arena_peak();

        let timed_ok = Cell::new(true);
        s.case(
            n,
            hash.finish(),
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
