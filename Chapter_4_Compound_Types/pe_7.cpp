#include <iostream>
#include <string>

struct Pizza_comp
{
    std::string name;
    double diameter;
    double weight;
};

int main(void)
{
    Pizza_comp company;
    std::cout << "Enter informations about your company: #- ends program" << '\n';
    std::cout << "Name of the Company: ";
    getline(std::cin,company.name);
    while(company.name[0] != '#'){
        std::cout << "Enter diameter of your Pizzas and weight of it: ";
        std::cin >> company.diameter >> company.weight;
        std::cout << "Company name: " << company.name << '\n'
                << "Diameter of your Pizzas: " << company.diameter << " cm" << '\n'
                << "Weight of your Pizzas: " << company.weight <<" g" << std::endl;
        std::cin.get();
        std::cout << "Enter informations about your company: #- ends program"<<'\n';
        getline(std::cin, company.name);
    }
    std::cout << "Thank you and goodbye!";
    return 0;
}