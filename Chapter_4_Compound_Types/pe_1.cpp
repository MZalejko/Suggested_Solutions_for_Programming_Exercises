#include <iostream>

const int SIZE{30};
constexpr int down_grade{1};

int main(void)
{

    char lname[SIZE];
    char fname[SIZE];
    
    int age{0};
    char grade{'F'};
    
    std::cout << "Enter your first name: ";
    std::cin.get(fname,SIZE);
    std::cin.get();
    
    std::cout << "Enter your last name: ";
    std::cin.getline(lname,SIZE-down_grade);
    
    std::cout << "What grade do you deserve: ";
    std::cin >> grade;

    std::cout << "How old are you: ";
    std::cin >> age;

    std::cout << "Name: " << lname << ', ' << fname << '\n'
             << "Your grade: " << char(grade + down_grade) << '\n'
             << "Age: " << age << std::endl;

    return 0;
}