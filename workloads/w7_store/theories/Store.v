(** W7 — FIDO credential store on a persistent red-black tree.

    A FIDO authenticator keeps its resident credentials in a store keyed
    by credential handle, and each credential carries a signature counter
    that the authenticator increments on every assertion (the relying
    party rejects a counter that does not go up: it is how cloned keys are
    detected). The store is Okasaki's red-black tree, the paper's [rbtree]
    micro-benchmark, here with a real use and up to 500 entries.

    Two events:
    - register [k c]: store credential [k] with counter [c], replacing the
      credential [k] if there is one;
    - assert [k]: if credential [k] exists with counter [c], set its
      counter to [c + 1] and answer [c + 1]; otherwise answer 0.

    Properties proved: [insert] keeps the red-black invariants and the
    search-tree order, a red-black tree of black height [h] has depth at
    most [2h + 1] and at least [2^h - 1] entries (so a lookup is
    logarithmic), [lookup] after [insert] finds the inserted value and
    only it, and the in-place driver computes the store specified as a
    finite map. *)

From Stdlib Require Import Arith List Lia.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** Layout constants, extracted to integer literals by [Extract.v]. *)
Definition byte_base := 256.
Definition key_len := 2.   (* credential handle, big-endian *)
Definition reg_len := 4.   (* registration: handle, then counter, big-endian *)

(** * Red-black tree *)

Inductive color := Red | Black.
Inductive tree := E | T (c : color) (l : tree) (k v : nat) (r : tree).

Fixpoint lookup (x : nat) (t : tree) : option nat :=
  match t with
  | E => None
  | T _ l k v r => if x <? k then lookup x l else if k <? x then lookup x r else Some v
  end.

(** Okasaki's rebalancing of a black node with a red child that has a red
    child. *)
