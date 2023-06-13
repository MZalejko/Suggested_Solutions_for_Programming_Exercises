#include "pe_7.hxx"



int main()
{

    std::vector<std::string> vostr;
    std::string temp;

    //acquire strings

    std::cout << "Enter strings (empty line to quit): " << std::endl;
    while(getline(std::cin, temp) && temp[0] != '\0')
    {
        vostr.push_back(temp);
    }
    std::cout << "Here is your input: " << std::endl;
    std::for_each(vostr.begin(), vostr.end(), ShowStr);

    //store in the file

    std::ofstream fout(file_name, std::ios_base::out | std::ios_base::binary);
    std::for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file content

    std::vector<std::string> vistr;
    std::ifstream fin(file_name, std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open())
    {
        std::cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    std::cout << "\nHere are the strings read from the file:\n";
    std::for_each(vistr.begin(), vistr.end(), ShowStr);
    
    return EXIT_SUCCESS;
}