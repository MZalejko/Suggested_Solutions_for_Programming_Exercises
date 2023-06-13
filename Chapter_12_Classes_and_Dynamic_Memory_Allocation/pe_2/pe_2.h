#ifndef PE_2_H
#define PE_2_H
#include <iostream>
#include <cstring>
#include <cctype>

class String{

    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String(const char* st);
        String();
        String(const String& st_cop);
        ~String();
        int length(){return len;};
        String& operator=(const String& st_cop);
        String& operator=(const char* st);
        char& operator[](int i);
        const char& operator[](int i) const;
        String operator+(const String& st) const;
        String operator+(const char* st) const;
        friend String operator+(const char* st, const String& st_2);
        String& stringlow();
        String& stringup();
        int Num_of_char(char c);
        friend bool operator<(const String& st, const String& st2);
        friend bool operator>(const String& st, const String& st2);
        friend bool operator==(const String& st, const String& st2);
        friend std::ostream& operator<<(std::ostream& os, const String& st);
        friend std::istream& operator>>(std::istream& is, String& st);
        static int HowMany(){return num_strings;};

};



#endif //PE_2_H
