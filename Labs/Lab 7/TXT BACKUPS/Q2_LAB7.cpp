// CIS-200-LAB 7-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 16 MAR 2021
//Last Modification Date: 03-16-2021
//Purpose: implement a template struct


*/

/*
Question 2:

Design and implement a template struct, called Employeet, 
//which contains two data members (id and salary). 
//The data types of id and salary are T1 and T2, respectively.

*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS
template<typename T1, typename T2> 
struct EmployeeT { T1 id; T2 salary; };

//FUNCTION DECLARATIONS



int main()
{

    cout << "\n-----WELCOME to the simple template struct program --BY Demetrius Johnson-----\n\n";


    //declare an instance of Employeet, x, with data types:  int and float 
    EmployeeT<int, float> x;

    //Assign int value (101) and float value (30000.00) to this instance
    x.id = 101;
    x.salary = 30000.00;

    //Print out the values of the data members to computer screen
    cout << "\n\nValues of x data members (of type int and float): id = " << x.id << "  salary = " << x.salary;

    //declare an instance of Employeet, y, with data types:  short and double
    EmployeeT<short, double> y;

    //Assign int value (411) and float value (40000.00) to this instance
    y.id = 411;
    y.salary = 40000.00;

    //Print out the values of the data members to computer screen
    cout << "\n\nValues of y data members (of type short and double): id = " << y.id << "  salary = " << y.salary;


    cout << endl << endl << "\n\nThe program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

