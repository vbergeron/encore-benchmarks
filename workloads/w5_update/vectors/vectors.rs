// W5 input vectors, shared by every variant through `include!`.
//
// The input is a stream of update events. N = number of events handled,
// from the factory state: version 1 in slot A (active, confirmed,
// anti-rollback counter 1), slot B blank, no download in progress.
//
// Commands (versions and digests are 2 bytes, big-endian):
//
//   1 v(2) size    BEGIN: download version v, `size` chunks, into the spare
//                  slot. Busy (1) if an image is on trial; rollback (2) if
//                  v is not above the running version; otherwise erase the
//                  spare slot, ok (0).
//   2 n data(n)    CHUNK: program the next chunk into the spare slot, ok;
//                  unexpected (3) with no download or all chunks received.
//   3 digest(2)    FINISH: unexpected unless all chunks are received, no
//                  image is on trial and v is still above the running
//                  version. Otherwise the download ends: if the digest
//                  read back from the spare slot matches, seal the slot
//                  with v and boot it next on trial, ok; else bad image (4).
//   4              CONFIRM: the image on trial, once booted, confirms
//                  itself: clear the trial, raise the anti-rollback
//                  counter to its version, ok. Unexpected otherwise.
//   5              REBOOT: the download is lost; the bootloader boots an
//                  image on trial once, and reverts to the other slot if
//                  it is still on trial at the next reset. Answer: 8 + the
//                  booted version.
//   other          one byte, bad event (5).
//
//   6 i cmd        CUT: power is lost after the first i flash writes of
//                  cmd, then the device resets (as REBOOT). One event, one
//                  answer: 8 + the booted version.
//
// The flash writes of each command, in order: BEGIN erases; CHUNK
// programs; FINISH seals then switches the boot slot; CONFIRM clears the
// trial then raises the counter; a reset marks the trial booted, or
// reverts. The digest of a chunk is `d = fold(mix, 0, bytes)` and a slot
// keeps `sum = mix(sum, d)` over its chunks since its erase (0), where
// `mix(acc, x) = (31 acc + x) mod 65521`.
//
// The stream repeats a 40-event cycle that goes through every command and
// answer, and cuts the power between the writes of FINISH and of CONFIRM,
// as well as before or after the single write of other commands. Each
// cycle installs the next version: cycle c starts with version a = c + 1
// running, and ends with a + 1 running. Every other cycle confirms it
// fully, the others are cut after the trial is cleared, which leaves the
// counter behind.

/// Size parameter of each case (events), in increasing order.
pub const CASES: &[u32] = &[10, 100, 1000];

/// Largest N in `CASES`.
pub const MAX_EVENTS: usize = 1000;

const BEGIN: u8 = 1;
const CHUNK: u8 = 2;
const FINISH: u8 = 3;
const CONFIRM: u8 = 4;
const REBOOT: u8 = 5;
const CUT: u8 = 6;
const UNKNOWN: u8 = 0xB0;

/// Chunks per image, and bytes per chunk.
const CHUNKS: usize = 4;
const CHUNK_LEN: usize = 16;

#[derive(Clone, Copy)]
enum Op {
    /// BEGIN with the running version plus this offset.
    Begin(u8),
    /// CHUNK k of the cycle's image.
    Chunk(u8),
    /// FINISH with the right digest (true) or a wrong one.
    Finish(bool),
    Confirm,
    Reboot,
    Unknown,
}

/// No power cut before the op.
const NONE: u8 = 0xFF;
/// Cut after 1 write on odd cycles, no cut on even ones.
const ODD: u8 = 0xFE;

