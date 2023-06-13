#include <iostream>

const int Max{5};

double* fill_array(double *arr_start, double *arr_end);
void show_array(const double *arr_start, const double* end);
void revalue(double r, double *arr_start, const double* end);

int main(void){

    double properties[Max];
    double *ptr;
    ptr = fill_array(properties, properties+Max);
    show_array(properties, ptr);
    
    if(*ptr > 0){
        std::cout<<"Set new value for your array: ";
        double factor;
        while(!(std::cin >> factor)){
            std::cin.clear();
            while(std::cin.get() != '\n'){
                continue;
            }
            std::cout<<"Incorrect value: Enter an number: ";
        }
        revalue(factor, properties, ptr);
        show_array(properties, ptr);
    }
    std::cout<<"Done.\n";

    return 0;
}

double* fill_array(double *arr_start, double *arr_end){
    double* ptr;
    double temp;
    int i;
    for(i = 0; i < arr_end - arr_start; i++){
        std::cout<<"Enter the value nr "<< (i+1)<<" : ";
        std::cin>>temp;
        if(!std::cin){
            std::cin.clear();
            while(std::cin.get() != '\n'){
                continue;
            }
            std::cout<<"False data, entering of datas aborted.\n";
            break;
        }
        else if(temp < 0){
            break;
        }
        *(arr_start + i) = temp; 
    }
    ptr = arr_start+i;
    return ptr;
}
void show_array(const double *arr_start, const double* end){
    for(int i = 0; i < end - arr_start; i++){
        std::cout<<"Property nr "<<(i+1)<<": ";
        std::cout<<*(arr_start+i)<<std::endl;
    }
}
void revalue(double r, double *arr_start, const double* end){
    for(int i = 0; i < end - arr_start; i++){
        *(arr_start+i) *= r;
    }
}
