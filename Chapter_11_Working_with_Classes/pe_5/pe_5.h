#ifndef PE_5_H
#define PE_5_H
#include <iostream>

class Stonewt{

    private:
        enum{Lbs_per_stn = 14};
        enum class Mode{STN, LBS};
        Mode _Mode;
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs, Mode _lbs = Mode::LBS);
        Stonewt(int stn, double lbs, Mode _stn = Mode::STN);
        Stonewt();
        ~Stonewt();
        void set_LBS(){_Mode = Mode::LBS;};
        void set_STN(){ _Mode = Mode::STN;};
        Stonewt operator+(const Stonewt& add) const;
        Stonewt operator-(const Stonewt& diff) const;
        Stonewt operator*(double n) const;
        friend Stonewt operator*(double n, const Stonewt& multp) {return multp * n;};
        friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);

};


#endif // PE_5_H