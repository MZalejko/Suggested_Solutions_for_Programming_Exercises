#ifndef PE_2_H
#define PE_2_H
#include <iostream>
#include <cstring>

class Cd{
    private:
        char* performers;
        char* label;
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
        char* main_song;
    public:
        Classic(const char* s1,const char* s2,const char* s3, int n, double x);
        Classic();
        Classic(const Classic& cl1);
        virtual ~Classic();
        virtual void Report() const;
        Classic& operator=(const Classic& cl1);

};



#endif // PE_2_H