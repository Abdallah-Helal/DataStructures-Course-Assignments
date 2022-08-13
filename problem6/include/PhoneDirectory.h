#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H


class PhoneDirectory
{
              // firstname lastname phone
    vector<pair<pair<string,string>,string>>Names;
public:
    void addNewEntry();
    int searchByPhone();
    int searchByFirstName();
    void deleteByFirstName();
    void printAt(int pos);
    void bubbleSort();
    void insertionSort();


    void selectionSort() ;
    void sortList();

    void listdirectory();
};


#endif // PHONEDIRECTORY_H
