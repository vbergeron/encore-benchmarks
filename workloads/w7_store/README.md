# W7 — FIDO credential store (persistent red-black tree)

The resident-credential store of a FIDO authenticator: credentials are
kept by handle, each with the signature counter that the authenticator
increments on every assertion (a relying party rejects a counter that does
not go up, which is how a cloned key is detected). The store is Okasaki's
red-black tree, the `rbtree` micro-benchmark of the paper, here with a
real use and a scale-up to 500 entries.

- **Program**: `run n` registers the first `n` credentials of the input in
  an empty store (a handle already there gets the new counter), then
  answers the input's 32 assertions in order: 0 if the credential is
  unknown, otherwise its new counter, the stored one plus one, which the
  store keeps. Every registration and every successful assertion is a
  persistent `insert`: it copies the path from the root and leaves the old
  nodes to the collector.
- **Proved** (`theories/Store.v`):
  - `insert_RB`: `insert` keeps the red-black invariants (no red node with
    a red child, same number of black nodes on every path); `load_RB` and
    `assert_RB`: so do the driver's two steps;
  - `RB_depth`, `RB_size`: a red-black tree of black height `h` has depth
    at most `2h + 1` and at least `2^h - 1` entries, so a lookup or an
    insert visits O(log n) nodes;
  - `insert_BST`: `insert` keeps the search-tree order;
  - `lookup_insert` (and `lookup_insert_eq`, `lookup_insert_neq`): after
    `insert x v`, `lookup x` finds `v`, and every other handle finds what
    it found before;
  - `run_spec`: the in-place driver computes the answers of the store
    specified as a finite map (`store := nat -> option nat`, updated
    pointwise) over the registrations and the assertions that the decoders
    of `Store.v` read from the input. It holds for any input, with no
    hypothesis on the bytes.
- **N**: number of registrations, 10, 50, 100, 500 (`vectors/vectors.rs`).
  Handles are odd, pseudo-random and distinct, except that every 50th
  registration re-registers the handle of 7 registrations earlier. The 32
  assertions are the same for every N: by groups of four, a registration
  spread over the whole stream (more of them hit as N grows), an even
  handle (never registered), the previous hit asserted again (its counter
  goes up twice), a registration among the first hundred (one of them a
  re-registered handle). They hit 3, 8, 14 and 24 times: the hashes differ
  for each N.
- **Input**: the assertions and the registrations (2 KiB for 500) are in
  flash and read byte by byte through the `input_byte` extern
  (`vendor/encore-extraction/ExtrEncoreInput.v`). R reads the same bytes
  from a slice, and keeps the store as a sorted array (binary search, a
  shift to insert): no allocator, and the store is rebuilt at each run.
- **Trust**: `nat` as VM integers (`ExtrEncore.v`); handles and counters
  are 16-bit and a counter goes up at most 32 times, far below 2^23.
  `input_byte` realised by the host (`ExtrEncoreInput.v`); the layout
  constants of `Store.v` extracted to literals in `Extract.v`. One extern,
  no argument beyond N.
- **Heap**: 32 KiB by default (E). A node is a 5-field constructor, 24
  bytes, so 500 credentials are 11.7 KiB live; `cargo xtask minheap` finds
  12.75 KiB for the whole case list. The heap peak reaches the whole heap
  from N = 50 up only because the collector runs when it is full.
- **C** (CertiRocq): not done yet.

Not modelled: deletion (a red-black delete is the other half of a real
store, and a much longer proof), the credential itself (key pair, user and
relying-party data stay in the Rust layer, found by handle), handles as the
16 to 64-byte credential IDs of CTAP2 (W3 shows the cost of comparing byte
strings), and persistence to flash.
