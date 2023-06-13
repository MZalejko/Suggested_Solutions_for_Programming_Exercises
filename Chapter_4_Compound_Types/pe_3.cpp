#include <iostream>
#include <cstring>

constexpr int size{30};
constexpr int multiply{2};
constexpr int downsize{1};

int main(void)
{

    char name[size];
    char surname[size];
    char evrt[multiply*size];

    std::cout << "Enter your name: ";
    std::cin.getline(name, size - downsize);
    std::cout<<"Enter your surname: ";
    std::cin.getline(surname, size - downsize);

    strncat(surname,", ",(size - downsize));
    strncpy(evrt, surname, (multiply*size - downsize));
    strncat(evrt, name, (size*multiply - downsize));

    std::cout << "All informations in one line: " << evrt << std::endl;


    return 0;
}