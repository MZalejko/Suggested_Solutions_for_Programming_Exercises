#ifndef SALES_H
#define SALES_H
#include <iostream>

namespace SALES
{
    const int QUARTERS{4};
    struct Sales{
        double sales[QUARTERS];
        double avarage;
        double max;
        double min;
    };
    void setSales(Sales & s, const double *arr, int n);
    void setSales(Sales & s);
    void showSales(const Sales & s);
}

#endif