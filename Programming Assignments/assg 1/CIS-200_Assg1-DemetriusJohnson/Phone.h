
//PHONE CLASS

//Author: Demetrius E Johnson
//Date: 12 MAR 2021
//Last Modification Date: 12-03-2021
//Purpose: demonstrate the utility of multiple inheritance


#ifndef PHONE_H
#define PHONE_H

class Phone
{
protected: //use protected inhertiance so that Iphone 12 can inherit these from Iphone class (since Iphone class will publicaly inherit these attributes first)

	int Age;
	float Price;


public:

	//constructors
	Phone();
	Phone(int a, float b);

	//set and get functions
	void setAge(int a);
	void setPrice(float b);
	int getAge(void);
	float getPrice(void);





};

#endif