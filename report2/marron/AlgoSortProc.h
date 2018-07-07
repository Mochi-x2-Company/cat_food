//====================================================================
//  工学部「知識工学基礎」  例題
//  高速整列算法  ヘッダファイル
//--------------------------------------------------------------------
//  AlgoSort  AlgoSortProc.h
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2000.10.11
//====================================================================


//====================================================================
//  定数定義マクロ
//====================================================================

#define  LEN    1024    // 配列最大長
#define  TRUE   1       // 真値
#define  FALSE  0       // 偽値


//====================================================================
//  データ型名定義
//====================================================================

typedef  int  Bool;        // 真偽値
typedef  int  Data;        // データ


//====================================================================
//  関数宣言
//====================================================================

//--------------------------------------------------------------------
//  要素の比較と交換
//--------------------------------------------------------------------

//----  配列の要素比較
Bool arr_ord(Data seq[], int p1, int p2);
Bool arr_ord_ct(Data seq[], int p1, int p2, int *ct);

//----  配列の要素交換 
void arr_swap(Data seq[], int p1, int p2); 
void arr_swap_ct(Data seq[], int p1, int p2, int *ct); 

//--------------------------------------------------------------------
//  間隔指定の前処理による高速整列算法
//--------------------------------------------------------------------

//----  シェルソート
void shell_sort(Data seq[], int n, int *ct_c, int *ct_s);  
void shell_sort_run(Data seq[], int low, int hig, int gap, 
                    int *ct_c, int *ct_s);    

//----  コームソート
void comb_sort(Data seq[], int n, int *ct_c, int *ct_s);   
void comb_sort_run(Data arr[], int low, int hig, int gap, 
                   int *ct_c, int *ct_s);

//--------------------------------------------------------------------
//  分割再帰による高速整列算法
//--------------------------------------------------------------------

//----  クイックソート
void quick_sort(Data seq[], int n, int *ct_c, int *ct_s); 
void quick_sort_rec(Data seq[], int low, int hig,         
                    int n, int *ct_c, int *ct_s);         
void parti_proc(Data arr[], int low, int hig, int key, int *m_l, int *m_h);

void quick_sort_it_st(Data seq[], int n); 
void quick_sort_it_qu(Data seq[], int n); 

//----  マージソート
void merge_sort(Data seq[], int n, int *ct_c, int *ct_s); 
void merge_sort_rec(Data seq[], int low, int hig, Data tmp[], 
                    int n, int *ct_c, int *ct_s);
void merge_proc(Data arr[], int l, int h);

void merge_sort_it_st(Data seq[], int n);
void merge_sort_it_qu(Data seq[], int n);

//----  ヒープソート
void heap_sort(Data seq[], int n, int *ct_c, int *ct_s);
void heap_sort_rec(Data seq[], int up, int lst, int *ct_c, int *ct_s);

//---- ノームソート
void gnome_sort(Data arr[], int n, int *ct_c, int *ct_s);

//--------------------------------------------------------------------
//  配列の入出力
//--------------------------------------------------------------------

//----  配列への入力
void input_arr(Data arr[], int n);                

//----  配列からの出力
void output_arr(Data arr[], int n);               

//----  処理過程の表示
void proc_view(Data arr[], int n, int ct_c, int ct_s);

//---- 配列のコピー
void arr_copy(Data src[], Data dist[], int n);
