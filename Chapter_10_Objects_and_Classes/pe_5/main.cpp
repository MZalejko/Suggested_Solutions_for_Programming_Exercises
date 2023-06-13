#include "stack.hxx"

int main()
{

    double sum_of_payments{0};
    Stack our_stack;
    char check_value;
    Customer temp_customer;

    show_menu();

    while(std::cin >> check_value && toupper(check_value) != 'Q')
    {
        clear_buffor();
        if(!isalpha(check_value))
        {
            std::cout << '\n';
            continue;
        }
        switch(check_value)
        {
            case 'A':
            case 'a':
                if(our_stack.isfull())
                {
                    std::cout << "Stack already full.\n";
                }
                else
                {
                    temp_customer = add_customer();
                    our_stack.push(temp_customer);
                }
                break;
            case 'P':
            case 'p':
                if(our_stack.isempty())
                {
                    std::cout << "Stack already empty.\n";
                }
                else
                {
                    
                    our_stack.pop(temp_customer);
                    sum_of_payments += temp_customer.payment;
                    std::cout << "Sum of payments: " << sum_of_payments << std::endl;
                    std::cout << "Customer " << temp_customer.fullname << " popped." <<std::endl;
                    
                }
                

        }
        show_menu();
    } 

    std::cout << "Bye!" << std::endl;    

    return EXIT_SUCCESS;
}