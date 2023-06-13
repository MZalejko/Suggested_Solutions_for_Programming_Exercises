#include "customer.hxx"

const int MIN_PER_HR = 60;

int main()
{
    std::srand(std::time(NULL));

    std::cout << "Case study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maximum size of the queue: ";
    
    int queue_size;
    int simulation_time;
    double average_customers_numb;
    double min_per_custm;
    std::cin >> queue_size;

    std::queue<Customer> bank_queue;

    std::cout <<"Enter time of the simulation: ";
    std::cin >> simulation_time;

    long cycle_limit = MIN_PER_HR * simulation_time;

    std::cout << "Enter the average number of customers per hour: ";
    std::cin >> average_customers_numb;

    min_per_custm = MIN_PER_HR / average_customers_numb;

    Customer temp_customer;     //  new customer data
    long turnaways{0};          //  turned away by full queue
    long customers{0};          //  joined the queue
    long served{0};             //  served during the simulation
    long sum_line{0};           //  cumulative line length
    int wait_time{0};           //  time until autoteller is free
    long line_wait{0};          //  cumulative time in line
    
    // running the simulation   

    for(int cycle = ZERO; cycle < cycle_limit; cycle++)
    {
        if(new_customer(min_per_custm))
        {
            if(!bank_queue.empty() && bank_queue.size() == queue_size)
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp_customer.set_long(cycle);
                bank_queue.push(temp_customer);
            }
        }
        if(wait_time <= ZERO && !bank_queue.empty())
        {   
            temp_customer = bank_queue.front();
            bank_queue.pop();
            wait_time = temp_customer.proc_time();
            line_wait += cycle - temp_customer.when();
            served++;
        }
        if(wait_time > 0)
        {
            wait_time--;

        }
        sum_line += bank_queue.size();
    }

    // reporting results

    if(customers > 0)
    {
        std::cout << "Customers accepted: " << customers << std::endl;
        std::cout << "  Customers served: " << served << std::endl;
        std::cout << "         turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << static_cast<double>(sum_line / cycle_limit);
        std::cout << " Average wait time: "
                  << static_cast<double>(line_wait / served) << " minutes\n";
    }
    else
    {
        std::cout << "No customers\n";
    }

    std::cout << "Done!\n";

    return 0;
}
