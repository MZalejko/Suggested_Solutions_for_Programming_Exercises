#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>

constexpr const char* list_name{"mat_and_pat_list.dat"};
constexpr const char* pat_list{"patlist.dat"};
constexpr const char* mat_list{"matlist.dat"};

inline bool check_if_open(const std::ofstream& offile){if(offile.is_open()){return true;} else{return false;}};
inline bool check_if_open(const std::ifstream& iffile){if(iffile.is_open()){return true;} else{return false;}};

void enter_names(std::ifstream& file, std::list<std::string>& list);
inline void show_list(const std::list<std::string>& list_to_show) {for(auto it: list_to_show) std::cout << it << std::endl;};
void copy_to_list(std::list<std::string>& list, std::list<std::string>& complete_list);
void create_new_file(std::list<std::string>& list, std::ofstream& new_list);
void send_string(const std::string& str, std::ofstream& new_list);

int main(int argc, char** argv)
{

    std::ifstream input_stream;
    std::ofstream output_stream;

    std::list<std::string> names_list;
    std::list<std::string> all_names_list;

    input_stream.open(pat_list);
    output_stream.open(list_name);

    if(!input_stream.is_open() || !output_stream.is_open())
    {
        std::cerr << "We've had a problem to open one of your files. Program terminates." << std::endl;
        exit(EXIT_FAILURE);
    }

    enter_names(input_stream, names_list);
    names_list.sort();
    show_list(names_list);

    copy_to_list(names_list, all_names_list);
    names_list.clear();

    input_stream.close();
    input_stream.open(mat_list);

    if(!input_stream.is_open())
    {
        std::cerr << "We've had a problem to open your file. Program terminates." << std::endl;
        exit(EXIT_FAILURE);
    }

    enter_names(input_stream, names_list);
    names_list.sort();
    show_list(names_list);

    copy_to_list(names_list, all_names_list);
    all_names_list.sort();
    all_names_list.unique();

    create_new_file(all_names_list, output_stream);

    std::cout << "Done!" << std::endl;

    input_stream.close();
    output_stream.close();



    return EXIT_SUCCESS;
}

void enter_names(std::ifstream& file, std::list<std::string>& list)
{
    std::string temp_name;
    std::cout << "Entering the names" << std::endl;
    while(!file.eof())
    {
        if(temp_name[0] == '\n')
        {
            continue;
        }
        std::getline(file, temp_name, '\n');
        list.push_back(temp_name);
    }
}

void copy_to_list(std::list<std::string>& list, std::list<std::string>& complete_list)
{
    complete_list.merge(list);

}

void create_new_file(std::list<std::string>& set, std::ofstream& new_list)
{
    for(auto it: set)
    {
        send_string(it, new_list);
    }
}

void send_string(const std::string& str, std::ofstream& new_list)
{
    for(auto it: str)
    {
        new_list.put(it);
    }
    new_list.put('\n');
}