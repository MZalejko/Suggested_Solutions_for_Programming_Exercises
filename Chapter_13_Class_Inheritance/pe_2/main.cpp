#include "pe_2.h"

void Bravo(const Cd& disk);

int main(){

    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Sonata fortepianowa B-dur,Fantazja C-moll", 
                            "Alfred Brendel","Philips", 2, 57.17);
    Cd *pcd = &c1;

    std::cout << "Direct use of the object:\n";
    c1.Report();
    c2.Report();


    std::cout << "Use of pointer on type Cd:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    std::cout << "Call of function  with type Cd reference:\n";
    Bravo(c1);
    Bravo(c2);

    std::cout << "Test  of assignment operator:\n";
    Classic copy;
    copy = c2;
    copy.Report();


    return 0;
}

void Bravo(const Cd& disk){
    disk.Report();
}