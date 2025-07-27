// CIS-200-LAB 4 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 12 FEB 2021
//Last Modification Date: 2-12-2021
//Purpose:


*/

/*
Question 2.

Implement the following main( ):

int main( )
{
       int a=1, b=2, c=3;

       a++;    b--;    c++;

       cout << a   << b   << c << endl;      // position 1


       a++;    b--;    c++;

       cout << a   << b   << c << endl;      // position 2


       a++;    b--;    c++;

       cout << a   << b   << c << endl;      // position 3

       return 0;
}

When you run this code, what do you see in the DOS window?

Set a regular breakpoint at positions 1, 2, and 3

//Use a stepwise debugging or “continue running” button to show your 
//program does stop at each breakpoint and to 
//show the values of a, b, and c in the local variables window. 
//Create a screenshot at each breakpoint.



*/



#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2, c = 3;

    a++;    b--;    c++;

    cout << a << b << c << endl;      // position 1


    a++;    b--;    c++;

    cout << a << b << c << endl;      // position 2


    a++;    b--;    c++;

    cout << a << b << c << endl;      // position 3
    
    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


