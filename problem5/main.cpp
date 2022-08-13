#include <iostream>
#include <vector>
#include <string>
#include "StudentName.h"
using namespace std;
/*

 Abdallah Emad      20200323
 Mostafa mohamed     20200544

*/

int main()
{
    /*********************test1****************************/
    StudentName stu1("Abdallah Emad Helal");
    stu1.print();     //before replace

    if (stu1.replace(1, 2))
        stu1.print();   //after replace
    else
        cout << "out of range";

    cout << endl;

    /*********************test2****************************/
    StudentName stu2("Mostafa Mohamed Ali");
    stu2.print();

    if (stu2.replace(3, 2))
        stu2.print();
    else
        cout << "out of range";

    cout << endl;

    /*********************test3****************************/
    StudentName stu3("Adam Ahmed");
    stu3.print();

    if (stu3.replace(1, 3))
        stu3.print();
    else
        cout << "out of range";

    cout << endl;

    /*********************test4****************************/
    StudentName stu4("Sayed");
    stu4.print();

    if (stu4.replace(1, 5))
        stu4.print();
    else
        cout << "out of range" << endl;

    cout << endl;
    /*********************test5****************************/

    StudentName stu5("Ahmed Nashat");
    stu5.print();

    if (stu5.replace(5, 1))
        stu5.print();
    else
        cout << "out of range";

    cout << endl;
    return 0;
}
