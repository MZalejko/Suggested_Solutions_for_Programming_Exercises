#include <iostream>
#include <fstream>
#include <cstdlib>

const int size{20};

struct Contributor{
    char surname[size];
    double payment{0};
};

void show_super(const Contributor * a, int n);
void show_normal(const Contributor *a, int n);

int main(){

    int num_of_contr;
    std::ifstream file;
    file.open("zad_9.txt");
    if(!file.is_open()){
        exit(EXIT_FAILURE);
    }
    file>>num_of_contr;
    file.get();

    Contributor * list_of_Contr = new Contributor[num_of_contr];

    for(int i = 0; i < num_of_contr; i++){
        file.getline(list_of_Contr[i].surname, size);
        file>>list_of_Contr[i].payment;
        file.get();
        if(file.fail()){
            exit(EXIT_FAILURE);
        }

    }

    for(int i = 0; i < num_of_contr; i++){
        std::cout<<list_of_Contr[i].surname<<'\n';
        std::cout<<list_of_Contr[i].payment<<'\n';
    }

    show_super(list_of_Contr, num_of_contr);
    show_normal(list_of_Contr,num_of_contr);

    file.close();
    delete [] list_of_Contr;

    return 0;
}

void show_super(const Contributor *a, int n){
    bool flag = false;
    std::cout<<"Our best Contributors: "<<'\n';
    for(int i = 0; i < n ; i++) {
        if(a[i].payment > 10000){
            flag = true;
            std::cout<<a[i].surname<<": "<<a[i].payment<<std::endl;
        }
        else if(flag == false && i == n-1){
            std::cout<<"None!"<<std::endl;
        }
    }
}
void show_normal(const Contributor *a, int n){
    bool flag = false;
    std::cout<<"Our Contributors: "<<'\n';
    for(int i = 0; i < n ; i++) {
        if(a[i].payment < 10000){
            flag = true;
            std::cout<<a[i].surname<<": "<<a[i].payment<<std::endl;
        }
        else if(flag == false && i == n-1){
            std::cout<<"None!"<<std::endl;
        }
    }
}

