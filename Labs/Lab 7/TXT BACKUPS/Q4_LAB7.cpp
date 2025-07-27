// CIS-200-LAB 7 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 19 MONTH 2021
//Last Modification Date: 03-21-2021
//Purpose: demontrate the use of try-catch-throw exception handling blcoks


*/

/*
Question 4:



*/



#include <iostream>
//#include <string>
//#include<stdexcept>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS



//FUNCTION DECLARATIONS



int main()
{
	cout << "----WELCOME to the simple try-throw-catch program ---BY Demetrius Johnson\n\n";
	cout << "Enter a value for x: 'q' to quit program, 'a' to throw int, 'c' to throw string literal, or input any other character.\n\n";

	char x9;

	cout << "x = ";
	cin >> x9;

	while (x9 != 'q'){
		
		try {
			switch (x9)
			{
			case 'a':
				throw 10; //throw an int literal
				break;
			case 'c':
				throw "picture"; //throw a string literal
				break;
			}
		}

		// Write two exception handlers here. Inside each exception handler, 
		// use cout to print a message
		catch (int x9_int_catch) {
		
			cout << "\n~THROWN EXCEPTION caught of type int: " << x9_int_catch << endl << endl;

		}
		catch (const char* x9_string_catch) { //need to use const char* since a string literal is techinically a const char[] array 
		
			cout << "\n~THROWN EXCEPTION caught of type string: " << x9_string_catch << endl << endl;
		
		}
		
		cout << "x = ";
		cin >> x9;

	}




    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

