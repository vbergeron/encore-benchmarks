//! W8 CRC-16 / CRC-32, variant R. Also the oracle: its `out_hash` values
//! are the reference every other variant must reproduce.
//!
//! One run computes the CRC-16/MODBUS and the CRC-32/ISO-HDLC of the
//! block, with the usual byte-at-a-time lookup tables, built at compile
//! time into flash.

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

/// Table of a reflected CRC: entry `i` is the register after shifting the
/// byte `i` through it, eight bits.
const fn table<const N: usize>(poly: u32) -> [u32; N] {
    let mut t = [0u32; N];
    let mut i = 0;
    while i < N {
        let mut c = i as u32;
        let mut k = 0;
        while k < 8 {
            c = if c & 1 != 0 { (c >> 1) ^ poly } else { c >> 1 };
            k += 1;
        }
        t[i] = c;
        i += 1;
    }
    t
}

static CRC16_TABLE: [u16; 256] = {
    let t: [u32; 256] = table(0xA001);
    let mut u = [0u16; 256];
    let mut i = 0;
    while i < 256 {
        u[i] = t[i] as u16;
        i += 1;
    }
    u
};

static CRC32_TABLE: [u32; 256] = table(0xEDB8_8320);

/// CRC-16/MODBUS: polynomial 0x8005 reflected, init 0xFFFF, no final XOR.
fn crc16(data: &[u8]) -> u16 {
    data.iter().fold(0xFFFF, |c, &b| (c >> 8) ^ CRC16_TABLE[((c ^ b as u16) & 0xFF) as usize])
}

/// CRC-32/ISO-HDLC: polynomial 0x04C11DB7 reflected, init and final XOR
/// 0xFFFFFFFF.
fn crc32(data: &[u8]) -> u32 {
    !data.iter().fold(!0, |c, &b| (c >> 8) ^ CRC32_TABLE[((c ^ b as u32) & 0xFF) as usize])
}

fn run(block: &[u8]) -> (u16, u32) {
    (crc16(block), crc32(block))
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    // SAFETY: only reference to SAMPLES, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };

    let mut s = Session::start(h, "w8_crc", "R", samples, |r| r);
    for &n in vectors::CASES {
        let block = &vectors::BLOCK[..n as usize];
        let (c16, c32) = run(block);
        // CRC-32 in two 16-bit halves, high first: Encore integers are
        // 24-bit.
        let mut hash = Fnv1a::new();
        hash.int(c16 as i64);
        hash.int((c32 >> 16) as i64);
        hash.int((c32 & 0xFFFF) as i64);
        s.case(n, hash.finish(), || { black_box(run(black_box(block))); }, |r| r);
    }
    exit(true)
}
