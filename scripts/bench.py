#!/usr/bin/env python3
"""Build, run and record encore-benchmarks firmware.

    scripts/bench.py run   -w w0_smoke -v e -b qemu-lm3s6965
    scripts/bench.py check
    scripts/bench.py minheap -w w0_smoke -v e
    scripts/bench.py size target/thumbv7m-none-eabi/release/w0_smoke-e

`run` builds `<workload>-<variant>` for the board's target with the budget
and parameters passed as BENCH_* variables (see crates/bench_build), runs it,
reads the `@@BENCH` records it prints, adds what only the host knows (commit,
toolchain, ELF sizes, and on QEMU the instruction count of every region) and
appends one row per case to results/benchmarks.jsonl.

Standard library only (Python >= 3.11 for tomllib).
"""

from __future__ import annotations

import argparse
import datetime as dt
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RESULTS = ROOT / "results" / "benchmarks.jsonl"
PREFIX = "@@BENCH "
SCHEMA = 1
ORACLE_VARIANT = "R"


def die(msg: str) -> None:
    print(f"bench: {msg}", file=sys.stderr)
    sys.exit(1)


def sh(cmd: list[str], **kw) -> str:
    return subprocess.run(cmd, check=True, capture_output=True, text=True, **kw).stdout.strip()


def tool(*names: str) -> str:
    for n in names:
        if shutil.which(n):
            return n
    die(f"none of {', '.join(names)} found in PATH")
    return ""


# ── Boards and packages ─────────────────────────────────────────────────────


def load_board(name: str) -> dict:
    path = ROOT / "boards" / f"{name}.toml"
    if not path.is_file():
        known = ", ".join(sorted(p.stem for p in (ROOT / "boards").glob("*.toml")))
        die(f"unknown board {name!r} (known: {known})")
    with path.open("rb") as f:
        board = tomllib.load(f)
    board["name"] = name
    return board


def package_dir(pkg: str) -> Path:
    for manifest in ROOT.glob("workloads/*/*/Cargo.toml"):
        text = manifest.read_text()
        if re.search(rf'^name\s*=\s*"{re.escape(pkg)}"', text, re.M):
            return manifest.parent
    die(f"no firmware package named {pkg!r} under workloads/")
    return ROOT


def has_feature(pkg_dir: Path, feature: str) -> bool:
    with (pkg_dir / "Cargo.toml").open("rb") as f:
        return feature in tomllib.load(f).get("features", {})


# ── Build ───────────────────────────────────────────────────────────────────


def build(pkg: str, board: dict, params: dict[str, str], features: list[str]) -> Path:
    env = dict(os.environ, BENCH_BOARD=board["name"], **params)
    cmd = ["cargo", "build", "--release", "--target", board["target"], "-p", pkg]
    if features:
        cmd += ["--features", ",".join(features)]
    r = subprocess.run(cmd, cwd=ROOT, env=env, capture_output=True, text=True)
    if r.returncode != 0:
        # A link failure against the RAM/flash budget is a result (Q1), not a
        # crash: surface it clearly.
        overflow = re.search(r"region `(RAM|FLASH)' overflowed by (\d+) bytes", r.stderr)
        if overflow:
            raise BudgetError(overflow.group(1), int(overflow.group(2)))
        sys.stderr.write(r.stderr)
        die(f"build of {pkg} failed")
    return ROOT / "target" / board["target"] / "release" / pkg


class BudgetError(Exception):
    def __init__(self, region: str, over: int):
        super().__init__(f"{region} budget exceeded by {over} bytes")
        self.region, self.over = region, over


# ── Run ─────────────────────────────────────────────────────────────────────


def symbol_addr(elf: Path, name: str) -> int | None:
    nm = tool("arm-none-eabi-nm", "llvm-nm", "rust-nm")
    for line in sh([nm, str(elf)]).splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[2] == name:
            return int(parts[0], 16) & ~1
    return None


