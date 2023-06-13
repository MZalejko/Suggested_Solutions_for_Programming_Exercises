#include "pe_3.h"

Stock::Stock(){
    char temp[] = "without name";
    company = new char[strlen(temp) + 1];
    strcpy(company, temp);
    shares = 0;
    share_val = 0.0;
    set_tot();
}
Stock::Stock(const char* co, long n, double pr){
    company = new char[strlen(co) + 1];
    strcpy(company, co);
    if(n < 0){
        std::cout << "Number of shares can't be less than 0;" <<std::endl;
        std::cout << "I'm setting the number of shares in " << company << "for 0." << std::endl;
        shares = 0;
    }
    else{
        shares = n;
    }
    share_val = pr;
    set_tot();
    
    
}
Stock::~Stock(){
    delete [] company;
}
void Stock::buy(long num, double price){
    if(num < 0){
        std::cout << "The number of shares purchased cannot be less than 0;" <<std::endl;
        std::cout << "Transaction is aborted." << std::endl;
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price){
    if(num < 0){
        std::cout << "The number of shares sold cannot be less than 0;" <<std::endl;
        std::cout << "Transaction is aborted." << std::endl;
    }
    else if(num > shares){
        std::cout << "The number of shares sold cannot be greater than the shares held;" <<std::endl;
        std::cout << "Transaction is aborted." << std::endl;
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price){
    share_val = price;
    set_tot();
}
const Stock& Stock::topval(const Stock& s) const{
    if(s.total_val > total_val){
        return s;
    }
    else{
        return *this;
    }
}
std::ostream& operator<<(std::ostream& os, const Stock& s){
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize prec = std::cout.precision(3);
    std::cout << "Company: " << s.company << '\n'
              << " Number of shares: " <<s.shares << '\n'
              << " Price of the share: "<<s.share_val << " zl" << '\n';
    std::cout.precision(2);
    std::cout << " Total shares price: " << s.total_val << " zl" << '\n';
    std::cout.setf(orig, std::ios_base::floatfield);
    std::cout.precision(prec);          
    return os;
}