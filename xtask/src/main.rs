//! Build, run and record encore-benchmarks firmware.
//!
//! ```text
//! cargo xtask run   -w w0_smoke -v e -b qemu-lm3s6965
//! cargo xtask check
//! cargo xtask minheap -w w0_smoke -v e
//! cargo xtask size target/thumbv7m-none-eabi/release/w0_smoke-e
//! ```
//!
//! `run` builds `<workload>-<variant>` for the board's target with the budget
//! and parameters passed as BENCH_* variables (see crates/bench_build), runs
//! it, reads the `@@BENCH` records it prints, adds what only the host knows
//! (commit, toolchain, ELF sizes, and on QEMU the instruction count of every
//! region) and appends one row per case to results/benchmarks.jsonl.

mod elf;
mod json;
mod runner;

use std::collections::BTreeMap;
use std::fs::{self, OpenOptions};
use std::io::Write as _;
use std::path::{Path, PathBuf};
use std::process::{Command, exit};
use std::sync::LazyLock;
use std::time::{SystemTime, UNIX_EPOCH};

use bench_build::Board;
use clap::{Args, Parser, Subcommand};
use serde_json::{Map, Value, json};

use runner::{BudgetError, PREFIX};

static ROOT: LazyLock<PathBuf> = LazyLock::new(|| {
    Path::new(env!("CARGO_MANIFEST_DIR"))
        .parent()
        .expect("xtask/ has a parent")
        .to_owned()
});
const SCHEMA: u64 = 1;
const ORACLE_VARIANT: &str = "R";

fn results_path() -> String {
    ROOT.join("results")
        .join("benchmarks.jsonl")
        .display()
        .to_string()
}

pub fn die(msg: &str) -> ! {
    eprintln!("bench: {msg}");
    exit(1)
}

fn sh(cmd: &[&str]) -> String {
    let out = Command::new(cmd[0])
        .args(&cmd[1..])
        .current_dir(ROOT.as_path())
        .output()
        .unwrap_or_else(|e| die(&format!("cannot run {}: {e}", cmd[0])));
    if !out.status.success() {
        die(&format!(
            "{} failed: {}",
            cmd.join(" "),
            String::from_utf8_lossy(&out.stderr).trim()
        ));
    }
    String::from_utf8_lossy(&out.stdout).trim().to_owned()
}

/// The first of `names` found in PATH.
pub fn tool(names: &[&str]) -> String {
    let path = std::env::var_os("PATH").unwrap_or_default();
    names
        .iter()
        .find(|n| std::env::split_paths(&path).any(|d| d.join(n).is_file()))
        .map(|n| (*n).to_owned())
        .unwrap_or_else(|| die(&format!("none of {} found in PATH", names.join(", "))))
}

// ── Command line ────────────────────────────────────────────────────────────

#[derive(Parser)]
#[command(
    name = "cargo xtask",
    about = "Build, run and record encore-benchmarks firmware"
)]
struct Cli {
    #[command(subcommand)]
    cmd: Cmd,
}

#[derive(Subcommand)]
enum Cmd {
    /// Build, run and record one workload variant
    Run(RunArgs),
    /// Compare every variant's latest out_hash with the R oracle
    Check {
        #[arg(long, default_value_t = results_path())]
        results: String,
    },
    /// Binary-search the smallest Encore heap that passes all cases
    Minheap {
        #[command(flatten)]
        target: TargetArgs,
        #[arg(long, default_value_t = 256)]
        step: u64,
        #[arg(long, default_value_t = 40 * 1024)]
        max_heap: u64,
    },
    /// Flash/RAM breakdown of an ELF
    Size { elf: PathBuf },
}

#[derive(Args, Clone)]
struct TargetArgs {
    /// e.g. w0_smoke
    #[arg(short, long)]
    workload: String,
    /// e (Encore), c (CertiRocq), r (Rust), rv (verified Rust)
    #[arg(short, long)]
    variant: String,
    #[arg(short, long, default_value = "qemu-lm3s6965")]
    board: String,
    /// RAM budget (50 = ST33J2M0, 64 = ST33K1M5)
    #[arg(long, default_value_t = 50)]
    ram_kb: u32,
    #[arg(long, default_value_t = 256)]
    flash_kb: u32,
    /// Encore heap (default: the workload's)
    #[arg(long)]
    heap_bytes: Option<u64>,
    /// Timed runs per case (default: 1 on QEMU, 1000 on boards)
    #[arg(long)]
    reps: Option<u32>,
    #[arg(long, value_parser = ["on", "off"], default_value = "on")]
    cps_optimize: String,
    /// Seconds
    #[arg(long, default_value_t = 600)]
    timeout: u64,
}

