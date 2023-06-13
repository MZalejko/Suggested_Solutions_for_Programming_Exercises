#include <iostream>

const int feet_to_inch{12};

const double inch_to_meter{0.0254};

const double pounds_to_kg{2.2};


int main(void)
{

    double height_feets, height_inches, weight, bmi;

    std::cout<<"Enter your height in feets and inches." << std::endl;
    std::cout << "Feets:" << std::endl;

    std::cin >> height_feets;
    
    std::cout << "Inches: " << std::endl;
    std::cin >> height_inches;

    std::cout << "Please enter now your weight in pounds: " << std::endl;
    std::cin >> weight;

    height_inches += height_feets * feet_to_inch;
    
    bmi = (weight/pounds_to_kg) / ((height_inches * inch_to_meter) * (height_inches * inch_to_meter));
   

    std::cout<<"Your BMI is: "<<bmi<<std::endl;

    return 0;
}