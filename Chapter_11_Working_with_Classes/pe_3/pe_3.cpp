#include "pe_3.h"
#include <cmath>

namespace VECTOR
{
    const double rad_to_deg = 45.0 / std::atan(1.0);
    
    void Vector::set_mag(){
        mag = std::sqrt(x * x + y * y);
    }

    void Vector::set_ang(){
        if(x == 0.0 && y == 0.0){ang = 0.0;}
        else{ang = std::atan2(y,x);}
    }

    void Vector::set_x(){
        x = mag * std::cos(ang);
    }

    void Vector::set_y(){
        y = mag * std::sin(ang);
    }
    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2 / rad_to_deg;
            set_x();
            set_y();
        }
        else{
            std::cout<<"Incorrect value of third argument Vector() --";
            std::cout<<"I'm setting Vector on 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2 / rad_to_deg;
            set_x();
            set_y();

        }
        else{
            std::cout<<"Incorrect value of third argument Vector() --";
            std::cout<<"I'm setting Vector on 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector(){}
    void Vector::polar_mode(){
        mode = POL;
    }
    void Vector::rect_mode(){
        mode = RECT;
    }
    Vector Vector::operator+(const Vector& b) const{
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector& b) const{
        return Vector(x - b.x, y - b.y);

    }
    Vector Vector::operator-() const{
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const{
        return Vector(n * x, n * y);
    }
    Vector operator*(double n, const Vector& b) {
        return b * n;
    }
    std::ostream& operator<<(std::ostream& os, const Vector& b){
        if(b.mode == Vector::RECT){
            os<<"(x,y) = (" << b.x <<", "<< b.y << ")"; 
        }
        else if(b.mode == Vector::POL){
            os<<"(m,a) = ("<<b.mag<<", "<<b.ang * rad_to_deg << ")";
        }
        else{
            os<<"Incorrect mode of representation of the Vector object.";
        }
        return os;
    }
}    