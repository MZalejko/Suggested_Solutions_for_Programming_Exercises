#include <iostream>
#include <fstream>
#include <cstdlib>



int main(int argc, char** argv)
{
    if(argc < 2 || argc > 2)
    {
        std::cerr << "Too many or too few arguments. Program will terminate." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream fout;

    fout.open(argv[1]);

    if(!fout.is_open())
    {
        std::cerr << "Problem with file " << argv[1]
                    << " Program terminates." << std::endl;
    }

    char input_char;

    std::cout << "Enter your string!" << std::endl;
    
    while(!std::cin.eof())
    {
        std::cin.get(input_char);
        fout << input_char;
        
    }

    std::cout << "All signs copied to your file." << std::endl;
    std::cout << "Thank you!" << std::endl; 

    fout.close();

    return EXIT_SUCCESS;
}