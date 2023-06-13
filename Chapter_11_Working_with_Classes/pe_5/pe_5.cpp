#include "pe_5.h"

Stonewt::Stonewt(double lbs, Mode _lbs){
    pounds = lbs;
    if(lbs > Lbs_per_stn){
        stone = lbs/Lbs_per_stn;
        pds_left = (int)lbs%Lbs_per_stn + (lbs - (int)lbs);
    }
    else{
        stone = 0;
        pds_left = lbs;
    }
    _Mode = _lbs;
    
}
Stonewt::Stonewt(int stn, double lbs, Mode _stn){
    stone = stn;
    pounds = stn * Lbs_per_stn + lbs;
    if(lbs > Lbs_per_stn){
        stone += lbs/Lbs_per_stn;
        pds_left = (int)lbs%Lbs_per_stn + (lbs - (int)lbs);
    }
    else{
        pds_left = (int)lbs%Lbs_per_stn + (lbs - (int)lbs);
    }
    _Mode = _stn;
}
Stonewt::Stonewt(){
    stone = pds_left = pounds = 0;
    _Mode = Mode::STN;
}
Stonewt::~Stonewt(){

}
Stonewt Stonewt::operator+(const Stonewt& add) const{
    return Stonewt(stone + add.stone, pds_left + add.pds_left);
}
Stonewt Stonewt::operator-(const Stonewt& diff) const{
    return Stonewt(stone - diff.stone, pds_left - diff.pds_left);
}
Stonewt Stonewt::operator*(double n) const{
    return Stonewt(stone * n, pds_left * n);
}
std::ostream& operator<<(std::ostream& os, const Stonewt& st){

    if(st._Mode == Stonewt::Mode::LBS){
         os<<st.pounds<<" pounds";
    }
    else if (st._Mode == Stonewt::Mode::STN){
        os<<st.stone<<" stones and "<<st.pds_left<<" pounds";            
    }

    return os;
}