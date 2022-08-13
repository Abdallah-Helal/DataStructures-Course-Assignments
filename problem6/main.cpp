#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include"PhoneDirectory.h"
using namespace std;

int main()
{
    PhoneDirectory dir;
    while (true)
    {
        int option;
        cout << "Please, choose any number from the following list" << endl
            << "1. Add an entry to the directory" << endl
            << "2. Look up a phone number" << endl
            << "3. Look up by first name" << endl
            << "4. Delete an entry from the directory" << endl
            << "5. List All entries in phone directory" << endl
            << "6. Exit" << endl;
        cin >> option;
        // switch to do what user choose
        switch (option) {
        case 1:
        {
            dir.addNewEntry();
            break;
        }
        case 2:
        {
            int pos=dir.searchByPhone();
            if (pos != -1)
                dir.printAt(pos);
            else
                cout << "the phone doesn't exist" << endl;
            break;
        }
        case 3:
        {
            int pos = dir.searchByFirstName();
            if (pos != -1)
                dir.printAt(pos);
            else
                cout << "the name doesn't exist" << endl;
            break;
        }
        case 4:
        {
            dir.deleteByFirstName();
            break;
        }
        case 5:
        {
            dir.listdirectory();
            break;
        }
        default:
            return 0;
        }
    }
    return 0;

}
