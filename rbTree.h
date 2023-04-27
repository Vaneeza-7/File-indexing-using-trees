#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"LinkedList.h"
using namespace std;

template <class K>
class rbNode {
    string fileName; //file number
    int lineno; //line number
    K key;    //index field

public:
    LinkedList<K> list;  //list for duplicates
    bool black;
    bool isleftchild;
    rbNode<K>* left;
    rbNode<K>* right;
    rbNode<K>* parent;

    rbNode()
    {
        fileName = "";
        lineno = 0;
        K key;
        left = right = parent = NULL;
        black = false;
        isleftchild = false;
        list.head = NULL;
        //new insertions are always red
    }

    rbNode(K k, int line, string file)
    {
        this->fileName = file;
        this->key = k;
        this->lineno = line;
        left = right = parent = NULL;
        black = false;
        isleftchild = false;
    }

    void setFilename(string s)
    {
        fileName = s;
    }

    void setKey(K k)
    {
        key = k;
    }

    string getFileName()
    {
        return fileName;
    }

    K getKey()
    {
        return key;
    }

    void setLinenumber(int l)
    {
        lineno = l;
    }

    int getLineNumber()
    {
        return lineno;
    }

};

template <class K>
class rbTree {
public:
    rbNode<K>* root;
    rbTree()
    {
        root = NULL;
    }

    bool isempty()
    {
        if (root == NULL)
            return true;
        else
            return false;

    }

    rbNode<K>* retrieve(K k)
    {
        bool found = false;
        rbNode<K>* nptr = root;
        while (nptr != NULL)
        {
            if (nptr->getKey() == k)
            {
                found = true;
                break;
            }
            else if (nptr->getKey() > k)
            {
                nptr = nptr->left;
            }
            else
                nptr = nptr->right;
        }
        if (found)
        {
            return nptr;
        }
        else
            nptr = NULL;
        return nptr;
    }

    int height(rbNode<K> node)  //height of node
    {
        if (node == NULL)
            return -1;
        else
        {
            int leftHeight = height(node.left) + 1;
            int rightHeight = height(node.right) + 1;
            if (leftHeight > rightHeight)
                return leftHeight;
            else
                return rightHeight;

        }
    }

    int height()  //height of tree
    {
        if (root == NULL)
            return -1;
        else
            return height(root) - 1;
    }

    int blackNodes(rbNode<K>* node)
    {
        if (node == NULL)
            return 1;

        int rightBlackNodes = blackNodes(node->right);
        int leftBlackNodes = blackNodes(node->left);
        if (leftBlackNodes != rightBlackNodes)
        {
            cout << "Fix tree! Depth property violation.\n";
        }
        else {
            if (node->black)
            {
                leftBlackNodes++;
            }
        }
        return leftBlackNodes;
    }

    //---------------INSERTION METHODS--------------------------//
    void leftRotate(rbNode<K>* node)
    {
        rbNode<K>* temp = new rbNode<K>();
        temp = node->right;
        node->right = temp->left;
        if (node->right != NULL) //update right child
        {
            node->right->parent = node;
            node->right->isleftchild = false;
        }
        if (node->parent == NULL) //we are the root node
        {
            root = temp;
            temp->parent = NULL;
        }
        else  //we're not the root
        {
            temp->parent = node->parent;  //temp points to parent and parent points to temp
            if (node->isleftchild)
            {
                temp->isleftchild = true;
                temp->parent->left = temp;
            }
            else
            {
                temp->isleftchild = false;
                temp->parent->right = temp;
            }

        }
        temp->left = node;
        node->isleftchild = true;
        node->parent = temp;
    }

    void rightRotate(rbNode<K>* node)
    {
        rbNode<K>* temp = new rbNode<K>();
        temp = node->left;
        node->left = temp->right;
        if (node->left != NULL) //update left child
        {
            node->left->parent = node;
            node->left->isleftchild = true; //????
        }
        if (node->parent == NULL) //we are the root node
        {
            root = temp;
            temp->parent = NULL;
        }
        else  //we're not the root
        {
            temp->parent = node->parent;  //temp points to parent and parent points to temp
            if (!node->isleftchild) //???
            {
                temp->isleftchild = false;
                temp->parent->right = temp;
            }
            else
            {
                temp->isleftchild = true;
                temp->parent->left = temp;
            }

        }
        temp->right = node;
        node->isleftchild = false;
        node->parent = temp;
    }

