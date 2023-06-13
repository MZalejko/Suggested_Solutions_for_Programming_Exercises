#include <iostream>
#include <array>

const int num_of_runs{3};

int main(void){

    std::array <double, num_of_runs> resaults_of_runs;

    std::cout<<"Enter resaults of 3 runs on 100 meters: "<<std::endl;

    for(int i = 0; i < num_of_runs; i++){
        std::cin>>resaults_of_runs[i];
    }
    for(int i = 0; i < num_of_runs; i++){
        std::cout<<"Resault of run number "<<i+1<<' '<<resaults_of_runs[i]<<'\n';
    }

    std::cout<<"Goodbye!"<<'\n';

}