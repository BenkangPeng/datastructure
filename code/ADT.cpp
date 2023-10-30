#include <iostream>
using namespace std ;
typedef struct 
{
    float real;
    float imag;
} Complex;
void assign(Complex &A, float real, float imag) {
    A.real = real;
    A.imag = imag;
}
void print(Complex A){
    cout << A.real << '+' << A.imag << 'i' << endl ;
}
void add(Complex &A , Complex B , Complex C){
    A.real = B.real + C.real ;
    A.imag = B.imag + C.imag ;
}
void minus(Complex &A , Complex B , Complex C){
    A.real = B.real - C.real ;
    A.imag = B.imag - C.imag ;
}
void multiply(Complex &A , Complex B , Complex C){
    A.real = B.real * C.real - B.imag * C.imag ;
    A.imag = B.real * C.imag + B.imag * C.real ;
}
void divide(Complex &A , Complex B , Complex C){
    A.real = (B.real * C.real + B.imag * C.imag) / (C.real * C.real + C.imag * C.imag) ;
    A.imag = ( - B.real * C.imag + B.imag * C.real ) / (C.real * C.real + C.imag * C.imag) ;
}
int main() {
    Complex A , B , C ;
    assign(A , 1 , 2);
    assign(B , 3 , 4) ;
    assign(C , 5 , 6) ;
    divide(A , B , C) ;
    print(A) ;
    return 0;
}