    void leftRightRotate(rbNode<K>* node)
    {
        //rotate parent:  the parent is grand parent's left child
        leftRotate(node->left);
        rightRotate(node);
    }

    void rightLeftRotate(rbNode<K>* node)
    {
        //rotate parent:  the parent is grand parent's right child
        rightRotate(node->right);
        leftRotate(node);
    }

    void rotate(rbNode<K>* node)
    {
        if (node->isleftchild)
        {
            if (node->parent->isleftchild)
            {
                rightRotate(node->parent->parent); //pass grandparent 
                //after rotation we and sibling become red and parent becomes black
                node->black = false;
                node->parent->black = true;
                if (node->parent->right != NULL)
                {
                    node->parent->right->black = false;
                }
                return;
            }
            //parent is a right child
            if (!node->parent->isleftchild)
            {
                rightLeftRotate(node->parent->parent);
                node->black = true;
                node->right->black = false;
                node->left->black = false;
                return;
            }
        }
        else //its a right child
        {
            if (!node->parent->isleftchild)
            {
                leftRotate(node->parent->parent); //pass grandparent 
                //after rotation we and sibling become red and parent becomes black
                node->black = false;
                node->parent->black = true;
                if (node->parent->left != NULL)
                {
                    node->parent->left->black = false;
                }
                return;
            }
            //parent is a left child
            if (node->parent->isleftchild)
            {
                leftRightRotate(node->parent->parent);
                node->black = true;
                node->right->black = false;
                node->left->black = false;
                return;
            }
        }
    }

    void correctTree(rbNode<K>* node)
    {
        //is aunt red or black?
        if (node->parent->isleftchild)  //then aunt would be rightChild
        {
            if (node->parent->parent->right == NULL || node->parent->parent->right->black) //if aunt is black
            {
                rotate(node);
            }
            else if (node->parent->parent->right != NULL) //red aunt do colour flip
            {
                node->parent->parent->right->black = true; //make aunt black
                node->parent->parent->black = false; //make grandparent red
                node->parent->black = true; //make parent black
                return;
            }
        }
        else  //means aunt is leftChild of grandparent (when node.parent is rightChild) 
        {
            if (node->parent->parent != NULL) {
                if (node->parent->parent->left == NULL || node->parent->parent->left->black) //if aunt is black
                {
                    rotate(node);
                }
            }
            if (node->parent != NULL)
                if (node->parent->parent != NULL) {
                    if (node->parent->parent->left != NULL) //red aunt do colour flip
                    {
                        node->parent->parent->left->black = true; //make aunt black
                        node->parent->parent->black = false; //make grandparent red
                        node->parent->black = true; //make parent black
                        return;
                    }
                }
        }

    }


    void checkColour(rbNode<K>* node)  //recursive
    {
        if (node == root)
        {
            node->black = true;
            return;
        }
        else
            if (node != NULL)
            {
                if (node->parent != NULL) {
                    if (!node->black && !node->parent->black)  //if node and parent both are red
                        correctTree(node);
                    checkColour(node->parent);
                }
            }
    }

    void insert(rbNode<K>* currNode, rbNode<K>* newNode)
    {
        if (newNode->getKey() > currNode->getKey())    //add to right
        {
            if (currNode->right == NULL)
            {
                currNode->right = newNode;
                newNode->parent = currNode;
                newNode->isleftchild = false;  //bcz we're right child
                //return;
            }
            else insert(currNode->right, newNode);
        }
        else if (newNode->getKey() < currNode->getKey())
        {
            if (currNode->left == NULL)
            {
                currNode->left = newNode;
                newNode->parent = currNode;
                newNode->isleftchild = true;
                //return;
            }
            else
                insert(currNode->left, newNode);
        }
        else if (newNode->getKey() == currNode->getKey()) //handling duplicates
        {
            currNode->list.insert(newNode->getKey(), newNode->getLineNumber(), newNode->getFileName());
        }

        checkColour(newNode);
    }

    void add(K k, int line, string name)
    {
        rbNode<K>* node = new rbNode<K>(k, line, name);
        //check if tree is empty
        if (isempty())
        {
            root = node;
            root->black = true; //root is always black
            return;
        }
        else
            insert(root, node);
    }

    ////===========================DELETION METHODS=================================//
    //void replace(rbNode<V, K>* n1, rbNode<V, K>* n2)
    //{
    //    if (n1->parent == NULL) //n1 is root, so make n2 the root instead
    //    {
    //        root = n2;

    //    }
    //    else if (n1 == n1->parent->right)//if n1 is the right child 
    //    {
    //        n1->parent->right = n2; //set n2 as right child instead
    //        n2->isleftchild = false; 
    //    }
    //    else
    //    {   
    //        n1->parent->left = n2;  //if the n1 is left child
    //        n2->isleftchild = true; //set n2 as the left child instead
    //    }

    //    n2->parent = n1->parent;
    //    delete n1;
    //    //updating n2's left and right is the responsibility of delete function
    //    //this function only updates parents
    //}

    //rbNode<V, K>* getMin(rbNode<V, K>* node) //get min node in left subtree
    //{
    //    while (node->left != NULL)
    //    {
    //        node = node->left;
    //    }
    //    return node;
    //}

    //void deleteFix(rbNode<V, K>* n)
    //{

    //}

    //void deleteNode(rbNode<V, K>* node)
    //{
    //    rbNode<V, K>* temp = new rbNode<V, K>();
    //    temp->black = node->black;  //make a node of same colour
    //    if (node->left == NULL)
    //    {
    //        rbNode<V, K>* temp2 = node->right;
    //        replace(node, node->right);
    //        delete node;
    //        deleteFix(temp2);  //bcz node doesnt exist anymore we'll call fixup with a pointer which points to node's child
    //    
    //    }
    //    else if (node->right == NULL)
    //    {
    //        rbNode<V, K>* temp2 = node->left;
    //        replace(node, node->left);
    //        delete node;
    //        deleteFix(temp2);
    //    }
    //    else
    //        rbNode<V, K>* temp2 = getMin(node->right); 
    //        temp2->black = temp2->black; 
    //        replace(temp2, temp2->right);
    //        temp2->right = node->right;
    //        node->right->parent = temp2;
    //        node->right->isleftchild = false;
    //        replace(node, temp2);
    //        temp2->left = node->left;
    //        delete node;
    //        deleteFix(temp2->right->left);


    //}

    //void Delete(rbNode<V, K>* currNode, K del)  //finds node to be deleted
    //{
    //    if (currNode->getKey() > del)
    //    {
    //        currNode = currNode->left;
    //    }
    //    else if (currNode->getKey() < del)
    //    {
    //        currNode = currNode->right;
    //    }
    //    else if (currNode->getKey() == del)
    //    {
    //        deleteNode(currNode);
    //    }
    //    else
    //        cout << "Node to be deleted not found.\n";
    //}

    //void deletion(K k) //interface function
    //{
    //    //check if tree is empty
    //    if (isempty())
    //    {

    //        cout << "Red-Black Tree is already empty.\n";
    //        return;
    //    }
    //    else
    //        Delete(root, k);   
    //}




    //---------------------RED BLACK TREE TRAVERSALS--------------------------//
    string getColour(rbNode<K>* n)
    {
        if (n->black)
        {
            return "Black";
        }
        else
            return "Red";
    }

    void PreOrderTraversal(rbNode<K>* n)
    {
        if (n != NULL)
        {
            cout << n->getKey() << " " << n->getLineNumber() << " " << n->getFileName() << " " << n->black << endl;
            PreOrderTraversal(n->left);
            PreOrderTraversal(n->right);

        }
    }

    void PostOrderTraversal(rbNode<K>* n)
    {
        //n=root
        if (n != NULL)
        {
            PostOrderTraversal(n->left);
            PostOrderTraversal(n->right);
            cout << n->getKey() << " " << n->getLineNumber() << " " << n->getFileName() << " " << n->black << endl;

        }
    }

    void InOrderTraversal(rbNode<K>* n)
    {
        //n = root;
        if (n != NULL)
        {
            InOrderTraversal(n->left);
            cout << n->getKey() << " " << n->getLineNumber() << " " << n->getFileName() << " " << getColour(n) << endl;
            if (n->list.head != NULL)
            {
                cout << "--------------------------------------Duplicates-----------------------------------------" << endl;
                n->list.printLL();
            }
            InOrderTraversal(n->right);
        }
    }

    void LevelOrder(rbNode<K>* n)
    {
        if (n == NULL)
            return;
        else
        {
            queue<rbNode<K>*> q;
            q.push(n);
            while (q.empty() == false)
            {
                rbNode<K>* top = q.front();
                cout << top->getKey() << " " << top->getLineNumber() << " " << top->getFileName() << endl;
                if (top->list.head != NULL)
                {
                    top->list.printLL();
                }
                q.pop();
                if (top->left != NULL)
                {
                    q.push(n->left);
                }
                if (top->right != NULL)
                {
                    q.push(n->right);
                }
            }
        }
    }

    void ShowinPreOrder() {
        cout << "PreOrder traversal of Red-black tree is : " << endl;
        PreOrderTraversal(root);
        cout << endl;
    }

    void ShowinPostOrder() {
        cout << "PostOrder traversal of Red-black tree is : " << endl;
        PostOrderTraversal(root);
        cout << endl;
    }

    void ShowinInOrder() {
        cout << "InOrder traversal of Red-black tree is : " << endl;
        InOrderTraversal(root);
        cout << endl;
    }

    void saveRBinFile(rbNode<K>* n, string filename)
    {
        fstream file;
        file.open(filename.c_str(), ios::app);
        if (!(file.is_open()))
        {
            cout << "File not open" << endl;
        }
        else
        {
            stack<rbNode<K>*> s;
            rbNode<K>* curr = n; //get the root

            while (curr != NULL || s.empty() == false)
            {

                while (curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top();
                s.pop();


                file << curr->getKey() << "," << curr->getLineNumber() << "," << curr->getFileName() << endl;
                if (curr->list.head != NULL)
                {
                    //file << "--------------------------------------Duplicates-----------------------------------------" << endl;
                    //n->list.printLL();
                    Node<K>* temp = new Node<K>;
                    temp = curr->list.head;
                    while (temp)
                    {
                        file << temp->data << "," << temp->line << "," << temp->file << endl;
                        temp = temp->next;
                    }
                }

                curr = curr->right;

            }

            //if (n != NULL)
            //{
            //    n = n->left;
            //    file << n->getKey() << " " << n->getLineNumber() << " " << n->getFileName() << endl;
            //    if (n->list.head != NULL)
            //    {
            //        file << "--------------------------------------Duplicates-----------------------------------------" << endl;
            //        //n->list.printLL();
            //        Node<K>* temp = new Node<K>;
            //        temp = n->list.head;
            //        while (temp)
            //        {
            //            file << temp->data << " " << temp->line << " " << temp->file << endl;
            //            temp = temp->next;
            //        }
            //    }
            //    n = n->right;
            //}
        }
        file.close();
    }

};

//template <class V, class K>
//class rbNode {
//    V value;
//    K key;
//public:
//    bool black;
//    bool isleftchild;
//    rbNode<V, K>* left;
//    rbNode<V, K>* right;
//    rbNode<V, K>* parent;
//
//    rbNode()
//    {
//        V value;
//        K key;
//        left = right = parent = NULL;
//        black = false;
//        isleftchild = false;
//        //new insertions are always red
//    }
//
//    rbNode(V val, K k)
//    {
//        this->value = val;
//        this->key = k;
//        left = right = parent = NULL;
//        black = false;
//        isleftchild = false;
//    }
//
//    void setValue(V val)
//    {
//        value = val;
//    }
//
//    void setKey(K k)
//    {
//        key = k;
//    }
//
//    V getValue()
//    {
//        return value;
//    }
//
//    K getKey()
//    {
//        return key;
//    }
//
//};
//
//template <class V, class K>
//class rbTree {
//public:
//    rbNode<V, K>* root;
//    rbTree()
//    {
//        root = NULL;
//    }
//
//    bool isempty()
//    {
//        if (root == NULL)
//            return true;
//        else
//            return false;
//
//    }
//
//    bool retrieve(K k)
//    {
//        bool found = false;
//        rbNode<V, K>* nptr = root;
//        while (nptr != NULL)
//        {
//            if (nptr->getKey() == k)
//            {
//                found = true;
//                break;
//            }
//            else if (nptr->getKey() > k)
//            {
//                nptr = nptr->left;
//            }
//            else
//                nptr = nptr->right;
//        }
//        return found;
//    }
//
//    int height(rbNode<V, K> node)  //height of node
//    {
//        if (node == NULL)
//            return -1;
//        else
//        {
//            int leftHeight = height(node.left) + 1;
//            int rightHeight = height(node.right) + 1;
//            if (leftHeight > rightHeight)
//                return leftHeight;
//            else
//                return rightHeight;
//
//        }
//    }
//
//    int height()  //height of tree
//    {
//        if (root == NULL)
//            return -1;
//        else
//            return height(root) - 1;
//    }
//
//    int blackNodes(rbNode<V, K>* node)
//    {
//        if (node == NULL)
//            return 1;
//
//        int rightBlackNodes = blackNodes(node->right);
//        int leftBlackNodes = blackNodes(node->left);
//        if (leftBlackNodes != rightBlackNodes)
//        {
//            cout << "Fix tree! Depth property violation.\n";
//        }
//        else {
//            if (node->black)
//            {
//                leftBlackNodes++;
//            }
//        }
//        return leftBlackNodes;
//    }
//
//    //---------------INSERTION METHODS---------------------
//    void leftRotate(rbNode<V, K>* node)
//    {
//        rbNode<V, K>* temp = new rbNode<V, K>();
//        temp = node->right;
//        node->right = temp->left;
//        if (node->right != NULL) //update right child
//        {
//            node->right->parent = node;
//            node->right->isleftchild = false;
//        }
//        if (node->parent == NULL) //we are the root node
//        {
//            root = temp;
//            temp->parent = NULL;
//        }
//        else  //we're not the root
//        {
//            temp->parent = node->parent;  //temp points to parent and parent points to temp
//            if (node->isleftchild)
//            {
//                temp->isleftchild = true;
//                temp->parent->left = temp;
//            }
//            else
//            {
//                temp->isleftchild = false;
//                temp->parent->right = temp;
//            }
//
//        }
//        temp->left = node;
//        node->isleftchild = true;
//        node->parent = temp;
//    }
//
//    void rightRotate(rbNode<V, K>* node)
//    {
//        rbNode<V, K>* temp = new rbNode<V, K>();
//        temp = node->left;
//        node->left = temp->right;
//        if (node->left != NULL) //update left child
//        {
//            node->left->parent = node;
//            node->left->isleftchild = true; //????
//        }
//        if (node->parent == NULL) //we are the root node
//        {
//            root = temp;
//            temp->parent = NULL;
//        }
//        else  //we're not the root
//        {
//            temp->parent = node->parent;  //temp points to parent and parent points to temp
//            if (!node->isleftchild) //???
//            {
//                temp->isleftchild = false;
//                temp->parent->right = temp;
//            }
//            else
//            {
//                temp->isleftchild = true;
//                temp->parent->left = temp;
//            }
//
//        }
//        temp->right = node;
//        node->isleftchild = false;
//        node->parent = temp;
//    }
//
//    void leftRightRotate(rbNode<V, K>* node)
//    {
//        //rotate parent:  the parent is grand parent's left child
//        leftRotate(node->left);
//        rightRotate(node);
//    }
//
//    void rightLeftRotate(rbNode<V, K>* node)
//    {
//        //rotate parent:  the parent is grand parent's right child
//        rightRotate(node->right);
//        leftRotate(node);
//    }
//
//    void rotate(rbNode<V, K>* node)
//    {
//        if (node->isleftchild)
//        {
//            if (node->parent->isleftchild)
//            {
//                rightRotate(node->parent->parent); //pass grandparent 
//                //after rotation we and sibling become red and parent becomes black
//                node->black = false;
//                node->parent->black = true;
//                if (node->parent->right != NULL)
//                {
//                    node->parent->right->black = false;
//                }
//                return;
//            }
//            //parent is a right child
//            if (!node->parent->isleftchild)
//            {
//                rightLeftRotate(node->parent->parent);
//                node->black = true;
//                node->right->black = false;
//                node->left->black = false;
//                return;
//            }
//        }
//        else //its a right child
//        {
//            if (!node->parent->isleftchild)
//            {
//                leftRotate(node->parent->parent); //pass grandparent 
//                //after rotation we and sibling become red and parent becomes black
//                node->black = false;
//                node->parent->black = true;
//                if (node->parent->left != NULL)
//                {
//                    node->parent->left->black = false;
//                }
//                return;
//            }
//            //parent is a left child
//            if (node->parent->isleftchild)
//            {
//                leftRightRotate(node->parent->parent);
//                node->black = true;
//                node->right->black = false;
//                node->left->black = false;
//                return;
//            }
//        }
//    }
//
//    void correctTree(rbNode<V, K>* node)
//    {
//        //is aunt red or black?
//        if (node->parent->isleftchild)  //then aunt would be rightChild
//        {
//            if (node->parent->parent->right == NULL || node->parent->parent->right->black) //if aunt is black
//            {
//                rotate(node);
//            }
//            else if (node->parent->parent->right != NULL) //red aunt do colour flip
//            {
//                node->parent->parent->right->black = true; //make aunt black
//                node->parent->parent->black = false; //make grandparent red
//                node->parent->black = true; //make parent black
//                return;
//            }
//        }
//        else  //means aunt is leftChild of grandparent (when node.parent is rightChild) 
//        {
//            if (node->parent->parent != NULL) {
//                if (node->parent->parent->left == NULL || node->parent->parent->left->black) //if aunt is black
//                {
//                    rotate(node);
//                }
//            }
//            if (node->parent->parent != NULL) {
//                if (node->parent->parent->left != NULL) //red aunt do colour flip
//                {
//                    node->parent->parent->left->black = true; //make aunt black
//                    node->parent->parent->black = false; //make grandparent red
//                    node->parent->black = true; //make parent black
//                    return;
//                }
//            }
//        }
//
//    }
//
//
//    void checkColour(rbNode<V, K>* node)  //recursive
//    {
//        if (node == root)
//        {
//            node->black = true;
//            return;
//        }
//        if (node != NULL) {
//            if (node->parent != NULL) {
//                if (!node->black && !node->parent->black)  //if node and parent both are red
//                    correctTree(node);
//                checkColour(node->parent);
//            }
//        }
//    }
//
//    void insert(rbNode<V, K>* currNode, rbNode<V, K>* newNode)
//    {
//        if (newNode->getKey() > currNode->getKey())    //add to right
//        {
//            if (currNode->right == NULL)
//            {
//                currNode->right = newNode;
//                newNode->parent = currNode;
//                newNode->isleftchild = false;  //bcz we're right child
//                //return;
//            }
//            else insert(currNode->right, newNode);
//        }
//        else if (newNode->getKey() < currNode->getKey())
//        {
//            if (currNode->left == NULL)
//            {
//                currNode->left = newNode;
//                newNode->parent = currNode;
//                newNode->isleftchild = true;
//                //return;
//            }
//            else
//                insert(currNode->left, newNode);
//        }
//        checkColour(newNode);
//    }
//
//    void add(V val, K k)
//    {
//        rbNode<V, K>* node = new rbNode<V, K>(val, k);
//        //check if tree is empty
//        if (isempty())
//        {
//            root = node;
//            root->black = true; //root is always black
//            return;
//        }
//        else
//            insert(root, node);
//    }
//
//    //---------------------RED BLACK TREE TRAVERSALS--------------------------//
//
//    void PreOrderTraversal(rbNode<V, K>* n)
//    {
//        if (n != NULL)
//        {
//            cout << n->getKey() << " ";
//            PreOrderTraversal(n->left);
//            PreOrderTraversal(n->right);
//
//        }
//    }
//
//    void PostOrderTraversal(rbNode<V, K>* n)
//    {
//        //n=root
//        if (n != NULL)
//        {
//            PostOrderTraversal(n->left);
//            PostOrderTraversal(n->right);
//            cout << n->getKey() << " ";
//
//        }
//    }
//
//    void InOrderTraversal(rbNode<V, K>* n)
//    {
//        //n = root;
//        if (n != NULL)
//        {
//            InOrderTraversal(n->left);
//            cout << n->getKey() << " " << n->black << endl;
//            InOrderTraversal(n->right);
//        }
//    }
//
//
//    void ShowinPreOrder() {
//        cout << "PreOrder traversal of Red-black tree is : " << endl;
//        PreOrderTraversal(root);
//        cout << endl;
//    }
//
//    void ShowinPostOrder() {
//        cout << "PostOrder traversal of Red-black tree is : " << endl;
//        PostOrderTraversal(root);
//        cout << endl;
//    }
//
//    void ShowinInOrder() {
//        cout << "InOrder traversal of Red-black tree is : " << endl;
//        InOrderTraversal(root);
//        cout << endl;
//    }
//
//};