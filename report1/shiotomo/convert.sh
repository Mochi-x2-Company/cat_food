#!/bin/bash

# epsをpngに変換するスクリプト
# 実行時引数の第一引数にepsファイルを,第二引数にpngファイルを指定

convert -density 144 $1 $2
