// CIS-200-LAB_6-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 08 MONTH 2021
//Last Modification Date: 03-08-2021
//Purpose: test the use of a recursive function


*/

/*
Question 1:

Write a recursive function defined by the following recursive formula:

foo (Y, X) =
    Y                                                            if  X = 1
    1                                                             if  X = Y
    (foo ( Y-1, X-1) + 4* foo ( Y-1, X))      if Y > X  > 1

Write a driver to print out the value for foo (5, 3)    and foo (6, 5).

In addition, print out the total number of recursive function calls in each case.



*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS

int recursiveFunction(int Y, int X, int& numRecFunc_calls);

//FUNCTION DECLARATIONS



int main()
{
    int numberOfRecFCalls = -1; //first call will cause this to go to 0; the first call is not a recursive call

    cout << "-----WELCOME: This program tests the use of a recursive function ----by Demetrius Johnson\n\n\n";



    cout << "Output for recursive function calls for input (5, 3): " << recursiveFunction(5, 3, numberOfRecFCalls) << endl;
    cout << "Number of recursive calls of the function: " << numberOfRecFCalls;

    numberOfRecFCalls = -1;
    cout << "\n\nOutput for recursive function calls for input (6, 5): " << recursiveFunction(6, 5, numberOfRecFCalls) << endl;
    cout << "Number of recursive calls of the function: " << numberOfRecFCalls;

    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

int recursiveFunction(int Y, int X, int& numRecFunc_calls) {

    numRecFunc_calls++;
    if (X == 1) { return Y; }
    if (X == Y) { return 1; }
    if(X > 1 && X < Y) { return recursiveFunction((Y - 1), (X - 1), numRecFunc_calls) + (4 * recursiveFunction(Y - 1, X, numRecFunc_calls)); }

}