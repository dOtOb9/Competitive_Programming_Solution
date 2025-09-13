# Heuristic Contest Project Makefile
# 統合プロジェクト管理

.DEFAULT_GOAL := help

# 変数
MANAGER := ./contest-manager.sh

# プロジェクト管理
setup: ## プロジェクト初期セットアップ
	$(MANAGER) setup

create: ## 新規コンテスト作成 (make create CONTEST=ahc054)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make create CONTEST=ahc054"; \
		exit 1; \
	fi
	$(MANAGER) create $(CONTEST)

list: ## 既存コンテスト一覧
	$(MANAGER) list

# ビルド・実行
build: ## 指定コンテストをビルド (make build CONTEST=ahc053)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make build CONTEST=ahc053"; \
		exit 1; \
	fi
	$(MANAGER) build $(CONTEST)

run: ## 指定コンテストを実行 (make run CONTEST=ahc053)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make run CONTEST=ahc053"; \
		exit 1; \
	fi
	$(MANAGER) run $(CONTEST)

test: ## 指定コンテストのテスト実行 (make test CONTEST=ahc053)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make test CONTEST=ahc053"; \
		exit 1; \
	fi
	$(MANAGER) test $(CONTEST)

# 開発支援
visualize: ## ビジュアライザー起動 (make visualize CONTEST=ahc053)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make visualize CONTEST=ahc053"; \
		exit 1; \
	fi
	$(MANAGER) visualize $(CONTEST)

clean: ## 指定コンテストをクリーン (make clean CONTEST=ahc053)
	@if [ -z "$(CONTEST)" ]; then \
		echo "使用方法: make clean CONTEST=ahc053"; \
		exit 1; \
	fi
	$(MANAGER) clean $(CONTEST)

# 全体操作
build-all: ## 全コンテストをビルド
	@for contest in contests/*/; do \
		if [ -d "$$contest" ]; then \
			contest_name=$$(basename "$$contest"); \
			echo "ビルド中: $$contest_name"; \
			$(MANAGER) build "$$contest_name" || true; \
		fi; \
	done

test-all: ## 全コンテストのテスト実行
	@for contest in contests/*/; do \
		if [ -d "$$contest" ]; then \
			contest_name=$$(basename "$$contest"); \
			echo "テスト中: $$contest_name"; \
			$(MANAGER) test "$$contest_name" || true; \
		fi; \
	done

clean-all: ## 全コンテストをクリーン
	@for contest in contests/*/; do \
		if [ -d "$$contest" ]; then \
			contest_name=$$(basename "$$contest"); \
			echo "クリーン中: $$contest_name"; \
			$(MANAGER) clean "$$contest_name" || true; \
		fi; \
	done

# 依存関係管理
update-deps: ## 依存関係更新
	$(MANAGER) update-deps

check: ## コードチェック
	cargo check --workspace
	cargo clippy --workspace

# ドキュメント
docs: ## ドキュメント生成してブラウザで開く
	cargo doc --workspace --no-deps
	./tools/open-browser.sh target/doc/heuristic_common/index.html

docs-build: ## ドキュメント生成（ブラウザを開かない）
	cargo doc --workspace --no-deps

docs-private: ## プライベート項目も含めてドキュメント生成
	cargo doc --workspace --document-private-items --no-deps
	./tools/open-browser.sh target/doc/heuristic_common/index.html

docs-clean: ## ドキュメントをクリーン
	cargo clean --doc

# 情報表示
info: ## プロジェクト情報表示
	@echo "===================="
	@echo "Heuristic Contest Project"
	@echo "===================="
	@echo "プロジェクトルート: $(shell pwd)"
	@echo ""
	@$(MANAGER) list

# ヘルプ
help: ## このヘルプを表示
	@echo "Heuristic Contest Project"
	@echo ""
	@echo "使用可能なターゲット:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}'
	@echo ""
	@echo "クイックスタート:"
	@echo "  make setup                    # 初期セットアップ"
	@echo "  make create CONTEST=ahc054    # 新規コンテスト作成"
	@echo "  make build CONTEST=ahc053     # ビルド"
	@echo "  make run CONTEST=ahc053       # 実行"
	@echo "  make test CONTEST=ahc053      # テスト実行"
	@echo "  make visualize CONTEST=ahc053 # ビジュアライザー"
	@echo ""

.PHONY: build build-debug run run-debug test clean check debug setup-dirs setup info \
        visualize visualize-folder download-vis run-sample run-all benchmark \
        prepare-submit watch docs docs-build docs-private docs-clean help
