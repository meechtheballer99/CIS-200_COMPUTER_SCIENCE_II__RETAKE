

//IPHONE12 CLASS

//Author: Demetrius E Johnson
//Date: 12 MAR 2021
//Last Modification Date: 12-03-2021
//Purpose: demonstrate the utility of multiple inheritance


#ifndef IPHONE12_H
#define IPHONE12_H
#include "IPhone.h"
class IPhone12 : public IPhone //public inheritance of IPhone class means all of its public and protected attributes are implicitly defined for this class, including IPhone's publicly inherited attributes
{

private:

	bool AugmentedRealityStatus;

public:

	//constructor
	IPhone12();

	//set and get functions
	void setAugmentedRealityStatus(bool status);
	bool getAugmentedRealityStatus(void);






};

#endif