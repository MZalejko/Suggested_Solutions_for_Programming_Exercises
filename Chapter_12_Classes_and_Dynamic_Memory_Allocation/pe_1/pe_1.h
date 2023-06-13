#ifndef PE_1_H
#define PE_1_H
#include <iostream>
#include <cstring>

class Cow{

    private:
        char name[20];
        char* hobby;
        double weight;
    public:
        Cow();
        Cow(const char* nm, const char* ho, double wt);
        Cow(const Cow& c);
        ~Cow();
        Cow& operator=(const Cow& c);
        void Show() const;    

};

#endif //PE_1_H