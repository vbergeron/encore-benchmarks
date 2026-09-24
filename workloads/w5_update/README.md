# W5 — A/B firmware update with anti-rollback

The update logic of a device with two image slots, in the style of
MCUboot's swap-less "direct-xip with revert" mode. The device boots the
active slot; an update is downloaded into the other one (the spare),
checked against its digest read back from flash, sealed with its version,
and booted on trial. If the new image does not confirm itself before the
next reset, the bootloader goes back to the old one. A confirmed image
raises the anti-rollback counter to its version. The logic is driven by a
stream of events, with power cuts injected between the flash writes of a
command.

- **Program**: `run n` handles the first `n` events of the input from the
  factory state (version 1 in slot A, slot B blank) and returns one answer
  per event: 0 ok, 1 busy (an image is on trial), 2 rollback, 3 command out
  of sequence, 4 bad image, 5 bad event, `8 + v` after a reset that booted
  version `v`. The events are BEGIN, CHUNK, FINISH, CONFIRM and REBOOT,
  and CUT `i` before a command: the power is lost after the first `i` flash
  writes of that command, then the device resets. The encoding is in
  `vectors/vectors.rs`.
- **Model** (`theories/Update.v`): `step` does not write flash itself. It
  returns the list of atomic flash writes (`effect`s) a command performs:
  erase, program a chunk, seal a slot, switch the boot slot, mark the
  trial booted, revert, clear the trial, raise the counter. A cut applies
  a prefix of that list, then the bootloader's own writes. RAM (the
  download in progress) is lost at every reset.
- **Proved** (`theories/Update.v`), with `Inv f`: the booted slot holds a
  valid image not below the anti-rollback counter, and while an image is
  on trial the other slot holds a valid, older image not below the counter:
  - `power_cut_safe`: from any state satisfying `Inv`, for any command, a
    power cut after **any** number of its writes followed by a reset
    leads to a state satisfying `Inv`, where neither the installed version
    (the fallback while on trial, the running image otherwise) nor the
    counter went down. `step_progress`: the same for a command run to its
    end;
  - `exec_progress` and `booted_valid`: the same for any list of events,
    cut anywhere, from the factory state. A valid image not below the
    counter is always the one booted;
  - `rollback_refused`: an image whose version is not above the running
    one is refused before anything is written;
  - `bump_first_unsafe`: the order of CONFIRM's two writes matters. Raising
    the counter before clearing the trial, with a cut in between, makes
    the bootloader revert to an image below the counter. The proof of
    `power_cut_safe` is what rules this order out.
- **N**: number of events, 10, 100, 1000. The stream repeats a 40-event
  cycle that installs the next version and goes through every command and
  answer: a rollback attempt, a download cut before a chunk (the download
  is lost), a cut after the erase, a chunk too many, a bad digest, a cut
  between the seal and the boot-slot switch, BEGIN refused during a trial,
  a trial not confirmed (reverted at the second reset), a trial confirmed
  (even cycles) or cut between its two writes (odd cycles, which leaves
  the counter behind), an unknown event. Four power cuts per cycle, five on
  odd cycles. Images
  are 4 chunks of 16 bytes.
- **Input**: the stream (10.7 KiB for 1000 events) is in flash and read
  byte by byte through the `input_byte` extern
  (`vendor/encore-extraction/ExtrEncoreInput.v`). R reads the same bytes
  from a slice. It writes flash through a `write` method with a budget of
  writes left before the power is lost, the usual way to inject faults in
  firmware tests, not through a list of effects.
- **Trust**: `nat` as VM integers (`ExtrEncore.v`); versions are 16-bit
  and digests below 65521, and `31 · 65520 + 65520` stays below 2^23.
  `input_byte` realised by the host (`ExtrEncoreInput.v`); the constants of
  `Update.v` (event tags, answer codes, digest parameters) extracted to
  literals in `Extract.v`. One extern, no argument beyond N.
- **Heap**: 32 KiB by default (E). `process` is not tail-recursive: each
  event keeps a continuation until the answers are consed on the way back,
  so the live heap grows with N; `cargo xtask minheap` finds 28 KiB for the
  whole case list (N = 1000).
- **C** (CertiRocq): not done yet.

Not modelled: the flash itself (a slot is its trailer, the number of
chunks and a running digest, not its bytes), a real digest or signature
(the polynomial hash stands for the SHA-256 and signature check a
bootloader would call through an extern), writes that are themselves torn
(each effect is atomic, as a trailer written in one flash word is), and
the swap modes of MCUboot, which copy images between slots.
