#include <iostream>

int main(void){

    int first, second, total{0};

    std::cout << "Enter two numbers: ";

    std::cin >> first >> second;

    for(int i = first; i <= second; i++){

        total += i;
    }

    std::cout << "Sum of numbers from " << first << " to " << second
            << " is " << total <<std::endl;

    return 0;
}