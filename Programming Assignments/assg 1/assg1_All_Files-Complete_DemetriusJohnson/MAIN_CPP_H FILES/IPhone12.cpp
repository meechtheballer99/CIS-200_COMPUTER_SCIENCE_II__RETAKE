


#include "IPhone12.h"


//constructor
IPhone12::IPhone12() { AugmentedRealityStatus = false; }

//set and get functions
void IPhone12::setAugmentedRealityStatus(bool status) { AugmentedRealityStatus = status; }
bool IPhone12::getAugmentedRealityStatus(void) { return AugmentedRealityStatus; }