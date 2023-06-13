#include <iostream>

const int size{12};
const char * months[size]{"January", "February", "March", "April", "May", 
                    "June", "Juli", "August", "September",
                    "Oktober", "November", "December"};

int main(){

    int * values;
    values = new int[size];
    int year_sum{0};

    for(int i = 0; i < size; i++){
        std::cout << "Enter the number of saled books in " << *(months + i) << ": ";
        std::cin >> *(values + i);
        year_sum += *(values + i);
    }
    std::cout << "In this year you have sold " << year_sum << " books!\n";

    delete [] values; 
    return 0;
}