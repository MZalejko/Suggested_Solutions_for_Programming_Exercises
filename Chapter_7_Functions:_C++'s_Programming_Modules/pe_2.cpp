#include <iostream>
#include <vector>
#include <cctype>

constexpr int size{10};

void enter_datas(std::vector<double> &a);
void show_datas(const std::vector<double> &a, double m);
double mean(const std::vector<double> &a);

int main(void){

    std::vector<double> results(size);
    double mean_resaults{0};

    enter_datas(results);
    mean_resaults = mean(results);
    show_datas(results, mean_resaults);


    return 0;
}

void enter_datas(std::vector<double> &a){
    double temp{};
    for(int i = 0; i < size; i++){
        if(std::cin>>temp){
            a[i] = temp;
            std::cin.get();
        }
        else{
            a.resize(i);
            break;
        }
        
    }
}
void show_datas(const std::vector<double> &a, double m){
    for(int i = 0; i < a.size(); i++){
        std::cout<<"Resault nr "<<i+1<<' '<<a[i]<<' ';
    }
    std::cout<<'\n';
    std::cout<<"The mean of all resaults: "<<m<<std::endl;
}
double mean(const std::vector<double> &a){
    double temp{0};
    for(int i = 0; i < a.size(); i++){
        temp += a[i];
    }
    return temp/a.size();
}