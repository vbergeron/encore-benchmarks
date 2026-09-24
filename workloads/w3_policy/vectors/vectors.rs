// W3 input vectors, shared by every variant through `include!`.
//
// The input is one byte stream: a header `q off_hi off_lo` (number of
// requests, offset of the policy), the q signing requests, then the policy.
//   request: d, d BIP32 indices (4 bytes, big-endian), amount (8 bytes,
//            big-endian), destination (20 bytes)
//   rule:    d, d ranges (low then high index, 4 bytes each), limit
//            (8 bytes), k, k allowed destinations (20 bytes each)
// N = number of rules of the policy the requests are checked against (the
// first N of the stream). The requests are the same for every N.
//
// Verdicts: 0 sign, 1 destination not allowed, 2 amount over the limit,
// 3 path not allowed (from the rule that came closest).

/// Size parameter of each case (rules), in increasing order.
pub const CASES: &[u32] = &[1, 4, 16, 64];

/// Rules in the stream (largest N).
pub const MAX_RULES: usize = 64;

/// Number of requests.
pub const REQUESTS: usize = 16;

/// Hardened BIP32 index.
const H: u32 = 0x8000_0000;
const PURPOSE: u32 = 44 | H;

// Rule i: m / 44' / (i/2)' / [0' ..= (i%4)'] ( / [0 ..= 1] ( / [0 ..= 20 + 3i] ) ),
// of depth 3, 4 or 5, a limit of (i + 1) * 10^11 and 1 to 3 destinations.
// Two consecutive rules share a coin type, so a request can match the path
// of several rules and be refused by one and signed by the other.

const fn rule_depth(i: usize) -> usize {
    3 + i % 3
}

const fn rule_range(i: usize, level: usize) -> (u32, u32) {
    match level {
        0 => (PURPOSE, PURPOSE),
        1 => ((i / 2) as u32 | H, (i / 2) as u32 | H),
        2 => (H, (i % 4) as u32 | H),
        3 => (0, 1),
        _ => (0, 20 + 3 * i as u32),
    }
}

const fn rule_limit(i: usize) -> u64 {
    (i as u64 + 1) * 100_000_000_000
}

const fn rule_dests(i: usize) -> usize {
    1 + i % 3
}

/// Destination `j` of rule `i` (rule `i` allows `j < rule_dests(i)`).
const fn addr(i: usize, j: usize) -> [u8; 20] {
    let mut a = [0u8; 20];
    let mut t = 0;
    while t < 20 {
        a[t] = ((i * 31 + j * 7 + t * 13) & 0xFF) as u8;
        t += 1;
    }
    a
}

#[derive(Clone, Copy)]
enum Kind {
    /// Upper edge of every range, amount equal to the limit, last allowed
    /// destination: allowed by the target rule.
    Ok,
    /// One over the limit.
    Over,
    /// A destination no rule of that coin allows.
    Dest,
    /// Last index one past the top of its range.
    Path,
    /// One level deeper than the rule.
    Deeper,
    /// Account index not hardened.
    Unhardened,
}

/// The requests, as (target rule, kind).
const REQS: [(usize, Kind); REQUESTS] = [
    (0, Kind::Ok),
    (1, Kind::Over),
    (3, Kind::Dest),
    (3, Kind::Ok),
    (6, Kind::Path),
    (10, Kind::Ok),
    (15, Kind::Unhardened),
    (15, Kind::Ok),
    (22, Kind::Over),
    (31, Kind::Ok),
    (31, Kind::Deeper),
    (40, Kind::Dest),
    (50, Kind::Ok),
    (63, Kind::Ok),
    (63, Kind::Over),
    (7, Kind::Path),
];

const CAP: usize = 8192;

struct Buf {
    b: [u8; CAP],
    len: usize,
}

impl Buf {
    const fn byte(mut self, v: u8) -> Self {
        self.b[self.len] = v;
        self.len += 1;
        self
    }

    const fn be(mut self, v: u64, n: usize) -> Self {
        let mut k = n;
        while k > 0 {
            k -= 1;
            self = self.byte((v >> (8 * k)) as u8);
        }
        self
    }

    const fn addr(mut self, a: [u8; 20]) -> Self {
        let mut t = 0;
        while t < 20 {
            self = self.byte(a[t]);
            t += 1;
        }
        self
    }
}

const fn request(mut buf: Buf, rule: usize, kind: Kind) -> Buf {
    let d = rule_depth(rule);
    let depth = if let Kind::Deeper = kind { d + 1 } else { d };
    buf = buf.byte(depth as u8);
    let mut level = 0;
    while level < depth {
        let mut index = if level < d { rule_range(rule, level).1 } else { 0 };
        if let Kind::Path = kind {
            if level == d - 1 {
                index += 1;
            }
        }
        if let Kind::Unhardened = kind {
            if level == 2 {
                index &= !H;
            }
        }
        buf = buf.be(index as u64, 4);
        level += 1;
    }
    let amount = match kind {
        Kind::Ok => rule_limit(rule),
        Kind::Over => rule_limit(rule) + 1,
        _ => rule_limit(rule) / 2,
    };
    buf = buf.be(amount, 8);
    let dest = match kind {
        Kind::Dest => addr(rule, 3),
        _ => addr(rule, rule_dests(rule) - 1),
    };
    buf.addr(dest)
}

const fn rule(mut buf: Buf, i: usize) -> Buf {
    let d = rule_depth(i);
    buf = buf.byte(d as u8);
    let mut level = 0;
    while level < d {
        let (lo, hi) = rule_range(i, level);
        buf = buf.be(lo as u64, 4).be(hi as u64, 4);
        level += 1;
    }
    buf = buf.be(rule_limit(i), 8).byte(rule_dests(i) as u8);
    let mut j = 0;
    while j < rule_dests(i) {
        buf = buf.addr(addr(i, j));
        j += 1;
    }
    buf
}

const BUILT: Buf = {
    let mut buf = Buf { b: [0; CAP], len: 0 };
    buf = buf.byte(REQUESTS as u8).be(0, 2);
    let mut r = 0;
    while r < REQUESTS {
        buf = request(buf, REQS[r].0, REQS[r].1);
        r += 1;
    }
    let off = buf.len;
    buf.b[1] = (off >> 8) as u8;
    buf.b[2] = off as u8;
    let mut i = 0;
    while i < MAX_RULES {
        buf = rule(buf, i);
        i += 1;
    }
    buf
};

const STREAM_LEN: usize = BUILT.len;

/// The whole stream, in flash.
pub static STREAM: [u8; STREAM_LEN] = {
    let mut s = [0u8; STREAM_LEN];
    let mut i = 0;
    while i < STREAM_LEN {
        s[i] = BUILT.b[i];
        i += 1;
    }
    s
};
