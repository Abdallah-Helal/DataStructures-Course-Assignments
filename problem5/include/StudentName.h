#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef STUDENTNAME_H
#define STUDENTNAME_H


using namespace std;

class StudentName
{
private:
    string Name;
public:
    StudentName()  ;
    StudentName(string Name);
    void print();
    bool replace(int i, int j);
};
#endif // STUDENTNAME_H
