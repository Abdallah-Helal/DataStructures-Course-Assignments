#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#ifndef BIGINT_H
#define BIGINT_H


class BigInt
{
    string num;
    string Onum; //original number to reset num after the operations
    BigInt operator-(BigInt ob);
public:

    BigInt();
    BigInt(string str);
    BigInt(int number);

    int size();
    BigInt operator+(BigInt ob);

    friend ostream& operator<< (ostream& output, BigInt ob);


    friend bool removeSign(BigInt& ob);
    friend int checkNum(string s1, string s2);
    friend void removezeros(string& s);


};

#endif // BIGINT_H
