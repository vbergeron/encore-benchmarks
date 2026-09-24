//! W1 APDU and BER-TLV parser, variant E: the extracted `run` executed by
//! encore_vm, reading the command APDU through the input extern.

#![no_std]
#![no_main]

use bench_harness::cycles::BoardCycles;
use bench_harness::semihosting::{exit, Stdout};
use bench_harness::{FmtBuf, Fnv1a, Harness, Session};
use core::cell::Cell;
use core::fmt::Write as _;
use core::hint::black_box;
use core::sync::atomic::{AtomicU32, Ordering};
use cortex_m_rt::entry;
use encore_vm::error::ExternError;
use encore_vm::ffi::VmList;
use encore_vm::value::Value;
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

/// The case being run: its APDU is what `input_byte` reads.
static CASE: AtomicU32 = AtomicU32::new(0);

/// Extern slot 0, `input_byte` in Encore.Extraction.ExtrEncoreInput: byte
/// `i` of the current command APDU. The argument is the extern's one-field
/// argument pack.
fn input_byte(vm: &mut Vm, arg: Value) -> Result<Value, ExternError> {
    let i = vm.ctor_field(arg, 0).int_value()?;
    match vectors::apdu(CASE.load(Ordering::Relaxed)).get(i as usize) {
        Some(&b) => Ok(Value::int(b as i32)),
        None => Err(ExternError::Custom("input_byte: index out of range")),
    }
}

fn run(vm: &mut Vm, n: u32) -> Result<VmList<i32>, ExternError> {
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
    vm.register_extern(0, input_byte);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w1_apdu", "E", samples, |r| {
        r.u32("program_bytes", config::PROGRAM_BYTES as u32)
            .u32("heap_bytes", config::HEAP_BYTES as u32)
            .bool("cps_optimize", config::CPS_OPTIMIZE)
    });

    for &n in vectors::CASES {
        CASE.store(n, Ordering::Relaxed);
        #[cfg(feature = "stats")]
        let ops_before = vm.stats().op_count;
        let summary = match run(&mut vm, n) {
            Ok(summary) => summary,
            Err(e) => {
                let mut reason = FmtBuf::<64>::new();
                let _ = write!(reason, "{e:?}");
                s.fail(n, reason.as_str());
                continue;
            }
        };
        // Hashed before any other VM call: the next allocation may collect
        // and move the list.
        let mut hash = Fnv1a::new();
        for v in summary.iter(&vm) {
            hash.int(v as i64);
        }
        // Peak heap is a running maximum since boot (encore_vm has no reset),
        // so it is read right after the untimed run; cases go by increasing N.
        #[cfg(feature = "stats")]
        let (ops, heap_peak) = {
            let st = vm.stats();
            (st.op_count - ops_before, st.arena.peak_heap * core::mem::size_of::<Value>())
        };

        // A timed run can fail where the untimed one passed (the heap is not
        // in the same state); the runner then marks the case failed.
        let timed_ok = Cell::new(true);
        let vm = &mut vm;
        s.case(
            n,
            hash.finish(),
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
