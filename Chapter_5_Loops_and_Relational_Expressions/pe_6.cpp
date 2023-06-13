#include <iostream>
#include <string>

const int size{12};
const int years{3};
const std::string months[size]{"January", "February", "March", "April", "May", 
                    "June", "Juli", "August", "September",
                    "Oktober", "November", "December"};

int main(void)
{

    int values_of_years[years][size];
    int sum_years[years]{0, 0, 0};
    int sum_all{0};
    

    for(int i = 0; i < years; i++)
    {
        std::cout << i+1 << " year of our work:\n";
        for(int j = 0; j < size; j++)
        {
            std::cout << "Enter the number of saled books in " << months[j] <<": ";
            std::cin >> *(*(values_of_years + i) + j);
            *(sum_years + i) += *(*(values_of_years + i) + j);
        }
    }
    for(int i = 0; i < years; i++)
    {
        std::cout << "Sum of solded books in " << i+1 << " year: " << sum_years[i] << '\n';
        sum_all += *(sum_years + i);
    }
    std::cout << "\nTotal sale: " << sum_all << std::endl;

    return 0;
}