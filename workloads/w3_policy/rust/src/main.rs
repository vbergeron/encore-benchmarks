//! W3 BIP32 path policy and allow-list, variant R. Also the oracle: its
//! `out_hash` values are the reference every other variant must reproduce.

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

/// Deepest path a request may carry.
const MAX_DEPTH: usize = 16;
const ADDR_LEN: usize = 20;

/// Verdicts, best first.
const SIGN: u8 = 0;
const BAD_DEST: u8 = 1;
const OVER_LIMIT: u8 = 2;
const BAD_PATH: u8 = 3;

fn be_u32(b: &[u8]) -> u32 {
    u32::from_be_bytes(b[..4].try_into().unwrap())
}

fn be_u64(b: &[u8]) -> u64 {
    u64::from_be_bytes(b[..8].try_into().unwrap())
}

struct Request<'a> {
    depth: usize,
    path: [u32; MAX_DEPTH],
    amount: u64,
    dest: &'a [u8],
}

impl<'a> Request<'a> {
    /// The request at the start of `b`, and the bytes after it.
    fn parse(b: &'a [u8]) -> (Self, &'a [u8]) {
        let depth = b[0] as usize;
        let mut path = [0; MAX_DEPTH];
        for (i, c) in b[1..1 + 4 * depth].chunks_exact(4).enumerate() {
            path[i] = be_u32(c);
        }
        let rest = &b[1 + 4 * depth..];
        let req = Request { depth, path, amount: be_u64(rest), dest: &rest[8..8 + ADDR_LEN] };
        (req, &rest[8 + ADDR_LEN..])
    }
}

/// A rule, read in place from the policy bytes.
struct Rule<'a> {
    ranges: &'a [u8],
    limit: u64,
    dests: &'a [u8],
}

impl<'a> Rule<'a> {
    fn parse(b: &'a [u8]) -> (Self, &'a [u8]) {
        let depth = b[0] as usize;
        let ranges = &b[1..1 + 8 * depth];
        let rest = &b[1 + 8 * depth..];
        let limit = be_u64(rest);
        let k = rest[8] as usize;
        let dests = &rest[9..9 + k * ADDR_LEN];
        (Rule { ranges, limit, dests }, &rest[9 + k * ADDR_LEN..])
    }

    fn verdict(&self, req: &Request) -> u8 {
        let path = &req.path[..req.depth];
        let path_ok = self.ranges.len() == 8 * path.len()
            && self.ranges.chunks_exact(8).zip(path).all(|(r, &c)| {
                (be_u32(&r[..4])..=be_u32(&r[4..])).contains(&c)
            });
        if !path_ok {
            BAD_PATH
        } else if req.amount > self.limit {
            OVER_LIMIT
        } else if self.dests.chunks_exact(ADDR_LEN).any(|d| d == req.dest) {
            SIGN
        } else {
            BAD_DEST
        }
    }
}

/// Check every request of `input` against the first `n` rules of its
/// policy, one verdict per request into `out`. Returns the number of
/// verdicts.
fn run(input: &[u8], n: usize, out: &mut [u8]) -> usize {
    let count = input[0] as usize;
    let policy = &input[u16::from_be_bytes([input[1], input[2]]) as usize..];
    let mut rest = &input[3..];
    for v in out[..count].iter_mut() {
        let (req, next) = Request::parse(rest);
        rest = next;
        let mut best = BAD_PATH;
        let mut rules = policy;
        for _ in 0..n {
            let (rule, next) = Rule::parse(rules);
            rules = next;
            best = best.min(rule.verdict(&req));
            if best == SIGN {
                break;
            }
        }
        *v = best;
    }
    count
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut OUT: [u8; vectors::REQUESTS] = [0; vectors::REQUESTS];
    // SAFETY: only references to SAMPLES and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let verdicts = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w3_policy", "R", samples, |r| r);
    for &n in vectors::CASES {
        let input = &vectors::STREAM[..];
        let len = run(input, n as usize, verdicts);
        let mut hash = Fnv1a::new();
        for &v in &verdicts[..len] {
            hash.int(v as i64);
        }
        s.case(n, hash.finish(), || { black_box(run(black_box(input), n as usize, verdicts)); }, |r| r);
    }
    exit(true)
}
