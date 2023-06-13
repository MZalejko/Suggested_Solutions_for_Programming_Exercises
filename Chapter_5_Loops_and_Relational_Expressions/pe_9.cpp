#include <iostream>
#include <string>

constexpr const char* endWord{"done"};

int main(){

    std::string dest;
    std::cout << "Enter word. Type \"done\" to ends.\n";
    std::cin >> dest;
    int num_of_words{0};
    while(dest != endWord)
    {
        num_of_words++;
        std::cin >> dest;
    }
    
    std::cout << "Number of given words: " << num_of_words << std::endl;

    return 0;
}
