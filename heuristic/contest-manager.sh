#!/bin/bash

# Heuristic Contest Manager
# 新規コンテスト作成、ビルド、実行などを管理

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR"

# 色付きメッセージ
info() { echo -e "\033[32m[INFO]\033[0m $1"; }
warn() { echo -e "\033[33m[WARN]\033[0m $1"; }
error() { echo -e "\033[31m[ERROR]\033[0m $1"; }

show_usage() {
    echo "Heuristic Contest Manager"
    echo ""
    echo "Usage: $0 <command> [options]"
    echo ""
    echo "Commands:"
    echo "  create <contest>     新規コンテストプロジェクト作成"
    echo "  list                 既存コンテスト一覧"
    echo "  build <contest>      指定コンテストをビルド"
    echo "  run <contest>        指定コンテストを実行"
    echo "  test <contest>       指定コンテストのテスト実行"
    echo "  clean <contest>      指定コンテストをクリーン"
    echo "  visualize <contest>  ビジュアライザー起動"
    echo "  update-deps          全依存関係更新"
    echo "  setup               初期セットアップ"
    echo ""
    echo "Examples:"
    echo "  $0 create ahc054"
    echo "  $0 build ahc053"
    echo "  $0 run ahc053"
    echo "  $0 visualize ahc053"
    echo ""
}

create_contest() {
    local contest_name="$1"
    if [[ -z "$contest_name" ]]; then
        error "コンテスト名を指定してください"
        exit 1
    fi
    
    local contest_dir="$PROJECT_ROOT/contests/$contest_name"
    
    if [[ -d "$contest_dir" ]]; then
        warn "コンテスト $contest_name は既に存在します"
        exit 1
    fi
    
    info "新規コンテスト $contest_name を作成中..."
    
    # ディレクトリ作成
    mkdir -p "$contest_dir"/{src,input,output,visualizer}
    
    # Cargo.toml作成
    cat > "$contest_dir/Cargo.toml" <<EOF
[package]
name = "$contest_name"
version.workspace = true
edition.workspace = true

[dependencies]
# ワークスペース共通依存関係
rand.workspace = true
rustc-hash.workspace = true
itertools.workspace = true
proconio.workspace = true
serde = { workspace = true, features = ["derive"] }
serde_json.workspace = true

# 共通ライブラリ
heuristic-common = { path = "../.." }
EOF
    
    # main.rs テンプレート作成
    cat > "$contest_dir/src/main.rs" <<EOF
use heuristic_common::*;
use proconio::input;

fn main() {
    // 入力読み込み
    input! {
        n: usize,
        // ここに問題固有の入力を追加
    }
    
    debug!("Input: n = {}", n);
    
    // ソルバー実行
    let solution = solve(n);
    
    // 結果出力
    output_solution(&solution);
}

fn solve(n: usize) -> Solution {
    measure_time!("solve", {
        // ここに問題固有の解法を実装
        Solution::new()
    })
}

fn output_solution(solution: &Solution) {
    // ここに出力形式を実装
    println!("{}", solution.score());
}

// 問題固有の解構造
#[derive(Debug, Clone)]
struct Solution {
    // 解の要素を定義
}

impl Solution {
    fn new() -> Self {
        Solution {
            // 初期化
        }
    }
    
    fn score(&self) -> i64 {
        // スコア計算を実装
        0
    }
    
    #[allow(dead_code)]
    fn to_json(&self) -> String {
        // ビジュアライザー用JSON出力
        serde_json::to_string(self).unwrap_or_default()
    }
}
EOF
    
    # ワークスペースに追加
    local cargo_toml="$PROJECT_ROOT/Cargo.toml"
    if ! grep -q "\"contests/$contest_name\"" "$cargo_toml"; then
        sed -i "/members = \[/a\\    \"contests/$contest_name\"," "$cargo_toml"
        info "ワークスペースに $contest_name を追加しました"
    fi
    
    info "コンテスト $contest_name を作成しました: $contest_dir"
    info "次の手順:"
    echo "  1. cd contests/$contest_name"
    echo "  2. 問題文を読んで入力形式を更新"
    echo "  3. solve() 関数を実装"
    echo "  4. cargo run でテスト実行"
}

list_contests() {
    info "既存コンテスト一覧:"
    for contest_dir in "$PROJECT_ROOT/contests"/*; do
        if [[ -d "$contest_dir" ]]; then
            local contest_name=$(basename "$contest_dir")
            echo "  - $contest_name"
        fi
    done
}

build_contest() {
    local contest_name="$1"
    check_contest_exists "$contest_name"
    
    info "ビルド中: $contest_name"
    cd "$PROJECT_ROOT"
    cargo build --bin "$contest_name" --release
}

run_contest() {
    local contest_name="$1"
    check_contest_exists "$contest_name"
    
    info "実行中: $contest_name"
    cd "$PROJECT_ROOT"
    cargo run --bin "$contest_name" --release
}

test_contest() {
    local contest_name="$1"
    check_contest_exists "$contest_name"
    
    info "テスト実行: $contest_name"
    cd "$PROJECT_ROOT/contests/$contest_name"
    
    if [[ -f "input/sample.txt" ]]; then
        info "サンプルケース実行中..."
        cargo run --release < input/sample.txt > output/sample_output.txt
        info "結果: output/sample_output.txt"
    else
        warn "input/sample.txt が見つかりません"
    fi
}

clean_contest() {
    local contest_name="$1"
    check_contest_exists "$contest_name"
    
    info "クリーン: $contest_name"
    cd "$PROJECT_ROOT/contests/$contest_name"
    cargo clean
    rm -rf output/*
}

visualize_contest() {
    local contest_name="$1"
    check_contest_exists "$contest_name"
    
    info "ビジュアライザー起動: $contest_name"
    cd "$PROJECT_ROOT/contests/$contest_name"
    "$PROJECT_ROOT/tools/visualize.sh" -b
}

check_contest_exists() {
    local contest_name="$1"
    if [[ -z "$contest_name" ]]; then
        error "コンテスト名を指定してください"
        exit 1
    fi
    
    if [[ ! -d "$PROJECT_ROOT/contests/$contest_name" ]]; then
        error "コンテスト $contest_name が見つかりません"
        exit 1
    fi
}

update_deps() {
    info "依存関係更新中..."
    cd "$PROJECT_ROOT"
    cargo update
}

setup_project() {
    info "プロジェクト初期セットアップ中..."
    cd "$PROJECT_ROOT"
    
    # ディレクトリ作成
    mkdir -p tools visualizer-common contests docs
    
    # 依存関係チェック
    cargo check
    
    info "セットアップ完了"
}

# メイン処理
case "${1:-}" in
    create)
        create_contest "$2"
        ;;
    list)
        list_contests
        ;;
    build)
        build_contest "$2"
        ;;
    run)
        run_contest "$2"
        ;;
    test)
        test_contest "$2"
        ;;
    clean)
        clean_contest "$2"
        ;;
    visualize)
        visualize_contest "$2"
        ;;
    update-deps)
        update_deps
        ;;
    setup)
        setup_project
        ;;
    help|--help|-h)
        show_usage
        ;;
    *)
        error "不明なコマンド: ${1:-}"
        show_usage
        exit 1
        ;;
esac
