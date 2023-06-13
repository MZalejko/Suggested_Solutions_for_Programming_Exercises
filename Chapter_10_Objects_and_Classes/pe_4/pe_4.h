#ifndef PE_4_H
#define PE_4_H

#include <iostream>

namespace SALES
{
    const int QUARTERS{4};
    class Sales{
    private:
        double sales[QUARTERS];
        double avarage;
        double max;
        double min;
    public:
        void setSales(const double *arr, int n);
        void setSales();
        void showSales()const;
    };
}

  


#endif