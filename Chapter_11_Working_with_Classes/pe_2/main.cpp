#include "pe_2.h"
#include <cstdlib>
#include <ctime>

using namespace VECTOR;
int main(){

    
    srand(time(NULL));

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps{0};
    double target;
    double dstep;
    std::cout<<"Enter a distance to go (k, to end): ";
    while(std::cin>>target){
        
        std::cout<<"Enter length of a step: ";
        
        if(!(std::cin >> dstep)){
            break;
        }

        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        std::cout<<"After "<<steps<<" steps culprit "
                 <<"had reached position: \n";
        std::cout<<result<<std::endl;
        result.polar_mode();
        std::cout<<" that is \n"<<result<<std::endl;
        std::cout<<"The average apparent step length = "
                  <<result.magval()/steps<<std::endl;

    steps = 0;
    result.reset(0.0, 0.0);
    std::cout<<"Enter new distance to go (k, to end): ";

    }
    std::cout<<"Goodbye!\n";
    std::cin.clear();
    while(std::cin.get() != '\n'){
        continue;
    }
    return 0;
}
