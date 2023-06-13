#include "wine.hxx"

Wine::Wine(const char* wine, int years, int* allYears, int* bottles) : name_of_wine(wine), wine_years(years){
    years_and_numBottles.first.resize(wine_years);
    years_and_numBottles.second.resize(wine_years);
    for(int it = 0; it < years; it++){
        years_and_numBottles.first[it] = allYears[it];
        years_and_numBottles.second[it] = bottles[it];
    }
}

Wine::Wine(const char* wine, int years) : name_of_wine(wine), wine_years(years){}

void Wine::getBottles(){
    years_and_numBottles.first.resize(wine_years);
    years_and_numBottles.second.resize(wine_years);
    int year{0};
    int bottles{0};
    if(wine_years == 0){
        std::cout << "Sorry we have no wine here!" << std::endl;
    }
    std::cout <<"Wine " << name_of_wine << " has " << wine_years << " years, set the year"
                " and number of the bottles: " << std::endl;

    for(int it = 0; it < wine_years; it++){
        std::cout << "You still have " << wine_years-it << " years to fill out" << std::endl;
        std::cin >> year >> bottles;
        years_and_numBottles.first[it] = year;
        years_and_numBottles.second[it] = bottles;
    }
}
void Wine::show() const{
    std::cout << "Wine: " << name_of_wine << std::endl;
    std::cout << "\t\t" << "Year:" << '\t' << "Bottles: " << std::endl;
    for(int it = 0; it < wine_years; it++){
        std::cout << "\t\t" << years_and_numBottles.first[it];
        std::cout << '\t' << years_and_numBottles.second[it] << std::endl;
    }
}
