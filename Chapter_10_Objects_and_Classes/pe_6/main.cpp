#include "pe_6.h"

int main(){

    Move first;
    Move second(12,24);
    Move third(42,56);
    first.showmove();
    first = second.add(third);

    second.showmove();
    third.showmove();
    first.showmove();

    third.reset();
    second.reset(1,1);

    third.showmove();
    second.showmove();



    return 0;
}