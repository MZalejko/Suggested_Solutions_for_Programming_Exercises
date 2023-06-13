#include <iostream>
#include <cstring>

constexpr const char* endWord{"done"};
const int size{60};

int main(){

    char dest[size];
    std::cout << "Enter word. Type \"done\" to ends.\n";
    std::cin >> dest;

    int num_of_words{0};
    while(strcmp(dest,endWord)){
        num_of_words++;
        std::cin >> dest;
    }
    std::cout << "Number of given words: " << num_of_words << std::endl;
    return 0;
}