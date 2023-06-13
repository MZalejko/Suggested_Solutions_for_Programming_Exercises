#include "pe_5.h"

int main(){

    Stonewt first(12,24.5);
    Stonewt second(10.0);
    Stonewt third;

    std::cout<<first<<std::endl;
    std::cout<<second<<std::endl;

    third = first + second;
    first = first - second;
    second = second * 2.5;

    std::cout<<third<<std::endl;
    std::cout<<first<<std::endl;
    std::cout<<second<<std::endl;

    first.set_LBS();
    second.set_LBS();
    third.set_LBS();

    std::cout<<third<<std::endl;
    std::cout<<first<<std::endl;
    std::cout<<second<<std::endl;



    return 0;
}