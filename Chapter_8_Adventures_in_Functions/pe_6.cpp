#include <iostream>
#include <cstring>

template <typename T> T maxn(T *arr, int n);
template <> const char* maxn(const char*arr[], int n);

int main(){

    int arr1[5]{23,4,56,34,2};
    double arr2[4]{ 2.3,4.7,34.5,34.7};
    const char *res;
    const char *arr3 [5]{
        "Jestem Maciek",
        "Mieszkam w Szn!",
        "Kiedys mieszkalem w Slubicach!",
        "Maaciekk1991!",
        "Auauauauauauuuuu!!!!"
    }; 
    
    std::cout<<"The biggest num of the array 1: "<<maxn(arr1,5)<<std::endl;
    std::cout<<"The biggest num of the array 2: "<<maxn(arr2,4)<<std::endl;
    res = maxn(arr3, 5);

    std::cout<<"Adress of the longest string in array 3: "<<&res<<std::endl;
    std::cout<<res<<std::endl;

    return 0;
}

template <typename T> T maxn(T *arr, int n){
    T res = *(arr+0);
    for(int i = 0; i < n; i++){
        if(res < *(arr+0)){
            res = *(arr+0);
        }
    }
    return res;
}

template <> const char* maxn(const char*arr[], int n){
    const char * res;
    res = arr[0];

    for(int i = 0; i < n ; i++){
        if(strlen(res) < strlen(arr[i])){
            res = arr[i];
        }
    }
    return res;

}