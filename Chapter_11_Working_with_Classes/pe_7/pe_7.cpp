#include "pe_7.h"

Complex::Complex(){
    real = imaginary = 0.0;
}
Complex::Complex(double rl, double imgn){
    real = rl;
    imaginary = imgn;
}
Complex::~Complex(){

}
Complex Complex::operator+(const Complex& class_elm) const{
    return Complex(real + class_elm.real, (imaginary + class_elm.imaginary));
}
Complex Complex::operator-(const Complex& class_elm) const{
    return Complex(real - class_elm.real, (imaginary - class_elm.imaginary));
}
Complex Complex::operator*(const Complex& class_elm) const{
    return Complex(real * class_elm.real - imaginary * class_elm.imaginary, (real * class_elm.imaginary + imaginary * class_elm.real));
}
Complex Complex::operator~(){
    return Complex(real, -imaginary);
}
Complex operator*(double n,const Complex& class_elm){
    return Complex(n * class_elm.real, n * class_elm.imaginary);
}
std::ostream& operator<<(std::ostream& os, const Complex& class_elem){
    os << "(" << class_elem.real <<","<< class_elem.imaginary <<"i)";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& class_elem){
    std::cout << "Real component: ";
    if(is >> class_elem.real){
        std::cout << "Imaginary component: ";
        is >> class_elem.imaginary;
        std::cout<<std::endl;
    }

    return is;
}

