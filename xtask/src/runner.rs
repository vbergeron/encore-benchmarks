//! Build a firmware, run it, and count the instructions of its regions.

use std::collections::HashMap;
use std::io::{BufRead, BufReader, Read};
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::thread;
use std::time::{Duration, Instant};

use bench_build::Board;
use serde_json::{Map, Value, json};

use crate::{ROOT, die, elf, tool};

/// A link failure against the RAM/flash budget: a result (Q1), not a crash.
#[derive(Debug)]
pub struct BudgetError {
    pub region: String,
    pub over: u64,
}

impl std::fmt::Display for BudgetError {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{} budget exceeded by {} bytes", self.region, self.over)
    }
}

pub fn build(
    pkg: &str,
    board: &Board,
    params: &[(&str, String)],
    features: &[&str],
) -> Result<PathBuf, BudgetError> {
    let mut cmd = Command::new("cargo");
    cmd.current_dir(ROOT.as_path())
        .args(["build", "--release", "--target", &board.target, "-p", pkg])
        .env("BENCH_BOARD", &board.name)
        .envs(params.iter().map(|(k, v)| (k, v)));
    if !features.is_empty() {
        cmd.args(["--features", &features.join(",")]);
    }
    let out = cmd
        .output()
        .unwrap_or_else(|e| die(&format!("cannot run cargo: {e}")));
    if !out.status.success() {
        let stderr = String::from_utf8_lossy(&out.stderr);
        if let Some(e) = overflow(&stderr) {
            return Err(e);
        }
        eprint!("{stderr}");
        die(&format!("build of {pkg} failed"));
    }
    Ok(ROOT
        .join("target")
        .join(&board.target)
        .join("release")
        .join(pkg))
}

/// The largest RAM/flash overflow the linker reports, in rust-lld's wording
/// (`will not fit in region 'RAM': overflowed by 12 bytes`, once per section)
/// or GNU ld's (`region `RAM' overflowed by 12 bytes`).
fn overflow(stderr: &str) -> Option<BudgetError> {
    stderr
        .match_indices("region ")
        .filter_map(|(i, m)| {
            let rest = stderr[i + m.len()..].strip_prefix(['`', '\''])?;
            let region = ["RAM", "FLASH"].into_iter().find(|r| rest.starts_with(r))?;
            let rest = rest[region.len()..].strip_prefix('\'')?;
            let rest = rest
                .strip_prefix(':')
                .unwrap_or(rest)
                .strip_prefix(" overflowed by ")?;
            let digits = &rest[..rest
                .find(|c: char| !c.is_ascii_digit())
                .unwrap_or(rest.len())];
            rest[digits.len()..].starts_with(" bytes").then_some(())?;
            Some(BudgetError {
                region: region.to_owned(),
                over: digits.parse().ok()?,
            })
        })
        .max_by_key(|e| e.over)
}

/// Exit code, stdout and region instruction counts of one run.
pub type Run = (i32, String, Vec<u64>);

pub fn run_qemu(elf_path: &Path, board: &Board, count_regions: bool, timeout: u64) -> Run {
    let field = |v: &Option<String>, k: &str| {
        v.clone()
            .unwrap_or_else(|| die(&format!("board {} has no `{k}`", board.name)))
    };
    let mut cmd = Command::new(tool(&["qemu-system-arm"]));
    cmd.args(["-machine", &field(&board.qemu_machine, "qemu_machine")])
        .args(["-cpu", &field(&board.qemu_cpu, "qemu_cpu")])
        .args(["-semihosting-config", "enable=on,target=native"])
        .args(["-nographic", "-monitor", "none", "-serial", "none"])
        .arg("-kernel")
        .arg(elf_path);
    if !count_regions {
        // Virtual time advances 1 ns per instruction, so the SysTick clock
        // that times the Encore GC (memory profile) reads instructions and
        // is the same from run to run.
        cmd.args(["-icount", "shift=0"]);
        let (code, out, _) = run_timed(cmd, elf_path, timeout, None);
        return (code, out, Vec::new());
    }

    let begin = elf::symbol_addr(elf_path, "bench_region_begin");
    let end = elf::symbol_addr(elf_path, "bench_region_end");
    let (Some(begin), Some(end)) = (begin, end) else {
        die(&format!(
            "{}: region markers not found (is bench_harness linked?)",
            file_name(elf_path)
        ));
    };
    // With no -D, QEMU writes its log to stderr, which we read as it comes.
    cmd.args(["-d", "in_asm,exec,nochain"]);
    let (code, out, counter) =
        run_timed(cmd, elf_path, timeout, Some(RegionCounter::new(begin, end)));
    (code, out, counter.map(|c| c.regions).unwrap_or_default())
}

