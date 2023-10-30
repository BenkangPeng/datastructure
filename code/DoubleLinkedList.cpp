#include<iostream>
using namespace std ;
typedef struct DoubleLinkedList
{
    int data ;
    struct DoubleLinkedList *prior , *next ;
}DLNode , *DLList;
void InitDLList (DLList &HEAD){
    HEAD = new DLNode ;
    HEAD->next = NULL ;
    HEAD->prior = NULL ;
}
void CreateList_DL(DLList &HEAD , int n){
    for(int i = 0 ; i < n ; i++){
        DLNode *p = new DLNode ;
        cin >> p->data ;
        p->next = HEAD->next ;

        if(HEAD->next){
            HEAD->next->prior = p ;
        }
        //i = 0 时，插入第一个元素时，HEAD->next 为NULL， NULL是没有的，即NULL->prior是访问不到的，segmentation fault
        //因此当HEAD->next不为NULL时，才会执行HEAD->next->prior = p 
        //当HEAD->next 为NULL，也就是创建第一个结点时，不要让(也没法让)NULL->prior = p 

        HEAD->next = p ;
        p->prior = HEAD ;
    }
}
int GetLength_DL(DLList &HEAD){
    int length = 0 ;
    DLNode *p = HEAD->next;
    while(p){
        length++ ;
        p = p->next ;
    }
    return length ;
}
void PrintList_DL(DLList &HEAD){
    DLNode *p = HEAD->next ;
    for(int i = 0 ; i < GetLength_DL(HEAD) ; i++){
        cout << p->data << "  " ;
        p = p->next ;
    }
    cout << endl ;
}
void InsertList_DL(DLList &HEAD , int i , int data){
    if( i < 0 || i > GetLength_DL(HEAD))    {cout << "the index is invalid" << endl ; exit(0) ;}
    DLNode *p = HEAD ;
    for(int j = 0 ; j < i ; j++){
        p = p->next ;
    }
    DLNode *s = new DLNode ;
    s->data = data ;
    s->next = p->next ;
    if(p->next){
        p->next->prior = s ;
    }
    p->next = s ;
    s->prior = p ;

}
void DeleteElem_DL(DLList &HEAD  , int i){
    if(i < 0 || i >= GetLength_DL(HEAD))    {cout << "the index is invalid " << endl ; exit(0) ;}
    DLNode *p = HEAD->next ;
    while(i--){
        p = p->next ;
    }
    p->prior->next = p->next ;
    p->next->prior = p->prior ;
    delete p ;
}
int main(){
    DLList HEAD ;
    InitDLList(HEAD) ;
    CreateList_DL(HEAD , 6) ;
    PrintList_DL(HEAD) ;
    InsertList_DL(HEAD , 2 , 821) ;
    PrintList_DL(HEAD) ;
    DeleteElem_DL(HEAD , 1) ;
    PrintList_DL(HEAD) ;
    return 0 ;
}
