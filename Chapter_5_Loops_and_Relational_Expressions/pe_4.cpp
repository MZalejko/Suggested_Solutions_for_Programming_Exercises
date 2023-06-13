#include <iostream>
#include <vector>

const double daphne_pr{0.1};
const double cleo_pr{0.05};

int main(){
    double daphne_sum{100.0},cleo_sum{100.0};
    double daphne_start{100.0};
    int years{0};
    std::vector <double> daphne_all(27);
    std::vector <double> cleo_all(27);
    do
    {
        daphne_sum += daphne_start * daphne_pr;
        cleo_sum += cleo_sum * cleo_pr;
        daphne_all[years] = daphne_sum;
        cleo_all[years] = cleo_sum;
        years++;
    }
    while(daphne_sum>cleo_sum);

    std::cout << "After " << years << " years Cleo had saved more as Daphne.\n";
    
    for(int i = 1; i <= years; i++)
    {
        std::cout << "After " << i << " year/s of saving: \n"
                 << "Daphne had saved: " << daphne_all[i-1] << " and Cleo had: " << cleo_all[i -1] << " !" << std::endl;
    }
    return 0;
}