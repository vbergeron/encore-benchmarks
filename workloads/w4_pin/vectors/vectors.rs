// W4 input vectors, shared by every variant through `include!`.
//
// The input is a stream of command APDUs, `INS Lc data(Lc)` (CLA, P1, P2
// left out). N = number of APDUs processed. The stream repeats a 16-APDU
// cycle that exercises every transition: wrong and right PIN, change,
// SELECT (logs out), PIN blocked, wrong and right PUK, unknown INS.
//
// Card at start: PIN 1234, PUK 12345678, 3 PIN tries, 10 PUK tries.

/// Size parameter of each case (APDUs), in increasing order.
pub const CASES: &[u32] = &[1, 10, 100, 1000];

const VERIFY: u8 = 0x20;
const CHANGE: u8 = 0x24;
const UNBLOCK: u8 = 0x2C;
const SELECT: u8 = 0xA4;
const READ_BINARY: u8 = 0xB0; // not implemented by the card: bad INS

/// One cycle; the card is back in its initial PIN state at its end. The
/// comment gives the expected response.
#[rustfmt::skip]
const CYCLE: &[u8] = &[
    VERIFY, 4, 0, 0, 0, 0,                          // wrong, 2 left
    VERIFY, 4, 1, 2, 3, 4,                          // ok
    CHANGE, 4, 9, 8, 7, 6,                          // ok, PIN 9876
    SELECT, 0,                                      // ok, logged out
    VERIFY, 4, 1, 2, 3, 4,                          // wrong, 2 left
    VERIFY, 4, 9, 8, 7, 6,                          // ok
    VERIFY, 4, 0, 0, 0, 0,                          // wrong, 2 left
    CHANGE, 4, 1, 2, 3, 4,                          // denied
    VERIFY, 4, 0, 0, 0, 0,                          // wrong, 1 left
    VERIFY, 4, 0, 0, 0, 0,                          // wrong, 0 left
    VERIFY, 4, 9, 8, 7, 6,                          // blocked
    UNBLOCK, 12, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, // wrong PUK, 9 left
    UNBLOCK, 12, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, // ok, PIN 1234
    VERIFY, 4, 1, 2, 3, 4,                          // ok
    CHANGE, 4, 1, 2, 3, 4,                          // ok
    READ_BINARY, 0,                                 // bad INS
];
const CYCLE_APDUS: usize = 16;

/// Largest N in `CASES`.
pub const MAX_APDUS: usize = 1000;

/// Byte length of the first `n` APDUs of the stream.
pub const fn stream_len(n: usize) -> usize {
    let (mut pos, mut i) = (0, 0);
    while i < n {
        pos += 2 + STREAM[pos + 1] as usize;
        i += 1;
    }
    pos
}

const STREAM_LEN: usize = {
    // Length of MAX_APDUS APDUs of the cycle, computed on CYCLE itself.
    let (mut len, mut pos, mut i) = (0, 0, 0);
    while i < MAX_APDUS {
        let lc = CYCLE[pos + 1] as usize;
        len += 2 + lc;
        pos += 2 + lc;
        i += 1;
        if i % CYCLE_APDUS == 0 {
            pos = 0;
        }
    }
    len
};

/// The whole stream, in flash.
pub static STREAM: [u8; STREAM_LEN] = {
    let mut s = [0u8; STREAM_LEN];
    let mut i = 0;
    while i < STREAM_LEN {
        s[i] = CYCLE[i % CYCLE.len()];
        i += 1;
    }
    s
};
