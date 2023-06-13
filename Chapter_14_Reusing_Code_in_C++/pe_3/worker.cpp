#include "worker.hxx"

#include <iostream>

void clearBuffor(){
    
    while(std::cin.get() != '\n'){
        continue;
    }
}

Worker::~Worker() {}
 
void Worker::Data() const{
    
    std::cout << "Name and Surname: " << fullName << std::endl;
    std::cout << "ID number: " << id << std::endl;
}

void Worker::Get(){

    getline(std::cin, fullName);
    std::cout << "Enter the ID number: ";
    std::cin >> id;
    clearBuffor();
}

void Waiter::Data() const{
    
    std::cout << "Elegance: " << panache << std::endl;
}

void Waiter::Get(){
    
    std::cout << "Enter waiter's panache rating: " << std::endl;
    std::cin >> panache;
    clearBuffor();

}

void Waiter::Set(){
    
    Worker::Get();
    Get();
}

void Waiter::Show() const{
    
    Worker::Data();
    Data();
}

const char* Singer::pv[Singer::voiceTypes]={"other", "alt", "kontralt", "sopran", "bas", "baryton", "tenor"};

void Singer::Data() const{
    
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}

void Singer::Get(){
    
    std::cout << "Enter a number for singer vocal range: " << std::endl;

    for(int it = 0; it < numOfVoices; it++){
        
        std::cout << it << ": " << pv[it] << " ";
        if(it % 4 == 3){
            std::cout << "\n\n";
        }
    }

    std::cin >> voice;
    clearBuffor();
    
}

void Singer::Set(){
    
    Worker::Get();
    Get();
}

void Singer::Show() const{
    
    Worker::Data();
    Data();
}

void SingingWaiter::Data() const{
    
    Waiter::Data();
    Singer::Data();
}
void SingingWaiter::Get(){
    
    Waiter::Get();
    Singer::Get();
}
void SingingWaiter::Set(){
    
    std::cout << "Enter name and surname of the singing waiter: " << std::endl;
    Worker::Get();
    Get();
}
void SingingWaiter::Show() const{
    
    std::cout << "Category: SingingWaiter\n";
    Worker::Data();
    Data();
}