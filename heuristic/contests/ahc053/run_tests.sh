#!/bin/bash

# AHC053 テスト実行スクリプト

echo "🎯 AHC053 テスト実行開始"
echo "========================="

cd "$(dirname "$0")"

# ビルド
echo "📦 ビルド中..."
cargo build --release --bin ahc053

if [ $? -ne 0 ]; then
    echo "❌ ビルド失敗"
    exit 1
fi

echo "✅ ビルド完了"
echo ""

# 入力ディレクトリ内の全ての.txtファイルに対してテスト実行
for input_file in input/*.txt; do
    if [ -f "$input_file" ]; then
        base_name=$(basename "$input_file" .txt)
        output_file="output/${base_name}_output.txt"
        
        echo "🔍 テスト実行: $base_name"
        echo "  入力: $input_file"
        echo "  出力: $output_file"
        
        # 実行
        cargo run --release --bin ahc053 < "$input_file" > "$output_file" 2>/dev/null
        
        if [ $? -eq 0 ]; then
            echo "  ✅ 実行成功"
            echo "  📤 出力:"
            cat "$output_file" | head -n 5 | sed 's/^/     /'
            if [ $(wc -l < "$output_file") -gt 5 ]; then
                echo "     ... ($(wc -l < "$output_file") 行)"
            fi
        else
            echo "  ❌ 実行失敗"
        fi
        echo ""
    fi
done

echo "🎉 テスト完了"
