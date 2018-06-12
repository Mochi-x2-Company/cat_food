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
#include <stdlib.h>
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

    //----  事前処理
    printf("0:乗算 1:累乗 2:累乗 3:二乗 4:カラツバ ? "); 
    sw = atoi(argv[1]);
    printf("%d", sw);
    //scanf("%d", &sw);

    //----  入力処理
    puts(""); 
    u = atoi(argv[2]);
    a = atoi(argv[3]);
    printf("U1 N1[] = ? ??  "); bignum_input(&n1, u, a);    // 第1項の入力
    if ( sw == 0 ) { 
        printf("U2 N2[] = ? ??  "); bignum_input(&n2, u, a);    // 第2項の入力
    } else if ( sw <= 2 ) {
        printf("E = ? ");
        e = atoi(argv[4]);
        printf("%d\n", e);
        //scanf("%d", &e); 
    } else if ( sw == 4 ) {
        printf("S = ? ");
        e = atoi(argv[4]);
        printf("%d", e);
        //scanf("%d", &e); 
    }

    //----  計算処理
    switch ( sw ) {
    case 0: 
        puts("乗算(畳込法)");
        flag = bignum_mlt(n1, n2, &n0);

        if ( ! flag ) { puts("Error"); break; }
        break;

    case 1: 
        puts("累乗(素朴法)");
        n1.count = 0;
        n0.count = 0;

        start = clock();
        flag = bignum_pow1(n1, e, &n0);
        end = clock();
        
        //実行範囲
        /*if ( flag ) {
            if ((fp = fopen("result1.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
            }
            p = n0.nsz-1;                 // 最上位節
            fprintf(fp, "%d\r\n", a);
            fprintf(fp, "%d : ", e);
            fprintf(fp, "%8lld", n0.node[p]);       // 最上位桁の出力(0無)

            while ( --p >= 0 ) {             // 下位桁の出力(0付)
                fprintf(fp, "%08lld", n0.node[p]);    // 途中桁の0は出力
            }
            fprintf(fp, "\r\n");                        // 出力後の改行
            fclose(fp);
        }*/
        
        //時間測定
        /*if ((fp = fopen("2-mlt1.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
        }       
        fprintf(fp, "%.9f\r\n", (double)(end-start));                        // 出力後の改行
        fclose(fp);

        printf("time = %.9f[s]\n", (double)(end-start));
        */

        if ((fp = fopen("2-mlt1co.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
        }
        fprintf(fp, "%d\r\n", n0.count);
        fclose(fp);
        printf("%d\n", n0.count);
        
        if ( ! flag ) { puts("Error"); exit(1); }
        break;

    case 2:
        puts("累乗(二乗法)");
        n1.count = 0;
        n0.count = 0;

        start = clock();
        flag = bignum_pow2(n1, e, &n0);
        end = clock();
        /*if ( flag ) {
            if ((fp = fopen("result1.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
            }
            p = n0.nsz-1;                 // 最上位節
            fprintf(fp, "%d\r\n", a);
            fprintf(fp, "%d : ", e);
            fprintf(fp, "%8lld", n0.node[p]);       // 最上位桁の出力(0無)

            while ( --p >= 0 ) {             // 下位桁の出力(0付)
                fprintf(fp, "%08lld", n0.node[p]);    // 途中桁の0は出力
            }
            fprintf(fp, "\r\n");                        // 出力後の改行
            fclose(fp);
        }*/

        /*if ((fp = fopen("2-mlt2.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
            }       

        fprintf(fp, "%.9f\r\n", (double)(end-start));                        // 出力後の改行
        fclose(fp);

        printf("time = %.9f[s]\n", (double)(end-start));
        */
        if ((fp = fopen("2-mlt2co.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
        }
        fprintf(fp, "%d\r\n", n0.count);
        fclose(fp);
        printf("%d\n", n0.count);

        if ( ! flag ) { puts("Error"); exit(1); }
        break;

    case 3:
        puts("二乗(素朴法)");
        n0 = n1;
        n1.count = 0;
        n0.count = 0;
        
        start = clock();

        flag = bignum_sq1(&n0);
        
        end = clock();

        printf("time = %.2f[s]\n", (double)(end-start)/CLOCKS_PER_SEC);

        if ( ! flag ) { puts("Error"); break; }
        break;

    case 4:
        puts("二乗(カラツバ法)");
        n0 = n1;
        n1.count = 0;
        n0.count = 0;

        start = clock();
        
        flag = bignum_pow3(n1, e, &n0);
                
        end = clock();

        /*if ((fp = fopen("time.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
            }       

        fprintf(fp, "%.9f\r\n", (double)(end-start)/CLOCKS_PER_SEC);                        // 出力後の改行
        fclose(fp);

        printf("time = %.9f[s]\n", (double)(end-start)/CLOCKS_PER_SEC);
        */

        if ((fp = fopen("2-mlt3co.txt", "a+")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                exit(1);
        }
        fprintf(fp, "%d\r\n", n0.count);
        fclose(fp);
        printf("%d\n", n0.count);

        if ( ! flag ) { puts("Error"); break; }
        break;

    }

    //----  出力処理
    printf("N0[] = "); bignum_output(n0);    // 整商の出力

    //----  終了処理
    return 0;
}

