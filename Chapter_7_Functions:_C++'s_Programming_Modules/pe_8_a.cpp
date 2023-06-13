#include <iostream>

const int Seasons{4};
const int Size{10};
const char Snames[Seasons][Size]{"Spring", "Summer", "Autumn", "Winter"};

void fill(double *ptr);
void show(const double *ptr);

int main(void){

    double expenses[Seasons];
    fill(expenses);
    show(expenses);

    return 0;
}


void fill(double *ptr){
    for(int i = 0; i < Seasons; i++){
        std::cout<<"Enter your expenses in "<<*(Snames+i)<<" : ";
        std::cin>>*(ptr+i);
    }
}
void show(const double *ptr){
    double total{0.0};
    std::cout<<"\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++){
        std::cout<<*(Snames+i)<<" : "<<*(ptr + i)<<" $"<<std::endl;
    }
}