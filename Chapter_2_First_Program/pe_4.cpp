#include <iostream>

using namespace std;

constexpr int year_to_motnhs{12};

int main(void){

    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age in months is: "<< age * year_to_motnhs << endl;

    return 0;
}