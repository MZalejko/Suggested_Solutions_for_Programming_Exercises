#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef double Item;

class List{

    private:
        enum {MAX = 10};
        Item items[MAX]{};
        int top;
    public:
        List();
        bool isempty() const;
        bool isfull() const;
        void add(Item new_item);
        void visit(void (*pf)(Item &));
        void show() const;

};





#endif //LIST_H