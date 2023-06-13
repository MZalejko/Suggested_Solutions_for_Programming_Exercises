#include "pe_4.h"

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;
}
Stack::Stack(const Stack& stck)
{
    size = stck.size;
    pitems = new Item[size];
    for(int it = 0; it < size; it++)
    {
        pitems[it] = stck.pitems[it];
    }
    top = stck.top;
}
Stack::~Stack()
{
    delete [] pitems;
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == size;
}
bool Stack::pop(Item& item)
{
    if(top == 0)
    {
        return false;
    }
    else
    {
        item = pitems[--top];
        return true;
    }
}
bool Stack::push(const Item& item)
{
    if(top == size)
    {
        return false;
    }
    else
    {
        pitems[top++] = item;
        return true;
    }
}
Stack& Stack::operator=(const Stack& stck)
{
    if(this == &stck)
    {
        return *this;
    }
    size = stck.size;
    top = stck.top;
    delete [] pitems;
    pitems = new Item[size];
    for(int it = 0; it < size; it++)
    {
        pitems[it] = stck.pitems[it];
    }

    return *this;
}

void Stack::show_stack() const
{
    for(int it = 0; it < top; it++)
    {
        std::cout << "Value #" << it+1 << ": " << pitems[it] << std::endl;
    }
}

//Functions

void show_menu()
{
    std::cout << "Enter A to add item to Stack, R to remove Item from Stack."
              << "Q to quit.\n";
}

void chosse_stack_size(Item& stck_v)
{
    std::cout << "How big should be your stack: ";
    std::cin >> stck_v;
    std::cin.get();
    std::cout << "Your stack will have " << stck_v << " items.\n";
}

void operate_on_stck(char& choose, Item& value_to_add , Stack& stck)
{
    while(std::cin >> choose && toupper(choose) != 'Q')
    {
        std::cin.get();
        switch(choose)
        {
            case 'A':
            case 'a':
                if(stck.isfull())
                {
                    std::cout << "Stack already full.\n";
                }
                else
                {
                    std::cout << "Value: ";
                    std::cin >> value_to_add;
                    std::cin.get();
                    stck.push(value_to_add);   
                }
                break;
            case 'R':
            case 'r':
                if(stck.isempty())
                {
                    std::cout << "Stack already empty.\n";
                }
                else
                {
                    stck.pop(value_to_add);
                    std::cout << "Value popped." << std::endl;
                }
                break;

        }
        show_menu();
    }
}