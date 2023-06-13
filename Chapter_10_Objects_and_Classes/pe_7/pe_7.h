#ifndef PE_7_H
#define PE_7_H

#include <iostream>
#include <cstring>

class Plorg{

    private:
        static const int length_of_name{19};
        char name_of_Plorg[length_of_name];
        int satiety_factor;

    public:
        Plorg(const char * name = "Plooooorg", int satiety = 90);
        ~Plorg();
        void change_satiety(int new_satiety);
        void say_my_name() const;

};


#endif