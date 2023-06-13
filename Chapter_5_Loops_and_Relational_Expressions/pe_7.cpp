#include <iostream>
#include <string>

struct Car
{
    std::string mark;
    int build_year;
};

int main(void)
{
    
    int num_of_structs{0};
    Car *marks;
    std::cout << "How many cars would you like to enter?: " << std::endl;
    std::cin >> num_of_structs;
    marks = new Car[num_of_structs];
    std::cin.get();
    
    for(int i = 0; i < num_of_structs; i++)
    {
        std::cout << "Car #" << i+1 << std::endl;
        std::cout << "Name of car: ";
        getline(std::cin, marks[i].mark);
        std::cout << "Year of build: ";
        std::cin >> marks[i].build_year;
        std::cin.get();
        std::cout << '\n';
    }

    for(int i = 0; i < num_of_structs; i++)
    {
        std::cout<<marks[i].build_year << " " << marks[i].mark << std::endl;
    }

    delete [] marks;
    return 0;
}