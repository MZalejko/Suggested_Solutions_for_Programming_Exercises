#include <iostream>

int factorial(int a);

int main(void){

    int results{1}, number;
    std::cout<<"Enter a number, program will count the factorial of it."<<std::endl;
    while(std::cin>>number){
        results = factorial(number);
        std::cout<<"Factorial of "<<number<<" is: "<<results<<std::endl;

    }

    std::cout<<"Thank you!"<<std::endl;

    return 0;
}

int factorial(int a){

    if(a > 1)
        a *= factorial(a-1);

    return a;
}