Definition balance (c : color) (l : tree) (k v : nat) (r : tree) : tree :=
  match c with
  | Red => T Red l k v r
  | Black =>
      match l with
      | T Red (T Red a xk xv b) yk yv c' | T Red a xk xv (T Red b yk yv c') =>
          T Red (T Black a xk xv b) yk yv (T Black c' k v r)
      | _ =>
          match r with
          | T Red (T Red b yk yv c') zk zv d | T Red b yk yv (T Red c' zk zv d) =>
              T Red (T Black l k v b) yk yv (T Black c' zk zv d)
          | _ => T Black l k v r
          end
      end
  end.

Fixpoint ins (x vx : nat) (t : tree) : tree :=
  match t with
  | E => T Red E x vx E
  | T c l k v r =>
      if x <? k then balance c (ins x vx l) k v r
      else if k <? x then balance c l k v (ins x vx r)
      else T c l x vx r
  end.

Definition make_black (t : tree) : tree :=
  match t with
  | E => E
  | T _ l k v r => T Black l k v r
  end.

Definition insert (x vx : nat) (t : tree) : tree := make_black (ins x vx t).

(** * The store *)

(** An assertion: the new tree and the answer. *)
Definition assert (x : nat) (t : tree) : tree * nat :=
  match lookup x t with
  | Some c => (insert x (S c) t, S c)
  | None => (t, 0)
  end.

(** * In-place driver

    The input stream is [q], then [q] handles to assert (2 bytes each),
    then the registrations (4 bytes each). [run n] registers the first
    [n] credentials in an empty store, then answers the [q] assertions in
    order. *)

Definition read_u16 (pos : nat) : nat := input_byte pos * byte_base + input_byte (S pos).

Fixpoint load (k pos : nat) (t : tree) : tree :=
  match k with
  | O => t
  | S k' => load k' (pos + reg_len) (insert (read_u16 pos) (read_u16 (pos + key_len)) t)
  end.

Fixpoint answer (k pos : nat) (t : tree) : list nat :=
  match k with
  | O => []
  | S k' => let (t', a) := assert (read_u16 pos) t in a :: answer k' (pos + key_len) t'
  end.

Definition run (n : nat) : list nat :=
  let q := input_byte 0 in
  answer q 1 (load n (1 + key_len * q) E).

(** * Red-black invariants

    [RB t c h]: [t] is a red-black tree of black height [h] that can hang
    below a node of color [c] (below a red node, its root is not red). *)

Inductive RB : tree -> color -> nat -> Prop :=
| RB_leaf : forall c, RB E c 0
| RB_r : forall l k v r h,
    RB l Red h -> RB r Red h -> RB (T Red l k v r) Black h
| RB_b : forall c l k v r h,
    RB l Black h -> RB r Black h -> RB (T Black l k v r) c (S h).

(** A tree that may have a red root with a red child: what [ins] returns
    before [make_black]. *)
Inductive NearlyRB : tree -> nat -> Prop :=
| NRB_r : forall l k v r h,
    RB l Black h -> RB r Black h -> NearlyRB (T Red l k v r) h
| NRB_b : forall l k v r h,
    RB l Black h -> RB r Black h -> NearlyRB (T Black l k v r) (S h).

Local Hint Constructors RB NearlyRB : core.

Lemma RB_weaken : forall t h, RB t Red h -> RB t Black h.
Proof. intros t h H. inversion H; subst; auto. Qed.

Local Hint Resolve RB_weaken : core.

(** Case analysis of a tree, one level down. *)
Ltac inv_RB :=
  repeat match goal with
  | H : RB (T _ _ _ _ _) _ _ |- _ => inversion H; subst; clear H
  | H : NearlyRB (T _ _ _ _ _) _ |- _ => inversion H; subst; clear H
  | H : NearlyRB E _ |- _ => inversion H
  | H : RB E _ ?h |- _ => is_var h; inversion H; subst; clear H
  | H : RB E _ (S _) |- _ => inversion H
  end.

(** Every case of [balance]. *)
Ltac balance_cases :=
  unfold balance;
  repeat match goal with |- context [match ?t with _ => _ end] => destruct t end.

Lemma balance_l : forall l k v r h,
  NearlyRB l h -> RB r Black h -> RB (balance Black l k v r) Black (S h).
Proof.
  intros l k v r h Hl Hr. inversion Hl; subst; clear Hl; balance_cases; inv_RB; auto 7.
Qed.

Lemma balance_r : forall l k v r h,
  RB l Black h -> NearlyRB r h -> RB (balance Black l k v r) Black (S h).
Proof.
  intros l k v r h Hl Hr. inversion Hr; subst; clear Hr; balance_cases; inv_RB; auto 7.
Qed.

Lemma balance_not_E : forall c l k v r, balance c l k v r <> E.
Proof.
  intros. unfold balance.
  repeat match goal with |- context [match ?t with _ => _ end] => destruct t end;
    discriminate.
Qed.

Lemma RB_nearly : forall t h, RB t Black h -> t <> E -> NearlyRB t h.
Proof. intros t h H Ht. inversion H; subst; auto. contradiction. Qed.

Lemma ins_RB : forall x vx t h,
  (RB t Black h -> NearlyRB (ins x vx t) h) /\
  (RB t Red h -> RB (ins x vx t) Black h).
Proof.
  intros x vx t. induction t as [|c l IHl k v r IHr]; intro h.
  - split; intro H; inversion H; subst; cbn; auto.
  - pose proof (fun h => proj1 (IHl h)) as IHl1; pose proof (fun h => proj2 (IHl h)) as IHl2.
    pose proof (fun h => proj1 (IHr h)) as IHr1; pose proof (fun h => proj2 (IHr h)) as IHr2.
    clear IHl IHr.
    cbn [ins]. split; intro H; inversion H; subst;
      destruct (x <? k); try destruct (k <? x);
      first
        [ solve [auto]
          (* red node under a black one: [balance Red] only rebuilds it *)
        | solve [cbn [balance]; auto]
          (* black node under a red one: stays black *)
        | solve [auto using balance_l, balance_r]
          (* black node under a black one: may become red *)
        | solve [apply RB_nearly; auto using balance_l, balance_r, balance_not_E] ].
Qed.

Theorem insert_RB : forall x vx t h,
  RB t Red h -> exists h', RB (insert x vx t) Red h'.
Proof.
  intros x vx t h H. apply RB_weaken, (ins_RB x vx t h) in H.
  unfold insert. inversion H; subst; cbn; eauto.
Qed.

(** Depth and size bounds: a lookup visits at most [2h + 1] nodes, in a
    tree of at least [2^h - 1] entries. *)

Fixpoint depth (t : tree) : nat :=
  match t with E => 0 | T _ l _ _ r => S (Nat.max (depth l) (depth r)) end.

Fixpoint size (t : tree) : nat :=
  match t with E => 0 | T _ l _ _ r => S (size l + size r) end.

Theorem RB_depth : forall t c h,
  RB t c h -> depth t <= 2 * h + match c with Red => 0 | Black => 1 end.
Proof.
  intros t c h H. induction H; cbn [depth] in *;
    repeat match goal with |- context [match ?c with Red => _ | Black => _ end] => destruct c end;
    lia.
Qed.

Theorem RB_size : forall t c h, RB t c h -> 2 ^ h <= S (size t).
Proof. intros t c h H. induction H; cbn in *; lia. Qed.

(** A red-black tree built by the driver from the empty tree. *)
Theorem load_RB : forall k pos t h,
  RB t Red h -> exists h', RB (load k pos t) Red h'.
Proof.
  induction k as [|k IH]; intros pos t h H; cbn [load]; eauto.
  destruct (insert_RB (read_u16 pos) (read_u16 (pos + key_len)) t h H) as [h' H'].
  eauto.
Qed.

Theorem assert_RB : forall x t h,
  RB t Red h -> exists h', RB (fst (assert x t)) Red h'.
Proof.
  intros x t h H. unfold assert. destruct (lookup x t); cbn [fst]; eauto using insert_RB.
Qed.

(** * Search-tree order *)

Fixpoint ForallT (P : nat -> Prop) (t : tree) : Prop :=
  match t with
  | E => True
  | T _ l k _ r => P k /\ ForallT P l /\ ForallT P r
  end.

Inductive BST : tree -> Prop :=
| BST_E : BST E
| BST_T : forall c l k v r,
    ForallT (fun x => x < k) l -> ForallT (fun x => x > k) r ->
    BST l -> BST r -> BST (T c l k v r).

Local Hint Constructors BST : core.

Lemma ForallT_imp : forall (P Q : nat -> Prop) t,
  ForallT P t -> (forall x, P x -> Q x) -> ForallT Q t.
Proof. intros P Q t. induction t; cbn; intuition. Qed.

(** Take apart every search-tree fact about a node. *)
Ltac inv_BST :=
  repeat match goal with
  | H : BST (T _ _ _ _ _) |- _ => inversion H; subst; clear H
  | H : ForallT _ (T _ _ _ _ _) |- _ => cbn [ForallT] in H
  | H : _ /\ _ |- _ => destruct H
  end.

(** Close order goals by transitivity through the keys. *)
Ltac solve_ForallT :=
  cbn [ForallT]; repeat split;
  try match goal with
  | H : ForallT _ ?t |- ForallT _ ?t => apply (ForallT_imp _ _ _ H); intros; lia
  end;
  try lia; auto.

Lemma balance_ForallT : forall (P : nat -> Prop) c l k v r,
  ForallT P l -> P k -> ForallT P r -> ForallT P (balance c l k v r).
Proof. intros. balance_cases; cbn [ForallT] in *; tauto. Qed.

Lemma ins_ForallT : forall (P : nat -> Prop) x vx t,
  ForallT P t -> P x -> ForallT P (ins x vx t).
Proof.
  intros P x vx t. induction t as [|c l IHl k v r IHr]; intros Ht Hx; cbn [ins].
  - cbn; auto.
  - cbn [ForallT] in Ht. destruct Ht as (Hk & Hl & Hr).
    destruct (x <? k); [|destruct (k <? x)];
      auto using balance_ForallT; cbn; auto.
Qed.

Lemma balance_BST : forall c l k v r,
  ForallT (fun x => x < k) l -> ForallT (fun x => x > k) r ->
  BST l -> BST r -> BST (balance c l k v r).
Proof.
  intros. balance_cases; inv_BST; repeat constructor; solve_ForallT.
Qed.

Lemma ins_BST : forall x vx t, BST t -> BST (ins x vx t).
Proof.
  intros x vx t. induction t as [|c l IHl k v r IHr]; intro H; cbn [ins].
  - repeat constructor.
  - inversion H; subst.
    destruct (Nat.ltb_spec x k); [|destruct (Nat.ltb_spec k x)].
    + apply balance_BST; auto. apply ins_ForallT; auto.
    + apply balance_BST; auto. apply ins_ForallT; auto.
    + replace x with k by lia. auto.
Qed.

Theorem insert_BST : forall x vx t, BST t -> BST (insert x vx t).
Proof.
  intros x vx t H. unfold insert. pose proof (ins_BST x vx t H) as H'.
  destruct (ins x vx t); cbn; inversion H'; auto.
Qed.

(** * [lookup] after [insert] *)

Lemma lookup_T : forall c l k v r x,
  lookup x (T c l k v r) = if x <? k then lookup x l else if k <? x then lookup x r else Some v.
Proof. reflexivity. Qed.

Lemma balance_lookup : forall c l k v r x,
  ForallT (fun y => y < k) l -> ForallT (fun y => y > k) r -> BST l -> BST r ->
  lookup x (balance c l k v r) = lookup x (T c l k v r).
Proof.
  intros. balance_cases; inv_BST; cbn [lookup];
    repeat match goal with
    | |- context [?a <? ?b] => destruct (Nat.ltb_spec a b)
    end;
    try lia; reflexivity.
Qed.

Lemma lookup_ins : forall x vx t y,
  BST t -> lookup y (ins x vx t) = if y =? x then Some vx else lookup y t.
Proof.
  intros x vx t y. induction t as [|c l IHl k v r IHr]; intro H; cbn [ins].
  - cbn [lookup].
    destruct (Nat.eqb_spec y x); destruct (Nat.ltb_spec y x); destruct (Nat.ltb_spec x y);
      try lia; reflexivity.
  - inversion H; subst.
    destruct (Nat.ltb_spec x k); [|destruct (Nat.ltb_spec k x)].
    + rewrite balance_lookup by auto using ins_ForallT, ins_BST.
      rewrite !lookup_T, IHl by auto.
      destruct (Nat.eqb_spec y x); destruct (Nat.ltb_spec y k); try lia; reflexivity.
    + rewrite balance_lookup by auto using ins_ForallT, ins_BST.
      rewrite !lookup_T, IHr by auto.
      destruct (Nat.eqb_spec y x); destruct (Nat.ltb_spec y k); destruct (Nat.ltb_spec k y);
        try lia; reflexivity.
    + replace x with k by lia. rewrite !lookup_T.
      destruct (Nat.eqb_spec y k); destruct (Nat.ltb_spec y k); destruct (Nat.ltb_spec k y);
        try lia; reflexivity.
Qed.

Theorem lookup_insert : forall x vx t y,
  BST t -> lookup y (insert x vx t) = if y =? x then Some vx else lookup y t.
Proof.
  intros x vx t y H. rewrite <- lookup_ins by exact H.
  unfold insert. destruct (ins x vx t); reflexivity.
Qed.

Corollary lookup_insert_eq : forall x vx t,
  BST t -> lookup x (insert x vx t) = Some vx.
Proof. intros. rewrite lookup_insert, Nat.eqb_refl by assumption. reflexivity. Qed.

Corollary lookup_insert_neq : forall x vx t y,
  BST t -> y <> x -> lookup y (insert x vx t) = lookup y t.
Proof.
  intros x vx t y H Hy. rewrite lookup_insert by exact H.
  apply Nat.eqb_neq in Hy. rewrite Hy. reflexivity.
Qed.

(** * The driver computes the specified store

    The specification: the input decoded into lists, and the store as a
    finite map, updated pointwise. *)

Definition store := nat -> option nat.

Definition upd (m : store) (x v : nat) : store :=
  fun y => if y =? x then Some v else m y.

Fixpoint read_regs (k pos : nat) : list (nat * nat) :=
  match k with
  | O => []
  | S k' => (read_u16 pos, read_u16 (pos + key_len)) :: read_regs k' (pos + reg_len)
  end.

Fixpoint read_keys (k pos : nat) : list nat :=
  match k with
  | O => []
  | S k' => read_u16 pos :: read_keys k' (pos + key_len)
  end.

Definition register (m : store) (kc : nat * nat) : store := upd m (fst kc) (snd kc).

Fixpoint answers (qs : list nat) (m : store) : list nat :=
  match qs with
  | [] => []
  | x :: qs' =>
      match m x with
      | Some c => S c :: answers qs' (upd m x (S c))
      | None => 0 :: answers qs' m
      end
  end.

Definition spec (n : nat) : list nat :=
  let q := input_byte 0 in
  answers (read_keys q 1) (fold_left register (read_regs n (1 + key_len * q)) (fun _ => None)).

(** [t] implements [m]. *)
Definition implements (t : tree) (m : store) : Prop :=
  BST t /\ forall y, lookup y t = m y.

Lemma insert_implements : forall t m x v,
  implements t m -> implements (insert x v t) (upd m x v).
Proof.
  intros t m x v [Hb Hl]. split.
  - apply insert_BST, Hb.
  - intro y. rewrite lookup_insert by exact Hb. unfold upd. rewrite Hl. reflexivity.
Qed.

Lemma load_implements : forall k pos t m,
  implements t m -> implements (load k pos t) (fold_left register (read_regs k pos) m).
Proof.
  induction k as [|k IH]; intros pos t m H; cbn [load read_regs fold_left]; auto.
  apply IH. apply insert_implements, H.
Qed.

Lemma answer_implements : forall k pos t m,
  implements t m -> answer k pos t = answers (read_keys k pos) m.
Proof.
  induction k as [|k IH]; intros pos t m H; cbn [answer read_keys answers]; auto.
  unfold assert. pose proof H as [_ Hl]. rewrite Hl.
  destruct (m (read_u16 pos)); f_equal; apply IH; auto using insert_implements.
Qed.

Theorem run_spec : forall n, run n = spec n.
Proof.
  intro n. unfold run, spec. apply answer_implements, load_implements.
  split; [constructor | reflexivity].
Qed.
