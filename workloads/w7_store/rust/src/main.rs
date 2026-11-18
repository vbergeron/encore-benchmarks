//! W7 FIDO credential store, variant R. Also the oracle: its `out_hash`
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

/// Credentials the store can hold.
const CAPACITY: usize = vectors::MAX_REGS;

/// No node: the null link of the tree.
const NIL: u16 = u16::MAX;

/// Resident credentials in a red-black tree keyed by handle, with their
/// signature counters: the same structure as the Gallina store, kept in
/// place in static arrays (nodes are indices, no allocator), so lookups
/// and insertions are O(log n).
struct Store {
    handles: [u16; CAPACITY],
    counters: [u32; CAPACITY],
    left: [u16; CAPACITY],
    right: [u16; CAPACITY],
    parent: [u16; CAPACITY],
    red: [bool; CAPACITY],
    root: u16,
    len: usize,
}

impl Store {
    const fn new() -> Self {
        Store {
            handles: [0; CAPACITY],
            counters: [0; CAPACITY],
            left: [NIL; CAPACITY],
            right: [NIL; CAPACITY],
            parent: [NIL; CAPACITY],
            red: [false; CAPACITY],
            root: NIL,
            len: 0,
        }
    }

    fn clear(&mut self) {
        self.root = NIL;
        self.len = 0;
    }

    /// The node holding `handle`, or NIL.
    fn find(&self, handle: u16) -> u16 {
        let mut x = self.root;
        while x != NIL {
            let k = self.handles[x as usize];
            if handle == k {
                return x;
            }
            x = if handle < k { self.left[x as usize] } else { self.right[x as usize] };
        }
        NIL
    }

    /// Stores `handle` with `counter`, replacing its counter if it is
    /// already there.
    fn register(&mut self, handle: u16, counter: u32) {
        // Descend to the leaf position, or to the node already there.
        let mut p = NIL;
        let mut x = self.root;
        while x != NIL {
            let k = self.handles[x as usize];
            if handle == k {
                self.counters[x as usize] = counter;
                return;
            }
            p = x;
            x = if handle < k { self.left[x as usize] } else { self.right[x as usize] };
        }
        let z = self.len as u16;
        self.len += 1;
        let zi = z as usize;
        self.handles[zi] = handle;
        self.counters[zi] = counter;
        self.left[zi] = NIL;
        self.right[zi] = NIL;
        self.parent[zi] = p;
        self.red[zi] = true;
        if p == NIL {
            self.root = z;
        } else if handle < self.handles[p as usize] {
            self.left[p as usize] = z;
        } else {
            self.right[p as usize] = z;
        }
        self.fix_insert(z);
    }

    /// Bumps the counter of `handle`: its new value, or 0 if unknown.
    fn assert(&mut self, handle: u16) -> u32 {
        let x = self.find(handle);
        if x == NIL {
            return 0;
        }
        self.counters[x as usize] += 1;
        self.counters[x as usize]
    }

    fn is_red(&self, x: u16) -> bool {
        x != NIL && self.red[x as usize]
    }

    /// Restores the red-black invariants after inserting the red node `z`.
    fn fix_insert(&mut self, mut z: u16) {
        while self.is_red(self.parent[z as usize]) {
            let p = self.parent[z as usize];
            let g = self.parent[p as usize];
            if p == self.left[g as usize] {
                let u = self.right[g as usize];
                if self.is_red(u) {
                    self.red[p as usize] = false;
                    self.red[u as usize] = false;
                    self.red[g as usize] = true;
                    z = g;
                } else {
                    if z == self.right[p as usize] {
                        z = p;
                        self.rotate_left(z);
                    }
                    let p = self.parent[z as usize];
                    let g = self.parent[p as usize];
                    self.red[p as usize] = false;
                    self.red[g as usize] = true;
                    self.rotate_right(g);
                }
            } else {
                let u = self.left[g as usize];
                if self.is_red(u) {
                    self.red[p as usize] = false;
                    self.red[u as usize] = false;
                    self.red[g as usize] = true;
                    z = g;
                } else {
                    if z == self.left[p as usize] {
                        z = p;
                        self.rotate_right(z);
                    }
                    let p = self.parent[z as usize];
                    let g = self.parent[p as usize];
                    self.red[p as usize] = false;
                    self.red[g as usize] = true;
                    self.rotate_left(g);
                }
            }
        }
        let r = self.root;
        self.red[r as usize] = false;
    }

    /// Makes the right child of `x` its parent.
    fn rotate_left(&mut self, x: u16) {
        let y = self.right[x as usize];
        let b = self.left[y as usize];
        self.right[x as usize] = b;
        if b != NIL {
            self.parent[b as usize] = x;
        }
        self.replace_child(x, y);
        self.left[y as usize] = x;
        self.parent[x as usize] = y;
    }

    /// Makes the left child of `x` its parent.
    fn rotate_right(&mut self, x: u16) {
        let y = self.left[x as usize];
        let b = self.right[y as usize];
        self.left[x as usize] = b;
        if b != NIL {
            self.parent[b as usize] = x;
        }
        self.replace_child(x, y);
        self.right[y as usize] = x;
        self.parent[x as usize] = y;
    }

    /// Puts `y` where `x` hangs from its parent (or at the root).
    fn replace_child(&mut self, x: u16, y: u16) {
        let p = self.parent[x as usize];
        self.parent[y as usize] = p;
        if p == NIL {
            self.root = y;
        } else if self.left[p as usize] == x {
            self.left[p as usize] = y;
        } else {
            self.right[p as usize] = y;
        }
    }
}

fn be_u16(b: &[u8]) -> u16 {
    u16::from_be_bytes([b[0], b[1]])
}

/// Register the first `n` credentials of `input` in an empty store, then
/// answer its assertions into `out`. Returns the number of answers.
fn run(input: &[u8], n: usize, store: &mut Store, out: &mut [u32]) -> usize {
    let q = input[0] as usize;
    let (asserts, regs) = input[1..].split_at(2 * q);
    store.clear();
    for reg in regs.chunks_exact(4).take(n) {
        store.register(be_u16(reg), be_u16(&reg[2..]) as u32);
    }
    for (a, handle) in out.iter_mut().zip(asserts.chunks_exact(2)) {
        *a = store.assert(be_u16(handle));
    }
    q
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut STORE: Store = Store::new();
    static mut OUT: [u32; vectors::ASSERTS] = [0; vectors::ASSERTS];
    // SAFETY: only references to SAMPLES, STORE and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let store = unsafe { &mut *(&raw mut STORE) };
    let answers = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w7_store", "R", samples, |r| r);
    for &n in vectors::CASES {
        let input = &vectors::STREAM[..];
        let len = run(input, n as usize, store, answers);
        let mut hash = Fnv1a::new();
        for &a in &answers[..len] {
            hash.int(a as i64);
        }
        s.case(
            n,
            hash.finish(),
            || { black_box(run(black_box(input), n as usize, store, answers)); },
            |r| r,
        );
    }
    exit(true)
}
