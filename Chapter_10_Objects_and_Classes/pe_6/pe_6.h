#ifndef PE_6_H
#define PE_6_H
#include <iostream>


class Move{

    private:

        double x;
        double y;

    public:
        Move(double a = 0, double b = 0);
        ~Move();
        void showmove() const;
        Move add(const Move& m);
        void reset(double a = 0, double b = 0);


};


#endif