#[derive(Args)]
struct RunArgs {
    #[command(flatten)]
    target: TargetArgs,
    /// timing: instruction/cycle counts, no stats; memory: VM stats on (heap peak, ops)
    #[arg(long, value_parser = ["timing", "memory"], default_value = "timing")]
    profile: String,
    /// Free-form tag stored with the rows
    #[arg(long, default_value = "")]
    label: String,
    #[arg(long, default_value_t = results_path())]
    out: String,
    /// Do not append to the results file
    #[arg(long)]
    dry_run: bool,
}

fn main() {
    match Cli::parse().cmd {
        Cmd::Run(a) => cmd_run(&a),
        Cmd::Check { results } => cmd_check(Path::new(&results)),
        Cmd::Minheap {
            target,
            step,
            max_heap,
        } => cmd_minheap(&target, step, max_heap),
        Cmd::Size { elf } => println!(
            "{}",
            serde_json::to_string_pretty(&elf::size_report(&elf)).unwrap()
        ),
    }
}

// ── Boards and packages ─────────────────────────────────────────────────────

fn load_board(name: &str) -> Board {
    if !ROOT.join("boards").join(format!("{name}.toml")).is_file() {
        let mut known: Vec<String> = fs::read_dir(ROOT.join("boards"))
            .into_iter()
            .flatten()
            .flatten()
            .filter_map(|e| {
                e.file_name()
                    .to_str()?
                    .strip_suffix(".toml")
                    .map(str::to_owned)
            })
            .collect();
        known.sort();
        die(&format!(
            "unknown board {name:?} (known: {})",
            known.join(", ")
        ));
    }
    Board::load(&ROOT, name)
}

fn manifest(path: &Path) -> toml::Table {
    let text =
        fs::read_to_string(path).unwrap_or_else(|e| die(&format!("{}: {e}", path.display())));
    text.parse()
        .unwrap_or_else(|e| die(&format!("{}: {e}", path.display())))
}

/// Directory of the firmware package `pkg`, under workloads/<w>/<variant>/.
fn package_dir(pkg: &str) -> PathBuf {
    let subdirs = |p: PathBuf| {
        fs::read_dir(p)
            .into_iter()
            .flatten()
            .flatten()
            .map(|e| e.path())
    };
    subdirs(ROOT.join("workloads"))
        .flat_map(subdirs)
        .find(|d| {
            let m = d.join("Cargo.toml");
            m.is_file()
                && manifest(&m)
                    .get("package")
                    .and_then(|p| p.get("name"))
                    .and_then(|n| n.as_str())
                    == Some(pkg)
        })
        .unwrap_or_else(|| {
            die(&format!(
                "no firmware package named {pkg:?} under workloads/"
            ))
        })
}

fn has_feature(pkg_dir: &Path, feature: &str) -> bool {
    manifest(&pkg_dir.join("Cargo.toml"))
        .get("features")
        .and_then(|f| f.as_table())
        .is_some_and(|f| f.contains_key(feature))
}

// ── Provenance ──────────────────────────────────────────────────────────────

fn provenance() -> Map<String, Value> {
    let lock = fs::read_to_string(ROOT.join("Cargo.lock")).unwrap_or_default();
    let key = "name = \"encore_vm\"\nversion = \"";
    let encore = lock
        .find(key)
        .and_then(|i| lock[i + key.len()..].split_once('"'))
        .map(|(v, _)| v.to_owned());
    let mut p = Map::new();
    p.insert("commit".into(), json!(sh(&["git", "rev-parse", "HEAD"])));
    p.insert(
        "dirty".into(),
        json!(!sh(&["git", "status", "--porcelain", "--untracked-files=no"]).is_empty()),
    );
    p.insert("encore_version".into(), json!(encore));
    p.insert("rustc".into(), json!(sh(&["rustc", "--version"])));
    p
}

