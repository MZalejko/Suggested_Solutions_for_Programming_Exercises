#include "pe_4.h"

Time::Time(){
    hours = minutes = 0;
}
Time::Time(int h, int m){
    hours = h;
    minutes = m;
}
void Time::AddMin(int m){
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}
void Time::AddHr(int h){
    hours += h;
}
void Time::Reset(int h, int m){
    hours = h;
    minutes = 0;
}
Time operator+(const Time& first, const Time& second){
    Time sum;
    sum.minutes = first.minutes + second.minutes;
    sum.hours = first.hours + second.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}
Time operator-(const Time& first, const Time& second){
    Time diff;
    diff.minutes = first.minutes - second.minutes;
    diff.hours = first.hours - second.hours;
    if(diff.minutes < 0){
        diff.hours -= 1;
        diff.minutes = diff.minutes + 60;
    }
    return diff;
}
Time operator*(const Time& first, double n){
    Time result;
    double temp;
    temp = (first.hours * 60 + first.minutes) * n;

    result.hours = temp/60;
    result.minutes = (int)temp%60;
    // result.hours += result.minutes / 60;
    // result.minutes %= 60;
    return result;
}
std::ostream& operator<<(std::ostream& os, const Time& first){
    os<<first.hours<<" hours, "<<first.minutes<<" minutes."<<std::endl;
    return os;

}