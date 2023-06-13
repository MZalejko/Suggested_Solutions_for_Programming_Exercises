#include <iostream>
#include <string>
#include <cctype>

#define QUIT_SIZE 1
constexpr char vowels[]{'a', 'e', 'i', 'o', 'u', 'y'};

void count_words(std::string& str, int& ct_vw, int& ct_cons, int& ct_oth);
void show_results(const int& ct_vw, const int& ct_cons, const int& ct_oth);

int main(){

    int st_vowels{0};
    int st_consonants{0};
    int st_other{0};

    

    std::cout << st_vowels << " " << st_consonants << " " << st_other << std::endl;

    std::string input_str;

    count_words(input_str, st_vowels, st_consonants, st_other);
    show_results(st_vowels, st_consonants, st_other);

    return 0;
}

void count_words(std::string& str, int& ct_vw, int& ct_cons, int& ct_oth)
{
    std::cout << "Enter words (q to quit)." << std::endl;

    std::cin >> str;

    while(str.size() > QUIT_SIZE || (*str.begin() != 'q' && *str.begin() != 'Q'))
    {   
        if(isdigit(*str.begin()))
        {
            ct_oth++;
            std::cin >> str;
            continue;
        }
        else if(isblank(*str.begin()))
        {
            std::cin >> str;
            continue;
        }
        switch(*str.begin())
        {
            case vowels[0]:
            case vowels[1]:
            case vowels[2]:
            case vowels[3]:
            case vowels[4]:
            case vowels[5]:
                ct_vw++;
                break;
            default :
                ct_cons++;
                break; 
        }
        std::cin >> str;
    }
}

void show_results(const int& ct_vw, const int& ct_cons, const int& ct_oth)
{
    std::cout << ct_vw << " words beginning with vowels." << std::endl;
    std::cout << ct_cons << " words beginning with consonants." << std::endl;
    std::cout << ct_oth << " others." << std::endl; 
}
