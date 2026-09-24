#!/usr/bin/env bash
# Entry point of the images of docker/Dockerfile. The checkout is mounted
# at /src; everything is built in a copy of it, and only `promote` and
# `certirocq` write back into it. Usually called through docker/rocq.sh.
#
#   check [dune args]      proofs and extraction; fails if a committed .scm
#                          differs from the re-extracted one
#   promote [dune args]    same, and write the re-extracted .scm back
#   certirocq [w ...]      regenerate workloads/<w>/certirocq/gen/ (all by
#                          default) and write it back; certirocq image only
#   shell                  a shell in the copy
set -euo pipefail
cmd="${1:-check}"
shift || true
src=/src
[ -f "$src/dune-project" ] || { echo "bench-rocq: mount the repository at $src" >&2; exit 2; }
work="$(mktemp -d)"
tar -C "$src" --exclude=./target --exclude=./_build --exclude=./.git -cf - . | tar -C "$work" -xf -
cd "$work"

# Promoted files of the copy that differ from the checkout's.
stale_scm() {
  local f
  for f in workloads/*/theories/*.scm; do
    cmp -s "$f" "$src/$f" || echo "$f"
  done
}

case "$cmd" in
  check)
    rocq --version | head -1
    dune build "$@"
    stale="$(stale_scm)"
    if [ -n "$stale" ]; then
      printf 'out of date (docker/rocq.sh promote):\n%s\n' "$stale" >&2
      exit 1
    fi
    echo "proofs checked, extracted Scheme up to date"
    ;;
  promote)
    dune build "$@"
    for f in $(stale_scm); do cp "$f" "$src/$f" && echo "promoted $f"; done
    ;;
  certirocq)
    [ -d "$(rocq c -where)/user-contrib/CertiRocq" ] ||
      { echo "bench-rocq: CertiRocq is only in the certirocq image" >&2; exit 2; }
    certirocq/generate.sh "$@"
    for d in workloads/*/certirocq/gen; do
      if ! diff -rq "$d" "$src/$d" >/dev/null 2>&1; then
        rm -rf "${src:?}/$d" && cp -r "$d" "$src/$d" && echo "regenerated $d"
      fi
    done
    ;;
  shell)
    exec bash "$@"
    ;;
  *)
    echo "bench-rocq: unknown command $cmd (check, promote, certirocq, shell)" >&2
    exit 2
    ;;
esac
