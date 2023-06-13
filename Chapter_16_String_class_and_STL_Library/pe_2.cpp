#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

bool palindrome_check(std::string & pal_string);

int main(void)
{

    std::string user_line;

    std::cout << "Enter your string: " << std::endl;

    getline(std::cin, user_line);

    std::cout << user_line << std::endl;

    std::cout << "Now we will check if your string is a palindrome!\n";

    if(palindrome_check(user_line))
        std::cout << "Yes it is!" << std::endl;
    else
        std::cout << "No it isn't!" << std::endl;


    return 0;
}

bool palindrome_check(std::string & pal_string)
{
    std::string::reverse_iterator r_it = pal_string.rbegin();

    std::string first_temp, second_temp;

    for(int it = 0; it < pal_string.size(); it++)
    {
        if(isalnum(*r_it))
        {
            first_temp.push_back(tolower(*r_it));
            second_temp.push_back(tolower(*r_it));
            r_it++;
        }
        else
        {
            r_it++;
        }

    }

    std::cout << first_temp << std::endl;
    std::cout << second_temp << std::endl;

    if(first_temp == second_temp)
        return true;
    else
        return false;    
}