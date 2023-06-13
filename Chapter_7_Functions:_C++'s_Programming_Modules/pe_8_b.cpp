#include <iostream>

const int Seasons{4};
const int Size{10};
const char Snames[Seasons][Size]{"Spring", "Summer", "Autumn", "Winter"};
struct Sexpenses{
        double expenses[Seasons]; 
    };

void fill(Sexpenses& abc);
void show(const Sexpenses& abc);

int main(void){
    Sexpenses season_expenses;
    
    fill(season_expenses);
    show(season_expenses);

    return 0;
}


void fill(Sexpenses& abc){
    for(int i = 0; i < Seasons; i++){
        std::cout<<"Enter your expenses in "<<*(Snames+i)<<" : ";
        std::cin>>abc.expenses[i];
    }
}
void show(const Sexpenses& abc){
    double total{0.0};
    std::cout<<"\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++){
        std::cout<<*(Snames+i)<<" : "<<abc.expenses[i]<<" $"<<std::endl;
    }
}