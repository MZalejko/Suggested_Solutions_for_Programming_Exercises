#include "pe_6.h"

Move::Move(double a, double b){
    x = a;
    y = b;
}
Move:: ~Move(){}
void Move::showmove() const{
    std::cout<<"A value of X: "<<x<<std::endl;
    std::cout<<"A value of Y: "<<y<<std::endl;
}
Move Move::add(const Move& m){
    double x_temp, y_temp;
    x_temp = x + m.x;
    y_temp = y + m.y;

    Move temp(x_temp, y_temp);

    return temp;
}

void Move::reset(double a, double b){
    std::cout<<"Resteing the object..."<<std::endl;
    x = a;
    y = b;
    std::cout<<"Done."<<std::endl;
}
