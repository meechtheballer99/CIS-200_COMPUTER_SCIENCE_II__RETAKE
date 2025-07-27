// CIS 200 - LAB 2 - WINTER 2021 - DEMETRIUS JOHNSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 4 FEB 2021
//Last Modification Date: 2-5-2021
//Purpose: a program to print an upside-down triangle composed of a symbol provided by user input


*/

/* 
Question 1 (2.5 points)
//Write a program to print an upside-down triangle composed of a symbol. 
//The number of lines in the triangle and the symbol should be entered as input from the keyboard. 
//For example, if the input values are 4 and $, the output is as follows:

                      $$$$$$$
                       $   $ 
                        $ $  
                         $   


                        

//In your program documentation, describe the loop(s) used as count-controlled or event-controlled.  You should print out the following results:
//(1)	5 and *    (five layers and symbol is *)
//(2)	6 and &   (six layers and symbol is &)





*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   
    int userChoice_numLines = 0; //used to store user choice of number of lines in the pyramid                               
    int odd_Character_Count = 0; //use this to make sure that the first line of the triangle will always be an odd number of characters
    char userChoice_char = ' '; //used to store the character of the user choice
    char empty_Space = ' '; //used to format the triangle with empty spaces on each line as necessary
    int space_Counter = 5; //used to control while loop that outputs spaces on a line //initiate it at 5 so it can be positioned slightly to the right
    int row_Counter = 0; //used to control which row is being worked on
    int char_Counter = 0; //used to control character outputs on a line

    //cout << userChoice_char;  //used for testing ASCII values
    //system("pause");

    cout << "------------WELCOME TO THE Triangle Output Program-------------By Demetrius Johnson--------------\n\n";
    cout << "This program prints an upside-down triangle composed of a symbol and layer(row) size provided by user input.\n\n";
    cout << "Input a character (including a single-digit number) for which the output triangle will be composed of: ";
    cin >> userChoice_char;
    cout << "Input a number value for the number of layers (rows) the output triangle will be composed of: ";
    cin >> userChoice_numLines;
    cout << "\n~User Selections for the triangle are --> Character: " << userChoice_char << "  Number Of Rows/layers: " << userChoice_numLines << endl << endl;

    odd_Character_Count = (userChoice_numLines * 2) - 1; //set the number of char on one line to be double user choice of number of lines; with the first line having an odd number of char on it

    row_Counter = userChoice_numLines;  //I will always keep userChoice_numLines variable constant so as to always have a reference point for all of my other variables of what the user input for rows
    //space_Counter = userChoice_numLines;
    while (row_Counter > 0) { //this loop controls a given row of the triangle (i.e. controls which row will be worked on)

        for (int i = space_Counter; i > 0; i--){ cout << empty_Space; } //control number of empty spaces on each row
        space_Counter++; //increment this variable so that during the next loop the number of initial spaces on the triangle row increases by 1 more than the previous row
       
        

        char_Counter = odd_Character_Count;
        while (char_Counter > 0) { //this loop controls the contents on a given row (i.e. number of characters in a row, including empty spaces)
            
            if (row_Counter == userChoice_numLines) { cout << userChoice_char; } // this statement only executed once for the entire program; 
                                                                                 //it is used so that only the first row of the triangle is full of characters

            else if (char_Counter == odd_Character_Count || char_Counter == 1) { cout << userChoice_char; } //use this loop for subsequent triangle lines; 
                                                                                                            //this will ensure the user char is output on the current row 
                                                                                                            //only at the start and end of the row
            else { cout << empty_Space; } //otherwise; input an empty space at the current position on the row
            
            char_Counter--;
        }

        odd_Character_Count -= 2; //decrement the odd character counter so next row of triangle will have 2 less characters
        cout << endl; //move to next row
        row_Counter--; //decrement number of rows left to be written
    }


    cout << endl << "...The Program has finished, user Triangle output successfully; thank you, goodbye...(;\n\n";
    system("pause");

    return 0;

}
