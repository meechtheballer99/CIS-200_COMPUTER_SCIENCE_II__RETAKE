

//IPHONE CLASS

//Author: Demetrius E Johnson
//Date: 12 MAR 2021
//Last Modification Date: 12-03-2021
//Purpose: demonstrate the utility of multiple inheritance


#ifndef IPHONE_H
#define IPHONE_H
#include "Phone.h"
class IPhone : public Phone //public inheritance of Phone class means all of its public and protected attributes are implicitly defined for this class
{

protected:
	
	int AppleID;

public:

	//constructors
	IPhone();

	//set and get functions
	void setAppleID(int x);
	int getAppleID(void);



};

#endif
