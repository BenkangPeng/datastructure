#include<iostream>
int MaxSubSeqSum_1(int *a , int N){
    int ThisSum = 0 , MaxSum = 0 ;
    for(int i = 0 ; i < N ; i++){
        for(int j = i ; j < N ; j++){
            ThisSum = 0 ;
            for(int k = i ; k <= j ; k++){
                ThisSum += a[k] ;
                MaxSum = (ThisSum > MaxSum) ? ThisSum : MaxSum ;
            }
        }
    }
    return MaxSum ;
} 
int MaxSubSeqSum_2(int *a , int N){
    int ThisSum = 0 , MaxSum = 0 ;
    for(int i = 0 ; i < N ; i++){
        ThisSum = 0 ;
        for(int j = i ; j < N ; j++){
            ThisSum += a[j] ;
            MaxSum = (ThisSum > MaxSum) ? ThisSum : MaxSum ;
        }
    }
    return MaxSum ;
}
int main(){
    int a[8] = {2 , -3 , 0 , 4 , -2 , 3 , -1 , 10} ;
    std::cout << MaxSubSeqSum_2(a , 8) ;
}