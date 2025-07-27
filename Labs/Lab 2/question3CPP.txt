// CIS 200 - LAB 2 - WINTER 2021 - DEMETRIUS JOHNSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 4 FEB 2021
//Last Modification Date:
//Purpose: use the concept of a macro --> preprocessor function/operation replacement directive


*/

/*

Question 3 (2.5 points)

Define a macro, getmin(a, b), by using #define …
getmin(a, b) returns a if a < b; otherwise return b.

Write a simple main( ) below:

int main( )
{

          int a = 5,  b = 10;

          cout << getmin(a, b) << endl;
        float x = 3.1,  y = 6.4;
        cout << getmin(x, y) << endl;

       return 0;
}




*/

#include <iostream>
#define getmin(a, b) (a < b ? a : b)
using namespace std;

int main()
{

    cout << "WELCOME-----This program shows the use of a macro function---By Demetrius Johnson-----\n\n";
    cout << "The macro function is: #define getmin(a, b) (a < b ? a : b)\n\n";

    
    int a = 5, b = 10;
    cout << "int a = 5, b = 10\n\n";
    cout << "Pre - processor directive will replace the getmin(a, b) with statement --> (5 < 10 ? 5 : 10)\n --> result: ";
    cout << getmin(a, b) << endl << endl; //pre-processor directive will replace the getmin(a,b) with statement (5 < 10 ? 5 : 10) 

   
    float x = 3.1, y = 6.4;
    cout << "\nfloat x = 3.1, y = 6.4;\n";
    cout << "\nPre-processor directive will replace the getmin(x,y) with statement --> (3.1 < 6.4 ? 3.1 : 6.4)\n  --> result: ";
    cout << getmin(x, y) << endl; //pre-processor directive will replace the getmin(x,y) with statement (3.1 < 6.4 ? 3.1 : 6.4) 


    cout << "\n\n ~program has finished...thank you..goodbye(:...\n\n";

    system("pause");

    return 0;
    
}