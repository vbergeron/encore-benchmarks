// W6 input vectors, shared by every variant through `include!`.
//
// N = frame size in bytes; the frame of size N is the first N bytes of
// FRAME. Bytes are pseudo-random with about one zero in 16, except for a
// run of 300 non-zero bytes from offset 600, so that the 1024-byte frame
// exercises the 254-byte block limit (code 0xFF).

/// Size parameter of each case (frame bytes), in increasing order.
pub const CASES: &[u32] = &[16, 64, 256, 1024];

/// Largest N in `CASES`.
pub const MAX_FRAME: usize = 1024;

/// Worst-case COBS encoding of `n` bytes: one code byte per 254 bytes,
/// plus one.
pub const fn max_encoded(n: usize) -> usize {
    n + n / 254 + 1
}

/// The frame, in flash.
pub static FRAME: [u8; MAX_FRAME] = {
    let mut f = [0u8; MAX_FRAME];
    let mut x: u32 = 0x2545_f491;
    let mut i = 0;
    while i < MAX_FRAME {
        // xorshift32
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        let b = (x >> 8) as u8;
        let long_run = i >= 600 && i < 900;
        f[i] = if long_run {
            b | 1
        } else if x & 0xF == 0 {
            0
        } else {
            b
        };
        i += 1;
    }
    f
};
