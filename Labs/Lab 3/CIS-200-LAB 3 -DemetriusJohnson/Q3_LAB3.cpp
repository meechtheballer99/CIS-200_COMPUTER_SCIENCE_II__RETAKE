// CIS-200-LAB 3 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 7 FEB 2021
//Last Modification Date: 2-7-2021
//Purpose:


*/

/*
Question 3 (4.0 points)

Given that Sale[NUM_ROW][NUM_COLUMN] is a two dimensional array of float-pofloat type and the two constants are defined as follows:

#define NUM_ROW  4
#define NUM_COLUMN 4

float Value[NUM_ROW][NUM_COLUMN] =
{ 	 5.1, 5.2, 5.3, 5.4, 4.5, 4.6, 4.7, 4.8, 4.9, 3.0, 3.1, 3.2,
             3.1, 3.2, 3.3, 3.4
};

Write a C++ main function that computes and prints out the following information about this 2d array:

(1)	The minimum value of Value[][] array elements (1 points).
(2)	The maximum value of  the Value[][] array elements (1 points).
(3)	The mean of all the Value[][] array elements (1 points).
(4)	The values of four neighboring elements with respect to Value[i][j], where i and j represent the row and column, respectively.  
Your program should ask users to input i and j, and then the code should prfloat out the values of all the four neighboring elements w.r.t. i and j. 
The four neighboring elements are defined as the elements at the left, right, up, and down positions adjacent to the element [i][j].

User test cases:
(a)	 i = 1,  j=1
(b)	 i = 0,  j =2
(c)	i= 2, j=3

You need to prfloat the results on computer screen and make a screenshot.

Hint:  You should consider wrap-around when element[i][j] is located at the boundary of the matrix.


//remember for array[i][j]; the i is row, j is column
//also remember arrays are by default passed by reference into functions

*/



#include <iostream>
#include<vector>
#define NUM_ROW  4
#define NUM_COLUMN 4
using namespace std;


//FUNCTION DECLARATIONS

float minVal_2D_Arr(float valueArr[][NUM_COLUMN]);
float maxVal_2D_Arr(float valueArr[][NUM_COLUMN]);
float meanVal_2D_Arr(float valueArr[][NUM_COLUMN]);
vector<float> neighbor_Horz_Vert_values_2D_Arr(float valueArr[][NUM_COLUMN], int row, int col);

//FUNCTION DECLARATIONS




int main()
{

    //2-D array below:
    float value[NUM_ROW][NUM_COLUMN] =
    { 5.1, 5.2, 5.3, 5.4,
      4.5, 4.6, 4.7, 4.8,
      4.9, 3.0, 3.1, 3.2,
      3.1, 3.2, 3.3, 3.4 };

    //cout << value[1][0]; //used for testing; note, since multi-demensional arrays are really stored as 1D arrays, cout << value[0][4] will yield the same as cout << [1][0]
    cout << "---WELCOME---this simple program takes a 2D array and ouputs various metrics about the array---BY Demetrius Johnson----\n\n";
    cout << "Here is the 2D array used: \n\n{ 5.1, 5.2, 5.3, 5.4,\n  4.5, 4.6, 4.7, 4.8,\n  4.9, 3.0, 3.1, 3.2,\n  3.1, 3.2, 3.3, 3.4 }\n\n";
 
    cout << "The MINIMUM value of the 2D array is: " << minVal_2D_Arr(value) << endl;
    cout << "The MAXIMUM value of the 2D array is: " << maxVal_2D_Arr(value) << endl;
    cout << "The MEAN value of the 2D array is: " << meanVal_2D_Arr(value) << endl << endl;
    cout << "Now, the program will compute the up-down-left-right neighbors from user input concerning an element in the array.\n";

    int Row, Col; //will use these to ask for user input for calling the neighbor funtion

    cout << "The 2D-Array form is this: [ROW][COLUMN] --> [i][j]\n\n";
    cout << "Input which ROW your element is in ( row elements go from 0 to 3 = 4 elments): ";
    cin >> Row;
    cout << "Input which COLUMN your element is in (col elements go from 0 to 3 = 4 elments): ";
    cin >> Col;
    cout << "Your element position " << "[" << Row << "][" << Col << "] {value = " << value[Row][Col] << "} has these 4 values as neighbors: \n\n";

    vector<float> output_Neighbor_Vec(4);
    output_Neighbor_Vec = neighbor_Horz_Vert_values_2D_Arr(value, Row, Col);

    for (int count = 0; count < 4; count++) {

        switch (count) {

        case 0: cout << "Right Neighbor: " << output_Neighbor_Vec.at(count) << endl; break;
        case 1: cout << "Left Neighbor: " << output_Neighbor_Vec.at(count) << endl; break;
        case 2: cout << "Top Neighbor: " << output_Neighbor_Vec.at(count) << endl; break;
        case 3: cout << "Bottom Neighbor: " << output_Neighbor_Vec.at(count) << endl; break;



        }
    }

    cout << endl << endl;
    cout << "Program has finished execution....exiting....thank you....\n";
    system("pause");
    return 0;
}


