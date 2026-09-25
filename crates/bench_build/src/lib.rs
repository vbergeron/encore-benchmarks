//! Build-script helper shared by every benchmark firmware.
//!
//! A firmware's `build.rs` calls [`configure`], which:
//!
//! - reads the board description from `boards/<BENCH_BOARD>.toml`;
//! - writes a `memory.x` whose RAM and flash lengths are the **budget**
//!   (`BENCH_RAM_KB`, `BENCH_FLASH_KB`), not the board's physical size, so a
//!   workload that does not fit fails at link time;
//! - writes `bench_config.rs` into `OUT_DIR` with the build parameters the
//!   firmware needs as constants (include it with
//!   `include!(concat!(env!("OUT_DIR"), "/bench_config.rs"))`).
//!
//! With the `encore` feature, [`encore::compile_scheme`] also turns a
//! Rocq-extracted `.scm` file into bytecode for `encore_vm::encore_program!`.
//! With the `certirocq` feature, [`certirocq::compile_c`] compiles the
//! CertiRocq-generated C of a workload and the runtime in `certirocq/`.
//!
//! Every parameter comes from an environment variable so that
//! `cargo xtask` can sweep them without editing files:
//!
//! | Variable | Default | Meaning |
//! |---|---|---|
//! | `BENCH_BOARD` | `qemu-lm3s6965` | board file in `boards/` |
//! | `BENCH_RAM_KB` | `50` | RAM budget given to the linker |
//! | `BENCH_FLASH_KB` | `256` | flash budget given to the linker |
//! | `BENCH_HEAP_BYTES` | workload default | Encore heap size |
//! | `BENCH_REPS` | `1` on QEMU, `1000` on boards | timed runs per case |
//! | `BENCH_CPS_OPTIMIZE` | `on` | `off` compiles Encore without the CPS optimizer |
//! | `BENCH_C_LOG_NURSERY` | `10` | CertiRocq nursery of 2^n words (C variant) |

use std::env;
use std::fmt::Write as _;
use std::fs;
use std::path::{Path, PathBuf};

const DEFAULT_BOARD: &str = "qemu-lm3s6965";
const DEFAULT_RAM_KB: u32 = 50;
const DEFAULT_FLASH_KB: u32 = 256;

/// A board description, as read from `boards/<name>.toml`.
#[derive(Debug, Clone)]
pub struct Board {
    pub name: String,
    pub core: String,
    pub target: String,
    pub flash_origin: u64,
    pub flash_kb: u32,
    pub ram_origin: u64,
    pub ram_kb: u32,
    /// `true` when the DWT cycle counter can be trusted on this board.
    pub dwt: bool,
    /// How the host runs the firmware: `qemu` or `probe-rs`.
    pub runner: String,
    /// QEMU `-machine` and `-cpu`, for the `qemu` runner.
    pub qemu_machine: Option<String>,
    pub qemu_cpu: Option<String>,
    /// probe-rs `--chip`, for the `probe-rs` runner.
    pub chip: Option<String>,
    /// Nanoseconds per SysTick tick (core clock source), for boards without
    /// a DWT. Times the Encore VM's GC with SysTick in the memory profile.
    pub systick_ns_per_tick: Option<u32>,
}

impl Board {
    /// The clock given to `encore_vm` in the memory profile, as
    /// `(source, scale, unit)`: `dwt` counts cycles; `systick` counts ticks
    /// times `scale` ns, which the `qemu` runner turns into instructions
    /// (`-icount shift=0`: 1 ns per instruction); `none` leaves times at 0.
    pub fn vm_clock(&self) -> (&'static str, u32, &'static str) {
        match (self.dwt, self.systick_ns_per_tick) {
            (true, _) => ("dwt", 1, "cycles"),
            (false, Some(ns)) if self.runner == "qemu" => ("systick", ns, "insns"),
            (false, Some(ns)) => ("systick", ns, "ns"),
            (false, None) => ("none", 0, "none"),
        }
    }

    pub fn load(repo_root: &Path, name: &str) -> Board {
        let path = repo_root.join("boards").join(format!("{name}.toml"));
        let text = fs::read_to_string(&path)
            .unwrap_or_else(|e| panic!("cannot read board file {}: {e}", path.display()));
        let t: toml::Table = text
            .parse()
            .unwrap_or_else(|e| panic!("invalid board file {}: {e}", path.display()));
        let int = |k: &str| {
            t.get(k)
                .and_then(toml::Value::as_integer)
                .unwrap_or_else(|| panic!("{}: missing integer `{k}`", path.display()))
        };
        let opt = |k: &str| t.get(k).and_then(toml::Value::as_str).map(str::to_owned);
        let string =
            |k: &str| opt(k).unwrap_or_else(|| panic!("{}: missing string `{k}`", path.display()));
        Board {
            name: name.to_owned(),
            core: string("core"),
            target: string("target"),
            flash_origin: int("flash_origin") as u64,
            flash_kb: int("flash_kb") as u32,
            ram_origin: int("ram_origin") as u64,
            ram_kb: int("ram_kb") as u32,
            dwt: string("cycles") == "dwt",
            runner: string("runner"),
            qemu_machine: opt("qemu_machine"),
            qemu_cpu: opt("qemu_cpu"),
            chip: opt("chip"),
            systick_ns_per_tick: t
                .get("systick_ns_per_tick")
                .and_then(toml::Value::as_integer)
                .map(|n| n as u32),
        }
    }
}