/// Now, as `2026-09-23T08:59:05+00:00`.
fn utc_now() -> String {
    let secs = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .expect("clock after 1970")
        .as_secs();
    let (days, rem) = ((secs / 86_400) as i64, secs % 86_400);
    // Civil date from days since 1970-01-01 (Howard Hinnant's algorithm).
    let z = days + 719_468;
    let era = z.div_euclid(146_097);
    let doe = z - era * 146_097;
    let yoe = (doe - doe / 1460 + doe / 36_524 - doe / 146_096) / 365;
    let doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    let mp = (5 * doy + 2) / 153;
    let day = doy - (153 * mp + 2) / 5 + 1;
    let month = if mp < 10 { mp + 3 } else { mp - 9 };
    let year = yoe + era * 400 + i64::from(month <= 2);
    let (h, m, s) = (rem / 3600, rem / 60 % 60, rem % 60);
    format!("{year:04}-{month:02}-{day:02}T{h:02}:{m:02}:{s:02}+00:00")
}

// ── Commands ────────────────────────────────────────────────────────────────

fn build_params(a: &TargetArgs, heap: Option<u64>) -> Vec<(&'static str, String)> {
    let mut p = vec![
        ("BENCH_RAM_KB", a.ram_kb.to_string()),
        ("BENCH_FLASH_KB", a.flash_kb.to_string()),
        ("BENCH_CPS_OPTIMIZE", a.cps_optimize.clone()),
    ];
    if let Some(h) = heap.or(a.heap_bytes) {
        p.push(("BENCH_HEAP_BYTES", h.to_string()));
    }
    if let Some(r) = a.reps {
        p.push(("BENCH_REPS", r.to_string()));
    }
    p
}

type Record = Map<String, Value>;

fn kind(r: &Record) -> &str {
    r.get("kind").and_then(Value::as_str).unwrap_or("")
}

/// A `case` record whose timed runs all succeeded. The firmware reports a
/// timed run that failed (e.g. out of heap, when garbage from the previous
/// run is still reachable) with `"timed_ok": false`: its region counts
/// measure a partial run and must not be read as a result.
fn passed(r: &Record) -> bool {
    kind(r) == "case" && r.get("timed_ok") != Some(&Value::Bool(false))
}

/// Build and run once. Returns the device records, the ELF and the features.
fn execute(
    a: &TargetArgs,
    profile: &str,
    heap: Option<u64>,
    quiet: bool,
) -> Result<(Vec<Record>, PathBuf, Vec<&'static str>), BudgetError> {
    let board = load_board(&a.board);
    let pkg = format!("{}-{}", a.workload, a.variant.to_lowercase());
    let pdir = package_dir(&pkg);
    let features = if profile == "memory" && has_feature(&pdir, "stats") {
        vec!["stats"]
    } else {
        vec![]
    };
    let elf = runner::build(&pkg, &board, &build_params(a, heap), &features)?;

    let (code, out, regions) = match board.runner.as_str() {
        // Instructions are counted in the timing profile only: tracing is slow.
        "qemu" => runner::run_qemu(&elf, &board, profile == "timing", a.timeout),
        "probe-rs" => runner::run_probe(&elf, &board, a.timeout),
        other => die(&format!("unknown runner {other:?}")),
    };
    let mut records = runner::parse_records(&out);
    if code != 0 {
        eprint!("{out}");
        die(&format!("{pkg} exited with status {code}"));
    }
    if !regions.is_empty() {
        runner::attach_insns(&mut records, &regions);
    }
    if !quiet {
        for r in &records {
            println!("{PREFIX}{}", json::line(r));
        }
    }
    Ok((records, elf, features))
}

