// CIS-200-_Assg4-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date:  04-09-2021
//Purpose: Implement a template class that demonstrates queue implementation

*/

/*
Question 1:



*/



#include <iostream>
#include "queueADT.h"
#include "queueADT.cpp"  //had to incude both .h and .cpp file of queueADT because of template; compiler needs to build every class instance for type called of the template class
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS



//FUNCTION DECLARATIONS



int main()
{

    cout << "----WELCOME:This program implements a template class that demonstrates queue implementation...BY Demetrius Johnson\n\n";


    queueADT<int>IntqueueADT;
    int x;
    IntqueueADT.MakeEmpty();
    IntqueueADT.Dequeue(x);
    IntqueueADT.Enqueue(10);
    IntqueueADT.Enqueue(20);
    IntqueueADT.Enqueue(30);
    IntqueueADT.Enqueue(40);
    cout << "int Length 3 = " << IntqueueADT.Length() << endl;
    IntqueueADT.Dequeue(x);
    cout << "int Length 4 = " << IntqueueADT.Length() << endl;
    cout << "The int queue contains : " << endl;
    IntqueueADT.Print();
    if (IntqueueADT.IsFull() == false)
        cout << "\nThe int queue is not full !" << endl;
    else
        cout << "\nThe int queue is full !" << endl;
    queueADT<float>FloatqueueADT;
    float y;
    FloatqueueADT.MakeEmpty();
    FloatqueueADT.Dequeue(y);
    FloatqueueADT.Enqueue(7.1);
    cout << "\n\n\nfloat Length 3 = " << FloatqueueADT.Length() << endl;
    FloatqueueADT.Enqueue(2.3);
    cout << "float Length 4 = " << FloatqueueADT.Length() << endl;
    FloatqueueADT.Enqueue(3.1);
    FloatqueueADT.Dequeue(y);
    cout << "The float queue contains : " << endl;
    FloatqueueADT.Print();
    queueADT<float> FloatqueueADT2 = FloatqueueADT;
    cout << "\nThe float queue 2 contains:  " << endl;
    FloatqueueADT2.Print();
    FloatqueueADT.MakeEmpty();
    cout << "\nThe float queue 3 contains:  " << endl;
    FloatqueueADT2.Print();


    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE

