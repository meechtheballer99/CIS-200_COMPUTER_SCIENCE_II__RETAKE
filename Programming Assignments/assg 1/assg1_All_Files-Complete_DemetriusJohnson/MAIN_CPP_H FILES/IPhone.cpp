

#include "IPhone.h"



//constructors
IPhone::IPhone() { AppleID = 0; }

//set and get functions
void IPhone::setAppleID(int x) { AppleID = x; }
int IPhone::getAppleID(void) { return AppleID; }
