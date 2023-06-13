#include <iostream>
#include <string>

class Bank_A{

    private:
        std::string fullname;
        std::string account_num;
        double saldo;
    public:
        Bank_A(std::string a_name = "New_Client", std::string acc_n = "11 1111 1111 1111 1111 1111 1111 1111", double acc_sl = 0.0){
            fullname = a_name;
            account_num = acc_n;
            saldo = acc_sl;
        };
        ~Bank_A(){};
        void show_name(){
            std::cout<<"Client's name: "<<fullname<<std::endl;
            std::cout<<"Client's account number: "<<account_num<<std::endl;
            std::cout<<"Account saldo: "<<saldo<<std::endl;
        }
        void cash_deposit(double depo){
            saldo += depo;
            std::cout<<depo<<" successful stored.\n";
            std::cout<<"Current account saldo: "<<saldo<<std::endl;
        }
        void cash_withdraw(double withd){
            char choose;
            std::cout<<"Would you really like to withdraw "<<withd<<" from your account(Y/n)? ";
            std::cin.get(choose);
            if(choose == 'Y' || choose == 'y'){
                saldo -= withd;
                std::cout<<"Withdraw successful. Thank you.\n";
            }
            else{
                std::cout<<"Whitdraw aborted.\n";
            }
        }



};


int main(){
    Bank_A first;
    Bank_A second("Adam Nowak", "25 2763 2789 9999 0000 0001 7865", 2600.0);
    first.show_name();
    second.show_name();
    first.cash_deposit(2500.5);
    second.cash_deposit(10000);
    first.cash_withdraw(1000.0);


    return 0;
}