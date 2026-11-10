# Enamel formal framework

A Rocq model of the envelope used by
[Enamel](https://github.com/ahoy-jon/enamel): extraction U, concretization γ
and free generation F, with F ⊣ U ⊣ γ. It is the formal counterpart of
Enamel's `docs/adjunctions.md` and `docs/rocq.md`. It is not part of the
Encore benchmarks: it is proof checking only, with no extraction and no
firmware.

```text
enamel/
  theories/TripleAdjonction.v  the model (comments in French)
  theories/Limits.v            proofs behind each limit in LIMITS.md
  theories/dune                rocq.theory Enamel
  LIMITS.md                    executive summary of the model's limits
```

## What `TripleAdjonction.v` covers

1. Adjunctions between preorders and the triple adjunction F ⊣ U ⊣ γ. Right
   adjoints keep meets, left adjoints keep joins.
2. Horn clauses: the least model exists and is unique, so F is defined.
3. Disjunction (CUE `|`): two minimal models and no least model, so F does
   not exist.
4. CUE constraints as a meet semilattice: γ(c₁ & c₂) = γ(c₁) ∩ γ(c₂), the
   order of constraints does not matter, and generate-and-check with any
   generator (an LLM) only returns valid systems.

The model checks a system by subsumption, but Enamel checks it by
compatibility (`cue vet`). These are not the same when observations are
partial. Read [LIMITS.md](LIMITS.md) before you rely on these results.

## Build

The theory is part of the repository's dune project, so the commands in the
root [README](../README.md#rocq) check it with the workload proofs:

```bash
dune build @enamel/theories/all  # only this theory
dune build                       # everything
docker/rocq.sh                   # the same without a local Rocq, as CI does
```

`Print Assumptions` at the end of each file prints
`Closed under the global context`. The CUE laws are section hypotheses, not
axioms.
