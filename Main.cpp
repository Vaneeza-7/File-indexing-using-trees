#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "AVL.h"
using namespace std;
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- File Reading Function -----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
vector<vector<string>> fileReaderAVL(string names[], int index)
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
            for (int p = 0; p < 10; p++)
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
            idTree.inOrdertraversal(idTree.root);
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
            AVLTree<int> yearTree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            yearTree.inOrdertraversal(yearTree.root);
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
            AVLTree<string> cause113Tree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            cause113Tree.inOrdertraversal(cause113Tree.root);
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
            AVLTree<string> causeTree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            causeTree.inOrdertraversal(causeTree.root);
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
            AVLTree<string> stateTree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            stateTree.inOrdertraversal(stateTree.root);
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
            AVLTree<int> deathTree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            deathTree.inOrdertraversal(deathTree.root);
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
            AVLTree<int> ageTree;
            vector<vector<string>> content;
            vector<string> row;
            string line, word;
            int lineNo = 0;
            int wordNo = 0;
            for (int p = 0; p < 10; p++)
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
            ageTree.inOrdertraversal(ageTree.root);
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
        break;
    }
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL ID Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLID()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    vector<vector<string>> data;
    data = fileReaderAVL(file_names, 1);

}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL Year Indexing Function ------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLYear()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    fileReaderAVL(file_names, 2);
}
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------- AVL 113 Cause Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVL113()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    fileReaderAVL(file_names, 3);
}
//---------------------------------------------------------------------------------------------------------------//
//----------------------------------------------- AVL Cause Indexing Function -----------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLCause()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    fileReaderAVL(file_names, 4);
}
//---------------------------------------------------------------------------------------------------------------//
//-------------------------------------------- AVL State Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLState()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    fileReaderAVL(file_names, 5);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------------- AVL Deaths Indexing Function --------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLDeaths()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
    fileReaderAVL(file_names, 6);
}
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------- AVL Age-Adjusted Deaths Indexing Function -------------------------------//
//---------------------------------------------------------------------------------------------------------------//
void AVLAge()
{
    string file_names[10] = { "NCHS_-_Leading_Causes_of_Death__United_States_1.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_2.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_3.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_4.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_5.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_6.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_7.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_8.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_9.csv",
                             "NCHS_-_Leading_Causes_of_Death__United_States_10.csv" };
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
//----------------------------------------------- Main Function -------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
int main()
{
    int optionIL = 0;
    int optionT = 0;
    cout << "Do you want to create index or load file?" << endl;
    cout << "1. Create Index" << endl;
    cout << "2. Load File" << endl;
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

                }
                break;
                case 2:
                {
                    AVLMenu();
                }
                break;
                case 3:
                {

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
        }
        break;
        default:
        {
            cout << "Wrong number!" << endl;
        }
        break;
    }
	return 0;
}