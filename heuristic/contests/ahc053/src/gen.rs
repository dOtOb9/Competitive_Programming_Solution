use proconio::input;
use rand::prelude::*;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() < 2 {
        eprintln!("Usage: cargo run --bin gen <seed>");
        std::process::exit(1);
    }
    
    let seed: u64 = args[1].parse().unwrap_or(42);
    let mut rng = StdRng::seed_from_u64(seed);
    
    // AHC053のパラメータ例（実際の制約は問題文に依存）
    let n = rng.gen_range(3..=10);  // 配列サイズ
    let m = rng.gen_range(3..=10);  // 別の配列サイズ
    let l = rng.gen_range(1..=50);  // 下限
    let u = rng.gen_range(l+1..=100); // 上限
    
    println!("{} {} {} {}", n, m, l, u);
    
    // b配列を生成
    let b: Vec<i64> = (0..m).map(|_| rng.gen_range(1..=100)).collect();
    println!("{}", b.iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" "));
}
