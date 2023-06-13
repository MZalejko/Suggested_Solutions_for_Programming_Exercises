#include "pe_7.h"



int main(){

    Plorg first;
    Plorg second("Betegel Plorg", 80);
    Plorg third("Betegel Plorg of Sun and Moon", 85);

    first.say_my_name();
    second.say_my_name();
    third.say_my_name();

    first.change_satiety(120);
    second.change_satiety(100);

    first.say_my_name();
    second.say_my_name();

    return 0;
}