//! W1 APDU and BER-TLV parser, variant R. Also the oracle: its `out_hash`
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

/// Why a command is rejected; the output is then the code alone.
#[derive(Clone, Copy)]
enum Reject {
    /// Malformed APDU (Lc of 0, data shorter than Lc, bytes after Le).
    Apdu = 1,
    /// Malformed BER-TLV in the data field.
    Tlv = 2,
}

/// Summary sink: three words per TLV node, pre-order.
struct Out<'a> {
    buf: &'a mut [u32],
    len: usize,
}

impl Out<'_> {
    fn push(&mut self, v: u32) -> usize {
        self.buf[self.len] = v;
        self.len += 1;
        self.len - 1
    }
}

/// One tag of one or two bytes. Returns the tag number and its size.
fn tag(buf: &[u8]) -> Option<(u32, usize)> {
    match *buf {
        [b, c, ..] if b & 0x1F == 0x1F => (c < 0x80).then_some(((b as u32) << 8 | c as u32, 2)),
        [b, ..] if b & 0x1F == 0x1F => None,
        [b, ..] => Some((b as u32, 1)),
        [] => None,
    }
}

/// A definite length in its shortest form. Returns the length and its
/// size.
fn length(buf: &[u8]) -> Option<(usize, usize)> {
    match *buf {
        [n, ..] if n < 0x80 => Some((n as usize, 1)),
        [0x81, n, ..] if n >= 0x80 => Some((n as usize, 2)),
        [0x82, hi, lo, ..] if hi != 0 => Some(((hi as usize) << 8 | lo as usize, 3)),
        _ => None,
    }
}

/// Parse the TLVs of `buf` at `depth` into `out`: tag, depth, then the
/// value length (primitive) or the number of children (constructed).
/// Returns the number of TLVs.
fn tlvs(mut buf: &[u8], depth: u32, out: &mut Out) -> Option<u32> {
    let mut count = 0;
    while !buf.is_empty() {
        let (t, tn) = tag(buf)?;
        let (len, ln) = length(&buf[tn..])?;
        let value = buf.get(tn + ln..tn + ln + len)?;
        out.push(t);
        out.push(depth);
        let slot = out.push(0);
        let first = if t > 0xFF { t >> 8 } else { t };
        out.buf[slot] = if first & 0x20 != 0 { tlvs(value, depth + 1, out)? } else { len as u32 };
        buf = &buf[tn + ln + len..];
        count += 1;
    }
    Some(count)
}

/// Parse a command APDU, then the BER-TLV structure of its data field.
/// Returns the output length: `[0, INS, summary...]` or a reject code.
fn run(cmd: &[u8], out: &mut [u32]) -> usize {
    let reject = |out: &mut [u32], r: Reject| {
        out[0] = r as u32;
        1
    };
    let [_cla, ins, _p1, _p2, body @ ..] = cmd else { return reject(out, Reject::Apdu) };
    let data: &[u8] = match *body {
        [] | [_] => &[],
        [lc, ref rest @ ..] => {
            let lc = lc as usize;
            if lc == 0 || rest.len() < lc || rest.len() > lc + 1 {
                return reject(out, Reject::Apdu);
            }
            &rest[..lc]
        }
    };
    let mut sink = Out { buf: out, len: 2 };
    if tlvs(data, 0, &mut sink).is_none() {
        return reject(out, Reject::Tlv);
    }
    let len = sink.len;
    out[0] = 0;
    out[1] = *ins as u32;
    len
}

/// Three words per TLV node, and at least two bytes per node.
const OUT_MAX: usize = 2 + 3 * (vectors::MAX_APDU / 2);

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut OUT: [u32; OUT_MAX] = [0; OUT_MAX];
    // SAFETY: only references to SAMPLES and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let summary = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w1_apdu", "R", samples, |r| r);
    for &n in vectors::CASES {
        let cmd = vectors::apdu(n);
        let len = run(cmd, summary);
        let mut hash = Fnv1a::new();
        for &v in &summary[..len] {
            hash.int(v as i64);
        }
        s.case(n, hash.finish(), || { black_box(run(black_box(cmd), summary)); }, |r| r);
    }
    exit(true)
}
