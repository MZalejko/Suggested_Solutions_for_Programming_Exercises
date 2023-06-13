#include <iostream>

int main(){

    char sign;

    std::cout << "Enter one of the Options: " << '\n';
    std::cout << "h) herbivore           p) pianist" << std::endl;
    std::cout << "t) tree                g) game" << std::endl;
    std::cout << "q) quit" << std::endl;

    while(std::cin >> sign && sign != 'q'){
        switch (sign){
            case 'h':
                std::cout << "Herbivores are eating only plants!!" << std::endl;
                std::cout << "My favorites are dinosaurs!" << std::endl;
                break;
            case 'p':
                std::cout << "The most famous pianist from Poland is Chopin!" << '\n';
                break;
            case 't':
                std::cout << "I like trees, we need them more and more." << '\n';
                break;
            case 'g':
                std::cout << "My favorite game is Gothic! That was the game of my childhood." << std::endl;
                break;    
            default:
                std::cout << "You need to choose from h, p, t, g or q to ends!" << '\n';
                break;                
        }    
            

    }
    std::cout << "Thank you! Goodbye!" << std::endl;

    return 0;
}