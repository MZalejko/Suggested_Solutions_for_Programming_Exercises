#ifndef PE_2_H
#define PE_2_H
#include <iostream>
#include <string>
#include <cstring>

class Person{

    private:
        static const int LIMIT{256};
        std::string lname;
        char fname[LIMIT];
    public:
        Person(){ lname = ""; fname[0] = '\0';}
        Person(const std::string & ln, const char * fn = "HeyYou");
        void Show() const;
        void FormalShow() const;
};


#endif