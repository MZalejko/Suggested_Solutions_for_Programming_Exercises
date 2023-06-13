#include <iostream>

static int sum;

int enter_num();

int main(void)
{
    int num;

    num = enter_num();

    while(num != 0)
    {
        sum += num;
        std::cout << "Sum of entered numbers: " << sum << '\n';
        num = enter_num();
    }
    std::cout << "Goodbye!\n";

    return 0;
}

int enter_num()
{
    int n;
    std::cout << "Enter a number: \n";
    std::cin >> n;
    return n;
}