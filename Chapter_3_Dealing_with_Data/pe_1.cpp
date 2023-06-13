#include <iostream>

const int inches_to_feet{12};


int main(void){


    std::cout << "Enter your height in inches:___\b\b\b";

    int height;

    std::cin >> height;

    int feets = height/inches_to_feet;

    std::cout << "Your height in inches: "<< height << "\n"
                "Your height in feets: " << feets << '.' << height % inches_to_feet << std::endl;

    return 0;
}