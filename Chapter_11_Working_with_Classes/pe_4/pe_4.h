#ifndef PE_4_H
#define PE_4_H
#include <iostream>

class Time{

    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        friend Time operator+(const Time& first, const Time& second);
        friend Time operator-(const Time& first, const Time& second);
        friend Time operator*(const Time& first, double n);
        friend Time operator*(double n, const Time& second){return second * n;};
        friend std::ostream& operator<<(std::ostream& os, const Time& first);

};



#endif //ZAD_4_h