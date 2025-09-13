use std::io::{self, BufWriter, Write, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut lines = input.lines();
    
    let first_line: Vec<i64> = lines.next().unwrap()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    
    let n = first_line[0] as usize;
    let _m = first_line[1] as usize;
    let l = first_line[2];
    let u = first_line[3];
    
    // 2行目は読み飛ばし（bの値は使わない）
    let _b_line = lines.next().unwrap();
    
    let value = (u + l) / 2;
    
    // 高速バッファリング出力
    let stdout = io::stdout();
    let mut writer = BufWriter::new(stdout.lock());
    
    for _i in 0..n {
        writeln!(writer, "{}", value).unwrap();
    }
    writer.flush().unwrap();
}