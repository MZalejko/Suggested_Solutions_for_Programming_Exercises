#ifndef PE_6_HXX
#define PE_6_HXX


#include <iostream>
#include <string>
#include <fstream>

using str = std::string;

constexpr const char* firstNameDescription{"First name: "};
constexpr const char* lastNameDescription{"Last name: "};
constexpr const char* jobStrDescription{"Job: "};
constexpr const char* setDescription {"Enter all of the values: "};
constexpr const char* reportingDescription{"Reporting to: "};
constexpr const char* file_name{"employees.dat"};
constexpr int max_array{10};
constexpr int display_width{30};
constexpr int signs_to_ignore{256};
constexpr char ignore_sign{':'};
constexpr char space_sign{' '};


class abstr_emp
{
    private:
        str fname;
        str lname;
        str job;

    public:
        enum class emp_type{Employee = 1, Manager, Fink, Highfink};
        abstr_emp();
        abstr_emp(const str& fn, const str& ln, const str& jb);
        virtual void showAll() const;
        virtual void setAll();
        friend std::ostream& operator<<(std::ostream& os, const abstr_emp& empl);
        virtual ~abstr_emp() = 0;
        virtual void write_all(std::ofstream& out_file) const;
        virtual void get_all(std::ifstream& in_file);
};

class employee: public abstr_emp
{
    public:
        employee();
        employee(const str& fn, const str& ln, const str& jb);
        virtual void showAll() const;
        virtual void setAll();
        virtual void write_all(std::ofstream& out_file) const;
        virtual void get_all(std::ifstream& in_file);
        
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
        virtual void write_all(std::ofstream& out_file) const;
        virtual void get_all(std::ifstream& in_file);
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
        virtual void write_all(std::ofstream& out_file) const;
        virtual void get_all(std::ifstream& in_file);
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
        virtual void write_all(std::ofstream& out_file) const;
        virtual void get_all(std::ifstream& in_file);
};

// Functions

char choose_menu(); //User's menu
void ignore_space(std::ifstream& in_file); //ignoring spaces
void if_file_not_empty(std::ifstream& in_file, abstr_emp** array, int& num); // it adds employees from file
void show_array(abstr_emp** array, const int& num); // function shows current array
void adding_new_employees(abstr_emp** array, int& num); //add new employee to the array
void send_to_file(std::ofstream& of_file, abstr_emp** array,const int& num, const int& num_of_empl);
void delete_memory(abstr_emp** array,const int& num);



#endif // PE_6_HXX