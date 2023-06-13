#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>

constexpr int max_size1{1000000};
constexpr int max_size2{10000000};
constexpr int max_size3{50000000};
constexpr int measurements{3};
constexpr int biggest_num{10000};
constexpr int str_width{16};
constexpr int float_width{10};

void fill_vector(std::vector<int>& vector_to_fill, const int& size);
double stopwatch(std::vector<int>& vector);
double stopwatch(std::list<int>& list);
void set_list(std::list<int>& list, const std::vector<int>& vector);
double copy_list_to_vect(std::list<int>& list, std::vector<int>& vector);
void clear_all(std::list<int>& list, std::vector<int>& vector, std::vector<int>& vector2);
void show(const std::vector<double>& vector, const std::vector<double>& vector2, const std::vector<double>& vector3);
void resizing(const int size, std::vector<int>& vector, std::list<int>& list);


int main(int argc, char** argv)
{   
    std::vector<double> vect_results;
    std::vector<double> list_results;
    std::vector<double> cp_li_to_vc;

    std::vector<int> vi0;
    std::vector<int> vi;
    std::list<int> li;

    std::srand(time(NULL));

    //first attempt - array size 1000000
    std::cout << "First attempt" << std::endl;
    fill_vector(vi0, max_size1);
    std::cout << "Copy...." << std::endl;

    resizing(max_size1, vi, li);
    std::copy(vi0.begin(), vi0.end(), vi.begin());
    std::copy(vi0.begin(), vi0.end(), li.begin());
    
    std::cout << "Stopwatching!" << std::endl;
    vect_results.push_back(stopwatch(vi));
    list_results.push_back(stopwatch(li));
    std::cout << "Seting the list" << std::endl;
    set_list(li, vi0);
    cp_li_to_vc.push_back(copy_list_to_vect(li, vi));
    clear_all(li, vi, vi0);

    //second attempt - array size 10000000
    std::cout << "Second attempt" << std::endl;
    fill_vector(vi0, max_size2);
    resizing(max_size2, vi, li);
    std::copy(vi0.begin(), vi0.end(), vi.begin());
    std::copy(vi0.begin(), vi0.end(), li.begin());

    vect_results.push_back(stopwatch(vi));
    list_results.push_back(stopwatch(li));
    set_list(li, vi0);
    cp_li_to_vc.push_back(copy_list_to_vect(li, vi));
    clear_all(li, vi, vi0);

    //third attempt - array size 50000000
    std::cout << "Third attempt" << std::endl;
    fill_vector(vi0, max_size3);
    
    resizing(max_size3, vi, li);
    std::copy(vi0.begin(), vi0.end(), vi.begin());
    std::copy(vi0.begin(), vi0.end(), li.begin());

    vect_results.push_back(stopwatch(vi));
    list_results.push_back(stopwatch(li));
    set_list(li, vi0);
    cp_li_to_vc.push_back(copy_list_to_vect(li, vi));
    clear_all(li, vi, vi0);

    show(vect_results, list_results, cp_li_to_vc);


    return EXIT_SUCCESS;
}

void fill_vector(std::vector<int>& vector_to_fill, const int& size)
{
    for(int it = 0; it < size; it++)
    {
        vector_to_fill.push_back(std::rand() % biggest_num);
    }
}

double stopwatch(std::vector<int>& vector)
{
    clock_t start = clock();
    std::sort(vector.begin(), vector.end());
    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}
double stopwatch(std::list<int>& list)
{
    clock_t start = clock();
    list.sort();
    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

void set_list(std::list<int>& list, const std::vector<int>& vector)
{
    list.clear();
    std::copy(vector.begin(), vector.end(), list.begin());
}

double copy_list_to_vect(std::list<int>& list, std::vector<int>& vector)
{
    clock_t start = clock();
    std::copy(list.begin(), list.end(), vector.begin());
    std::sort(vector.begin(), vector.end());
    std::copy(vector.begin(), vector.end(), list.begin());
    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}
void clear_all(std::list<int>& list, std::vector<int>& vector, std::vector<int>& vector2)
{
    list.clear();
    vector.clear();
    vector2.clear();
}

void show(const std::vector<double>& vector, const std::vector<double>& vector2, const std::vector<double>& vector3)
{   
    std::vector<double>::const_iterator vect_it = vector.begin();
    std::vector<double>::const_iterator vect2_it = vector2.begin();
    std::vector<double>::const_iterator vect3_it = vector3.begin();

    std::cout.setf(std::ios_base::right, std::ios::adjustfield);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    for(int it = 0; it < measurements; it++)
    {
        if(it == 0)
            std::cout << "Values for array size: " << max_size1 << std::endl;
        else if(it == 1)
            std::cout << "Values for array size: " << max_size2 << std::endl;
        else
            std::cout << "Values for array size: " << max_size3 << std::endl;  
        
        std::cout.precision(3);
        
        std::cout.width(str_width);
        std::cout << "Vector sort: ";
        std::cout.width(float_width);
        std::cout << *vect_it << std::endl;
        std::cout.width(str_width);
        std::cout << "List sort: ";
        std::cout.width(float_width);
        std::cout << *vect2_it << std::endl;
        std::cout.width(str_width);
        std::cout << "List to vector: ";
        std::cout.width(float_width);
        std::cout << *vect3_it << std::endl;

        vect_it++;
        vect2_it++;
        vect3_it++;

    }
}

void resizing(const int size, std::vector<int>& vector, std::list<int>& list)
{
    vector.resize(size);
    list.resize(size);
}