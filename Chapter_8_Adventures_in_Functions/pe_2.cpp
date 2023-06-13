#include <iostream>
#include <cstring>

const int size{40};

struct Choco_Bar{
    char name_of_product[size];
    double weight;
    int num_of_cals;
};

void fill_struct(Choco_Bar & prod, const char * name = "Millenium Munch", double wght = 2.85, int cals = 350);
void show(const Choco_Bar & prod);

int main(){
    int num_of_prod;
    char temp_n[size];
    double temp_w{0.0};
    int temp_c{0};

    std::cout<<"How many products woudl you like to enter? ";
    std::cin>>num_of_prod;
    std::cin.get();
    
    Choco_Bar products[num_of_prod];
    
    for(int i = 0; i < num_of_prod; i++){
        std::cout<<"Product nr: "<<(i+1)<<'\n';
        std::cout << "Name of product: ";
        std::cin.getline(temp_n, size);
        std::cout << "Weight of the product: ";
        std::cin >> temp_w;
        std::cin.get(); 
        std::cout << "Calories of the product: ";
        std::cin >> temp_c;
        std::cin.get();

        fill_struct(products[i], temp_n, temp_w, temp_c);
        std::cout << std::endl;
    }

    return 0;
}

void fill_struct(Choco_Bar & prod, const char * name, double wght, int cals){
    strcpy(prod.name_of_product, name);
    prod.weight = wght;
    prod.num_of_cals = cals;


}
void show(const Choco_Bar & prod){
    std::cout<<std::endl;
    std::cout<<"Product name: "<<prod.name_of_product<<'\n';
    std::cout<<"Weight of product: "<<prod.weight<<'\n';
    std::cout<<"Calories in product: "<<prod.num_of_cals<<'\n';
}