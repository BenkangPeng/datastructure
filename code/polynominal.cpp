#include<iostream>
#include<cmath>
#include<ctime>
#define N 9 
#define K 1e7 // numbers of loop
double a[10] = { 2.1 , 3.4 , 2 , 1.3 , 3 , 8.8 , 4.3 , 5.3 , 5.3 , 4.3} ;
double func1(double x , double *a ){
    double res = a[0] ;
    for(int i = 1 ; i <= N ; i++){
        res += a[i] * pow(x , i) ;
    }
    return res ;
    //std:: cout << "the result of polynominal by func1 is " << res << std::endl ; 
}
double func2(double x , double *a){
    // Qin Jiushao's algorithm
    double res = a[9] ;
    for(int i = N ; i > 0 ; i--){
        res = a[i - 1] + res * x ;
    }
    return res ;
    //std::cout << "the resulr of polynominal by func2 is " << res << std::endl ;
}
void time_func1(){
    clock_t start , stop ;
    start = clock() ;
    for(int i = 0 ; i < K ; i++){
        func1( 2.4 , a ) ;   
    }
    stop = clock() ;
    std::cout << "func1 cost " << (double(stop - start)) / CLK_TCK / K << " s per time" << std::endl ;
}
void time_func2(){
    clock_t start , stop ;
    start = clock() ;
    for(int i = 0 ; i < K ; i++){
        func2( 2.4 , a ) ;   
    }
    stop = clock() ;
    std::cout << "func2 cost " << (double(stop - start)) / CLK_TCK / K  << " s per time" << std::endl ;
}
int main(){
    double x ; 
    std::cin >> x ; 
    std::cout << "the result of func1 is " << func1(x , a) << std::endl ;    
    std::cout << "the result of func2 is " << func2(x , a) << std::endl ;    
    func2(x , a) ;
    time_func1() ;
    time_func2() ;
}