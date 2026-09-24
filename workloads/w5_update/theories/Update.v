(** W5 — A/B firmware update with anti-rollback, driven by a stream of
    update events, with power cuts injected between any two flash writes.

    The device has two image slots. It boots the [active] one; the other
    one, the [spare], receives the next image. An update erases the spare,
    programs it chunk by chunk, checks its digest read back from flash,
    seals it with its version and makes it active on trial ([pending]).
    The bootloader boots a pending image once ([tried]); if the image does
    not confirm itself before the next reset, the bootloader reverts to the
    other slot. A confirmed image raises the anti-rollback counter
    ([floor]) to its version.

    Every change to persistent state is an [effect], one atomic flash
    write. [step] decides which effects a command performs; a power cut can
    stop it after any prefix of them, and RAM (the download in progress)
    is lost. The two properties that matter, proved below for every state
    reachable that way:
    - the installed version never decreases, and the anti-rollback counter
      never goes down;
    - after a power cut at any point, the slot the bootloader boots holds a
      valid image whose version is not below the counter. *)

From Stdlib Require Import Arith List Lia Bool.
Import ListNotations.
From Encore.Extraction Require Import ExtrEncoreInput.

(** Constants. Each one is extracted to a VM integer literal by
    [Extract.v]: a [nat] literal would otherwise extract to a chain of
    successor applications. *)
Definition byte_base := 256.
Definition modulus := 65521.     (* largest prime below 2^16 *)
Definition radix := 31.
Definition factory_version := 1.
(** Event tags of the input stream. *)
Definition ev_begin := 1.
Definition ev_chunk := 2.
Definition ev_finish := 3.
Definition ev_confirm := 4.
Definition ev_reboot := 5.
Definition ev_cut := 6.
(** Response codes. *)
Definition code_busy := 1.
Definition code_rollback := 2.
Definition code_unexpected := 3.
Definition code_bad_image := 4.
Definition code_bad_event := 5.
Definition code_booted := 8.

(** * Persistent state *)

Inductive slot_id := SA | SB.

Definition other (i : slot_id) : slot_id :=
  match i with SA => SB | SB => SA end.

(** A slot: whether it holds a sealed image, the version in its trailer,
    and what has been programmed (number of chunks and running digest). *)
Record slot := mk_slot {
  valid : bool;
  ver : nat;
  len : nat;
  sum : nat
}.

Record flash := mk_flash {
  slot_a : slot;
  slot_b : slot;
  active : slot_id;   (* the slot the bootloader boots *)
  pending : bool;     (* the active image is on trial *)
  tried : bool;       (* ... and has been booted once *)
  floor : nat         (* anti-rollback counter *)
}.

Definition get (f : flash) (i : slot_id) : slot :=
  match i with SA => slot_a f | SB => slot_b f end.

Definition put (f : flash) (i : slot_id) (s : slot) : flash :=
  match i with
  | SA => mk_flash s (slot_b f) (active f) (pending f) (tried f) (floor f)
  | SB => mk_flash (slot_a f) s (active f) (pending f) (tried f) (floor f)
  end.

Definition spare (f : flash) : slot_id := other (active f).
Definition cur (f : flash) : slot := get f (active f).

(** The digest: a polynomial hash modulo a prime, a stand-in for the
    SHA-256 a real bootloader would call through an extern. *)
Definition mix (acc d : nat) : nat := (acc * radix + d) mod modulus.
Arguments mix : simpl never.

(** * Effects: atomic flash writes *)

Inductive effect :=
| Erase (i : slot_id)
| Program (i : slot_id) (d : nat)   (* append a chunk of digest [d] *)
| Seal (i : slot_id) (v : nat)      (* write the trailer: valid, version [v] *)
| SetBoot (i : slot_id)             (* boot [i] next, on trial *)
| MarkTried
| Revert                            (* back to the other slot *)
| ClearPending
| Bump (v : nat).                   (* anti-rollback counter *)

Definition apply (f : flash) (e : effect) : flash :=
  match e with
  | Erase i => put f i (mk_slot false 0 0 0)
  | Program i d =>
      let s := get f i in put f i (mk_slot false (ver s) (S (len s)) (mix (sum s) d))
  | Seal i v => let s := get f i in put f i (mk_slot true v (len s) (sum s))
  | SetBoot i => mk_flash (slot_a f) (slot_b f) i true false (floor f)
  | MarkTried => mk_flash (slot_a f) (slot_b f) (active f) (pending f) true (floor f)
  | Revert => mk_flash (slot_a f) (slot_b f) (other (active f)) false false (floor f)
  | ClearPending => mk_flash (slot_a f) (slot_b f) (active f) false false (floor f)
  | Bump v => mk_flash (slot_a f) (slot_b f) (active f) (pending f) (tried f) v
  end.

