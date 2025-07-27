// CIS-200_Assg3-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Demetrius E Johnson
//Date: 22 MAR 2021
//Last Modification Date: 03-22-2021
//Purpose: implement unsorted linked list

/*
Question 1 (30 points)

Given the following skeleton of an unsorted list class that uses an unsorted linked list:

template<class ItemType>
struct NodeType
{
	ItemType item;
	NodeType*  next;
};

template<class ItemType>
class UList
{
public:
	UList();  // default constrctor
	UList(const UList &x);  // we implement copy constructor with deep copy
	UList& operator = (UList &x); // equal sign operator with deep copy
	bool IsThere(ItemType item) const;  // return true of false to indicate if item is in the list
	void Insert(ItemType item);  // if item is not in the list, insert it into the list
	void Delete(ItemType item);  //  delete item from the list
	void Print();  // Print all the items in the list on screen
	int Length();   // return the number of items in the list
	~UList();  // programmer should be responsible to deallocate the linked list
private:
	NodeType<ItemType> * listPtr;
};

Task 1: Implement the template class UList on the basis of the above skeleton.  Compile your program.
Task 2: Write a simple driver that reads values from file float.dat, inserts them into an instance, x, of the list, prints the length of the final list, and prints the values of all the list elements.
Task 3: Add code to your driver to test the remaining member functions. Delete 2.0, 9.0, and 6.2 from x and print the list to be sure they are gone.
Task 4: Create another instance, y, through the copy constructor such that the content of y is the same as that of x, but a deep copy should be done. Print out the all the list elements of y.
Task 5: Declare an instance, z, and assign the content of x to z through the operation “=”. Print out the all the list elements of z.
Task 6: Test if 9.0 is in the lists x and y via the member function: IsThere(ItemType item) and print out the test results.
Task 7: What is the Big-O notation for the time complexity of IsThere( ) function?


*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ulist.h"
#include "ulist.cpp" //I had to add the inclusion of .cpp file of the ulist class to avoid the link error 
					//I was getting due to my classes implementing template classes; nonetheless I wanted my code to be easier to read so I still separated the ulist class

using namespace std;


//FUNCTION DECLARATIONS
template<typename ItemType>
void ReadFromFile(ifstream& InputStream, UList<ItemType>& list); //use this function to read from the file




int main()
{
    cout << "---WELCOME: this program tests the implementation of an UNSORTED linked list  ----By Demetrius Johnson\n\n\n";

	//stringstream ss;
	//string string_float;
	ifstream IFS("float.dat");
	if (!IFS.is_open()) { cout << "\n\n~FILE NOT OPENED SUCESSFULLY~\n\n"; }
	else { cout << "~'float.dat' file opened successfully...\n\n"; }

	//float test;
	//IFS >> test;
	//IFS >> string_float;

	//TASK 2: : Write a simple driver that reads values from file float.dat, 
	//inserts them into an instance, x, of the list, prints the length of the final list, and prints the values of all the list elements.

	UList<float> x;
	ReadFromFile(IFS, x);
	cout << "\nThe values stored in the 'float.dat' were placed in linked list 'x':\n\n";
	x.Print();
	

	//Task 3: Add code to your driver to test the remaining member functions.Delete 2.0, 9.0, and 6.2 from x and print the list to be sure they are gone.
	x.Delete(2.0);
	x.Delete(9.0);
	x.Delete(6.2);
	x.Insert(55.0); //testing the insert function

	cout << "\n\nAfter calling the delete function for 2.0, 9.0, and 6.2; and insert function for 55.0, the values stored in the 'x' are:\n\n";
	x.Print();
	cout << "\n*Notice: items not deleted remain in the list, including 6, since 6.2 was called for deletion but not in the list.\n";
	


	//Task 4: Create another instance, y, through the copy constructor such that the content of y is the same as that of x, 
	//but a deep copy should be done. Print out the all the list elements of y.

	UList<float> y(x);
	cout << "\n\nAfter calling the copy constructor for 'y', another linked list, the values of 'y' are:\n\n";
	y.Print();


	//Task 5: Declare an instance, z, and assign the content of x to z through the operation=. Print out the all the list elements of z.
	UList<float> z;
	z = x;
	cout << "\n\nAfter calling the operator= for 'z = x', the values of 'z' are:\n\n";
	z.Print();

	//Task 6: Test if 9.0 is in the lists x and y via the member function : IsThere(ItemType item) and print out the test results.
	cout << "\n\nTesting the IsThere(ItemType item) function to see if x or y has 9.0 in their perspective lists:\n";
	cout << "Is 9.0 in 'x' (1 = true, 0 = false): " << x.IsThere(9.0) << endl;
	cout << "Is 9.0 in 'y' (1 = true, 0 = false): " << y.IsThere(9.0) << endl;

	//Task 7: What is the Big - O notation for the time complexity of IsThere() function ?
	//answer: O(N) since I only implemented 1 while loop in my function that searches from the first node to the last node in the linked list.

	IFS.close();
    cout << "\n\n\n~....Program has finished...exiting....\n";
    system("pause");


    return 0;


}


//FUNCTION DEFINITIONS:

template<typename ItemType>
void ReadFromFile(ifstream& InputStream, UList<ItemType>& list) {


	ItemType T;

	
	while (InputStream >> T) { //use this loop to read all values from the file into the linked list; when the stream fail bit is set then the while loop will exit

		list.Insert(T);
		

	}
	


}