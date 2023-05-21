  # File Indexing using Trees

## Data Structures Project Documentation

Our project utilizes three types of trees: Red-Black Tree, AVL Tree, and B-Tree. These trees are employed for file indexing and replicate the functionality of a Database Management System (DBMS).

## B-Trees

### 1. The DataSet Class

This class defines the data structure used in our B-Tree. Each object of this class stores one line read from the CSV files. The data is set using a constructor.

### 2. The BTree Class

The BTree class contains the root node. To initiate the project, an object of this class is created in the menu function. All the functions, such as traverse, are called on this object. This class also includes functions to operate on the root node.

### 3. The Node Class

The Node class contains arrays of DataSet objects and an array that points to the child pointers of the Node's object. It also includes functions to operate on each individual node.

## Project Operation

The project operates by calling a menu function in Main. The menu function displays a prompt to input the degree of the B-Tree and presents a menu of options to choose from:

1. Read the File and Construct the B-Tree:
   - This option constructs a B-Tree with the details read from the given CSV file. It creates files in the subfolder /Node/ with <id>.txt as the name. This operation calls the insert(DataSet) function on the BTree object.

2. Do a Point Search:
   - This option prints out tuples for a given index. If multiple entries exist with the same ID, it displays multiple tuples. This operation calls the traversePoint() function on the BTree object.

3. Specify an Index Range to Search:
   - This option prints all the tuples within a given range of ID. This operation calls the traversePoint() function on the BTree object.

4. Delete a Tuple:
   - This option deletes the tuple from the B-Tree and also deletes the file corresponding to the tuple in the Nodes subfolder.

5. Edit a Tuple:
   - This option provides further options to edit and update the file that was created before.

6. Display the Whole Database:
   - This option displays the entire database using the print() function on the BTree object.

7. Exit:
   - This function exits the program and releases the dynamically allocated memory.

## Red-Black Trees

The Red-Black Tree implementation in this project consists of the following components:

1. RbNode Class:
   - Contains the implementation for a single Red-Black Tree node.

2. RbTree Class:
   - Contains the implementation for the Red-Black Tree class with functionalities such as insertion, retrieval, color checking, and rotations.

3. FileReaderRB():
   - Reads the given CSV files and constructs a Red-Black Tree for the specified key.

4. RBMenu():
   - Displays different options for indexing on the Red-Black Tree.

5. saveRBinFile():
   - Saves the constructed Red-Black index tree in a text file. The file contains the node data (key, line number, file name).

6. LoadRBfromFile():
   - Loads the Red-Black Tree from the created index file, which contains information about the Red-Black Tree nodes.

7. PointSearch():
   - Prints the data for a given key by receiving the file name and line number as arguments.

## AVL Trees

The AVL Tree implementation in this project consists of the following components:

1. AVLNode Class:
   - Nodes for AVL Trees. Each node holds the necessary data and has constructors to initialize the node. There is also a destructor to deallocate memory.

2. AVLTree Class:
   - Represents the AVL Tree and contains the root node. It provides functions for basic tree operations.

3. AVLLoad():
   - Loads the tree from a file.

4. AVLFileReader():
   - Reads the specified files, performs indexing, and stores the information about each index in the tree. It then stores the tree in a file.

5. AVLMenu():
   - Displays a menu for AVL indexing of the data. Other functions, such as AVLID, AVL113, and AVLCause, call the file reader function to construct the tree according to the specified index option.

To proceed with the program, it is necessary to first read the files and construct the B-Tree. During the construction of the B-Tree, for each line in all files (10 files), the node details are also stored in a file in a subfolder `/Nodes/`.

## Prerequisites

Ensure that a file named `------.csv` is present in the folder where the program is being run.

  ## License

This project is licensed under the [MIT License](LICENSE).

  ## Authors
- [Vaneeza](https://github.com/Vaneeza-7)
- [Rabail](https://github.com/Rabail-RN)
- [Ayesha](https://github.com/ayeshasajid1034)
  


 
