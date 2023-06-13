#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "pe_5.hxx"



int main(void)
{   
    std::string* temp;
    std::string* our_array = new std::string[size_of_array];
    fill_array(our_array);
    int new_s;

    std::cout << "Unsorted and duplicated array: " << std::endl;
    std::for_each(our_array, our_array + size_of_array, show_array<std::string>);

    std::cout << std::endl;

    new_s = reduce(our_array, size_of_array);

    std::cout << "New array size: " << new_s << std::endl;

    temp = new std::string[new_s];
    std::copy(our_array, our_array + new_s, temp);

    delete [] our_array;
    our_array = new std::string[new_s];
    std::copy(temp, temp + new_s, our_array);

    std::cout << "Sorted and unduplicated array: " << std::endl;

    std::for_each(our_array, our_array + new_s, show_array<std::string>);

    std::cout << std::endl;
    
    return 0;
}


