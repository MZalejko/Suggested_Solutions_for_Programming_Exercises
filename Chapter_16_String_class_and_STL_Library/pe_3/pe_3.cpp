#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>
#include <cstdlib>
#include <ctime>

void copy_from_file(std::ifstream& file, std::vector<std::string>& word_list);
void show_rules(int string_length);

constexpr int guesses{6};

int main(void)
{   
    std::vector<std::string> word_list;
    std::ifstream opened_file;
    
    copy_from_file(opened_file, word_list);


    std::srand(std::time(0));
    char play;

    std::cout << "Will you play a wrod game? <y/n>";
    std::cin >> play;
    play = tolower(play);
    while(play == 'y')
    {
        std::string target = word_list[std::rand() % word_list.size()];
        int length = target.length();
        std::string attempt(length, '-');
        std::string badchars;
        show_rules(length);
        int it {0};
        while(it < guesses && attempt != target)
        {
            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            if(badchars.find(letter) != std::string::npos || attempt.find(letter) != std::string::npos)
            {
                std::cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == std::string::npos)
            {
                std::cout << "Oh, bad guess!\n";
                ++it;
                badchars += letter;
            }
            else
            {
                std::cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);

                while(loc != std::string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            std::cout << "Your word: " << attempt << std::endl;
            if(attempt != target)
            {
                if(badchars.length() > 0)
                    std::cout << "Bad choices: " << badchars << std::endl;
                std::cout << (guesses - it) << " bad guesses left\n";     
            }
        }
        if(it < guesses)
            std::cout << "That's right!\n";
        else
            std::cout << "Sorry, the word is " << target << ".\n";    
        
        std::cout << "Will you play another game? <y/n> ";
        std::cin >> play;
        play = tolower(play);
    }

    std::cout << "Bye" << std::endl;


    opened_file.close();
    return 0;
}

void copy_from_file(std::ifstream& file, std::vector<std::string>& word_list)
{
    file.open("words_list.txt");
    if(!file.is_open())
    {   
        std::cerr << "Problem with file!" << std::endl;
        exit(EXIT_FAILURE);
    }


    std::string temp;
    while(file.good())
    {
        file >> temp;
        word_list.push_back(temp);
    }
    if(file.eof())
    {
        std::cout << "End of File, data loading is completed\n";
    }
    else
    {
        std::cout << "Data loading aborted\n";
    }    
    
}

void show_rules(int string_length)
{
    std::cout << "Guess my secret word. It has " << string_length
              << " letters, and you guess\n"
              << " one letter at a time. You get " << guesses
              << " wrong guesses." << std::endl;
}