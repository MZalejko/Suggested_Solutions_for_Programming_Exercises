#include <iostream>

const int size{45};

struct CandyBar
{
    char name[size];
    double weight;
    int num_of_cals;
};

int main(void)
{

    CandyBar snack{"Mocha Munch", 2.3, 350};

    std::cout<<"Snack name: "<<snack.name<<'\n'
            <<"Weight of snack: "<<snack.weight<<'\n'
            <<"Calories in snack: "<<snack.num_of_cals<<std::endl;

    return 0;
}