fn cmd_run(a: &RunArgs) {
    let t = &a.target;
    let (records, built) = match execute(t, &a.profile, None, false) {
        Ok((records, elf, features)) => (records, Some((elf, features))),
        Err(e) => {
            println!("bench: {e} — recorded as a failure (Q1)");
            let fail = json!({"kind": "fail", "workload": t.workload, "variant": t.variant.to_uppercase(),
                              "n": null, "reason": e.to_string()});
            (vec![fail.as_object().unwrap().clone()], None)
        }
    };
    let start = records.iter().find(|r| kind(r) == "start");
    let from_start = |k: &str| start.and_then(|s| s.get(k)).cloned().unwrap_or(Value::Null);
    let board = load_board(&t.board);

    let mut base = Map::new();
    base.insert("schema".into(), json!(SCHEMA));
    base.insert("timestamp".into(), json!(utc_now()));
    base.insert("label".into(), json!(a.label));
    base.extend(provenance());
    base.insert("workload".into(), json!(t.workload));
    base.insert("variant".into(), json!(t.variant.to_uppercase()));
    base.insert("board".into(), json!(board.name));
    base.insert("core".into(), json!(board.core));
    base.insert("target".into(), json!(board.target));
    base.insert("profile".into(), json!(a.profile));
    base.insert(
        "build".into(),
        json!({
            "ram_kb": t.ram_kb,
            "flash_kb": t.flash_kb,
            "reps": from_start("reps"),
            "heap_bytes": from_start("heap_bytes"),
            "program_bytes": from_start("program_bytes"),
            "cps_optimize": from_start("cps_optimize"),
            "features": built.as_ref().map_or(vec![], |(_, f)| f.clone()),
        }),
    );
    base.insert(
        "size".into(),
        built
            .as_ref()
            .map_or(Value::Null, |(elf, _)| elf::size_report(elf)),
    );
    if let Some(calib) = records.iter().find(|r| kind(r) == "calibration") {
        let c: Map<String, Value> = ["insns", "cycles"]
            .into_iter()
            .filter_map(|k| Some((k.to_owned(), calib.get(k)?.clone())))
            .collect();
        base.insert("calibration".into(), Value::Object(c));
    }

    let rows: Vec<Record> = records
        .iter()
        .filter(|r| matches!(kind(r), "case" | "fail"))
        .map(|r| {
            let mut row = base.clone();
            row.insert("n".into(), r.get("n").cloned().unwrap_or(Value::Null));
            row.insert("ok".into(), json!(passed(r)));
            if kind(r) == "case" && !passed(r) {
                row.insert("reason".into(), json!("a timed run failed"));
            }
            for (k, v) in r {
                if !["kind", "workload", "variant", "n", "regions"].contains(&k.as_str()) {
                    row.insert(k.clone(), v.clone());
                }
            }
            row
        })
        .collect();
    if rows.is_empty() {
        die("no case records produced");
    }

    let out = Path::new(&a.out);
    if !a.dry_run {
        if let Some(dir) = out.parent().filter(|d| !d.as_os_str().is_empty()) {
            fs::create_dir_all(dir).unwrap_or_else(|e| die(&format!("{}: {e}", dir.display())));
        }
        let mut f = OpenOptions::new()
            .create(true)
            .append(true)
            .open(out)
            .unwrap_or_else(|e| die(&format!("{}: {e}", out.display())));
        for row in &rows {
            writeln!(f, "{}", json::line(row))
                .unwrap_or_else(|e| die(&format!("{}: {e}", out.display())));
        }
        let shown = std::path::absolute(out).unwrap_or_else(|_| out.to_owned());
        let shown = shown.strip_prefix(ROOT.as_path()).unwrap_or(&shown);
        println!("bench: {} rows appended to {}", rows.len(), shown.display());
    }
    report_oracle(&rows, out);
}

fn load_rows(path: &Path) -> Vec<Record> {
    let Ok(text) = fs::read_to_string(path) else {
        return vec![];
    };
    text.lines()
        .filter(|l| !l.trim().is_empty())
        .map(|l| {
            serde_json::from_str(l).unwrap_or_else(|e| die(&format!("{}: {e}", path.display())))
        })
        .collect()
}

fn field(r: &Record, k: &str) -> Value {
    r.get(k).cloned().unwrap_or(Value::Null)
}

/// `(workload, n)` → out_hash of the most recent successful R row.
fn oracle_table<'a>(rows: impl IntoIterator<Item = &'a Record>) -> BTreeMap<String, Value> {
    rows.into_iter()
        .filter(|r| r.get("variant").and_then(Value::as_str) == Some(ORACLE_VARIANT) && is_ok(r))
        .map(|r| {
            (
                json!([field(r, "workload"), field(r, "n")]).to_string(),
                field(r, "out_hash"),
            )
        })
        .collect()
}

