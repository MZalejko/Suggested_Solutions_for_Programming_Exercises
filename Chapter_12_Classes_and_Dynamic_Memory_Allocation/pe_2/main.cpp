#include "pe_2.h"


int main(){

    String s1(" i ucze sie C++.");
    String s2 = "Podaj swoje imie: ";
    String s3;
    std::cout << s2;
    std::cin >> s3;
    s2 = "Mam na imie " + s3;
    std::cout << s2 << '\n';
    s2 = s2 + s1;
    s2.stringup();
    std::cout << "Ciag\n" << s2 <<"\nzawiera" <<" " << s2.Num_of_char('A') << " 'A'.\n";
    s1 = "czerwona";
    String rgb[3] = { String(s1), String("zielona"), String("niebieska")};
    std::cout << "Podaj nazwe barwy podstawowej: ";
    String ans;
    bool success = false;
    while(std::cin >> ans){
        ans.stringlow();
        for(int i = 0; i < 3; i++){
            if(ans == rgb[i]){
                std::cout << "Prawidlowo!\n";
                success = true;
                break;
            }
        }
        if(success){
            break;
        }
        else{
            std::cout << "Try  again!\n";
        }

    }
    std::cout << "goodbye!\n";

    return 0;
}