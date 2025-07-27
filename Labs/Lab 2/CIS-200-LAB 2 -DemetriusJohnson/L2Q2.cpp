// CIS 200 - LAB 2 - WINTER 2021 - DEMETRIUS JOHNSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 4 FEB 2021
//Last Modification Date: 2-5-2021
//Purpose: take a positive integer from users via cin and to print out the value of this number in its octal representation (8-based numbering system)


*/

/*

Question 2 (2.5 points)

//Write a program to take a positive integer from users via cin and to print out the value of this number in its octal representation (8-based numbering system). 
//For instance, if you input 8, the output should be 10.

//You should test your program with the following inputs:
    //12
    //15




*/

#include <iostream>
#include <vector>
using namespace std;


int main()
{

    int userInteger_base10 = 0; //use this to get user input and to convert their input from decimal to octal
    int remainder = 0; //use this to store the remainder of any division results //set remainder to 1 in case user inputs '0', the for loop will still execute at least once
    vector<int> placeValStorageVector_octal;
    
    cout << "------------WELCOME TO THE Base-8 (Octal) Number Representation program-------------By Demetrius Johnson--------------\n\n";
    cout << "This program prints a positive decimal (base 10) integer value\nfrom the user in its octal representation (8-based numbering system).\n";
    cout << "For example: if you input '8', the output will be '10'\n\n";
    cout << "Please input a base-10 (decimal system) integer (no fractions allowed) value to be converted to base-8 (octal numbering system).\n\nUser Input: ";
    cin >> userInteger_base10;

    cout << "\n\t" << userInteger_base10 << " [base-10] = ";

 

    do{ //this loop will read in the place values of the octal value, but backwards (left to right, place values become stronger) //used do-while so it executes even if user inputs '0'

        remainder = userInteger_base10 % 8; //get remainder, which will provide a place value digit of the octal number
        placeValStorageVector_octal.push_back(remainder); //set element in the vector equal to the remainder (which is equal to the current place value digit of the octal number)
        userInteger_base10 /= 8; //divide integer by 8 every instance to move to the next place value (power) that is necessary to convert the decimal number to octal number

    } while (userInteger_base10 != 0);


    for (int elementPos = (placeValStorageVector_octal.size() - 1); elementPos >= 0; elementPos--) { //this will output the octal value, 
                                                                                               //starting from end of the vector which is where the larger place values are stored
                                                                                               //remember vector element position size is size - 1, since element 0 is included
        cout << placeValStorageVector_octal.at(elementPos);
    }



    cout << " [base-8]" << endl;
    cout << "\n...Program will now exit...Thank you(:...\n\n";
    system("pause");
    return 0;

}