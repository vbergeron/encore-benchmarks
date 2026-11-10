(* ===================================================================== *)
(*  Limits of the model in TripleAdjonction.v                            *)
(*                                                                       *)
(*  Each limit listed in ../LIMITS.md is stated and checked here, so     *)
(*  the summary is backed by proofs and not only by prose.               *)
(*                                                                       *)
(*   L1. The TripleAdj record can be inhabited, but nothing in           *)
(*       TripleAdjonction.v builds an instance tied to CUE.              *)
(*   L2. TripleAdjonction.v accepts a system by *subsumption*:           *)
(*       U(s) & c = U(s). Enamel's `cue vet` accepts it by               *)
(*       *compatibility*: U(s) & c is not bottom. Under compatibility,   *)
(*       gamma(c1 & c2) = gamma(c1) /\ gamma(c2) is false as soon as an   *)
(*       observation is partial (counterexample below).                  *)
(*   L3. The law comes back when the observation is concrete (an atom    *)
(*       of the lattice) on the constrained paths: then compatibility    *)
(*       and subsumption are the same check (general theorem below).     *)
(* ===================================================================== *)

From Stdlib Require Import List Bool.
From Enamel Require Import TripleAdjonction.
Import ListNotations.

(* ===================================================================== *)
(** * L1. TripleAdj is satisfiable (identity on Prop)                     *)
(* ===================================================================== *)

Definition PropPO : PO :=
  {| carrier := Prop;
     leq := fun a b => a -> b;
     leq_refl := fun _ x => x;
     leq_trans := fun _ _ _ f g x => g (f x) |}.

(** So the corollaries of section 1 are not vacuous. They are still not
    connected to section 4: there, [gamma_c] goes to [Sys -> Prop], not
    to [Sys], and [gamma_meet] is proved directly. *)
Definition identity_triple : TripleAdj PropPO PropPO.
Proof.
  refine {| F := fun x => x; U := fun x => x; gamma := fun x => x |};
    intros a b; simpl; tauto.
Defined.

(* ===================================================================== *)
(** * L3. General theorem: compatibility with concrete observations      *)
(* ===================================================================== *)

Section Compatibility.
  (** Same lattice hypotheses as section 4 of TripleAdjonction.v, plus a
      bottom element (`_|_`, a CUE conflict). *)
  Variable Cstr : Type.
  Variable meet : Cstr -> Cstr -> Cstr.
  Variable top bot : Cstr.
  Hypothesis meet_assoc : forall x y z, meet x (meet y z) = meet (meet x y) z.
  Hypothesis meet_comm  : forall x y, meet x y = meet y x.
  Hypothesis meet_idem  : forall x, meet x x = x.
  Hypothesis meet_top   : forall x, meet top x = x.
  Hypothesis meet_bot   : forall x, meet bot x = bot.

  Variable Sys : Type.
  Variable U_obs : Sys -> Cstr.

  (** What `cue vet` checks: unification does not conflict. *)
  Definition compatible (c : Cstr) (s : Sys) : Prop := meet (U_obs s) c <> bot.

  (** One direction always holds: if the joint check passes, every
      separate check passes. *)
  Theorem compatible_meet_split :
    forall c1 c2 s, compatible (meet c1 c2) s -> compatible c1 s /\ compatible c2 s.
  Proof.
    unfold compatible. intros c1 c2 s H. split; intro E; apply H.
    - rewrite meet_assoc, E. apply meet_bot.
    - rewrite (meet_comm c1 c2), meet_assoc, E. apply meet_bot.
  Qed.

  (** A concrete observation is an atom: not bottom, and any constraint
      either accepts it unchanged or conflicts with it. In CUE terms: the
      observation is fully concrete on every path a constraint mentions. *)
  Definition concrete (o : Cstr) : Prop :=
    o <> bot /\ forall c, meet o c = o \/ meet o c = bot.

  (** For a concrete observation, compatibility is subsumption. *)
  Theorem compatible_iff_subsumed :
    forall s c, concrete (U_obs s) ->
      compatible c s <-> cle Cstr meet (U_obs s) c.
  Proof.
    unfold compatible, cle. intros s c [Hnb Hat]. split.
    - intro H. destruct (Hat c) as [E|E]; [exact E | contradiction].
    - intros E. rewrite E. exact Hnb.
  Qed.

  (** So the validation law of docs/adjunctions.md holds under
      compatibility, but only for concrete observations. *)
  Theorem compatible_meet_concrete :
    forall c1 c2 s, concrete (U_obs s) ->
      compatible (meet c1 c2) s <-> compatible c1 s /\ compatible c2 s.
  Proof.
    intros c1 c2 s Hc. split; [apply compatible_meet_split|].
    intros [H1 H2].
    apply compatible_iff_subsumed in H1, H2; try exact Hc.
    unfold compatible, cle in *. rewrite meet_assoc, H1, H2.
    exact (proj1 Hc).
  Qed.
End Compatibility.

(* ===================================================================== *)
(** * L2. Counterexample: a partial observation                          *)
(* ===================================================================== *)

(** One CUE field: `_` (top), a literal, or `_|_` (bottom). *)
Inductive Field := Top | Lit (n : nat) | Bot.

Definition fmeet (x y : Field) : Field :=
  match x, y with
  | Top, z | z, Top => z
  | Bot, _ | _, Bot => Bot
  | Lit a, Lit b => if Nat.eqb a b then Lit a else Bot
  end.

(** It satisfies every lattice hypothesis used above, so it is a
    legitimate instance of both TripleAdjonction.v section 4 and
    [Compatibility]. *)
Lemma fmeet_comm : forall x y, fmeet x y = fmeet y x.
Proof.
  intros [| a |] [| b |]; simpl; try reflexivity.
  rewrite PeanoNat.Nat.eqb_sym.
  destruct (Nat.eqb b a) eqn:E; [apply PeanoNat.Nat.eqb_eq in E; subst|]; reflexivity.
Qed.

Lemma fmeet_idem : forall x, fmeet x x = x.
Proof. intros [| a |]; simpl; try reflexivity. now rewrite PeanoNat.Nat.eqb_refl. Qed.

Lemma fmeet_top : forall x, fmeet Top x = x.
Proof. reflexivity. Qed.

Lemma fmeet_bot : forall x, fmeet Bot x = Bot.
Proof. intros [| a |]; reflexivity. Qed.

Lemma fmeet_assoc : forall x y z, fmeet x (fmeet y z) = fmeet (fmeet x y) z.
Proof.
  intros [| a |] [| b |] [| c |]; simpl; try reflexivity;
    repeat (match goal with |- context [Nat.eqb ?p ?q] =>
              destruct (Nat.eqb p q) eqn:? end; simpl; try reflexivity);
    repeat match goal with H : Nat.eqb _ _ = _ |- _ =>
      first [apply PeanoNat.Nat.eqb_eq in H | apply PeanoNat.Nat.eqb_neq in H] end;
    subst; try congruence; rewrite PeanoNat.Nat.eqb_refl in *; congruence.
Qed.

(** The system's field was not observed (translucency): U(s) = `_`.
    Team 1 requires `x: 1`, team 2 requires `x: 2`. *)
Definition unobserved (_ : Datatypes.unit) : Field := Top.

(** Each separate `cue vet` passes, the joint one fails: the law
    gamma(c1 & c2) = gamma(c1) /\ gamma(c2) is false under compatibility. *)
Theorem compatibility_breaks_meet_law :
  compatible Field fmeet Bot Datatypes.unit unobserved (Lit 1) tt /\
  compatible Field fmeet Bot Datatypes.unit unobserved (Lit 2) tt /\
  ~ compatible Field fmeet Bot Datatypes.unit unobserved (fmeet (Lit 1) (Lit 2)) tt.
Proof. unfold compatible, unobserved; simpl; repeat split; congruence. Qed.

(** The same observation is rejected by both teams under the subsumption
    check of TripleAdjonction.v: that model is sound, but it is not the
    check Enamel runs. *)
Theorem subsumption_rejects_unobserved :
  ~ cle Field fmeet (unobserved tt) (Lit 1) /\
  ~ cle Field fmeet (unobserved tt) (Lit 2).
Proof. unfold cle, unobserved; simpl; split; congruence. Qed.

(** And the observation is not concrete, as L3 requires. *)
Theorem unobserved_not_concrete : ~ concrete Field fmeet Bot (unobserved tt).
Proof.
  unfold concrete, unobserved. intros [_ H].
  destruct (H (Lit 1)) as [E|E]; simpl in E; discriminate.
Qed.

Print Assumptions compatible_meet_concrete.
Print Assumptions compatibility_breaks_meet_law.
