#include "pe_4.h"

    void SALES::Sales::setSales(const double *arr, int n){
        double min_t, max_t, total{0.0};
        std::cout<<"Setting sales values...\n";
        
        for(int i = 0; i < QUARTERS; i++){
            if(n > i){sales[i] = arr[i];}
            else{sales[i] = 0.0;}
            total += sales[i];
        }
        min_t = max_t = sales[0];
        for(int i = 0; i < n && i < QUARTERS; i++){
            if(min_t > sales[i]){min_t = sales[i];}
            if(max_t < sales[i]){max_t = sales[i];}
        }
        min = min_t;
        max = max_t;
        avarage = (n < QUARTERS) ? total/n : total/QUARTERS;
        std::cout<<"Done, thank you\n";

    }
    void SALES::Sales::setSales(){
        std::cout<<"Enter values for 4 quarters: "<<std::endl;
        for(int i = 0; i < QUARTERS; i++){
            std::cout<<"Quarter nr "<<i+1<<" :";
            std::cin>>sales[i];
            std::cin.get();
            avarage += sales[i];
        }
        max = min = sales[0];
        avarage = avarage/QUARTERS;

        for(int i = 0; i < QUARTERS; i++){
            if(min > sales[i]){min = sales[i];}
            if(max < sales[i]){max = sales[i];}
        }
        std::cout<<"Done! Thank you!\n";
        
    }
    void SALES::Sales::showSales() const{
        std::cout<<"Quarter results: \n";
        for(int i = 0; i < QUARTERS; i++){
            std::cout<<"Quarter nr "<<i+1<<" "<<std::endl;
            std::cout<<sales[i]<<std::endl;
        }
        std::cout<<"Avarage results: "<<avarage<<std::endl;
        std::cout<<"Max results: "<<max<<std::endl;
        std::cout<<"Min results: "<<min<<std::endl;
    }