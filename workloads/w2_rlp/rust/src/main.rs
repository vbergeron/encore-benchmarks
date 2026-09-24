//! W2 transaction decoder (Ethereum RLP), variant R. Also the oracle: its
//! `out_hash` values are the reference every other variant must reproduce.
//!
//! One run decodes the signing payload and renders the screen the user
//! approves: chain id, recipient, value, nonce, gas price, gas limit and
//! calldata, amounts in decimal and bytes in hexadecimal.

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

enum Item<'a> {
    Str(&'a [u8]),
    List(&'a [u8]),
}

/// A long length of `ll` bytes, in its shortest form.
fn long_len(ll: u8, buf: &[u8]) -> Option<(usize, &[u8])> {
    match (ll, buf) {
        (1, [n, rest @ ..]) if *n >= 56 => Some((*n as usize, rest)),
        (2, [hi, lo, rest @ ..]) if *hi != 0 => Some(((*hi as usize) << 8 | *lo as usize, rest)),
        _ => None,
    }
}

/// The canonically encoded RLP item at the start of `buf`, and what
/// follows it.
fn item(buf: &[u8]) -> Option<(Item<'_>, &[u8])> {
    let (&b, rest) = buf.split_first()?;
    let (list, len, rest) = match b {
        0x00..=0x7F => return Some((Item::Str(&buf[..1]), rest)),
        0x80..=0xB7 => (false, (b - 0x80) as usize, rest),
        0xB8..=0xBF => {
            let (len, rest) = long_len(b - 0xB7, rest)?;
            (false, len, rest)
        }
        0xC0..=0xF7 => (true, (b - 0xC0) as usize, rest),
        0xF8..=0xFF => {
            let (len, rest) = long_len(b - 0xF7, rest)?;
            (true, len, rest)
        }
    };
    let payload = rest.get(..len)?;
    let rest = &rest[len..];
    Some(if list {
        (Item::List(payload), rest)
    } else if len == 1 && payload[0] < 0x80 {
        return None; // a single byte below 0x80 must be encoded as itself
    } else {
        (Item::Str(payload), rest)
    })
}

struct Tx<'a> {
    nonce: &'a [u8],
    gas_price: &'a [u8],
    gas_limit: &'a [u8],
    to: &'a [u8],
    value: &'a [u8],
    data: &'a [u8],
    chain_id: &'a [u8],
}

/// An unsigned integer: big-endian, no leading zero, at most 256 bits.
fn scalar(s: &[u8]) -> Option<&[u8]> {
    (s.first() != Some(&0) && s.len() <= 32).then_some(s)
}

/// Decode an EIP-155 signing payload: one list of nine strings and
/// nothing after it, the last two empty.
fn decode(payload: &[u8]) -> Option<Tx<'_>> {
    let (Item::List(mut body), []) = item(payload)? else { return None };
    let mut f: [&[u8]; 9] = [&[]; 9];
    for slot in &mut f {
        let (Item::Str(s), rest) = item(body)? else { return None };
        *slot = s;
        body = rest;
    }
    if !body.is_empty() || f[3].len() != 20 || !f[7].is_empty() || !f[8].is_empty() {
        return None;
    }
    Some(Tx {
        nonce: scalar(f[0])?,
        gas_price: scalar(f[1])?,
        gas_limit: scalar(f[2])?,
        to: f[3],
        value: scalar(f[4])?,
        data: f[5],
        chain_id: scalar(f[6])?,
    })
}

/// The screen: seven fields, their text back to back in `buf`.
struct Screen<'a> {
    buf: &'a mut [u8],
    len: usize,
    ends: [usize; 7],
    fields: usize,
}

impl Screen<'_> {
    fn end_field(&mut self) {
        self.ends[self.fields] = self.len;
        self.fields += 1;
    }

    /// A big-endian integer in decimal.
    fn decimal(&mut self, be: &[u8]) {
        let mut n = [0u8; 32];
        let n = &mut n[..be.len()];
        n.copy_from_slice(be);
        let start = self.len;
        let mut first = 0;
        loop {
            while first < n.len() && n[first] == 0 {
                first += 1;
            }
            if first == n.len() {
                break;
            }
            let mut rem = 0u32;
            for b in &mut n[first..] {
                let x = rem << 8 | *b as u32;
                *b = (x / 10) as u8;
                rem = x % 10;
            }
            self.buf[self.len] = b'0' + rem as u8;
            self.len += 1;
        }
        if self.len == start {
            self.buf[self.len] = b'0';
            self.len += 1;
        }
        self.buf[start..self.len].reverse();
        self.end_field();
    }

    /// Bytes in lowercase hexadecimal.
    fn hex(&mut self, bytes: &[u8]) {
        const DIGITS: &[u8; 16] = b"0123456789abcdef";
        for &b in bytes {
            self.buf[self.len] = DIGITS[(b >> 4) as usize];
            self.buf[self.len + 1] = DIGITS[(b & 0xF) as usize];
            self.len += 2;
        }
        self.end_field();
    }
}

/// Decode `payload` and render its screen into `buf`. Returns the end of
/// each field; none if the payload is rejected.
fn run(payload: &[u8], buf: &mut [u8]) -> ([usize; 7], usize) {
    let mut screen = Screen { buf, len: 0, ends: [0; 7], fields: 0 };
    if let Some(tx) = decode(payload) {
        screen.decimal(tx.chain_id);
        screen.hex(tx.to);
        screen.decimal(tx.value);
        screen.decimal(tx.nonce);
        screen.decimal(tx.gas_price);
        screen.decimal(tx.gas_limit);
        screen.hex(tx.data);
    }
    (screen.ends, screen.fields)
}

/// Five integers of up to 78 digits, and every other byte of the payload
/// shown as two hex digits.
const SCREEN_MAX: usize = 5 * 78 + 2 * 512;

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut SCREEN: [u8; SCREEN_MAX] = [0; SCREEN_MAX];
    // SAFETY: only references to SAMPLES and SCREEN, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let screen = unsafe { &mut *(&raw mut SCREEN) };

    let mut s = Session::start(h, "w2_rlp", "R", samples, |r| r);
    for &n in vectors::CASES {
        let payload = vectors::payload(n);
        let (ends, fields) = run(payload, screen);
        // Each field's characters, then -1 as a field separator.
        let mut hash = Fnv1a::new();
        let mut start = 0;
        for &end in &ends[..fields] {
            for &c in &screen[start..end] {
                hash.int(c as i64);
            }
            hash.int(-1);
            start = end;
        }
        s.case(n, hash.finish(), || { black_box(run(black_box(payload), screen)); }, |r| r);
    }
    exit(true)
}
