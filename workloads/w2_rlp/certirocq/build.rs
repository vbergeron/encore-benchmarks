fn main() {
    // Same budget as the E heap: the CertiRocq nursery and generations are
    // carved out of an arena of this size.
    let config = bench_build::configure(20 * 1024);
    // Promoted by `dune build @certirocq` from theories/CompileC.v.
    let generated = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("gen");
    bench_build::certirocq::compile_c(&generated, &config);
}
