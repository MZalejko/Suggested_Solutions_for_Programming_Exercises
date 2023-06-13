#include <iostream>

long double propability(unsigned numbers, unsigned picks, unsigned num_of_extra);

int main(void){

    double nums_in_lottery, how_many_picks, how_many_extra;


    std::cout<<"Enter the number of balls in lottery, than number of picks"
            <<"and how many numbers are in extra lottery";
    while((std::cin>>nums_in_lottery>>how_many_picks>>how_many_extra) && how_many_picks <= nums_in_lottery){
        std::cout<<"Chance to win is one to: ";
        std::cout<<propability(nums_in_lottery, how_many_picks, how_many_extra)<<'\n';
        std::cout<<"Another numbers or q to exit: "<<'\n';

    }        
    std::cout<<"Goodbye!\n";

    return 0;
}

long double propability(unsigned numbers, unsigned picks, unsigned num_of_extra){
    double prop{1.0};
    for(numbers, picks; picks > 0; picks--, numbers--){
        prop = prop * numbers/picks;
    }
    return prop /num_of_extra;
}