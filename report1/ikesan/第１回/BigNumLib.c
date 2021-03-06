//====================================================================
//  工学部「情報環境実験１」(富永)  例題
//  多倍長整数の計算  四則演算の関数実装
//--------------------------------------------------------------------
//  BigNum  BigNumLib.c
//  ライブラリ
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.05.20  v3.0
//--------------------------------------------------------------------
//  s15t200 高松太郎
//  2017.01.16  v3.0  元ソース
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
#include "BigNumLib.h"


//====================================================================
//  関数定義  入出力
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の入力
//--------------------------------------------------------------------

Bool bignum_input(BigNum *b) 
{
    //----  局所宣言
    int u;    // 多倍長の節数
    int a;    // 一時変数
    int k;    // 反復変数

    //----  初期処理
    bignum_init(b, 0, 0);    // 結果を0に初期化

    //----  節数の入力と確認
    scanf("%d", &u);                    // 節数の入力
    printf("%d\n", u);
    if ( u > NMX ) { return FALSE; }    // 範囲超過なら打切

    //----  各節の入力と確認
    for ( k = u-1; k >= 0; k-- ) {         // 上位節から
        scanf("%d", &a);                     // 入力値の各格納
        printf("%d\n", a);
        // 二倍長や負数も許容(入力の利便性のため)
        if ( a < 0 ) { return FALSE; }       // 節値が負数なら打切
        if ( a >= RAD ) { return FALSE; }    // 節値が基数の以上なら打切
        b->node[k] = a;                      // 構造体の配列メンバに節値を格納
    }

    //----  事後処理
    return bignum_normal(b);    // 節値と節長・桁長の正規化
}
Bool bignum_input2(BigNum *b, int u, int a) 
{
    //----  局所宣言
    //int u;    // 多倍長の節数
    //int a;    // 一時変数
    int k;    // 反復変数

    //----  初期処理
    bignum_init(b, 0, 0);    // 結果を0に初期化

    //----  節数の入力と確認
    printf("%d\n", u);
    //scanf("%d", &u);                    // 節数の入力
    if ( u > NMX ) { return FALSE; }    // 範囲超過なら打切

    //----  各節の入力と確認
    for ( k = u-1; k >= 0; k-- ) {         // 上位節から
        printf("%d\n", a);
        //scanf("%d", &a);                     // 入力値の各格納
        // 二倍長や負数も許容(入力の利便性のため)
        // if ( a < 0 ) { return FALSE; }       // 節値が負数なら打切
        // if ( a >= RAD ) { return FALSE; }    // 節値が基数の以上なら打切
        b->node[k] = a;                      // 構造体の配列メンバに節値を格納
    }

    //----  事後処理
    return bignum_normal(b);    // 節値と節長・桁長の正規化
}

// 現在の入力方法は、多倍長の節数を指定し、各節を上位節から入力する。
// 節の区切は、空白1字とする。各節の上位桁の 0 は省略できる。
// 4  16 2031 45 0007 → 16 2031 0045 0007
// 改良として、fgets() と sscanf() を用いて、
// 16203100450007 のように桁数を指定せずに入力できるようにする。

//--------------------------------------------------------------------
//  多倍長整数の出力
//--------------------------------------------------------------------

void bignum_output(const BigNum b) 
{
    int p = b.nsz-1;                 // 最上位節
    printf("%3d : ", b.nsz);
    printf("%8lld ", b.node[p]);       // 最上位桁の出力(0無)

    while ( --p >= 0 ) {             // 下位桁の出力(0付)
        printf("%08lld ", b.node[p]);    // 途中桁の0は出力
    }
    puts("");                        // 出力後の改行
}


//====================================================================
//  関数定義  初期化と正規化
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の初期化 (単倍長整数の埋込による多倍長化)
//--------------------------------------------------------------------

Bool bignum_init(BigNum *b0, int a, int p) 
{
    int k;
    //----  事前処理
    if ( a < 0 || a >= RAD ) { return FALSE; }    // 不適な初期値で異常を返却
    // # 二倍長まで認めるときは、a/RAD >= RAD とする

    //----  計算処理
    for ( k = 0; k < NMX; k++ ) { b0->node[k] = 0; }    // 各節を0を格納
    // # 宣言時の初期化を利用して、以下としてもよい
    // BigNum t = {1, 0, {0}}; *b0 = t; 
    b0->node[p] = a;                                    // 第0節に代入

    //----  事後処理
    return bignum_normal(b0);
}

//--------------------------------------------------------------------
//  多倍長整数の正規化 (節値と範囲の正規化)
//--------------------------------------------------------------------

Bool bignum_normal(BigNum *b0) 
{
    if ( ! bignum_carry(b0) ) { return FALSE; }    // 節値の清算
    return bignum_size(b0);                        // 節数の格納
}

//--------------------------------------------------------------------
//  多倍長整数の節値の正規化 (繰上り・繰下りの清算)
//--------------------------------------------------------------------

