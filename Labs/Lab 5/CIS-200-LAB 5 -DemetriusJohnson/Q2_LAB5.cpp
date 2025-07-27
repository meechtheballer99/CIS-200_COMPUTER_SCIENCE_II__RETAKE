// CIS-200-LAB 5 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 19 FEB 2021
//Last Modification Date: 2-19-2021
//Purpose: demonstrate the use of class constructors and operator overloading


*/

/*
Question 2: Class Constructors and Operator Overloading


Create a class called Student, which contains the following data members:

private:
        int x;
protected:
        float y;

Class Student should include the following member functions:

(1)	Default constructor that sets x and y to 0 and 0.0, respectively
(2)	Parameterized constructor that take two input arguments: int a, float b
(3)	Copy constructor
(4)	Overloading of “=” operator


Implement a main( ), in which you need to design test cases to test each of the above member functions.

Create screenshots to show the results.

*/



#include <iostream>
#include<assert.h>
using namespace std;


//CLASS DECLARATIONS

class Student {

public:

    Student() { x = 0; y = 0.0; }                                                       //(1)	Default constructor that sets x and y to 0 and 0.0, respectively
    Student(int a, float b) { x = a; y = b; }                                        //(2)	Parameterized constructor that take two input arguments : int a, float b
    Student(Student& copyObj) { this->x = copyObj.x; this->y = copyObj.y; }         //(3)	Copy constructor

    Student& operator=(Student &copyObj) {
        this->x = copyObj.x;
        this->y = copyObj.y;
        return *this;
    }                                                                             //(4)	Overloading of " = " operator

    int get_X_Val(void) { return x; } //need getter function since x and y are inaccessible outside of this class (they are not public data members)
    float get_Y_Val(void) { return y; }
private:

    int x;

protected:

    float y;

};

//CLASS DECLARATIONS



int main()
{

    cout << "-------WELCOME TO THE SIMPLE CLASS CONSTRUCTOR AND '=' OPERATOR OVERLOAD DEMONSTRATION PROGRAM ---BY Demetrius JOhnson--------\n\n\n";
    //remember a constructor is a function that is called when an object is first declared and needs to be built (memory needs to be allocated for the variable and its data attributes assigned a value)

    Student one; //this will call the default constructor --> the object is being constructed and the declaration takes no parameters; attributes will be set to a default value specified in the function
    cout << "After initializing 'Student one': Student one --> " << "x = " << one.get_X_Val() << " y = " << one.get_Y_Val() << "  //Default Constructor called" << endl << endl;
    Student two(2, 2.2); //this will call the parameterized constructor --> the object is being contructed and the declaration includes paramters that will set attribute values to a non-default value
    cout << "After initializing 'Student two(2, 2.2)': Student two --> " << "x = " << two.get_X_Val() << " y = " << two.get_Y_Val() << " //Parameterized Constructor called" << endl << endl;
    Student three(two);  //this will call the copy constructor function
    cout << "After initializing 'Student three(two)': Student three --> " << "x = " << three.get_X_Val() << " y = " << three.get_Y_Val() << "  //Copy Constructor called" << endl << endl;
    Student four = two; //this is a form of initialization using the assginment operator that will call also call the copy constructor function
    cout << "After initializing 'Student four = two': Student four --> " << "x = " << four.get_X_Val() << " y = " << four.get_Y_Val() << "  //Copy Constructor called" << endl << endl;
    four = one; //this will call the overloaded assignment operator (=) function 
                //although this is overloaded, since there are no pointer attributes and the function I wrote essentially does a memberwise copy, 
                //it function as the default =operator (non-overloaded)
    cout << "After setting 'four = one': Student four --> " << "x = " << four.get_X_Val() << " y = " << four.get_Y_Val() << "  //Overloaded Assignment Operater (=) called" << endl;


    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

