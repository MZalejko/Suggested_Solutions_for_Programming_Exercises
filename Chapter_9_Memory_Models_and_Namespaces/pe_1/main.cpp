#include "golf.h"

int main(){
    golf ourTeam[4];

    setgolf(ourTeam[0],"Johnny Bravo!", 230);

    for(int i = num_of_s_pl; i < 4; i++){
        if(setgolf(ourTeam[i]) == 0){
            std::cout<<"Seting the Team aborted. None name player entered."<<std::endl;
            break;
        }
    }
    handicap(ourTeam[0], 450);

    for(int i = 0; i < num_of_s_pl; i++){
        showgolf(ourTeam[i]);
    }

    return 0;
}