#include "pe_4.h"

constexpr int SIZE{4};
constexpr int TEMP{50};
char temp_brand[TEMP];
char temp_style[20];
char temp_nickname[TEMP];
short int temp_bootles{0};
short int temp_year{0};


int main(){

    
    
    Port* table[SIZE];
    VintagePort* table2[2];
    for(int it = 0; it < 2; it++){
        enter_Port();
        table[it] = new Port(temp_brand, temp_style, temp_bootles);
    }

    for(int it = 0; it < 2; it++){
        enter_VintagePort();
        table2[it] = new VintagePort(temp_brand, temp_style, temp_nickname, temp_bootles, temp_year);
    }

    // for(int it = 0; it < SIZE; it++){
    //     if(it < 2){
    //         enter_Port();
    //         table[it] = new Port(temp_brand, temp_style, temp_bootles);
    //     }
    //     else{
    //         enter_VintagePort();
    //         table[it] = new VintagePort(temp_brand, temp_style, temp_nickname, temp_bootles, temp_year);
    //     }
    // }

    for(int it = 0; it < 2 ; it++){
        table[it]->Show();
        std::cout << *table[it];
        std::cout << std::endl;
    }

    for(int it = 0; it < 2 ; it++){
        table2[it]->Show();
        std::cout << *table2[it];
        std::cout << std::endl;
    }

    for(int it = 0; it < 2; it++){
        delete table[it];
        delete table2[it];
    }


    return 0;
}

void enter_Port(){
    std::cout << "Enter brand, style and bottles" << std::endl;
    std::cin.getline(temp_brand, TEMP);
    std::cin.getline(temp_style, 20);
    std::cin >> temp_bootles;
    std::cin.get();
}
void enter_VintagePort(){
    std::cout << "Enter brand, style, nickname, bootles and year" << std::endl;
    std::cin.getline(temp_brand, TEMP);
    std::cin.getline(temp_style, 20);
    std::cin.getline(temp_nickname, TEMP);
    std::cin >> temp_bootles;
    std::cin >> temp_year;
    std::cin.get();
}