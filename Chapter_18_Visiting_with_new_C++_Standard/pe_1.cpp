#include <iostream>
#include <cstdlib>
#include <initializer_list>

template<typename T>
T average_list(std::initializer_list<T> values_list);


int main(int argc, char** argv)
{
    auto q = average_list({15.4, 10.7, 9.0});
    std::cout << q << std::endl;
    
    std::cout << average_list({20, 30, 19, 17, 45, 38}) << std::endl;

    auto ad = average_list<double>({'A', 70, 65.33});
    std::cout << ad << std::endl;

    return EXIT_SUCCESS;
}

template<typename T>
T average_list(std::initializer_list<T> values_list)
{   
    T temp{0};
    for(auto it: values_list)
    {
        temp += it;
    }

    return temp;
}