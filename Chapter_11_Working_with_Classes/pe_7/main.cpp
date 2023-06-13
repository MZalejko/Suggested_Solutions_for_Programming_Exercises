#include "pe_7.h"

int main(){

    Complex a(3.0, 4.0);
    Complex c;

    std::cout << "Enter a complex number (k, to end):\n";
    while(std::cin >> c){
        std::cout << "C is " << c << '\n';
        std::cout << "coupled with C is " << ~c <<'\n';
        std::cout << "A is " << a << '\n';
        std::cout << "A + C " << a + c << '\n';
        std::cout << "A - C " << a - c << '\n';
        std::cout << "A * C " << a * c << '\n';
        std::cout << "2 * C " << 2 * c << '\n';
        std::cout << "Enter a complex number (k, to end):\n";
    }
    std::cout<<"Done!\n";

    return 0;
}