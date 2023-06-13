#include "person.hxx"
#include <vector>

#define SIZE 5

constexpr const char* proofString{"GPBEgpbe"};

Person* choosePlayer(Person* newPlayer);

int main(){
    
    std::vector<Person*>ourPlayers;
    Person* newPerson;



    for(int it = 0; it < SIZE; it++){
        ourPlayers.push_back(choosePlayer(newPerson));
    
        if(ourPlayers[it] != nullptr)
            ourPlayers[it]->Set();
        else{
            ourPlayers.pop_back();
            break;
        }
    }

    std::cout << std::endl;

    for(int it = 0; it < ourPlayers.size(); it++){
        std::cout << &ourPlayers[it] << std::endl;
    }

    std::cout << std::endl;

    for(int it = 0; it < ourPlayers.size(); it++){
        ourPlayers[it]->Show();
    }


}

Person* choosePlayer(Person* newPlayer) {
    char choice;
    do{
        std::cout << "Choose your player: " << std::endl;
        std::cout << "G : Gunslinger " << '\t' << "P : PokerPlayer" << std::endl;
        std::cout << "B : BadDude " << '\t' << "E : exit" << std::endl;
        std::cin >> choice;
        clearBuffor();
    }
    while(strchr(proofString, choice) == ZERO);
    switch(choice){
        case 'G':
        case 'g':
            newPlayer = new Gunslinger;
            break;
        case 'P':
        case 'p':
            newPlayer = new PokerPlayer;
            break;
        case 'B':
        case 'b':
            newPlayer = new BadDude;
            break;
        case 'E':
        case 'e':
            newPlayer = nullptr;
            break;  
        }
    return newPlayer;
}