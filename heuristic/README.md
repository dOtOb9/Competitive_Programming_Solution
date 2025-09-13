# Heuristic Contest Project

統合されたヒューリスティックコンテスト開発環境

## プロジェクト構造

```
heuristic/
├── Cargo.toml                 # Rustワークスペース設定
├── Makefile                   # プロジェクト管理用Makefile
├── README.md                  # このファイル
├── contest-manager.sh         # コンテスト管理スクリプト
├── src/                       # 共通ライブラリ
│   ├── lib.rs
│   ├── utils/                 # 共通ユーティリティ
│   ├── algorithms/            # アルゴリズム実装
│   ├── visualization/         # ビジュアライザー支援
│   └── io/                    # 入出力処理
├── tools/                     # 開発ツール
│   ├── visualize.sh
│   ├── benchmark.sh
│   └── submit-helper.sh
├── templates/                 # 新規コンテスト用テンプレート
│   ├── rust/
│   └── cpp/
├── contests/                  # 各コンテスト実装
│   ├── ahc053/               # AHC053固有実装
│   │   ├── Cargo.toml
│   │   ├── src/
│   │   │   └── main.rs       # エントリポイント（共通lib使用）
│   │   ├── input/            # 入力ファイル
│   │   ├── output/           # 出力ファイル
│   │   └── visualizer/       # コンテスト固有ビジュアライザ
│   └── ahc054/               # 今後のコンテスト用
└── docs/                     # ドキュメント
    ├── setup.md
    ├── algorithms.md
    └── visualization.md
```

## 特徴

### 1. 統合開発環境
- 全コンテストで共通のライブラリとツールを使用
- Rustワークスペースによる依存関係管理
- 統一されたビルド・実行・テスト環境

### 2. 共通ライブラリ
- よく使用されるアルゴリズムとデータ構造
- 入出力処理の標準化
- ビジュアライザー支援機能
- ベンチマーク・プロファイリング支援

### 3. 開発効率化
- 新規コンテスト用テンプレート生成
- 自動ビジュアライザー起動
- バッチ実行・結果比較
- 提出準備の自動化

### 4. WSL最適化
- Windows統合を活用したビジュアライザー
- クロスプラットフォーム対応
- 効率的なファイル操作

## 使用方法

### 初期セットアップ
```bash
cd heuristic
make setup
```

### 新規コンテスト作成
```bash
./contest-manager.sh create ahc054
```

### 開発・実行
```bash
cd contests/ahc053
make run-sample
make visualize
```

### 全体管理
```bash
# ルートから全コンテストのテスト実行
make test-all

# 依存関係更新
make update-deps
```

## 設計思想

1. **DRY原則**: 共通コードの重複を避ける
2. **モジュラー設計**: 各部分が独立して機能
3. **開発効率**: 定型作業の自動化
4. **拡張性**: 新しいコンテストや機能の追加が容易
5. **可読性**: 統一されたコード構造とドキュメント
