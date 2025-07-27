// CIS-200-LAB 10 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 12 April 2021
//Last Modification Date: 04-12-2021
//Purpose: Demonstrate the use of Polymorphism and Dynamic Binding: one of the corner stones of object-oriented programming in C++

*/

/*
Question 1:

Write a program that uses inheritance and polymorphism. Make a Pet class and let it have a kind of food (string). 
You have a feed() function and a speak() function. Both functions should be virtual functions.
Child classes will have different things depending on what it is. 
Inside the four child classes, you should override the feed( ) and speak( ) functions to generate the specified output.


//notes:

//Dynamic binding (i.e., polymorphism) is one corner stone of the object-oriented programming.
//In C++, we rely on virtual functions and pointers to a base class and its derived classes to implement the polymorphism.

**it gives the capabaility of using one pointer to point to several different but similarly derived objects but with their own unique characteristics
//and take advantage of being able to accessing all of the functions and data members because 
//of dynamic binding (polymorphism of the base class, from which other classes are dereived so as to take on another form of the base class object)

*/

#include <iostream>
#include "Pet.cpp"
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS



//FUNCTION DECLARATIONS



int main()
{

    cout << "---WELCOME: This program demonstrates Polymorphism through Dynamic Binding with virtual functions\n--BY Demetrius Johnson\n\n";

	Pet* nick, * jeff, * chris, * sam;

	nick = new Cat("Meow Mix", "red");
	jeff = new Monkey("Banana", true);
	chris = new Lizard("Flies", 5);
	sam = new Turtle("Lettuce", 0.5);

	nick->feed(); jeff->feed(); chris->feed();
	sam->feed();
	nick->speak(); jeff->speak(); chris->speak();
	sam->speak();
	

    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

