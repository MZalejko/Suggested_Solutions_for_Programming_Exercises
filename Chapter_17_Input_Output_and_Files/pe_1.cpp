#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char** argv)
{

    std::cout << "Enter signs!" << std::endl;
    std::cout << "Program will terminate with \'$\' sign." << std::endl;

    char input_char;
    short quantity{0};

    do
    {
        std::cin.get(input_char);
        quantity++;
    } while (input_char != '$');

    std::cin.putback(input_char);

    std::cout << "Hey, you have entered " << quantity << " signs.\n";
    std::cout << "The last sign in buffor is " << char(std::cin.get()) << std::endl;

    std::cout << "Thank you!" << std::endl;    


    return EXIT_SUCCESS;
}