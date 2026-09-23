//! What the host reads from a firmware ELF: marker addresses and sizes.

use std::collections::HashMap;
use std::fs;
use std::path::Path;

use object::elf::{SHF_ALLOC, SHF_EXECINSTR, SHF_WRITE};
use object::{
    Object, ObjectSection, ObjectSymbol, SectionFlags, SectionIndex, SectionKind, SymbolKind,
};
use serde_json::{Map, Value, json};

use crate::die;

fn read(elf: &Path) -> Vec<u8> {
    fs::read(elf).unwrap_or_else(|e| die(&format!("cannot read {}: {e}", elf.display())))
}

fn parse<'a>(elf: &Path, data: &'a [u8]) -> object::File<'a> {
    object::File::parse(data)
        .unwrap_or_else(|e| die(&format!("{}: not an ELF: {e}", elf.display())))
}

/// Address of a (Thumb) function, without the Thumb bit.
pub fn symbol_addr(elf: &Path, name: &str) -> Option<u64> {
    let data = read(elf);
    let file = parse(elf, &data);
    file.symbols()
        .find(|s| s.name() == Ok(name))
        .map(|s| s.address() & !1)
}

const FLASH_SECTIONS: [&str; 4] = [".vector_table", ".text", ".rodata", ".data"];
const RAM_SECTIONS: [&str; 3] = [".data", ".bss", ".uninit"];

/// Where a symbol's bytes live, as `nm` would letter it.
#[derive(Clone, Copy, PartialEq)]
enum Place {
    Flash,
    Ram,
    Other,
}

fn place(flags: SectionFlags) -> Place {
    let SectionFlags::Elf { sh_flags } = flags else {
        return Place::Other;
    };
    let (alloc, write, exec) = (
        sh_flags & u64::from(SHF_ALLOC) != 0,
        sh_flags & u64::from(SHF_WRITE) != 0,
        sh_flags & u64::from(SHF_EXECINSTR) != 0,
    );
    match (alloc, write, exec) {
        (true, _, true) | (true, false, false) => Place::Flash,
        (true, true, false) => Place::Ram,
        _ => Place::Other,
    }
}

/// Flash and RAM breakdown of a firmware ELF.
pub fn size_report(elf: &Path) -> Value {
    let data = read(elf);
    let file = parse(elf, &data);

    let mut sections = Map::new();
    let mut places: HashMap<SectionIndex, Place> = HashMap::new();
    for s in file.sections() {
        places.insert(s.index(), place(s.flags()));
        let Ok(name) = s.name() else { continue };
        let skipped = [".debug", ".comment", ".ARM.attributes"];
        if !name.starts_with('.')
            || s.kind() == SectionKind::Metadata
            || skipped.iter().any(|p| name.starts_with(p))
        {
            continue;
        }
        sections.insert(name.to_owned(), json!(s.size()));
    }
    let sum = |names: &[&str]| -> u64 {
        sections
            .iter()
            .filter(|(k, _)| names.contains(&k.as_str()))
            .map(|(_, v)| v.as_u64().unwrap_or(0))
            .sum()
    };
    let flash_bytes = sum(&FLASH_SECTIONS);
    let ram_static_bytes = sum(&RAM_SECTIONS);

    // Attribution by crate, from demangled symbol names. With LTO, code
    // inlined into a caller counts for the caller's crate: an estimate.
    let mut symbols: Vec<(u64, String, Place)> = file
        .symbols()
        .filter(|s| s.size() > 0 && !s.is_undefined())
        .filter(|s| !matches!(s.kind(), SymbolKind::Section | SymbolKind::File))
        .filter_map(|s| {
            let at = places
                .get(&s.section_index()?)
                .copied()
                .unwrap_or(Place::Other);
            let name = s.name().ok()?;
            Some((s.size(), demangle(name), at))
        })
        .collect();
    symbols.sort_by(|a, b| (a.0, &a.1).cmp(&(b.0, &b.1)));

    let mut by_crate: Vec<(String, u64)> = Vec::new();
    let mut ram_symbols: Vec<(String, u64)> = Vec::new();
    for (size, name, at) in symbols {
        match at {
            Place::Flash => {
                let krate = crate_of(&name);
                match by_crate.iter_mut().find(|(k, _)| *k == krate) {
                    Some((_, total)) => *total += size,
                    None => by_crate.push((krate, size)),
                }
            }
            Place::Ram => match ram_symbols.iter_mut().find(|(k, _)| *k == name) {
                Some((_, s)) => *s = size,
                None => ram_symbols.push((name, size)),
            },
            Place::Other => {}
        }
    }
    by_crate.sort_by(|a, b| b.1.cmp(&a.1));
    ram_symbols.sort_by(|a, b| b.1.cmp(&a.1));
    ram_symbols.truncate(8);
    let object = |kv: Vec<(String, u64)>| {
        Value::Object(kv.into_iter().map(|(k, v)| (k, json!(v))).collect())
    };

    json!({
        "flash_bytes": flash_bytes,
        "ram_static_bytes": ram_static_bytes,
        "sections": sections,
        "flash_by_crate": object(by_crate),
        "ram_symbols": object(ram_symbols),
    })
}

