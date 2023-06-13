#include "golf.h"
 
int num_of_s_pl{0};

void setgolf(golf & g, const char * name, int i){
    strcpy(g.fullname, name);
    g.handicap = i;
    num_of_s_pl++;
}
int setgolf(golf & g){
    std::cout<<"Enter a fullname of a player: "<<std::endl;
    std::cin.get(g.fullname, Len);
    std::cout<<"And his handicap: "<<std::endl;
    std::cin>>g.handicap;
    std::cin.get();
    if(strlen(g.fullname)>0){
        num_of_s_pl++;
        return 1;
    }
    else{
        return 0;
    }
}
void handicap(golf & g, int hc){
    std::cout<<"New handicap of "<<g.fullname<<std::endl;
    g.handicap = hc;
    std::cout<<"New handicap is seted on: "<<g.handicap<<std::endl;
}
void showgolf(const golf & g){
    std::cout<<"Players fullname: "<<g.fullname<<std::endl;
    std::cout<<"Players handicap: "<<g.handicap<<std::endl;
}
