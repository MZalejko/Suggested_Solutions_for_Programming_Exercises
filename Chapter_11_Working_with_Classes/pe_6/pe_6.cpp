#include "pe_6.h"

Stonewt::Stonewt(double lbs){
    stone = (int)lbs/Lbs_per_stn;
    if(lbs > Lbs_per_stn){
        pds_left = (int)lbs%Lbs_per_stn + (lbs + (int)lbs);
    }
    else {
        pds_left = lbs;
    }    
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + pds_left;
}
Stonewt::Stonewt(){
    stone = pds_left = pounds = 0;
}
Stonewt::~Stonewt(){

}
bool Stonewt::operator<(const Stonewt& st){
    if(pounds < st.pounds){return true;}
    else {return false;}
}
bool Stonewt::operator>(const Stonewt& st){
    if(pounds > st.pounds){return true;}
    else {return false;}
}
bool Stonewt::operator<=(const Stonewt& st){
    if(pounds <= st.pounds){return true;}
    else {return false;}
}
bool Stonewt::operator>=(const Stonewt& st){
    if(pounds >= st.pounds){return true;}
    else {return false;}
}
bool Stonewt::operator!=(const Stonewt& st){
    if(pounds != st.pounds){return true;}
    else {return false;}
}
bool Stonewt::operator==(const Stonewt& st){
    if(pounds == st.pounds){return true;}
    else {return false;}
}
void Stonewt::show_lbs() const{
    std::cout << pounds << " pounds.\n";
}
void Stonewt::show_stn() const{
    std::cout << stone << " stones, " << pds_left << " pounds.\n";
}    