/// Demangled name without its hash, and without the `.0`-style suffix LLVM
/// appends to legacy Rust symbols (`nm -C` hides both).
fn demangle(name: &str) -> String {
    let name = name.strip_prefix("_ZN").map_or(name, |body| {
        // Length-prefixed identifiers up to the closing `E`.
        let mut i = 0;
        while let Some(len) = body[i..]
            .find(|c: char| !c.is_ascii_digit())
            .filter(|&d| d > 0)
        {
            let n: usize = body[i..i + len].parse().unwrap_or(usize::MAX);
            i = i.saturating_add(len).saturating_add(n);
            if i >= body.len() || !body.is_char_boundary(i) {
                return name;
            }
        }
        if body.as_bytes().get(i) == Some(&b'E') {
            &name[..3 + i + 1]
        } else {
            name
        }
    });
    format!("{:#}", rustc_demangle::demangle(name))
}

/// Crate a demangled symbol belongs to. For `<T as Trait>::f`, the crate of
/// `T` when it is a path, else the crate of `Trait` (`<str as
/// core::fmt::Display>` is core's).
pub fn crate_of(symbol: &str) -> String {
    let path = match qualified(symbol) {
        Some((self_ty, tr)) => {
            let self_ty = self_ty.trim_start_matches(['&', '*']);
            let self_ty = self_ty.strip_prefix("mut ").unwrap_or(self_ty);
            if self_ty.contains("::") { self_ty } else { tr }
        }
        None => symbol.trim_start_matches('<'),
    };
    match path.split_once("::") {
        Some((krate, _)) => krate.to_owned(),
        None => "(c/asm)".to_owned(),
    }
}

/// `<T as Trait>::…` → `(T, Trait)`, taking the shortest `T` and then the
/// shortest `Trait` that make the pattern match.
fn qualified(symbol: &str) -> Option<(&str, &str)> {
    let rest = symbol.strip_prefix('<')?;
    let mut from = 0;
    while let Some(i) = rest[from..].find(" as ") {
        let (self_ty, after) = (&rest[..from + i], &rest[from + i + 4..]);
        if !self_ty.is_empty() {
            let skip = after.chars().next().map_or(0, char::len_utf8);
            if let Some(j) = after[skip..].find(">::").filter(|_| skip > 0) {
                return Some((self_ty, &after[..skip + j]));
            }
        }
        from += i + 1;
    }
    None
}

#[cfg(test)]
mod tests {
    use super::{crate_of, demangle};

    #[test]
    fn demangled() {
        let taken = "_ZN8cortex_m10peripheral5TAKEN17h989da3b22e0db698E.0";
        assert_eq!(demangle(taken), "cortex_m::peripheral::TAKEN");
        assert_eq!(
            demangle("_ZN4core3fmt5write17h0123456789abcdefE"),
            "core::fmt::write"
        );
        assert_eq!(demangle(".Lanon.fad58de7.10"), ".Lanon.fad58de7.10");
        assert_eq!(demangle("_ZN3foo"), "_ZN3foo");
        assert_eq!(demangle("memcpy"), "memcpy");
    }

    #[test]
    fn crates() {
        assert_eq!(crate_of("core::fmt::write"), "core");
        assert_eq!(crate_of("<str as core::fmt::Display>::fmt"), "core");
        assert_eq!(
            crate_of("<&mut bench_harness::X as core::fmt::Write>::write_str"),
            "bench_harness"
        );
        assert_eq!(crate_of("<w0_smoke_r::A>::f"), "w0_smoke_r");
        assert_eq!(crate_of("memcpy"), "(c/asm)");
    }
}
