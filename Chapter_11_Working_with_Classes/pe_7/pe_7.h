#ifndef PE_7_H
#define PE_7_H
#include <iostream>

class Complex{

    private:
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double rl, double imgn);
        ~Complex();
        Complex operator+(const Complex& class_elm) const;
        Complex operator-(const Complex& class_elm) const;
        Complex operator*(const Complex& class_elm) const;
        Complex operator~();
        friend Complex operator*(double n,const Complex& class_elm);
        friend std::ostream& operator<<(std::ostream& os, const Complex& class_elem);
        friend std::istream& operator>>(std::istream& is, Complex& class_elem);

};



#endif // PE_7_H