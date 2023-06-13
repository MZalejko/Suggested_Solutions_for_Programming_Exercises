#include <iostream>

void show(char * arr);
void show(char * arr, int n);

int main(void){
    char sentence[30]{"My name is Maciek Zalejko!"};
    int num{4};
    show(sentence);
    std::cout<<"Function overloading\n";
    show(sentence, num);
    return 0;
}

void show(char * arr){
    std::cout<<arr<<std::endl;
}
void show(char * arr, int n){
    for(int i = 0; i < n; i++){
        std::cout<<arr<<std::endl;
    }
}