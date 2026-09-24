# syntax=docker/dockerfile:1
# The Rocq side of the benchmarks without a local opam switch. Run it
# through docker/rocq.sh; see docker/README.md.

# Rocq 9.1 and dune: the image the CI's Rocq job uses. Enough to check the
# proofs and re-extract the Scheme.
FROM rocq/rocq-prover:9.1 AS rocq
# The switch on PATH, so that the image also runs as another user:
# docker/rocq.sh runs it as the caller, so that the files it writes into
# the checkout belong to them.
ENV PATH=/home/rocq/.opam/${COMPILER}/bin:${PATH}
COPY --chmod=0755 docker/entrypoint.sh /usr/local/bin/bench-rocq
ENTRYPOINT ["bench-rocq"]
CMD ["check"]

# Plus CertiRocq 0.9.1, built from source by certirocq/toolchain.sh, to
# regenerate the C of variant C (workloads/*/certirocq/gen/).
FROM rocq AS certirocq
RUN opam install -y coq-core coq-stdlib stdlib-shims menhir ppx_optcomp \
 && opam clean -a -c -s --logs
COPY certirocq/toolchain.sh certirocq/certirocq-no-wasm.patch /tmp/certirocq/
RUN opam exec -- bash /tmp/certirocq/toolchain.sh /tmp/certirocq/build \
 && rm -rf /tmp/certirocq
