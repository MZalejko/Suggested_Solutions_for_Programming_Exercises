#include "list.h"

void add_two(Item& a){a += 2;};

int main(){

    List first_list;
    Item temp;
    std::cout<<"Enter a number or q to quit\n";
    while(std::cin>>temp){
        first_list.add(temp);
        std::cout<<"Enter another number or q to quit"<<std::endl;
    }

    first_list.show();
    first_list.visit(add_two);
    first_list.show();


    return 0;
}