//FUNCTION DEFINITIONS

float minVal_2D_Arr(float valueArr[][NUM_COLUMN]){

    float minVal = valueArr[0][0]; //initialize the the minVal variable to the very first value in the 2D array as a starting minVal point

    for (int row = 0; row < 4; row++) {

        for (int column = 0; column < 4; column++) {

            if (minVal > valueArr[row][column]) { minVal = valueArr[row][column]; } //check each element using the two for-loops against current min
                                                                                    //which control the row and column number iteration respectively
        }
    }

    return minVal;
}

float maxVal_2D_Arr(float valueArr[][NUM_COLUMN]) {

    float maxVal = valueArr[0][0]; //initialize the the maxVal variable to the very first value in the 2D array as a starting minVal point

    for (int row = 0; row < 4; row++) {

        for (int column = 0; column < 4; column++) {

            if (maxVal < valueArr[row][column]) { maxVal = valueArr[row][column]; } //check each element using the two for-loops against current max
                                                                                    //which control the row and column number iteration respectively
        }
    }

    return maxVal;
}

float meanVal_2D_Arr(float valueArr[][NUM_COLUMN]){

    float sum = 0;
    float numVal = 0;
    float values_summed = 0;
    float meanVal = 0;

    for (int row = 0; row < 4; row++) {

        for (int column = 0; column < 4; column++) {

            sum += valueArr[row][column]; //add the current element value to the mean
            values_summed++;
        }
    }
    meanVal = (sum / values_summed);
    return meanVal;
}

vector<float> neighbor_Horz_Vert_values_2D_Arr(float valueArr[][NUM_COLUMN], int row, int col){

    vector<float> neighbor_Vec(4); // VECTOR ELEMENTS: right neighbor = 0, left neighbor = 1, top neighbor = 2, bottom neighbor = 3
                                   //note: left and right neighbors depend on the adjacent columns, up and down nieghbors depend on the adjacent rows

   
    neighbor_Vec.at(0) = valueArr[row][((col + 1) % 4)]; //use +1 and % 4 since elements range from 0-3, 
                                                         //which means if col == 3, (3+1) % 4 = 0; if col == 0, then (0+1) % 4 = 1 
                                                         //--> will handle the wrap-around case for defining right neighbors (column 3 elements)
                                                         //as well as normal cases for right nieghbor

    neighbor_Vec.at(1) = valueArr[row][((col + 3) % 4)]; //+3 in this case to find left neighbors and account for wrap-around case (column 0 elements)
    neighbor_Vec.at(2) = valueArr[((row + 3) % 4)][col]; //top neighbors including wrap-around case (row 0)
    neighbor_Vec.at(3) = valueArr[((row + 1) % 4)][col]; //bottom neighbors including wrap-around case (row 3)

    return neighbor_Vec;
}

//FUNCTION DEFINITIONS