// W0 input vectors, shared by every variant through `include!`.
//
// N = length of the list [1..N]. The result N(N+1)/2 must stay below 2^23
// (Encore integers are 24-bit signed): N <= 4095.

/// Size parameter of each case, in increasing order.
pub const CASES: &[u32] = &[1, 10, 100, 1000];
