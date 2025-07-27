
//Author: Demetrius E Johnson
//Date: 04 MAR 2021
//Last Modification Date: 03-04-2021
//Purpose:

//Question 1  Unsorted List (30 points)

#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#define MAX_ITEMS 10
typedef char ItemType;
//using namespace std;
//Implement a template class UnsortedList as defined by the following skeleton :


   

class UnsortedList
{
private:
    int length;
    ItemType values[MAX_ITEMS];
    int currentPos;

public:
    UnsortedList();  // default constructor: lenght=0, currentPos=-1
    void MakeEmpty();    // let length=0
    void InsertItem(ItemType x);   // insert x into the list     
    void DeleteItem(ItemType x);  // delete x from the list
    bool IsFull();   // test if the list is full
    int LengthIs();   // return length
    void RetrieveItem(ItemType& x, bool& found); // retrieve x from the list, the boolean result is stored in found
    void ResetList();  // currentPos = -1
    void GetNextItem(ItemType& x);    // get the next element from the list with respect to the currentPos
    void printElement();  // print out the values of all the list elements, separated by a white space 
};


#endif