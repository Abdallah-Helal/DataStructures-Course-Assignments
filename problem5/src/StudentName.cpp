#include "StudentName.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


StudentName::StudentName() :Name("") {}
StudentName::StudentName(string Name)
{
    int numOfSpace = 0, pos = 0;
    for (int i = 0; i < Name.length(); ++i)
    {
        if (Name[i] == ' ')
        {
            numOfSpace++;
            pos = i;
        }
    }
    if (numOfSpace == 0)
        this->Name = Name + " " + Name + " " + Name;
    else if (numOfSpace == 1)
        this->Name = Name + Name.substr(pos);
    else
        this->Name = Name;
}
void StudentName::print()
{
    vector <string> names;
    string name = "";
    cout << Name << endl;
    for (int i = 0; i < Name.size(); i++)
    {
        if (Name[i] == ' ')
        {
            names.push_back(name);
            name = "";
            continue;
        }
        else if (i == Name.size() - 1)
        {
            name += Name[i];
            names.push_back(name);
            break;
        }
        name += Name[i];
    }
    for (int i = 0; i < names.size(); i++)
        cout << names[i] << endl;
}
bool StudentName:: replace(int i, int j)
{
    vector <string> names;
    string name = "";
    for (int i = 0; i < Name.size(); i++)
    {
        if (Name[i] == ' ')
        {
            names.push_back(name);
            name = "";
            continue;
        }
        else if (i == Name.size() - 1)
        {
            name += Name[i];
            names.push_back(name);
            name = "";
            break;
        }
        name += Name[i];
    }

    if (i > names.size() || j > names.size())
        return false;
    else
    {
        swap(names[i - 1], names[j - 1]);
        int i = 0;
        for (; i < names.size()-1; i++)
            name += names[i] + " ";

        name += names[i];
        Name = name;
        return true;
    }
}
