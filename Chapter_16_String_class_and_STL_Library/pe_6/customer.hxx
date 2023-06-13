#ifndef CUSTOMER_HXX
#define CUSTOMER_HXX

#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>

#define ZERO 0

bool new_customer(double x);

class Customer
{
    private:
        long arrive;
        int processtime;
    public:
        Customer (int arrtime = 0, int procstime = 0) : arrive(arrtime), processtime(procstime) {};
        void set_long(long when_time);
        long when() const { return arrive; };
        int proc_time() const { return processtime;};

};

void Customer::set_long(long when_time)
{
    processtime = std::rand() % 3 + 1;
    arrive  = when_time;
}   

// new_customer function

bool new_customer(double x)
{
    return (std::rand() * x/ RAND_MAX < 1);
}



#endif //CUSTOMER_HXX