#include <iostream>
#include <cctype>


int main()
{

    char sign;

    std::cout << "Enter sign, @ ends program\n";
    while(std::cin >> sign && sign != '@')
    {
        if(isalpha(sign))
        {
            if(isupper(sign))
            {
                std::cout << (char)tolower(sign);
            }
            else if(islower(sign))
            {
                std::cout << (char)toupper(sign);
            }
        }
    }
    std::cout << "\nGoodbye!\n";

    return 0;
}