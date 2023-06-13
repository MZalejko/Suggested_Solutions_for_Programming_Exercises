#include <iostream>

using namespace std;

constexpr float lightYear_to_astronomicalUnit{63240};

double astronomic(double n);

int main(void)
{
    double light_years, astronomical_units;

    cout << "Enter the number of light years to convert: ";
    cin >> light_years;
    astronomical_units = astronomic(light_years);
    cout << light_years << " are converted to " << astronomical_units << " astronomical units" << endl;

    return 0;
}

double astronomic(double n)
{
    double x;
    x = n * lightYear_to_astronomicalUnit;
    return x;
}