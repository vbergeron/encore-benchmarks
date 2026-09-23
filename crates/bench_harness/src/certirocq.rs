//! Calling a CertiRocq-generated C program and reading its result.
//!
//! CertiRocq lays values out like OCaml: an odd word is an integer
//! (`n << 1 | 1`), also used for constructors without arguments (their
//! index among the nullary constructors); an even word points to a block
//! whose header, one word before, holds the tag (index among the
//! constructors with arguments) and whose fields follow. `nat` is mapped
//! to integers (certirocq/theories/BenchNat.v), so a `nat` is an integer
//! word.
//!
//! The C side is `certirocq/runtime/bench_rt.c`: every run starts on a
//! fresh arena, and a result stays valid until the next run.

/// A CertiRocq value (one machine word).
pub type Value = usize;

/// The program's top level, `body` in the generated C: it evaluates the
/// definitions and returns the entry point's closure.
pub type Body = unsafe extern "C" fn(*mut core::ffi::c_void) -> Value;

unsafe extern "C" {
    fn bench_rt_run(body: Body, arg: Value, out: *mut Value) -> i32;
    fn bench_rt_set_input(data: *const u8, len: u32);
    fn bench_rt_arena_peak() -> u32;
    fn bench_rt_last_error() -> i32;
}

pub const fn int(n: isize) -> Value {
    ((n << 1) | 1) as Value
}

pub const fn is_int(v: Value) -> bool {
    v & 1 == 1
}

pub const fn int_val(v: Value) -> isize {
    (v as isize) >> 1
}

/// Constructor tag of a block.
///
/// # Safety
/// `v` must be a block of the result of the latest run.
pub unsafe fn tag(v: Value) -> u8 {
    unsafe { *(v as *const Value).sub(1) as u8 }
}

/// Field `i` of a block.
///
/// # Safety
/// `v` must be a block of the result of the latest run with more than `i`
/// fields.
pub unsafe fn field(v: Value, i: usize) -> Value {
    unsafe { *(v as *const Value).add(i) }
}

/// The input buffer that `input_byte` (theories/EncoreInput.v) reads.
pub fn set_input(data: &'static [u8]) {
    unsafe { bench_rt_set_input(data.as_ptr(), data.len() as u32) }
}

/// Apply the entry point of `body` to `arg` on a fresh heap. On failure,
/// the reason: the runtime aborted (arena exhausted, input index out of
/// range) or the C stack ran out.
pub fn run(body: Body, arg: Value) -> Result<Value, &'static str> {
    let mut out = 0;
    if unsafe { bench_rt_run(body, arg, &mut out) } != 0 {
        return Ok(out);
    }
    Err(match unsafe { bench_rt_last_error() } {
        2 => "C stack exhausted",
        _ => "runtime abort (arena exhausted)",
    })
}

/// Arena high-water mark of the latest run, in bytes.
pub fn arena_peak() -> u32 {
    unsafe { bench_rt_arena_peak() }
}

/// The elements of a Gallina `list`: `nil` is the integer 0, `cons` the
/// block of tag 0 with the head and the tail.
///
/// # Safety
/// `v` must be a list in the result of the latest run, and no run may
/// happen while the iterator is in use.
pub unsafe fn list(v: Value) -> impl Iterator<Item = Value> {
    let mut cur = v;
    core::iter::from_fn(move || {
        if is_int(cur) {
            return None;
        }
        let (head, tail) = unsafe { (field(cur, 0), field(cur, 1)) };
        cur = tail;
        Some(head)
    })
}
