// W7 input vectors, shared by every variant through `include!`.
//
// The input is one byte stream: `q`, the q credential handles to assert
// (2 bytes each, big-endian), then the registrations: a credential handle
// then its signature counter, 2 bytes each, big-endian.
// N = number of registrations loaded into an empty store before the
// assertions (the first N of the stream). The assertions are the same for
// every N.
//
// Answer to an assertion: 0 if the credential is unknown, otherwise its
// new counter (the stored counter plus one), which the store keeps.

/// Size parameter of each case (registrations), in increasing order.
pub const CASES: &[u32] = &[10, 50, 100, 500];

/// Registrations in the stream (largest N).
pub const MAX_REGS: usize = 500;

/// Number of assertions.
pub const ASSERTS: usize = 32;

// Handle of registration j: odd, pseudo-random and distinct (40503 is odd,
// so j -> 40503 j + 12345 is a bijection modulo 2^15), except that every
// 50th registration re-registers the handle of 7 registrations earlier,
// which replaces its counter.
const fn fresh_handle(j: usize) -> u16 {
    (((j * 40503 + 12345) % 32768) * 2 + 1) as u16
}

const fn reg_handle(j: usize) -> u16 {
    if j % 50 == 49 { fresh_handle(j - 7) } else { fresh_handle(j) }
}

const fn reg_counter(j: usize) -> u16 {
    ((j * 7919 + 17) % 60000) as u16
}

// Assertion i, by i mod 4: a registration spread over the whole stream (so
// that more of them hit as N grows), an even handle (never registered), the
// handle of assertion i - 2 again (its counter goes up twice), a
// registration among the first hundred. Assertion 15 targets a
// re-registered handle.
const fn assert_handle(i: usize) -> u16 {
    match i % 4 {
        0 => reg_handle((i * 37 + 5) % MAX_REGS),
        1 => (((i * 977 + 3) % 32768) * 2) as u16,
        2 => assert_handle(i - 2),
        _ => if i == 15 { reg_handle(49) } else { reg_handle(i * 3) },
    }
}

const STREAM_LEN: usize = 1 + 2 * ASSERTS + 4 * MAX_REGS;

/// The whole stream, in flash.
pub static STREAM: [u8; STREAM_LEN] = {
    let mut s = [0u8; STREAM_LEN];
    s[0] = ASSERTS as u8;
    let mut i = 0;
    while i < ASSERTS {
        let h = assert_handle(i);
        s[1 + 2 * i] = (h >> 8) as u8;
        s[2 + 2 * i] = h as u8;
        i += 1;
    }
    let mut j = 0;
    while j < MAX_REGS {
        let at = 1 + 2 * ASSERTS + 4 * j;
        let (h, c) = (reg_handle(j), reg_counter(j));
        s[at] = (h >> 8) as u8;
        s[at + 1] = h as u8;
        s[at + 2] = (c >> 8) as u8;
        s[at + 3] = c as u8;
        j += 1;
    }
    s
};
