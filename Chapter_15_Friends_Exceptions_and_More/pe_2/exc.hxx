#ifndef EXC_HXX
#define EXC_HCC

#include <iostream>
#include <stdexcept>

constexpr const char* exception_description{"Exeception"};
constexpr const char* bad_hmean_excp{"Function HMean"};
constexpr const char* bad_gmean_excp{"Function GMean"};

class bad_hmean : public std::logic_error {
    public:
        bad_hmean() : std::logic_error(bad_hmean_excp){}
        virtual void what();
};

class bad_gmean : public std::logic_error {

    public:
        bad_gmean() : std::logic_error(bad_gmean_excp){}
        virtual void what();

};

void bad_hmean::what()
{
    std::cout << exception_description << " in " << std::logic_error::what() << std::endl;
    std::cout << "Incorrect arguments" << std::endl;
}

void bad_gmean::what()
{
    std::cout << exception_description << " in " << std::logic_error::what() << std::endl;
    std::cout << "Incorrect arguments" << std::endl;
}

#endif //EXC_HXX