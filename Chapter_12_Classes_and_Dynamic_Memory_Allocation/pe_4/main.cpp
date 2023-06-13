#include "pe_4.h"

int main()
{

    Item num_in_stack;
    char choose_value;
    chosse_stack_size(num_in_stack);

    Item value{0};

    Stack first_stack(num_in_stack);

    show_menu();

    operate_on_stck(choose_value, value, first_stack);

    Stack second_stack(first_stack);


    chosse_stack_size(num_in_stack);
    show_menu();
    Stack third_stack(num_in_stack);
    operate_on_stck(choose_value, value, third_stack);
    
    std::cout<<std::endl;
    first_stack.show_stack();
    std::cout<<std::endl;
    second_stack.show_stack();
    std::cout<<std::endl;
    third_stack.show_stack();
    std::cout<<std::endl;
    first_stack = third_stack;
    std::cout<<std::endl;
    first_stack.show_stack();



    return EXIT_SUCCESS;
}