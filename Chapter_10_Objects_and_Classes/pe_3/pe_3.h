#ifndef PE_3_H
#define PE_3_H
#include <iostream>
#include <cstring>

const int Len{40};

class Golf{
    private:
        char fullname[Len];
        int handicap;
    public:
        Golf(const char * name = "None", int i = 0);
        ~Golf();
        void setgolf();
        void handc(int hc);
        void showgolf() const;
        void length_of_fullname()const;
};


#endif