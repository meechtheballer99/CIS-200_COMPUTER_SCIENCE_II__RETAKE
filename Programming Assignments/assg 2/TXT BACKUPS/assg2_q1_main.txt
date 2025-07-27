// CIS-200_Assg2-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Demetrius E Johnson
//Date: 04 MAR 2021
//Last Modification Date: 03-04-2021
//Purpose:

//Question 1  Unsorted List (30 points)


#include <iostream>
#include "UnsortedList.h"
#include <fstream>
using namespace std;


//FUNCTION DECLARATIONS
int numCharElement(ifstream& x);
//FUNCTION DECLARATIONS



int main()
{
    std::cout << "---WELCOME: This program implements the use of an Unsorted List abstract data structure ----By Demetrius Johnson\n\n\n";


    UnsortedList x;
    
    ifstream charFile("char.dat"); // open char.dat
    if (!charFile.is_open()) { 
        
        std::cout << "FILE NOT OPENED SUCCESSFULLY";
        std::cout << charFile.good();
    }
    
    // set up x based on the data in char.dat
    char fElement;
    while (charFile >> fElement) { //get characters from the file

        if (isalpha(fElement)) { x.InsertItem(fElement); }

    }

    
    cout << "Contents of unsorted list, which was read from a file is: " << endl << endl;
    x.printElement();

    cout << endl << endl << "Size of unsorted list is: " << endl << endl << numCharElement(charFile) << endl << endl << endl;

   


    charFile.close();

    system("pause");

    return 0;

}


//FUNCTION DEFINITIONS:

int numCharElement(ifstream& x) {

    int numChar = 0;
    int FilePos = 0;
    x.clear(); //clear flags
    x.seekg(0, ios::beg); //go back to beginning of file
    while ((x.peek() > 64 && x.peek() < 91) || (x.peek() > 96 && x.peek() < 123) || x.peek() == '\n') { //A-Z and a-z ASCII character set

        

       if(x.peek() != '\n'){ numChar++; }

       //cout << x.peek() << endl; //this line used for testing only
      
       FilePos++;
       x.seekg(FilePos); //increment the istream pointer to point to the next byte in the file
       
      
    }

    return numChar;
    

}