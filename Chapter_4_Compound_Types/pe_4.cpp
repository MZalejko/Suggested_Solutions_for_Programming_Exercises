#include <iostream>
#include <string>

constexpr int size{30};

int main(void)
{

    std::string name;
    std::string surname;
    std::string evrt;

    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "Enter your surname: ";
    getline(std::cin, surname);

    evrt = (surname + ", ") + name;
    std::cout << "Everything in one line: " << evrt << std::endl;
    

    return 0;
}