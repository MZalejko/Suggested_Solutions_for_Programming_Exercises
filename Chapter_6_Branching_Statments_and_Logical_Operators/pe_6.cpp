#include <iostream>

const int size{20};

struct Contributor{
    char surname[size];
    double payment{0};
};

void show_super(const Contributor * a, int n);
void show_normal(const Contributor *a, int n);

int main(){

    int num_of_contr;
    std::cout << "Enter the number of contributors: \n";
    std::cin >> num_of_contr;
    std::cin.get();

    Contributor * list_of_Contr = new Contributor[num_of_contr];

    for(int i = 0; i < num_of_contr; i++){
        std::cout << "Enter a surname of contributor and his payment: \n";
        std::cin.getline(list_of_Contr[i].surname, size);
        std::cin >> list_of_Contr[i].payment;
        std::cin.get();

    }

    for(int i = 0; i < num_of_contr; i++){
        std::cout << list_of_Contr[i].surname << '\n';
        std::cout << list_of_Contr[i].payment << '\n';
    }

    show_super(list_of_Contr, num_of_contr);
    show_normal(list_of_Contr,num_of_contr);

    delete [] list_of_Contr;

    return 0;
}

void show_super(const Contributor *a, int n){
    bool flag = false;
    std::cout << "Our best Contributors: " << '\n';
    for(int i = 0; i < n ; i++) {
        if(a[i].payment > 10000){
            flag = true;
            std::cout << a[i].surname << ": " << a[i].payment << std::endl;
        }
        else if(flag == false && i == n-1){
            std::cout << "None!" << std::endl;
        }
    }
}
void show_normal(const Contributor *a, int n){
    bool flag = false;
    std::cout << "Our Contributors: " << '\n';
    for(int i = 0; i < n ; i++) {
        if(a[i].payment < 10000){
            flag = true;
            std::cout << a[i].surname << ": " << a[i].payment << std::endl;
        }
        else if(flag == false && i == n-1){
            std::cout << "None!" << std::endl;
        }
    }
}

