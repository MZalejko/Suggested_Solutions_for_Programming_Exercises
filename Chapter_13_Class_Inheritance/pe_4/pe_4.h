#ifndef PE_4_H
#define PE_4_H
#include <iostream>
#include <cstring>

void enter_Port();
void enter_VintagePort();

class Port{
    private:
        char* brand;
        char style[20];
        int bootles;
    public:
        Port(const char* br = "None", const char* st = "None", int b = 0);
        Port(const Port& pr);
        virtual ~Port();
        Port& operator=(const Port& pr);
        Port& operator+=(int b);
        Port& operator-=(int b);
        int BottleCount() const {return bootles;}
        virtual void Show() const;
        friend std::ostream& operator<<(std::ostream& os, const Port& pr);

};

class VintagePort : public Port {
    private:
        char* nickname;
        int year;
    public:
        VintagePort(const char* br = "None", const char* st = "None", const char* nck = "None", int b = 0, int y = 0);
        VintagePort(const VintagePort& vpr);
        virtual ~VintagePort();
        VintagePort& operator=(const VintagePort& vpr);
        virtual void Show() const;
        friend std::ostream& operator<<(std::ostream& os, const VintagePort& vpr);
};


#endif //PE_4_H