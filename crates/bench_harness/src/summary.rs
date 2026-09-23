//! Order statistics over a buffer of samples, computed on the device so that
//! only four numbers per case leave it.

/// Summary of `runs` samples. When `cycles` is false the samples came from a
/// counter that does not exist on this board and only `runs` is meaningful.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct Summary {
    pub runs: u32,
    pub cycles: bool,
    pub min: u32,
    pub median: u32,
    pub p99: u32,
    pub max: u32,
}

impl Summary {
    /// Sorts `samples` in place. The median of an even count is the lower
    /// middle value; p99 is the nearest-rank percentile.
    pub fn from_samples(samples: &mut [u32], cycles: bool) -> Summary {
        let n = samples.len();
        if n == 0 {
            return Summary { cycles, ..Summary::default() };
        }
        samples.sort_unstable();
        Summary {
            runs: n as u32,
            cycles,
            min: samples[0],
            median: samples[(n - 1) / 2],
            p99: samples[nearest_rank(n, 99)],
            max: samples[n - 1],
        }
    }
}

/// Zero-based index of the `pct`-th percentile by the nearest-rank method.
fn nearest_rank(n: usize, pct: usize) -> usize {
    ((pct * n).div_ceil(100)).clamp(1, n) - 1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn summary_of_1_to_1000() {
        let mut v: [u32; 1000] = core::array::from_fn(|i| 1000 - i as u32);
        let s = Summary::from_samples(&mut v, true);
        assert_eq!((s.runs, s.min, s.median, s.p99, s.max), (1000, 1, 500, 990, 1000));
    }

    #[test]
    fn single_sample() {
        let s = Summary::from_samples(&mut [7], false);
        assert_eq!((s.runs, s.min, s.median, s.p99, s.max), (1, 7, 7, 7, 7));
    }

    #[test]
    fn empty() {
        assert_eq!(Summary::from_samples(&mut [], true).runs, 0);
    }
}
