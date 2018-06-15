//====================================================================
//  工学部「情報算法２」(富永)  例題
//  多倍長整数の計算  入出力と計算実行
//--------------------------------------------------------------------
//  BigNum  BigNumMain.c
//  ソース
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.05.18  v2.0
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
#include <time.h>
#include <sys/time.h>
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
    struct timeval t_sta, t_fin;
    // time_t t_sta, t_fin; //開始時間、終了時間(実時間)
    clock_t c_sta, c_fin; //開始時間、終了時間(CPU時間)
    
    n0.cnt = 0;

    //----  冒頭出力
    puts("工学部「情報環境実験１」(富永) 2017年度 課題１");
    puts("多倍長整数の計算 4桁1節で1万進数による実装");
    puts("tominaga 富永浩之");       // 各自の学籍番号と氏名に修正
    puts("2017.05.23(月)  v2.0");    // 実際の更新日とバージョンを明記
    puts("");

    //----  事前処理
    printf("0:乗算 1:累乗 2:累乗 3:累乗 4:二乗 5:二乗 ? "); 
    scanf("%d", &sw);

    //----  入力処理
    puts(""); 
    printf("U1 N1[] = ? ??  "); bignum_input(&n1);    // 第1項の入力
    if ( sw == 0 ) { 
        printf("U2 N2[] = ? ??  "); bignum_input(&n2);    // 第2項の入力
    } else if ( sw <= 3 ) {
        printf("E = ? "); scanf("%d", &e); 
    } else if ( sw == 5 ) {
        printf("S = ? "); scanf("%d", &e); 
    }

    gettimeofday(&t_sta, NULL);
    c_sta = clock();

    //----  計算処理
    switch ( sw ) {
    case 0: 
        puts("乗算(畳込法)");
        flag = bignum_mlt(n1, n2, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 1: 
        puts("累乗(素朴法)");
        flag = bignum_pow1(n1, e, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 2:
        puts("累乗(二乗法)");
        flag = bignum_pow2(n1, e, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 3:
        puts("累乗(カラツバ法)");
        flag = bignum_pow3(n1, e, &n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 4:
        puts("二乗(素朴法)");
        n0 = n1;
        flag = bignum_sq1(&n0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 5:
        puts("二乗(カラツバ法)");
        n0 = n1;
        flag = bignum_sq2(&n0, e);
        if ( ! flag ) { puts("Error"); break; }
        break;
    }

    gettimeofday(&t_fin, NULL);
    c_fin = clock();

    //----  出力処理
    printf("N0[] = "); bignum_output(n0);    // 整商の出力

    printf(" mlt_count\t : %d\n", n0.cnt);

    printf(" 実時間 \t : %f\n", (t_fin.tv_sec - t_sta.tv_sec)+(t_fin.tv_usec-t_sta.tv_usec)/1000000.0);
    printf(" CPU時間\t : %f\n", (double)(c_fin-c_sta)/CLOCKS_PER_SEC);

    //----  終了処理
    return 0;
}
