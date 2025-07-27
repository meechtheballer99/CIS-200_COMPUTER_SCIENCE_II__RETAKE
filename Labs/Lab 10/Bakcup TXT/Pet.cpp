/*
//Author: Demetrius E Johnson
//Date: 12 April 2021
//Last Modification Date: 04-14-2021
//Purpose: Demonstrate the use of Polymorphism and Dynamic Binding: one of the corner stones of object-oriented programming in C++

*/

#include <string>
#include <iostream>
using namespace std;

class Pet
{
protected:
    string Kind_of_Food = "Eats generic food";
    string Kind_of_Sound = "Makes an animal noise";
public:

    Pet() { //default constructor
    
        //cout << "Got a pet" << endl;
        //special noteL: I had to comment out the above line because I learned while stepping through the program that
        //all derived class constructors will always first call the base class constructor before executing any of its code lines

    }
   
    virtual void feed(void) {
    
        cout << Kind_of_Food << endl;
    }

    virtual void speak(void) {
    
        cout << Kind_of_Sound << endl;
    
    }
};

//note: good practice for when overiding a virtual function is to use keyword 'override'

class Cat : public Pet
{

private:
    string color;
public:
    Cat() {//default constructor --  good practice to define default constructor when any other consturctor is defined 
             //and to make sure no paramter creation of an object is supported
    
        Kind_of_Sound = "Meow!";
        color = "~unspecified color";
        cout << "Got a " << color << " cat" << endl;
    } 

    Cat(string inputFood, string inputColor) { //parametized constructor needed based on calls made from Lab's Main function
    
        Kind_of_Sound = "Meow!";
        Kind_of_Food = inputFood;
        color = inputColor;
        cout << "Got a " << color << " cat" << endl;
        
    }
    void feed(void) override {
    
        cout << "Eats " << Kind_of_Food << endl;
    
    }
    void speak(void) override {
    
        cout << Kind_of_Sound << endl;
    
    }


};

class Monkey : public Pet
{
private:
    bool hasTail;
public:
    Monkey() {//default constructor --  good practice to define default constructor when any other consturctor is defined 
               //and to make sure no paramter creation of an object is supported

        Kind_of_Sound = "*Scratches pit*";
        cout << "Got a monkey (unknown if it has a tail)" << endl;
    }

    Monkey(string inputFood, bool tail) { //parametized constructor needed based on calls made from Lab's Main function

        Kind_of_Sound = "*Scratches pit*";
        Kind_of_Food = inputFood;
        hasTail = tail;
        if (hasTail) {
            cout << "Got a monkey with a tail" << endl;
        }
        else {
            cout << "Got a monkey without a tail" << endl;
        }

    }
    void feed(void) override {

        cout << "Eats " << Kind_of_Food << endl;

    }
    void speak(void) override {

        cout << Kind_of_Sound << endl;

    }

};

class Lizard : public Pet
{
private:
    unsigned short int Length_of_Tongue;
public:
    Lizard() {//default constructor --  good practice to define default constructor when any other consturctor is defined 
                 //and to make sure no paramter creation of an object is supported

        Kind_of_Sound = "Grrrrrrr~";
        cout << "Got a lizard (unknown length of tongue)" << endl;
    }

    Lizard(string inputFood, int inputTongueLength) { //parametized constructor needed based on calls made from Lab's Main function

        Kind_of_Sound = "Grrrrrrr~";
        Kind_of_Food = inputFood;
        Length_of_Tongue = inputTongueLength;
        cout << "Got a lizard with a " << Length_of_Tongue << "cm tongue" << endl;

    }
    void feed(void) override {

        cout << "Eats " << Kind_of_Food << endl;

    }
    void speak(void) override {

        cout << Kind_of_Sound << endl;

    }

};

class Turtle : public Pet
{
private:
    float weight;
public:
    Turtle() {//default constructor --  good practice to define default constructor when any other consturctor is defined 
                //and to make sure no paramter creation of an object is supported

        Kind_of_Sound = "*Turtle noise*";
        cout << "Got a turtle (weight unknown)" << endl;
    }

    Turtle(string inputFood, float inputweight) { //parametized constructor needed based on calls made from Lab's Main function

        Kind_of_Sound = "*Turtle noise*";
        Kind_of_Food = inputFood;
        weight = inputweight;
        cout << "Got a " << weight << "-pound turtle" << endl;

    }
    void feed(void) override {

        cout << "Eats " << Kind_of_Food << endl;

    }
    void speak(void) override {

        cout << Kind_of_Sound << endl;

    }

};

