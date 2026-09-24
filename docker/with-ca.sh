#!/usr/bin/env bash
# Run a command that downloads, trusting the extra CA of the build secret
# extra_ca (see the certirocq stage of the Dockerfile) on top of the system
# ones: curl (opam's downloader) and git read the bundle from these
# variables. Without the secret, the command runs as is.
set -euo pipefail
extra=/run/secrets/extra_ca
if [ -s "$extra" ]; then
  bundle="$(mktemp)"
  cat /etc/ssl/certs/ca-certificates.crt "$extra" >"$bundle"
  export CURL_CA_BUNDLE="$bundle" GIT_SSL_CAINFO="$bundle" SSL_CERT_FILE="$bundle"
fi
exec "$@"
