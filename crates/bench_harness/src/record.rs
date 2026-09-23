//! One-line JSON records, written straight to the sink without buffering.

use crate::{Summary, RECORD_PREFIX};
use core::fmt::Write;

/// Builder for one record. Fields are written as they are added; nothing is
/// allocated. Write errors are ignored: a truncated line is rejected by the
/// runner, which is the best a firmware can do about a broken output channel.
pub struct Record<'w, W: Write> {
    out: &'w mut W,
}

impl<'w, W: Write> Record<'w, W> {
    pub fn new(out: &'w mut W, kind: &str) -> Self {
        let _ = out.write_str(RECORD_PREFIX);
        let _ = out.write_str("{\"kind\":");
        let _ = write_json_str(out, kind);
        Record { out }
    }

    fn key(&mut self, k: &str) {
        let _ = self.out.write_char(',');
        let _ = write_json_str(self.out, k);
        let _ = self.out.write_char(':');
    }

    pub fn str(mut self, k: &str, v: &str) -> Self {
        self.key(k);
        let _ = write_json_str(self.out, v);
        self
    }

    pub fn u32(mut self, k: &str, v: u32) -> Self {
        self.key(k);
        let _ = write!(self.out, "{v}");
        self
    }

    pub fn u64(mut self, k: &str, v: u64) -> Self {
        self.key(k);
        let _ = write!(self.out, "{v}");
        self
    }

    pub fn i64(mut self, k: &str, v: i64) -> Self {
        self.key(k);
        let _ = write!(self.out, "{v}");
        self
    }

    pub fn bool(mut self, k: &str, v: bool) -> Self {
        self.key(k);
        let _ = self.out.write_str(if v { "true" } else { "false" });
        self
    }

    /// A 32-bit value written as a `"0x........"` string (hashes).
    pub fn hex(mut self, k: &str, v: u32) -> Self {
        self.key(k);
        let _ = write!(self.out, "\"{v:#010x}\"");
        self
    }

    /// `"regions"` (always) and `"cycles": {min, median, p99, max}` (only
    /// when the counter is real, so QEMU records never carry fake cycles).
    pub fn timing(mut self, s: &Summary) -> Self {
        self = self.u32("regions", s.runs);
        if s.cycles {
            self.key("cycles");
            let _ = write!(
                self.out,
                "{{\"min\":{},\"median\":{},\"p99\":{},\"max\":{}}}",
                s.min, s.median, s.p99, s.max
            );
        }
        self
    }

    /// Peak stack use in bytes, from [`crate::stack::peak`].
    pub fn stack(self, peak: Option<usize>) -> Self {
        match peak {
            Some(b) => self.u32("stack_peak_bytes", b as u32),
            None => self,
        }
    }

    pub fn finish(self) {
        let _ = self.out.write_str("}\n");
    }
}

fn write_json_str<W: Write>(out: &mut W, s: &str) -> core::fmt::Result {
    out.write_char('"')?;
    for c in s.chars() {
        match c {
            '"' => out.write_str("\\\"")?,
            '\\' => out.write_str("\\\\")?,
            c if (c as u32) < 0x20 => write!(out, "\\u{:04x}", c as u32)?,
            c => out.write_char(c)?,
        }
    }
    out.write_char('"')
}

#[cfg(test)]
mod tests {
    use super::*;

    struct Buf {
        data: [u8; 256],
        len: usize,
    }

    impl Write for Buf {
        fn write_str(&mut self, s: &str) -> core::fmt::Result {
            let end = self.len + s.len();
            self.data.get_mut(self.len..end).ok_or(core::fmt::Error)?.copy_from_slice(s.as_bytes());
            self.len = end;
            Ok(())
        }
    }

    fn render(f: impl FnOnce(&mut Buf)) -> Buf {
        let mut b = Buf { data: [0; 256], len: 0 };
        f(&mut b);
        b
    }

    fn text(b: &Buf) -> &str {
        core::str::from_utf8(&b.data[..b.len]).unwrap()
    }

    #[test]
    fn full_record() {
        let s = Summary { runs: 3, cycles: true, min: 1, median: 2, p99: 3, max: 3 };
        let b = render(|b| {
            Record::new(b, "case").str("w", "a\"b").u32("n", 7).hex("h", 0xab).timing(&s).stack(Some(64)).finish()
        });
        assert_eq!(
            text(&b),
            "@@BENCH {\"kind\":\"case\",\"w\":\"a\\\"b\",\"n\":7,\"h\":\"0x000000ab\",\"regions\":3,\
             \"cycles\":{\"min\":1,\"median\":2,\"p99\":3,\"max\":3},\"stack_peak_bytes\":64}\n"
        );
    }

    #[test]
    fn no_fake_cycles() {
        let s = Summary { runs: 1, cycles: false, ..Summary::default() };
        let b = render(|b| Record::new(b, "calibration").timing(&s).finish());
        assert_eq!(text(&b), "@@BENCH {\"kind\":\"calibration\",\"regions\":1}\n");
    }
}

/// Fixed-capacity string for formatting short messages (error reasons)
/// without an allocator. Output past the capacity is dropped.
pub struct FmtBuf<const N: usize> {
    buf: [u8; N],
    len: usize,
}

impl<const N: usize> FmtBuf<N> {
    pub const fn new() -> Self {
        FmtBuf { buf: [0; N], len: 0 }
    }

    pub fn as_str(&self) -> &str {
        // Only whole `&str`s are copied in, but truncation may split a char.
        match core::str::from_utf8(&self.buf[..self.len]) {
            Ok(s) => s,
            Err(e) => core::str::from_utf8(&self.buf[..e.valid_up_to()]).unwrap_or(""),
        }
    }
}

impl<const N: usize> Default for FmtBuf<N> {
    fn default() -> Self {
        Self::new()
    }
}

impl<const N: usize> Write for FmtBuf<N> {
    fn write_str(&mut self, s: &str) -> core::fmt::Result {
        let n = s.len().min(N - self.len);
        self.buf[self.len..self.len + n].copy_from_slice(&s.as_bytes()[..n]);
        self.len += n;
        Ok(())
    }
}
