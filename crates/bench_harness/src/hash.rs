//! Output fingerprint. Every variant hashes its outputs the same way, and the
//! runner checks that each variant's hash matches the Rust (R) oracle's
//! before any of its measurements are trusted.

/// 32-bit FNV-1a.
#[derive(Clone, Copy, Debug)]
pub struct Fnv1a(u32);

impl Default for Fnv1a {
    fn default() -> Self {
        Self::new()
    }
}

impl Fnv1a {
    pub const fn new() -> Self {
        Fnv1a(0x811c_9dc5)
    }

    pub fn bytes(&mut self, data: &[u8]) -> &mut Self {
        for &b in data {
            self.0 ^= b as u32;
            self.0 = self.0.wrapping_mul(0x0100_0193);
        }
        self
    }

    /// Hash an integer as 4 little-endian bytes (so an `i32` from the VM and
    /// a `u32` from native code hash equally when the value is the same).
    pub fn int(&mut self, v: i64) -> &mut Self {
        self.bytes(&(v as i32).to_le_bytes())
    }

    pub fn finish(&self) -> u32 {
        self.0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn known_vectors() {
        assert_eq!(Fnv1a::new().finish(), 0x811c_9dc5);
        assert_eq!(Fnv1a::new().bytes(b"a").finish(), 0xe40c_292c);
        assert_eq!(Fnv1a::new().bytes(b"foobar").finish(), 0xbf9c_f968);
    }
}
