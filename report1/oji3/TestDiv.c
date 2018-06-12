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

int main(int argc,char **argv) 
{
    //----  局所宣言
    BigNum n0;        // 加減乗算や累乗の結果変数
    BigNum n1, n2;    // 入力変数
    BigNum n3, n4;    // 除算における整商と剰余
    int a1, a2, a3, a4;
    int e;            // 累乗の指数
    Bool flag;        // 結果の吟味
    int sw;
    
    //changed
    int u;
    //
    sscanf(argv[1],"%d",&u);
    sscanf(argv[2],"%d",&e);
    //----  冒頭出力
    puts("工学部「情報環境実験１」(富永) 2018年度 課題１");
    puts("多倍長整数の計算 4桁1節で1万進数による実装");
    puts("tominaga 富永浩之");       // 各自の学籍番号と氏名に修正
    puts("2018.06.05(月)  v3.0");    // 実際の更新日とバージョンを明記
    puts("");

    //----  事前処理
    printf("0:多多単多 1:多多単多  2:多単多単 3:多多多多 4:多多多多 ? "); 
    sscanf(argv[3],"%d", &sw);
    printf("%d\n",sw);

    //----  入力処理
    puts(""); 
    printf("U1 N1[] = ? ??  "); bignum_input(&n1,u,e);    // 第1項の入力 change
    printf("U2 N2[] = ? ??  "); bignum_input(&n2,u,e);    // 第2項の入力 change

    //----  計算処理
    switch ( sw ) {
    case 0: 
        puts("多÷多＝単‥多 (減算法)");
        flag = bignum_div0(n1, n2, &a3, &n4);
        bignum_init(&n3, a3, 0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 1: 
        puts("多÷多＝単‥多 (二分法)");
        flag = bignum_div1(n1, n2, &a3, &n4);
        bignum_init(&n3, a3, 0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 2:
        puts("多÷単＝多‥単 (商立法)");
        a2 = n2.node[0];
        flag = bignum_div2(n1, a2, &n3, &a4);
        bignum_init(&n4, a4, 0);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 3:
        puts("多÷多＝多‥多 (商立法)");
        flag = bignum_div3(n1, n2, &n3, &n4);
        if ( ! flag ) { puts("Error"); break; }
        break;
    case 4:
        puts("多÷多＝多‥多 (二分法)");
        flag = bignum_div3(n1, n2, &n3, &n4);
        if ( ! flag ) { puts("Error"); break; }
        break;
    }

    //----  出力処理
    printf("N3[] = "); bignum_output(n3);    // 整商の出力
    printf("N4[] = "); bignum_output(n4);    // 剰余の出力

    //----  終了処理
    return 0;
}