pub fn run_probe(elf_path: &Path, board: &Board, timeout: u64) -> Run {
    // probe-rs forwards semihosting output and exits with the firmware's
    // semihosting exit code. Not yet validated on hardware.
    let chip = board
        .chip
        .clone()
        .unwrap_or_else(|| die(&format!("board {} has no `chip`", board.name)));
    let mut cmd = Command::new(tool(&["probe-rs"]));
    cmd.args(["run", "--chip", &chip]).arg(elf_path);
    let (code, out, _) = run_timed(cmd, elf_path, timeout, None);
    (code, out, Vec::new())
}

fn file_name(p: &Path) -> String {
    p.file_name().map_or_else(
        || p.display().to_string(),
        |n| n.to_string_lossy().into_owned(),
    )
}

/// Run `cmd` to completion or until `timeout` seconds, feeding its stderr to
/// `counter` when there is one.
fn run_timed(
    mut cmd: Command,
    elf_path: &Path,
    timeout: u64,
    counter: Option<RegionCounter>,
) -> (i32, String, Option<RegionCounter>) {
    cmd.stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped());
    let mut child = cmd
        .spawn()
        .unwrap_or_else(|e| die(&format!("cannot start {:?}: {e}", cmd.get_program())));
    let mut stdout = child.stdout.take().expect("piped stdout");
    let stderr = child.stderr.take().expect("piped stderr");
    let out_reader = thread::spawn(move || {
        let mut buf = Vec::new();
        let _ = stdout.read_to_end(&mut buf);
        String::from_utf8_lossy(&buf).into_owned()
    });
    let err_reader = thread::spawn(move || {
        let mut counter = counter;
        let mut r = BufReader::with_capacity(1 << 20, stderr);
        let mut line = Vec::new();
        while r.read_until(b'\n', &mut line).unwrap_or(0) > 0 {
            if let Some(c) = counter.as_mut() {
                c.feed(&line);
            }
            line.clear();
        }
        counter
    });

    let deadline = Instant::now() + Duration::from_secs(timeout);
    let status = loop {
        match child.try_wait() {
            Ok(Some(status)) => break status,
            Ok(None) if Instant::now() >= deadline => {
                let _ = child.kill();
                let _ = child.wait();
                die(&format!(
                    "{}: timed out after {timeout}s",
                    file_name(elf_path)
                ));
            }
            Ok(None) => thread::sleep(Duration::from_millis(10)),
            Err(e) => die(&format!("waiting for {:?}: {e}", cmd.get_program())),
        }
    };
    let out = out_reader.join().expect("stdout reader");
    let counter = err_reader.join().expect("stderr reader");
    (status.code().unwrap_or(-1), out, counter)
}

/// Count guest instructions between region markers in a QEMU trace.
///
/// QEMU (`-d in_asm,exec,nochain`) logs every translation block (TB) once
/// when it is translated (`IN:` + `OBJD-T: <hex bytes>`) and every execution
/// of a TB (`Trace N: <host> [<flags>/<guest pc>/...]`). With chaining
/// disabled every execution is logged, so summing the instruction counts of
/// the TBs executed between the TB starting at `bench_region_begin` and the
/// one starting at `bench_region_end` gives the instructions of the region.
pub struct RegionCounter {
    begin: u64,
    end: u64,
    tb_insns: HashMap<u64, u64>,
    pending: Option<u64>,
    current: Option<u64>,
    pub regions: Vec<u64>,
    pub total: u64,
}

