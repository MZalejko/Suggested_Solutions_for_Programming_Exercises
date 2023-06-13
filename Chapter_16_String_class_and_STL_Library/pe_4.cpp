#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

static int new_size{0};

void show_array(long x);
void fill_array(long* array);
int reduce(long* array, int num_);
void count_array(long* array, long* new_a_s);

constexpr int size_of_array{10};

int main(void)
{   
    long* temp;
    long* our_array = new long[size_of_array];
    fill_array(our_array);
    int new_s;

    std::cout << "Unsorted and duplicated array: " << std::endl;
    std::for_each(our_array, our_array + size_of_array, show_array);

    std::cout << std::endl;

    new_s = reduce(our_array, size_of_array);

    std::cout << "New array size: " << new_s << std::endl;

    temp = new long[new_s];
    std::copy(our_array, our_array + new_s, temp);

    delete [] our_array;
    our_array = new long[new_s];
    std::copy(temp, temp + new_s, our_array);

    std::cout << "Sorted and unduplicated array: " << std::endl;

    std::for_each(our_array, our_array + new_s, show_array);

    std::cout << std::endl;

    delete [] temp;
    delete [] our_array;
    
    return 0;
}

void show_array(long x)
{
    std::cout << x << " ";
}

void fill_array(long* array)
{
    for(int it = 0; it < size_of_array; it++)
    {
        std::cin >> *(array + it);
        std::cin.get();
    }
}

int reduce(long* array, int num_)
{   
    
    std::sort(array, array + num_);
    long* new_array_size = std::unique(array, array + num_);
    
    count_array(array, new_array_size);

    return new_size;

}

void count_array(long* array, long* new_a_s)
{
    for(auto it = array; it < new_a_s; it++)
    {
        new_size++;
    }

}


