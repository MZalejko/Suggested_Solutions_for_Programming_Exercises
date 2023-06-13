#include <iostream>
#include <cstdlib>
#include <fstream>

constexpr short needed_num_of_args{3};

bool check_arguments(int num_of_args);

int main(int argc, char** argv)
{

    std::ifstream fin;
    std::ofstream fout;
    char temp_char;

    if(check_arguments(argc))
    {
        exit(EXIT_FAILURE);
    }

    std::cout << "Program is going to copy all signs from file " << argv[1] << std::endl;
    std::cout << "To file " << argv[2] << std::endl;

    fin.open(argv[1]);
    fout.open(argv[2]);

    if(!fin.is_open() || !fout.is_open())
    {
        std::cerr << "We can't open one of your files. Program terminates." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Coping your files..." << std::endl;

    while(!fin.eof())
    {
        fin.get(temp_char);
        fout.put(temp_char);
    }

    std::cout <<"Everything is done!" << std::endl;
    std::cout <<"Thank you!" << std::endl;

    fin.close();
    fout.close();
    return EXIT_SUCCESS;
}

bool check_arguments(int num_of_args)
{
    if(num_of_args != needed_num_of_args)
    {
        std::cerr << "Too many or too few arguments in command line."
                    <<" We need two files! Program will termniate" << std::endl;
        return true;
    }
    return false;
}