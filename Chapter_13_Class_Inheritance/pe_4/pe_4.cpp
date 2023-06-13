#include "pe_4.h"


Port::Port(const char* br, const char* st, int b){
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bootles = b;
}
Port::Port(const Port& pr){
    brand = new char[strlen(pr.brand) + 1];
    strcpy(brand, pr.brand);
    strcpy(style, pr.style);
    bootles = pr.bootles;
}
Port::~Port(){
    delete [] brand;
}
Port& Port::operator=(const Port& pr){
    if(this == &pr){
        return *this;
    }
    delete [] brand;
    brand = new char[strlen(pr.brand) + 1];
    strcpy(brand, pr.brand);
    strcpy(style, pr.style);
    bootles = pr.bootles;

    return *this;
}
Port& Port::operator+=(int b){
    bootles = bootles + b;
    return *this;
}
Port& Port::operator-=(int b){
    if(bootles > 0 && bootles >= b){
        bootles = bootles - b;
    }
    else if(bootles > 0 && bootles < b){
        std::cout << "We can only substract " << bootles << " bottles." << std::endl;
        bootles = 0;
    }
    return *this;
}
void Port::Show() const{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Type: " << style << std::endl;
    std::cout << "Bottles: " << bootles << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Port& pr){

    os << pr.brand << " ," << pr.style << " ," << pr.bootles;

    return os;
}

VintagePort::VintagePort(const char* br, const char* st, const char* nck, int b, int y) :Port(br,st,b){
    nickname = new char[strlen(nck) + 1];
    strcpy(nickname, nck);
    year = y;
}
VintagePort::VintagePort(const VintagePort& vpr) :Port(vpr){
    nickname = new char[strlen(vpr.nickname) + 1];
    strcpy(nickname, vpr.nickname);
    year = vpr.year;
}
VintagePort::~VintagePort(){
    delete [] nickname;
}
VintagePort& VintagePort::operator=(const VintagePort& vpr){
    if(this == &vpr){
        return *this;
    }
    Port::operator=(vpr);
    delete [] nickname;
    nickname = new char[strlen(vpr.nickname) + 1];
    strcpy(nickname, vpr.nickname);
    year = vpr.year;

    return *this;
}
void VintagePort::Show() const{
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vpr){
    os << (const Port&) vpr;
    os << " ," << vpr.nickname << " ," << vpr.year;
    return os;
}
