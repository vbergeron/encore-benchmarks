#!/usr/bin/env bash
# The Rocq side of the benchmarks in Docker, from the repository root:
#
#   docker/rocq.sh [check]           check the proofs, and that the committed
#                                    .scm are what extraction produces (as CI)
#   docker/rocq.sh promote           same, and write the re-extracted .scm
#   docker/rocq.sh certirocq [w ...] regenerate the C of variant C
#   docker/rocq.sh certirocq-check [w ...]
#                                    fail if a committed gen/ is not what
#                                    CertiRocq produces (as CI)
#   docker/rocq.sh shell             a shell with Rocq, on a copy of the tree
#
# Extra arguments of check and promote go to `dune build`.
#
# The image is pulled from ghcr.io/vbergeron/encore-benchmarks-<target>,
# tagged with docker/image-tag.sh (published by the certirocq-image
# workflow), and built locally only when no image is published for the
# current Dockerfile and toolchain; ROCQ_BUILD=1 always builds it locally.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cmd="${1:-check}"
target=rocq
case "$cmd" in certirocq | certirocq-check) target=certirocq ;; esac
image="encore-benchmarks-$target"
remote="${ROCQ_REGISTRY:-ghcr.io/vbergeron}/$image:$("$root/docker/image-tag.sh")"
if [ "${ROCQ_BUILD:-0}" != 1 ] &&
  { docker image inspect "$remote" >/dev/null 2>&1 || docker pull "$remote" >&2; }; then
  docker tag "$remote" "$image"
else
  [ "${ROCQ_BUILD:-0}" = 1 ] || echo "rocq.sh: $remote is not published, building $image" >&2
  docker build --target "$target" -t "$image" -f "$root/docker/Dockerfile" "$root" >&2
fi
mode=ro
case "$cmd" in promote | certirocq) mode=rw ;; esac
tty=()
[ -t 0 ] && [ -t 1 ] && tty=(-it)
exec docker run --rm "${tty[@]}" --user "$(id -u):$(id -g)" -e HOME=/tmp \
  -v "$root:/src:$mode" "$image" "${@:-check}"
