#include <iostream>
#include <cctype>
#include <string>

constexpr short quit_value{1};

void upper_string(std::string& str);
std::string enter_string();


int main()
{
    std::string our_string;
    std::cout << "Enter a string (q to quiut): ";
    our_string = enter_string();

    while(our_string.size() > quit_value || (our_string[0] != 'Q' && our_string[0] != 'q'))
    {
        std::cout << our_string << std::endl;
        upper_string(our_string);
        std::cout << our_string << std::endl;
        std::cout << "Next string (q to quit): ";
        our_string = enter_string();
    }

    std::cout << "Bye!" << std::endl;

    return EXIT_SUCCESS;
}

void upper_string(std::string& str)
{
    if(str[0] != 'Q' && str[0] != 'q')
    {
        for(short it = 0; it < str.size(); it++)
        {
            str[it] = toupper(str[it]);
        }
    }
}
std::string enter_string()
{
    std::string temp;
    getline(std::cin, temp);
    return temp;
    
}