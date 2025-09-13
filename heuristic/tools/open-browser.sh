#!/bin/bash

# WSLからWindowsブラウザでファイルを開くヘルパースクリプト

set -e

show_usage() {
    echo "WSL Browser Opener"
    echo "Usage: $0 [OPTIONS] <file_path>"
    echo ""
    echo "Options:"
    echo "  -h, --help    このヘルプを表示"
    echo ""
    echo "Examples:"
    echo "  $0 target/doc/heuristic_common/index.html"
    echo "  $0 output/visualizer.html"
    echo ""
}

open_in_browser() {
    local file_path="$1"
    
    # ファイルの存在確認
    if [[ ! -f "$file_path" ]]; then
        echo "エラー: ファイルが見つかりません: $file_path"
        exit 1
    fi
    
    # 絶対パスに変換
    local abs_path=$(realpath "$file_path")
    
    echo "ブラウザで開いています: $abs_path"
    
    # 複数の方法を試行
    local success=false
    
    # 方法1: PowerShellのStart-Process
    if ! $success; then
        if powershell.exe -c "Start-Process '$(wslpath -w "$abs_path")'" 2>/dev/null; then
            success=true
            echo "✓ PowerShell経由で開きました"
        fi
    fi
    
    # 方法2: cmd.exe のstart (UNCパス対応)
    if ! $success; then
        # ファイルをtmpディレクトリにコピーしてから開く
        local tmp_dir="/mnt/c/temp"
        mkdir -p "$tmp_dir" 2>/dev/null || true
        
        if [[ -d "$tmp_dir" ]]; then
            local tmp_file="$tmp_dir/$(basename "$file_path")"
            cp "$abs_path" "$tmp_file"
            if cmd.exe /c start "$(wslpath -w "$tmp_file")" 2>/dev/null; then
                success=true
                echo "✓ 一時ファイル経由で開きました: $tmp_file"
            fi
        fi
    fi
    
    # 方法3: explorer.exeでフォルダを開く
    if ! $success; then
        local dir_path=$(dirname "$abs_path")
        echo "ブラウザで開けませんでした。フォルダを開きます: $dir_path"
        explorer.exe "$(wslpath -w "$dir_path")" 2>/dev/null || {
            echo "エラー: フォルダも開けませんでした"
            exit 1
        }
        echo "✓ フォルダを開きました。手動でファイルをダブルクリックしてください"
    fi
}

# 引数チェック
if [[ $# -eq 0 ]]; then
    show_usage
    exit 1
fi

case "${1:-}" in
    -h|--help)
        show_usage
        exit 0
        ;;
    -*)
        echo "エラー: 未知のオプション: $1"
        show_usage
        exit 1
        ;;
    *)
        open_in_browser "$1"
        ;;
esac
