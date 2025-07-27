// CIS-200-LAB_8-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
//Author: Demetrius E Johnson
//Date: April 27, 2021
//Last Modification Date: April 27, 2021
//Purpose: This program demonstrates how to output beginning memory addresses


*/

/*
Question 2:

//In the following main( ) function, try to find a way to print out the beginning memory address of each variable.

*/



#include <iostream>
//#include<assert.h>
using namespace std;





int add(int x, int y)
{
    return (x + y);
}

int main()
{
   cout << "---Welcome: This program demonstrates how to output beginning memory addresses\n--By Demetrius Johnson\n\n";


   int a = 10;
   float b = 3.14;
   char c = 'j';
   char d[80];

    // print out the beginning memory address of the above 4 variables
    // as well as the memory address of function add( )
   cout << "The beggning memory address of an array or function is its name;\nfor normal variables, the beginning address is simply the name using the & operator.\n";
   cout << "A sepcial case for normal variables or for an array, is when you have a char variable or char array,\nthe &operator or ";
   cout << "name of char array fails so you must cast it as a (void*) pointer" << endl;
   cout << "and output the value stored by the casted pointer that is storing the address\nof the char or start address of the char array.\n\n";


   cout << "For example: 'add' is a function name, 'a' is an int, 'b' is a float, 'c' is a char, and 'd' is a char array, thus:\n\n";
   cout << "cout << add --> " << add << endl;
   cout << "cout << &a --> " << &a << endl;
   cout << "cout << &b --> " << &b << endl;
   cout << "cout << (void*)&c --> " << (void*)&c << endl;
   cout << "cout << (void*)d --> " << (void*)d << endl;

   cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
   system("pause");

    return 0;

    
}


