#include <iostream>
#include <array>

const int size{100};

int main(void)
{

    std::array <long double, size> factorials;

    factorials[1]=factorials[0] = 1.0;

    for(int i = 2; i < size; i++){
        factorials[i] = i * factorials[i-1];
    }
    for(int i = 0; i < size; i++){
        std::cout << i<< "! " << factorials[i] << std::endl;
    }
        

    return 0;
}