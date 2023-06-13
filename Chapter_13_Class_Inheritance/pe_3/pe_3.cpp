#include "pe_3.h"


//Class Ma- abstraction basic class

Ma::Ma(const char* lbl, int rat){
    label = new char[strlen(lbl) + 1];
    strcpy(label, lbl);
    rating = rat;
}
Ma::Ma(const Ma& Ma_next){
    label = new char[strlen(Ma_next.label) + 1];
    strcpy(label, Ma_next.label);
    rating = Ma_next.rating;
}
Ma::~Ma(){
    delete [] label;
}
Ma& Ma::operator=(const Ma& Ma_next){  
    if(this == &Ma_next){
        return *this;
    }
    delete [] label;
    label = new char[strlen(Ma_next.label) + 1];
    rating = Ma_next.rating;
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Ma& base){

    os << base.label << std::endl;
    os << base.rating << std::endl;

    return os;
}


//Class baseDma

baseDma::baseDma(const char* lbl, int rat) : Ma(lbl, rat){}
baseDma::baseDma(const baseDma& base_next) : Ma(base_next){}
baseDma::~baseDma(){}
baseDma& baseDma::operator=(const baseDma& base_next){
    if(this == &base_next){
        return *this;
    }
    Ma::operator=(base_next);
    return *this;
}
void baseDma::View() const{
    std::cout << "Label: " << ret_label() << std::endl;
    std::cout << "Rating: " << ret_rating() << std::endl;
}
std::ostream& operator<<(std::ostream& os, const baseDma& base){
    os << (const Ma&)base;
    return os;
}


//Class lacksDma

lacksDma::lacksDma(const char* lbl, const char* clr, int rat) :Ma(lbl,rat){
    strcpy(color, clr);
}
lacksDma::lacksDma(const lacksDma& lacks_next) :Ma(lacks_next){
    strcpy(color, lacks_next.color);
}
lacksDma::~lacksDma(){}
lacksDma& lacksDma::operator=(const lacksDma& lacks_next){
    if(this == &lacks_next){
        return *this;
    }
    Ma::operator=(lacks_next);
    strcpy(color, lacks_next.color);
    return *this;
}
void lacksDma::View() const{
    std::cout << "Label: " << ret_label() << std::endl;
    std::cout << "Rating: " << ret_rating() << std::endl;
    std::cout << "Color: " << color << std::endl;
}
std::ostream& operator<<(std::ostream& os, const lacksDma& lacks){
    os << (const Ma&)lacks;
    os << lacks.color << std::endl;
    return os;
}


//Class hasDma

hasDma::hasDma(const char* lbl, const char* stl, int rat) :Ma(lbl, rat){
    style = new char[strlen(stl) + 1];
    strcpy(style, stl);
}
hasDma::hasDma(const hasDma& has_next) :Ma(has_next){
    style = new char[strlen(has_next.style) + 1];
    strcpy(style, has_next.style);
}
hasDma::~hasDma(){
    delete [] style;
}
hasDma& hasDma::operator=(const hasDma& has_next){
    if(this == &has_next){
        return *this;
    }
    Ma::operator=(has_next);
    delete [] style;
    style = new char[strlen(has_next.style) + 1];
    strcpy(style, has_next.style);
    return *this;
}
void hasDma::View() const{
    std::cout << "Label: " << ret_label() << std::endl;
    std::cout << "Rating: " << ret_rating() << std::endl;
    std::cout << "Style: " << style << std::endl;
}
std::ostream& operator<<(std::ostream& os, const hasDma& has){
    os << (const Ma&) has;
    os << has.style << std::endl;

    return os;
}