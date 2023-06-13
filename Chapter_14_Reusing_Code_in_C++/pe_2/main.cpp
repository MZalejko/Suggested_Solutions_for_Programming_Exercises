#include "wine_inh.hxx"

#define SIZE 50
#define YRS 3

int main(){

    char wine_label[SIZE];
    int years{0};

    std::cout << "Set a name of the wine: ";
    std::cin.getline(wine_label, SIZE);
    std::cout << "And number of the years: ";
    std::cin >> years;

    Wine first_kind_of_wine(wine_label, years);

    first_kind_of_wine.getBottles();
    first_kind_of_wine.show();

    int get_years[YRS]{1993, 1995, 1998};
    int get_bottles[YRS]{48, 60, 72};

    Wine second_kind_of_wine("Gushing Grape Red", YRS, get_years, get_bottles);

    second_kind_of_wine.show();

    std::cout << "Total number of the bottles of the wine: " << second_kind_of_wine.get_nameWine()
              << " : " << second_kind_of_wine.sumBottles() << std::endl;

    return 0;
}