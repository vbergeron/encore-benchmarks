(lang dune 3.8)
(using coq 0.8)
(name encore-benchmarks)

(generate_opam_files true)

; Proofs and extraction of every workload. `opam install --deps-only .`
; installs the pinned Rocq.
(package
 (name encore-benchmarks)
 (synopsis "Rocq side of the Encore benchmarks: workload proofs and extraction")
 (allow_empty)
 (depends
  (rocq-core (and (>= 9.1) (< 9.2)))
  (rocq-stdlib (and (>= 9.1) (< 9.2)))))
