#pragma once
#include<iostream>
using namespace std;

template <class V, class K>
class rbNode {
    V value;
    K key;    
public:
    bool black;
    bool isleftchild;
    rbNode<V, K>* left;
    rbNode<V, K>* right;
    rbNode<V, K>* parent;

    rbNode()
    {
        V value;
        K key;
        left = right = parent = NULL;
        black = false;
        isleftchild = false;
           //new insertions are always red
    }

    rbNode(V val, K k)
    {
        this->value = val;
        this->key = k;
        left = right = parent = NULL;
        black = false;
        isleftchild = false;
    }

    void setValue(V val)
    {
        value = val;
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

    //---------------INSERTION METHODS---------------------
    void add(V val, K k)
    {
        rbNode<V, K>* node = new rbNode<V, K>(val, k);
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

    void insert(rbNode<V, K> currNode, rbNode<V, K> newNode )
    {
        if (newNode.getKey() > currNode.getKey())    //add to right
        {
            if (currNode.right == NULL)
            {
                currNode.right = newNode;
                newNode.parent = currNode;
                newNode.isleftchild = false;  //bcz we're right child
                //return;
            }
            else insert(currNode.right, newNode);
        }
        else if (newNode.getKey() < currNode.getKey())
        {
            if (currNode.left == NULL)
            {
                currNode.left = newNode;
                newNode.parent = currNode;
                newNode.isleftchild = true;
                //return;
            }
            else
                insert(currNode.left, newNode);
        }
        checkColour(newNode);
    }

    void checkColour(rbNode<V, K> node)  //recursive
    {
        if (node == root)
            return;
        if (!node.black && !node.parent->black)  //if node and parent both are red
            correctTree(node);
         checkColour(node.parent);
    }

    void correctTree(rbNode<V, K> node)
    {
        //is aunt red or black?
        if (node.parent->isleftchild)  //then aunt would be rightChild
        {
            if (node.parent->parent->right == NULL || node.parent->parent->right->black) //if aunt is black
            {
                rotate(node);
            }
            if (node.parent->parent->right != NULL) //red aunt do colour flip
            {
                node.parent->parent->right->black = true; //make aunt black
                node.parent->parent->black = false; //make grandparent red
                node.parent->black = true; //make parent black
                return;
            }
        }
        else  //means aunt is leftChild of grandparent (when node.parent is rightChild) 
        {
            if (node.parent->parent->left == NULL || node.parent->parent->left->black) //if aunt is black
            {
                rotate(node);
            }
            if (node.parent->parent->left != NULL) //red aunt do colour flip
            {
                node.parent->parent->left->black = true; //make aunt black
                node.parent->parent->black = false; //make grandparent red
                node.parent->black = true; //make parent black
                return;
            }
        }

    }

    void rotate(rbNode<V, K> node)
    {
        if (node.isleftchild)
        {
            if (node.parent->isleftchild)
            {
                rightRotate(node.parent->parent); //pass grandparent 
                //after rotation we and sibling become red and parent becomes black
                node.black = false;
                node.parent->black = true;
                if(node.parent->right!=NULL)
                {
                    node.parent->right->black = false;
                }
                return;
            }
            //parent is a right child
            if (!node.parent->isleftchild)
            {
                rightLeftRotate(node.parent->parent);
                node.black = true;
                node.right->black = false;
                node.left->black = false;
                return;
            }
        }
        else //its a right child
        {
            if (!node.parent->isleftchild)
            {
                leftRotate(node.parent->parent); //pass grandparent 
                //after rotation we and sibling become red and parent becomes black
                node.black = false;
                node.parent->black = true;
                if (node.parent->left != NULL)
                {
                    node.parent->left->black = false;
                }
                return;
            }    
            //parent is a left child
            if (node.parent->isleftchild)
            {
                leftRightRotate(node.parent->parent);
                node.black = true;
                node.right->black = false;
                node.left->black = false;
                return;
            }
        }
    }

    void leftRotate(rbNode<V, K> node)
    {
        rbNode<V, K> temp = node.right;
        node.right = temp.left;
        if (node.right != NULL) //update right child
        {
            node.right->parent = node;
            node.right->isleftchild = false;
        }
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