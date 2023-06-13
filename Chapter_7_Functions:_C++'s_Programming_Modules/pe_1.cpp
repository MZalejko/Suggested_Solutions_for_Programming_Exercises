#include <iostream>

double m_har(double a, double b);

int main(void){

    double harm;
    double x,y;
    std::cout<<"Enter two numbers, 0 ends life of program.\n";
    std::cin>>x>>y;

    while(x && y){
        harm = m_har(x,y);
        std::cout<<"Harmonic mean is: "<<harm<<std::endl;
        std::cin>>x>>y;
    }

    std::cout<<"Goodbye!"<<std::endl;
    return 0;
}

double m_har(double a, double b){
    return 2.0*a*b/(a+b);
}