impl RegionCounter {
    pub fn new(begin: u64, end: u64) -> Self {
        RegionCounter {
            begin,
            end,
            tb_insns: HashMap::new(),
            pending: None,
            current: None,
            regions: Vec::new(),
            total: 0,
        }
    }

    /// Thumb instructions in a block of little-endian code bytes.
    pub fn thumb_insns(raw: &[u8]) -> u64 {
        let (mut n, mut i) = (0, 0);
        while i + 1 < raw.len() {
            let hw = u16::from(raw[i]) | (u16::from(raw[i + 1]) << 8);
            i += if hw & 0xE000 == 0xE000 && hw & 0x1800 != 0 {
                4
            } else {
                2
            };
            n += 1;
        }
        n
    }

    pub fn feed(&mut self, line: &[u8]) {
        if let Some(hex) = line.strip_prefix(b"OBJD-T: ") {
            let raw = decode_hex(hex);
            self.pending = Some(self.pending.unwrap_or(0) + Self::thumb_insns(&raw));
            return;
        }
        let Some((host, pc)) = parse_trace(line) else {
            return;
        };
        if let Some(n) = self.pending.take() {
            // First execution after a translation: (re)bind this host address.
            self.tb_insns.insert(host, n);
        }
        let n = self.tb_insns.get(&host).copied().unwrap_or(0);
        self.total += n;
        if pc == self.begin {
            self.current = Some(0);
        } else if pc == self.end {
            if let Some(c) = self.current.take() {
                self.regions.push(c);
            }
        } else if let Some(c) = self.current.as_mut() {
            *c += n;
        }
    }
}

fn decode_hex(s: &[u8]) -> Vec<u8> {
    let digits: Vec<u8> = s
        .iter()
        .filter(|c| !c.is_ascii_whitespace())
        .map_while(|&c| (c as char).to_digit(16).map(|d| d as u8))
        .collect();
    digits.chunks_exact(2).map(|p| (p[0] << 4) | p[1]).collect()
}

fn lower_hex(s: &[u8]) -> Option<u64> {
    let ok = !s.is_empty() && s.iter().all(|c| matches!(c, b'0'..=b'9' | b'a'..=b'f'));
    ok.then(|| u64::from_str_radix(std::str::from_utf8(s).ok()?, 16).ok())?
}

/// `Trace 0: 0x7f00dead [00000000/00000134/...` → `(host, guest pc)`.
fn parse_trace(line: &[u8]) -> Option<(u64, u64)> {
    let rest = line.strip_prefix(b"Trace ")?;
    let digits = rest.iter().take_while(|c| c.is_ascii_digit()).count();
    let rest = rest[digits..]
        .strip_prefix(b": 0x")
        .filter(|_| digits > 0)?;
    let sp = rest.iter().position(|&c| c == b' ')?;
    let host = lower_hex(&rest[..sp])?;
    let rest = rest[sp..].strip_prefix(b" [")?;
    let mut fields = rest.splitn(3, |&c| c == b'/');
    lower_hex(fields.next()?)?;
    let pc = lower_hex(fields.next()?)?;
    fields.next()?;
    Some((host, pc))
}

pub const PREFIX: &str = "@@BENCH ";

pub fn parse_records(stdout: &str) -> Vec<Map<String, Value>> {
    stdout
        .lines()
        .filter_map(|l| l.strip_prefix(PREFIX))
        .map(|r| {
            serde_json::from_str(r)
                .unwrap_or_else(|_| die(&format!("malformed record: {:?}", format!("{PREFIX}{r}"))))
        })
        .collect()
}

