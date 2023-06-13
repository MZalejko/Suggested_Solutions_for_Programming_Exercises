#include "pe_1.h"

// Class Cd

Cd::Cd(const char* s1, const char* s2, int n, double x){
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd& d){
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd(){

}
Cd::~Cd(){

}
void Cd::Report() const{
    std::cout<<"Performes: "<<performers<<std::endl;
    std::cout<<"Label: "<<label<<std::endl;
    std::cout<<"Number of songs: "<<selections<<std::endl;
    std::cout<<"Playtime: "<<playtime<<std::endl;
}
Cd& Cd::operator=(const Cd& d){
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}   

// Class Classic

Classic::Classic(const char* s1,const char* s2,const char* s3, int n, double x) : Cd(s1, s2, n, x){
    strcpy(main_song, s3);
}

Classic::Classic() : Cd(){

}
Classic::~Classic(){

}
void Classic::Report() const{
    Cd::Report();
    std::cout<<"Main song: "<<main_song<<std::endl;
}