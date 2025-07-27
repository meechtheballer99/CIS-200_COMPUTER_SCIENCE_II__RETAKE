

#include "Phone.h"


//constructors
Phone::Phone() { Age = 0; Price = 0.0; }
Phone::Phone(int a, float b) { Age = a; Price = b; }

//set and get functions
void Phone::setAge(int a) { Age = a; }
void Phone::setPrice(float b) { Price = b; }
int Phone::getAge(void) { return Age; }
float Phone::getPrice(void) { return Price; }
