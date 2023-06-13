#include "pe_1.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace VECTOR;
int main(){

    
    srand(time(NULL));

    std::ofstream out_file;
    out_file.open("output_file.txt");

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
        out_file << "Distance to go: "<<target
                 << " length of the step: "<<dstep<<std::endl;
        while(result.magval() < target){
            out_file<<steps<<": (x, y) = ("<<result.xval()<<", "<<result.yval()<<")"<<std::endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        out_file<<"After "<<(steps-1)<<" steps culprit "
                 <<"has reached position: \n";
        out_file<<result<<std::endl;
        result.polar_mode();
        out_file<<" that is \n"<<result<<std::endl;
        out_file<<"The average apparent step length = "
                  <<result.magval()/steps<<std::endl;

    steps = 0;
    result.reset(0.0, 0.0);
    std::cout<<"Enter new distance to go (k, to end): ";

    }
    out_file.close();
    std::cout<<"Goodbye!\n";
    std::cin.clear();
    while(std::cin.get() != '\n'){
        continue;
    }
    return 0;
}