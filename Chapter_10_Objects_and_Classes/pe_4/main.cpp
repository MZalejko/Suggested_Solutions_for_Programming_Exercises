#include "pe_4.h"

int main(){

    double res_y_2[3]{13673.4, 34586.3, 98536.6};
    SALES::Sales Year1;
    SALES::Sales Year2;

    Year1.setSales();
    Year2.setSales(res_y_2 , 3);

    Year1.showSales();
    Year2.showSales();

    return 0;
}