#!/usr/bin/env bash
# Regenerate the C of every workload's C variant (workloads/*/certirocq/gen/)
# with CertiRocq. Needs the toolchain of toolchain.sh and `dune build` (for
# the workload theories). The generated C is committed.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
dune build
b="$root/_build/default"
common=(-Q "$b/theories" EncoreBench.Common -Q "$root/certirocq/theories" EncoreBench.CertiRocq)
rocq compile "${common[@]}" certirocq/theories/BenchNat.v
for dir in workloads/*/certirocq; do
  [ -f "$dir/CompileC.v" ] || continue
  w="$(basename "$(dirname "$dir")")"
  theory="$(sed -n 's/^ *(name \(EncoreBench\.[A-Za-z0-9]*\)).*/\1/p' "workloads/$w/theories/dune")"
  echo "== $w ($theory)"
  rm -rf "$dir/gen" && mkdir -p "$dir/gen"
  (cd "$dir/gen" && rocq compile "${common[@]}" -Q "$b/workloads/$w/theories" "$theory" ../CompileC.v)
  rm -f "$dir"/CompileC.vo* "$dir"/CompileC.glob "$dir"/.CompileC.aux
done
