#include <iostream>
#include <functional>
#include <cstdlib>

long double sum_values() {return 0;};

template<typename T, typename... Args>
long double sum_values(T value, Args... args);

int main()
{

    long double sum;
    sum = sum_values(10, 'A', 22.0, 33.4);
    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}

template<typename T, typename... Args>
long double sum_values(T value, Args... args)
{
    long double temp{0};
    temp += sum_values(args...);
    return temp + value ;
}