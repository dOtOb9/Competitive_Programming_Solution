//! # AHC共通ライブラリ
//! 
//! ヒューリスティックコンテスト用の共通機能を提供するライブラリです。
//! 
//! ## 主な機能
//! 
//! - **グリッド操作**: 2D座標とグリッドの操作
//! - **ユーティリティ**: ランダム関数、タイマー、デバッグ支援
//! - **アルゴリズム**: よく使用されるアルゴリズムの実装
//! - **入出力**: 標準的な入出力処理
//! - **ビジュアライザー**: デバッグ用データ出力支援
//! 
//! ## 使用例
//! 
//! ```rust
//! use heuristic_common::*;
//! 
//! fn main() {
//!     // グリッドの作成
//!     let mut grid = Grid::new(10, 10, 0);
//!     let pos = Pos::new(5, 5);
//!     grid.set(pos, 42);
//!     
//!     // タイマーの使用
//!     let timer = Timer::new(2000); // 2秒制限
//!     
//!     // デバッグ出力
//!     debug!("Current position: {:?}", pos);
//!     
//!     // 時間測定
//!     let result = measure_time!("calculation", {
//!         // 重い計算処理
//!         42
//!     });
//! }
//! ```
//! 
//! ## モジュール構成
//! 
//! - [`utils`]: ユーティリティ関数（グリッド、ランダム、タイマー）
//! - [`algorithms`]: アルゴリズム実装
//! - [`io`]: 入出力処理
//! - [`visualization`]: ビジュアライザー支援

pub mod utils;
pub mod algorithms;
pub mod io;
pub mod visualization;

// よく使用される型のre-export
pub use utils::*;
pub use algorithms::*;
pub use io::*;

// 共通的に使用されるクレートのre-export
pub use itertools::Itertools;
pub use rand::prelude::*;
pub use rustc_hash::{FxHashMap, FxHashSet};

/// 共通的に使用される型エイリアス
pub type HashMap<K, V> = FxHashMap<K, V>;
pub type HashSet<T> = FxHashSet<T>;

/// デバッグビルド時のみ出力されるデバッグマクロ
/// 
/// # 例
/// 
/// ```rust
/// # use heuristic_common::debug;
/// let x = 42;
/// debug!("x = {}", x); // デバッグビルド時のみ stderr に出力
/// ```
#[macro_export]
macro_rules! debug {
    ($($arg:tt)*) => {
        #[cfg(debug_assertions)]
        eprintln!($($arg)*);
    };
}

/// 実行時間を測定するマクロ
/// 
/// ブロックの実行時間を測定し、デバッグビルド時にラベル付きで出力します。
/// 
/// # 例
/// 
/// ```rust
/// # use heuristic_common::measure_time;
/// let result = measure_time!("heavy_calculation", {
///     // 重い計算処理
///     (0..1000).sum::<i32>()
/// });
/// // デバッグビルド時: "heavy_calculation: 0.123ms" が出力される
/// ```
#[macro_export]
macro_rules! measure_time {
    ($label:expr, $block:block) => {{
        let start = std::time::Instant::now();
        let result = $block;
        let elapsed = start.elapsed();
        debug!("{}: {:.3}ms", $label, elapsed.as_millis());
        result
    }};
}
