#include "pe_3.h"

int main(){
    Golf first{"Maciek Zalejko", 425};
    Golf second;
    first.showgolf();
    second.showgolf();

    second.setgolf();
    second.showgolf();
    second.length_of_fullname();
    first.length_of_fullname();

    return 0;
}