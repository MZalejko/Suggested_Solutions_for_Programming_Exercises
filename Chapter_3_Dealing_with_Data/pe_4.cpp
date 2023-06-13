#include <iostream>

const int seconds_to_day{86400};

const int minuts_to_houres{60};

const int seconds_to_houres{3600};

int main(void){



    long long seconds;

    std::cout << "Enter the number of seconds: \n";

    std::cin >> seconds;

    long c_sec, c_min, c_hr, c_day;

    c_day = seconds/seconds_to_day;
    c_hr = (seconds%seconds_to_day)/seconds_to_houres;
    c_min = ((seconds%seconds_to_day)%seconds_to_houres)/minuts_to_houres;
    c_sec = ((seconds%seconds_to_day)%seconds_to_houres)%minuts_to_houres;

    std::cout << seconds << " seconds = " << c_day << " days, " << c_hr << " hours, " << c_min << " minutes and " << c_sec << " seconds.";



    return 0;
}