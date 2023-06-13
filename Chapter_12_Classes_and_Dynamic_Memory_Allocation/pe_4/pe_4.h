#ifndef PE_4_H
#define PE_4_H
#include <iostream>
#include <cctype>

typedef unsigned long Item;

class Stack{

    private:
        
        enum {MAX = 10};
        Item* pitems;
        int size;
        int top;

    public:

        explicit Stack(int n = MAX);
        Stack(const Stack& stck);
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        bool pop(Item& item);
        bool push(const Item& item);
        Stack& operator=(const Stack& stck);
        void show_stack() const;
};

// Functions

void show_menu();
void chosse_stack_size(Item& stck_v);
void operate_on_stck(char& choose, Item& value_to_add, Stack& stck);

#endif // PE_4_H