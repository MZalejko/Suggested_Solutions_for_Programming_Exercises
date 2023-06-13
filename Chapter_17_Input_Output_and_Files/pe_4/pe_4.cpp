#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

inline bool check_if_open(const std::ofstream& offile){if(offile.is_open()){return true;} else{return false;}};
inline bool check_if_open(const std::ifstream& iffile){if(iffile.is_open()){return true;} else{return false;}};
void copy_function(std::ifstream& first, std::ifstream& second, std::ofstream& output_file);

int main(int argc, char** argv)
{
    std::ifstream first_input;
    std::ifstream second_input;
    std::ofstream first_output;

    first_input.open("first.txt");
    second_input.open("second.txt");
    first_output.open("combined.txt");

    if(!check_if_open(first_input) || !check_if_open(second_input) || !check_if_open(first_output))
    {
        std::cerr << "We have problem to open one of your files. Program will termiante." << std::endl;
        exit(EXIT_FAILURE);
    }

    copy_function(first_input, second_input, first_output);

    first_input.close();
    second_input.close();
    first_output.close();

    first_input.open("combined.txt");
    if(!check_if_open(first_input))
    {
        std::cerr << "Problem with output file." << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        while(!first_input.eof())
        {
            std::cout << (char) first_input.get();
        }
    }

    first_input.close();

    return EXIT_SUCCESS;
}

void copy_function(std::ifstream& first, std::ifstream& second, std::ofstream& output_file)
{
    std::cout << "Start to copy!" << std::endl;
    
    while(!first.eof() || !second.eof())
    {       
            std::string temp;
            
            if(!first.eof())
            {
                std::cout << "Copy first" << std::endl;
                std::getline(first, temp, '\n');
                output_file.put('\n');

                for(auto it: temp)
                {
                    output_file.put(it);
                }
            }
            
            if(!second.eof())
            {
                std::cout << "Copy second" << std::endl;
                std::getline(second, temp, '\n');
                output_file.put('\n');

                for(auto it: temp)
                {
                    output_file.put(it);
                }
            }
    
    }


    if(first.bad() || second.bad())
    {
        std::cerr << "We couldn't copy all of your files, because of one of the inputs files." << std::endl;
    }
    else if(output_file.bad())
    {
         std::cerr << "We couldn't copy all of your files, because of output file." << std::endl;
    }
    else
    {
        std::cout << "Process is completed! Thank you!" << std::endl;
    }
}