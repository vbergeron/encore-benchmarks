#!/usr/bin/env bash
# The Rocq side of the benchmarks in Docker, from the repository root:
#
#   docker/rocq.sh [check]           check the proofs, and that the committed
#                                    .scm are what extraction produces (as CI)
#   docker/rocq.sh promote           same, and write the re-extracted .scm
#   docker/rocq.sh certirocq [w ...] regenerate the C of variant C (builds
#                                    CertiRocq into the image the first time)
#   docker/rocq.sh shell             a shell with Rocq, on a copy of the tree
#
# Extra arguments of check and promote go to `dune build`.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cmd="${1:-check}"
target=rocq
[ "$cmd" = certirocq ] && target=certirocq
image="encore-benchmarks-$target"
# A CA to trust while the image downloads (a TLS-intercepting proxy's).
ca="${BENCH_EXTRA_CA:-${SSL_CERT_FILE:-}}"
secret=()
[ -n "$ca" ] && [ -f "$ca" ] && secret=(--secret "id=extra_ca,src=$ca")
docker build "${secret[@]}" --target "$target" -t "$image" -f "$root/docker/Dockerfile" "$root" >&2
mode=ro
case "$cmd" in promote | certirocq) mode=rw ;; esac
tty=()
[ -t 0 ] && [ -t 1 ] && tty=(-it)
exec docker run --rm "${tty[@]}" --user "$(id -u):$(id -g)" -e HOME=/tmp \
  -v "$root:/src:$mode" "$image" "${@:-check}"
