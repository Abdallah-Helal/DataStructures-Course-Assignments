#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include"BigInt.h"
using namespace std;

int main()
{
    BigInt num(222);
    BigInt num1(3000);
    cout << num + num1 << endl;

    cout << "size: " << num1.size() << endl;
    /************************************************/
    BigInt num2("123456789012345678901234567890");
    BigInt num3("113456789011345678901134567890");
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num2 << endl;

    BigInt num4 = num2 + num3;
    cout << "num2 + num3 = " << num4 << endl;


    cout << "num3 + num4= " << num3 + num4 << endl;

    /************************************************/

    BigInt num6("-555555555555555555555555555555");
    BigInt num7("-555555555555555555555555555555");
    cout << "num6 = " << num6 << endl;
    cout << "num7 = " << num7 << endl;

    BigInt num8 = num6 + num7;
    cout << "num6 + num7 = " << num8 << endl;

    BigInt num9(5555555);
    cout << "num9" << num9 << endl;
    cout << "num8 + num9 = " << num8 + num9 << endl;



    return 0;
}
