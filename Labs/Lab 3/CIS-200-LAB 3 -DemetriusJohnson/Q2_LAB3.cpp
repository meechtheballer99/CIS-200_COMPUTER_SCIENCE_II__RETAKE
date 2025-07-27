// CIS-200-LAB 3 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 7 FEB 2021
//Last Modification Date: 2-7-2021
//Purpose:


*/

/*

Question 2 (3.0 points)
Write a program to determine whether the character entered is a capital letter, a small case letter, a digit or a special symbol.
The following table shows the range of ASCII values for various characters.
Characters	ASCII Values
A – Z	65 – 90
a – z	97 – 122
0 – 9	48 – 57
special symbols	0 - 47, 58 - 64, 91 - 96, 123 – 127

In your main( ), you should declare a char variable ch and get a user input from keyboard for ch.  
Based on the above ASCII table, 
print out a message to show that the input character is an upper case or a lower case or a digit or a special symbol.

User test inputs:
    Y
    t
    5
    *

*/



#include <iostream>
using namespace std;




int main()
{
    char ch;
    char user_Decide = 121; //121 == 'y' //use this variable so user can decide wether or not to exit program


    do { //made this loop so it will be easier to test multiple values until it is desired to exit the program

        cout << "-----WELCOME to the simple character type determination program----BY Demetrius Johnson------\n\n";
        cout << " This program will take the user character input and determine which category it belongs to:\n\n\t*Upper-case Letter\n\t*Lower-case Letter\n\t*Digit\n\t*Special Symbol\n\n";
        cout << "Input a single character: ";
        cin >> ch;
        cout << endl << "Your character '" << ch << "' is a ";

        if (ch > 47 && ch < 58) { cout << "Digit."; }
        else if (ch > 64 && ch < 91) { cout << "Upper-case Letter."; }          //using the if-else statements to funnel down from smallest decimal to largest                                                     
        else if (ch > 96 && ch < 123) { cout << "Lower-case Letter."; }         // for determining what type of character the user has input
        else { cout << "Special Symbol."; }

        cout << "\n\nEnter 'y' to restart program; enter any other character to exit: ";
        cin >> user_Decide;
        cout << endl << endl;

    } while (user_Decide == 121); //121 == 'y'

    cout << "\n\nProgram exit option selected...exiting program....thank you.....goodbye(:";
    cout << endl;
    system("pause");
    return 0;
}


