fn main() {
    // The arena gets the same number of bytes as this workload's Encore
    // heap (encore/build.rs). It holds the 4 KiB thread_info, the nursery
    // and the generations; the C stack, which direct-style code also uses
    // for its recursion, is what is left of the RAM budget.
    let config = bench_build::configure(32 * 1024);
    // Promoted by `dune build @certirocq` from theories/CompileC.v.
    let generated = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("gen");
    bench_build::certirocq::compile_c(&generated, &config);
}
