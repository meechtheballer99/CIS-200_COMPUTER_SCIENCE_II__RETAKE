// CIS-200-LAB_6-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 08 MONTH 2021
//Last Modification Date: 03-08-2021
//Purpose: Show use of a Linear search


*/

/*
Question 3:

Implement a function that conducts a linear search with the following interface:

bool LinearSearch (int info[ ],  int x,  int fromLoc, int toLoc, int &step);
//  info[fromLoc, toLoc] stores an ordered list
// step:  the number of search step of this linear search
//  x --  a search item
//  if x is in the list, return true; otherwise, return false


Test cases:
#define LEN 10000
int info[LEN];
for(int i=0; i< LEN; i++)
    info[i] = i;

int step;

cout << LinearSearch(info, 997, 0, LEN-1, step)  << endl;
cout << “Linear search steps: “ << step << endl;

cout << LinearSearch(info, 20000, 0, LEN-1, step) << endl;
cout << “Linear search steps: “ << step << endl;



*/



#include <iostream>
#define LEN 10000
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS
bool LinearSearch(int info[], int x, int fromLoc, int toLoc, int& step);
//FUNCTION DECLARATIONS



int main()
{

    cout << "-----WELCOME: This program tests the implementation of a linear function that conducts a linear search.\n----by Demetrius Johnson\n\n";
    cout << "Note that the Time Complexity for a linear search O(N)\n\n\n";
    int info[LEN];

    for (int i = 0; i < LEN; i++) { info[i] = i; } //set every element of the array equal to its element position (0 - 9999)

    int step = 0; //initiate step counter to 0 steps --> first call to linearSearch function

    cout << "For linear search of 9997 from sorted info array 0-9999 ";
    cout << "(True = 1 or False = 0): " << LinearSearch(info, 9997, 0, LEN - 1, step) << endl << endl;
    cout << "Linear search steps: " << step << endl << endl;
    cout << "Expected linear search steps based on known Time Complexity of O(N): 9998 (0 to 9997 --> 9998 steps)\n\n\n\n\n";

    step = 0; //reset step counter
    cout << "For linear search of 20000 from sorted info array 0-9999 ";
    cout << "True = 1 or False = 0: " << LinearSearch(info, 20000, 0, LEN - 1, step) << endl << endl;
    cout << "Linear search steps: " << step << endl << endl;
    cout << "Expected linear search steps based on known Time Complexity of O(N): 10000. \n20000 is not in the array so expect search to be worst case.\n\n";






    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE



//  info[fromLoc, toLoc] stores an ordered list
// step:  the number of search step of this linear search
//  x --  a search item
//  if x is in the list, return true; otherwise, return false

bool LinearSearch(int info[], int x, int fromLoc, int toLoc, int& step) {

    for(int i = fromLoc; i <= toLoc; i++){
    
        step++;
        if (x == info[i]) { return true; }
        if (i == toLoc) { return false; } //if i increments all the way to toLoc without finding a match from the statement above this, then value is not found so return false
    
    }


   
}



