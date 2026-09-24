//! W5 A/B firmware update, variant R. Also the oracle: its `out_hash`
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

const FACTORY_VERSION: u32 = 1;
const MODULUS: u32 = 65521;

const OK: u32 = 0;
const BUSY: u32 = 1;
const ROLLBACK: u32 = 2;
const UNEXPECTED: u32 = 3;
const BAD_IMAGE: u32 = 4;
const BAD_EVENT: u32 = 5;
const BOOTED: u32 = 8;

fn mix(acc: u32, x: u32) -> u32 {
    (acc * 31 + x) % MODULUS
}

#[derive(Clone, Copy)]
struct Slot {
    valid: bool,
    version: u32,
    chunks: u32,
    digest: u32,
}

impl Slot {
    const BLANK: Slot = Slot { valid: false, version: 0, chunks: 0, digest: 0 };
}

/// Persistent state. Every change goes through `write`, one atomic flash
/// write each; `budget` is how many more writes succeed before the power
/// is lost (fault injection).
struct Flash {
    slots: [Slot; 2],
    active: usize,
    trial: bool,
    booted_once: bool,
    counter: u32,
    budget: u32,
}

impl Flash {
    const fn factory() -> Self {
        let a = Slot { valid: true, version: FACTORY_VERSION, chunks: 0, digest: 0 };
        Flash {
            slots: [a, Slot::BLANK],
            active: 0,
            trial: false,
            booted_once: false,
            counter: FACTORY_VERSION,
            budget: u32::MAX,
        }
    }

    fn write(&mut self, w: impl FnOnce(&mut Self)) {
        if self.budget > 0 {
            self.budget -= 1;
            w(self);
        }
    }

    fn spare(&self) -> usize {
        1 - self.active
    }

    fn running(&self) -> u32 {
        self.slots[self.active].version
    }

    /// The bootloader: an image on trial is booted once, then reverted.
    /// Returns the version booted.
    fn boot(&mut self) -> u32 {
        if self.trial {
            if self.booted_once {
                self.write(|f| {
                    f.active = f.spare();
                    f.trial = false;
                    f.booted_once = false;
                });
            } else {
                self.write(|f| f.booted_once = true);
            }
        }
        self.running()
    }
}

struct Download {
    version: u32,
    size: u32,
    received: u32,
}

enum Cmd {
    Begin { version: u32, size: u32 },
    Chunk { digest: u32 },
    Finish { digest: u32 },
    Confirm,
    Reboot,
    Unknown,
}

struct Device {
    flash: Flash,
    download: Option<Download>,
}

impl Device {
    const fn new() -> Self {
        Device { flash: Flash::factory(), download: None }
    }

    fn reset(&mut self) {
        *self = Device::new();
    }

    fn command(&mut self, cmd: Cmd) -> u32 {
        let f = &mut self.flash;
        match cmd {
            Cmd::Begin { .. } if f.trial => BUSY,
            Cmd::Begin { version, .. } if version <= f.running() => ROLLBACK,
            Cmd::Begin { version, size } => {
                let spare = f.spare();
                f.write(|f| f.slots[spare] = Slot::BLANK);
                self.download = Some(Download { version, size, received: 0 });
                OK
            }
            Cmd::Chunk { digest } => match &mut self.download {
                Some(d) if !f.trial && d.received < d.size => {
                    let spare = f.spare();
                    f.write(|f| {
                        let s = &mut f.slots[spare];
                        s.valid = false;
                        s.chunks += 1;
                        s.digest = mix(s.digest, digest);
                    });
                    d.received += 1;
                    OK
                }
                _ => UNEXPECTED,
            },
            Cmd::Finish { digest } => match &self.download {
                Some(d) if !f.trial && d.received == d.size && d.version > f.running() => {
                    let (version, spare) = (d.version, f.spare());
                    self.download = None;
                    if f.slots[spare].digest != digest {
                        return BAD_IMAGE;
                    }
                    f.write(|f| {
                        f.slots[spare].valid = true;
                        f.slots[spare].version = version;
                    });
                    f.write(|f| {
                        f.active = spare;
                        f.trial = true;
                        f.booted_once = false;
                    });
                    OK
                }
                _ => UNEXPECTED,
            },
            Cmd::Confirm if f.trial && f.booted_once => {
                let version = f.running();
                f.write(|f| {
                    f.trial = false;
                    f.booted_once = false;
                });
                f.write(|f| f.counter = version);
                OK
            }
            Cmd::Confirm => UNEXPECTED,
            Cmd::Reboot => {
                self.download = None;
                BOOTED + f.boot()
            }
            Cmd::Unknown => BAD_EVENT,
        }
    }

