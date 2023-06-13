#include "pe_2.hxx"


Cpmv::Cpmv()
{
    std::cout << "Default constructor" << std::endl;
    pl = new Info;
}
Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << "Constructor with two strings" << std::endl;
    pl = new Info;
    pl->qcode = q;
    pl->zcode = z;
}
Cpmv::Cpmv(const Cpmv& copy_Cpmv)
{
    std::cout << "Copying constructor" << std::endl;
    pl = new Info;
    pl->qcode = copy_Cpmv.pl->qcode;
    pl->zcode = copy_Cpmv.pl->zcode;
}
Cpmv::Cpmv(Cpmv&& mv_Cpmv)
{
    std::cout << "Move constructor" << std::endl;
    pl = mv_Cpmv.pl;
    mv_Cpmv.pl = nullptr;
}
Cpmv::~Cpmv()
{
    std::cout << "Destructor" << std::endl;
    delete pl;
}
Cpmv& Cpmv::operator=(const Cpmv& copy_Cpmv)
{
    std::cout << "Copy assigment operator" << std::endl;
    if(this == &copy_Cpmv)
    {
        return *this;
    }
    delete pl;
    pl = new Info;
    pl->qcode = copy_Cpmv.pl->qcode;
    pl->zcode = copy_Cpmv.pl->zcode;
    return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& mv_Cpmv)
{
    std::cout << "Move assigment operator" << std::endl;
    if(this == &mv_Cpmv)
    {
        return *this;
    }
    delete pl;
    pl = mv_Cpmv.pl;
    mv_Cpmv.pl = nullptr;
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj) const
{   
    std::cout << "Plus operator" << std::endl;
    Cpmv Temp(this->pl->qcode, this->pl->zcode);
    Temp.pl->qcode += obj.pl->qcode;
    Temp.pl->zcode += obj.pl->zcode;
    return Temp;
}
void Cpmv::Display() const
{
    std::cout << pl->qcode << std::endl;
    std::cout << pl->zcode << std::endl;
}