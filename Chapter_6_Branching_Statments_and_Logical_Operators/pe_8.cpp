#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

constexpr int size{200};

int main(){

    int counter{0};
    char tab1[size];
    char temp;

    std::ifstream from_file;


    from_file.open("zad_8.txt");
    if(!from_file.is_open()){
        exit(EXIT_FAILURE);
    }
    from_file.get(temp);
    while(counter < size){
        *(tab1 + counter) = temp;
        from_file.get(temp);
        counter++;
        if(from_file.eof()){
            std::cout<<"End of File(EOF)\n";
            from_file.get();
            break;    
        }
        else if(from_file.fail()){
            std::cout<<"Loading aborted. Unknown mistake.\n";
            from_file.get();
            break;
        }
    }
    
    if(counter){
        std::cout<<"Number of loaded elements: "<<counter<<std::endl;
    }
    else{
        std::cout<<"Loaded 0!"<<std::endl;
    }
    std::cout<<tab1<<std::endl;

    from_file.close();
    return 0;
}