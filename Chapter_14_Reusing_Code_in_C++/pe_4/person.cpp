#include "person.hxx"

void clearBuffor(){

    while(std::cin.get() != '\n'){
        continue;
    }
}


// Person methods
Person::~Person() {}

void Person::enterDatas(){
    std::cout << "Enter a name: " << std::endl;
    std::getline(std::cin, fullName);
}

void Person::showDatas() const{
    std::cout <<"Name: " << fullName << std::endl;
}

//Gunslinger methods

void Gunslinger::enterDatas(){
    std::cout << "What is his gun draw time: " << std::endl;
    std::cin >> timeToDraw;
    while(timeToDraw < DEFAULTDRAWTIME){
        std::cout << "No one is so quick! Try again:  " << std::endl;
        std::cin >> timeToDraw;
    }
    clearBuffor();
    std::cout << "How many kills does he have: " << std::endl;
    std::cin >> numOfKills;
    while (numOfKills < ZERO){
        std::cout << "How could he killed less than 0? Again!: " << std::endl;
        std::cin >> numOfKills;
    }
    clearBuffor();
}
void Gunslinger::showDatas() const{
    std::cout << "Gun draw time: " << timeToDraw << std::endl;
    std::cout << "Kills: " << numOfKills << std::endl; 
}
void Gunslinger::Show() const{
    std::cout << "Type of person: Gunslinger" << std::endl;
    Person::showDatas();
    showDatas();
}

void Gunslinger::Set(){
    std::cout << "Class: Gunslinger" << std::endl;
    Person::enterDatas();
    enterDatas();
}

void Gunslinger::newKills() {
    
    std::cout << "Ok, how many kills has he right now: " << std::endl;
    std::cin >> numOfKills;
    while(numOfKills < ZERO){
        std::cout << "Noooo... Again...: " << std::endl;
        std::cin >> numOfKills;
    }
    clearBuffor();

}

//Card methods

std::string Card::colors[NUMOFCARDSCOLORS] = {"hearts", "diamonds", "clubs", "spades"};


Card::~Card() {};

void Card::getCardColor(){
    srand(time(NULL));
    
    cardColor = rand() % NUMOFCARDSCOLORS;
}

void Card::getCardValue(){
    srand(time(NULL));

    cardValue = rand() % MAXCARD;
    cardValue++;

}

void Card::showCard() const{
    std::cout << "Card color: " << colors[cardColor] << std::endl;
    std::cout << "Card value: " << cardValue << std::endl;
}

//Poker player methods

void PokerPlayer::enterDatas(){
    Card::setCardValues();
}

void PokerPlayer::showDatas() const{
    Card::showCard();
}

void PokerPlayer::Show() const {
    std::cout << "Type of Person : Poker Player" << std::endl;
    Person::showDatas();
    showDatas();
}

void PokerPlayer::Set(){
    std::cout << "Class: PokerPlayer" << std::endl;
    Person::enterDatas();
    enterDatas();
}

//Badboy methods

void BadDude::enterDatas() {
    Gunslinger::enterDatas();
    PokerPlayer::enterDatas();
}

void BadDude::showDatas() const{
    Gunslinger::showDatas();
    PokerPlayer::showDatas();
}

void BadDude::Show() const{
    std::cout << "Type of the person: Bad Dude" << std::endl;
    Person::showDatas();
    showDatas();

}    

void BadDude::Set() {
    std::cout << "Class BadDude: " << std::endl;
    Person::enterDatas();
    enterDatas();
}