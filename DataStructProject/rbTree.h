#pragma once
#include<iostream>
using namespace std;

template <class V, class K>
class rbNode {
    V value;
    K key;
    int colour;    //0 represents black & 1 represents red
public:
    rbNode* left;
    rbNode* right;

    rbNode()
    {
        V value;
        K key;
        left = NULL;
        right = NULL;
        colour = 1;   //new insertions are always red
    }

    rbNode(V val, K k, int col)
    {
        value = val;
        key = k;
        colour = col;
        left = NULL;
        right = NULL;
    }

    void setValue(V val)
    {
        value = val;
    }

    void setColour(int col)
    {
        colour = col;
    }

    void setKey(K k)
    {
        key = k;
    }

    V getValue()
    {
        return value;
    }

    K getKey()
    {
        return key;
    }

    int getColour()
    {
        return colour;
    }

};

template <class V, class K>
class rbTree {
public:
    rbNode<V, K>* root;
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

    bool retrieve(K k)
    {
        bool found = false;
        rbNode<V, K>* nptr = root;
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
        return found;
    }

    //---------------------RED BLACK TREE TRAVERSALS--------------------------//

    void PreOrderTraversal(rbNode<V, K>* n)
    {
        if (n != NULL)
        {
            cout << n->getKey() << " ";
            PreOrderTraversal(n->left);
            PreOrderTraversal(n->right);

        }
    }

    void PostOrderTraversal(rbNode<V, K>* n)
    {
         //n=root
        if (n != NULL)
        {
            PostOrderTraversal(n->left);
            PostOrderTraversal(n->right);
            cout << n->getKey() << " ";

        }
    }

    void InOrderTraversal(rbNode<V, K>* n)
    {
        //n = root;
        if (n != NULL)
        {
            InOrderTraversal(n->left);
            cout << n->getKey() << " ";
            InOrderTraversal(n->right);
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

};