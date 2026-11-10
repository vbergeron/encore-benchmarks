# Limits of the current model: executive summary

This note covers the Rocq model in
[`theories/TripleAdjonction.v`](theories/TripleAdjonction.v). It says what
the model proves, what it does not prove, and where it is different from what
[Enamel](https://github.com/ahoy-jon/enamel) does in practice. Each limit
marked *(checked)* has a matching proof in
[`theories/Limits.v`](theories/Limits.v).

## In short

- The model compiles, and it uses no global axioms. All the assumptions about
  CUE are explicit hypotheses.
- The proofs are correct. What they prove is the model, not Enamel's real
  check.
- **Main limit.** The model accepts a system when its observation is *more
  precise* than the constraint (subsumption). Enamel accepts a system when its
  observation *does not conflict* with the constraint (`cue vet`). These are
  two different checks. With the second one, the central law
  γ(c₁ & c₂) = γ(c₁) ∩ γ(c₂) is **false** when the observation is partial.
- The law is true again when the observation is concrete on every field that a
  constraint mentions. That is the condition to state, to test, or to enforce.
- The "triple adjunction F ⊣ U ⊣ γ" is a framing. It is not yet a proved
  result about CUE.

## What the model proves

1. **Adjunctions on preorders (section 1).** Right adjoints keep meets, and
   left adjoints keep joins. So in a triple adjunction, γ keeps meets and U
   keeps both. This is standard and correct.
2. **Horn clauses have one least model (section 2).** This means
   deterministic generation (F) makes sense for this fragment.
3. **Disjunction removes the least model (section 3).** `x: "a" | "b"` has
   two minimal models and no least one. So generation becomes a search
   problem.
4. **Validation composes (section 4).** If constraints form a meet
   semilattice and a system is accepted when U(s) ⊑ c, then:
   - checking against `c₁ & c₂` is the same as checking against both;
   - the order of constraints and duplicate constraints do not matter;
   - any system returned by the generate-and-check loop is valid, for **any**
     generator, including an LLM.

## Limits

### 1. The checked relation is not the one Enamel uses *(checked)*

| | Accept system `s` for constraint `c` when |
|---|---|
| Model (`gamma_c`) | `U(s) & c = U(s)`: the observation is at least as precise as `c` |
| Enamel (`cue vet .`) | `U(s) & c` is not `_|_`: the two do not conflict |

Enamel's observations are partial on purpose ("translucent"). A field that
the adapter does not observe is `_`, and `_` is compatible with everything.

Example: the field `x` is not observed. Team 1 requires `x: 1` and team 2
requires `x: 2`. Each check passes on its own, but the joint check fails,
because `1 & 2` is a conflict.

Consequences:

- "Independent checks combine without coordination" is false for partial
  observations. A system can pass every team's check and still fail the
  combined envelope.
- `validate_unify` (the joint check equals all the separate checks) has the
  same problem.
- Today the example repository is safe, because it validates **one** unified
  envelope (`conforms: intent & observation & {...}`). The risk appears if
  checks are later run separately, for example one per team or one per CI job.

Proof: `compatibility_breaks_meet_law` in `Limits.v`.

### 2. When the law does hold *(checked)*

The law is true under compatibility when the observation is **concrete**.
Concrete means that any constraint either accepts the observation as it is or
conflicts with it. In CUE terms, the observation has a concrete value on every
path that some constraint mentions. In that case the two checks are the same,
and every result of section 4 applies.

Proof: `compatible_iff_subsumed` and `compatible_meet_concrete` in
`Limits.v`.

Possible actions:

- Make concreteness part of each adapter contract. The adapter lists the
  paths it always fills.
- Or validate with a concreteness check (for example `cue vet -c` or
  `cue export`) on the constrained paths.
- Or always validate the single unified envelope, never the separate pieces.

### 3. The sections are not connected *(partly checked)*

- No `TripleAdj` instance is built from CUE. The record can be satisfied (the
  identity on `Prop`, `identity_triple`), so section 1 is not empty. But its
  results are never applied to the CUE section.
- In section 4, γ maps a constraint to a *set* of systems (`Sys -> Prop`), not
  to a system, as in the `TripleAdj` record. The law `gamma_meet` is proved
  directly, not from `gamma_preserves_meets`.
- The Horn least model (section 2) is never shown to be a left adjoint F.
  Section 3 does not conclude "no F ⊣ U" formally.

### 4. The theorem `galois` is only a definition

It is proved by `reflexivity`, because both sides are the same formula. No
abstraction map α appears in it. A real Galois connection α ⊣ γ between sets
of systems and constraints needs **joins** in the constraint lattice (CUE's
`|`). The model does not assume joins, and section 3 shows that they are
exactly where things get harder.

### 5. CUE is idealised

- The lattice laws use exact equality. So `Cstr` must be a normal form of CUE
  values, not CUE source text.
- `cle_dec` assumes subsumption can always be decided. CUE's subsumption check
  is not complete for some constructs. This point is worth checking against
  the CUE version in use.
- Defaults (`*`), closed structs (`close`, definitions), comprehensions and
  references are not modelled. Enamel's examples use `close`.
- Bottom (`_|_`, a conflict) is not in the original model. `Limits.v` adds
  it.

### 6. The generator and the loop are simplified

- The LLM is a function from a seed and a constraint to a system. It gets no
  feedback, so the "observe, compare, repair" loop of Enamel is not modelled.
  Soundness would still hold with feedback.
- Only soundness is proved: an accepted system is valid. Nothing is said about
  progress, termination or the chance of success. This is expected, but it
  should be said clearly.

### 7. Trust boundary

These proofs say nothing about:

- adapter fidelity: whether `U` really observes what it claims;
- the CUE implementation: whether `cue vet` follows the lattice laws;
- whether the constraints say what people intend.

These are the same limits that Enamel's `docs/rocq.md` lists.

### 8. Small hygiene point

`Lemma unit` in section 1 hides the standard type `unit` in every file that
imports `TripleAdjonction`. `Limits.v` has to write `Datatypes.unit`. Renaming
the lemma (for example to `adj_unit`) would remove this trap.

## Suggested next steps

1. Use compatibility (`U(s) & c` is not bottom) as the main check, and prove
   section 4 again under the concreteness condition of limit 2. This is the
   model of what Enamel runs.
2. Add joins and build a real α ⊣ γ. Then get `gamma_meet` from
   `gamma_preserves_meets` and build a `TripleAdj`-style instance from it.
3. Connect sections 2 and 3 to adjunctions: if a left adjoint exists, then a
   least model exists, so section 3 rules out F.
4. Write a small example that links one Rocq theorem to one CUE constraint, as
   Enamel's `docs/rocq.md` proposes.
