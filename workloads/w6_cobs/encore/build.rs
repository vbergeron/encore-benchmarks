fn main() {
    let config = bench_build::configure(40 * 1024);
    // Promoted by `dune build` from theories/Extract.v.
    let scm = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../theories/w6_cobs.scm");
    bench_build::encore::compile_scheme(&scm, &config);
}
