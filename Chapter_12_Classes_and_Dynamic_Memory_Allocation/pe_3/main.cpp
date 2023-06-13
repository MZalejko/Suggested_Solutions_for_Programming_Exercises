#include "pe_3.h"

const int STKS{4};

int main(){

    Stock stocks[STKS] = {
        {"NanoSmart", 12, 20.0},
        {"BurakPOL", 200, 2.0},
        {"GruzPOL", 130, 3.25},
        {"FutroPOL", 60, 6.5}
    };
    std::cout << "Investment portfolio: \n";
    
    for(int st = 0; st < STKS; st++){
        std::cout << stocks[st];
    }

    const Stock* top = &stocks[0];
    for(int st = 0; st < STKS; st++){
        top = &top -> topval(stocks[st]);
    }
    std::cout << "The most valuable package:\n";
    std::cout << *top << std::endl;

    return 0;
}