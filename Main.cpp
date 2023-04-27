#include<iostream>
#include"AvlTree.h"
#include"FileHandling.h"
#include"LinkedList.h"
#include"rbTree.h"
#include"Btree.h"
using namespace std;

int main()
{
    int optionIL = 0;
    int optionT = 0;
    int optionL = 0;
    for (;optionIL != 3;) {
        cout << "Do you want to create index or load file?" << endl;
        cout << "1. Create Index" << endl;
        cout << "2. Load File" << endl;
        cout << "3. Exit Program" << endl;
        cin >> optionIL;
        switch (optionIL)
        {
        case 1:
        {
            cout << "Which tree do you want to use for indexing?" << endl;
            cout << "1. Red Black Trees" << endl;
            cout << "2. AVL Trees" << endl;
            cout << "3. B-Trees" << endl;
            cin >> optionT;
            switch (optionT)
            {
            case 1:
            {
                RBMenu();
            }
            break;
            case 2:
            {
                AVLMenu();
            }
            break;
            case 3:
            {
                Menu();
            }
            break;
            default:
            {
                cout << "Wrong Option!" << endl;
            }
            break;
            }
        }
        break;
        case 2:
        {
            cout << "Which file do you want to load?" << endl;
            cout << "1. Red Black Tree File" << endl;
            cout << "2. AVL Tree File" << endl;
            cout << "3. B-Tree File" << endl;
            cin >> optionL;
            switch (optionL)
            {
            case 1:
            {
                RBLoad();
            }
            break;
            case 2:
            {
                AVLLoad();
            }
            break;
            case 3:
            {

            }
            break;
            }
        }
        break;
        }
    }
    return 0;
}