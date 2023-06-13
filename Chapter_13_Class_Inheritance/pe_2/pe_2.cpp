#include "pe_2.h"

Cd::Cd(const char* s1,const char* s2, int n, double x){
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;

}
Cd::Cd(const Cd& d){
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;


}
Cd::Cd(){
    performers = new char[5];
    label = new char[5];
    strcpy(performers, "Empty");
    strcpy(label, "Empty");
    selections = 0;
    playtime = 0;

}
Cd::~Cd(){
    delete [] performers;
    delete [] label;
    std::cout << "CD destructor" << std::endl;
}
void Cd::Report() const{
    std::cout<<"Performes: "<<performers<<std::endl;
    std::cout<<"Label: "<<label<<std::endl;
    std::cout<<"Number of songs: "<<selections<<std::endl;
    std::cout<<"Playtime: "<<playtime<<std::endl;
}
Cd& Cd::operator=(const Cd& d){
    if(this == &d){
        return *this;
    }
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;

}

Classic::Classic(const char* s1,const char* s2,const char* s3, int n, double x) : Cd(s1, s2, n, x){
    main_song = new char[strlen(s3) + 1];
    strcpy(main_song, s3);
}
Classic::Classic() :Cd(){
    main_song = new char[5];
    strcpy(main_song, "Empty");
}
Classic::Classic(const Classic& cl1) : Cd(cl1){
    main_song = new char[strlen(cl1.main_song) + 1];
    strcpy(main_song, cl1.main_song);
}
Classic::~Classic(){
    delete [] main_song;
    std::cout << "Classic destructor" << std::endl;
}
void Classic::Report() const{
    Cd::Report();
    std::cout << "Main song: " << main_song << std::endl;
}
Classic& Classic::operator=(const Classic& cl1) {
    if(this == &cl1){
        return *this;
    }
    Cd::operator=(cl1);
    delete [] main_song;
    main_song = new char[strlen(cl1.main_song) + 1];
    strcpy(main_song, cl1.main_song);

    return *this;
}