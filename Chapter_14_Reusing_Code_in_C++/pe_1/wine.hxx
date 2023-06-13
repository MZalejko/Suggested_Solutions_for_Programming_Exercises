#ifndef WINE_HXX
#define WINE_HXX

#include <string>
#include <cstring>
#include <iostream>
#include <valarray>

using ArrayInt = std::valarray<int>;
using ArrayPair = std::pair<ArrayInt, ArrayInt>;

class Wine{
    private:
        std::string name_of_wine;
        ArrayPair years_and_numBottles;
        int wine_years{0};
    public:
        Wine(){};
        Wine(const char* wine, int years, int* allYears, int* bottles);
        Wine(const char* wine, int years);
        ~Wine(){};        
        void getBottles();
        int sumBottles() const {return years_and_numBottles.second.sum();};
        const std::string& get_nameWine(){return name_of_wine;};
        void show() const;
};





#endif //WINE_HXX
