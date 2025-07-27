// CIS-200-LAB_6-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 08 MONTH 2021
//Last Modification Date: 03-08-2021
//Purpose: implement a recursive function that conducts a binary search


*/

/*
Question 2:

Implement a recursive function that conducts a binary search with the following interface:

bool BinarySearch (int info[ ],  int x,  int fromLoc, int toLoc, int &step);
//  info[fromLoc, toLoc] stores an ordered list
// step:  the number of search step of this binary search
//  x --  a search item
//  if x is in the list, return true; otherwise, return false


Test cases:
#define LEN 10000
int info[LEN];
for(int i=0; i< LEN; i++)
    info[i] = i;

int step;

cout << BinarySearch(info, 997, 0, LEN-1, step)  << endl;
cout << “Binary search steps: “ << step << endl;

cout << BinarySearch(info, 20000, 0, LEN-1, step) << endl;
cout << “Binary search steps: “ << step << endl;



*/



#include <iostream>
#define LEN 10000
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS
bool BinarySearch(int info[], int x, int fromLoc, int toLoc, int& step);
//FUNCTION DECLARATIONS



int main()
{

    cout << "-----WELCOME: This program tests the implementation of a recursive function that conducts a binary search.\n----by Demetrius Johnson\n\n";
    cout << "Note that the Time Complexity for a binary search is log_2(N)\n\n\n";
    int info[LEN];

    for (int i = 0; i < LEN; i++) { info[i] = i; } //set every element of the array equal to its element position (0 - 9999)

    int step = 0; //initiate step counter to 0 steps --> first call to binarySearch recursive function 

    cout << "For binary search of 9997 from sorted info array 0-9999 ";
    cout << "(True = 1 or False = 0): " << BinarySearch(info, 9997, 0, LEN - 1, step) << endl << endl;
    cout << "Binary search steps: " << step << endl << endl;
    cout << "Expected binary search steps based on known Time Complexity of log_2(N): log_2(9997) = 13.287\n\n\n\n\n";

    step = 0; //reset step counter
    cout << "For binary search of 20000 from sorted info array 0-9999 ";
    cout << "(True = 1 or False = 0): " << BinarySearch(info, 20000, 0, LEN - 1, step) << endl << endl;
    cout << "Binary search steps: " << step << endl << endl;
    cout << "Expected binary search steps based on known Time Complexity of log_2(N): log_2(10000) = 13.287; \n20000 is not in the array so expect search to be worst case.\n\n";






    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE



//  info[fromLoc, toLoc] stores an ordered list
// step:  the number of search step of this binary search
//  x --  a search item
//  if x is in the list, return true; otherwise, return false

bool BinarySearch(int info[], int x, int fromLoc, int toLoc, int& step) {

    int midPoint = (fromLoc + toLoc) / 2; //set new midpoint every time this function is called using the passed in from and to location values
    int From_To_Distance = toLoc - fromLoc;
    step++; //increase by the number of times this function is called

    if (x == info[midPoint]) { return true; } 

    if (x > info[midPoint] && From_To_Distance > 1) { //ensure from and to location difference is greater than 1 so that the function will not loop
        

        fromLoc = midPoint;
        return BinarySearch(info, x, fromLoc, toLoc, step); 
    }

    if (x < info[midPoint] && From_To_Distance > 1) { //ensure from and to location difference is greater than 1 so that the function will not loop

        toLoc = midPoint;
        return BinarySearch(info, x, fromLoc, toLoc, step);
    }

    if (From_To_Distance < 2) { //need this for the case where FROM and TO is a difference of only 1 or 0 in terms of position; 
                                 //EXAMPLE: (1+2)/2  = 1 --> (1+2)/2 = 1....repeating from above functions assigning from and to and a new midpoint that will keep resulting in 1; same scenario for FROM = TO.
        
        if (x == info[fromLoc] || x == info[toLoc]) { return true; }
        else { return false; }
    
    } //value not found case (or valued found at the last two locations to search)
}

