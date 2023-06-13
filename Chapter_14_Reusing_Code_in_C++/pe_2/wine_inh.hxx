#ifndef WINE_INH_HXX
#define WINE_INH_HXX

#include <iostream>
#include <valarray>
#include <string>
#include <cstring>

using ArrayInt = std::valarray<int>;
using ArrayPair = std::pair<ArrayInt, ArrayInt>;

class Wine : private std::string, private ArrayInt, private ArrayPair{
    private:
        int wine_years{0};
    public:
        Wine(){};
        Wine(const char* wine, int years, int* allYears, int* bottles);
        Wine(const char* wine, int years);
        ~Wine(){};        
        void getBottles();
        int sumBottles() const {return ArrayPair::second.sum();};
        const std::string& get_nameWine(){return (const std::string&)(*this);};
        void show() const;
};






#endif// WINE_INH_HXX