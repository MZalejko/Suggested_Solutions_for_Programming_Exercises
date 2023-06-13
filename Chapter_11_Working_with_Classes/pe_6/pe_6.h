#ifndef PE_6_H
#define PE_6_H
#include <iostream>

class Stonewt{

    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        bool operator<(const Stonewt& st);
        bool operator>(const Stonewt& st);
        bool operator<=(const Stonewt& st);
        bool operator>=(const Stonewt& st);
        bool operator!=(const Stonewt& st);
        bool operator==(const Stonewt& st);
        void show_lbs() const;
        void show_stn() const;    

};



#endif //PE_6_H