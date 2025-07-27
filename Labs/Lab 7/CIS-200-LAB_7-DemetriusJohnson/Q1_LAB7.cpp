// CIS-200-LAB 7 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 16 MAR 2021
//Last Modification Date: 03-16-2021
//Purpose: use a template function that can swap many data types


*/

/*
Question 1:

//Design and implement a template function, called swapt(T *p1, T *p2), 
//which takes two parameters with the same generic data type. 
//The function swaps the values of these two parameters.


*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS

template<typename T> 
void swapT(T* p1, T* p2);

//FUNCTION DECLARATIONS



int main()
{

    cout << "WELCOME to the template swap function with pointer arguments program --By Demetrius Johnson\n\n";

    //originally declared values
    int x = 30, y = 40;
    float w = 3.7, v = 1.2;
    string a = "good", b = "morning";

    cout << "Origianl values of x and y (int), w and v (float), and a and b (string):\n\n";
    cout << "x = " << x << "  y = " << y << endl;
    cout << "w = " << w << "  v = " << v << endl;
    cout << "a = " << a << "  b = " << b << endl;

    
    
    //swapping values
    swapT(&x, &y);
    swapT(&w, &v);
    swapT(&a, &b);

    cout << "\n\nSwapped values of x and y (int), w and v (float), and a and b (string):\n\n";
    cout << "x = " << x << "  y = " << y << endl;
    cout << "w = " << w << "  v = " << v << endl;
    cout << "a = " << a << "  b = " << b << endl;


    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

template<typename T>
void swapT(T* p1, T* p2) {

    T holder; 
    holder = *p1;//let holder store the value stored at the address to which p1 points to

    *p1 = *p2; //set the value stored at p1 equal to the value stored at p2
    *p2 = holder; //now set the value stored by p2 equal to the original data value p1 stored

    return;
}