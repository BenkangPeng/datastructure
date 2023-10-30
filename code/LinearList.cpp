#include<iostream>
#define ElementType int 
#define MaxSize 20 
using namespace std ;
typedef struct SqList{
    ElementType  *element ;
    int length ;
}SqList ;


void InitList_Sq(SqList &L){
    //Initial the Squence Linear List
    L.element = new ElementType[MaxSize] ;
    if(!L.element)  {
        exit(0);
        L.length = 0 ;
    }
}
void DestroyList(SqList &L){
    if(L.element)   delete L.element ;
}
void ClearList(SqList &L){
    L.length = 0 ;
}
int GetLength(SqList L){
    return  L.length ;
}
int IsEmpty(SqList &L){
    if(L.length)    return 0 ;
    else    return 1 ;
}
int GetEle(SqList &L , int i , ElementType &e){
    if(i < 1 || i > L.length)   return 0 ;
    else e = L.element[i] ;
    return 1 ;
}
int LocateEle (SqList &L , ElementType e){
    for(int i = 0 ; i < L.length ; i++){
        if(L.element[i] == e)   return i ;
    }
    return -1 ;
}
int ListInsert_Sq(SqList &L , ElementType e , int i ){
    if(i < 0 || i > L.length || (L.length + 1) > MaxSize)   return 0 ;
    for(int j = L.element[L.length - 1] ; j >= i ; j--){
        L.element[j + 1] = L.element[j] ;
    }
    L.element[i] = e ;
    L.length++ ;
    return 1 ;
}
void PrintList_Sq(SqList &L){
    for(int i = 0 ; i < L.length ; i++){
        cout << L.element[i] << " " ;
    }
    cout << endl ;
}
int ListDelete_Sq(SqList &L , int i ){
    if(i < 0 || i > L.length - 1) return 0 ;
    for(int j = i + 1 ; j < L.length ; j++){
        L.element[j - 1] = L.element[j] ; 
    }
    L.length-- ;
    return 1 ;
}
void union_list(SqList &La , SqList Lb){
    int length = GetLength(Lb) ;
    for(int i = 0 ; i < GetLength(Lb) ; i++){
        if(LocateEle(La , Lb.element[i]) == -1) {
            ListInsert_Sq(La , Lb.element[i] , GetLength(La)) ;
        }
    }
}
void merge_list_Sq(SqList &Lc , SqList La , SqList Lb ){
    int length_a = GetLength(La) , length_b = GetLength(Lb) ;
    Lc.length = length_a + length_b ;
    Lc.element = new ElementType[Lc.length] ;
    int i = 0 , j = 0 , k = 0 ;
    while(i < length_a && j < length_b){
        if(La.element[i] < Lb.element[j]){
            Lc.element[k++] = La.element[i++] ;
        }
        else Lc.element[k++] = Lb.element[j++] ;
    }
    while(i < length_a) Lc.element[k++] = La.element[i++] ;
    while(j < length_b) Lc.element[k++] = Lb.element[j++] ;
}
int main(){
    SqList La , Lb , Lc ;
    InitList_Sq(La) ; 
    InitList_Sq(Lb) ;
    int a[5] = {1 , 3 , 5 , 7 , 9} ;
    int b[5] = {2 , 4 , 6 , 8 , 9} ;
    for(int i = 0 ; i < 5 ; i++){
        La.element[i] = a[i] ;
        Lb.element[i] = b[i] ;
    }
    La.length = 5 ;
    Lb.length = 5 ;
    // union_list(La , Lb) ;
    merge_list_Sq(Lc , La , Lb) ;
    PrintList_Sq(Lc) ;
}