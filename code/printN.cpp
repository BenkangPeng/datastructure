#include<iostream>
#include<ctime>
void printN_loop(int N){
    for(int i = 1 ; i <= N ; i++){
        std::cout << i << ' ' ;
    }
}
void printN_recursion(int N){
    if(N){
        printN_recursion(N - 1) ;
        std::cout << N << ' ' ;
    }
}
int main()
{
    int N ;
    std::cin >> N ;
    clock_t start1 , stop1 , start2 , stop2 ;
    start1 = clock() ;
    printN_recursion(N) ;
    stop1 = clock() ;

    start2 = clock() ;
    printN_loop(N) ;
    stop2 = clock() ;

    std::cout << "printN_recursion cost " << (double(stop1 - start1)) / CLK_TCK << std::endl ;
    std::cout << "printN_loop cost " << (double(stop2 - start2)) / CLK_TCK << std::endl ;
    return 0 ;
}