Bool bignum_carry(BigNum *b0)
{
    //----  局所選言
    long long int v;        // 一時的な節値(0未満RAD以上の値になることも)
    int c = 0;    // 下位節からの繰上り・繰下り
    int k;        // 反復変数

    //----  節値の正規化
    for ( k = 0; k < NMX; k++ ) {
        v = b0->node[k] + c;
        //--  繰上りの清算(正数の整除演算で直接に確定)
        if ( v >= 0 ) { b0->node[k] = v % RAD; c = v / RAD; continue; }
        //--  繰下りの清算(負数のため、反復加算で計算)
        c = 0;
        while ( v < 0 ) { v += RAD; c--; }
        b0->node[k] = v;
    }

    //----  範囲超過
    return ( c == 0 );    // 最上位節で繰上り・繰下りが残れば、異常を返却
}

//--------------------------------------------------------------------
//  多倍長整数の範囲の正規化 (節数と桁数の格納)
//--------------------------------------------------------------------

Bool bignum_size(BigNum *b) 
{
    //----  局所宣言
    long long int v;    // 最上位の節値
    int k;    // 反復変数

    //----  節数の計算と格納
    for ( k = NMX-1; k >= 0; k-- ) { 
        if ( b->node[k] != 0 ) { break; }    // 最上位節の検知
    }
    if ( k < 0 ) { k = 0; }    // 0に対する例外処理
    b->nsz = k+1;              // 節数を格納

    //----  桁数の計算と格納
    b->dsz = k * WID;        // node[k-1]〜node[0]は、WID桁分ある
    v = b->node[k];          // 最上位桁node[k]は、1〜WID桁しかない
    while ( v > 0 ) { (b->dsz)++; v /= TEN; }    // 節値を割りながら桁数を加算
    return TRUE;             
    // # 0に対しては、桁数0 節数1 になっている。
}

//--------------------------------------------------------------------
//  多倍長整数の節移動  右移動と(節下げ)左移動(節上げ)
//--------------------------------------------------------------------

Bool bignum_shift(BigNum *b, int s)
{
    //----  局所宣言
    int k;        // 反復変数

    //----  事前処理
    if ( s == 0 ) { return TRUE; }               // 移動なし
    if ( b->nsz + s > NMX ) { return FALSE; }    // 左移動で節溢れ

    //----  右移動(節下げ)
    if ( s < 0 ) {
        for ( k = 0; k < NMX; k++ ) { 
            if ( k-s < NMX ) { b->node[k] = b->node[k-s]; } 
                else { b->node[k] = 0; }
       }
    }

    //----  左移動(節上げ)
    if ( s > 0 ) {
        for ( k = NMX-1; k >= 0; k-- ) { 
            if ( k-s >= 0 ) { b->node[k] = b->node[k-s]; } 
                else { b->node[k] = 0; }
        }
    }

    //----  事後処理
    return bignum_normal(b);    // 節数と桁数の格納
}


//====================================================================
//  関数定義  比較演算
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の大小比較  関数strcmp()と同様の返却値
//--------------------------------------------------------------------

int bignum_cmp(BigNum b1, BigNum b2)
{
    //----  局所宣言
    int k;    // 反復変数

    //----  差が多倍長の大小判定
    for ( k = NMX-1; k >= 1; k-- ) {                   // 上位節からの比較
        if ( b1.node[k] < b2.node[k] ) { return -2; }    // 途中で正順のとき
        if ( b1.node[k] > b2.node[k] ) { return +2; }    // 途中で逆順のとき
    }
    //----  差が単倍長の大小判定
    if ( b1.node[0] < b2.node[0] ) { return -1; }    // 正順のとき
    if ( b1.node[0] > b2.node[0] ) { return +1; }    // 逆順のとき
    return 0;    // 相等の返却
}

//--------------------------------------------------------------------
//  多倍長整数の零判定
//--------------------------------------------------------------------

Bool bignum_zero(BigNum b)
{
    return  ( b.dsz == 0 );    // 桁数0は0のときのみ
}

//--------------------------------------------------------------------
//  多倍長整数の順序判定
//--------------------------------------------------------------------

Bool bignum_within(BigNum b1, BigNum b2, BigNum b3)
{
    return ( bignum_cmp(b1, b2) <= 0 && bignum_cmp(b2, b3) < 0 );
}


//====================================================================
//  関数定義  加減算
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の加算
//--------------------------------------------------------------------

Bool bignum_add(BigNum b1, BigNum b2, BigNum *b0) 
{
    int k;
    for ( k = 0; k < NMX; k++ ) {               // 下位節から
        b0->node[k] = b1.node[k] + b2.node[k];    // 節同士の加算
    }
    return bignum_normal(b0);                   // 繰上りの清算
    // 計算が範囲超過でも結果b0は更新されてしまうので注意
}

//--------------------------------------------------------------------
//  多倍長整数の減算
//--------------------------------------------------------------------

Bool bignum_sub(BigNum b1, BigNum b2, BigNum *b0) 
{
    int k;
    for ( k = 0; k < NMX; k++ ) {               // 下位節から
        b0->node[k] = b1.node[k] - b2.node[k];    // 節同士の減算
    }
    return bignum_normal(b0);                    // 繰下りの清算
    // 計算が範囲超過でも結果b0は更新されてしまうので注意
}

//--------------------------------------------------------------------
//  多倍長整数の増分(多倍長整数への単倍長整数の加算更新)
//--------------------------------------------------------------------

Bool bignum_inc(BigNum *b0, int a, int p) 
{
    // 二倍長や負数も許容(一時的な計算のため)
    // if ( a < 0 || a >= RAD ) { return FALSE; }
    b0->node[p] += a;
    return bignum_normal(b0);    // 節値と節長の正規化
}

