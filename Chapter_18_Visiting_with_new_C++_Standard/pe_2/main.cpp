#include "pe_2.hxx"

int main()
{
    Cpmv first;
    Cpmv second("Maciek", "Agamnon");
    Cpmv third("Ola", "Demina");
    Cpmv fourth(second + third);
    Cpmv fifth("Karol", "Kasia");
    Cpmv sixth;
    first = fifth;
    sixth = second + fifth;

    second.Display();
    third.Display();
    fourth.Display();
    first.Display();
    sixth.Display();



    



    return EXIT_SUCCESS;
}