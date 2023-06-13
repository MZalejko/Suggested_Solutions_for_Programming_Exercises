#include <iostream>

const float tax_1{0.0};
const float tax_2{0.1};
const float tax_3{0.15};
const float tax_4{0.2};

const float incomes_1{5000.0};
const float incomes_2{10000.0};
const float incomes_3{20000.0};

int main(){ 

    float incomes{0};
    float taxes{0};
    std::cout << "Enter your months incomes in Twarps: \n";
    while(std::cin >> incomes && incomes > 0){
        if(incomes <= incomes_1){
            taxes = incomes * tax_1;
            std::cout << "You have to pay " << taxes << " Twarpes for your taxes!" << std::endl;
        }
        else if(incomes > incomes_1 && incomes <= incomes_2){
            taxes = (incomes-incomes_1)*tax_2;
            std::cout << "You have to pay " << taxes << " Twarpes for your taxes!" << std::endl;
        }
        else if(incomes > incomes_2 && incomes <= incomes_3){
            taxes = (incomes - (incomes_2 + incomes_1))*tax_3 + (incomes_2 * tax_2) + (incomes_1 * tax_1);
            std::cout << "You have to pay " << taxes << " Twarpes for your taxes!" << std::endl;
        }
        else if(incomes > incomes_3){
            taxes = (incomes -(incomes_3 + incomes_2 + incomes_1)) * tax_4 + (incomes_3 * tax_3) + (incomes_2 * tax_2) + (incomes_1 * tax_1);
            std::cout << "You have to pay " << taxes << " Twarpes for your taxes!" << std::endl;
        }
       std::cout << "Would you like to calculate your taxes again ?" << std::endl; 
    }

    std::cout << "Goodbye!!" << std::endl;

    return 0;
}