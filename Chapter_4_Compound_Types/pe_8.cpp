#include <iostream>
#include <string>
#define ENDS_NUM 0

struct Pizza_comp
{
    std::string name;
    double diameter;
    double weight;
};

int main(void)
{
    Pizza_comp *company;
    company = new Pizza_comp;

    std::cout << "Enter informations about your company: 0- ends program" << '\n';
    
    std::cout << "Enter diameter of your Pizzas in cm's: " << std::endl;
    std::cin >> company->diameter;
    std::cin.get();
    
    while(company->diameter != ENDS_NUM){
        std::cout << "Name of the Company: ";
        getline(std::cin,company->name);
        
        std::cout << " at the end - weight of it in grams: ";
        std::cin >> company->weight;
        std::cout << "Company name: " << company->name << '\n'
                << "Diameter of your Pizzas: " << company->diameter << " cm" << '\n'
                << "Weight of your Pizzas: " << company->weight << " g" << std::endl;
        std::cin.get();
        std::cout << "Enter informations about your company: 0- ends program" << '\n';
        std::cin >> company->diameter;
        std::cin.get();
    }
    std::cout << "Thank you and goodbye!\n";
    delete company; 
    return 0;
}