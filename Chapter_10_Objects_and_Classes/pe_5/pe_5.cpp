#include "stack.hxx"

Stack::Stack()
{
    top = 0;
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == MAX;
}
bool Stack::push(const Customer& cust)
{
    if(top < MAX)
    {
        num_of_customers[top++] = cust;
        return true;
    }
    else
    {
        return false;
    }
}
bool Stack::pop(Customer& cust)
{
    if(top > 0)
    {
        cust = num_of_customers[--top];
        return true;
    }
    else
    {
        return false;
    }
}

// Functions

void clear_buffor()
{
    while(std::cin.get() != '\n')
    {
        continue;
    }
}

Customer add_customer()
{
    Customer customer_add;
    std::cout << "Enter a name of customer: ";
    std::cin.getline(customer_add.fullname, MAXSIZE);
    std::cout << "Enter a payment of the customer: ";
    std::cin >> customer_add.payment;
    clear_buffor();
    return customer_add;
}

void show_menu()
{
    std::cout << "Please enter A to add a customer.\n"
            << "P to process a Customer, or Q to quit.\n";
}