Definition apply_all (f : flash) (es : list effect) : flash := fold_left apply es f.

(** The bootloader, at every reset: a pending image is booted once, then
    reverted if it is still pending at the next reset. *)
Definition boot_effects (f : flash) : list effect :=
  if pending f then (if tried f then [Revert] else [MarkTried]) else [].

Definition boot (f : flash) : flash := apply_all f (boot_effects f).

(** * Commands *)

(** RAM: the download in progress, lost at reset. *)
Inductive ram :=
| Idle
| Loading (v size got : nat).

Inductive cmd :=
| Begin (v size : nat)     (* start downloading version [v], [size] chunks *)
| Chunk (d : nat)          (* one chunk, by its digest *)
| Finish (digest : nat)    (* end of the download, expected image digest *)
| Confirm                  (* the running image confirms itself *)
| Reboot
| Unknown.

Inductive resp :=
| Ok
| Busy          (* an image is on trial: the fallback slot must not be erased *)
| Rollback      (* version not above the running one *)
| Unexpected    (* command out of sequence *)
| BadImage      (* digest mismatch *)
| BadEvent
| Booted (v : nat).

Definition step (f : flash) (r : ram) (c : cmd) : ram * list effect * resp :=
  match c with
  | Begin v size =>
      if pending f then (r, [], Busy)
      else if v <=? ver (cur f) then (r, [], Rollback)
      else (Loading v size 0, [Erase (spare f)], Ok)
  | Chunk d =>
      match r with
      | Loading v size got =>
          if negb (pending f) && (got <? size)
          then (Loading v size (S got), [Program (spare f) d], Ok)
          else (r, [], Unexpected)
      | Idle => (r, [], Unexpected)
      end
  | Finish digest =>
      match r with
      | Loading v size got =>
          if pending f || negb (got =? size) || (v <=? ver (cur f))
          then (r, [], Unexpected)
          else if sum (get f (spare f)) =? digest
          then (Idle, [Seal (spare f) v; SetBoot (spare f)], Ok)
          else (Idle, [], BadImage)
      | Idle => (r, [], Unexpected)
      end
  | Confirm =>
      (* The order matters: see [bump_first_unsafe]. *)
      if pending f && tried f then (r, [ClearPending; Bump (ver (cur f))], Ok)
      else (r, [], Unexpected)
  | Reboot => (Idle, boot_effects f, Booted (ver (cur (boot f))))
  | Unknown => (r, [], BadEvent)
  end.

Definition effects (f : flash) (r : ram) (c : cmd) : list effect :=
  snd (fst (step f r c)).

(** An event of the trace: a command, or a command cut by a power failure
    after its first [i] effects, followed by a reset. *)
Inductive event :=
| Do (c : cmd)
| Cut (i : nat) (c : cmd).

Definition code (x : resp) : nat :=
  match x with
  | Ok => 0
  | Busy => code_busy
  | Rollback => code_rollback
  | Unexpected => code_unexpected
  | BadImage => code_bad_image
  | BadEvent => code_bad_event
  | Booted v => code_booted + v
  end.

Definition handle (f : flash) (r : ram) (e : event) : flash * ram * nat :=
  match e with
  | Do c =>
      let '(r', es, x) := step f r c in (apply_all f es, r', code x)
  | Cut i c =>
      let f' := boot (apply_all f (firstn i (effects f r c))) in
      (f', Idle, code (Booted (ver (cur f'))))
  end.

(** * Driver: events from the input buffer *)

Definition read_u16 (pos : nat) : nat :=
  input_byte pos * byte_base + input_byte (S pos).

Fixpoint digest (acc pos k : nat) {struct k} : nat :=
  match k with
  | O => acc
  | S k' => digest (mix acc (input_byte pos)) (S pos) k'
  end.

(** The command at [pos], and the position after it. Encoding:
    [1 v(2) size] begin, [2 n data(n)] chunk, [3 digest(2)] finish,
    [4] confirm, [5] reboot; any other tag is one byte, unknown. *)
