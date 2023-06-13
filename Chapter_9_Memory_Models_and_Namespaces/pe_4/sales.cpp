#include "sales.h"

    void SALES::setSales(Sales & s, const double *arr, int n){
        double min, max, total{0.0};
        std::cout<<"Setting sales values...\n";
        
        for(int i = 0; i < QUARTERS; i++){
            if(n > i){s.sales[i] = arr[i];}
            else{s.sales[i] = 0.0;}
            total += s.sales[i];
        }
        min = max = s.sales[0];
        for(int i = 0; i < n && i < QUARTERS; i++){
            if(min > s.sales[i]){min = s.sales[i];}
            if(max < s.sales[i]){max = s.sales[i];}
        }
        s.min = min;
        s.max = max;
        s.avarage = (n < QUARTERS) ? total/n : total/QUARTERS;
        std::cout<<"Done, thank you\n";

    }
    void SALES::setSales(Sales & s){
        std::cout<<"Enter values for 4 quarters: "<<std::endl;
        for(int i = 0; i < QUARTERS; i++){
            std::cout<<"Quarter nr "<<i+1<<" :";
            std::cin>>s.sales[i];
            std::cin.get();
            s.avarage += s.sales[i];
        }
        s.max = s.min = s.sales[0];
        s.avarage = s.avarage/QUARTERS;

        for(int i = 0; i < QUARTERS; i++){
            if(s.min > s.sales[i]){s.min = s.sales[i];}
            if(s.max < s.sales[i]){s.max = s.sales[i];}
        }
        std::cout<<"Done! Thank you!\n";
        
    }
    void SALES::showSales(const Sales & s){
        std::cout<<"Quarter results: \n";
        for(int i = 0; i < QUARTERS; i++){
            std::cout<<"Quarter nr "<<i+1<<" "<<std::endl;
            std::cout<<s.sales[i]<<std::endl;
        }
        std::cout<<"Avarage results: "<<s.avarage<<std::endl;
        std::cout<<"Max results: "<<s.max<<std::endl;
        std::cout<<"Min results: "<<s.min<<std::endl;
    }