//! W0 smoke, variant E: the extracted `run` executed by encore_vm.

#![no_std]
#![no_main]

use bench_harness::cycles::BoardCycles;
use bench_harness::semihosting::{exit, Stdout};
use bench_harness::{FmtBuf, Fnv1a, Harness, Session};
use core::cell::Cell;
use core::hint::black_box;
use cortex_m_rt::entry;
use core::fmt::Write as _;
use encore_vm::error::ExternError;
use encore_vm::vm::Vm;
use panic_halt as _;

mod config {
    include!(concat!(env!("OUT_DIR"), "/bench_config.rs"));
}

mod vectors {
    include!("../../vectors/vectors.rs");
}

encore_vm::encore_program!(env!("OUT_DIR"));
encore_vm::encore_heap!(HEAP, config::HEAP_BYTES);

fn run(vm: &mut Vm, n: u32) -> Result<i32, ExternError> {
    vm.call_global(funcs::RUN, (n as i32,))
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let mut h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    let Ok(mut vm) = boot(HEAP()) else {
        h.log(format_args!("encore: boot failed"));
        exit(false)
    };

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w0_smoke", "E", samples, |r| {
        r.u32("program_bytes", config::PROGRAM_BYTES as u32)
            .u32("heap_bytes", config::HEAP_BYTES as u32)
            .bool("cps_optimize", config::CPS_OPTIMIZE)
    });

    for &n in vectors::CASES {
        #[cfg(feature = "stats")]
        let ops_before = vm.stats().op_count;
        let out = match run(&mut vm, n) {
            Ok(out) => out,
            Err(e) => {
                let mut reason = FmtBuf::<64>::new();
                let _ = write!(reason, "{e:?}");
                s.fail(n, reason.as_str());
                continue;
            }
        };
        // Peak heap is a running maximum since boot (encore_vm has no reset),
        // so it is read right after the untimed run; cases go by increasing N.
        #[cfg(feature = "stats")]
        let (ops, heap_peak) = {
            let st = vm.stats();
            (st.op_count - ops_before, st.arena.peak_heap * core::mem::size_of::<encore_vm::value::Value>())
        };
        let hash = Fnv1a::new().int(out as i64).finish();

        // A timed run can fail where the untimed one passed (the heap is not
        // in the same state); the runner then marks the case failed.
        let timed_ok = Cell::new(true);
        let vm = &mut vm;
        s.case(
            n,
            hash,
            || {
                if black_box(run(vm, black_box(n))).is_err() {
                    timed_ok.set(false);
                }
            },
            |r| {
                let r = r.bool("timed_ok", timed_ok.get());
                #[cfg(feature = "stats")]
                let r = r.u64("vm_ops", ops).u32("heap_peak_bytes", heap_peak as u32);
                r
            },
        );
    }
    exit(true)
}