class RegionCounter:
    """Count guest instructions between region markers in a QEMU trace.

    QEMU (-d in_asm,exec,nochain) logs every translation block (TB) once when
    it is translated (`IN:` + `OBJD-T: <hex bytes>`) and every execution of a
    TB (`Trace N: <host> [<flags>/<guest pc>/...]`). With chaining disabled
    every execution is logged, so summing the instruction counts of the TBs
    executed between the TB starting at `bench_region_begin` and the one
    starting at `bench_region_end` gives the instructions of the region.
    """

    TRACE = re.compile(r"^Trace \d+: (0x[0-9a-f]+) \[[0-9a-f]+/([0-9a-f]+)/")

    def __init__(self, begin: int, end: int):
        self.begin, self.end = begin, end
        self.tb_insns: dict[str, int] = {}
        self.pending: int | None = None
        self.current: int | None = None
        self.regions: list[int] = []
        self.total = 0

    @staticmethod
    def thumb_insns(hexbytes: str) -> int:
        raw = bytes.fromhex(hexbytes)
        n = i = 0
        while i + 1 < len(raw):
            hw = raw[i] | (raw[i + 1] << 8)
            i += 4 if (hw & 0xE000) == 0xE000 and (hw & 0x1800) != 0 else 2
            n += 1
        return n

    def feed(self, line: str) -> None:
        if line.startswith("OBJD-T: "):
            self.pending = (self.pending or 0) + self.thumb_insns(line[8:].strip())
            return
        m = self.TRACE.match(line)
        if not m:
            return
        host, pc = m.group(1), int(m.group(2), 16)
        if self.pending is not None:
            # First execution after a translation: (re)bind this host address.
            self.tb_insns[host] = self.pending
            self.pending = None
        n = self.tb_insns.get(host, 0)
        self.total += n
        if pc == self.begin:
            self.current = 0
        elif pc == self.end:
            if self.current is not None:
                self.regions.append(self.current)
            self.current = None
        elif self.current is not None:
            self.current += n


