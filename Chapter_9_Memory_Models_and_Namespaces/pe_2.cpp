#include <iostream>
#include <string>


void strcount(const std::string & str);

int main(){

    std::string input;
    char next;
    std::cout<<"Enter string: \n";
    getline(std::cin, input);

    while(input.size()){
        strcount(input);
        std::cout<<"Enter next string (empty string ends entering): \n";
        getline(std::cin, input);

    }
    std::cout<<"Done!\n";
    return 0;
}

void strcount(const std::string & str){
    static int total{0};
    int count{0};

    std::cout<<"\""<<str<<"\" have ";
    for(int i = 0; i < str.size(); i++){
        count++;
    }
    total += count;
    std::cout<<count<< " signs\n";
    std::cout<<"Together "<<total<<" signs\n";
}