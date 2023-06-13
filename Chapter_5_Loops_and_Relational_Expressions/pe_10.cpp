#include <iostream>

void show_tree(int numOfRows);

int main()
{

    int num;
    std::cout << "Number of rows: ";
    std::cin >> num;

    show_tree(num);

    return 0;
}

void show_tree(int numOfRows)
{
    for(int i = 0; i < numOfRows; i++)
    {
        for(int j = i; j < numOfRows-1; j++)
        {
            std::cout << '.';
        }
        for(int n = i; n >= 0; n--)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
