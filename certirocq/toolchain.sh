#!/usr/bin/env bash
# Build CertiRocq v0.9.1+9.1 and its dependencies from source, for the C
# variant. Needed only to regenerate workloads/*/certirocq/gen/ (the C is
# committed, so building firmware needs gcc-arm-none-eabi only).
#
# Prerequisites: Rocq 9.1 and Stdlib 9.1 installed (rocq-runtime, rocq-core,
# rocq-stdlib, plus the coq-core / coq-stdlib compatibility packages, which
# provide coqc and coq_makefile), dune >= 3.21, OCaml >= 4.14 with findlib,
# zarith, menhir, ppx_optcomp and stdlib-shims, and libgmp headers. With
# opam, `opam install rocq-certirocq` is the normal route; this script is
# for machines where opam's repository is not reachable.
#
# Two deviations from the released packages, both outside the C path:
#   - CompCert 3.17's bundled Flocq uses `Zmod`, which Stdlib 9.1 removed:
#     it is renamed to `Z.modulo`.
#   - CertiRocq's Wasm backend needs coq-wasm (and mathcomp, parseque, ...);
#     certirocq-no-wasm.patch removes it. The Clight backend, the one the
#     C variant uses, is untouched.
#
# CompCert is configured for arm-eabi, so that CertiRocq generates C for
# 32-bit words (it reads Archi.ptr64), and with -ignore-coq-version: its
# configure accepts Rocq up to 9.1 but not 9.1.1, which rocq-prover:9.1
# now ships.
set -euxo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
work="${1:-$PWD/certirocq-toolchain}"
mkdir -p "$work"
cd "$work"
coqlib="$(rocq c -where)"

clone() { [ -d "$2" ] || git clone -q --depth 1 -b "$3" "https://github.com/$1" "$2"; }

clone coq-community/coq-ext-lib ext-lib v0.13.1
(cd ext-lib && make -j"$(nproc)" theories && make install)

clone mattam82/Coq-Equations equations v1.3.1-9.1
(cd equations && ./configure.sh && make -j"$(nproc)" \
  && dune install rocq-equations --prefix "$(dirname "$(dirname "$(command -v rocq)")")")

clone MetaRocq/metarocq metarocq v1.5.1-9.1
(cd metarocq && ./configure.sh local \
  && make -j"$(nproc)" template-rocq pcuic safechecker erasure erasure-plugin safechecker-plugin \
  && for d in utils common template-rocq pcuic safechecker template-pcuic erasure \
              safechecker-plugin erasure-plugin; do make -C "$d" install; done)

clone AbsInt/CompCert compcert v3.17
(cd compcert \
  && { grep -rlP "\bZmod\b(?![_'])" --include=*.v . || true; } | xargs -r perl -pi -e "s/\bZmod\b(?![_'])/Z.modulo/g" \
  && ./configure -ignore-coq-version -clightgen arm-eabi && make depend && make -j"$(nproc)" proof \
  && for d in lib common arm backend cfrontend driver cparser export; do \
       install -d "$coqlib/user-contrib/compcert/$d"; \
       install -m 0644 "$d"/*.v "$d"/*.vo "$d"/*.glob "$coqlib/user-contrib/compcert/$d/"; \
     done \
  && for d in Core Prop Calc IEEE754; do \
       install -d "$coqlib/user-contrib/Flocq/$d"; \
       install -m 0644 flocq/"$d"/*.v flocq/"$d"/*.vo flocq/"$d"/*.glob "$coqlib/user-contrib/Flocq/$d/"; \
     done \
  && install -d "$coqlib/user-contrib/MenhirLib" \
  && install -m 0644 MenhirLib/*.v MenhirLib/*.vo MenhirLib/*.glob "$coqlib/user-contrib/MenhirLib/")

clone CertiCoq/certicoq certirocq v0.9.1+9.1
(cd certirocq && git apply "$here/certirocq-no-wasm.patch" \
  && make -j"$(nproc)" all && make plugin \
  && make -C libraries install && make -C theories install && make -C plugin install)
