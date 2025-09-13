# AHC053 Makefile
# Rust プロジェクト

# Rustプロジェクトであることを示す
RUST_PROJECT := 1

# 共通Makefileをインクルード
include ../tools/Makefile.common

# AHC053固有のターゲット
contest-info: ## コンテスト情報を表示
	@echo "AtCoder Heuristic Contest 053"
	@echo "実行時間制限: 通常2秒"
	@echo "メモリ制限: 1024MB"
	@echo ""
	@echo "ビジュアライザ: https://img.atcoder.jp/ahc053/"

# サンプルダウンロード（手動実装が必要）
download-samples: ## サンプルケースをダウンロード
	@echo "サンプルケースを手動でダウンロードして input/ に配置してください"
	@echo "例:"
	@echo "  wget https://img.atcoder.jp/ahc053/sample.txt -O input/sample.txt"

# 提出用ファイル準備
prepare-submit: build ## 提出用ファイルを準備
	@echo "提出用ファイルを準備中..."
	cp src/main.rs submit.rs
	@echo "submit.rs を作成しました"

.PHONY: contest-info download-samples prepare-submit