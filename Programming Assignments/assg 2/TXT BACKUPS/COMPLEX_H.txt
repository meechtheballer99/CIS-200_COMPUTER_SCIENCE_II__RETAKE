//Author: Demetrius E Johnson
//Date: 04 MAR 2021
//Last Modification Date: 03-04-2021
//Purpose: write a program using a class that can represent imaginary numbers


#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using std::ostream; //Notes from a c++ help site: Alternatively, you could have a using declaration before the unqualified name ostream appears:using std::ostream;

//A complex number is a number of the form: a + b * i,  where a and b are number of type double, and i is a number that represents sqrt(-1). 

class Complex
{

private:

	double real;
	double imaginary;




public:

	Complex();//Include a default constructor that initializes an object to 0 + 0 * i.

	Complex(double real, double imaginary); //Include a constructor with two parameters of type double that can be used to set the member variables of an object to any values

	Complex(double realPart);//Include a constructor with one parameter of type double called realPart and define the constructor so that the object will be initialized to realPart + 0 * i. 

	Complex(const Complex& inputObj); //include a copy constructor

	//Overload all the following operators so that they correctly apply to the type Complex class:

	Complex& operator=(const Complex &inputObj); //assignment operator //need to make sure to use keyword const so that I can do operations such as x = y+z
	bool operator==(Complex& inputObj); //comparison operator
	Complex operator+(Complex& inputObj); //add
	Complex operator-(Complex& inputObj); //subtract
	Complex operator*(Complex& inputObj); //mult operator
	Complex operator/(Complex& inputObj); //div operator
	friend ostream& operator<<(ostream& os, const Complex& outputObj); //output (insertion) operator for cout or fstream out 
												  //Here, it is important to make operator overloading function 
												  //a friend of the class because it would be called without creating an object.
	Complex& operator++(); //prefix operator
	Complex operator++(int); //postfix operator
	




};

#endif