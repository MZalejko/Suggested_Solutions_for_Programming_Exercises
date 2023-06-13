#include "emp.hxx"

#define ARRAY_SIZE 4

void makeSpace();

int main()
{
    employee firstEmp("Trip", "Harris", "Thumper");
    makeSpace();
    std:: cout << firstEmp << std::endl;
    firstEmp.showAll();
    makeSpace();

    manager firstMang("Amorphia", "Spindragon", "Nuancer", 5);
    makeSpace();
    std::cout << firstMang << std::endl;
    firstMang.showAll();
    makeSpace();

    fink firstFink("Matt", "Oggs", "Oiler", "Junno Barr");
    makeSpace();
    std::cout << firstFink << std::endl;
    firstFink.showAll();
    makeSpace();

    highFink firstHighFink(firstMang, "Curly Kew");
    makeSpace();
    firstHighFink.showAll();
    makeSpace();

    std::cout << "Press a key for next phase: \n";
    std::cin.get();
    std::cin.get();

    highFink secondHighFink;
    secondHighFink.setAll();
    makeSpace();

    std::cout << "using an abstr_emp * pointer: \n";
    abstr_emp * tri[ARRAY_SIZE] = {&firstEmp, &firstFink, &firstHighFink, &secondHighFink};
    for(int it = 0; it < ARRAY_SIZE; it++)
    {
        tri[it]->showAll();
    }

    return 0;

}

void makeSpace(){
    std::cout << std::endl;
}