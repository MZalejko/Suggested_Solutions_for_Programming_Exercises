#include "wine_inh.hxx"

Wine::Wine(const char* wine, int years, int* allYears, int* bottles) : std::string(wine), ArrayPair(ArrayInt(years), ArrayInt(years)) {
    wine_years = years;
    for(int it = 0; it < years; it++){
        ArrayPair::first[it] = allYears[it];
        ArrayPair::second[it] = bottles[it];
    }
}
Wine::Wine(const char* wine, int years) : std::string(wine){
    wine_years = years;
}      
void Wine::getBottles(){
    ArrayPair::first.resize(wine_years);
    ArrayPair::second.resize(wine_years);
    int year{0};
    int bottles{0};
    if(wine_years == 0){
        std::cout << "Sorry we have no wine here!" << std::endl;
    }
    std::cout <<"Wine " << (const std::string&)(*this) << " has " << wine_years << " years, set the year"
                " and number of the bottles: " << std::endl;

    for(int it = 0; it < wine_years; it++){
        std::cout << "You still have " << wine_years-it << " years to fill out" << std::endl;
        std::cin >> year >> bottles;
        ArrayPair::first[it] = year;
        ArrayPair::second[it] = bottles;
    }
}
void Wine::show() const{ 
    std::cout << "Wine: " << (const std::string& )(*this) << std::endl;
    std::cout << "\t\t" << "Year:" << '\t' << "Bottles: " << std::endl;
    for(int it = 0; it < wine_years; it++){
        std::cout << "\t\t" << ArrayPair::first[it];
        std::cout << '\t' << ArrayPair::second[it] << std::endl;
    }
}