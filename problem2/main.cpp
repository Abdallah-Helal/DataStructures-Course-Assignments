#include <iostream>
#include "fraction.h"

using namespace std;
class FractionCalculator
{
public :
    static fraction add (fraction m1 , fraction m2)
    {
        return m1+m2 ;
    }
    static fraction subtract (fraction m1 , fraction m2)
    {
        return m1-m2 ;
    }
    static fraction multiply (fraction m1 , fraction m2)
    {
        return m1*m2 ;
    }
    static fraction divide (fraction m1 , fraction m2)
    {
        return m1/m2 ;
    }
    static fraction show_as_fraction (double m)
    {
        fraction x(m) ;
        return x ;
    }
    FractionCalculator() {}
    ~FractionCalculator() {}


};
int main()
{
    cout << "Welcome to our fraction Calculator\n" ;
    cout << "----------------------------------\n" ;
    cout << "1- Perform fraction Addition\n" ;
    cout << "2- Perform fraction Subtraction\n" ;
    cout << "3- Perform fraction Multiplication\n" ;
    cout << "4- Perform fraction division\n" ;
    cout << "5- turn float to fraction\n" ;
    int choice ; cin >> choice ;
    double x ,y ;
    switch(choice) {
        case (1) :
        {
            cout << "Enter two float numbers" << endl;
            cin >> x >> y ;
            fraction m1(x) , m2(y) ;
            cout << "sum =" << FractionCalculator::add(m1,m2) << endl;
            break;
        }
        case (2) :
        {
            cout << "Enter two float numbers" << endl;
            cin >> x >> y ;
            fraction m1(x) , m2(y) ;
            cout  << "difference =" << FractionCalculator::subtract(x,y) <<endl;
            break;
        }
        case 3 :
        {
            cout << "Enter two float numbers" << endl;
            cin >> x >> y ;
            fraction m1(x) , m2(y) ;
            cout << "multiplication =" << FractionCalculator::multiply(x,y) << endl;
            break;
        }
        case 4 :
        {
            cout << "Enter two float numbers" << endl;
            cin >> x >> y ;
            fraction m1(x) , m2(y) ;
            cout << "division =" << FractionCalculator::divide(x,y) << endl;
            break;
        }
        case 5 :
            {
            cout << "Enter the float number" << endl;
            cin >> x ;
            cout << x << " = " << FractionCalculator::show_as_fraction(x) << endl;
            break;
        }
}

    return 0;
}
