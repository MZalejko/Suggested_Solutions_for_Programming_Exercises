#include "pe_7.hxx"

Store& Store::operator()(const std::string& str)
{

    std::size_t len = str.length();
    ofstrm -> write((char*)&len, sizeof(std::size_t));
    ofstrm -> write(str.data(), len);
    return *this;
}

void ShowStr(const std::string& str)
{
    std::cout << str << std::endl;
}
void GetStrs(std::ifstream& fin, std::vector<std::string>& vect_str)
{
    std::size_t len;
    std::string temp;
    char ch;
    while(fin.peek() && !fin.eof())
    {
        fin.read((char*) &len, sizeof(std::size_t));
        for(std::size_t it = 0; it < len; it++)
        {
            fin.read(&ch, sizeof(char));
            temp.push_back(ch);
        }
        vect_str.push_back(temp);
        temp.clear();
    }
}
