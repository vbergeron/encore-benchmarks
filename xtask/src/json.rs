//! JSON in the layout `results/benchmarks.jsonl` has always used: one object
//! per line, `", "` between items and `": "` after keys, keys in insertion
//! order (serde_json's `preserve_order`).

use std::io;

use serde::Serialize;
use serde_json::ser::Formatter;

struct Spaced;

impl Formatter for Spaced {
    fn begin_array_value<W: ?Sized + io::Write>(
        &mut self,
        w: &mut W,
        first: bool,
    ) -> io::Result<()> {
        if first { Ok(()) } else { w.write_all(b", ") }
    }

    fn begin_object_key<W: ?Sized + io::Write>(
        &mut self,
        w: &mut W,
        first: bool,
    ) -> io::Result<()> {
        if first { Ok(()) } else { w.write_all(b", ") }
    }

    fn begin_object_value<W: ?Sized + io::Write>(&mut self, w: &mut W) -> io::Result<()> {
        w.write_all(b": ")
    }
}

/// One line of JSONL.
pub fn line<T: Serialize>(value: &T) -> String {
    let mut out = Vec::new();
    let mut ser = serde_json::Serializer::with_formatter(&mut out, Spaced);
    value.serialize(&mut ser).expect("serializing JSON");
    String::from_utf8(out).expect("serde_json writes UTF-8")
}

#[cfg(test)]
mod tests {
    use serde_json::json;

    #[test]
    fn spaced_like_the_results_file() {
        let v = json!({"a": 1, "b": [1, 2], "c": {"d": null}});
        assert_eq!(
            super::line(&v),
            r#"{"a": 1, "b": [1, 2], "c": {"d": null}}"#
        );
    }
}
