//====================================================================
//  工学部「情報算法２」(富永)  例題
//  多倍長整数の計算  入出力と計算実行
//--------------------------------------------------------------------
//  BigNum  BigNumMain.c
//  ソース
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2018.06.05  v3.0
//====================================================================


//====================================================================
//  仕様
//====================================================================

/*--------------------------------------------------------------------


--------------------------------------------------------------------*/


//====================================================================
//  前処理
//====================================================================

//--------------------------------------------------------------------
//  ヘッダ指定
//--------------------------------------------------------------------

#include <stdio.h>
#include "BigNumLib.h"    // 多倍長整数ユーザ関数


//====================================================================
//  大域宣言
//====================================================================

//--------------------------------------------------------------------
//  関数宣言
//--------------------------------------------------------------------


//====================================================================
//  本体処理
//====================================================================

int main(void) 
{
    //----  局所宣言
    BigNum n0;        // 加減乗算や累乗の結果変数
    BigNum n1, n2;    // 入力変数
    BigNum n3, n4;    // 除算における整商と剰余
    int a1, a2, a3, a4;
    int e;            // 累乗の指数
    Bool flag;        // 結果の吟味
    int sw;

    //----  冒頭出力
    puts("工学部「情報環境実験１」(富永) 2018年度 課題１");
    puts("多倍長整数の計算 4桁1節で1万進数による実装");
    puts("tominaga 富永浩之");       // 各自の学籍番号と氏名に修正
    puts("2018.06.05(月)  v3.0");    // 実際の更新日とバージョンを明記
    puts("");

    //----  事前処理
    printf("0:正規化 1:加算 2:減算 3:乗算 ? "); 
    scanf("%d", &sw);

    //----  入力処理
    puts(""); 
    printf("U1 N1[] = ? ??  "); bignum_input(&n1);    // 第1項の入力
    if ( sw != 0 ) { 
        printf("U2 N2[] = ? ??  "); bignum_input(&n2);    // 第2項の入力
    } 

    //----  計算処理
    switch ( sw ) {
    case 0: 
        puts("正規化");
        n0 = n1;
        flag = bignum_normal(&n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 1: 
        puts("加算");
        flag = bignum_add(n1, n2, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 2:
        puts("減算");
        flag = bignum_sub(n1, n2, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 3:
        puts("乗算)");
        n0 = n1;
        flag = bignum_mlt(n1, n2, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    }

    //----  出力処理
    printf("N0[] = "); bignum_output(n0);    // 整商の出力

    //----  終了処理
    return 0;
}
