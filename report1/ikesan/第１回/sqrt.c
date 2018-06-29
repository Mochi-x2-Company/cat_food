#include <stdio.h>
#include <stdlib.h>
#include "BigNumLib.h"

int main(int argc, char *argv[]) 
{
    //----  局所宣言
    FILE *fp;
    BigNum n0;        // 加減乗算や累乗の結果変数
    BigNum n1, n2;    // 入力変数
    BigNum n3, n4;    // 除算における整商と剰余
    int a1, a2, a3, a4;
    int a, u;
    int e;            // 累乗の指数
    Bool flag;        // 結果の吟味
    int sw;
    int p;
    clock_t start, end;

    //----  冒頭出力
    puts("工学部「情報環境実験１」(富永) 2018年度 課題１");
    puts("多倍長整数の計算 4桁1節で1万進数による実装");
    puts("tominaga 富永浩之");       // 各自の学籍番号と氏名に修正
    puts("2018.06.05(火)  v3.0");    // 実際の更新日とバージョンを明記
    puts("");

    //----  入力処理 
    u = atoi(argv[1]);
    a = atoi(argv[2]);
    printf("U1 N1[] = ? ??  "); bignum_input(&n1, u, a);    // 第1項の入力 
    printf("S = ? ");
    e = atoi(argv[4]);
    printf("%d", e);

    bignum_sqrt(BigNum b1, BigNum *b0);

}