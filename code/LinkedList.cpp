#include<iostream>
using namespace std ;
typedef struct Lnode{
    int data ;
    struct Lnode *next ;
}Lnode , *Linklist;
void InitList_L(Linklist &L){
    L = new Lnode ;
    L->next = NULL ; // L is the head pointer of linklist , L points to the first node .
}
int IsEmpty(Linklist &L){
    return L->next == NULL ;
}
int DestroyList_L(Linklist &L){
    Lnode *p ;
    while(L){
        p = L ;
        L = L->next ;
        delete p ;
    }
    return 0 ;
}
int ClearList(Linklist &L){
    Lnode *p , *q ;
    q = L->next ;
    p = L->next ;
    while(p){
        q = q->next ;
        delete p ;
        p = q ;
    }
    L->next = NULL ;
    return 0 ;
}
int GetLength(Linklist &L){
    Lnode *p = L->next ;
    int length = 0 ;
    while (p)
    {
        length++ ;
        p = p->next ;
    }
    return length ; 
}

int GetElem(Linklist &L , int index , int &e){
    if(index < 0 || index > GetLength(L) - 1 ) {
        cout << "the index is invalid " << endl ;
        return 0 ;
    }

    Lnode *p = L->next ;
    int j = 0 ;
    while( p && (index != j) ){
        j++ ;
        p = p->next ;
    }
    e = p->data ;
    return 0 ;
} 
int LocateElem(Linklist &L , int data){
    Lnode *p = L->next ;
    int j = 0 ;
    while(p){
        if(p->data == data) return j ;
        p = p->next ;
        j++ ;
    }
    cout << "data isn't in this linkedlist ." << endl ;
    return -1 ;
}   

int ListInsert(Linklist &L , int i , int data){
    if(i < 0 || i > GetLength(L))   return -1 ;
    Lnode *p = L ;
    int j = -1 ;//j=-1,i=0对应插入到index = 0 的位置
    while(p && (j!=i-1)){
        p = p->next ;
        j++ ;
    }
    Lnode *s = new Lnode ;
    s->data = data ;
    s->next = p->next ;
    p->next = s ;
    return 0 ;
}
void DeleteElem(Linklist &L , int i){
    if(i < 0 || i >= GetLength(L))  {cout << "the index i is invalid" << endl ; exit(0) ;}
    Lnode *p = L ;
    int j = -1 ;
    while(p && (j!=i-1)){
        p = p->next ;
        j++ ;
    }
    Lnode *s = p->next ;
    p->next = s->next ;
    delete s ;

}


void PrintList(Linklist &L){
    Lnode *p = L->next ;
    while(p){
        cout << p->data << "  " ;
        p = p->next ;
    }
    cout << endl ;
}

void CreateList_H(Linklist &L , int n){
    //insert the nodes from the head of linkedlist
    L = new Lnode ;
    L->next = NULL ;
    for(int i = n - 1 ; i >= 0 ; i--){
        Lnode *p = new Lnode ;
        cin >> p->data ;
        p->next = L->next ;
        L->next = p ;
    }
}
void CreateList_T(Linklist &L , int n ){
    //Insert elements from the tail of linkedlist
    L = new Lnode ;
    L->next = NULL ;
    Lnode *T = L ;
    for(int i = 0 ; i < n ; i++){
        Lnode *p = new Lnode ;
        cin >> p->data ;
        T->next = p ;
        T = T->next ;
        p->next = NULL ;
    }
    
}
int main(){
    Linklist L ;
    CreateList_T(L , 6) ;
    PrintList(L) ;
}