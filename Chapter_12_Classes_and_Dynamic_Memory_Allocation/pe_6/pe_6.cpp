#include "queue.hxx"

const int MIN_PER_HR{60};
const int hours{100};
const int max_customer_number{60};

bool newcustomer(double x); // is there a new customer?
void show_results(const std::vector<std::pair<int,double>>& res);

int main()
{

    std::srand(std::time(NULL));
    long cyclelimit = MIN_PER_HR * hours;
    int queue_length;
    std::vector<std::pair<int,double>> results_one; // results of the simulation nr 1 first part: customers_per_hour, second part: average wait time
    std::cout << "Enter a length of a queue: ";
    std::cin >> queue_length;
    std::cin.get();

    
    double min_per_cust;
    Item customer_data; //new customers data
    long turnaways_first{0};
	long customers_first{0};     //  joined the first queue
	long served_first{0};        //  served during the simulation
	long sum_line_first{0};      //  cumulative first line length
	int wait_time_first{0};      //  time until autoteller one is free
	long line_wait_first{0};     //  cumulative time in first line
    long turnaways_second{0};
	long customers_second{0};     //  joined the second queue 
	long served_second{0};        //  served during the simulation
	long sum_line_second{0};      //  cumulative second line length
	int wait_time_second{0};      //  time until autoteller two is free
	long line_wait_second{0};     //  cumulative time in second line
    int cust_per_hour = max_customer_number;

    

    while(cust_per_hour > 0)
    {   
        Queue line1(queue_length);
        Queue line2(queue_length);
        min_per_cust = MIN_PER_HR/cust_per_hour;
        for(int it = 0; it < cyclelimit; it++)
        {
            
            if(newcustomer(min_per_cust))
            {
                if(line2.queuecount() >= line1.queuecount())
                {
                    if(line1.isfull())
                    {
                        turnaways_first++;
                    }
                    else
                    {
                        customers_first++;
                        customer_data.set(it);
                        line1.enqueue(customer_data);
                    }
                }
                else
                {
                    
                    if(line2.isfull())
                    {
                        turnaways_second++;
                    }
                    else
                    {
                        customers_second++;
                        customer_data.set(it);
                        line2.enqueue(customer_data);
                    }
                        
                }
            }
            if(wait_time_first == 0 && !line1.isempty())
            {
                    line1.dequeue(customer_data);
                    wait_time_first = customer_data.ptime();
                    line_wait_first += (it - customer_data.when());
                    served_first++;
            }
            if(wait_time_second == 0 && !line2.isempty())
            {
                    line2.dequeue(customer_data);
                    wait_time_second = customer_data.ptime();
                    line_wait_second += (it - customer_data.when());
                    served_second++;
            }

            if(wait_time_first > 0)
            {
                wait_time_first--;
            }
            if(wait_time_second > 0)
            {
                wait_time_second--;
            }
        
            sum_line_first += line1.queuecount();
            sum_line_second += line2.queuecount();
        }
        std::pair<int,double> temp_one;
        temp_one.first = cust_per_hour;
        temp_one.second = (double)(line_wait_first + line_wait_second) / (served_first + served_second);
        results_one.push_back(temp_one);
        turnaways_first = 0;
        customers_first = 0;
        served_first = 0;
        sum_line_first = 0;
        wait_time_first = 0;
        line_wait_first = 0;

        turnaways_second = 0;
        customers_second = 0;
        served_second = 0;
        sum_line_second = 0;
        wait_time_second = 0;
        line_wait_second = 0;
        
        cust_per_hour--;
        
    }
    std::cout <<"RESULTS ONE"<<std::endl;
    show_results(results_one);

    return EXIT_SUCCESS;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}

void show_results(const std::vector<std::pair<int,double>>& res)
{
    
    for(int it = 0; it < res.size(); it++)
    {
        std::cout << "Customers per hour: " << res[it].first << std::endl;
        std::cout << "Average wait time: " << res[it].second << std::endl;

    }
}