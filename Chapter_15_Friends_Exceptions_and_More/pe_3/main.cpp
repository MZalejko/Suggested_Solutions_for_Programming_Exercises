#include <cmath>
#include "new_exc.hxx"

double hmean(double a, double b);
double gmean(double a, double b);

bad_mean* exc;

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
        catch(bad_mean* exc)
        {
            if(typeid(exc) == typeid(bad_hmean*))
            {
                exc->what();
                std::cout << "I'm sorry, it's over" << std::endl;
                break;
            }
            else
            {
                exc->what();
                std::cout << "I'm sorry, it's over" << std::endl;
                break;
            }
        }
    }

    std::cout << "The End" << std::endl;

    delete exc;

    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {   
        exc = new bad_hmean(a,b);
        throw exc;
    }
    return 2.0 * a * b / (a+b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
    {
        exc = new bad_gmean(a,b);
        throw exc;
    }

    return std::sqrt(a*b);
}