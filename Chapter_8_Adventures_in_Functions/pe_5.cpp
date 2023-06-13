#include <iostream>

const int size{5};

template<typename T>
T max5(T* arr, int n);

int main(void){

    int arr1[size]{4,6,34,23,78};
    double arr2[size]{2.4,5.6, 34.5, 56.6, 12.2};

    std::cout<<"The biggest num of array 1: "<<max5(arr1, size)<<std::endl;
    std::cout<<"The biggest num of array 2: "<<max5(arr2, size)<<std::endl;

    return 0;
}

template<typename T>
T max5(T* arr, int n){
    T res;
    res = arr[0];
    for(int i = 0; i < n; i++){
        if(res < arr[i]){
            res = arr[i];
        }
    }
    return res;
}