//! グリッド操作ユーティリティ
//! 
//! 2次元グリッドでの座標操作と近傍探索などの機能を提供します。

/// 2D座標を表す構造体
/// 
/// # 例
/// 
/// ```rust
/// # use heuristic_common::Pos;
/// let pos = Pos::new(3, 4);
/// assert_eq!(pos.row, 3);
/// assert_eq!(pos.col, 4);
/// 
/// // 4近傍の取得
/// let neighbors = pos.neighbors4(10, 10);
/// assert!(neighbors.len() <= 4);
/// ```
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct Pos {
    /// 行座標（縦方向、上から下へ）
    pub row: usize,
    /// 列座標（横方向、左から右へ）
    pub col: usize,
}

impl Pos {
    /// 新しい座標を作成
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Pos;
    /// let pos = Pos::new(2, 3);
    /// ```
    pub fn new(row: usize, col: usize) -> Self {
        Self { row, col }
    }
    
    /// 隣接する4方向の座標を返す
    /// 
    /// グリッドの境界内の座標のみを返します。
    /// 
    /// # 引数
    /// 
    /// * `height` - グリッドの高さ
    /// * `width` - グリッドの幅
    /// 
    /// # 例
    /// 
    /// ```rust
    /// # use heuristic_common::Pos;
    /// let pos = Pos::new(1, 1);
    /// let neighbors = pos.neighbors4(3, 3);
    /// assert_eq!(neighbors.len(), 4); // 中央なので4つ全て
    /// 
    /// let corner = Pos::new(0, 0);
    /// let corner_neighbors = corner.neighbors4(3, 3);
    /// assert_eq!(corner_neighbors.len(), 2); // 角なので2つ
    /// ```
    pub fn neighbors4(&self, height: usize, width: usize) -> Vec<Pos> {
        let mut neighbors = Vec::new();
        let (r, c) = (self.row, self.col);
        
        if r > 0 { neighbors.push(Pos::new(r - 1, c)); }
        if r + 1 < height { neighbors.push(Pos::new(r + 1, c)); }
        if c > 0 { neighbors.push(Pos::new(r, c - 1)); }
        if c + 1 < width { neighbors.push(Pos::new(r, c + 1)); }
        
        neighbors
    }
    
    /// 隣接する8方向の座標を返す
    pub fn neighbors8(&self, height: usize, width: usize) -> Vec<Pos> {
        let mut neighbors = Vec::new();
        let (r, c) = (self.row, self.col);
        
        for dr in -1i32..=1 {
            for dc in -1i32..=1 {
                if dr == 0 && dc == 0 { continue; }
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;
                if nr >= 0 && nr < height as i32 && nc >= 0 && nc < width as i32 {
                    neighbors.push(Pos::new(nr as usize, nc as usize));
                }
            }
        }
        
        neighbors
    }
    
    /// マンハッタン距離
    pub fn manhattan_distance(&self, other: &Pos) -> usize {
        ((self.row as i32 - other.row as i32).abs() + 
         (self.col as i32 - other.col as i32).abs()) as usize
    }
}

/// 2Dグリッド
#[derive(Debug, Clone)]
pub struct Grid<T> {
    pub data: Vec<Vec<T>>,
    pub height: usize,
    pub width: usize,
}

impl<T> Grid<T> {
    pub fn new(height: usize, width: usize, default_value: T) -> Self 
    where T: Clone {
        Self {
            data: vec![vec![default_value; width]; height],
            height,
            width,
        }
    }
    
    pub fn get(&self, pos: Pos) -> Option<&T> {
        self.data.get(pos.row)?.get(pos.col)
    }
    
    pub fn get_mut(&mut self, pos: Pos) -> Option<&mut T> {
        self.data.get_mut(pos.row)?.get_mut(pos.col)
    }
    
    pub fn set(&mut self, pos: Pos, value: T) {
        if let Some(cell) = self.get_mut(pos) {
            *cell = value;
        }
    }
    
    pub fn is_valid(&self, pos: Pos) -> bool {
        pos.row < self.height && pos.col < self.width
    }
    
    pub fn positions(&self) -> impl Iterator<Item = Pos> + '_ {
        (0..self.height).flat_map(move |r| {
            (0..self.width).map(move |c| Pos::new(r, c))
        })
    }
}
