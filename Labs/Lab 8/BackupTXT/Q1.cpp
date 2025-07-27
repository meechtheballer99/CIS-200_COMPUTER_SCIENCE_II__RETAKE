// CIS-200-LAB_8-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
//Author: Demetrius E Johnson
//Date: April 26, 2021
//Last Modification Date: April 26, 2021
//Purpose: This program demonstrates the use of a linked list using a struct and some basic functions


*/

/*
Question 1:

//Write a function called listsize that takes a pointer to the start of a linked list and returns the number of elements in the list,  
//and another function called listsum that also takes a pointer to the start of a linked list and returns the sum of the values of all elements in the list. 
//In your main routine, you need to print out the results of these two functions on computer screen.

*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS
struct listrec
{
    int value;
    struct listrec* next;
};

int listsize(listrec* LinkedList_Ptr); // takes a pointer to the start of a linked list and returns the number of elements in the list
int listsum(listrec* LinkedList_Ptr); //takes a pointer to the start of a linked list and returns the sum of the values of all elements in the list

//FUNCTION DECLARATIONS



int main()
{
    cout << "---Welcome: This program demonstrates the use of a linked list using a struct and some basic functions\n--By Demetrius Johnson\n\n";

    listrec int_LinkedList; //create a linked list; this node will keep the starting address of the list as well
    listrec* int_linkedList_Ptr = &int_LinkedList; //use this ptr to navigate through the linked list

    int_linkedList_Ptr->value = 4; //set value of FIRST node
    int_linkedList_Ptr->next = new listrec; //allocate memory for next node
    int_linkedList_Ptr = int_linkedList_Ptr->next; //move to next node
    int_linkedList_Ptr->value = 5; //set value of SECOND node
    int_linkedList_Ptr->next = new listrec; //allocate memory for next node
    int_linkedList_Ptr = int_linkedList_Ptr->next; //move to next node
    int_linkedList_Ptr->value = 3; //set value of THIRD node
    int_linkedList_Ptr->next = nullptr; //we have inserted all items; set end of list to nullptr so we have a denotation for the end.
   
    cout << "The Number of elements in the int linked list is: " << listsize(&int_LinkedList) << endl << endl;
    cout << "The sum of all the values stored by all the elements in the int linked list is: " << listsum(&int_LinkedList) << endl << endl;

    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

int listsize(listrec* LinkedList_Ptr) {

    int element_counter = 0; //use this to keep track of the size of the linked list

    while (LinkedList_Ptr != nullptr) {
    
        element_counter++; // current node not null; so increase counter to add an element
        LinkedList_Ptr = LinkedList_Ptr->next; //move to next node
    
    }

    return element_counter; //return the number of elements

} // takes a pointer to the start of a linked list and returns the number of elements in the list

int listsum(listrec* LinkedList_Ptr) {

    int sum = 0; //use this to keep track of the sum of the element values in the linked list

    while (LinkedList_Ptr != nullptr) {

        sum += LinkedList_Ptr->value; // current node not null; so add value of the current element
        LinkedList_Ptr = LinkedList_Ptr->next; //move to next node

    }

    return sum; //return sum of all the elements

} //takes a pointer to the start of a linked list and returns the sum of the values of all elements in the list

