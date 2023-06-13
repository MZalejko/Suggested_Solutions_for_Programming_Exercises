#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <cstdlib>

#define NUM 100
#define NUM2 200
#define ARR_SIZE 10

int main()
{
    auto lam_f = [](int n) { std::cout << n << " ";};
    
    int vals[ARR_SIZE] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::list<int> yadayada(vals, vals + ARR_SIZE);
    std::list<int> etcetera(vals, vals + ARR_SIZE);

    std::cout << "Original lists:\n";

    std::for_each(yadayada.begin(), yadayada.end(), lam_f);
    std::cout << std::endl;

    std::for_each(etcetera.begin(), etcetera.end(), lam_f);
    std::cout << std::endl;

    yadayada.remove_if([](int v) {return v > NUM;});
    etcetera.remove_if([](int v) {return v > NUM2;});

    std::cout << "Trimmed lists:\n";

    std::for_each(yadayada.begin(), yadayada.end(), lam_f);
    std::cout << std::endl;

    std::for_each(etcetera.begin(), etcetera.end(), lam_f);
    std::cout << std::endl;




    

    return EXIT_SUCCESS;
}