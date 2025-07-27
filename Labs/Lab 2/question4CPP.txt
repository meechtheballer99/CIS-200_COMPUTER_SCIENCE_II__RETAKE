// CIS 200 - LAB 2 - WINTER 2021 - DEMETRIUS JOHNSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 4 FEB 2021
//Last Modification Date: 
//Purpose: Show the use of an inline c++ style function



NOTES:

A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro. (C style)

Inline function is a function that is expanded in-line when it is called. 
When the inline function is called, the whole code of the inline function gets inserted 
or substituted at the point of inline function call.  (C++ style)

*Note, a macro is a the same as an inline function in that the contents are replaced by the compiler at compile time (pre-processor directive)



*/

/*

Question 4 (2.5 points)
Define an inline function, int getmin(int a, int b).
getmin(a, b) returns a if a < b; otherwise return b.

Write a simple main( ) below:

int main( )
{

          int a = 5,  b = 10;

          cout << getmin(a, b) << endl;

         return 0;
}
*/

#include <iostream>
using namespace std;

inline int getmin(int a, int b) { //inline function; no overhead from a function call; automatically the compiler replaces any code that calls this function with its line of code;
                                  //no new memory needed to be allocated as like with a normal function call

    return (a < b ? a : b);


}

int main()
{
    cout << "-----WELCOME: This function shows the use of inline c++ style function -----By Demetrius Johnson\n\n";

    cout << "Inline function:\n\n inline int getmin(int a, int b) { return (a < b ? a : b); }\n\n";
    cout << "Function call:\n\n int a = 5, b = 10;\n\n cout << getmin(a, b) << endl;\n\nOutput results: ";

    int a = 5, b = 10;
    cout << getmin(a, b) << endl;

    cout << "\n\n~Program has finished....thank you....\n\n";

    system("pause");

    return 0;
}