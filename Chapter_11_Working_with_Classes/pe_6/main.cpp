#include "pe_6.h"

const int MAX{6};

int main(){

    Stonewt arr[MAX] {{12,4}, {3,12}, {4.0}};
    Stonewt test(11,0);
    Stonewt max;
    Stonewt min;
    char chose;
    int res,val_stn{0};
    double val_lbs{0};
    for ( int i = 3; i < MAX; i++ ){
        std::cout<< "Chose how to create a Stone: A- stones and pounds, B- only pounds\n";
        std::cin>>chose;
        if(chose == 'A' || chose == 'a'){
            std::cin>>val_stn>>val_lbs;
            arr[i] = Stonewt{val_stn, val_lbs};
        }
        else if (chose == 'B' || chose == 'b'){
            std::cin>>val_lbs;
            arr[i] = Stonewt{val_lbs};
        }
    }

    max = arr[0];
    min = arr[0];
    for(int i = 0; i < MAX; i++){
        if(min > arr[i]){
            min = arr[i];
        }
        if(max < arr[i]){
            max = arr[i];
        }
    }

    for(int i = 0; i < MAX; i++){
        if(arr[i] >= test){
            res++;
        }

    }

    std::cout<<"The biggest element of the array is: "<<std::endl;
    max.show_stn();
    max.show_lbs();
    std::cout<<"The smallest element of the array is: "<<std::endl;
    min.show_stn();
    min.show_lbs();
    std::cout<<"We have "<< res <<" elements that are bigger than or equal to the test class.\n";

    return 0;
}
