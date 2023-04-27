#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<fstream>
#include "AvlTree.h"
#include"rbTree.h"
using namespace std;

//vector<vector<string>> fileReaderAVL(string names[], int index)
//{
//    switch (index)
//    {
//    case 1:                                                             //ID indexing-------------------------
//    {
//        AVLTree<int> idTree;
//        vector<vector<string>> content;
//        vector<string> row;
//        string line, word;
//        int lineNo = 0;
//        int wordNo = 0;
//        for (int p = 0; p < 10; p++)
//        {
//            fstream file(names[p], ios::in);
//            if (file.is_open())
//            {
//                lineNo = 0;
//                while (getline(file, line))
//                {
//                    wordNo = 0;
//                    if (lineNo > 0)
//                    {
//                        row.clear();
//
//                        stringstream str(line);
//
//                        while (getline(str, word, ','))
//                        {
//                            wordNo++;
//                            if (wordNo == index)
//                            {
//                                int len = word.length();
//                                char* arr = new char[len];
//                                for (int i = 0; i < len; i++)
//                                {
//                                    arr[i] = word[i];
//                                }
//                                int id = atoi(arr);
//                                idTree.root = idTree.insertNode(id, idTree.root, lineNo, names[p]);
//                                row.push_back(word);
//                            }
//                        }
//                        content.push_back(row);
//                    }
//                    lineNo++;
//                }
//            }
//            else
//            {
//                cout << "Could not open the file\n";
//            }
//        }
//        idTree.inOrdertraversal(idTree.root);
//        /* for (int i = 0; i < content.size(); i++)
//         {
//             for (int j = 0; j < content[i].size(); j++)
//             {
//                 cout << content[i][j] << " ";
//             }
//             cout << "\n";
//         }*/
//        return content;

//----------------------------------QUERY SEARCHES-----------------------------------//
void pointSearchRB(string filename, int lineNo)
{
    fstream file(filename.c_str(), ios::in);
    string line, word;
    vector<string>row;
    vector<vector<string>> content;
    int linenum;
    if (file.is_open())
    {
        linenum = 0;
        while (getline(file, line))
        {
            if (linenum == lineNo)
            {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {

                    row.push_back(word);
                }
                content.push_back(row);
            }

            linenum++;
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            cout << content[i][j] << " ";
        }
        cout << "\n";
    }

}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- File Reading Function -----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//

void fileReaderAVL(string names[], int index)
{
    switch (index)
    {
    case 1:                                                             //ID indexing-------------------------
    {
        AVLTree<int> idTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int id = atoi(arr);
                                idTree.root = idTree.insertNode(id, idTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //idTree.inOrdertraversal(idTree.root);
        //levelOrderTraversalInt(idTree.root);
        string filename = "AVLIDTree.txt";
        idTree.saveInIDFile(idTree.root, filename);
    }
    break;
    case 2:
    {                         //----------Year indexing-------------------------
        AVLTree<int> yearTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int year = atoi(arr);
                                yearTree.root = yearTree.insertNode(year, yearTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //yearTree.inOrdertraversal(yearTree.root);
        string filename = "AVLYearTree.txt";
        yearTree.saveInIDFile(yearTree.root, filename);
    }
    break;
    case 3:
    {                                                                    //Cause113 indexing-------------------------
        AVLTree<string> cause113Tree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }

                                //int year = atoi(arr);
                                cause113Tree.root = cause113Tree.insertNode(word, cause113Tree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }

            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //cause113Tree.inOrdertraversal(cause113Tree.root);
        string filename = "AVL113Tree.txt";
        cause113Tree.saveInIDFile(cause113Tree.root, filename);
    }
    break;
    case 4:
    {                                                                    //Cause indexing------------------------
        AVLTree<string> causeTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                //int year = atoi(arr);
                                causeTree.root = causeTree.insertNode(word, causeTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }

            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //causeTree.inOrdertraversal(causeTree.root);
        string filename = "AVLCauseTree.txt";
        causeTree.saveInIDFile(causeTree.root, filename);
    }
    break;
    case 5:
    {                                                                    //State indexing-----------------------
        AVLTree<string> stateTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }

                                //int year = atoi(arr);
                                stateTree.root = stateTree.insertNode(word, stateTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }

            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //stateTree.inOrdertraversal(stateTree.root);
        string filename = "AVLStateTree.txt";
        stateTree.saveInIDFile(stateTree.root, filename);
    }
    break;
    case 6:
    {                                                                   //Deaths indexing-------------------------
        AVLTree<int> deathTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int death = atoi(arr);
                                deathTree.root = deathTree.insertNode(death, deathTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //deathTree.inOrdertraversal(deathTree.root);
        string filename = "AVLDeathTree.txt";
        deathTree.saveInIDFile(deathTree.root, filename);
    }
    break;
    case 7:
    {                                                                     //Age-Adjusted death rate indexing-------------------------
        AVLTree<int> ageTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == index)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int age = atoi(arr);
                                ageTree.root = ageTree.insertNode(age, ageTree.root, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //ageTree.inOrdertraversal(ageTree.root);
        string filename = "AVLAgeTree.txt";
        ageTree.saveInIDFile(ageTree.root, filename);
    }
    break;
    default:
    {
        cout << "Wrong number!!" << endl;
    }
    break;
    }
}
void AVLID()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 1);

}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL Year Indexing Function ------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLYear()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 2);
}
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------- AVL 113 Cause Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVL113()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 3);
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL Cause Indexing Function -----------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLCause()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 4);
}
//---------------------------------------------------------------------------------------------------------------//
//-------------------------------------------- AVL State Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLState()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 5);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------------- AVL Deaths Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLDeaths()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                               "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 6);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------- AVL Age-Adjusted Deaths Indexing Function -------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLAge()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderAVL(file_names, 7);
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL Tree Menu Function ----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLMenu()
{
    int optionF = 0;
    cout << "Which field do you want to do indexing on?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Year" << endl;
    cout << "3. 113 Cause Name" << endl;
    cout << "4. Cause Name" << endl;
    cout << "5. State" << endl;
    cout << "6. Deaths" << endl;
    cout << "7. Age-Adjusted death rate" << endl;
    cin >> optionF;
    switch (optionF)
    {
    case 1:
    {
        AVLID();
    }
    break;
    case 2:
    {
        AVLYear();
    }
    break;
    case 3:
    {
        AVL113();
    }
    break;
    case 4:
    {
        AVLCause();
    }
    break;
    case 5:
    {
        AVLState();
    }
    break;
    case 6:
    {
        AVLDeaths();
    }
    break;
    case 7:
    {
        AVLAge();
    }
    break;
    default:
    {
        cout << "Wrong Option!" << endl;
    }
    break;
    }
}



