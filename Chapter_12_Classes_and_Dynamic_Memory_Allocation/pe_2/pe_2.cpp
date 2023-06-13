#include "pe_2.h"

int String::num_strings = 0;

String::String(const char* st){
    len = strlen(st);
    str = new char[len+1];
    strcpy(str, st);
    num_strings++;
}    
String::String(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
String::String(const String& st_cop){
    len = st_cop.len;
    str = new char[len+1];
    strcpy(str, st_cop.str);
    num_strings++;

}
String::~String(){
    --num_strings;
    delete [] str;
}
String& String::operator=(const String& st_cop){
    if(this == &st_cop){
        return *this;
    }
    delete [] str;
    len = st_cop.len;
    str = new char[len+1];
    strcpy(str, st_cop.str);
    return *this;
}
String& String::operator=(const char* st){
    delete [] str;
    if(strlen(st) > CINLIM){
        len = CINLIM;
    }
    else{
        len = strlen(st);
    }
    str = new char[len + 1];
    strcpy(str, st);
    return *this;
}
char& String::operator[](int i){
    return str[i];
}
const char& String::operator[](int i) const{
    return str[i];
}
String String::operator+(const String& st) const{
    String temp;
    int temp_len = strlen(str) + strlen(st.str);
    int add_len{0};
    if(temp_len > CINLIM){
        temp.str = new char[CINLIM + 1];
        add_len = CINLIM - strlen(str);
        strcpy(temp.str, str);
        strncat(temp.str, st.str, add_len);
        temp.len = strlen(temp.str);
    }
    else{
        temp.str = new char[temp_len + 1];
        strcpy(temp.str, str);
        strcat(temp.str, st.str);
        temp.len = strlen(temp.str);
    }

    return temp;
}
String String::operator+(const char* st) const{
    String temp(st);
    // int temp_len = strlen(str) + strlen(st);
    // int add_len{0};
    // if(temp_len > CINLIM){
    //     temp.str = new char[CINLIM + 1];
    //     add_len = CINLIM - strlen(str);
    //     strcpy(temp.str, str);
    //     strncat(temp.str, st, add_len);
    //     temp.len = strlen(temp.str);
    // }
    // else{
    //     temp.str = new char[temp_len + 1];
    //     strcpy(temp.str, str);
    //     strcat(temp.str, st);
    //     temp.len = strlen(temp.str);
    // }

    // return temp;
    return String(*this + temp);
}
String operator+(const char* st, const String& st_2){
    return String(st) + st_2;
}
String& String::stringlow(){
    for(int i = 0; i < strlen(str); i++){
        if(isupper(str[i])){
            str[i] = tolower(str[i]);
        }
    }
    return *this;
}
String& String::stringup(){
    for(int i = 0; i < strlen(str); i++){
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        }
    }
    return *this;
}
int String::Num_of_char(char c){
    int temp_num_of_char{0};
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c){
            temp_num_of_char++;
        }
    }
    return temp_num_of_char;
}
bool operator<(const String& st, const String& st2){
    return (strcmp(st.str, st2.str) < 0);
}
bool operator>(const String& st, const String& st2){
    return st2< st;
}
bool operator==(const String& st, const String& st2){
    return (strcmp(st.str, st2.str) == 0);
}
std::ostream& operator<<(std::ostream& os, const String& st){
    os << st.str;
    return os;
}
std::istream& operator>>(std::istream& is, String& st){
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st = temp;
    while(is && is.get() != '\n')
        continue;
    return is;

}
