#!/usr/bin/env bash
# Regenerate the C of the workloads' C variants (workloads/*/certirocq/gen/)
# with CertiRocq: every workload, or the ones named on the command line
# (`generate.sh w1_apdu w2_rlp`). Needs the toolchain of toolchain.sh and
# `dune build` (for the workload theories). The generated C is committed.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
dune build
b="$root/_build/default"
common=(-Q "$b/vendor/encore-extraction" Encore.Extraction -Q "$root/certirocq/theories" EncoreBench.CertiRocq)
rocq compile "${common[@]}" certirocq/theories/BenchNat.v
if [ $# -gt 0 ]; then dirs=("${@/#/workloads/}"); dirs=("${dirs[@]/%//certirocq}"); else dirs=(workloads/*/certirocq); fi
for dir in "${dirs[@]}"; do
  [ -f "$dir/CompileC.v" ] || { [ $# -eq 0 ] && continue; echo "no $dir/CompileC.v" >&2; exit 1; }
  w="$(basename "$(dirname "$dir")")"
  theory="$(sed -n 's/^ *(name \(EncoreBench\.[A-Za-z0-9]*\)).*/\1/p' "workloads/$w/theories/dune")"
  echo "== $w ($theory)"
  rm -rf "$dir/gen" && mkdir -p "$dir/gen"
  (cd "$dir/gen" && rocq compile "${common[@]}" -Q "$b/workloads/$w/theories" "$theory" ../CompileC.v)
  rm -f "$dir"/CompileC.vo* "$dir"/CompileC.glob "$dir"/.CompileC.aux
done
