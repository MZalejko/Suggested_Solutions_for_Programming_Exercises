#include "sales.hxx"

Sales::Bad_index::Bad_index(int ix, const std::string exc_descr ) : std::logic_error(exc_descr), bindex_value(ix)
{

}

Sales::Sales(short yy)
{
    year = yy;
    for(int it = 0; it < MONTHS; it++)
    {
        gross[it] = 0;
    }
}

Sales::Sales(short yy, const double* gr, int n)
{
    year = yy;
    short limit = (n < MONTHS) ? n : MONTHS;
    for(int it = 0; it < limit; it++)
    {
        *(gross + it) = *(gr + it); 
    }
    for(int it = limit; it < MONTHS; it++)
    {
        *(gross + it) = 0;
    }
}

double Sales::operator[](int it) const
{
    if(it < 0 || it >= MONTHS)
        throw Bad_index(it);
    return gross[it];    
}

double& Sales::operator[](int it)
{
    if(it < 0 || it >= MONTHS)
        throw Bad_index(it);
    return gross[it];    
}

LabeledSales::NBad_index::NBad_index(const std::string& lbl, int ix, const std::string & exc_descr) : Sales::Bad_index(ix, exc_descr)
{
    bad_label = lbl;
}

LabeledSales::LabeledSales(const std::string& lbl, short yy) : Sales(yy)
{
    label = lbl;
}

LabeledSales::LabeledSales(const std::string& lbl, short yy, const double* gr, int n) : Sales(yy, gr, n)
{
    label = lbl;
}

double LabeledSales::operator[](int it) const
{
    if(it < 0 || it >= MONTHS)
        throw NBad_index(return_label(), it);
    return Sales::operator[](it);
}

double& LabeledSales::operator[](int it)
{
    if(it < 0 || it >= MONTHS)
        throw NBad_index(return_label(), it);
    return Sales::operator[](it);
}