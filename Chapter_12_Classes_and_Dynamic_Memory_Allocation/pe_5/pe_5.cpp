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
    std::vector<std::pair<int,double>> results; // results of the simulation first part: customers_per_hour, second part: average wait time
    std::cout << "Enter a length of a queue: ";
    std::cin >> queue_length;
    std::cin.get();

    
    double min_per_cust;
    Item customer_data; //new customers data
    long turnaways{0};
	long customers{0};     //  joined the queue
	long served{0};        //  served during the simulation
	long sum_line{0};      //  cumulative line length
	int wait_time{0};      //  time until autoteller is free
	long line_wait{0};     //  cumulative time in line
    int cust_per_hour = max_customer_number;

    

    while(cust_per_hour > 0)
    {   
        Queue line(queue_length);
        min_per_cust = MIN_PER_HR/cust_per_hour;
        for(int it = 0; it < cyclelimit; it++)
        {
            
            if(newcustomer(min_per_cust))
            {
                if(line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    customer_data.set(it);
                    line.enqueue(customer_data);
                }
            }
            if(wait_time <= 0 && !line.isempty())
            {
                line.dequeue(customer_data);
                wait_time = customer_data.ptime();
                line_wait += it - customer_data.when();
                served++;
            }
            if(wait_time > 0)
                wait_time--;
        
            sum_line += line.queuecount();
        }
        std::pair<int,double> temp;
        temp.first = cust_per_hour;
        temp.second = (double)line_wait / served;
        results.push_back(temp);
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;
        cust_per_hour--;
        
    }
    std::cout <<"RESULTS"<<std::endl;
    show_results(results);


    return EXIT_SUCCESS;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
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