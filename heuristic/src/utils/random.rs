//! ランダム関連ユーティリティ

pub use rand::prelude::*;

pub fn choose_two<T>(rng: &mut impl Rng, slice: &[T]) -> Option<(usize, usize)> {
    if slice.len() < 2 {
        return None;
    }
    let i = rng.gen_range(0..slice.len());
    let j = rng.gen_range(0..slice.len() - 1);
    let j = if j >= i { j + 1 } else { j };
    Some((i, j))
}
