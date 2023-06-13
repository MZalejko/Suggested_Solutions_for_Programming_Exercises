//VARIANT 1:

#include <iostream>
#include <cstring>

struct chaff{
    char dross[20];
    int slag;
};

void show(const chaff *arr, int n);

int main(){

    char temp[20];

    chaff *chaffs = new chaff[2];

    for(int i = 0; i < 2; i++){
        std::cout<<"CHAFF "<<i+1<<" :"<<std::endl;
        std::cin.get(temp, 20);
        strcpy(chaffs[i].dross, temp);
        std::cin>>chaffs[i].slag;
        std::cin.get();
    }

    show(chaffs, 2);

    delete [] chaffs;
    return 0;
}

void show(const chaff *arr, int n){
    for(int i =0; i < n; i++){
        std::cout<<"CHAFF "<<i+1<<" :"<<std::endl;
        std::cout<<"Dross: "<<arr[i].dross<<std::endl;
        std::cout<<"Slag: "<<arr[i].slag<<std::endl;
    }
}