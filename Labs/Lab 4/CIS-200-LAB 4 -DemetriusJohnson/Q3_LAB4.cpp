// CIS-200-LAB 4 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 12 FEB 2021
//Last Modification Date: 2-12-2021
//Purpose: practice using break points


*/

/*
Question 3.

Implement the following factorial( ) and main( ):

Int factorial( int n)
{
          If(n == 1)
               Return 1;
          Else
               Return( n* factorial(n-1));   // position 2
}

int main( )
{
       int c=3;

       cout << “factorial(3)= “  << factorial(c) << endl;      // position 1

       return 0;
}

(1)	Set a regular breakpoint at position 1 and then use step-into button to step into factorial( ).
(2)	Inside the factorial( ), use step-over button to move to position 2 and use step-into button to step into the factorial( ) again
(3)	Repeat the above step 2 until the recursion finishes the calculation and comes back to the main( )

Make a screenshot at position 1 and each position 2 at different recursive levels.


*/



#include <iostream>
using namespace std;
//FUNCTION DECLARATIONS
int factorial(int n);
//FUNCTION DECLARATIONS

int main()
{
    int c = 3;

    cout << "factorial(3) = " << factorial(c) << endl;      // position 1

    
    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}
//FUNCTION DEFINITIONS BELOW THIS LINE
int factorial(int n){


    if(n == 1)
        return 1; //base case
    else
        return(n * factorial(n - 1));   // position 2  //recursive case
}