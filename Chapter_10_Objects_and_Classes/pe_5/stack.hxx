#ifndef STACK_HXX
#define STACK_HXX

#include <iostream>
#include <cctype>

#define MAXSIZE 35


struct Customer 
{
    char fullname[MAXSIZE];
    double payment;
};

// Functions
void clear_buffor();
Customer add_customer();
void show_menu();

class Stack
{
    private:    
        enum{MAX = 10};
        Customer num_of_customers[MAX];
        int top;
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        // push() returns false if stack is already full, true otherwise
        bool push(const Customer& cust);
        // pop() returns false if stack is already empty, true otherwise
        bool pop(Customer& cust);

};


#endif // STACK_HXX