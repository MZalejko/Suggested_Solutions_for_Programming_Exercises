#include "pe_6.hxx"

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

void abstr_emp::write_all(std::ofstream& out_file) const
{
    out_file << firstNameDescription << fname << std::endl;
    out_file << lastNameDescription << lname << std::endl;
    out_file << jobStrDescription << job << std::endl;
}

void abstr_emp::get_all(std::ifstream& in_file)
{
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    getline(in_file, fname);
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    getline(in_file, lname);
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    getline(in_file, job);

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

void employee::write_all(std::ofstream& out_file) const
{
    out_file << (int)abstr_emp::emp_type::Employee << std::endl;
    abstr_emp::write_all(out_file);
}

void employee::get_all(std::ifstream& in_file)
{
    abstr_emp::get_all(in_file);
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
    std::cout << "In charge of: " << inchargeof << " employees" << std::endl;
}
void manager::setAll()
{
    abstr_emp::setAll();
    std::cout << "How many employees has he/she: " << std::endl;
    std::cin >> inchargeof;
    std::cin.get();

}

void manager::write_all(std::ofstream& out_file) const
{
    out_file << (int)abstr_emp::emp_type::Manager << std::endl;
    abstr_emp::write_all(out_file);
    out_file << "In charge of: " << inchargeof << std::endl;

}

void manager::get_all(std::ifstream& in_file)
{
    abstr_emp::get_all(in_file);
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    in_file >> inchargeof;
    in_file.get();
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
    std::cout << reportingDescription << reportsTo << std::endl;
}
void fink::setAll()
{
    abstr_emp::setAll();
    std::cout << "Whom are you reporting to: " << std::endl;
    getline(std::cin, reportsTo);
}

void fink::write_all(std::ofstream& out_file) const
{
    out_file << (int)abstr_emp::emp_type::Fink << std::endl;
    abstr_emp::write_all(out_file);
    out_file << reportingDescription << reportsTo << std::endl;

}

void fink::get_all(std::ifstream& in_file)
{
    abstr_emp::get_all(in_file);
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    getline(in_file, reportsTo);

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
    std::cout << reportingDescription << fink::reportsToWho() << std::endl;
}
void highFink::setAll()
{
    abstr_emp::setAll();
    std::cout << "How many employees has he/she: " << std::endl;
    std::cin >> manager::inChargeOf();
    std::cin.get();
    std::cout << "Whom are you reporting to: " << std::endl;
    getline(std::cin, fink::reportsToWho());


}

void highFink::write_all(std::ofstream& out_file) const
{
    out_file << (int)abstr_emp::emp_type::Highfink << std::endl;
    abstr_emp::write_all(out_file);
    out_file << "In charge of: " << manager::inChargeOf() << std::endl;
    out_file << reportingDescription << fink::reportsToWho() << std::endl;

}

void highFink::get_all(std::ifstream& in_file)
{
    abstr_emp::get_all(in_file);
    in_file >> manager::inChargeOf();
    in_file.get();
    in_file.ignore(signs_to_ignore, ignore_sign);
    ignore_space(in_file);
    getline(in_file, fink::reportsToWho());
    
}

//Functions

char choose_menu()
{
    char return_value;

    std::cout << "\t\tPROGRAM'S MENU" << std::endl;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout.width(display_width);
    std::cout << "E: Employee";
    std::cout << "M: Manager" << std::endl;
    std::cout.width(display_width);
    std::cout << "F: Fink";
    std::cout << "H: Highfink" << std::endl;
    std::cout << "Q: Quit" << std::endl;
    std::cout.width(0);

    std::cout << "Choose option: ";
    std::cin.get(return_value);
    std::cin.get();
    return_value = toupper(return_value);

    return return_value;

}

void ignore_space(std::ifstream& in_file)
{
    while(space_sign == in_file.peek())
    {
        in_file.get();
    }
}

void if_file_not_empty(std::ifstream& in_file, abstr_emp** array, int& num)
{
    if(in_file.is_open())
    {
        std::cout << "Reading the list" << std::endl;
        int class_type;
        char ch;
        while((in_file >> class_type).get(ch))
        {
            
            switch(class_type)
            {
                case (int)abstr_emp::emp_type::Employee :
                    array[num] = new employee;
                    array[num++] -> get_all(in_file);
                    break;
                case (int)abstr_emp::emp_type::Manager :
                    array[num] = new manager;
                    array[num++] -> get_all(in_file);
                    break;
                case (int)abstr_emp::emp_type::Fink :
                    array[num] = new fink;
                    array[num++] -> get_all(in_file);
                    break;
                case (int)abstr_emp::emp_type::Highfink :
                    array[num] = new highFink;
                    array[num++] -> get_all(in_file);
                    break;
                default:
					std::cerr << "It looks like an error has occurred" << std::endl;
					break;
            }
        }
    }
    in_file.close();
}

void show_array(abstr_emp** array, const int& num)
{
    std::cout << "ARRAY: " << std::endl;
    for(int it = 0; it < num; it++)
    {
        array[it]->showAll();
        std::cout << std::endl;
    }
}

void adding_new_employees(abstr_emp** array, int& num)
{
    char value{'0'}; //default value 
    while(num < max_array && value != 'Q')
    {
        value = choose_menu();
        switch(value)
        {
            case 'E':
                array[num] = new employee;
                array[num++] -> setAll();
                break;
            case 'M':
                array[num] = new manager;
                array[num++] -> setAll();
                break;
            case 'F':
                array[num] = new fink;
                array[num++] -> setAll();
                break;
            case 'H':
                array[num] = new highFink;
                array[num++] -> setAll();
                break;
            case 'Q':
                std::cout << "Program ends the adding process. \n";
                break;
            default:
                std::cout << "False character value. Choose E,M,F,H or Q" << std::endl;
                break;

        }
    }
}

void send_to_file(std::ofstream& of_file,abstr_emp** array,const int& num,const int& num_of_empl)
{
    std::cout << "Sending to file" << std::endl;
    if(!of_file.is_open())
    {
        std::cerr << "Problem with file" << file_name << std::endl;
    }
    else
    {
        for(int it = num; it < num_of_empl; it++)
        {
            array[it] -> write_all(of_file);
        }
        
    }
    of_file.close();
}

void delete_memory(abstr_emp** array,const int& num)
{
    std::cout << "The program removes the allocated memory" << std::endl;
    for(int it = 0; it < num; it++)
    {
        delete array[it];
    }
}
