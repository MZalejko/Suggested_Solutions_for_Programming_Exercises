#include <iostream>

const int size{45};
constexpr int size_of_array{3};

struct CandyBar{

    char name[size];
    double weight;
    int num_of_cals;
};

int main(void)
{
    CandyBar *snacks = new CandyBar[size_of_array];
    snacks[0] = {"Snickers", 3.5, 450};
    snacks[1] = {"Wafelek Grzes", 50.5, 350};
    snacks[2] = {"Batonik Jezyk", 43.25, 400};
      

    for(int i = 0; i < size_of_array; i++)
    {
        std::cout << "Snack name: " << snacks[i].name << '\n'
            << "Weight of snack: " << snacks[i].weight << '\n'
            << "Calories in snack: " <<snacks[i].num_of_cals << std::endl;
        if(i<2)
        {
            std::cout<<"\n\n";
        }

    }

    delete [] snacks;

    return 0;
}