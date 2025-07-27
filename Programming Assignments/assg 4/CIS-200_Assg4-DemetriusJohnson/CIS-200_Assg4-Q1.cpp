// CIS-200-_Assg4-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date: 08-04-2021
//Purpose: Implement a template class that demonstrates stack implementation


*/

/*
Question 1:



*/



#include <iostream>
#include "stackADT.h"
#include "stackADT.cpp"  //had to incude both .h and .cpp file of stackADT because of template; compiler needs to build every class instance for type called of the template class
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS



//FUNCTION DECLARATIONS



int main()
{

    cout << "----WELCOME:This program implements a template class that demonstrates stack implementation...BY Demetrius Johnson\n\n";


    stackADT<int> IntStack;
    int x;
    IntStack.Pop(x);
    IntStack.Push(11);
    IntStack.Push(22);
    cout << "int length 1 = " << IntStack.Length() << endl;
    IntStack.Pop(x);
    IntStack.Push(33);
    cout << "int length 2 = " << IntStack.Length() << endl;
    cout << "The int stack contains : " << endl;
    IntStack.Print();
    IntStack.Push(44);
    IntStack.Push(55);
    IntStack.Push(66);
    if (IntStack.IsFull() == false) {
        cout << "\nThe int stack is not full !" << endl;
    }
    else {
        cout << "\nThe int stack is full !" << endl;
    }
    stackADT<int> IntStack2(IntStack);
    cout << "\nThe int stack2 contains : " << endl;
    IntStack2.Print();
    IntStack2.MakeEmpty();
    cout << "\nThe int stack3 contains : " << endl;
    IntStack2.Print();


    stackADT<float> FloatStack;
    float y;
    FloatStack.Pop(y);
    FloatStack.Push(7.1);
    cout << "\nfloat length 1 = " << FloatStack.Length() << endl;
    FloatStack.Push(2.3);
    FloatStack.Push(3.1);
    cout << "float length 2 = " << FloatStack.Length() << endl;
    FloatStack.Pop(y);
    cout << "The float stack contains : " << endl;
    FloatStack.Print();
    stackADT<float> FloatStack2 = FloatStack;
    cout << "\nThe float stack 2 contains:  " << endl;
    FloatStack2.Print();
    FloatStack.MakeEmpty();
    cout << "\nThe float stack 3 contains:  " << endl;
    FloatStack2.Print();









    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

