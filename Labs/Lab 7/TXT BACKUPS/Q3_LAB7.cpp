// CIS-200-LAB 7 -DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
//Author: Demetrius E Johnson
//Date: 16 MAR 2021
//Last Modification Date: 03-16-2021
//Purpose: practice the use of dynamic allocation using a multi-dimensional array of 3 Dimensions


*/

/*
Question 3:

Dynamic memory allocation is an efficient and flexible way for software development. Design and implement a function, bar( ... ), 
which dynamically allocates a three-dimensional arrays. This function has four parameters: 
1) a parameter for transmitting the array between main( ) and bar( ); 
2) an integer parameter for specifying the length of the first index of the array; 
3) an integer parameter for specifying the length of the second index of the array; 
4) an integer parameter for specifying the length of the third index of the array.

In the function of bar( ), you need to do the following tasks:

i) dynamically allocate a three-dimensional array (say x[][][] ) with length (length1, length2, length3)

ii) perform the following loops:
     for(int i=0; i< length1; i++)
          for(int j=0; j<length2; j++)
               for(int k=0; k<length3; k++)
                      x[i][j][k]= sin(i*j*k);

  In the function of main( ), you need to do the following tasks:

i) assume the three-dimensional array is of float type;
ii) ask users to input three integer parameters: s1, s2, and s3 for lengths of three indices of the array to be created.
iii) call bar(…)  by passing s1, s2 and s3 to length1, length 2 and length3 in bar( )
iv) after finishing the calling of bar(…), perform the following loops:
     for(int i=0; i< s1; i++)
          for(int j=0; j<s2; j++)
              for(int k=0; k<s3; k++)
                     cout << "i= " << i << "  j= " << j  <<  " k= " << k << "y[i][j][k]=  " <<
                                 y[i][j][k] << endl;
v) deallocate the array created in bar( )



*/



#include <iostream>
//#include<assert.h>
using namespace std;


//FUNCTION DECLARATIONS

template<typename T>
int Triple_P_alloc(T*** Triple_P, int length1, int length2, int length3);
template<typename T>
int Triple_P_dealloc(T*** Triple_P, int length1, int length2); //note length3 is not used in this function because it is the length of 
                                                                //the single pointers allocation which point only to addresses of data variables - not other pointer variables;
                                                               



//FUNCTION DECLARATIONS

//**SPECIAL NOTE: THERE ARE 2 WAYS TO PASS BY REFERENCE: 
//1) USING POINTER ARGUMENTS [(var_type* var_name) -->pass in argument is &var_name]  
//2) USING REFERENCE ARGUMENTS [(var_type& var_name) -->pass in argument is var_name]  

