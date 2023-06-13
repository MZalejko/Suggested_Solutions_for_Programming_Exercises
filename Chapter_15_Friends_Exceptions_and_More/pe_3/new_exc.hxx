#ifndef NEW_EXC_HXX
#define NEW_EXC_HCC

#include <iostream>
#include <stdexcept>

#define HMEAN_MULTIPLIER -1

constexpr const char* exception_description{"An exeception occured"};
constexpr const char* bad_hmean_excp{"function HMean"};
constexpr const char* bad_gmean_excp{"function GMean"};

class bad_mean : public std::logic_error
{
    private:
        double first_value;
        double second_value;
    public:
        bad_mean(double first, double second) : first_value(first), second_value(second), std::logic_error(exception_description) {};
        virtual void what() = 0;
        double return_first() {return first_value;};
        double return_second() {return second_value;};        
};

class bad_hmean : public bad_mean 
{
    private:
        const char* exception_name;
    public:
        bad_hmean(double first, double second, const char* descr = bad_hmean_excp) :exception_name(descr),bad_mean(first, second) {};
        virtual void what();
};

class bad_gmean : public bad_mean
{
    private:
        const char* exception_name;
    public:
        bad_gmean(double first, double second, const char* descr = bad_gmean_excp) : exception_name(descr), bad_mean(first, second){}
        virtual void what();

};

void bad_mean::what()
{
    std::cout << std::logic_error::what() << std::endl;
}

void bad_hmean::what()
{
    bad_mean::what();
    std::cout << "Incorrect arguments" << " in " << exception_name << std::endl;
    std::cout << bad_mean::return_first() << " = " << HMEAN_MULTIPLIER * bad_mean::return_second() << std::endl;
}

void bad_gmean::what()
{
    bad_mean::what();
    std::cout << "Incorrect arguments" << " in " << exception_name << std::endl;
    std::cout << bad_mean::return_first() << " and " << bad_mean::return_second() << " should be greater than 0"<< std::endl;
}

#endif //NEW_EXC_HXX