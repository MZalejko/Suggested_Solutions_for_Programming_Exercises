#include <iostream>

double add(double x, double y);
double calculate(double x, double y, double (*pf)(double z, double v));

int main(){

    double a,b,c;
    double (*pf)(double z, double v);
    pf = add;
    std::cin>>a>>b;
    c = calculate(a,b,(*pf));
    std::cout<<"A: "<<a<<std::endl;
    std::cout<<"B: "<<b<<std::endl;
    std::cout<<"C: "<<c<<std::endl;
    return 0;
}

double add(double x, double y){
    return x + y;
}
double calculate(double x, double y, double (*pf)(double z, double v)){
    return (*pf)(x,y);
}