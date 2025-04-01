#include <iostream>
#include "complex.hpp"

using namespace std;

int main (){
    using cmplx = complex<double>;
    // using coco = complex<float>;
    cmplx a(2.56, 2);
    cmplx b(-2, 1);
    cmplx c(-3, -3.5);
    double d=3.5;
    cout << "a " << a << endl;
    cout << "b " << b << endl;
    
    a += b;
    cout <<"a+=b "<< a << endl;
    
    b *= b;
    cout <<"b^2 "<< b << endl;

    cout <<"-b "<< -b << endl;
    cout <<"a.conj "<< a.conj() << endl;
    cout << "a+a* "<< a + a.conj() << endl;
    cout << "a*b " << a * b << endl;
    cout << "c+d " << c+d << endl;
    cout << "c*d " << c*d << endl;

    c-=c.conj();
    cout << "c-c* "<< c << endl;

    return 0;
}
    
