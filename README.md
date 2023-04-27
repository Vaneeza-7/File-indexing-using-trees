# File-indexing-using-trees

                                              Data Structures  
                                             Project Documentation 
 
Our Project has 3 trees. Red Black tree, AVL tree and B tree to perform file indexing and replicate a functionality as that of a DBMS. 

## B-Trees
  
### 1-The DataSet Class
 
This class defines the Data that we have to contain in our BTree. One object of this class stores one line read from the CSV files.The data is set using a constructor. 
 
### 2-The Btree Class
 
This tree contains the root of Node. To start the project we create an object of this class	 in the menu function. We call all the functions on this object. Like traverse etcetera. 
 
This class also has functions to operate on the root node. 
 
### 3-The Node 	Class
 
This class has arrays of DataSet 	Objects and an array that points to the Child pointers	 of Node’s object. 
 
This class also has functions to operate on each individual node. 
 
### Project Operation  
 
This project operates by calling a Menu Function in Main. The Menu function displays a prompt to input Degree of BTree, then it displays the menu. We are prompted to select from the given options. The options are 

Read the File and Construct the B Tree 
 
This option constructs Btree with the details it reads from the given CSV file. It also creates files in a subfolder /Node/ with <id>.txt as name. For this operation we call insert(DataSet) 	function on BTree object.	 
 
### 1.	Do a point search 
 
It prints out tuples for a given index. It will display multiple tuples if there 	 exists multiple entries with the same ID. We call traversePoint() 	function	 for this on a BTree object. 
 
 
### 2.	Specify an index range to search 
 
This prints all the tuples within a given range of ID.We call traversePoint()	 function for this on a BTree object. 
 
### 3.	Delete a tuple 
 
This deletes the tuple from the BTree and also deletes the file for corresponding tuple in the Nodes subfolder. 
 
### 4.	Edit a tuple 
 
This option further gives us options on what to edit, and it edits and updates the file it had created before. 
 
### 5.	Display the whole Database 
 
This displays the whole database using function print() on object of the	  BTree. 
 
### 6.	Exit 
 
This function Exits the program and relieves the memory that has been dynamically allocated. 
  
  ## Red Black Trees:
### 1.	Rb Node class:
Contains implementation for a single red-black tree node.
### 2.	Rb Tree class
Contains implementation for red, black tree class with the insertion, retrieve, check color, rotations etc. functionalities.
### 3.	FileReaderRB()
Reads the given csv files and constructs a red-black tree for the specified key.
### 4.	RBMenu()
Displays different options for indexing on red-black tree
### 5.	saveRBinFile()
saves the constructed red-black index tree in a txt file.
The file contains the node data (key, line number, file name).
### 6.	LoadRBfromFile()
This function loads the red-black tree from the created index file which contains information about red black tree nodes.
### 7.	PointSearch()
This functions prints the data for a given key by receiving file name and line number as arguments.
## AVL Trees:
### AVLNode class:
Nodes for AVL trees and all the data each node of the tree has to hold will be present in this class.
The class has constructors to initialize the node. A single node will have two pointers for left and right children of the node, variables to store key, line number on which the key is and the filename having the key. There is also a destructor to deallocate all the memory.
### AVLTree class:
This class has root of AVLNode type. There is a constructor and other functions for all the basic functionalities on the tree.
### AVLLoad:
This function is used to load the tree from the file.
### AVLfilereader:
This function reads all the files given and performs indexing and stores the information about each index in the tree. It then stores the tree in a file.
### AVLMenu:
This function shows a menu for AVL indexing of the data.
Other functions such as AVLID, AVL113, AVLCause etc. call the file reader function to construct tree according to the index option which user will specify.

To Proceed with the program we must first read the Files and Construct the BTree. When the BTree is constructed for each line in all files 10 files. As per the requirement all nodes’ details are also stored in a file in a subfolder /Nodes/. 
 
Prerequisites  
 
File named “ ------.csv ” must be present in the folder where the program is being run. 
 
