//! W6 COBS framing, variant R. Also the oracle: its `out_hash` values are
//! the reference every other variant must reproduce.
//!
//! One run encodes the frame, then decodes the encoding.

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

/// Encode `src` into `dst` (at least `max_encoded(src.len())` bytes).
/// Returns the encoded length.
fn encode(src: &[u8], dst: &mut [u8]) -> usize {
    let mut code_at = 0;
    let mut code = 1u8;
    let mut w = 1;
    for &b in src {
        if b == 0 {
            dst[code_at] = code;
            code_at = w;
            w += 1;
            code = 1;
        } else {
            dst[w] = b;
            w += 1;
            code += 1;
            if code == 0xFF {
                dst[code_at] = code;
                code_at = w;
                w += 1;
                code = 1;
            }
        }
    }
    dst[code_at] = code;
    w
}

/// Decode `src` into `dst`. Returns the decoded length, or `None` if
/// `src` is not a valid encoding (empty, a zero byte, a truncated block)
/// or `dst` is too small.
fn decode(src: &[u8], dst: &mut [u8]) -> Option<usize> {
    if src.is_empty() {
        return None;
    }
    let (mut r, mut w) = (0, 0);
    while r < src.len() {
        let code = src[r] as usize;
        if code == 0 || r + code > src.len() {
            return None;
        }
        let block = &src[r + 1..r + code];
        if block.contains(&0) {
            return None;
        }
        dst.get_mut(w..w + block.len())?.copy_from_slice(block);
        w += block.len();
        r += code;
        if code < 0xFF && r < src.len() {
            *dst.get_mut(w)? = 0;
            w += 1;
        }
    }
    Some(w)
}

const ENC_MAX: usize = vectors::max_encoded(vectors::MAX_FRAME);

fn run(frame: &[u8], enc: &mut [u8; ENC_MAX], dec: &mut [u8; vectors::MAX_FRAME]) -> (usize, Option<usize>) {
    let n = encode(frame, enc);
    (n, decode(&enc[..n], dec))
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut ENC: [u8; ENC_MAX] = [0; ENC_MAX];
    static mut DEC: [u8; vectors::MAX_FRAME] = [0; vectors::MAX_FRAME];
    // SAFETY: only references to SAMPLES, ENC and DEC, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let enc = unsafe { &mut *(&raw mut ENC) };
    let dec = unsafe { &mut *(&raw mut DEC) };

    let mut s = Session::start(h, "w6_cobs", "R", samples, |r| r);
    for &n in vectors::CASES {
        let frame = &vectors::FRAME[..n as usize];
        let (enc_len, dec_len) = run(frame, enc, dec);
        let mut hash = Fnv1a::new();
        for &b in &enc[..enc_len] {
            hash.int(b as i64);
        }
        match dec_len {
            Some(len) => {
                for &b in &dec[..len] {
                    hash.int(b as i64);
                }
            }
            None => {
                hash.int(-1);
            }
        }
        s.case(n, hash.finish(), || { black_box(run(black_box(frame), enc, dec)); }, |r| r);
    }
    exit(true)
}
