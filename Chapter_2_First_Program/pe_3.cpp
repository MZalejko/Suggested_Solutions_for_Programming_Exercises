#include <iostream>

using namespace std;

void first(void);
void second(void);

int main(void){

    first();
    first();
    second();
    second();


    return 0;
}

void first(void)
{
    cout << "Three blind mice\n";
}
void second(void)
{
    cout << "See how they run" << endl;
}