Definition decode_cmd (pos : nat) : cmd * nat :=
  let t := input_byte pos in
  if t =? ev_begin then (Begin (read_u16 (S pos)) (input_byte (S (S (S pos)))), S (S (S (S pos))))
  else if t =? ev_chunk then
    let n := input_byte (S pos) in (Chunk (digest 0 (S (S pos)) n), S (S pos) + n)
  else if t =? ev_finish then (Finish (read_u16 (S pos)), S (S (S pos)))
  else if t =? ev_confirm then (Confirm, S pos)
  else if t =? ev_reboot then (Reboot, S pos)
  else (Unknown, S pos).

(** [6 i] before a command cuts the power after its first [i] effects. *)
Definition decode (pos : nat) : event * nat :=
  if input_byte pos =? ev_cut then
    let (c, pos') := decode_cmd (S (S pos)) in (Cut (input_byte (S pos)) c, pos')
  else let (c, pos') := decode_cmd pos in (Do c, pos').

(** Handle [k] events starting at byte [pos] of the input. *)
Fixpoint process (k : nat) (f : flash) (r : ram) (pos : nat) : list nat :=
  match k with
  | O => []
  | S k' =>
      let (e, pos') := decode pos in
      let '(f', r', x) := handle f r e in
      x :: process k' f' r' pos'
  end.

(** Factory state: version 1 in slot A, slot B blank. *)
Definition init : flash :=
  mk_flash (mk_slot true factory_version 0 0) (mk_slot false 0 0 0) SA false false factory_version.

Definition run (n : nat) : list nat := process n init Idle 0.

(** * Properties *)

(** The version the device is committed to: the fallback while an image
    is on trial, the running image otherwise. *)
Definition installed (f : flash) : nat :=
  if pending f then ver (get f (spare f)) else ver (cur f).

(** The bootloader boots a valid image not below the counter; while an
    image is on trial, the fallback is valid too, not below the counter,
    and older than the image on trial. *)
Definition Inv (f : flash) : Prop :=
  valid (cur f) = true /\ floor f <= ver (cur f) /\
  (pending f = true ->
   valid (get f (spare f)) = true /\ floor f <= ver (get f (spare f)) /\
   ver (get f (spare f)) < ver (cur f)).

(** [f'] is a safe successor of [f]. *)
Definition progress (f f' : flash) : Prop :=
  Inv f' /\ installed f <= installed f' /\ floor f <= floor f'.

Lemma progress_refl : forall f, Inv f -> progress f f.
Proof. intros f H. split; [exact H | split; apply Nat.le_refl]. Qed.

Lemma progress_trans : forall f g h, progress f g -> progress g h -> progress f h.
Proof. unfold progress. intros f g h (_ & ? & ?) (? & ? & ?). split; [assumption | split; lia]. Qed.

(** Every prefix of [es] leads from [f] to a safe successor. *)
Fixpoint safe (f : flash) (es : list effect) : Prop :=
  match es with
  | [] => True
  | e :: es' => progress f (apply f e) /\ safe (apply f e) es'
  end.

Lemma safe_prefix : forall es f i,
  Inv f -> safe f es -> progress f (apply_all f (firstn i es)).
Proof.
  induction es as [|e es IH]; intros f i Hf Hs.
  - rewrite firstn_nil. apply progress_refl, Hf.
  - destruct i as [|i]; cbn; [apply progress_refl, Hf|].
    destruct Hs as [He Hs]. eapply progress_trans; [exact He|].
    apply IH; [apply He | exact Hs].
Qed.

Lemma safe_all : forall es f, Inv f -> safe f es -> progress f (apply_all f es).
Proof.
  intros es f Hf Hs. rewrite <- (firstn_all es). apply safe_prefix; auto.
Qed.

(** Case analysis on a flash state and the tests of [step]. *)
Ltac flash_cases :=
  match goal with
  | f : flash |- _ =>
      let act := fresh "act" in let p := fresh "p" in let t := fresh "t" in
      destruct f as [[? ? ? ?] [? ? ? ?] act p t ?];
      unfold progress in *; unfold Inv, installed, spare, cur in *; cbn in *;
      destruct act, p, t; cbn in *
  end.

Ltac solve_flash :=
  unfold progress in *; unfold Inv, installed, spare, cur in *; cbn in *;
  repeat match goal with
  | H : _ /\ _ |- _ => destruct H
  | |- _ /\ _ => split
  | |- _ -> _ => intro
  | H : true = true -> _ |- _ => specialize (H eq_refl)
  | |- True => exact I
  end;
  first [ reflexivity | discriminate | assumption | lia ].

Lemma boot_safe : forall f, Inv f -> safe f (boot_effects f).
Proof. intros f H. unfold boot_effects. flash_cases; solve_flash. Qed.

Lemma boot_progress : forall f, Inv f -> progress f (boot f).
Proof. intros f H. apply safe_all, boot_safe; exact H. Qed.

Lemma step_safe : forall f r c, Inv f -> safe f (effects f r c).
Proof.
  intros f r c H. unfold effects, step.
  destruct c as [v size|d|dg| | |]; [| destruct r as [|v size got] ..
    | unfold boot_effects | ]; cbn [fst snd];
  flash_cases;
  repeat match goal with
  | |- context [?a <=? ?b] => destruct (Nat.leb_spec a b)
  | |- context [?a <? ?b] => destruct (Nat.ltb_spec a b)
  | |- context [?a =? ?b] => destruct (a =? b)
  | |- context [match ?n with 0 => _ | S _ => _ end] => destruct n
  end; cbn; solve_flash.
Qed.

(** Anti-rollback, at every step: a command run to completion keeps the
    invariant, never lowers the installed version or the counter. *)
Theorem step_progress : forall f r c, Inv f -> progress f (apply_all f (effects f r c)).
Proof. intros. apply safe_all, step_safe; assumption. Qed.

(** A power cut after any number of the effects of any command, then a
    reset: the bootloader boots a valid image, not below the counter, and
    neither the installed version nor the counter went down. *)
Theorem power_cut_safe : forall f r c i,
  Inv f -> progress f (boot (apply_all f (firstn i (effects f r c)))).
Proof.
  intros f r c i H. pose proof (safe_prefix _ _ i H (step_safe f r c H)) as Hp.
  eapply progress_trans; [exact Hp|]. apply boot_progress, Hp.
Qed.

Theorem handle_progress : forall f r e,
  Inv f -> progress f (fst (fst (handle f r e))).
Proof.
  intros f r [c|i c] H; cbn.
  - pose proof (step_progress f r c H) as Hp. unfold effects in Hp.
    destruct (step f r c) as [[r' es] x]. exact Hp.
  - apply power_cut_safe, H.
Qed.

Lemma init_inv : Inv init.
Proof. unfold Inv, init, factory_version. cbn. repeat split; auto; discriminate. Qed.

(** Any trace of events, cut anywhere. *)
Fixpoint exec (f : flash) (r : ram) (es : list event) : flash :=
  match es with
  | [] => f
  | e :: es' => let '(f', r', _) := handle f r e in exec f' r' es'
  end.

Theorem exec_progress : forall es f r, Inv f -> progress f (exec f r es).
Proof.
  induction es as [|e es IH]; intros f r H; cbn; [apply progress_refl, H|].
  pose proof (handle_progress f r e H) as Hp.
  destruct (handle f r e) as [[f' r'] x]. cbn in Hp.
  eapply progress_trans; [exact Hp|]. apply IH, Hp.
Qed.

(** From the factory state, whatever the events and wherever the power is
    cut: the booted slot holds a valid image not below the counter. *)
Corollary booted_valid : forall es r,
  let f := exec init r es in
  valid (cur f) = true /\ floor f <= ver (cur f) /\
  factory_version <= installed f /\ factory_version <= floor f.
Proof.
  intros es r f. destruct (exec_progress es init r init_inv) as ((? & ? & _) & ? & ?).
  repeat split; assumption.
Qed.

(** An image not above the running one is refused, and nothing is
    written. *)
Theorem rollback_refused : forall f r v size,
  pending f = false -> v <= ver (cur f) ->
  step f r (Begin v size) = (r, [], Rollback).
Proof.
  intros f r v size Hp Hv. cbn. rewrite Hp.
  apply Nat.leb_le in Hv. rewrite Hv. reflexivity.
Qed.

(** Confirm must clear the trial flag before it raises the counter: the
    other order, cut in between, reverts to an image below the counter. *)
Remark bump_first_unsafe :
  let f := mk_flash (mk_slot true 1 0 0) (mk_slot true 2 0 0) SB true true 1 in
  Inv f /\ ~ Inv (boot (apply f (Bump (ver (cur f))))).
Proof. cbn. unfold Inv. cbn. split; [repeat split; lia | intros (_ & H & _); lia]. Qed.
