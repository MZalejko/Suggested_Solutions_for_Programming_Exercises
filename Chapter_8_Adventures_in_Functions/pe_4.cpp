#include <iostream>
#include <cstring>

struct stringy{
    char *str;
    int ct;
};

void set(stringy & strc, char *sentence);
void show(const stringy& strc, int num=1);
void show(const char *sentence, int num=1);


int main(void){

    stringy beany;
    char testing[] = "Reality is no longer the same as it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);
    show(testing, 3);

    show("Done!");

    delete [] beany.str;

    return 0;

}

void set(stringy & strc, char *sentence){
    strc.str = new char [strlen(sentence) + 1];
    strcpy(strc.str, sentence);
    strc.ct = strlen(sentence);

}
void show(const stringy& strc, int num){
    for(int i = 0; i < num; i++){
        std::cout<<strc.str<<std::endl;
    }
}
void show(const char *sentence, int num){
    for(int i = 0; i < num; i++){
        std::cout<<sentence<<std::endl;
    }
}