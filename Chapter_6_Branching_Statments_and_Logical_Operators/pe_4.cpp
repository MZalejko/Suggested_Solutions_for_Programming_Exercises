#include <iostream>

const int size{25};
const int size_of_company{5};
struct ZPDW
{
    char name[size];
    char position[size];
    char pseudonym[size];
    int preferations;
};

int main(){

    char value;
    ZPDW list_of_workers[size_of_company]
    {
        {"Peter Robertson", "Electric", "Petro", 1},
        {"Maciek Zalejko", "Supervisor", "Zaleyy", 0},
        {"Robert Gacek", "Builder", "Gacus", 2},
        {"Andreas Knuettel", "Supervisor", "Knuetti", 1},
        {"Adriana Smigielska", "Idiot", "DramaQueen", 2}
    };

    std::cout << "Enter one of the sorting options: " << '\n';
    std::cout << "a) list by names           b) list by positions" << std::endl;
    std::cout << "c) list by pseudonyms      d) list by preferations" << std::endl;
    std::cout << "q) quit" << std::endl;

    while(std::cin >> value && value != 'q'){
        switch(value){
            case 'a':
                for(int i = 0; i < size_of_company; i++){
                    std::cout << list_of_workers[i].name << std::endl;
                }
                break;
            case 'b':
                for(auto i: list_of_workers){std::cout << i.position << std::endl;}
                break;
            case 'c':
                for(auto i: list_of_workers){std::cout << i.pseudonym << std::endl;}
                break;
            case 'd':
    
                for(int j = 0; j < size_of_company; j++){
                    switch(list_of_workers[j].preferations){
                        case 0:
                            std::cout << list_of_workers[j].name << '\n';
                            break;
                        case 1:
                            std::cout << list_of_workers[j].position << '\n';
                            break;
                        case 2:
                            std::cout << list_of_workers[j].name << '\n';
                            break;             
                    }
                }
                break;
            default:
                std::cout << "Incorrect value: a,b,c,d or q to quit!" << '\n';
                break;    
    }
}
    std::cout << "Goodbye!" << std::endl;
    return 0;
}    
