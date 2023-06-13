#include "pe_2.h"

int main(){

    Person first;
    Person second("Johann");
    Person third("Zalejko", "Maciek");

    first.Show();
    second.Show();
    third.Show();

    first.FormalShow();
    second.FormalShow();
    third.FormalShow();

}