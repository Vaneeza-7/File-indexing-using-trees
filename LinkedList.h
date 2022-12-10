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
	N data;														//Data in the node
	Node<N>* next;												//Pointer to hold the address of next node
	Node()														//Default constructor
	{
		data = 0;
		next = NULL;
	}
	Node(N d)													//Parameterized constructor
	{
		data = d;
		next = NULL;
	}
	Node(N d, Node<N>* n)										//Parameterized constructor
	{
		data = d;
		next = n;
	}
	~Node()														//Destructor
	{
		data = 0;
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
	void insert(N d)											//Function to insert a new node in the list
	{
		if (head == NULL)										//If the list is empty
		{
			Node<N>* n = new Node<N>(d);
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
			temp->next = new Node<N>(d);
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
			while (temp->data != d || temp->next!=NULL)
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
	void updateList(N d)										//Function to update some value in the list
	{

	}
	void removeNode(N d)										//Function to remove a node from the list
	{

	}
	~LinkedList()												//Destructor
	{

	}
};