#include <iostream>

int main(void){

    long long world_population, country_population;

    double percentage;

    std::cout << "Enter wolrd's popoulation and selected country population: \n";

    std::cin >> world_population >> country_population;

    percentage = (country_population*100)/double(world_population);

    std::cout << "The population of the entered country constitue " << percentage << " \% of the world's population.";

    return 0;
}