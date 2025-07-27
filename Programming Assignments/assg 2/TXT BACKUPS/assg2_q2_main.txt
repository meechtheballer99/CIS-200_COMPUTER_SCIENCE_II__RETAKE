// CIS-200_Assg2-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Demetrius E Johnson
//Date: 04 MAR 2021
//Last Modification Date: 03-04-2021
//Purpose: write a program using a class that can represent complex numbers

//Question 2  Operator (30 points)




//A complex number is a number of the form: a + b * i,  where a and b are number of type double, and i is a number that represents sqrt(-1). 

#include <iostream>
#include "Complex.h"
using namespace std;


//FUNCTION DECLARATIONS

//FUNCTION DECLARATIONS



int main()
{
    cout << "---WELCOME to the Complex Numbers Program ----By Demetrius Johnson\n\n\n";
    cout << "A complex number is represented in the form z = Real + Imaginary --? a +b*i:\n\nA is a real number, B is a real number, and i = sqrt(-1).\n\n";


   // In your main() function, you should perform the following tests :

    Complex x(2, 2);
    Complex y(4, 3);
    Complex z, w, v, q;
    Complex T(y); //other test variable

    cout << "Testing copy constructor and operator<< : Complex T(y) --> T = " << T << endl;

    z = x + y;
    w = x - y;
    v = x * y;
    q = x / y;

    cout << "\nTest variables: \n\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = x + y = " << z << endl;
    cout << "w = x - y = " << w << endl;
    cout << "v = x * y = " << v << endl;
    cout << "q = x / y = " << q << endl;
    cout << "\nTesting operator== --> is z = w? solution: ";
    if (z == w)
        cout << "z = w" << endl;
    else
        cout << "z != w" << endl;
    
    T = ++x;
    cout << "\nTesting prefix operator++ --> T = ++x:\n\n T = " << T << "\n x = " << x << endl;
    T = x++;
    cout << "\nTesting postfix operator++ --> T = x++:\n\n T = " << T << "\n x = " << x << endl;

   // print out the real and imaginary parts of z, w, v, and q
  

   //In order to print out the values of complex numbers, you may design a public member function print() to do so.

   //You also need to design test cases for ++, << , and copy constructor.







    cout << "\n\n\n~....Program has finished...exiting....\n";
    system("pause");
  

    return 0;

}


//FUNCTION DEFINITIONS:

