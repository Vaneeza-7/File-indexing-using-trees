#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <direct.h>

using namespace std;
string returnString(long selection, string str);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class DataSet {
public:
    long lineNo;
    string fileName, str;
    long id;
    DataSet() {}
    DataSet(long line, string adress, long identification, string s) {
        lineNo = line;
        fileName = adress;
        id = identification;
        str = s;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                   /*-------------------NODE PART-----------------------*/

struct Node {

    DataSet* dataObjects;
    long Degree;
    Node** ChildPtr;
    long N_Keys;
    bool leaf;

    Node(long _Degree, bool _leaf);
    void remove(long numValue) {
        long Fid = findKey(numValue);

        if (Fid < N_Keys and dataObjects[Fid].id == numValue) {

            if (leaf)
                remove_leaf(Fid);
            else
                remove_nonleaf(Fid);
        }
        else {

            if (leaf) {
                return;
            }

            bool flag = ((Fid == N_Keys) ? true : false);

            if (ChildPtr[Fid]->N_Keys < Degree) {
                fill(Fid);
            }

            if (flag and Fid > N_Keys) {
                ChildPtr[Fid - 1]->remove(numValue);
            }
            else {
                ChildPtr[Fid]->remove(numValue);
            }
        }
        return;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void remove_leaf(long Fid) {
        for (long i = Fid + 1; i < N_Keys; ++i) {
            dataObjects[i - 1] = dataObjects[i];
        }
        N_Keys--;

        return;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void remove_nonleaf(long Fid) {
        long numValue = dataObjects[Fid].id;

        if (ChildPtr[Fid]->N_Keys >= Degree) {
            long pred = predicate(Fid);
            dataObjects[Fid].id = pred;
            ChildPtr[Fid]->remove(pred);
        }
        else if (ChildPtr[Fid + 1]->N_Keys >= Degree) {
            long succ = getSucc(Fid);
            dataObjects[Fid].id = succ;
            ChildPtr[Fid + 1]->remove(succ);
        }
        else {
            merge(Fid);
            ChildPtr[Fid]->remove(numValue);
        }
        return;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void insert_nonfull(DataSet numValue) {
        long index = N_Keys - 1;

        if (leaf == true) {
            for (;index >= 0 and dataObjects[index].id > numValue.id;) {
                dataObjects[index + 1] = dataObjects[index];
                index--;
            }

            dataObjects[index + 1] = numValue;
            N_Keys = N_Keys + 1;
        }
        else
        {
            for (;index >= 0 and dataObjects[index].id > numValue.id;) {
                index--;
            }
            if (ChildPtr[index + 1]->N_Keys == (2 * Degree) - 1) {
                splitter(index + 1, ChildPtr[index + 1]);

                if (dataObjects[index + 1].id < numValue.id) {
                    index++;
                }
            }
            ChildPtr[index + 1]->insert_nonfull(numValue);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    long predicate(long Fid) {
        Node* cur = ChildPtr[Fid];
        for (;!cur->leaf;) {
            cur = cur->ChildPtr[cur->N_Keys];
        }
        return cur->dataObjects[cur->N_Keys - 1].id;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    long getSucc(long Fid) {

        Node* cur = ChildPtr[Fid + 1];
        for (;!cur->leaf;) {
            cur = cur->ChildPtr[0];
        }
        return cur->dataObjects[0].id;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void getfrom_prev(long Fid) {
        Node* child = ChildPtr[Fid];
        Node* sibling = ChildPtr[Fid - 1];

        for (long i = child->N_Keys - 1; i >= 0; --i) {
            child->dataObjects[i + 1] = child->dataObjects[i];
        }
        if (!child->leaf) {
            for (long i = child->N_Keys; i >= 0; --i) {
                child->ChildPtr[i + 1] = child->ChildPtr[i];
            }
        }

        child->dataObjects[0] = dataObjects[Fid - 1];

        if (!child->leaf) {
            child->ChildPtr[0] = sibling->ChildPtr[sibling->N_Keys];
        }
        dataObjects[Fid - 1] = sibling->dataObjects[sibling->N_Keys - 1];

        child->N_Keys += 1;
        sibling->N_Keys -= 1;

        return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void splitter(long i, Node* y) {
        Node* z = new Node(y->Degree, y->leaf);
        z->N_Keys = Degree - 1;

        for (long j = 0; j < Degree - 1; j++) {
            z->dataObjects[j] = y->dataObjects[j + Degree];
        }
        if (y->leaf == false) {
            for (long j = 0; j < Degree; j++) {
                z->ChildPtr[j] = y->ChildPtr[j + Degree];
            }
        }

        y->N_Keys = Degree - 1;

        for (long j = N_Keys; j >= i + 1; j--) {
            ChildPtr[j + 1] = ChildPtr[j];
        }

        ChildPtr[i + 1] = z;

        for (long j = N_Keys - 1; j >= i; j--) {
            dataObjects[j + 1] = dataObjects[j];
        }
        dataObjects[i] = y->dataObjects[Degree - 1];

        N_Keys = N_Keys + 1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void fill(long Fid) {
        if (Fid != 0 and ChildPtr[Fid - 1]->N_Keys >= Degree) {
            getfrom_prev(Fid);
        }
        else if (Fid != N_Keys and ChildPtr[Fid + 1]->N_Keys >= Degree) {
            getfrom_next(Fid);
        }
        else {
            if (Fid != N_Keys) {
                merge(Fid);
            }
            else {
                merge(Fid - 1);
            }
        }
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void merge(long Fid) {
        Node* child = ChildPtr[Fid];
        Node* sibling = ChildPtr[Fid + 1];

        child->dataObjects[Degree - 1] = dataObjects[Fid];

        for (long i = 0; i < sibling->N_Keys; ++i) {
            child->dataObjects[i + Degree] = sibling->dataObjects[i];
        }
        if (!child->leaf) {
            for (long i = 0; i <= sibling->N_Keys; ++i)
                child->ChildPtr[i + Degree] = sibling->ChildPtr[i];
        }

        for (long i = Fid + 1; i < N_Keys; ++i) {
            dataObjects[i - 1] = dataObjects[i];
        }
        for (long i = Fid + 2; i <= N_Keys; ++i) {
            ChildPtr[i - 1] = ChildPtr[i];
        }
        child->N_Keys += sibling->N_Keys + 1;
        N_Keys--;

        delete(sibling);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    long findKey(long numValue) {
        long Fid = 0;
        for (;Fid < N_Keys and dataObjects[Fid].id < numValue;) {
            ++Fid;
        }
        return Fid;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void getfrom_next(long Fid) {
        Node* child = ChildPtr[Fid];
        Node* sibling = ChildPtr[Fid + 1];

        child->dataObjects[(child->N_Keys)] = dataObjects[Fid];

        if (!(child->leaf)) {
            child->ChildPtr[(child->N_Keys) + 1] = sibling->ChildPtr[0];
        }
        dataObjects[Fid] = sibling->dataObjects[0];

        for (long i = 1; i < sibling->N_Keys; ++i) {
            sibling->dataObjects[i - 1] = sibling->dataObjects[i];
        }
        if (!sibling->leaf) {
            for (long i = 1; i <= sibling->N_Keys; ++i) {
                sibling->ChildPtr[i - 1] = sibling->ChildPtr[i];
            }
        }

        child->N_Keys += 1;
        sibling->N_Keys -= 1;

        return;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void print() {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->print();
            cout << endl << dataObjects[i].str;
        }

        if (leaf == false) {
            ChildPtr[i]->print();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void man(Node* t) {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->man(t);
            t = NULL;
        }

        if (leaf == false) {
            ChildPtr[i]->man(t);
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void alldel() {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->alldel();

        }

        if (leaf == false) {
            ChildPtr[i]->alldel();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void traverseString(string a1, long b1) {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->traverseString(a1, b1);
            if (returnString(b1, dataObjects[i].str) == a1) {
                cout << endl << dataObjects[i].str;
            }
        }

        if (leaf == false) {
            ChildPtr[i]->traverseString(a1, b1);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void traversepoint(long a) {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->traversepoint(a);
            if (dataObjects[i].id == a) {
                cout << endl << dataObjects[i].str;
            }
        }

        if (leaf == false) {
            ChildPtr[i]->traversepoint(a);
        }
    }
    void traversepoints(long a, long b) {
        long i;
        for (i = 0; i < N_Keys; i++) {
            if (leaf == false)
                ChildPtr[i]->traversepoints(a, b);
            if (dataObjects[i].id >= a and dataObjects[i].id <= b) {
                cout << endl << dataObjects[i].str;
            }
        }

        if (leaf == false) {
            ChildPtr[i]->traversepoints(a, b);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    Node* search(long numValue)
    {
        long i = 0;
        for (;i < N_Keys and numValue > dataObjects[i].id;) {
            i++;
        }

        if (dataObjects[i].id == numValue) {
            return this;
        }
        if (leaf == true) {
            return NULL;
        }
        return ChildPtr[i]->search(numValue);
    }
};

                             /*-------------------END OF NODE PART-----------------------*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                    /*STRUCTURE OF B-TREE*/

struct BTree {
    Node* root = NULL; // Pointer to root node 
    long Degree; // Minimum degree 
    void dlr(Node* y)
    {
        root->man(y);
    }

    Node* getRoot() {
        return root;
    }
    BTree(long _Degree) {
        Degree = _Degree;
    }

    void print() {
        if (root == NULL) {
            cout << "The Root is Null and Empty " << endl << endl;
        }
        if (root != NULL) {
            root->print();
        }
    }

   /* void dfsTraverse() {
        printNode();
        for (int i = 0; i < szp; i++) {
            if (ptr[i] != NULL) {
                cout << "Goto " << i << " : " << endl; getchar();
                ptr[i]->dfsTraverse();
            }*/

    void traverseString(string a1, long a2) {
        if (root == NULL) {
            cout << "The Root is Null and Empty " << endl << endl;
        }
        if (root != NULL) {
            root->traverseString(a1, a2);
        }
    }

    void traversePoint(long a1) {
        if (root == NULL) {
            cout << "The Root is Null and Empty " << endl << endl;
        }
        if (root != NULL) {
            root->traversepoint(a1);
        }
    }
    void traversePoints(long a1, long b1) {
        if (root == NULL) {
            cout << "The Root is Null and Empty " << endl << endl;
        }
        if (root != NULL) {
            root->traversepoints(a1, b1);
        }
    }
    void remove(long numValue) {
        if (!root) {
            cout << "The tree is empty\n";
            return;
        }

        root->remove(numValue);

        if (root->N_Keys == 0) {
            Node* tmp = root;
            if (root->leaf) {
                root = NULL;
            }
            else {
                root = root->ChildPtr[0];
            }
            delete tmp;
        }
        return;
    }
    void frr(Node* u)
    {
        u=NULL;
    }

    Node* search(long numValue) {
        return (root == NULL) ? NULL : root->search(numValue);
    }

    void insert(DataSet numValue) {

        if (root == NULL) {
            root = new Node(Degree, true);
            root->dataObjects[0] = numValue;
            root->N_Keys = 1;
        }
        else
        {
            if (root->N_Keys == 2 * Degree - 1) {
                Node* s = new Node(Degree, false);

                s->ChildPtr[0] = root;

                s->splitter(0, root);

                long i = 0;
                if (s->dataObjects[0].id < numValue.id) {
                    i++;
                }
                s->ChildPtr[i]->insert_nonfull(numValue);

                root = s;
            }
            else {
                root->insert_nonfull(numValue);
            }
        }
    }
};

Node::Node(long t1, bool leaf1) {
    Degree = t1;
    leaf = leaf1;

    ChildPtr = new Node * [2 * Degree];
    dataObjects = new DataSet[(2 * Degree) - 1];

    N_Keys = 0;
}
void deler(Node* x)
{
    delete x;
}
void fre(Node* CocaCola)
{
     delete CocaCola;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void creatingFile(string ID, string data, string fileName, long line) {
    string newFileName;
    newFileName = "\Nodes\\" + ID + ".txt";
    ofstream newFile;
    newFile.open(newFileName);
    newFile << ID << endl;
    newFile << data << endl;
    newFile << fileName << endl;
    newFile << line << endl;
    newFile.close();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void readingOneFile(string fileName, BTree& obj) {

    _mkdir("Nodes");
    ifstream fileObject;
    fileObject.open(fileName);
    string str;
    long ID;
    string year, deaths, deathRate;
    string causeName113, causeName, state;
    long counter(1);

    for (;!fileObject.eof();) {
        getline(fileObject, str);
        if (counter > 1) {

            long i = 0;
            string s[7] = {
              ""
            };
            long itr = 0;
            long br = 0;
            for (;str[i];) {
                if (str[i] == '"') {
                    br++;
                    i++;
                }
                if (str[i] == ',') {

                    if (br % 2 == 1) {
                        s[itr] += str[i];
                    }
                    else {
                        itr++;
                    }
                }
                else {
                    s[itr] += str[i];
                }
                i++;
            }
            stringstream object(s[0]);
            object >> ID;

            obj.insert(DataSet(counter, fileName, ID, str));
            creatingFile(s[0], str, fileName, counter);

        }
        counter++;
    }
    fileObject.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void readingAllFiles(string alpha, BTree& obj) {
    _mkdir("Nodes");
    ifstream obj2;
    obj2.open(alpha);
    if(obj2.fail()){
    	cout<<"File DeathRate_01.csv is not available in the current directory"<<endl;
    	obj2.close();
    	exit(1);
	}
	obj2.close();
    
    for (long i(1); i <= 10; i++) {
        if (i < 10) {
            stringstream ss;
            ss << i;
            string str1 = ss.str();
            alpha[11] = str1[0];
            readingOneFile(alpha, obj);
        }
        if (i == 10) {
            alpha[10] = '1';
            alpha[11] = '0';
            readingOneFile(alpha, obj);
        }
    }

    remove("\Nodes\\.txt");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string updateString(long selection, string str, string replacment) {
    long i = 0;
    string s[7] = {
      ""
    };
    long itr = 0;
    long br = 0;
    for (;str[i];) {
        if (str[i] == '"') {
            br++;
            i++;
        }
        if (str[i] == ',') {

            if (br % 2 == 1) {
                s[itr] += str[i];
            }
            else {
                itr++;
            }
        }
        else {
            s[itr] += str[i];
        }
        i++;
    }
    if (selection == 2) {
        s[1] = replacment;
    }
    else if (selection == 3) {
        s[2] = replacment;
    }
    else if (selection == 4) {
        s[3] = replacment;
    }
    else if (selection == 5) {
        s[4] = replacment;
    }
    else if (selection == 6) {
        s[5] = replacment;
    }
    else if (selection == 7) {
        s[6] = replacment;
    }

    string temp = s[0] + "," + s[1] + ",\"" + s[2] + "\"," + s[3] + "," + s[4] + "," + s[5] + "," + s[6];

    return temp;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


string returnString(long selection, string str) {
    long i = 0;
    string s[7] = {
      ""
    };
    long itr = 0;
    long br = 0;
    for (;str[i];) {
        if (str[i] == '"') {
            br++;
            i++;
        }
        if (str[i] == ',') {

            if (br % 2 == 1) {
                s[itr] += str[i];
            }
            else {
                itr++;
            }
        }
        else {
            s[itr] += str[i];
        }
        i++;
    }
    if (selection == 1) {
        return s[0];
    }
    else if (selection == 2) {
        return s[1];
    }
    else if (selection == 3) {
        return s[2];
    }
    else if (selection == 4) {
        return s[3];
    }
    else if (selection == 5) {
        return 	s[4];
    }
    else if (selection == 6) {
        return s[5];
    }
    else if (selection == 7) {
        return s[6];
    }


}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Menu() {
    cout << "Please make sure that you have DeathRate_01.csv file in the directory you are running this program" << endl;
    //system("PAUSE");
    cout << endl;
    long degree;
    cout << "Please Input the degree of B Tree (minimum 2)" << endl;
    cin >> degree;
    if (degree < 2) {
        cout << "Value Should be More Than 2" << endl;
        exit(1);
    }
    BTree obj(degree);
    cout << endl;
    long choice(0);
    for (;choice != 8;) {
        cout << "\n\n1. Read the File and Construct the B Tree" << endl <<
            "2. Do a point search" << endl <<
            "3. Specify an index range to search" << endl <<
            "4. Delete a tuple" << endl <<
            "5. Edit a tuple" << endl <<
            "6. Display the whole Database" << endl <<
            "7. Clear memory" << endl <<
            "8. End program" << endl;

        cin >> choice;
        cout << endl;

        switch (choice) {

        case 1:
        {
            cout << "Reading All Files DeathRate_cx.csv and Entering Data into the BTree, Please Wait!" << endl;
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_1.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_2.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_3.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_4.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_5.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_6.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_7.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_8.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_9.csv", obj);
            readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_10.csv", obj);
            //readingOneFile("NCHS_-_Leading_Causes_of_Death__United_States_6.csv", obj);
            cout << "Reading From ALL Files Complete" << endl;
            cout << "Creating new files in folder Node" << endl;
            cout << "Creating new files in folder Node Complete" << endl;
            break;
            
        }

        case 2: //Doing sigle point search
        {
            if (obj.getRoot() == NULL) {
                cout << "Please Read the files first" << endl << endl;
                break;
            }
            cout << "1. Search with ID." << endl <<
                "2. Search with Year." << endl <<
                "3. Search with 113 Causes Name." << endl <<
                "4. Search with Cause Name." << endl <<
                "5. Search with State." << endl <<
                "6. Search with Deaths." << endl <<
                "7. Search with Age Adjusted Death Rate." << endl;


            cout << endl << "Please input the option value" << endl;
            long alpha;
            cin >> alpha;


            if (alpha == 1) {
                Node* obj1;
                obj1 = obj.search(alpha);
                if (obj1 == NULL) {
                    cout << "No value found for the given index" << endl << endl;
                    break;
                }
                long option(0);
                cout << endl << "Enter the value to Search" << endl;
                cin >> option;
                obj.traversePoint(option);
            }
            if (alpha > 1 and alpha <= 7) {
                string option;
                cout << endl << "Enter the value to Search" << endl;
                cin >> option;
                obj.traverseString(option, alpha);
                break;
            }


            break;
        }
        case 3: { //indexing range
            Node* obj2;
            if (obj.getRoot() == NULL) {
                cout << "Please Read the files first" << endl << endl;
                break;
            }
            cout << "Please input the indexing range (space seperated)" << endl;
            long beta;
            long alpha;
            alpha = 43;
            beta = 200;
            cin >> alpha >> beta;
            if (alpha > beta) {
                obj.traversePoints(beta, alpha);

            }
            if (alpha <= beta) {
                obj.traversePoints(alpha, beta);

            }
            break;
        }
        case 4: {
            if (obj.getRoot() == NULL) {
                cout << "Please Read the files first" << endl << endl;
                break;
            }
            Node* obj1;
            cout << "Please input the indexing value" << endl;
            long alpha;
            cin >> alpha;
            cout << endl;
            obj1 = obj.search(alpha);
            if (obj1 == NULL) {
                cout << "No value found for the given index" << endl << endl;
                break;
            }
            for (long i(0); 1; i++) {
                if (obj1->dataObjects[i].id == alpha) {
                    string idstr;
                    idstr = to_string(alpha);
                    string str = "\Nodes\\" + idstr + "\.txt";
                    const char* c = str.c_str();
                    remove(c);
                    obj.remove(obj1->dataObjects[i].id);
                    break;
                }
            }

            break;
        }

        case 8: {
            cout << "GoobBye, Have a Nice Day!" << endl;
            exit(1);

            break;
        }
        case 7: {
            
            obj.frr(obj.root);
            obj.root = NULL;
            cout<<endl<<"Memory Freed Successfully."<<endl;
            break;
        }
        case 6: {
            obj.print();
            break;
        }

        case 5: {  //edit
            if (obj.getRoot() == NULL) {
                cout << "Please Read the files first" << endl << endl;
                break;
            }
            long alpha;
            cout << "Please input the ID value" << endl;
            cin >> alpha;
            cout << endl;

            cout << "1. Replace ID." << endl <<
                "2. Replace Year." << endl <<
                "3. Replace 113 Causes Name." << endl <<
                "4. Replace Cause Name." << endl <<
                "5. Replace State." << endl <<
                "6. Replace Deaths." << endl <<
                "7. Replace Age Adjusted Death Rate." << endl;
            long input;
            cout << endl << "Please Select Your Option from menu above and your replacment string with a space" << endl;
            cin >> input;
            char replacmentString[250] = {
              ""
            };
            cin.get(replacmentString, 250);
            Node* obj3;
            cout << endl;
            for (long i(00); i < 249; i++) {
                replacmentString[i] = replacmentString[i + 1];
            }

            obj3 = obj.search(alpha);
            if (obj3 == NULL) {
                cout << "No value found for the given index" << endl << endl;
                break;
            }
            for (long i(0); 1; i++) {
                if (obj3->dataObjects[i].id == alpha /*id*/) {
                    if (input == 1) {
                        stringstream obj(replacmentString);
                        long a;
                        obj >> a;
                        obj3->dataObjects[i].id = a;
                        input = 0;
                    }
                    obj3->dataObjects[i].str = updateString(input, obj3->dataObjects[i].str, replacmentString);
                    string tempStr = to_string(obj3->dataObjects[i].id);
                    creatingFile(tempStr, obj3->dataObjects[i].str, obj3->dataObjects[i].fileName, obj3->dataObjects[i].lineNo);
                    break;
                }
            }
            cout << "\nEdit Completed\n";
            choice = 0;

        }
              //a
              break;

        default: {
            cout << "Please select the correct option." << endl;
            break;
        }

        }
    }
}

int main() {

    Menu();
}
