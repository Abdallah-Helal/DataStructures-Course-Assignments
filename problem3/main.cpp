#include <iostream>
#include "matrix.h"

using namespace std;
class matrixCalculator
{
public :
    template<class T>
    static matrix<T> ADD(matrix<T>a, matrix<T>b)
    {
        return (a+b) ;
    }
    template<class T>
    static matrix<T> subtract (matrix<T>a, matrix<T>b)
    {
        return a-b ;
    }
    template<class T>
    static matrix<T> multiply (matrix<T>a, matrix<T>b)
    {
        return a*b ;
    }
};
int main()
{
    cout << "Welcome to our Matrix Calculator\n" ;
    cout << "----------------------------------\n" ;
    cout << "1- Perform Matrix Addition\n" ;
    cout << "2- Perform Matrix Subtraction\n" ;
    cout << "3- Perform Matrix Multiplication\n" ;
    cout << "4- Matrix Transpose\n" ;
    int choice ;
    cin >> choice ;
    switch(choice)
    {
    case 1:
    {
        try
        {
            int x,y ;
            cout<< "enter the first matrix dimention :" ;
            cin >> x >> y ;
            matrix<int> a(x,y);
            cin >> a ;
            cout<< "enter the second matrix dimentions then enter the matrix :" ;
            cin >> x >> y ;
            matrix<int> b(x,y);
            cin >> b ;
            matrix<int> rslt=matrixCalculator::ADD(a,b);
            cout << "result:\n" << rslt ;
        }
        catch(const char *e)
        {
            cout << e ;
        }
        break;
    }
    case (2) :
    {
        try
        {
            int x,y ;
            cout<< "enter the first matrix dimention :" ;
            cin >> x >> y ;
            matrix<int> a(x,y);
            cin >> a ;
            cout<< "enter the second matrix dimentions then enter the matrix :" ;
            cin >> x >> y ;
            matrix<int> b(x,y);
            cin >> b ;
            matrix<int> rslt=matrixCalculator::subtract(a,b);
            cout << "result:\n" << rslt ;
        }
        catch(const char *e)
        {
            cout << e ;
        }
        break;
    }
    case (3) :
    {
        try
        {
            int x,y ;
            cout<< "enter the first matrix dimention :" ;
            cin >> x >> y ;
            matrix<int> a(x,y);
            cin >> a ;
            cout<< "enter the second matrix dimentions then enter the matrix :" ;
            cin >> x >> y ;
            matrix<int> b(x,y);
            cin >> b ;
            matrix<int> rslt=matrixCalculator::multiply(a,b);
            cout << "result:\n" << rslt ;
        }
        catch(const char *e)
        {
            cout << e ;
        }
        break;
    }
    case (4) :
    {
        int x,y ;
        cout<< "enter the matrix dimention :" ;
        cin >> x >> y ;
        matrix<int> m1(x,y);
        cout<< "enter the matrix :" ;
        cin >> m1 ;
        m1.transpose();
        cout << "matrix m1 trasposed \n" << "new m1:\n" << m1 ;
        break;
    }
}

    return 0;
}
