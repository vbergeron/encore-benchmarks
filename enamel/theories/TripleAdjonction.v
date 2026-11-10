(* ===================================================================== *)
(*  Co-génération : triple adjonction F ⊣ U ⊣ γ                           *)
(*  Formalisation Rocq (Rocq 9.1 + Stdlib ; aussi testé avec Coq 8.18)    *)
(*                                                                        *)
(*  Plan                                                                  *)
(*   1. Adjonctions entre préordres (version posétale) ; triple           *)
(*      adjonction ; un adjoint à droite préserve les meets (limites),   *)
(*      un adjoint à gauche préserve les joins (colimites).              *)
(*   2. Fragment libéral (clauses de Horn) : le modèle initial existe     *)
(*      et est unique  -> F est bien défini.                             *)
(*   3. Dès qu'il y a une disjonction (comme `|` en CUE) : plusieurs      *)
(*      modèles minimaux, aucun modèle initial  -> F n'existe pas.        *)
(*   4. Contraintes à la CUE (meet & associatif, commutatif, idempotent), *)
(*      extraction U, concrétisation γ, validation, LLM échantillonneur,  *)
(*      composition sans coordination.                                    *)
(* ===================================================================== *)

From Stdlib Require Import List Permutation Bool.
Import ListNotations.

(* ===================================================================== *)
(** * 1. Adjonctions posétales et triple adjonction                       *)
(* ===================================================================== *)

Record PO := {
  carrier :> Type;
  leq : carrier -> carrier -> Prop;
  leq_refl : forall x, leq x x;
  leq_trans : forall x y z, leq x y -> leq y z -> leq x z
}.
Arguments leq {_} _ _.
Arguments leq_refl {_} _.
Arguments leq_trans {_} _ _ _ _ _.
Notation "x ⊑ y" := (leq x y) (at level 70).

(** [f ⊣ g] : f c ⊑ s  <->  c ⊑ g s  (connexion de Galois). *)
Definition adjoint {A B : PO} (f : A -> B) (g : B -> A) : Prop :=
  forall a b, f a ⊑ b <-> a ⊑ g b.

Definition is_meet {A : PO} (x y m : A) : Prop :=
  m ⊑ x /\ m ⊑ y /\ forall z, z ⊑ x -> z ⊑ y -> z ⊑ m.

Definition is_join {A : PO} (x y j : A) : Prop :=
  x ⊑ j /\ y ⊑ j /\ forall z, x ⊑ z -> y ⊑ z -> j ⊑ z.

Section Adjunctions.
  Context {A B : PO} (f : A -> B) (g : B -> A) (H : adjoint f g).

  Lemma counit : forall b, f (g b) ⊑ b.
  Proof. intro b. apply H, leq_refl. Qed.

  Lemma unit : forall a, a ⊑ g (f a).
  Proof. intro a. apply H, leq_refl. Qed.

  Lemma right_adjoint_monotone : forall b1 b2, b1 ⊑ b2 -> g b1 ⊑ g b2.
  Proof.
    intros b1 b2 Hb. apply H. eapply leq_trans; [apply counit | exact Hb].
  Qed.

  Lemma left_adjoint_monotone : forall a1 a2, a1 ⊑ a2 -> f a1 ⊑ f a2.
  Proof.
    intros a1 a2 Ha. apply H. eapply leq_trans; [exact Ha | apply unit].
  Qed.

  (** L'adjoint à droite préserve les limites (ici : les meets).
      C'est l'énoncé abstrait derrière γ(c1 & c2) = γ(c1) ∩ γ(c2). *)
  Theorem right_adjoint_preserves_meets :
    forall b1 b2 m, is_meet b1 b2 m -> is_meet (g b1) (g b2) (g m).
  Proof.
    intros b1 b2 m [H1 [H2 Hglb]]. repeat split.
    - now apply right_adjoint_monotone.
    - now apply right_adjoint_monotone.
    - intros z Hz1 Hz2. apply H. apply Hglb; now apply H.
  Qed.

  (** Dualement, l'adjoint à gauche préserve les colimites (joins). *)
  Theorem left_adjoint_preserves_joins :
    forall a1 a2 j, is_join a1 a2 j -> is_join (f a1) (f a2) (f j).
  Proof.
    intros a1 a2 j [H1 [H2 Hlub]]. repeat split.
    - now apply left_adjoint_monotone.
    - now apply left_adjoint_monotone.
    - intros z Hz1 Hz2. apply H. apply Hlub; now apply H.
  Qed.
End Adjunctions.

(** Triple adjonction : F ⊣ U ⊣ γ, avec U (extraction) au centre.
    C = spécifications / contraintes, S = systèmes. *)
Record TripleAdj (C S : PO) := {
  F     : C -> S;            (* génération libre      *)
  U     : S -> C;            (* extraction (oubli)    *)
  gamma : C -> S;            (* concrétisation        *)
  adj_FU : adjoint F U;      (* F ⊣ U *)
  adj_Ug : adjoint U gamma   (* U ⊣ γ *)
}.
Arguments F {_ _} _ _.
Arguments U {_ _} _ _.
Arguments gamma {_ _} _ _.
Arguments adj_FU {_ _} _ _ _.
Arguments adj_Ug {_ _} _ _ _.

Section Triple.
  Context {C S : PO} (T : TripleAdj C S).

  (** La validation (γ) compose toujours : elle préserve les meets. *)
  Corollary gamma_preserves_meets :
    forall c1 c2 m, is_meet c1 c2 m ->
      is_meet (gamma T c1) (gamma T c2) (gamma T m).
  Proof. apply (right_adjoint_preserves_meets (U T)), adj_Ug. Qed.

  (** La génération (F), quand elle existe, préserve les joins. *)
  Corollary F_preserves_joins :
    forall c1 c2 j, is_join c1 c2 j -> is_join (F T c1) (F T c2) (F T j).
  Proof. apply (left_adjoint_preserves_joins _ (U T)), adj_FU. Qed.

  (** U, étant à la fois adjoint à gauche et à droite, préserve les deux. *)
  Corollary U_preserves_meets_and_joins :
    (forall s1 s2 m, is_meet s1 s2 m -> is_meet (U T s1) (U T s2) (U T m)) /\
    (forall s1 s2 j, is_join s1 s2 j -> is_join (U T s1) (U T s2) (U T j)).
  Proof.
    split.
    - apply (right_adjoint_preserves_meets (F T)), adj_FU.
    - apply (left_adjoint_preserves_joins _ (gamma T)), adj_Ug.
  Qed.
End Triple.

(* ===================================================================== *)
(** * 2. Fragment libéral : clauses de Horn, le modèle initial existe     *)
(* ===================================================================== *)

Section Horn.
  Variable Atom : Type.

  (** Interprétation = ensemble d'atomes vrais. *)
  Definition Interp := Atom -> Prop.

  Record clause := { body : list Atom; head : Atom }.
  Definition Theory := list clause.

  Definition sat (M : Interp) (cl : clause) : Prop :=
    (forall x, In x (body cl) -> M x) -> M (head cl).

  Definition model (P : Theory) (M : Interp) : Prop :=
    forall cl, In cl P -> sat M cl.

  Definition incl_I (M N : Interp) : Prop := forall x, M x -> N x.

  (** F(P) : intersection de tous les modèles. *)
  Definition least_model (P : Theory) : Interp :=
    fun x => forall M, model P M -> M x.

  Theorem least_model_is_model : forall P, model P (least_model P).
  Proof.
    intros P cl Hin Hbody M HM.
    apply (HM cl Hin). intros x Hx. exact (Hbody x Hx M HM).
  Qed.

  Theorem least_model_is_least :
    forall P M, model P M -> incl_I (least_model P) M.
  Proof. intros P M HM x Hx. exact (Hx M HM). Qed.

  (** Unicité : deux modèles initiaux coïncident (extensionnellement). *)
  Theorem initial_model_unique :
    forall P M1 M2,
      model P M1 -> (forall N, model P N -> incl_I M1 N) ->
      model P M2 -> (forall N, model P N -> incl_I M2 N) ->
      forall x, M1 x <-> M2 x.
  Proof.
    intros P M1 M2 HM1 L1 HM2 L2 x. split.
    - apply L1, HM2.
    - apply L2, HM1.
  Qed.
End Horn.

(* ===================================================================== *)
(** * 3. Disjonction : plus de modèle initial, plusieurs minimaux         *)
(* ===================================================================== *)

Section Disjunction.
  (** Théorie à une seule contrainte disjonctive :  pa ∨ pb
      (analogue CUE :  x: "a" | "b"). *)
  Inductive atom2 := pa | pb.

  Definition dmodel (M : atom2 -> Prop) : Prop := M pa \/ M pb.

  Definition minimal (M : atom2 -> Prop) : Prop :=
    dmodel M /\
    forall N, dmodel N -> (forall x, N x -> M x) -> (forall x, M x -> N x).

  Definition Ma : atom2 -> Prop := fun x => x = pa.
  Definition Mb : atom2 -> Prop := fun x => x = pb.

  Theorem Ma_minimal : minimal Ma.
  Proof.
    split; [left; reflexivity|].
    intros N [Ha|Hb] Hsub x Hx; unfold Ma in Hx; subst x.
    - exact Ha.
    - specialize (Hsub pb Hb). discriminate.
  Qed.

  Theorem Mb_minimal : minimal Mb.
  Proof.
    split; [right; reflexivity|].
    intros N [Ha|Hb] Hsub x Hx; unfold Mb in Hx; subst x.
    - specialize (Hsub pa Ha). discriminate.
    - exact Hb.
  Qed.

  Theorem minimal_models_distinct : ~ (forall x, Ma x <-> Mb x).
  Proof. intro H. assert (Mb pa) by (apply H; reflexivity). discriminate. Qed.

  (** Aucun modèle initial : la génération déterministe F n'existe pas
      hors du fragment libéral. *)
  Theorem no_initial_model :
    ~ exists M, dmodel M /\ forall N, dmodel N -> forall x, M x -> N x.
  Proof.
    intros [M [[Ha|Hb] Hleast]].
    - assert (Hc : Mb pa) by (apply (Hleast Mb (or_intror eq_refl)); exact Ha).
      discriminate.
    - assert (Hc : Ma pb) by (apply (Hleast Ma (or_introl eq_refl)); exact Hb).
      discriminate.
  Qed.
End Disjunction.

(* ===================================================================== *)
(** * 4. Contraintes CUE, extraction, concrétisation, validation          *)
(* ===================================================================== *)

Section CUE.
  (** Treillis de contraintes : unification & (meet) ; `_` = top. *)
  Variable Cstr : Type.
  Variable meet : Cstr -> Cstr -> Cstr.          (* c1 & c2 *)
  Variable top  : Cstr.                          (* _       *)
  Hypothesis meet_assoc : forall x y z, meet x (meet y z) = meet (meet x y) z.
  Hypothesis meet_comm  : forall x y, meet x y = meet y x.
  Hypothesis meet_idem  : forall x, meet x x = x.
  Hypothesis meet_top   : forall x, meet top x = x.

  (** Ordre de subsomption induit : x ⊑ y ssi x & y = x. *)
  Definition cle (x y : Cstr) : Prop := meet x y = x.

  Lemma cle_refl : forall x, cle x x.
  Proof. intro x. apply meet_idem. Qed.

  Lemma cle_trans : forall x y z, cle x y -> cle y z -> cle x z.
  Proof.
    unfold cle. intros x y z Hxy Hyz.
    rewrite <- Hxy, <- meet_assoc, Hyz. reflexivity.
  Qed.

  Lemma meet_lb1 : forall x y, cle (meet x y) x.
  Proof.
    unfold cle. intros x y.
    rewrite (meet_comm (meet x y) x), meet_assoc, meet_idem. reflexivity.
  Qed.

  Lemma meet_lb2 : forall x y, cle (meet x y) y.
  Proof. unfold cle. intros x y. rewrite <- meet_assoc, meet_idem. reflexivity. Qed.

  Lemma meet_glb : forall x y z, cle z x -> cle z y -> cle z (meet x y).
  Proof.
    unfold cle. intros x y z Hx Hy. rewrite meet_assoc, Hx, Hy. reflexivity.
  Qed.

  Definition CPO : PO :=
    {| carrier := Cstr; leq := cle; leq_refl := cle_refl; leq_trans := cle_trans |}.

  Lemma meet_is_meet : forall x y, @is_meet CPO x y (meet x y).
  Proof.
    intros x y. split; [apply meet_lb1|split; [apply meet_lb2|]].
    intros z. apply meet_glb.
  Qed.

  (** Systèmes et extraction déterministe U (foncteur d'oubli) :
      chaque système est observé comme une contrainte CUE. *)
  Variable Sys : Type.
  Variable U_obs : Sys -> Cstr.

  (** Concrétisation : γ(c) = ensemble des systèmes qui satisfont c. *)
  Definition gamma_c (c : Cstr) : Sys -> Prop := fun s => cle (U_obs s) c.

  (** Connexion de Galois (forme élémentaire) : α(X) ⊑ c  <->  X ⊆ γ(c). *)
  Theorem galois :
    forall (X : Sys -> Prop) c,
      (forall s, X s -> cle (U_obs s) c) <-> (forall s, X s -> gamma_c c s).
  Proof. reflexivity. Qed.

  Theorem gamma_monotone : forall c1 c2 s, cle c1 c2 -> gamma_c c1 s -> gamma_c c2 s.
  Proof. intros c1 c2 s H Hs. eapply cle_trans; eauto. Qed.

  Theorem gamma_top : forall s, gamma_c top s.
  Proof.
    intro s. unfold gamma_c, cle. rewrite meet_comm. apply meet_top.
  Qed.

  (** Le théorème central :  γ(c1 & c2) = γ(c1) ∩ γ(c2). *)
  Theorem gamma_meet :
    forall c1 c2 s, gamma_c (meet c1 c2) s <-> gamma_c c1 s /\ gamma_c c2 s.
  Proof.
    intros c1 c2 s. unfold gamma_c. split.
    - intro H. split; eapply cle_trans; eauto using meet_lb1, meet_lb2.
    - intros [H1 H2]. now apply meet_glb.
  Qed.

  (** ---- Validation décidable (unification CUE) ---- *)
  Hypothesis cle_dec : forall x y, {cle x y} + {~ cle x y}.

  Definition validate (c : Cstr) (s : Sys) : bool :=
    if cle_dec (U_obs s) c then true else false.

  Theorem validate_correct : forall c s, validate c s = true <-> gamma_c c s.
  Proof.
    intros c s. unfold validate, gamma_c.
    destruct (cle_dec (U_obs s) c); split; intro; congruence || contradiction.
  Qed.

  (** ---- Le LLM : échantillonneur stochastique arbitraire ----
      Aucune hypothèse n'est faite sur [llm] : il peut proposer
      n'importe quel système, pour n'importe quelle graine. *)
  Variable Seed : Type.
  Variable llm  : Seed -> Cstr -> Sys.

  (** Échantillonnage par rejet : on essaie des graines jusqu'à acceptation. *)
  Fixpoint sample (seeds : list Seed) (c : Cstr) : option Sys :=
    match seeds with
    | [] => None
    | sd :: rest =>
        let s := llm sd c in
        if validate c s then Some s else sample rest c
    end.

  (** Fiabilité : quoi que fasse le LLM, tout système retourné satisfait c. *)
  Theorem sample_sound :
    forall seeds c s, sample seeds c = Some s -> gamma_c c s.
  Proof.
    induction seeds as [|sd rest IH]; simpl; intros c s H; [discriminate|].
    destruct (validate c (llm sd c)) eqn:E.
    - injection H as <-. now apply validate_correct.
    - now apply IH.
  Qed.

  (** ---- Composition sans coordination ----
      Plusieurs équipes posent des contraintes indépendamment ;
      leur conjonction est l'unification de la liste. *)
  Definition unify (l : list Cstr) : Cstr := fold_right meet top l.

  (** L'ordre d'arrivée des contraintes est indifférent. *)
  Theorem unify_perm : forall l l', Permutation l l' -> unify l = unify l'.
  Proof.
    intros l l' H. induction H; simpl.
    - reflexivity.
    - now rewrite IHPermutation.
    - rewrite !meet_assoc, (meet_comm y x). reflexivity.
    - congruence.
  Qed.

  Theorem unify_app : forall l l', unify (l ++ l') = meet (unify l) (unify l').
  Proof.
    induction l as [|c l IH]; intro l'; simpl.
    - now rewrite meet_top.
    - now rewrite IH, meet_assoc.
  Qed.

  (** Répéter des contraintes ne change rien (idempotence). *)
  Theorem unify_dup : forall l, unify (l ++ l) = unify l.
  Proof. intro l. now rewrite unify_app, meet_idem. Qed.

  (** Valider contre la conjonction = valider contre chaque contrainte. *)
  Theorem gamma_unify :
    forall l s, gamma_c (unify l) s <-> Forall (fun c => gamma_c c s) l.
  Proof.
    induction l as [|c l IH]; intro s; simpl.
    - split; [constructor | intros _; apply gamma_top].
    - rewrite gamma_meet, IH. split.
      + intros [H1 H2]. now constructor.
      + intro H. inversion H; subst. now split.
  Qed.

  Theorem validate_unify :
    forall l s, validate (unify l) s = forallb (fun c => validate c s) l.
  Proof.
    intros l s. apply eq_true_iff_eq.
    rewrite validate_correct, gamma_unify, forallb_forall, Forall_forall.
    split; intros H c Hc; apply validate_correct; auto.
  Qed.

  (** Synthèse finale : quel que soit l'ordre des contraintes et le
      comportement du LLM, un système accepté satisfait toutes les
      contraintes de toutes les équipes. *)
  Theorem cogeneration_sound :
    forall seeds l l' s,
      Permutation l l' ->
      sample seeds (unify l) = Some s ->
      gamma_c (unify l') s /\ Forall (fun c => gamma_c c s) l'.
  Proof.
    intros seeds l l' s Hp Hs.
    pose proof (sample_sound _ _ _ Hs) as H.
    rewrite (unify_perm _ _ Hp) in H.
    split; [exact H | now apply gamma_unify].
  Qed.
End CUE.

Print Assumptions cogeneration_sound.
Print Assumptions no_initial_model.
Print Assumptions gamma_preserves_meets.