fn is_ok(r: &Record) -> bool {
    r.get("ok").and_then(Value::as_bool).unwrap_or(false)
}

fn show(v: &Value) -> String {
    match v {
        Value::String(s) => s.clone(),
        Value::Null => "None".into(),
        v => v.to_string(),
    }
}

fn report_oracle(new_rows: &[Record], results: &Path) -> bool {
    let old = load_rows(results);
    let oracle = oracle_table(old.iter().chain(new_rows));
    let mut ok = true;
    for r in new_rows {
        let (w, v, n) = (
            show(&field(r, "workload")),
            show(&field(r, "variant")),
            show(&field(r, "n")),
        );
        if !is_ok(r) {
            println!("  {w} {v} n={n}: FAILED ({})", show(&field(r, "reason")));
            continue;
        }
        let key = json!([field(r, "workload"), field(r, "n")]).to_string();
        let verdict = match oracle.get(&key) {
            None => "no oracle yet",
            Some(h) if *h == field(r, "out_hash") => "ok",
            Some(_) => "MISMATCH",
        };
        ok &= verdict != "MISMATCH";
        let nonempty = |k: &str| {
            r.get(k)
                .filter(|c| c.as_object().is_some_and(|o| !o.is_empty()))
        };
        let extra = match nonempty("insns")
            .map(|c| ("insns", c))
            .or(nonempty("cycles").map(|c| ("cycles", c)))
        {
            Some((what, cost)) => format!(" {what} median={}", show(&cost["median"])),
            None => String::new(),
        };
        println!("  {w} {v} n={n}: {verdict}{extra}");
    }
    ok
}

fn cmd_check(results: &Path) {
    let rows = load_rows(results);
    let oracle = oracle_table(&rows);
    let mut latest: BTreeMap<(String, String, String, String), &Record> = BTreeMap::new();
    for r in rows.iter().filter(|r| is_ok(r)) {
        let key = ["workload", "variant", "board", "n"].map(|k| show(&field(r, k)));
        latest.insert(key.into(), r);
    }
    let mut bad = 0;
    for ((w, v, b, n), r) in &latest {
        let key = json!([field(r, "workload"), field(r, "n")]).to_string();
        let hash = field(r, "out_hash");
        if let Some(reference) = oracle.get(&key).filter(|h| **h != hash) {
            bad += 1;
            println!(
                "MISMATCH {w} {v} {b} n={n}: {} != oracle {}",
                show(&hash),
                show(reference)
            );
        }
    }
    println!(
        "bench: {} latest results checked against the {ORACLE_VARIANT} oracle, {bad} mismatches",
        latest.len()
    );
    exit(i32::from(bad > 0));
}

/// Smallest heap (multiple of `step`) at which every case still passes.
fn cmd_minheap(a: &TargetArgs, step: u64, max_heap: u64) {
    let passes = |heap: u64| -> bool {
        let good = match execute(a, "memory", Some(heap), true) {
            Err(_) => false,
            Ok((records, _, _)) => {
                let cases: Vec<&Record> = records
                    .iter()
                    .filter(|r| matches!(kind(r), "case" | "fail"))
                    .collect();
                !cases.is_empty() && cases.iter().all(|r| passed(r))
            }
        };
        println!("  heap {heap:>7} B: {}", if good { "pass" } else { "fail" });
        good
    };

    let (mut lo, mut hi) = (0, max_heap / step);
    if !passes(hi * step) {
        die(&format!("fails even with {} B of heap", hi * step));
    }
    while hi - lo > 1 {
        let mid = (lo + hi) / 2;
        if passes(mid * step) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    println!(
        "bench: {}-{} on {}: minimum heap {} B",
        a.workload,
        a.variant,
        a.board,
        hi * step
    );
}

#[cfg(test)]
mod tests {
    #[test]
    fn timestamp_shape() {
        let t = super::utc_now();
        assert_eq!(t.len(), "2026-09-23T08:59:05+00:00".len());
        assert!(t.ends_with("+00:00") && t.as_bytes()[10] == b'T');
    }
}
