// CIS-200-LAB_11 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 15 April 2021
//Last Modification Date: 04-19-2021
//Purpose: Use a tree struct node to demonstrate the structure of a Binary Search Tree data type
*/

/*
Question 1:

Question 1  Tree
In this assignment, perform the following four coding tasks:
(1)	Create a struct TreeNode
(2)	Use this TreeNode to construct a binary search tree based on the following input queue:
                  F,  A,  B,  M,  C, Q

(3)	Use Inorder Traversal to print out the content of this tree

You need to provide screenshots of your code and running result.

*/



#include <iostream>
#include "BinarySearchTree.cpp" //had to just use a cpp file since template classes require more than just the declaration (because of how the compiler works at compile time)
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS



//FUNCTION DECLARATIONS




int main()
{
    cout << "--WELCOME: This program uses a tree struct node to demonstrate the implementation of a Binary Search Tree data type--\n--BY Demetrius Johnson--\n\n\n";


    BST<char> charBST;

    cout << "Below is the In-Order print of a char Binary Search Tree:\n\n";
    charBST.insert('F');
    charBST.insert('A');
    charBST.insert('B');
    charBST.insert('M');
    charBST.insert('C');
    charBST.insert('Q');
    //charBST.remove('B'); //used for testing; function works but it is defective because then destructor will no longer work

    charBST.print_InOrder();

    //did some additional testing below with a different data type to see if my program would hold up!

    BST<int> intBST;

    cout << "\n\n\n\nBelow is the In-Order print of an int Binary Search Tree:\n\n";
    intBST.insert(1);
    intBST.insert(4);
    intBST.insert(-4);
    intBST.insert(10);
    intBST.insert(33);
    intBST.insert(7);
   

    intBST.print_InOrder();


    cout << endl << endl << "\n\n\nThe program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

