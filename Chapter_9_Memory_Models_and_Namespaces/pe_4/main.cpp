#include "sales.h"

int main(){
    double res_y_2[3]{13673.4, 34586.3, 98536.6};
    SALES::Sales Year1;
    SALES::Sales Year2;

    SALES::setSales(Year1);
    SALES::setSales(Year2, res_y_2 , 3);

    SALES::showSales(Year1);
    SALES::showSales(Year2);

    return 0;
}