pub fn order_stats(xs: &[u64]) -> Value {
    let mut s = xs.to_vec();
    s.sort_unstable();
    let n = s.len();
    let p99 = s[(99 * n).div_ceil(100).clamp(1, n) - 1];
    json!({"min": s[0], "median": s[(n - 1) / 2], "p99": p99, "max": s[n - 1]})
}

/// Give each record carrying `regions` its share of the counted regions, in
/// order, minus the calibration overhead.
pub fn attach_insns(records: &mut [Map<String, Value>], regions: &[u64]) {
    let count =
        |r: &Map<String, Value>| r.get("regions").and_then(Value::as_u64).unwrap_or(0) as usize;
    let expected: usize = records.iter().map(count).sum();
    if expected != regions.len() {
        die(&format!(
            "trace has {} regions, records announce {expected}",
            regions.len()
        ));
    }
    let (mut overhead, mut i) = (0, 0);
    for r in records.iter_mut() {
        let k = count(r);
        let mine = &regions[i..i + k];
        i += k;
        if k == 0 {
            continue;
        }
        let net: Vec<u64> = mine.iter().map(|x| x.saturating_sub(overhead)).collect();
        let mut stats = order_stats(&net);
        if r.get("kind").and_then(Value::as_str) == Some("calibration") {
            overhead = stats["median"].as_u64().unwrap_or(0);
            stats = order_stats(mine);
        }
        r.insert("insns".into(), stats);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn thumb_widths() {
        // movs r0, #1 (16-bit); bl (32-bit); bx lr (16-bit)
        assert_eq!(
            RegionCounter::thumb_insns(&[0x01, 0x20, 0x00, 0xf0, 0x00, 0xf8, 0x70, 0x47]),
            3
        );
        assert_eq!(RegionCounter::thumb_insns(&[0x01]), 0);
    }

    #[test]
    fn counts_between_markers() {
        let mut c = RegionCounter::new(0x100, 0x200);
        for l in [
            "OBJD-T: 01200120",
            "Trace 0: 0x7f01 [00000000/00000100/01000000/ff200000] ",
            "OBJD-T: 0120012001207047",
            "Trace 0: 0x7f02 [00000000/00000150/01000000/ff200000] ",
            "Trace 0: 0x7f02 [00000000/00000150/01000000/ff200000] ",
            "OBJD-T: 7047",
            "Trace 0: 0x7f03 [00000000/00000200/01000000/ff200000] ",
        ] {
            c.feed(l.as_bytes());
        }
        assert_eq!(c.regions, vec![8]);
        assert_eq!(c.total, 11);
    }

    #[test]
    fn trace_lines() {
        assert_eq!(
            parse_trace(b"Trace 12: 0x7fab [0000/00000134/x] f\n"),
            Some((0x7fab, 0x134))
        );
        assert_eq!(parse_trace(b"Trace : 0x7fab [0000/00000134/x]"), None);
        assert_eq!(parse_trace(b"Trace 1: 0x7FAB [0000/00000134/x]"), None);
    }

    #[test]
    fn budget_overflow() {
        let lld = "rust-lld: error: section '.text' will not fit in region 'FLASH': overflowed by 40 bytes\n\
                   rust-lld: error: section '.rodata' will not fit in region 'FLASH': overflowed by 3968 bytes\n";
        let e = overflow(lld).unwrap();
        assert_eq!((e.region.as_str(), e.over), ("FLASH", 3968));
        assert!(overflow("error: linking failed\n").is_none());
        let e = overflow("ld: region `FLASH' overflowed by 1234 bytes\n").unwrap();
        assert_eq!((e.region.as_str(), e.over), ("FLASH", 1234));
    }

    #[test]
    fn stats() {
        let v: Vec<u64> = (1..=100).collect();
        assert_eq!(
            order_stats(&v),
            json!({"min": 1, "median": 50, "p99": 99, "max": 100})
        );
        assert_eq!(
            order_stats(&[7]),
            json!({"min": 7, "median": 7, "p99": 7, "max": 7})
        );
    }
}
