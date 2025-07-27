// CIS-200-LAB 3 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 7 FEB 2021
//Last Modification Date: 2-7-2021
//Purpose: 


*/

/*
Question 1 (3.0 points)

Suppose you work for a boss who is stingy about memory use and
ask you to use only one unsigned char variable, x, for the representation of the binary status (ON or OFF) of 8 locations. 
(See a figure below.)  The reason for this is that your boss wants to use your code in handling with multiple-million user information.
In addition, your boss requires you to write a code for complete a number of steps as follows:

    1) input a decimal number (0-255)
    2) convert it to a binary number
    3) loop throuhg all the bits of this binary number and print out the locations that correspond to the bit value as 1
    //for example: if you have a binary number 10000001 (decimal: 129) then message output should be: "Garage, bedroom are on".
    bit location representations: 
    0: garage
    1: kitchen
    2: hallway
    3: basement 
    4: great room 
    5: family room 
    6: bathroom 
    7: bed room
Test your program with the following input numbers:

    (a)	 3
    (b)	13
    (c)	133



   SIDE NOTES ON BITWISE OPERATORS:

   ***Bitwise operators return an integer value.
   ***The bitwise logical operators work on the data bit by bit, starting from the least significant bit, 
        i.e. LSB bit which is the rightmost bit, working towards the MSB (Most Significant Bit) which is the leftmost bit.
   ***The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
   *** The << (left shift) in C or C++ takes two numbers, left shifts ALL of the bits of the first operand, the second operand decides the number of places to shift.
   ***The >> (right shift) in C or C++ takes two numbers, right shifts ALL of the bits of the first operand, the second operand decides the number of places to shift.
   *** when you use bitwise & operator in a conditional statement, it checks agaisnt the LSB (least significant bit); if the last bit each number == 1 (bit is on) then it evaluates to true.
*/



#include <iostream>
#include<vector>
using namespace std;

int main()
{

    unsigned char x; //using char since it is only 8 bits of data--> 2^8 = 256 values possible; unsigned so that we get larger positive value storage range [0-255] instead of [-128 to 127] 
    int user_Decimal_Input = 0; //only need this integer in order to get user initial decimal value input
    vector<short> c_Vec(8); //needed only so that we can print out the binary value in the correct order
    


   cout << "-----WELCOME to the 8-bit room-lighting decimal to binary representation program----BY Demetrius Johnson------\n\n";
   cout << " ON (1) and OFF (0) room-lighting bit (element) locations:\n\n0: garage\n1: kitchen\n2: hallway\n3: basement\n4: great room\n5: family room\n6: bathroom\n7: bed room\n";
   cout << "\nFor Example --> if you input the decimal number: 129, it will be converted to the binary number: 10000001";
   cout << "\nThen message output should be: 'garage, bedroom are ON' --> output of locations with light on (bit value = 1) will\nbe displayed from least to most significant bit.\n\n";
        
       
   cout << "\nPlease input a decimal value in the range [0-255]: ";
   cin >> user_Decimal_Input;
   x = user_Decimal_Input; //store the user data inside of the smallest integral data type (char/unsigned char == 1 byte == 8 bits)

   cout << "\n\tThe binary value of the decimal value " << user_Decimal_Input << " is equal to: ";

   for (int i = 7; i >= 0; i--) {

       c_Vec.at(i) = (x % 2); //set the proper bit of the 8-bit binary number using the formula of division by 2 and keeping the remainder, 
                              //starting with the LSB (right most bit == least significant bit)
       x /= 2; // divide by two to get to the next place value

   }
   x = user_Decimal_Input; //re-input the user's integer value input since it was manipulated by the above function
   for (int j = 0; j < 8; j++) { cout << c_Vec.at(j); } //output the binary number

   
   if (x > 0) { cout << endl << endl << "\tThe "; } //use this only if at least one bit is on
   for (int k = 7; k >= 0; k--) { //this loop will go from LSB to MSB for output as the program specified it would do for bits that are ON
       
     
       switch (k) {

       case 7:
           if (c_Vec.at(k)) { cout << "Garage, "; } break;
       case 6:
           if (c_Vec.at(k)) { cout << "Kitchen, "; } break;
       case 5:
           if (c_Vec.at(k)) { cout << "Hallway, "; } break;
       case 4:
           if (c_Vec.at(k)) { cout << "Basement, "; } break;
       case 3:
           if (c_Vec.at(k)) { cout << "Great Room, "; } break;
       case 2:
           if (c_Vec.at(k)) { cout << "Family Room, "; } break;
       case 1:
           if (c_Vec.at(k)) { cout << "Bathroom, "; } break;
       case 0:
           if (c_Vec.at(k)) { cout << "Bedroom, "; } break;
      }
   }

   cout << "\b\b "; //use this to clear off last ',' character 
   if (x > 0) { cout << "is/are ON."; } //more than one bit ON
   else { cout << "No rooms are on (all bits OFF)."; } //no bits ON; all OFF
   cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


