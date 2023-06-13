#include <iostream>

constexpr int display_width{40};

int main()
{
    char exit;
    
    std::cout << "Display menu, choose an option: " << std::endl;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout.width(display_width);
    std::cout << "a:"; 
    std::cout << "alphabetical display" << std::endl;
    std::cout.width(display_width);
    std::cout << "b:";
    std::cout << "rating ascending display" << std::endl;
    std::cout.width(display_width);
    std::cout << "c:";
    std::cout << "rating descending display" << std::endl;
    std::cout.width(display_width);
    std::cout << "d:";
    std::cout << "price ascending display" << std::endl;
    std::cout.width(display_width);
    std::cout << "e:";
    std::cout << "price descending display" << std::endl;
    std::cout.width(display_width);
    std::cout << "q:";
    std::cout << "quit" << std::endl;

    


    return 0;

}

