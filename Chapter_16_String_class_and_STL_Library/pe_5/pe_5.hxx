#ifndef PE_5_HXX
#define PE_5_HXX

static int new_size{0};

constexpr int size_of_array{10};

template <typename T>
void show_array(T x);

template <typename T>
void fill_array(T* array);

template <typename T>
int reduce(T* array, int num_);

template <typename T>
void count_array(T* array, T* new_a_s);

//Definitions

template <typename T>
void show_array(T x)
{
  std::cout << x << " ";
}

template <typename T>
void fill_array(T* array)
{
    for(int it = 0; it < size_of_array; it++)
    {
        std::cin >> *(array + it);
        std::cin.get();
    }
}

template <typename T>
int reduce(T* array, int num_)
{   
    
    std::sort(array, array + num_);
    T* new_array_size = std::unique(array, array + num_);
    
    count_array(array, new_array_size);

    return new_size;

}

template <typename T>
void count_array(T* array, T* new_a_s)
{
    for(auto it = array; it < new_a_s; it++)
    {
        new_size++;
    }

}


#endif // PE_5_HXX