#include "list.h"

List::List(){
    top = 0;
}
bool List::isempty() const{
    return top == 0;
}
bool List::isfull() const{
    return top == MAX;
}
void List::add(Item new_item){
    if(top < MAX){
        items[top] = new_item;
        top++;
    }
}
void List::visit(void (*pf)(Item &)){
    for(int i = 0; i < top; i++){
        pf(items[i]);
    }
}
void List::show() const{
    if(isempty()){
        std::cout<<"List is empty!\n";
    }
    else{
        for(int i = 0; i < top; i++){
            std::cout<<"Element nr "<<i+1<<" : "<<items[i]<<std::endl;
        }
    }
}