/// The resolved build parameters of one firmware build.
#[derive(Debug, Clone)]
pub struct Config {
    pub board: Board,
    pub ram_kb: u32,
    pub flash_kb: u32,
    pub heap_bytes: usize,
    pub reps: u32,
    pub cps_optimize: bool,
    /// CertiRocq nursery size, log2 of words (C variant only).
    pub c_log_nursery: u32,
}

/// Configure a benchmark firmware build. Call once from `build.rs`.
///
/// `default_heap_bytes` is the Encore heap size when `BENCH_HEAP_BYTES` is
/// unset; variants without a heap pass `0`.
pub fn configure(default_heap_bytes: usize) -> Config {
    let root = repo_root();
    let out = out_dir();

    for var in [
        "BENCH_BOARD",
        "BENCH_RAM_KB",
        "BENCH_FLASH_KB",
        "BENCH_HEAP_BYTES",
        "BENCH_REPS",
        "BENCH_CPS_OPTIMIZE",
        "BENCH_C_LOG_NURSERY",
    ] {
        println!("cargo::rerun-if-env-changed={var}");
    }

    let board_name = env::var("BENCH_BOARD").unwrap_or_else(|_| DEFAULT_BOARD.to_owned());
    let board_file = root.join("boards").join(format!("{board_name}.toml"));
    println!("cargo::rerun-if-changed={}", board_file.display());
    let board = Board::load(&root, &board_name);

    let target = env::var("TARGET").unwrap_or_default();
    if target != board.target {
        panic!(
            "board `{}` needs --target {}, but this build targets `{target}`",
            board.name, board.target
        );
    }

    let ram_kb = env_num("BENCH_RAM_KB", DEFAULT_RAM_KB);
    let flash_kb = env_num("BENCH_FLASH_KB", DEFAULT_FLASH_KB);
    assert!(ram_kb <= board.ram_kb, "RAM budget {ram_kb} KiB exceeds board RAM");
    assert!(flash_kb <= board.flash_kb, "flash budget {flash_kb} KiB exceeds board flash");

    let config = Config {
        heap_bytes: env_num("BENCH_HEAP_BYTES", default_heap_bytes),
        reps: env_num("BENCH_REPS", if board.dwt { 1000 } else { 1 }),
        cps_optimize: env::var("BENCH_CPS_OPTIMIZE").map_or(true, |v| v != "off"),
        c_log_nursery: env_num("BENCH_C_LOG_NURSERY", 10),
        board,
        ram_kb,
        flash_kb,
    };

    write_memory_x(&out, &config);
    write_bench_config(&out, &config);
    config
}

fn write_memory_x(out: &Path, c: &Config) {
    let memory_x = format!(
        "/* Generated by bench_build for board `{}`: budget, not physical size. */\n\
         MEMORY {{\n  \
           FLASH : ORIGIN = {:#010x}, LENGTH = {}K\n  \
           RAM   : ORIGIN = {:#010x}, LENGTH = {}K\n\
         }}\n",
        c.board.name, c.board.flash_origin, c.flash_kb, c.board.ram_origin, c.ram_kb,
    );
    fs::write(out.join("memory.x"), memory_x).expect("write memory.x");
    println!("cargo::rustc-link-search={}", out.display());
}

fn write_bench_config(out: &Path, c: &Config) {
    let mut s = String::from("// Generated by bench_build. Do not edit.\n");
    let _ = writeln!(s, "#[allow(dead_code)] pub const BOARD: &str = {:?};", c.board.name);
    let _ = writeln!(s, "#[allow(dead_code)] pub const RAM_KB: u32 = {};", c.ram_kb);
    let _ = writeln!(s, "#[allow(dead_code)] pub const FLASH_KB: u32 = {};", c.flash_kb);
    let _ = writeln!(s, "#[allow(dead_code)] pub const HEAP_BYTES: usize = {};", c.heap_bytes);
    let _ = writeln!(s, "#[allow(dead_code)] pub const REPS: usize = {};", c.reps.max(1));
    let _ = writeln!(s, "#[allow(dead_code)] pub const DWT: bool = {};", c.board.dwt);
    let _ = writeln!(s, "#[allow(dead_code)] pub const CPS_OPTIMIZE: bool = {};", c.cps_optimize);
    let (clock, scale, unit) = c.board.vm_clock();
    let _ = writeln!(s, "#[allow(dead_code)] pub const VM_CLOCK: &str = {clock:?};");
    let _ = writeln!(s, "#[allow(dead_code)] pub const VM_CLOCK_SCALE: u32 = {scale};");
    let _ = writeln!(s, "#[allow(dead_code)] pub const VM_CLOCK_UNIT: &str = {unit:?};");
    fs::write(out.join("bench_config.rs"), s).expect("write bench_config.rs");
}

