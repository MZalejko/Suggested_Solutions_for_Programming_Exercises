#ifndef PERSON_HXX
#define PERSON_HXX

#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUMOFCARDSCOLORS 4
#define MINCARD 1
#define MAXCARD 52
#define DEFAULTDRAWTIME 5.0
#define ZERO 0

constexpr const char* defName{"No one"};

void clearBuffor();

class Person{

    private:
        std::string fullName;

    protected:
        virtual void enterDatas();
        virtual void showDatas() const;

    public:
        Person() : fullName(defName) {};
        Person(const std::string& name) : fullName(name){};
        virtual ~Person() = 0;
        virtual void Show() const = 0;
        virtual void Set() = 0;

};

class Gunslinger : virtual public Person {

    private:
        float timeToDraw;
        short numOfKills;

    protected:
        virtual void enterDatas();
        virtual void showDatas() const;

    public:
        Gunslinger() : Person(), timeToDraw(DEFAULTDRAWTIME), numOfKills(ZERO) {};
        Gunslinger(const std::string& name, float drawTime, short kills): Person(name), timeToDraw(drawTime), numOfKills(kills) {};
        Gunslinger(const Person& newP, float drawTime, short kills) : Person(newP), timeToDraw(drawTime), numOfKills(kills) {};
        //virtual ~Gunslinger() {};
        virtual void Show() const;
        virtual void Set();
        float Draw() const {return timeToDraw;};
        void newKills();
        

};

class Card{
    
    private:
        short cardColor;
        short cardValue;
        static std::string colors[NUMOFCARDSCOLORS];
        
    protected:
        enum cardColors{hearts , diamonds, clubs, spades};
        void getCardColor();
        void getCardValue();

    public:
        Card() : cardColor(hearts), cardValue(MINCARD) {};
        ~Card();
        void setCardValues() {getCardColor(); getCardValue();};
        void showCard() const;

};

class PokerPlayer : virtual public Person, protected Card{

    protected:
        virtual void enterDatas();
        virtual void showDatas() const;
    public:
        PokerPlayer() : Person(), Card() {};
        PokerPlayer(const std::string& name) : Person(name), Card() {};
        PokerPlayer(const Person& newP) : Person(newP), Card() {};
        //virtual ~PokerPlayer() {};
        virtual void Show() const;
        virtual void Set();
        void Draw(){Card::setCardValues(); Card::showCard();};

};

class BadDude : public Gunslinger, public PokerPlayer {
    protected:
        virtual void enterDatas();
        virtual void showDatas() const;

    public:
        BadDude() {};
        BadDude(const std::string& name , float drawT, short kills) : Person(name), Gunslinger(name, drawT,kills), PokerPlayer(name) {};
        BadDude(const Person& newP, float drawT, short kills) : Person(newP), Gunslinger(newP, drawT, kills), PokerPlayer(newP) {};
        BadDude(const Gunslinger& newG) : Person(newG), Gunslinger(newG), PokerPlayer(newG) {};
        BadDude(const PokerPlayer& newPl, float drawT, short kills) : Person(newPl), Gunslinger(newPl, drawT, kills), PokerPlayer(newPl) {};
        //virtual ~BadDude() {};
        float Gdraw() const {return Gunslinger::Draw();};
        void Cdraw() {PokerPlayer::Draw();};
        virtual void Show() const;
        virtual void Set(); 
};


#endif //PERSON_HXX