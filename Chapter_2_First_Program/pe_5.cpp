#include <iostream>
#define MULTIPLIER 1.8
#define ADDITION 32

using namespace std;

double celsius_to_fahrenheit(double n);

int main(void)
{

    double cels, fahrenheits;

    cout << "Enter the temperature in Celsius degrees: ";
    cin >> cels;
    fahrenheits = celsius_to_fahrenheit(cels);
    cout << cels << " Celsius degrees are "<< fahrenheits << " in Fahrenheits" << endl;

    return 0;
}

double celsius_to_fahrenheit(double n)
{
    double temp;

    temp = MULTIPLIER * n + ADDITION;

    return temp;
}