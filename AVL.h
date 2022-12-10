#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;
//-------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------- AVL Node Class --------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------//
template <class T>
class AVLNode
{
public:
	string fileName;											//File which has the key/index
	int lineNum;												//Line Number of the file having the key/index
	int height;													//Height of the tree
	LinkedList<T> list;											//List to store duplicates
	T key;														//Index
	AVLNode<T>* left;											//Pointer for left child
	AVLNode<T>* right;											//Pointer for right child
	AVLNode()													//Default constructor for node class
	{
		key = 0;
		height = 0;
		lineNum = 0;
		fileName = "";
		left = NULL;
		right = NULL;
		list.head = NULL;
	}
	AVLNode(T k,int l,string f)									//Parameterized constructor
	{
		key = k;
		lineNum = l;
		fileName = f;
		height = 0;
		left = NULL;
		right = NULL;
		list.insert(k);
	}
	int calculateHeight(AVLNode<T>* n)							//Function to calculate height of the tree
	{
		if (n == NULL)
			return -1;
		else
			return n->height;
	}
	int max(int l, int r)										//Function to find maximum height out of left and right subtrees
	{
		if (l < r)
			return r;
		else
			return l;
	}
	~AVLNode()													//Destructor for node class
	{
		key = 0;
		height = 0;
		lineNum = 0;
		fileName = "";
		delete left;
		left = NULL;
		delete right;
		right = NULL;
	}
};
//-------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------- AVL Tree Class --------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------//
template <class T>
class AVLTree
{
public:
	AVLNode<T>* root;											//Root of the tree
	AVLTree()													//Default constructor
	{
		root = NULL;
	}
	AVLNode<T>* insertNode(T k, AVLNode<T>* &r,int l,string f)	//Insertion of a node in the tree
	{
		if (r == NULL)											//In case root is NULL(no node in the tree)
		{
			r = new AVLNode<T>(k,l,f);
		}
		else
		{														//In case there is some node in the tree
			if (k < r->key)										//If data to be inserted is lesser than current node
			{
				r->left = insertNode(k, r->left,l,f);
				if ((r->calculateHeight(r->left) - r->calculateHeight(r->right)) == 2 || (r->calculateHeight(r->left) - r->calculateHeight(r->right)) == -2)
					if (k < r->left->key)
						r = rotateRR(r);
					else
						r = rotateRL(r);
			}
			else if (k > r->key)								//If data to be inserted is greater than current node
			{
				r->right = insertNode(k, r->right,l,f);
				if ((r->calculateHeight(r->left) - r->calculateHeight(r->right)) == 2 || (r->calculateHeight(r->left) - r->calculateHeight(r->right)) == -2)
					if (k > r->right->key)
						r = rotateLL(r);
					else
						r = rotateLR(r);
			}
			else
			{													//If the data is a duplicate
				cout << "Here will be the linked list of duplicates" << endl;
				r->list.insert(k);
			}

		}
		r->height = r->max(r->calculateHeight(r->left), r->calculateHeight(r->right)) + 1;			//Calculating the height
		return r;																					//Returning the updated tree
	}
	AVLNode<T>* rotateRR(AVLNode<T>* v1)
	{
		AVLNode<T>* v2 = new AVLNode<T>;
		v2 = v1->left;
		v1->left = v2->right;
		v2->right = v1;
		v1->height = v1->max(v1->calculateHeight(v1->left), v1->calculateHeight(v1->right)) + 1;
		v2->height = v2->max(v2->calculateHeight(v2->left), v1->height) + 1;
		return v2;
	}
	AVLNode<T>* rotateLL(AVLNode<T>* v1)
	{
		AVLNode<T>* v2 = new AVLNode<T>;
		v2 = v1->right;
		v1->right = v2->left;
		v2->left = v1;
		v1->height = v1->max(v1->calculateHeight(v1->left), v1->calculateHeight(v1->right)) + 1;
		v2->height = v2->max(v2->calculateHeight(v2->left), v1->height) + 1;
		return v2;
	}
	AVLNode<T>* rotateRL(AVLNode<T>* v)
	{
		v->left = rotateRR(v->left);
		v = rotateLL(v);
		return v;
	}
	AVLNode<T>* rotateLR(AVLNode<T>* v)
	{
		v->right = rotateLL(v->right);
		v = rotateRR(v);
		return v;
	}
	void inOrdertraversal(AVLNode<T>* r)
	{
		if (r != NULL)
		{
			inOrdertraversal(r->left);
			cout << r->key << " " << r->lineNum << " " << r->fileName << endl;
			inOrdertraversal(r->right);
		}
	}
	//void searchNode()
	//{

	//}
	//void updateNode()
	//{

	//}
	//AVLNode<T>* deletionOfNode(T k,AVLNode<T>* &r)
	//{
	//	/*Node<T>* temp = root;
	//	Node* rec = NULL;
	//	while (temp)
	//	{
	//		if (temp->data == val)
	//			break;
	//		else if (val < temp->data)
	//		{
	//			rec = temp;
	//			temp = temp->left;
	//		}
	//		else if (val > temp->data)
	//		{
	//			rec = temp;
	//			temp = temp->right;
	//		}
	//	}
	//	if (temp->left == NULL)
	//	{
	//		Node* del = temp->right;
	//		rec->right = del;
	//		delete temp;

	//	}
	//	else if (temp->right == NULL)
	//	{
	//		Node* del = temp->left;
	//		rec->left = del;
	//		delete temp;
	//	}
	//	else
	//	{
	//		Node* temp2 = temp->right;
	//		Node* rec2 = NULL;
	//		while (temp2->left != NULL)
	//		{
	//			rec2 = temp;
	//			temp2 = temp2->left;
	//		}
	//		if (rec2 == NULL)
	//			temp->right = temp2->right;
	//		else
	//			rec2->left = temp2->right;
	//		temp->data = temp2->data;
	//		delete temp2;
	//	}*/
	//}
	~AVLTree()
	{

	}
};