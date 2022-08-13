#include "fraction.h"

fraction::fraction()
{
    //ctor
}
fraction::fraction(int n, int d):numerator(n),denominator(d)
{
    //ctor
}
fraction::fraction (double x)
{
    double n = x ;
    while (n != (int) n)
        n*=10 ;
    denominator = n/x ;
    numerator = n ;
    reduce() ;
}


fraction::~fraction()
{
    //dtor
}

void fraction::reduce ()
{
    for (int i=2 ; i<= min(abs(numerator), denominator) ; i++)
        while (numerator%i==0 && denominator%i ==0)
        {
            numerator/=i;
            denominator /=i ;
        }
}
int fraction::getnum ()
{
    return numerator ;
}
int fraction::getden ()
{
    return denominator ;
}
fraction fraction::operator+ (fraction obj)
{
    fraction temp;
    temp.numerator = numerator*obj.getden() + obj.getnum()*denominator ;
    temp.denominator = denominator*obj.getden() ;
    temp.reduce() ;
    return temp ;
}
fraction fraction::operator- (fraction obj)
{
    fraction temp;
    temp.numerator = numerator*obj.getden() - obj.getnum()*denominator ;
    temp.denominator = denominator*obj.getden() ;
    temp.reduce() ;
    return temp ;
}

fraction fraction::operator* (fraction obj)
{
    fraction temp;
    temp.numerator = numerator*obj.getnum() ;
    temp.denominator = denominator*obj.getden() ;
    temp.reduce() ;
    return temp ;
}
fraction fraction::operator/ (fraction obj)
{
    fraction temp;
    temp.numerator = numerator*obj.getden() ;
    temp.denominator = denominator*obj.getnum() ;
    temp.reduce() ;
    return temp ;
}

fraction fraction::operator> (fraction obj)
{
    return (numerator*obj.getden() > obj.getnum() * denominator) ;
}
fraction fraction::operator< (fraction obj)
{
    return (numerator*obj.getden() < obj.getnum() * denominator) ;
}
fraction fraction::operator== (fraction obj)
{
    return (numerator == obj.getnum() && denominator == obj.getden()) ;
}
fraction fraction::operator>= (fraction obj)
{
    return (numerator*obj.getden() >= obj.getnum() * denominator) ;
}
fraction fraction::operator<= (fraction obj)
{
    return (numerator*obj.getden() <= obj.getnum() * denominator) ;
}
ostream& operator << (ostream & os, fraction obj)
{
    os << obj.numerator << '/' << obj.denominator ;
    return os ;
}
istream& operator >> (istream & is, fraction obj)
{
    is >> obj.numerator >> obj.denominator ;
    return is ;
}