fn env_num<T: std::str::FromStr>(var: &str, default: T) -> T {
    match env::var(var) {
        Ok(v) => v
            .trim()
            .parse()
            .unwrap_or_else(|_| panic!("{var}={v:?} is not a number")),
        Err(_) => default,
    }
}

fn out_dir() -> PathBuf {
    PathBuf::from(env::var("OUT_DIR").expect("bench_build must run from a build script"))
}

/// The repository root: the closest ancestor of the calling crate that holds
/// `dune-project` and `boards/`.
pub fn repo_root() -> PathBuf {
    let manifest = PathBuf::from(env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR"));
    manifest
        .ancestors()
        .find(|p| p.join("dune-project").is_file() && p.join("boards").is_dir())
        .expect("cannot find the encore-benchmarks root above CARGO_MANIFEST_DIR")
        .to_path_buf()
}

#[cfg(feature = "encore")]
pub mod encore {
    //! Compile the E variant's Scheme into Encore bytecode.

    use super::{out_dir, Config};
    use encore_compiler::pass::cps_optimize::OptimizeConfig;
    use std::fmt::Write as _;
    use std::fs;
    use std::path::Path;

    /// Compile `scm` (a Rocq-extracted Scheme file, usually promoted by dune)
    /// into `OUT_DIR/bytecode.bin` and `OUT_DIR/bindings.rs`, the files
    /// `encore_vm::encore_program!(env!("OUT_DIR"))` includes.
    ///
    /// Also appends `PROGRAM_BYTES` (the bytecode size) to `bench_config.rs`,
    /// so the firmware can report the runtime / program flash split.
    pub fn compile_scheme(scm: &Path, config: &Config) {
        println!("cargo::rerun-if-changed={}", scm.display());
        let src = fs::read_to_string(scm)
            .unwrap_or_else(|e| panic!("cannot read {}: {e}", scm.display()));
        let (module, ctor_names) = encore_scheme::parse_with_metadata(&src);
        let optimize = config.cps_optimize.then(OptimizeConfig::default);
        let out = out_dir();
        encore_compiler::pipeline::compile_to_dir_with_ctors(
            &module,
            optimize,
            true,
            &out,
            &ctor_names,
        )
        .expect("encore compile");

        let len = fs::metadata(out.join("bytecode.bin")).expect("bytecode.bin").len();
        let cfg_path = out.join("bench_config.rs");
        let mut cfg = fs::read_to_string(&cfg_path).expect("bench_config.rs");
        let _ = writeln!(cfg, "pub const PROGRAM_BYTES: usize = {len};");
        fs::write(cfg_path, cfg).expect("write bench_config.rs");
    }
}

#[cfg(feature = "certirocq")]
pub mod certirocq {
    //! Compile the C variant: CertiRocq-generated C plus the runtime.

    use super::{out_dir, repo_root, Config};
    use std::fmt::Write as _;
    use std::fs;
    use std::path::Path;

    /// Compile every `.c` file of `gen_dir` (promoted by `dune build
    /// @certirocq`) with the vendored CertiRocq runtime and `bench_rt.c`
    /// (`certirocq/runtime/`), with the plan's `-Os`, for the board's
    /// target. The arena is `config.heap_bytes`.
    ///
    /// Also appends `C_LOG_NURSERY` to `bench_config.rs`.
    pub fn compile_c(gen_dir: &Path, config: &Config) {
        let rt = repo_root().join("certirocq").join("runtime");
        println!("cargo::rerun-if-changed={}", rt.display());
        println!("cargo::rerun-if-changed={}", gen_dir.display());

        let mut sources: Vec<_> = fs::read_dir(gen_dir)
            .unwrap_or_else(|e| panic!("cannot read {}: {e}", gen_dir.display()))
            .map(|e| e.expect("dir entry").path())
            .filter(|p| p.extension().is_some_and(|x| x == "c"))
            .collect();
        sources.sort();
        assert!(!sources.is_empty(), "no generated C in {}", gen_dir.display());

        cc::Build::new()
            .files(&sources)
            .file(rt.join("gc_stack.c"))
            .file(rt.join("bench_rt.c"))
            // The shims come first: they stand in for the libc headers.
            .include(rt.join("shim"))
            .include(&rt)
            .include(gen_dir)
            .define("BENCH_ARENA_BYTES", config.heap_bytes.to_string().as_str())
            .define("LOG_NURSERY_SIZE", config.c_log_nursery.to_string().as_str())
            .opt_level_str("s")
            .flag("-std=gnu11")
            .flag("-ffreestanding")
            .flag("-ffunction-sections")
            .flag("-fdata-sections")
            .warnings(false)
            .compile("certirocq_program");

        let cfg_path = out_dir().join("bench_config.rs");
        let mut cfg = fs::read_to_string(&cfg_path).expect("bench_config.rs");
        let _ = writeln!(cfg, "pub const C_LOG_NURSERY: u32 = {};", config.c_log_nursery);
        fs::write(cfg_path, cfg).expect("write bench_config.rs");
    }
}
