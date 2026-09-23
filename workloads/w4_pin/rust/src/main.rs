//! W4 PIN state machine, variant R. Also the oracle: its `out_hash` values
//! are the reference every other variant must reproduce.

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

const MAX_TRIES: u8 = 3;
const MAX_PUK_TRIES: u8 = 10;
const PUK_LEN: usize = 8;
/// Longest reference data (PIN or PUK) the card stores.
const MAX_SECRET: usize = 16;

/// Response codes, as in the Gallina: 0 ok, 1 blocked, 2 denied, 3 bad
/// instruction, 4 + n wrong secret with n tries left.
const OK: u8 = 0;
const BLOCKED: u8 = 1;
const DENIED: u8 = 2;
const BAD_INS: u8 = 3;
const fn wrong(left: u8) -> u8 {
    4 + left
}

#[derive(Clone, Copy)]
struct Secret {
    len: usize,
    bytes: [u8; MAX_SECRET],
}

impl Secret {
    fn new(digits: &[u8]) -> Self {
        let mut bytes = [0; MAX_SECRET];
        bytes[..digits.len()].copy_from_slice(digits);
        Secret { len: digits.len(), bytes }
    }

    fn matches(&self, guess: &[u8]) -> bool {
        &self.bytes[..self.len] == guess
    }
}

struct Card {
    pin: Secret,
    puk: Secret,
    tries: u8,
    puk_tries: u8,
    auth: bool,
}

impl Card {
    fn new() -> Self {
        Card {
            pin: Secret::new(&[1, 2, 3, 4]),
            puk: Secret::new(&[1, 2, 3, 4, 5, 6, 7, 8]),
            tries: MAX_TRIES,
            puk_tries: MAX_PUK_TRIES,
            auth: false,
        }
    }

    fn handle(&mut self, ins: u8, data: &[u8]) -> u8 {
        match ins {
            0x20 => {
                if self.tries == 0 {
                    self.auth = false;
                    return BLOCKED;
                }
                if self.pin.matches(data) {
                    self.tries = MAX_TRIES;
                    self.auth = true;
                    OK
                } else {
                    self.tries -= 1;
                    self.auth = false;
                    wrong(self.tries)
                }
            }
            0x24 => {
                if !self.auth {
                    return DENIED;
                }
                self.pin = Secret::new(data);
                OK
            }
            0x2C => {
                if self.puk_tries == 0 {
                    return BLOCKED;
                }
                let (guess, new_pin) = data.split_at(data.len().min(PUK_LEN));
                self.auth = false;
                if self.puk.matches(guess) {
                    self.pin = Secret::new(new_pin);
                    self.tries = MAX_TRIES;
                    self.puk_tries = MAX_PUK_TRIES;
                    OK
                } else {
                    self.puk_tries -= 1;
                    wrong(self.puk_tries)
                }
            }
            0xA4 => {
                self.auth = false;
                OK
            }
            _ => BAD_INS,
        }
    }
}

/// Handle the APDUs of `stream` from a fresh card, one response code per
/// APDU into `out`. Returns the number of responses.
fn run(stream: &[u8], out: &mut [u8]) -> usize {
    let mut card = Card::new();
    let mut rest = stream;
    let mut n = 0;
    while let [ins, lc, tail @ ..] = rest {
        let (data, next) = tail.split_at(*lc as usize);
        out[n] = card.handle(*ins, data);
        n += 1;
        rest = next;
    }
    n
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut OUT: [u8; vectors::MAX_APDUS] = [0; vectors::MAX_APDUS];
    // SAFETY: only references to SAMPLES and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let resp = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w4_pin", "R", samples, |r| r);
    for &n in vectors::CASES {
        let stream = &vectors::STREAM[..vectors::stream_len(n as usize)];
        let len = run(stream, resp);
        let mut hash = Fnv1a::new();
        for &c in &resp[..len] {
            hash.int(c as i64);
        }
        s.case(n, hash.finish(), || { black_box(run(black_box(stream), resp)); }, |r| r);
    }
    exit(true)
}
