// CIS-200-LAB_8-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
//Author: Demetrius E Johnson
//Date: April 26, 2021
//Last Modification Date: April 26, 2021
//Purpose: This program demonstrates the use of a linked list using a struct and some basic functions


*/

/*
Question 2:

//Write a function called printlist that takes a pointer to the start of a char linked list and prints 
//out all the nodes in the list in sequence. 

*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS
struct listrec
{
    char value;
    struct listrec* next;
};

void printlist(listrec* start_of_linked_list);  // print out all the nodes in the list


//FUNCTION DECLARATIONS



int main()
{
    cout << "---Welcome: This program demonstrates the use of a linked list using a struct and some basic functions\n--By Demetrius Johnson\n\n";

    listrec char_LinkedList; //create a linked list; this node will keep the starting address of the list as well
    listrec* char_linkedList_Ptr = &char_LinkedList; //use this ptr to navigate through the linked list

    char_linkedList_Ptr->value = 'a'; //set value of FIRST node
    char_linkedList_Ptr->next = new listrec; //allocate memory for next node
    char_linkedList_Ptr = char_linkedList_Ptr->next; //move to next node
    char_linkedList_Ptr->value = 'c'; //set value of SECOND node
    char_linkedList_Ptr->next = new listrec; //allocate memory for next node
    char_linkedList_Ptr = char_linkedList_Ptr->next; //move to next node
    char_linkedList_Ptr->value = 'W'; //set value of THIRD node
    char_linkedList_Ptr->next = nullptr; //we have inserted all items; set end of list to nullptr so we have a denotation for the end.
   
    cout << "The values stored in the char linked list are: \n\n";
    printlist(&char_LinkedList);

    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

void printlist(listrec* LinkedList_Ptr) {

    while (LinkedList_Ptr != nullptr) {

        cout << LinkedList_Ptr->value << " "; //cout value of current node
        LinkedList_Ptr = LinkedList_Ptr->next; //move to next node

    }

}  // print out all the nodes in the list