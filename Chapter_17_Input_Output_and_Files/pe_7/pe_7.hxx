#ifndef PE_7_HXX
#define PE_7_HXX

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

constexpr const char* file_name{"strings.dat"};

class Store
{
    private:
        std::ofstream* ofstrm;
    public:
        Store(std::ofstream& ofstr) : ofstrm(&ofstr) {};
        ~Store(){};
        Store& operator()(const std::string& str);
};

//Functions

void ShowStr(const std::string& str);
void GetStrs(std::ifstream& fin, std::vector<std::string>& vect_str);

#endif // PE_7_HXX