#include "emp.hxx"

//methods abstr_emp

abstr_emp::abstr_emp()
{

}
abstr_emp::abstr_emp(const str& fn, const str& ln, const str& jb) : fname(fn), lname(ln), job(jb)
{

}
abstr_emp::~abstr_emp()
{

}
void abstr_emp::showAll() const
{
    std::cout << firstNameDescription << fname << std::endl;
    std::cout << lastNameDescription << lname << std::endl;
    std::cout << jobStrDescription << job << std::endl;
}
void abstr_emp::setAll()
{
    std::cout << setDescription << std::endl;
    std::cout << firstNameDescription;
    getline(std::cin, fname);
    std::cout << lastNameDescription;
    getline(std::cin, lname);
    std::cout << jobStrDescription;
    getline(std::cin, job);
    std::cout << std::endl;
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& empl)
{
    os << empl.fname << std::endl;
    os << empl.lname << std::endl;

    return os;
}

//methods employee

employee::employee() : abstr_emp()
{

}
employee::employee(const str& fn, const str& ln, const str& jb) : abstr_emp(fn, ln, jb)
{

}
void employee::showAll() const
{
    abstr_emp::showAll();
}
void employee::setAll()
{
    abstr_emp::setAll();
}

//methods manager

manager::manager() : abstr_emp()
{

}
manager::manager(const str& fn, const str& ln, const str& jb, int ico) : abstr_emp(fn, ln, jb), inchargeof(ico)
{

}
manager::manager(const abstr_emp& emp, int ico) : abstr_emp(emp), inchargeof(ico)
{

}
manager::manager(const manager& mang) : abstr_emp(mang)
{
    inchargeof = mang.inchargeof;
}


void manager::showAll() const
{
    abstr_emp::showAll();
    std::cout << "In charge of " << inchargeof << " employees" << std::endl;
}
void manager::setAll()
{
    abstr_emp::setAll();
    std::cout << "How many employees has he/she: " << std::endl;
    std::cin >> inchargeof;
    std::cin.get();

}

// methods fink
fink::fink() : abstr_emp()
{

}
fink::fink(const str& fn, const str& ln, const str& jb, const str& rpT) : abstr_emp(fn, ln, jb), reportsTo(rpT)
{

}
fink::fink(const abstr_emp& emp, const str& rpT) : abstr_emp(emp), reportsTo(rpT)
{

}
fink::fink(const fink& fnk) : abstr_emp(fnk)
{
    reportsTo = fnk.reportsTo;
}
void fink::showAll() const
{
    abstr_emp::showAll();
    std::cout << "Reporting to: " << reportsTo << std::endl;
}
void fink::setAll()
{
    abstr_emp::setAll();
    std::cout << "Who are you reporting to: " << std::endl;
    getline(std::cin, reportsTo);
}
// methods highfink

highFink::highFink()
{

}
highFink::highFink(const str& fn, const str& ln, const str& jb, const str& rpT, int ico) : abstr_emp(fn, ln, jb), fink(fn, ln, jb, rpT), manager(fn, ln, jb, ico)
{

}
highFink::highFink(const abstr_emp& emp, const str& rpT, int ico) : abstr_emp(emp), fink(emp, rpT), manager(emp, ico)
{

}
highFink::highFink(const fink& fk, int ico) : abstr_emp(fk), fink(fk), manager(fk, ico)
{

}
highFink::highFink(const manager& mang, const str& rpT) : abstr_emp(mang), fink(mang, rpT), manager(mang)
{

}
highFink::highFink(const highFink& hfk) : abstr_emp(hfk), fink(hfk), manager(hfk)
{

}
void highFink::showAll() const
{
    abstr_emp::showAll();
    std::cout << "In charge of " << manager::inChargeOf() << " employees" << std::endl;
    std::cout << "Reporting to: " << fink::reportsToWho() << std::endl;
}
void highFink::setAll()
{
    abstr_emp::setAll();
    std::cout << "How many employees has he/she: " << std::endl;
    std::cin >> manager::inChargeOf();
    std::cin.get();
    std::cout << "Who are you reporting to: " << std::endl;
    getline(std::cin, fink::reportsToWho());


}