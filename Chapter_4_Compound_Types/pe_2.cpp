#include <iostream>
#include <string>

int main(void)
{

    std::string name;
    std::string dessert;

    std::cout << "Enter your name: ";
    getline(std::cin,name);

    std::cout<<"What is your favorite dessert? ";
    getline(std::cin, dessert);

    std::cout<< "I have a " << dessert
            << " for you " << name << '\n';




    return 0;
}