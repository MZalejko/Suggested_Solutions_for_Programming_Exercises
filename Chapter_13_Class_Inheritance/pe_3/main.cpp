#include "pe_3.h"

constexpr int size{5};
constexpr int temp_size{50};

int main(){

    Ma* tab[size];
    
    char temp_label[temp_size];
    char temp_color[temp_size];
    char temp_style[temp_size];
    int temp_rating{0};
    int num_of_classes{0};
    char kind;

    for(int i = 0; i < size; i++){
        std::cout << "Whichone of Class would you like to create? " << std::endl;
        std::cout << "Type B/b for Base, L/l for Lacks, H/h for Has" << std::endl;
        std::cin >> kind ;
        std::cin.get();
        switch(kind)
        {
        case 'B':
        case 'b':
            std::cout << "Label: " << std::endl;
            std::cin.getline(temp_label,temp_size,'\n');
            //std::cin.get();
            std::cout << "Rating: " << std::endl;
            std::cin >> temp_rating;
            std::cin.get();
            tab[i] = new baseDma(temp_label, temp_rating);
            num_of_classes++;
            break;
        case 'L':
        case 'l':
            std::cout << "Label: " << std::endl;
            std::cin.getline(temp_label,temp_size,'\n');
            std::cout << "Color: " << std::endl;
            std::cin.getline(temp_color,temp_size,'\n');
            std::cout << "Rating: " << std::endl;
            std::cin >> temp_rating;
            std::cin.get();
            tab[i] = new lacksDma(temp_label,temp_color, temp_rating);
            num_of_classes++;
            break;
        case 'H':
        case 'h':
            std::cout << "Label: " << std::endl;
            std::cin.getline(temp_label,temp_size,'\n');
            std::cout << "Style: " << std::endl;
            std::cin.getline(temp_style,temp_size,'\n');
            std::cout << "Rating: " << std::endl;
            std::cin >> temp_rating;
            std::cin.get();
            tab[i] = new hasDma(temp_label,temp_style, temp_rating);
            num_of_classes++;
            break;    
        default:
            goto end_of_loop;
        }
        
    }
    end_of_loop:
    
    for(int it = 0; it < num_of_classes; it++){
        std::cout << *tab[it] << std::endl;
    }
    for(int it = 0; it < num_of_classes; it++){
        tab[it]->View();
    }



    for(int it = 0; it < num_of_classes; it++){
        delete tab[it];
    }

    return 0;
}