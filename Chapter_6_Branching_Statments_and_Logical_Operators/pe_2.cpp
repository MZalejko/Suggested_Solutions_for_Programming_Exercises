#include <iostream>

constexpr int size{10};
constexpr int decrease_or_increase{1};

double fill_array(double* array);
double count_sum(const double* array, const double& arr_size);
double count_average(const double& sum, const double& arr_size);
void show_greater_average(const double* array, int& g_average, const double& arr_size, const double& average);

int main()
{

    double donates[size];

    double sum{0};
    double average{0};
    int greater_than_avarge{0};
    int num_of_donates{0};

    std::cout << "Enter up to 10 donation values! Non numeric value quit.\n";

    num_of_donates = fill_array(donates);
    sum = count_sum(donates, num_of_donates);
    average = count_average(sum, num_of_donates);
    show_greater_average(donates, greater_than_avarge, num_of_donates, average);


    return 0;
}

double fill_array(double* array)
{
    short it{0};
    int value{0};
    while(it < size && (std::cin >> value))
    {   
        *(array + it) = value;
        std::cout << "Donate nr " << it + decrease_or_increase << ": ";
        std::cout << value << std::endl;
        it++;
    }
    return it;
}

double count_sum(const double* array, const double& arr_size)
{
    double temp_sum{0};
    for(int it = 0; it < arr_size; it++)
    {
        temp_sum += *(array + it);
    }
    std::cout << "Sum of the donates: " << temp_sum << std::endl;
    return temp_sum;
}

double count_average(const double& sum, const double& arr_size)
{
    double temp_average = sum/arr_size;
    std::cout << "Average: " << temp_average << std::endl;
    return temp_average;
}

void show_greater_average(const double* array, int& g_average, const double& arr_size, const double& average)
{
    for(int it = 0; it < arr_size; it++)
    {
        if(*(array + it) > average)
        {
            std::cout << "Value nr " << it + decrease_or_increase << " greater than average: " << *(array + it) << std::endl;
            g_average++;
        }
    }

    std::cout << "We have " << g_average<< " donations greater than avarge" << std::endl;
}