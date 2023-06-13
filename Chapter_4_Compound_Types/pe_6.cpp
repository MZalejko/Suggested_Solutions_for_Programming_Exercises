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
    CandyBar snacks[3]
    {
        {"Snickers", 3.5, 450},
        {"Kinder Bueno", 50.5, 350},
        {"Mocha Munch", 2.3, 350}
    };

    for(int i = 0; i < 3; i++)
    {
        std::cout << "Snack name: " <<snacks[i].name<< '\n'
            << "Weight of snack: " << snacks[i].weight << '\n'
            << "Calories in snack: " << snacks[i].num_of_cals << std::endl;

        if(i<2)
        {
            std::cout << "\n\n";
        }

    }

    return 0;
}