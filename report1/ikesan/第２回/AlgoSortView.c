//====================================================================
//  C言語 中級プログラミング  例題
//  高速整列算法
//--------------------------------------------------------------------
//  AlgoSort AlgoSortView.c
//  ソース本体
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.06.16
//====================================================================


//====================================================================
//  ヘッダ情報
//====================================================================

#include <stdio.h>
#include <stdlib.h>
#include "AlgoSortProc.h"


//====================================================================
//  メイン関数
//====================================================================

int main(int argc, char *argv[]) 
{
  //----  宣言
  int sw = 0;        // 算法の種別
  char *str;         // 算法メッセージ
  int n;             // データ数
  Data seq[LEN];     // データ列
  int ct_cmp = 0;    // 比較回数
  int ct_swp = 0;    // 交換回数

  //----  算法の指定
  if ( argc == 2 ) { sw = atoi(argv[1]); }
  if ( sw < 4 || sw > 8 ) {
    //puts("実行時引数の不正"); 
    //puts("4: シェル法  5: コーム法  6: クイック法  7: マージ法  8: ヒープ法"); 
    return 0;
  }

  //----  配列の長さと各要素の入力
  //printf("データ数 = ?  ");
  scanf("%d", &n);
  //printf("配列要素 : ?  ");
  input_arr(seq, n);
  //puts("");

  //----  初期表示
  //puts("比較  交換 :  処理過程");
  //proc_view(seq, n, ct_cmp, ct_swp);

  //----  整列算法
  switch ( sw ) {
  case 4:
    shell_sort(seq, n, &ct_cmp, &ct_swp);
    str = "シェル法"; 
    break;
  case 5:
    comb_sort(seq, n, &ct_cmp, &ct_swp);
    str = "コーム法"; 
    break;
  case 6:
    quick_sort(seq, n, &ct_cmp, &ct_swp);
    str = "クイック法"; 
    break;
  case 7:
    merge_sort(seq, n, &ct_cmp, &ct_swp);
    str = "マージ法"; 
    break;
  case 8:
    heap_sort(seq, n, &ct_cmp, &ct_swp);
    str = "ヒープ法"; 
    break;
  }

  //----  整列結果の出力
  //puts("");
  printf("%3d, %3d\n", ct_cmp, ct_swp);
  //printf("%s  比較 %3d回  交換 %3d回\n", str, ct_cmp, ct_swp);

  return 0;
}