//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- File Loading Function -----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLLoad()
{
    int optionF = 0;
    cout << "Which field tree do you want to load for queries?" << endl;
    cout << "1. ID tree" << endl;
    cout << "2. Year tree" << endl;
    cout << "3. 113 Cause Name tree" << endl;
    cout << "4. Cause Name tree" << endl;
    cout << "5. State tree" << endl;
    cout << "6. Deaths tree" << endl;
    cout << "7. Age-Adjusted death rate tree" << endl;
    cin >> optionF;
    switch (optionF)
    {
    case 1:
    {
        string filename = "AVLIDTree.txt";
        fstream file;
        AVLTree<int> idLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        int id = 0;
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                idLTree.root = idLTree.insertNode(id, idLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        int search = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter ID to search" << endl;
            cin >> search;
            idLTree.retrieve(idLTree.root, search);
            //pointSearchRB(t->fileName, t->lineNum);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }

    }
    break;
    case 2:
    {

        string filename = "AVLYearTree.txt";
        fstream file;
        AVLTree<int> yearLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        int id = 0;
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                yearLTree.root = yearLTree.insertNode(id, yearLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        int search = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter year to search" << endl;
            cin >> search;
            //AVLNode<int>* t = yearLTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            yearLTree.retrieve(yearLTree.root, search);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }

    }
    break;
    case 3:
    {
        string filename = "AVL113Tree.txt";
        fstream file;
        AVLTree<string> cause113LTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        string id = "";
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        id = word;

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                cause113LTree.root = cause113LTree.insertNode(id, cause113LTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter cause113 to search" << endl;
            cin >> search;
            //AVLNode<string>* t = cause113LTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            cause113LTree.retrieve(cause113LTree.root, search);


        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }

    }
    break;
    case 4:
    {
        string filename = "AVLCauseTree.txt";
        fstream file;
        AVLTree<string> causeLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        string id = "";
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        id = word;

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                causeLTree.root = causeLTree.insertNode(id, causeLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter cause to search" << endl;
            cin >> search;
            //AVLNode<string>* t = causeLTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            causeLTree.retrieve(causeLTree.root, search);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }
    break;
    case 5:
    {
        string filename = "AVLStateTree.txt";
        fstream file;
        AVLTree<string> StateLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        string id = "";
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        id = word;

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                StateLTree.root = StateLTree.insertNode(id, StateLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter state to search" << endl;
            cin >> search;
            //AVLNode<string>* t = StateLTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            StateLTree.retrieve(StateLTree.root, search);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }
    break;
    case 6:
    {

        string filename = "AVLDeathTree.txt";
        fstream file;
        AVLTree<int> deathLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        int id = 0;
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                deathLTree.root = deathLTree.insertNode(id, deathLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        int search = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter deaths to search" << endl;
            cin >> search;
            //AVLNode<int>* t = deathLTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            deathLTree.retrieve(deathLTree.root, search);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }

    }
    break;
    case 7:
    {

        string filename = "AVLAgeTree.txt";
        fstream file;
        AVLTree<float> ageLTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        int id = 0;
        string filenameInNode = "";
        file.open(filename.c_str(), ios::app);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                lineNo = 0;
                wordNo = 0;
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atof(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 2)
                    {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);

                        row.push_back(word);
                    }
                    else if (wordNo == 3)
                    {
                        filenameInNode = word;
                    }
                }
                content.push_back(row);
                ageLTree.root = ageLTree.insertNode(id, ageLTree.root, lineNo, filenameInNode);
            }
        }
        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        float search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter age adjusted death rate to search" << endl;
            cin >> search;
            //AVLNode<float>* t = ageLTree.retrieve(search);
            //pointSearchRB(t->fileName, t->lineNum);
            ageLTree.retrieve(ageLTree.root, search);

        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }

    }
    break;
    default:
    {
        cout << "Wrong Option!" << endl;
    }
    break;
    }
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- REd Black Tree Functions -------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
vector<vector<string>> fileReaderRBtree(string names[], int column)
{
    //vector<vector<string>> content;
    //vector<string> row;
    //string line, word;
    //int lineno = 0;
    //int wordno = 0;

    //for (int p = 0; p < 10; p++)
    //{
    //    fstream file(names[p], ios::in);
    //    if (file.is_open())
    //    {
    //        while (getline(file, line))
    //        {
    //            wordno = 0;
    //            if (lineno > 0) {
    //                row.clear();

    //                stringstream str(line);

    //                while (getline(str, word, ','))
    //                {
    //                    wordno++;
    //                    if (wordno == column)
    //                    {
    //                        row.push_back(word);
    //                    }
    //                }
    //                content.push_back(row);
    //            }
    //            lineno++;
    //        }
    //    }
    //    else
    //    {
    //        cout << "Could not open the file\n";
    //    }
    //}
    ///* for (int i = 0; i < content.size(); i++)
    // {
    //     for (int j = 0; j < content[i].size(); j++)
    //     {
    //         cout << content[i][j] << " ";
    //     }
    //     cout << "\n";

    // }*/
    //return content;

    switch (column)
    {
    case 1:                                                             //ID indexing-------------------------
    {
        rbTree<int> idRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int id = atoi(arr);
                                idRBTree.add(id, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //idRBTree.ShowinInOrder();
        idRBTree.saveRBinFile(idRBTree.root, "idRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 2:
    {
        rbTree<int> yearRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int id = atoi(arr);
                                yearRBTree.add(id, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //yearRBTree.ShowinInOrder();
        yearRBTree.saveRBinFile(yearRBTree.root, "yearRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 3:
    {
        rbTree<string> cause113RBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }

                                //int year = atoi(arr);
                                cause113RBTree.add(word, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }

            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //cause113RBTree.ShowinInOrder();
        cause113RBTree.saveRBinFile(cause113RBTree.root, "cause113RBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 4:
    {
        rbTree<string> causeRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }

                                //int year = atoi(arr);
                                causeRBTree.add(word, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }

            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //causeRBTree.ShowinInOrder();
        causeRBTree.saveRBinFile(causeRBTree.root, "causeRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 5:
    {
        rbTree<string> stateRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {

                                stateRBTree.add(word, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //stateRBTree.ShowinInOrder();
        stateRBTree.saveRBinFile(stateRBTree.root, "stateRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 6:
    {
        rbTree<int> deathRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                int death = atoi(arr);
                                deathRBTree.add(death, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //deathRBTree.ShowinInOrder();
        deathRBTree.saveRBinFile(deathRBTree.root, "deathRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    case 7:
    {
        rbTree<float> ageRBTree;
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int wordNo = 0;
        for (int p = 0; p < 2; p++)
        {
            fstream file(names[p], ios::in);
            if (file.is_open())
            {
                lineNo = 0;
                while (getline(file, line))
                {
                    wordNo = 0;
                    if (lineNo > 0)
                    {
                        row.clear();

                        stringstream str(line);

                        while (getline(str, word, ','))
                        {
                            wordNo++;
                            if (wordNo == column)
                            {
                                int len = word.length();
                                char* arr = new char[len];
                                for (int i = 0; i < len; i++)
                                {
                                    arr[i] = word[i];
                                }
                                float age = atof(arr);
                                ageRBTree.add(age, lineNo, names[p]);
                                row.push_back(word);
                            }
                        }
                        content.push_back(row);
                    }
                    lineNo++;
                }
            }
            else
            {
                cout << "Could not open the file\n";
            }
        }
        //ageRBTree.ShowinInOrder();
        ageRBTree.saveRBinFile(ageRBTree.root, "ageRBTree.txt");
        /* for (int i = 0; i < content.size(); i++)
         {
             for (int j = 0; j < content[i].size(); j++)
             {
                 cout << content[i][j] << " ";
             }
             cout << "\n";
         }*/
        return content;
    }
    break;
    default:
    {
        cout << "Wrong number!!" << endl;
    }
    }

}
//
//void createRBTree(int option)
//{
//    if (option == 1)//if id based indexing
//    {
//        rbTree<int, int> idIndex;
//        int keys;
//        string file_names[10] = { "File1.csv","File2.csv","File3.csv","File4.csv","File5.csv","File6.csv","File7.csv","File8.csv","File9.csv","File10.csv" };
//        vector<vector<string>> indexArray = fileReaderRBtree(file_names, option);
//        for (int i = 0; i < indexArray.size(); i++)
//        {
//            for (int j = 0; j < indexArray[i].size(); j++)
//            {
//                //keys = stoi(indexArray[i][j]);
//                string temp = indexArray[i][j];
//                int len = temp.length();
//                char* arr = new char[len];
//                for (int i = 0;i < len;i++)
//                {
//                    arr[i] = temp[i];
//                }
//                keys = atoi(arr);
//                idIndex.add(9, keys); //inserting keys into red black tree
//            }
//        }
//        idIndex.ShowinInOrder();
//    }
//
//}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- RED BLACK ID Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBID()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    vector<vector<string>> data;
    data = fileReaderRBtree(file_names, 1);

}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- RB Year Indexing Function ------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBYear()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderRBtree(file_names, 2);
}
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------- RB 113 Cause Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RB113()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderRBtree(file_names, 3);
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- RB Cause Indexing Function -----------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBCause()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };
    fileReaderRBtree(file_names, 4);
}
//---------------------------------------------------------------------------------------------------------------//
//-------------------------------------------- RB State Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBState()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                                 "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderRBtree(file_names, 5);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------------- RB Deaths Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBDeaths()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };
    fileReaderRBtree(file_names, 6);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------- RB Age-Adjusted Deaths Indexing Function -------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBAge()
{
    string file_names[2] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv" };

    fileReaderRBtree(file_names, 7);
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- Red Black Tree Menu Function ----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void RBMenu()
{
    int optionF = 0;
    cout << "Which field do you want to do indexing on?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Year" << endl;
    cout << "3. 113 Cause Name" << endl;
    cout << "4. Cause Name" << endl;
    cout << "5. State" << endl;
    cout << "6. Deaths" << endl;
    cout << "7. Age-Adjusted death rate" << endl;
    cin >> optionF;
    switch (optionF)
    {
    case 1:
    {
        RBID();
    }
    break;
    case 2:
    {
        RBYear();
    }
    break;
    case 3:
    {
        RB113();
    }
    break;
    case 4:
    {
        RBCause();
    }
    break;
    case 5:
    {
        RBState();
    }
    break;
    case 6:
    {
        RBDeaths();
    }
    break;
    case 7:
    {
        RBAge();
    }
    break;
    default:
    {
        cout << "Wrong Option!" << endl;
    }
    break;
    }
}

void LoadRBfromFile(string filename, int column)
{
    fstream file;
    file.open(filename.c_str(), ios::in);

    switch (column)
    {
    case 1:                                                             //ID indexing-------------------------
    {
        rbTree<int> idRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int id = 0;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                idRBTree.add(id, lineNo, fileName);
            }
        }
        int optionS = 0;
        int search = 0;
        int search1 = 0;
        int search2 = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter ID to search" << endl;
            cin >> search;
            rbNode<int>* t = idRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());

        }
        break;
        case 2:
        {
            cout << "Enter id range to search with space" << endl;
            cin >> search1 >> search2;
            /*rbNode<int>* temp = idRBTree.root;
            while (temp != NULL) {
                if (search1 < temp->getKey())
                {
                    if (temp != NULL)
                    temp = temp->left;
                }
                if (search1 <= temp->getKey() && search2 >= temp->getKey())
                {
                    if (temp != NULL)
                    pointSearchRB(temp->getFileName(), temp->getLineNumber());
                }
                if (temp != NULL)
                temp = temp->right;
            }*/
        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }


    }
    break;
    case 2:
    {
        rbTree<int> yearRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int id = 0;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                yearRBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }

        int optionS = 0;
        int search = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter year to search" << endl;
            cin >> search;
            rbNode<int>* t = yearRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<int>* temp = new Node<int>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }
    break;
    case 3:
    {
        rbTree<string> cause113RBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        string id;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        id = word;
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                cause113RBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }

        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter cause113 to search" << endl;
            cin >> search;
            rbNode<string>* t = cause113RBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<string>* temp = new Node<string>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }

    break;
    case 4:
    {
        rbTree<string> causeRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        string id;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        id = word;
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                causeRBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter cause to search" << endl;
            cin >> search;
            rbNode<string>* t = causeRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<string>* temp = new Node<string>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }

    break;
    case 5:
    {
        rbTree<string> stateRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        string id;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        id = word;
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                stateRBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }
        int optionS = 0;
        string search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter State name to search" << endl;
            cin >> search;
            rbNode<string>* t = stateRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<string>* temp = new Node<string>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }

    break;
    case 6:
    {
        rbTree<int> deathRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        int id = 0;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                deathRBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }

        int optionS = 0;
        int search = 0;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter death to search" << endl;
            cin >> search;
            rbNode<int>* t = deathRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<int>* temp = new Node<int>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }
    break;
    case 7:
    {
        rbTree<float> ageRBTree;
        vector<string> row;
        string line, word;
        int lineNo = 0;
        float id = 0;
        string lineno, fileName;
        int wordNo = 0;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                wordNo = 0;

                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                {
                    wordNo++;
                    if (wordNo == 1) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        id = atof(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 2) {
                        int len = word.length();
                        char* arr = new char[len];
                        for (int i = 0; i < len; i++)
                        {
                            arr[i] = word[i];
                        }
                        lineNo = atoi(arr);
                        row.push_back(word);
                    }
                    if (wordNo == 3) {
                        fileName = word;
                        row.push_back(word);
                    }
                }

                ageRBTree.add(id, lineNo, fileName);
            }
        }

        else
        {
            cout << "Could not open the file\n";
        }

        int optionS = 0;
        float search;
        cout << "File loaded successfully!" << endl;
        cout << "1. Do Search Query (point search)" << endl;
        cout << "2. Do Range Search" << endl;
        cin >> optionS;
        switch (optionS)
        {
        case 1:
        {
            cout << "Enter age adjusted death rate to search" << endl;
            cin >> search;
            rbNode<float>* t = ageRBTree.retrieve(search);
            pointSearchRB(t->getFileName(), t->getLineNumber());
            if (t->list.head != NULL)
            {
                Node<float>* temp = new Node<float>;
                temp = t->list.head;
                while (temp)
                {
                    pointSearchRB(temp->file, temp->line);
                    temp = temp->next;
                }
            }
        }
        break;
        case 2:
        {

        }
        break;
        default:
        {
            cout << "Wrong Query!" << endl;
        }
        break;
        }
    }
    break;
    default:
    {
        cout << "Wrong number!!" << endl;
    }
    }


}

void RBLoad()
{
    int optionF = 0;
    cout << "Which field tree do you want to load for queries?" << endl;
    cout << "1. ID tree" << endl;
    cout << "2. Year tree" << endl;
    cout << "3. 113 Cause Name tree" << endl;
    cout << "4. Cause Name tree" << endl;
    cout << "5. State tree" << endl;
    cout << "6. Deaths tree" << endl;
    cout << "7. Age-Adjusted death rate tree" << endl;
    cin >> optionF;
    switch (optionF)
    {
    case 1:
    {
        LoadRBfromFile("idRBTree.txt", 1);
    }
    break;
    case 2:
    {
        LoadRBfromFile("yearRBTree.txt", 2);
    }
    break;
    case 3:
    {
        LoadRBfromFile("cause113RBTree.txt", 3);
    }
    break;
    case 4:
    {
        LoadRBfromFile("causeRBTree.txt", 4);
    }
    break;
    case 5:
    {
        LoadRBfromFile("stateRBTree.txt", 5);
    }
    break;
    case 6:
    {
        LoadRBfromFile("deathRBTree.txt", 6);
    }
    break;
    case 7:
    {
        LoadRBfromFile("ageRBTree.txt", 7);
    }
    break;
    default:
    {
        cout << "Wrong Option!" << endl;
    }
    break;
    }
}
