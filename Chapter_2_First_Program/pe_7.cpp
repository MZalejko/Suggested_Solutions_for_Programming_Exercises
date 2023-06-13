#include <iostream>

using namespace std;

void time_show(int a, int b);

int main(void)
{
    int minutes,seconds;

    cout << "Enter number of minutes and seconds: " << endl;
    cin >> minutes >> seconds;
    time_show(minutes, seconds);

    return 0;
}

void time_show(int a, int b)
{

    cout << "TIME: " << a << ":" << b << endl;
}