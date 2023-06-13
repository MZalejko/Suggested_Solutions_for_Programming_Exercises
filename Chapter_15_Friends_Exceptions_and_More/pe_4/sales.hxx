#ifndef SALES_HXX
#define SALES_HXX

#include <iostream>
#include <string>
#include <stdexcept>

#define NUM_OF_MONTHS 12

constexpr const char* mistake_Sales_descr{"Incorrect index in Sales class object\n"};
constexpr const char* mistake_LabeledSales_descr{"Incorrect index in LabeledSales class object\n"};
constexpr const char* default_lbl{"None"};

class Sales 
{
    public:
        enum {MONTHS = NUM_OF_MONTHS};
        class Bad_index : public std::logic_error
        {
            private:
                int bindex_value;
            public:
                explicit Bad_index(int ix, const std::string exc_descr = mistake_Sales_descr);
                int return_bindexvalue() const { return bindex_value;};
                virtual ~Bad_index() throw() {};
        };
        explicit Sales(short yy = 0);
        Sales(short yy, const double* gr, int n);
        virtual ~Sales() {};
        short return_year() const {return year;};
        virtual double operator[](int it) const;
        virtual double& operator[](int it);
    private:
        double gross[MONTHS];
        short year;
};

class LabeledSales : public Sales
{
    public:
        class NBad_index : public Sales::Bad_index
        {
            private:
                std::string bad_label;
            public:
                NBad_index(const std::string& lbl, int ix, const std::string & exc_descr = mistake_LabeledSales_descr);
                const std::string& lbl_value() const {return bad_label;};
                virtual ~NBad_index() throw() {};
        };
        explicit LabeledSales(const std::string& lbl = default_lbl, short yy = 0);
        LabeledSales(const std::string& lbl, short yy, const double* gr, int n);
        virtual ~LabeledSales() {};
        const std::string& return_label() const {return label;};
        virtual double operator[](int it) const;
        virtual double& operator[](int it);
    private:
        std::string label;

};




#endif //SALES_HXX