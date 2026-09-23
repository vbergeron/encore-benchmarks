//! Output and exit over ARM semihosting.

use core::fmt;

/// Semihosting stdout as a [`fmt::Write`] sink.
pub struct Stdout(cortex_m_semihosting::hio::HostStream);

impl Stdout {
    pub fn new() -> Option<Stdout> {
        cortex_m_semihosting::hio::hstdout().ok().map(Stdout)
    }
}

impl fmt::Write for Stdout {
    fn write_str(&mut self, s: &str) -> fmt::Result {
        self.0.write_all(s.as_bytes()).map_err(|_| fmt::Error)
    }
}

/// End the run. The runner treats a failure exit as a failed benchmark and
/// discards its records.
pub fn exit(success: bool) -> ! {
    use cortex_m_semihosting::debug;
    debug::exit(if success { debug::EXIT_SUCCESS } else { debug::EXIT_FAILURE });
    #[allow(clippy::empty_loop)]
    loop {}
}