int main()
{
    cout << "---WELCOME: This Program implements the dynamic allocation and deallocation of a 3D Array --BY Demetrius Johnson\n\n\n";

    int L1 = 0;
    int L2 = 0;
    int L3 = 0;
    int num_delete_calls = 0;

    //ask user for size of 3D array
    cout << "Select the array size of the first dimension (L1 = array of double pointers): ";
    cin >> L1;
    cout << "Select the array size of the second dimension (L2 = array of single pointers): ";
    cin >> L2;
    cout << "Select the array size of the third dimension (L3 = array of non-pointer data): ";
    cin >> L3;
    cout << "\n*NOTE: each array value [i][j][k] is set to a value: sin(i * j * k) = radians.\n\n";

    //3D array is of float type
    float*** triple_float = new float**[L1]; //triple pointer points to (stores) a double pointer [address] or an array of double pointers [addresses]
    int num_dynamic_alloc = 1;
    num_dynamic_alloc += Triple_P_alloc(triple_float, L1, L2, L3); //call allocation function
    cout << "\nDuring allocation, the number of 'new' calls was: 1 + L1 + (L1 * L2) == " << 1 << " + " << L1 << " + (" << L1 << " * " << L2 << ") = " << num_dynamic_alloc;
    cout << "\n\nThe forumula comes from:\n\n";
    cout << " 1 --> allocation of memory for triple pointer." << endl << endl;
    cout << " + L1 --> each element of the triple pointer is a double pointer,\n and each double pointer needs also to be assigned memory --> of type single pointer." << endl << endl;
    cout << " + (L1 * L2) --> the number of single pointers pointed to by \n each double pointer all need also to be assigned memory." << endl << endl;
    cout << " ***NOTE: L3, the size of the single pointer memory allocation is\n irrelevant since it only contains an array of normal data addresses;";
    cout << "\n it only matters how many times 'new' operator is called regardless of size allocated for each single pointer.\n\n";
    cout << "~Total number of elements in the 3D array is: L1 * L2 * L3 = " << L1 << " * " << L2 << " * " << L3 << " = " << (L1 * L2 * L3) << endl;
    // after finishing the calling, perform the following loops :
    for (int i = 0; i < L1; i++)
        for (int j = 0; j < L2; j++)
            for (int k = 0; k < L3; k++)
                cout << "i = " << i << "  j = " << j << " k = " << k << "  triple_float[i][j][k] = " <<
                triple_float[i][j][k] << endl;

    num_delete_calls = Triple_P_dealloc(triple_float, L1, L2); //deallocate the triple pointer 
    cout << "\n\nDuring deallocation, the number of 'delete[]' calls was: (L2 * L1) + L1 + 1 == ("<< L2 << " * " << L1 << ") + " << L1 << " + " << 1 << " = " << num_delete_calls;
    cout << "\n\nThe forumula comes from:\n\n";
    cout << " (L2 * L1) --> the number of single pointers pointed to by \n each double pointer all need also to be deallocated memory." << endl << endl;
    cout << " + L1 --> each element of the triple pointer is a double pointer,\n and each double pointer array needs also to be deallocated its memory of single pointers." << endl << endl;
    cout << " + 1 --> the deallocation of memory for the single triple pointer which was storing an array of single pointers." << endl << endl;
    cout << " ***NOTE: L3, the size of the single pointer memory allocation is\n irrelevant since it only points to a single array of normal data variable addresses;";
    cout << "\n it is only necessary to call 'delete[]' once for all single pointers regardless of address size pointed to.\n\n";
    
    cout << endl << endl << "The program has finished execution....now exiting...thank you....\n\n";
    system("pause");

    return 0;
}


//FUNCTION DEFINITIONS BELOW THIS LINE


//Dynamic memory allocation is an efficientand flexible way for software development. Design and implement a function, bar(...),
//which dynamically allocates a three - dimensional array.This function has four parameters :
//1) a parameter for transmitting the array between main() and bar();
//2) an integer parameter for specifying the length of the first index of the array;
//3) an integer parameter for specifying the length of the second index of the array;
//4) an integer parameter for specifying the length of the third index of the array.

template<typename T>
int Triple_P_alloc(T*** Triple_P, int length1, int length2, int length3) {

    int num_allocations = 0;//use this to keep track of allocations so that I know how many deallocations there should be later

    for (int i = 0; i < length1; i++) { //remember element 0 is the first element; thus we say i < length1 //this loop allocates memory for all double pointer elements from Triple_P
        
        Triple_P[i] = new T*[length2]; //double pointer points to (stores) a single pointer [address] or an array of single pointers [addresses]
        num_allocations++; 
        for (int j = 0; j < length2; j++) {//remember element 0 is the first element; thus we say j < length2 //this loop allocates memory for all single pointer elements from double Pointers in Triple_P
            
            Triple_P[i][j] = new T[length3]; //single pointer points to the address of a data variable or an array of data variables [addresses]
            num_allocations++;
        }
    }

    //now assign values to all elements of the 3D array
    for (int i = 0; i < length1; i++)
        for (int j = 0; j < length2; j++)
            for (int k = 0; k < length3; k++)
                Triple_P[i][j][k] = sin(i * j * k);

    return num_allocations;
}

template<typename T>
int Triple_P_dealloc(T*** Triple_P, int length1, int length2) {

    int num_delete_called = 0; //use this to track num of deallocations; should match the number of allocations made from when the 3D array was allocated memory

    for (int i = 0; i < length1; i++) { 

        for (int j = 0; j < length2; j++) {//use this loop to deallocate single pointers, and then double pointers

            delete[] Triple_P[i][j]; //dealloc single pointers 
            num_delete_called++; //used to keep track/test if proper number of deletes called based on 3D array size
        }

        delete[] Triple_P[i]; //dealloc double pointers
        num_delete_called++;
    }

    delete[] Triple_P; //finally, dealloc the triple pointer
    num_delete_called++;

    return num_delete_called;
}