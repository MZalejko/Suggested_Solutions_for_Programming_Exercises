#ifndef EMP_HXX
#define EMP_HXX

#include <iostream>
#include <string>

using str = std::string;

constexpr const char* firstNameDescription{"First name: "};
constexpr const char* lastNameDescription{"Last name: "};
constexpr const char* jobStrDescription{"Job: "};
constexpr const char* setDescription {"Enter all of the values: "};


class abstr_emp
{
    private:
        str fname;
        str lname;
        str job;

    public:
        abstr_emp();
        abstr_emp(const str& fn, const str& ln, const str& jb);
        virtual void showAll() const;
        virtual void setAll();
        friend std::ostream& operator<<(std::ostream& os, const abstr_emp& empl);
        virtual ~abstr_emp() = 0;
};

class employee: public abstr_emp
{
    public:
        employee();
        employee(const str& fn, const str& ln, const str& jb);
        virtual void showAll() const;
        virtual void setAll();
};

class manager: virtual public abstr_emp
{
    private:
        int inchargeof;
    
    protected:
        int inChargeOf()const {return inchargeof;};
        int& inChargeOf() {return inchargeof;};
    
    public:
        manager();
        manager(const str& fn, const str& ln, const str& jb, int ico = 0);
        manager(const abstr_emp& emp, int ico = 0);
        manager(const manager& mang);
        virtual void showAll() const;
        virtual void setAll();
};

class fink: virtual public abstr_emp
{
    private:
        str reportsTo;
    
    protected:
        const str reportsToWho() const {return reportsTo;};
        str& reportsToWho() {return reportsTo;};

    public:
        fink();
        fink(const str& fn, const str& ln, const str& jb, const str& rpT);
        fink(const abstr_emp& emp, const str& rpT);
        fink(const fink& fnk);
        virtual void showAll() const;
        virtual void setAll();
};

class highFink: public manager, public fink
{
    public:
        highFink();
        highFink(const str& fn, const str& ln, const str& jb, const str& rpT, int ico = 0);
        highFink(const abstr_emp& emp, const str& rpT, int ico = 0);
        highFink(const fink& fk, int ico = 0);
        highFink(const manager& mang, const str& rpt);
        highFink(const highFink& hfk);
        virtual void showAll() const;
        virtual void setAll();
};





#endif // EMP_HXX