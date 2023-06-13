#include <cmath>
#include "exc.hxx"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: " << std::endl;

    while(std::cin >> x >> y)
    {
        try
        {
            z = hmean(x,y);
            std::cout << "Harmonic mean of these numbers: " << x << 
                         " and "<< y << " is " << z << std::endl;
            z = gmean(x,y);             
            std::cout << "Geometric mean of these numbers: " << x << 
                         " and " << y << " is " << z << std::endl;
            std::cout << "Enter another pair of numbers <e to exit> :"; 
        }
        catch(bad_hmean& bhm)
        {
            bhm.what();
            std::cout << "Enter another pair of numbers <e to exit> :"; 
            continue;
        }
        catch(bad_gmean& bgm)
        {
            bgm.what();
            std::cout << "I'm sorry, it's over" << std::endl;
            break;
        }
    }

    std::cout << "The End" << std::endl;

    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {
        throw bad_hmean();
    }

    return 2.0 * a * b / (a+b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
    {
        throw bad_gmean();
    }

    return std::sqrt(a*b);
}