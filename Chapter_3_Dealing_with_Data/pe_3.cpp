#include <iostream>

const int degree_to_minut{60};

const int minut_to_second{60};

int main(void)
{
   

    double degrees, minutes,seconds,converted;

    std::cout << "Enter geographic lenght in degrees, minutes and seconds \n";

    std::cout << "At first degrees: ";

    std::cin >> degrees;

    std::cout << "Now minutes: ";

    std::cin >> minutes;

    std::cout << "And at least seconds: ";

    std::cin >> seconds;

    converted = degrees + ((minutes + (seconds/minut_to_second))/degree_to_minut);


    std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << converted << std::endl;


    return 0;
}