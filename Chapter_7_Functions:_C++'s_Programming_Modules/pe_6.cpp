#include <iostream>

const int size{15};

int fill_array(double * arr, int size);
void show_array(const double * arr, int size);
void reverse_array(double * arr, int size);

int main(){

    double array[size];
    int new_size;
    new_size = fill_array(array, size);
    show_array(array, new_size);
    reverse_array(array, new_size);
    show_array(array, new_size); 
    return 0;
}

int fill_array(double * arr, int size){
    int temp{0};
    double num{0};
    std::cout<<"Fill an array with \"double\" numbers, none numeric value ends entering of numbers\n"; 
    while((std::cin>>num) && temp < size){
        std::cin.get();
        *(arr + temp) = num;
        temp++;
        if(temp == size){
            std::cout<<"Array is full.\n";
            break;
        }
    }
    if(temp < size){
        std::cout<<"None numeric value was entered. Run of function was compromised.\n";
    }
    return temp;
}
void show_array(const double * arr, int size){
    for(int i = 0; i < size; i++){
        std::cout<<*(arr+i)<<" ";
    }
    std::cout<<std::endl;
}
void reverse_array(double * arr, int size){
    double temp;
    for(int i = 0, j = size-1; i < size/2; ++i, --j){
        temp = *(arr + j);
        *(arr + j) = *(arr + i);
        *(arr + i) = temp;
    }
}