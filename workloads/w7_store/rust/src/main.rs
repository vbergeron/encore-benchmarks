//! W7 FIDO credential store, variant R. Also the oracle: its `out_hash`
//! values are the reference every other variant must reproduce.

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

/// Credentials the store can hold.
const CAPACITY: usize = vectors::MAX_REGS;

/// Resident credentials, sorted by handle, with their signature counters.
struct Store {
    handles: [u16; CAPACITY],
    counters: [u32; CAPACITY],
    len: usize,
}

impl Store {
    const fn new() -> Self {
        Store { handles: [0; CAPACITY], counters: [0; CAPACITY], len: 0 }
    }

    fn clear(&mut self) {
        self.len = 0;
    }

    /// Stores `handle` with `counter`, replacing its counter if it is
    /// already there.
    fn register(&mut self, handle: u16, counter: u32) {
        match self.handles[..self.len].binary_search(&handle) {
            Ok(i) => self.counters[i] = counter,
            Err(i) => {
                self.handles.copy_within(i..self.len, i + 1);
                self.counters.copy_within(i..self.len, i + 1);
                self.handles[i] = handle;
                self.counters[i] = counter;
                self.len += 1;
            }
        }
    }

    /// Bumps the counter of `handle`: its new value, or 0 if unknown.
    fn assert(&mut self, handle: u16) -> u32 {
        match self.handles[..self.len].binary_search(&handle) {
            Ok(i) => {
                self.counters[i] += 1;
                self.counters[i]
            }
            Err(_) => 0,
        }
    }
}

fn be_u16(b: &[u8]) -> u16 {
    u16::from_be_bytes([b[0], b[1]])
}

/// Register the first `n` credentials of `input` in an empty store, then
/// answer its assertions into `out`. Returns the number of answers.
fn run(input: &[u8], n: usize, store: &mut Store, out: &mut [u32]) -> usize {
    let q = input[0] as usize;
    let (asserts, regs) = input[1..].split_at(2 * q);
    store.clear();
    for reg in regs.chunks_exact(4).take(n) {
        store.register(be_u16(reg), be_u16(&reg[2..]) as u32);
    }
    for (a, handle) in out.iter_mut().zip(asserts.chunks_exact(2)) {
        *a = store.assert(be_u16(handle));
    }
    q
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut STORE: Store = Store::new();
    static mut OUT: [u32; vectors::ASSERTS] = [0; vectors::ASSERTS];
    // SAFETY: only references to SAMPLES, STORE and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let store = unsafe { &mut *(&raw mut STORE) };
    let answers = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w7_store", "R", samples, |r| r);
    for &n in vectors::CASES {
        let input = &vectors::STREAM[..];
        let len = run(input, n as usize, store, answers);
        let mut hash = Fnv1a::new();
        for &a in &answers[..len] {
            hash.int(a as i64);
        }
        s.case(
            n,
            hash.finish(),
            || { black_box(run(black_box(input), n as usize, store, answers)); },
            |r| r,
        );
    }
    exit(true)
}
