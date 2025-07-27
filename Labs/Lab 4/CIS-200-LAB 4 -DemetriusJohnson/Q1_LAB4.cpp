// CIS-200-LAB 4 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 12 FEB 2021
//Last Modification Date: 2-12-2021
//Purpose: Test the Assertion function


*/

/*
Question 1.

Implement a function with the following skeleton:

float getSquareRoot( float x)
{
     // add an assert( ) function call here to make sure that x is a positive number
     ….

     // Return the square root of x
         ….
}

You should also implement the following main( ):

int main( )
{
       float a;

       do
       {
             cout << “Input a number: “ ;
             cin >> a;

             cout << “Square root of “  << a   << “= “ << getSquareRoot(a) << endl;
         }while(a > -999);

         
}

Note that you need to add the following statement before using the assert( ) function:

#include <assert.h>

Test your program with different inputs, including a negative number and create a screenshot of the error window popped up by the assert( ).

*/



#include <iostream>
#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS

float getSquareRoot(float x);

//FUNCTION DECLARATIONS



int main()
{


    float a;

    do
    {
        cout << "Input a number: ";
        cin >> a;

        cout << "Square root of " << a << " = " << getSquareRoot(a) << endl;
    } while (a > -999);




    
    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DECLARATIONS BELOW THIS LINE

float getSquareRoot(float x)
{
    assert(x >= 0); // add an assert( ) function call here to make sure that x is a positive number
    

    return sqrt(x);
        
}
