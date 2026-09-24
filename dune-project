(lang dune 3.21)
(using rocq 0.11)
(name encore-benchmarks)

(generate_opam_files true)

; Proofs and extraction of every workload. `opam install --deps-only .`
; installs the pinned Rocq, and rocq-encore (Encore's extraction theory,
; Encore.Extraction) from the Encore commit named in
; encore-benchmarks.opam.template, the same one as Cargo.toml.
(package
 (name encore-benchmarks)
 (synopsis "Rocq side of the Encore benchmarks: workload proofs and extraction")
 (allow_empty)
 (depends
  (dune (>= 3.21))
  (rocq-core (and (>= 9.1) (< 9.2)))
  (rocq-stdlib (and (>= 9.1) (< 9.2)))
  (rocq-encore (= 0.1.6))))
