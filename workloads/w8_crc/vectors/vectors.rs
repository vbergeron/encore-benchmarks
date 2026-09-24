// W8 input vectors, shared by every variant through `include!`.
//
// N = block size in bytes; the block of size N is the first N bytes of
// BLOCK, pseudo-random bytes. Each run computes the CRC-16/MODBUS and the
// CRC-32/ISO-HDLC of the block.

/// Size parameter of each case (block bytes), in increasing order.
pub const CASES: &[u32] = &[16, 64, 256, 1024];

/// Largest N in `CASES`.
pub const MAX_BLOCK: usize = 1024;

/// The block, in flash.
pub static BLOCK: [u8; MAX_BLOCK] = {
    let mut f = [0u8; MAX_BLOCK];
    let mut x: u32 = 0x6b8b_4567;
    let mut i = 0;
    while i < MAX_BLOCK {
        // xorshift32
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        f[i] = (x >> 8) as u8;
        i += 1;
    }
    f
};