    /// Runs `cmd` with the power lost after `writes` flash writes, then
    /// resets.
    fn cut(&mut self, writes: u32, cmd: Cmd) -> u32 {
        self.flash.budget = writes;
        self.command(cmd);
        self.flash.budget = u32::MAX;
        self.download = None;
        BOOTED + self.flash.boot()
    }
}

fn be_u16(b: &[u8]) -> u32 {
    u16::from_be_bytes([b[0], b[1]]) as u32
}

/// The command at the start of `input`, and its length.
fn parse_cmd(input: &[u8]) -> (Cmd, usize) {
    match input[0] {
        1 => (Cmd::Begin { version: be_u16(&input[1..]), size: input[3] as u32 }, 4),
        2 => {
            let n = input[1] as usize;
            let digest = input[2..2 + n].iter().fold(0, |d, &b| mix(d, b as u32));
            (Cmd::Chunk { digest }, 2 + n)
        }
        3 => (Cmd::Finish { digest: be_u16(&input[1..]) }, 3),
        4 => (Cmd::Confirm, 1),
        5 => (Cmd::Reboot, 1),
        _ => (Cmd::Unknown, 1),
    }
}

/// Handle the first `n` events of `input` from the factory state; the
/// answers go to `out`.
fn run(input: &[u8], n: usize, dev: &mut Device, out: &mut [u32]) {
    dev.reset();
    let mut pos = 0;
    for a in &mut out[..n] {
        *a = if input[pos] == 6 {
            let writes = input[pos + 1] as u32;
            let (cmd, len) = parse_cmd(&input[pos + 2..]);
            pos += 2 + len;
            dev.cut(writes, cmd)
        } else {
            let (cmd, len) = parse_cmd(&input[pos..]);
            pos += len;
            dev.command(cmd)
        };
    }
}

#[entry]
fn main() -> ! {
    let mut p = cortex_m::Peripherals::take().unwrap();
    let Some(out) = Stdout::new() else { exit(false) };
    let h = Harness::new(BoardCycles::new(config::DWT, &mut p), out);

    static mut SAMPLES: [u32; config::REPS] = [0; config::REPS];
    static mut DEVICE: Device = Device::new();
    static mut OUT: [u32; vectors::MAX_EVENTS] = [0; vectors::MAX_EVENTS];
    // SAFETY: only references to SAMPLES, DEVICE and OUT, taken once in `main`.
    let samples = unsafe { &mut *(&raw mut SAMPLES) };
    let dev = unsafe { &mut *(&raw mut DEVICE) };
    let answers = unsafe { &mut *(&raw mut OUT) };

    let mut s = Session::start(h, "w5_update", "R", samples, |r| r);
    for &n in vectors::CASES {
        let input = &vectors::STREAM[..];
        run(input, n as usize, dev, answers);
        let mut hash = Fnv1a::new();
        for &a in &answers[..n as usize] {
            hash.int(a as i64);
        }
        s.case(
            n,
            hash.finish(),
            || run(black_box(input), n as usize, dev, answers),
            |r| r,
        );
    }
    exit(true)
}
