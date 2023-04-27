#pragma once
#include <iostream>
#include <fstream>
using namespace std;
//-------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------- Node Class ----------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------//
template <class N>
class Node
{
public:
	int line;
	string file;
	N data;														//Data in the node
	Node<N>* next;												//Pointer to hold the address of next node
	Node()														//Default constructor
	{
		line = 0;
		file = "";
		data;
		next = NULL;
	}
	Node(N d, int l, string f)									//Parameterized constructor
	{
		line = l;
		file = f;
		data = d;
		next = NULL;
	}
	Node(N d, Node<N>* n, int l, string f)						//Parameterized constructor
	{
		line = l;
		file = f;
		data = d;
		next = n;
	}
	~Node()														//Destructor
	{
		line = 0;
		file = "";
		data = NULL;
		delete next;
		next = NULL;
	}
};
//-------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------- Linked List Class ----------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------//

template <class N>
class LinkedList
{
public:
	Node<N>* head;												//Head(first node) in the list
	LinkedList()												//Default constructor
	{
		head = NULL;
	}
	void insert(N d, int l, string f)								//Function to insert a new node in the list
	{
		if (head == NULL)										//If the list is empty
		{
			Node<N>* n = new Node<N>(d, l, f);
			head = n;
			head->next = NULL;
		}
		else
		{														//If the list is not empty
			Node<N>* temp = new Node<N>;
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node<N>(d, l, f);
			(temp->next)->next = NULL;
		}
	}
	bool isEmpty()												//To check if the list is empty
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	Node<N>* search(N d)										//Function to search some node in the list
	{
		Node<N>* temp = new Node<N>;
		temp = head;
		if (temp->data == d)
		{														//If the first node has the data being searched
			return temp;
		}
		else
		{														//If the first node does not have the data being searched
			while (temp->data != d || temp->next != NULL)
			{
				temp = temp->next;
			}
			if (temp->next == NULL)
			{
				cout << "Data not found in the list." << endl;
				return 0;
			}
			else
			{
				return temp;
			}
		}
	}
	void printLL()
	{
		Node<N>* temp = new Node<N>;
		temp = head;
		while (temp)
		{
			cout << temp->data << " " << temp->line << " " << temp->file << endl;
			temp = temp->next;
		}
	}

	void updateList(N d, int l, string f)							//Function to update some value in the list
	{

	}
	void removeNode(N d, int l, string f)							//Function to remove a node from the list
	{

	}
	~LinkedList()												//Destructor
	{

	}
};