/// One cycle: power cut (or NONE), op. The comment gives the answer, with
/// `a` the running version at the start of the cycle and `v = a + 1`.
#[rustfmt::skip]
const CYCLE: &[(u8, Op)] = &[
    (NONE, Op::Begin(0)),     // rollback
    (NONE, Op::Begin(1)),     // ok, erase
    (NONE, Op::Chunk(0)),     // ok
    (NONE, Op::Chunk(1)),     // ok
    (0,    Op::Chunk(2)),     // cut before programming: booted a
    (NONE, Op::Chunk(2)),     // unexpected, the download was lost
    (1,    Op::Begin(1)),     // cut after the erase: booted a
    (NONE, Op::Begin(1)),     // ok
    (NONE, Op::Chunk(0)),     // ok
    (NONE, Op::Chunk(1)),     // ok
    (NONE, Op::Chunk(2)),     // ok
    (NONE, Op::Chunk(3)),     // ok
    (NONE, Op::Chunk(0)),     // unexpected, all chunks received
    (NONE, Op::Finish(false)),// bad image
    (NONE, Op::Begin(1)),     // ok
    (NONE, Op::Chunk(0)),     // ok
    (NONE, Op::Chunk(1)),     // ok
    (NONE, Op::Chunk(2)),     // ok
    (NONE, Op::Chunk(3)),     // ok
    (1,    Op::Finish(true)), // cut after the seal, before the switch: booted a
    (NONE, Op::Begin(1)),     // ok
    (NONE, Op::Chunk(0)),     // ok
    (NONE, Op::Chunk(1)),     // ok
    (NONE, Op::Chunk(2)),     // ok
    (NONE, Op::Chunk(3)),     // ok
    (NONE, Op::Finish(true)), // ok, v on trial
    (NONE, Op::Begin(2)),     // busy
    (NONE, Op::Confirm),      // unexpected, not booted yet
    (NONE, Op::Reboot),       // booted v, on trial
    (NONE, Op::Reboot),       // not confirmed: reverted, booted a
    (NONE, Op::Confirm),      // unexpected
    (NONE, Op::Begin(1)),     // ok
    (NONE, Op::Chunk(0)),     // ok
    (NONE, Op::Chunk(1)),     // ok
    (NONE, Op::Chunk(2)),     // ok
    (NONE, Op::Chunk(3)),     // ok
    (NONE, Op::Finish(true)), // ok, v on trial
    (0,    Op::Reboot),       // cut at once, still reset: booted v, on trial
    (ODD,  Op::Confirm),      // ok (even cycle); cut after clearing the trial: booted v (odd)
    (NONE, Op::Unknown),      // bad event
];

/// Cycles in the stream: enough for MAX_EVENTS events.
const CYCLES: usize = MAX_EVENTS.div_ceil(CYCLE.len());

const fn mix(acc: u32, x: u32) -> u32 {
    (acc * 31 + x) % 65521
}

/// Byte j of chunk k of the image of cycle c.
const fn image_byte(c: usize, k: usize, j: usize) -> u8 {
    let x = ((c * CHUNKS + k) * CHUNK_LEN + j) as u32;
    (x.wrapping_mul(2654435761) >> 24) as u8
}

const fn chunk_digest(c: usize, k: usize) -> u32 {
    let (mut d, mut j) = (0, 0);
    while j < CHUNK_LEN {
        d = mix(d, image_byte(c, k, j) as u32);
        j += 1;
    }
    d
}

const fn image_digest(c: usize) -> u32 {
    let (mut s, mut k) = (0, 0);
    while k < CHUNKS {
        s = mix(s, chunk_digest(c, k));
        k += 1;
    }
    s
}

const fn cut_of(c: usize, cut: u8) -> u8 {
    if cut == ODD { if c % 2 == 1 { 1 } else { NONE } } else { cut }
}

const fn op_len(op: Op) -> usize {
    match op {
        Op::Begin(_) => 4,
        Op::Chunk(_) => 2 + CHUNK_LEN,
        Op::Finish(_) => 3,
        Op::Confirm | Op::Reboot | Op::Unknown => 1,
    }
}

const STREAM_LEN: usize = {
    let (mut len, mut c) = (0, 0);
    while c < CYCLES {
        let mut e = 0;
        while e < CYCLE.len() {
            let (cut, op) = CYCLE[e];
            if cut_of(c, cut) != NONE {
                len += 2;
            }
            len += op_len(op);
            e += 1;
        }
        c += 1;
    }
    len
};

/// The whole stream, in flash.
pub static STREAM: [u8; STREAM_LEN] = {
    let mut s = [0u8; STREAM_LEN];
    let (mut at, mut c) = (0, 0);
    while c < CYCLES {
        let running = (c + 1) as u32;
        let mut e = 0;
        while e < CYCLE.len() {
            let (cut, op) = CYCLE[e];
            let cut = cut_of(c, cut);
            if cut != NONE {
                s[at] = CUT;
                s[at + 1] = cut;
                at += 2;
            }
            match op {
                Op::Begin(off) => {
                    let v = running + off as u32;
                    s[at] = BEGIN;
                    s[at + 1] = (v >> 8) as u8;
                    s[at + 2] = v as u8;
                    s[at + 3] = CHUNKS as u8;
                }
                Op::Chunk(k) => {
                    s[at] = CHUNK;
                    s[at + 1] = CHUNK_LEN as u8;
                    let mut j = 0;
                    while j < CHUNK_LEN {
                        s[at + 2 + j] = image_byte(c, k as usize, j);
                        j += 1;
                    }
                }
                Op::Finish(good) => {
                    let d = image_digest(c);
                    let d = if good { d } else { (d + 1) % 65521 };
                    s[at] = FINISH;
                    s[at + 1] = (d >> 8) as u8;
                    s[at + 2] = d as u8;
                }
                Op::Confirm => s[at] = CONFIRM,
                Op::Reboot => s[at] = REBOOT,
                Op::Unknown => s[at] = UNKNOWN,
            }
            at += op_len(op);
            e += 1;
        }
        c += 1;
    }
    s
};
