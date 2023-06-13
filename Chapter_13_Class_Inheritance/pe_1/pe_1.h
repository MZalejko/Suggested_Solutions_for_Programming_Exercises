#ifndef PE_1_H
#define PE_1_H
#include <iostream>
#include <cstring>

class Cd{
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(const char* s1,const char* s2, int n, double x);
        Cd(const Cd& d);
        Cd();
        virtual ~Cd();
        virtual void Report() const;
        Cd& operator=(const Cd& d);    
};

class Classic: public Cd {
    private:
        char main_song[25];
    public:
        Classic(const char* s1,const char* s2,const char* s3, int n, double x);
        Classic();
        virtual ~Classic();
        virtual void Report() const;

};



#endif // PE_1_H