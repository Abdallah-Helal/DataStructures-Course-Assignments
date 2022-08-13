#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std ;

class fraction
{
    public:
        fraction();
        fraction(int , int );
        fraction(double );
        virtual ~fraction();
        int getnum ();
        int getden () ;
        fraction operator+ (fraction obj);
        fraction operator- (fraction obj);
        fraction operator* (fraction obj);
        fraction operator/ (fraction obj);
        friend istream& operator >> (istream & is, fraction obj) ;
        friend ostream& operator << (ostream & os, fraction obj) ;
        fraction operator> (fraction obj) ;
        fraction operator< (fraction obj) ;
        fraction operator== (fraction obj) ;
        fraction operator>= (fraction obj) ;
        fraction operator<= (fraction obj) ;

    protected:

    private:
        int numerator;
        int denominator;
        void reduce ();
};

#endif // FRACTION_H
