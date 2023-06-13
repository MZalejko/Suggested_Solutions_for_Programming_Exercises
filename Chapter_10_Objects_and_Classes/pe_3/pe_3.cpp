#include "pe_3.h"


Golf::Golf(const char * name, int i){
    strcpy(fullname, name);
    handicap = i;
}

Golf::~Golf(){}

void Golf::setgolf(){
    char temp[Len];
    int temp_hand{0};
    std::cout<<"Enter a fullname of a player: "<<std::endl;
    std::cin.get(temp, Len);
    std::cout<<"And his handicap: "<<std::endl;
    std::cin>>temp_hand;
    std::cin.get();
    if(strlen(temp)>0){ 
        *this = Golf(temp, temp_hand);
    }
}
void Golf::handc(int hc){
    std::cout<<"New handicap of "<<fullname<<std::endl;
    handicap = hc;
    std::cout<<"New handicap is seted on: "<<handicap<<std::endl;
}
void Golf::showgolf() const {
    std::cout<<"Players fullname: "<<fullname<<std::endl;
    std::cout<<"Players handicap: "<<handicap<<std::endl;
}
void Golf::length_of_fullname() const{
    std::cout<<strlen(fullname)<<std::endl;
}
