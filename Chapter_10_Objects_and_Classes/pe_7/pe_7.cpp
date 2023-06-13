#include "pe_7.h"

Plorg::Plorg(const char * name, int satiety){
    if(strlen(name) > 19){
        std::cout<<"Plorg's name is too long!"<<std::endl;
        std::cout<<"Set new one!"<<std::endl;
        char temp[19];
        std::cin.getline(temp, length_of_name);
        strncpy(name_of_Plorg, temp, length_of_name);
        satiety_factor = satiety;
    }
    else{
        strncpy(name_of_Plorg, name, length_of_name);
        satiety_factor = satiety;
    }
    std::cout<<name_of_Plorg<<" is born!"<<std::endl;

}
Plorg::~Plorg(){};
void Plorg::change_satiety(int new_satiety){
    satiety_factor = new_satiety;
    std::cout<<"New satiety have been seted!"<<'\n';
}
void Plorg::say_my_name() const{
    std::cout<<"HI!!\nMy name is "<<name_of_Plorg<<std::endl;
    std::cout<<"My satiety is "<<satiety_factor<<std::endl;
}


