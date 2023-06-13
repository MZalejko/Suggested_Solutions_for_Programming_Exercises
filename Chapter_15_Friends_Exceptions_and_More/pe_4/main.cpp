#include "sales.hxx"


int main()
{
    double vals1[NUM_OF_MONTHS]
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[NUM_OF_MONTHS]
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 25
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    std::cout << "First try block" << std::endl;

    try
    {
        std::cout << "Year: " << sales1.return_year() << std::endl;

        for(int it = 0; it < NUM_OF_MONTHS ; it++)
        {
            std::cout << sales1[it] <<" ";
            if(it % 6 == 5) {std::cout << std::endl;}
        }

        std::cout << "Year: " << sales2.return_year() << std::endl;
        std::cout << "Label: " << sales2.return_label() << std::endl;
        for(int it = 0; it < NUM_OF_MONTHS ; it++)
        {
            std::cout << sales2[it] << " ";
            if(it % 6 == 5) {std::cout << std::endl;}
        }
        std::cout << "End of the first try block" << std::endl;
    }
    catch(Sales::Bad_index & bd)
    {
        std::cout << bd.what();
        if(typeid(LabeledSales::NBad_index &) == typeid(bd))
        {
            LabeledSales::NBad_index & nbd = dynamic_cast<LabeledSales::NBad_index &>(bd);
            std::cout << "Company: " << nbd.lbl_value() << std::endl;
        }
        std::cout << "Index value:  " << bd.return_bindexvalue() << std::endl;
    }

    std::cout << "Second try block: \n";

    try
    {
        sales1[2] = 37.5;
        sales2[20] = 23345;
        std::cout << "End of the second try block" << std::endl;
    }
    catch(Sales::Bad_index & bd)
    {
        std::cout << bd.what() << std::endl;
        
        if(typeid(LabeledSales::NBad_index &) == typeid(bd))
        {
            LabeledSales::NBad_index & nbd = dynamic_cast<LabeledSales::NBad_index &>(bd);
            std::cout << "Company: " << nbd.lbl_value() << std::endl;
        }
        std::cout << "Index value: " << bd.return_bindexvalue() << std::endl;
    }




    return 0;
}