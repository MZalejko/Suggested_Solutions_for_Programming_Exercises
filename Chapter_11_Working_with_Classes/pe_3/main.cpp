#include "pe_3.h"
#include <cstdlib>
#include <ctime>

using namespace VECTOR;
int main(){

    
    srand(time(NULL));

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps{0};
    unsigned long min_steps{0};
    unsigned long max_steps{0};
    unsigned long av_steps{0};
    int num_of_attempts{0};
    std::cout<<"Enter number of attempts: "<<std::endl;
    std::cin>>num_of_attempts;
    double target;
    double dstep;
    std::cout<<"Enter a distance to go (k, to end): ";
    std::cin>>target;
    std::cout<<"Enter length of a step: ";
    std::cin >> dstep;
    for(int i = 0; i < num_of_attempts; i++){
        std::cout<<"Attempt nr "<<(i+1)<<std::endl;
        
        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        if(i == 0 ){
            av_steps = max_steps = min_steps = steps;
        }
        else if(min_steps > steps){
            min_steps = steps;
        }
        else if(max_steps < steps){
            max_steps = steps;
        }

    steps = 0;
    result.reset(0.0, 0.0);
        if(i == (num_of_attempts-1)){
            std::cout<<"Maximal number of steps: "<<max_steps<<std::endl;
            std::cout<<"Minimal number of steps: "<<min_steps<<std::endl;
            std::cout<<"Average number of steps: "<<av_steps/num_of_attempts<<std::endl;
            dstep = target = num_of_attempts = 0;
            std::cout<<"If you want to continue enter new values for length of step, target and number of attempts(Enter k to end the program): ";
            if(!(std::cin>>dstep>>target>>num_of_attempts)){
                break;
            }
        }

    }
    std::cout<<"Goodbye!\n";
    std::cin.clear();
    while(std::cin.get() != '\n'){
        continue;
    }
    return 0;
}

