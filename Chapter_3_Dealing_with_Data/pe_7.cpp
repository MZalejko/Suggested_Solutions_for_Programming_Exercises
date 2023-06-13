#include <iostream>

const double galon_to_liters{3.875};
const double km100_to_miles{62.14};

int main(void)
{

    double liters_km, fuel_in_galons;
    long int converted_consumption;
    
    std::cout << "Enter the consumption of the gasoline in european style (liters per 100 km): \n";
    
    std::cin >> liters_km;

    fuel_in_galons = liters_km/galon_to_liters;
    converted_consumption = km100_to_miles/fuel_in_galons;

    std::cout << "You have entered: " << liters_km << " liters per 100 km.\n"
                "It is about: "<< converted_consumption <<" miles per galon.\n";


    return 0;
}