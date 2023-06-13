#include <iostream>
#include <string>
#include <cctype>
#include <iterator>

bool palindrome_check(std::string& pal_string);

int main(void)
{

    std::string user_line;

    std::cout << "Enter a string: " << std::endl;

    getline(std::cin, user_line);

    std::cout << "Now we are going to check if your string is a palindrome\n";

    std::cout << user_line << std::endl;

    if(palindrome_check(user_line))
    {
	std::cout << "Your string is a palindrome\n";
    }
    else
    {
    	std::cout << "Your string is not a palindrome\n";
    }
	

    return 0;
}

bool palindrome_check(std::string& pal_string)
{
    std::string::reverse_iterator r_it = pal_string.rbegin();

    std::string temp;

    for(int it = 0; it < pal_string.size(); it++)
    {
        temp.push_back(*r_it);
        r_it++;
    }

    if(pal_string == temp)
    {
        return true;
    }
    else
    {
        return false; 
    }
           

}
