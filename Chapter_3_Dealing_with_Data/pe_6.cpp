#include <iostream>

int main(void)
{

    long miles, galons;
    
    std::cout << "How many miles have you driven: " << std::endl;
    
    std::cin >> miles;
    
    std::cout << "How many galones of gasoline have you used: \n";
    
    std::cin >> galons;

    std::cout << "You have driven: " << miles/galons << " miles per galon.\n";

    return 0;
}