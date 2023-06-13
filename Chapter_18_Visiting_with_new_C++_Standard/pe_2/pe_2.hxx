#include <iostream>
#include <string>
#include <cstdlib>

class Cpmv
{
    public:
        struct Info
        {
            std::string qcode;
            std::string zcode;
        };
    private:
        Info *pl;
    public:
        Cpmv();
        Cpmv(std::string q, std::string z);
        Cpmv(const Cpmv& copy_Cpmv);
        Cpmv(Cpmv&& mv_Cpmv);
        ~Cpmv();
        Cpmv& operator=(const Cpmv& copy_Cpmv);
        Cpmv& operator=(Cpmv&& mv_Cpmv);
        Cpmv operator+(const Cpmv& obj) const;
        void Display() const;
};