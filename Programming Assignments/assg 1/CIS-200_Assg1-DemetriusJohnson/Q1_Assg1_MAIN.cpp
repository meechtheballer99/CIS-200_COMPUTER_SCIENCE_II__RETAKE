// CIS-200_Assg1-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Demetrius E Johnson
//Date: 12 MAR 2021
//Last Modification Date: 12-03-2021
//Purpose: demonstrate the utility of multiple inheritance






#include <iostream>
#include "IPhone12.h" //this will cause a chain of inlcudes: iphone12 --> includes iphone ---> includes phone.
using namespace std;


int main()
{
    cout << "---WELCOME to the Mulitple Inheritance Utility Demonstration Program ----By Demetrius Johnson\n\n";


    Phone x;
    cout << "Initial value for x: " << endl;
    cout << "\tAge = " << x.getAge() << "\n\tPrice = " << x.getPrice() << endl;

    x.setAge(3);
    x.setPrice(200);
    cout << "Modified value for x: " << endl;
    cout << "\tAge = " << x.getAge() << "\n\tPrice = " << x.getPrice() << endl << endl;



    IPhone y;
    cout << "Initial value for y: " << endl;
    cout << "\tAge = " << y.getAge() << "\n\tPrice = " << y.getPrice() << "\n\tApple ID = " << y.getAppleID() << endl;

    y.setAge(2);
    y.setPrice(300);
    y.setAppleID(1234);
    cout << "Modified value for y: " << endl;
    cout << "\tAge = " << y.getAge() << "\n\tPrice = " << y.getPrice() << "\n\tApple ID = " << y.getAppleID() << endl << endl;

    IPhone12 z;
    cout << "Initial value for z: " << endl;
    cout << "\tAge = " << z.getAge() << "\n\tPrice = " << z.getPrice() << "\n\tApple ID = " << z.getAppleID() << "\n\tAugmentedReality status = " << z.getAugmentedRealityStatus() << endl;

    z.setAge(1);
    z.setPrice(500);
    z.setAppleID(3234);
    z.setAugmentedRealityStatus(true);
    cout << "Modified value for z: " << endl;
    cout << "\tAge = " << z.getAge() << "\n\tPrice = " << z.getPrice() << "\n\tApple ID = " << z.getAppleID() << "\n\tAugmentedReality status = " << z.getAugmentedRealityStatus() << endl;





    cout << "\n\n\n~....Program has finished execution...exiting....\n";
    system("pause");


    return 0;
}


