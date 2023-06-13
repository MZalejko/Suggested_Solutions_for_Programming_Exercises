#include "pe_1.h"

Cow::Cow(){
    strcpy(name, "MUUUUUUU");
    hobby = new char[strlen("GRAAAAAS")+1];
    strcpy(hobby, "GRAAAAAS");
    weight = 1000;

}
Cow::Cow(const char* nm, const char* ho, double wt){
    if(strlen(nm) > 20){
        std::cout<<"Sorry, your cow's name can have only 20 signs."<<std::endl;
    }
    strncpy(name, nm, 20);
    hobby = new char[strlen(ho)+1];
    strcpy(hobby, ho);
    weight = wt;

}
Cow::Cow(const Cow& c){
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    weight = c.weight;
}
Cow::~Cow(){
    delete [] hobby;
}
Cow& Cow::operator=(const Cow& c){
    if(this == &c){
        return *this;
    }
    delete [] hobby;
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;

    return *this;
}
void Cow::Show() const{
    std::cout<<"Name of Cow: "<<name<<std::endl;
    std::cout<<"Cow's hobby: "<<hobby<<std::endl;
    std::cout<<"Weight of Cow: "<<weight<<" kg."<<std::endl;
}    