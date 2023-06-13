#ifndef PE_2_H
#define PE_2_H
#include <iostream>

namespace VECTOR
{
    class Vector{
        public:
            enum Mode{RECT, POL};
        private:
            double x;
            double y;
            Mode mode;
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval(){return x;}
            double yval(){return y;}
            double magval() const;
            double angval() const;
            void polar_mode(); 
            void rect_mode();
            Vector operator+(const Vector &b) const;
            Vector operator-(const Vector &b) const;
            Vector operator-() const;
            Vector operator*(double n) const;
            friend Vector operator*(double n, const Vector &b);
            friend std::ostream & operator<<(std::ostream& os, const Vector &b);

    };
} // namespace VECTOR

#endif //ZAD_2_H