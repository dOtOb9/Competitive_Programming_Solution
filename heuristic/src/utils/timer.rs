//! # タイマー関連ユーティリティ
//! 
//! 競技プログラミングでの時間制限管理に使用するタイマー機能を提供します。

use std::time::{Duration, Instant};

/// 実行時間制限を管理するタイマー
/// 
/// # 例
/// 
/// ```rust
/// # use heuristic_common::Timer;
/// let timer = Timer::new(2000); // 2秒制限
/// 
/// // 何らかの処理...
/// 
/// if timer.is_time_up() {
///     println!("時間切れ！");
/// }
/// 
/// println!("経過時間: {}ms", timer.elapsed_ms());
/// ```
pub struct Timer {
    start: Instant,
    time_limit: Duration,
}

impl Timer {
    /// 新しいタイマーを作成
    /// 
    /// # 引数
    /// 
    /// * `time_limit_ms` - 制限時間（ミリ秒）
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Timer;
    /// let timer = Timer::new(5000); // 5秒制限
    /// ```
    pub fn new(time_limit_ms: u64) -> Self {
        Self {
            start: Instant::now(),
            time_limit: Duration::from_millis(time_limit_ms),
        }
    }
    
    /// 開始からの経過時間を取得
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Timer;
    /// let timer = Timer::new(1000);
    /// let elapsed = timer.elapsed();
    /// assert!(elapsed.as_millis() < 1000);
    /// ```
    pub fn elapsed(&self) -> Duration {
        self.start.elapsed()
    }
    
    /// 経過時間をミリ秒で取得
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Timer;
    /// let timer = Timer::new(1000);
    /// let elapsed_ms = timer.elapsed_ms();
    /// assert!(elapsed_ms < 1000);
    /// ```
    pub fn elapsed_ms(&self) -> u64 {
        self.elapsed().as_millis() as u64
    }
    
    /// 制限時間に達したかチェック
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Timer;
    /// let timer = Timer::new(1000);
    /// 
    /// // 制限時間内なのでfalse
    /// assert!(!timer.is_time_up());
    /// ```
    pub fn is_time_up(&self) -> bool {
        self.elapsed() >= self.time_limit
    }
    
    /// 残り時間をミリ秒で取得
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Timer;
    /// let timer = Timer::new(1000);
    /// let remaining = timer.remaining_ms();
    /// assert!(remaining <= 1000);
    /// ```
    pub fn remaining_ms(&self) -> u64 {
        self.time_limit.saturating_sub(self.elapsed()).as_millis() as u64
    }
}