def run_qemu(elf: Path, board: dict, count_regions: bool, timeout: int) -> tuple[int, str, list[int]]:
    cmd = [
        tool("qemu-system-arm"),
        "-machine", board["qemu_machine"],
        "-cpu", board["qemu_cpu"],
        "-semihosting-config", "enable=on,target=native",
        "-nographic", "-monitor", "none", "-serial", "none",
        "-kernel", str(elf),
    ]
    if not count_regions:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
        return r.returncode, r.stdout, []

    begin = symbol_addr(elf, "bench_region_begin")
    end = symbol_addr(elf, "bench_region_end")
    if begin is None or end is None:
        die(f"{elf.name}: region markers not found (is bench_harness linked?)")
    counter = RegionCounter(begin, end)
    with tempfile.TemporaryDirectory() as tmp:
        fifo = Path(tmp) / "trace"
        os.mkfifo(fifo)
        cmd += ["-d", "in_asm,exec,nochain", "-D", str(fifo)]
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)

        def pump() -> None:
            with open(fifo, errors="replace") as f:
                for line in f:
                    counter.feed(line)

        reader = threading.Thread(target=pump, daemon=True)
        reader.start()
        try:
            out, _ = proc.communicate(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.kill()
            die(f"{elf.name}: timed out after {timeout}s")
        reader.join()
    return proc.returncode, out, counter.regions


def run_probe(elf: Path, board: dict, timeout: int) -> tuple[int, str, list[int]]:
    # probe-rs forwards semihosting output and exits with the firmware's
    # semihosting exit code. Not yet validated on hardware.
    cmd = [tool("probe-rs"), "run", "--chip", board["chip"], str(elf)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
    return r.returncode, r.stdout, []


def parse_records(stdout: str) -> list[dict]:
    records = []
    for line in stdout.splitlines():
        if line.startswith(PREFIX):
            try:
                records.append(json.loads(line[len(PREFIX):]))
            except json.JSONDecodeError:
                die(f"malformed record: {line!r}")
    return records


def order_stats(xs: list[int]) -> dict:
    s = sorted(xs)
    n = len(s)
    p99 = s[max(1, min(n, -(-99 * n // 100))) - 1]
    return {"min": s[0], "median": s[(n - 1) // 2], "p99": p99, "max": s[-1]}


def attach_insns(records: list[dict], regions: list[int]) -> None:
    """Give each record carrying `regions` its share of the counted regions,
    in order, minus the calibration overhead."""
    expected = sum(r.get("regions", 0) for r in records)
    if expected != len(regions):
        die(f"trace has {len(regions)} regions, records announce {expected}")
    overhead = 0
    i = 0
    for r in records:
        k = r.get("regions", 0)
        mine, i = regions[i:i + k], i + k
        if not k:
            continue
        stats = order_stats([max(0, x - overhead) for x in mine])
        if r["kind"] == "calibration":
            overhead = stats["median"]
            stats = order_stats(mine)
        r["insns"] = stats


# ── Sizes ───────────────────────────────────────────────────────────────────

FLASH_SECTIONS = {".vector_table", ".text", ".rodata", ".data"}
RAM_SECTIONS = {".data", ".bss", ".uninit"}


def size_report(elf: Path) -> dict:
    size = tool("arm-none-eabi-size", "llvm-size", "rust-size")
    sections: dict[str, int] = {}
    for line in sh([size, "-A", str(elf)]).splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[0].startswith(".") and parts[1].isdigit():
            if not parts[0].startswith((".debug", ".comment", ".ARM.attributes")):
                sections[parts[0]] = int(parts[1])

    # Attribution by crate, from demangled symbol names. With LTO, code
    # inlined into a caller counts for the caller's crate: an estimate.
    nm = tool("arm-none-eabi-nm", "llvm-nm", "rust-nm")
    by_crate: dict[str, int] = {}
    ram_symbols: dict[str, int] = {}
    for line in sh([nm, "-S", "-C", "--size-sort", str(elf)]).splitlines():
        parts = line.split(maxsplit=3)
        if len(parts) != 4:
            continue
        _, sz, kind, name = parts
        sz = int(sz, 16)
        crate = crate_of(name)
        if kind in "tTrR":
            by_crate[crate] = by_crate.get(crate, 0) + sz
        elif kind in "bBdD":
            ram_symbols[name] = sz
    return {
        "flash_bytes": sum(v for k, v in sections.items() if k in FLASH_SECTIONS),
        "ram_static_bytes": sum(v for k, v in sections.items() if k in RAM_SECTIONS),
        "sections": sections,
        "flash_by_crate": dict(sorted(by_crate.items(), key=lambda kv: -kv[1])),
        "ram_symbols": dict(sorted(ram_symbols.items(), key=lambda kv: -kv[1])[:8]),
    }


def crate_of(symbol: str) -> str:
    """Crate a demangled symbol belongs to. For `<T as Trait>::f`, the crate
    of `T` when it is a path, else the crate of `Trait` (`<str as
    core::fmt::Display>` is core's)."""
    m = re.match(r"<(.+?) as (.+?)>::", symbol)
    if m:
        self_ty, trait = m.group(1).lstrip("&*").removeprefix("mut "), m.group(2)
        path = self_ty if "::" in self_ty else trait
    else:
        path = symbol.lstrip("<")
    if "::" not in path:
        return "(c/asm)"
    return path.split("::", 1)[0]


# ── Provenance ──────────────────────────────────────────────────────────────


def provenance() -> dict:
    commit = sh(["git", "rev-parse", "HEAD"], cwd=ROOT)
    dirty = bool(sh(["git", "status", "--porcelain", "--untracked-files=no"], cwd=ROOT))
    lock = (ROOT / "Cargo.lock").read_text() if (ROOT / "Cargo.lock").exists() else ""
    m = re.search(r'name = "encore_vm"\nversion = "([^"]+)"', lock)
    return {
        "commit": commit,
        "dirty": dirty,
        "encore_version": m.group(1) if m else None,
        "rustc": sh(["rustc", "--version"], cwd=ROOT),
    }


# ── Commands ────────────────────────────────────────────────────────────────


def build_params(a: argparse.Namespace, heap: int | None = None) -> dict[str, str]:
    p = {"BENCH_RAM_KB": str(a.ram_kb), "BENCH_FLASH_KB": str(a.flash_kb),
         "BENCH_CPS_OPTIMIZE": a.cps_optimize}
    if heap is not None or a.heap_bytes is not None:
        p["BENCH_HEAP_BYTES"] = str(heap if heap is not None else a.heap_bytes)
    if a.reps is not None:
        p["BENCH_REPS"] = str(a.reps)
    return p


def execute(a: argparse.Namespace, heap: int | None = None, quiet: bool = False) -> tuple[list[dict], dict]:
    """Build and run once. Returns the device records and build info."""
    board = load_board(a.board)
    pkg = f"{a.workload}-{a.variant.lower()}"
    pdir = package_dir(pkg)
    features = ["stats"] if a.profile == "memory" and has_feature(pdir, "stats") else []
    params = build_params(a, heap)
    elf = build(pkg, board, params, features)

    if board["runner"] == "qemu":
        # Instructions are counted in the timing profile only: tracing is slow.
        code, out, regions = run_qemu(elf, board, a.profile == "timing", a.timeout)
    elif board["runner"] == "probe-rs":
        code, out, regions = run_probe(elf, board, a.timeout)
    else:
        die(f"unknown runner {board['runner']!r}")
    records = parse_records(out)
    if code != 0:
        sys.stderr.write(out)
        die(f"{pkg} exited with status {code}")
    if regions:
        attach_insns(records, regions)
    if not quiet:
        for r in records:
            print(PREFIX + json.dumps(r))
    info = {"board": board, "package": pkg, "elf": elf, "features": features, "params": params}
    return records, info


def cmd_run(a: argparse.Namespace) -> None:
    try:
        records, info = execute(a)
    except BudgetError as e:
        print(f"bench: {e} — recorded as a failure (Q1)")
        records, info = [{"kind": "fail", "workload": a.workload, "variant": a.variant.upper(),
                          "n": None, "reason": str(e)}], None
    start = next((r for r in records if r["kind"] == "start"), {})
    board = load_board(a.board)
    row_base = {
        "schema": SCHEMA,
        "timestamp": dt.datetime.now(dt.timezone.utc).isoformat(timespec="seconds"),
        "label": a.label,
        **provenance(),
        "workload": a.workload,
        "variant": a.variant.upper(),
        "board": board["name"],
        "core": board["core"],
        "target": board["target"],
        "profile": a.profile,
        "build": {
            "ram_kb": a.ram_kb,
            "flash_kb": a.flash_kb,
            "reps": start.get("reps"),
            "heap_bytes": start.get("heap_bytes"),
            "program_bytes": start.get("program_bytes"),
            "cps_optimize": start.get("cps_optimize"),
            "features": info["features"] if info else [],
        },
        "size": size_report(info["elf"]) if info else None,
    }
    calib = next((r for r in records if r["kind"] == "calibration"), {})
    if calib:
        row_base["calibration"] = {k: calib[k] for k in ("insns", "cycles") if k in calib}

    rows = []
    for r in records:
        if r["kind"] not in ("case", "fail"):
            continue
        row = dict(row_base, n=r.get("n"), ok=r["kind"] == "case")
        row.update({k: v for k, v in r.items() if k not in ("kind", "workload", "variant", "n", "regions")})
        rows.append(row)
    if not rows:
        die("no case records produced")

    if not a.dry_run:
        out = Path(a.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        with out.open("a") as f:
            for row in rows:
                f.write(json.dumps(row, sort_keys=False) + "\n")
        print(f"bench: {len(rows)} rows appended to {out.relative_to(ROOT) if out.is_relative_to(ROOT) else out}")
    report_oracle(rows, Path(a.out))


def latest_rows(path: Path) -> list[dict]:
    if not path.exists():
        return []
    return [json.loads(l) for l in path.read_text().splitlines() if l.strip()]


def oracle_table(rows: list[dict]) -> dict[tuple, str]:
    """(workload, n) -> out_hash of the most recent successful R row."""
    table = {}
    for r in rows:
        if r.get("variant") == ORACLE_VARIANT and r.get("ok"):
            table[(r["workload"], r["n"])] = r["out_hash"]
    return table


def report_oracle(new_rows: list[dict], results: Path) -> bool:
    oracle = oracle_table(latest_rows(results) + new_rows)
    ok = True
    for r in new_rows:
        if not r.get("ok"):
            print(f"  {r['workload']} {r['variant']} n={r['n']}: FAILED ({r.get('reason')})")
            continue
        ref = oracle.get((r["workload"], r["n"]))
        verdict = "no oracle yet" if ref is None else ("ok" if ref == r["out_hash"] else "MISMATCH")
        ok &= verdict != "MISMATCH"
        cost = r.get("insns") or r.get("cycles") or {}
        what = "insns" if "insns" in r else "cycles" if "cycles" in r else ""
        extra = f" {what} median={cost['median']}" if cost else ""
        print(f"  {r['workload']} {r['variant']} n={r['n']}: {verdict}{extra}")
    return ok


def cmd_check(a: argparse.Namespace) -> None:
    rows = latest_rows(Path(a.results))
    oracle = oracle_table(rows)
    latest: dict[tuple, dict] = {}
    for r in rows:
        if r.get("ok"):
            latest[(r["workload"], r["variant"], r["board"], r["n"])] = r
    bad = 0
    for (w, v, b, n), r in sorted(latest.items(), key=lambda kv: str(kv[0])):
        ref = oracle.get((w, n))
        if ref is not None and ref != r["out_hash"]:
            bad += 1
            print(f"MISMATCH {w} {v} {b} n={n}: {r['out_hash']} != oracle {ref}")
    print(f"bench: {len(latest)} latest results checked against the {ORACLE_VARIANT} oracle, {bad} mismatches")
    sys.exit(1 if bad else 0)


def cmd_minheap(a: argparse.Namespace) -> None:
    """Smallest heap (multiple of --step) at which every case still passes."""
    a.profile = "memory"

    def passes(heap: int) -> bool:
        try:
            records, _ = execute(a, heap=heap, quiet=True)
        except BudgetError:
            return False
        cases = [r for r in records if r["kind"] in ("case", "fail")]
        good = bool(cases) and all(r["kind"] == "case" for r in cases)
        print(f"  heap {heap:>7} B: {'pass' if good else 'fail'}")
        return good

    lo, hi = 0, a.max_heap // a.step
    if not passes(hi * a.step):
        die(f"fails even with {hi * a.step} B of heap")
    while hi - lo > 1:
        mid = (lo + hi) // 2
        if passes(mid * a.step):
            hi = mid
        else:
            lo = mid
    print(f"bench: {a.workload}-{a.variant} on {a.board}: minimum heap {hi * a.step} B")


def cmd_size(a: argparse.Namespace) -> None:
    print(json.dumps(size_report(Path(a.elf)), indent=2))


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)

    def target_args(sp: argparse.ArgumentParser) -> None:
        sp.add_argument("-w", "--workload", required=True, help="e.g. w0_smoke")
        sp.add_argument("-v", "--variant", required=True, help="e (Encore), c (CertiRocq), r (Rust), rv (verified Rust)")
        sp.add_argument("-b", "--board", default="qemu-lm3s6965")
        sp.add_argument("--ram-kb", type=int, default=50, help="RAM budget (50 = ST33J2M0, 64 = ST33K1M5)")
        sp.add_argument("--flash-kb", type=int, default=256)
        sp.add_argument("--heap-bytes", type=int, help="Encore heap (default: the workload's)")
        sp.add_argument("--reps", type=int, help="timed runs per case (default: 1 on QEMU, 1000 on boards)")
        sp.add_argument("--cps-optimize", choices=["on", "off"], default="on")
        sp.add_argument("--timeout", type=int, default=600, help="seconds")

    r = sub.add_parser("run", help="build, run and record one workload variant")
    target_args(r)
    r.add_argument("--profile", choices=["timing", "memory"], default="timing",
                   help="timing: instruction/cycle counts, no stats; memory: VM stats on (heap peak, ops)")
    r.add_argument("--label", default="", help="free-form tag stored with the rows")
    r.add_argument("--out", default=str(RESULTS))
    r.add_argument("--dry-run", action="store_true", help="do not append to the results file")
    r.set_defaults(func=cmd_run)

    c = sub.add_parser("check", help="compare every variant's latest out_hash with the R oracle")
    c.add_argument("--results", default=str(RESULTS))
    c.set_defaults(func=cmd_check)

    m = sub.add_parser("minheap", help="binary-search the smallest Encore heap that passes all cases")
    target_args(m)
    m.add_argument("--step", type=int, default=256)
    m.add_argument("--max-heap", type=int, default=40 * 1024)
    m.set_defaults(func=cmd_minheap)

    s = sub.add_parser("size", help="flash/RAM breakdown of an ELF")
    s.add_argument("elf")
    s.set_defaults(func=cmd_size)

    a = p.parse_args()
    a.func(a)


if __name__ == "__main__":
    main()
