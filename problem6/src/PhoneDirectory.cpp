#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include"PhoneDirectory.h"

using namespace std;

void PhoneDirectory::addNewEntry()
    {
        string firstName="", lastName="", phone="";
        cin >> firstName >> lastName >> phone;
        Names.push_back({ {firstName ,lastName }, phone});
        cout << "The addion succeed"<<endl;
    }
int PhoneDirectory::searchByPhone()
{
    cout << "Enter the PHONE : ";
    string phone="";   cin >> phone;
    for (int i = 0; i < Names.size(); i++)
    {
        if (Names[i].second == phone)
            return i;
    }
    return -1;
}
int PhoneDirectory::searchByFirstName()
{
    cout << "Enter the first name: ";
    string firstName = "";    cin >> firstName;
    for (int i = 0; i < Names.size(); i++)
    {
        if (Names[i].first.first == firstName)
            return i;
    }
    return -1;
}
void PhoneDirectory::deleteByFirstName()
{
    int pos=searchByFirstName();
    if (pos == -1) {
        cout << "the name doesn't exist" << endl;
        return;
    }
    auto it = Names.begin() + pos;
    Names.erase(it);
}
void PhoneDirectory::printAt(int pos)
{
    cout << "position: " << pos << endl;
    cout << Names[pos].first.first << " " << Names[pos].first.second << " " << Names[pos].second << endl;
}

void PhoneDirectory::bubbleSort() {
    int size = Names.size();
    // loop to access each array element
    for (int step = 0; step < (size - 1); step++) {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); i++) {

            if (Names[i].first.first > Names[i+1].first.first) {

                // swapping occurs if elements
                // are not in intended order
                swap(Names[i], Names[i + 1]);
                swapped = 1;
            }
        }
        // no swapping means the array is already sorted
        if (swapped == 0)
            break;
    }
}
void PhoneDirectory::insertionSort()
{
    int size = Names.size();
    int step, j;
    auto key = Names[0];
    for (step = 1; step < size; step++)
    {
        key = Names[step];
        j = step - 1;
        // Compare key with each element on the left of it until an element smaller than it is found.
        while (j >= 0 && Names[j].first.first > key.first.first)
        {
            Names[j + 1] = Names[j];
            j-=1;
        }
        Names[j + 1] = key;
    }
}

void PhoneDirectory::selectionSort() {
    for (int step = 0; step <Names.size() - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < Names.size(); i++) {
            // Select the minimum element in each loop.
            if (Names[i].first.first < Names[min_idx].first.first)
                min_idx = i;
        }

        // put min at the correct position
        swap(Names[min_idx],Names[step]);
    }
}
void PhoneDirectory::sortList()
{
    int option=0;
    cout << "Please, choose any number from the following list" << endl
        << "1. insertionSort " << endl
        << "2. bubbleSort" << endl
        << "3. selectionSort" << endl;
    cin >> option;
    switch (option) {
    case 1:
    {
        insertionSort();
        break;
    }
    case 2:
    {
        bubbleSort();
        break;
    }
    case 3:
    {
        selectionSort();
            break;
    }
    default:
        exit(0) ;
    }
}
void PhoneDirectory::listdirectory()
{
    sortList();
    for (int i = 0; i < Names.size(); i++)
    {
        cout << Names[i].first.first << " " << Names[i].first.second << " " << Names[i].second << endl;

    }
}
