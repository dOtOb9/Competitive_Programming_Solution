#!/bin/bash

# AHC共通ビジュアライザスクリプト
# WSL環境での利用に最適化

set -e

# 色付きメッセージ関数
info() {
    echo -e "\033[32m[INFO]\033[0m $1"
}

error() {
    echo -e "\033[31m[ERROR]\033[0m $1"
}

warn() {
    echo -e "\033[33m[WARN]\033[0m $1"
}

# 使用方法表示
show_usage() {
    echo "AHC共通ビジュアライザスクリプト"
    echo "Usage: $0 [OPTIONS] [INPUT_FILE] [OUTPUT_FILE]"
    echo ""
    echo "Options:"
    echo "  -h, --help          このヘルプを表示"
    echo "  -b, --browser       結果をブラウザで開く"
    echo "  -o, --open-folder   結果フォルダをエクスプローラーで開く"
    echo "  -v, --visualizer    ビジュアライザファイルを指定"
    echo "  -d, --directory     作業ディレクトリを指定（デフォルト: 現在のディレクトリ）"
    echo ""
    echo "Examples:"
    echo "  $0 input/sample.txt output/result.txt"
    echo "  $0 -b input/sample.txt output/result.txt"
    echo "  $0 -o  # 結果フォルダを開く"
    echo "  $0 -d ../ahc054 -b input/sample.txt output/result.txt"
    echo ""
}

# デフォルト値
OPEN_BROWSER=false
OPEN_FOLDER=false
VISUALIZER_FILE=""
INPUT_FILE=""
OUTPUT_FILE=""
WORK_DIR="$(pwd)"

# 引数解析
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_usage
            exit 0
            ;;
        -b|--browser)
            OPEN_BROWSER=true
            shift
            ;;
        -o|--open-folder)
            OPEN_FOLDER=true
            shift
            ;;
        -v|--visualizer)
            VISUALIZER_FILE="$2"
            shift 2
            ;;
        -d|--directory)
            WORK_DIR="$2"
            shift 2
            ;;
        -*)
            error "未知のオプション: $1"
            show_usage
            exit 1
            ;;
        *)
            if [[ -z "$INPUT_FILE" ]]; then
                INPUT_FILE="$1"
            elif [[ -z "$OUTPUT_FILE" ]]; then
                OUTPUT_FILE="$1"
            else
                error "引数が多すぎます"
                show_usage
                exit 1
            fi
            shift
            ;;
    esac
done

# 作業ディレクトリに移動
cd "$WORK_DIR"
info "作業ディレクトリ: $(pwd)"

# フォルダを開く場合
if [[ "$OPEN_FOLDER" == "true" ]]; then
    info "結果フォルダを開いています..."
    
    # 結果フォルダの候補
    RESULT_DIRS=("output" "results" "out" ".")
    FOUND_DIR=""
    
    for dir in "${RESULT_DIRS[@]}"; do
        if [[ -d "$dir" ]]; then
            FOUND_DIR="$dir"
            break
        fi
    done
    
    if [[ -n "$FOUND_DIR" ]]; then
        explorer.exe "$(wslpath -w "$(realpath "$FOUND_DIR")")" 2>/dev/null || {
            explorer.exe "$(realpath "$FOUND_DIR")" 2>/dev/null || {
                error "フォルダを開けませんでした"
                exit 1
            }
        }
    else
        explorer.exe "$(wslpath -w "$(pwd)")" 2>/dev/null || {
            error "フォルダを開けませんでした"
            exit 1
        }
    fi
    exit 0
fi

# 必要なディレクトリの確認・作成
mkdir -p input output visualizer

# ビジュアライザファイルの確認
if [[ -n "$VISUALIZER_FILE" ]]; then
    if [[ ! -f "$VISUALIZER_FILE" ]]; then
        error "ビジュアライザファイルが見つかりません: $VISUALIZER_FILE"
        exit 1
    fi
else
    # 一般的なビジュアライザファイルを検索
    POSSIBLE_VISUALIZERS=(
        "visualizer/visualizer.html"
        "visualizer/index.html" 
        "vis.html"
        "visualizer.html"
        "vis/index.html"
        "vis/vis.html"
    )
    
    for vis in "${POSSIBLE_VISUALIZERS[@]}"; do
        if [[ -f "$vis" ]]; then
            VISUALIZER_FILE="$vis"
            break
        fi
    done
fi

# 入力・出力ファイルの確認
if [[ -n "$INPUT_FILE" ]]; then
    # 相対パスの場合、inputディレクトリ内も検索
    if [[ ! -f "$INPUT_FILE" && -f "input/$INPUT_FILE" ]]; then
        INPUT_FILE="input/$INPUT_FILE"
    fi
    
    if [[ ! -f "$INPUT_FILE" ]]; then
        error "入力ファイルが見つかりません: $INPUT_FILE"
        exit 1
    fi
fi

if [[ -n "$OUTPUT_FILE" ]]; then
    # 相対パスの場合、outputディレクトリ内も検索
    if [[ ! -f "$OUTPUT_FILE" && -f "output/$OUTPUT_FILE" ]]; then
        OUTPUT_FILE="output/$OUTPUT_FILE"
    fi
    
    if [[ ! -f "$OUTPUT_FILE" ]]; then
        warn "出力ファイルが見つかりません: $OUTPUT_FILE"
    fi
fi

# ビジュアライザファイルが見つからない場合の処理
if [[ -z "$VISUALIZER_FILE" ]]; then
    warn "ビジュアライザファイルが見つかりません"
    info "以下のいずれかを配置してください:"
    echo "  - visualizer/visualizer.html"
    echo "  - visualizer/index.html"
    echo "  - vis.html"
    echo "  - visualizer.html"
    echo "  - vis/index.html"
    echo "  - vis/vis.html"
    echo ""
    info "または -v オプションでファイルを指定してください"
    exit 1
fi

# ビジュアライザの実行
info "ビジュアライザを実行中..."
info "入力ファイル: ${INPUT_FILE:-"なし"}"
info "出力ファイル: ${OUTPUT_FILE:-"なし"}"
info "ビジュアライザ: $VISUALIZER_FILE"

# ブラウザで開く場合
if [[ "$OPEN_BROWSER" == "true" ]]; then
    info "ブラウザでビジュアライザを開いています..."
    
    # Windowsパスに変換
    WIN_PATH=$(wslpath -w "$(realpath "$VISUALIZER_FILE")" 2>/dev/null || echo "$(realpath "$VISUALIZER_FILE")")
    
    # ブラウザで開く
    cmd.exe /c start "\"\"" "\"$WIN_PATH\"" 2>/dev/null || {
        # 代替方法
        powershell.exe -c "Start-Process '$(wslpath -w "$(realpath "$VISUALIZER_FILE")")'" 2>/dev/null || {
            error "ブラウザでファイルを開けませんでした"
            info "手動で以下のファイルを開いてください: $VISUALIZER_FILE"
        }
    }
else
    info "ビジュアライザファイル: $VISUALIZER_FILE"
    info "ブラウザで開くには -b オプションを使用してください"
fi

info "完了!"
