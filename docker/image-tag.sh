#!/usr/bin/env bash
# The tag of the published images of docker/Dockerfile: a hash of the files
# that go into them. The certirocq-image workflow publishes
# ghcr.io/vbergeron/encore-benchmarks-{rocq,certirocq}:<tag>, and
# docker/rocq.sh pulls the image of the current tag instead of building it.
set -euo pipefail
cd "$(dirname "$0")/.."
sha256sum docker/Dockerfile docker/entrypoint.sh \
  certirocq/toolchain.sh certirocq/certirocq-no-wasm.patch |
  sha256sum | cut -c1-16
