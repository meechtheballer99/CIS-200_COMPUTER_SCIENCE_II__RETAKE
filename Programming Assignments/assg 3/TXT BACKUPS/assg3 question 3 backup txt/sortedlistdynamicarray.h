
#ifndef SORTEDLISTDYNAMICARRAY_H
#define SORTEDLISTDYNAMICARRAY_H
#define LEN 30


template<class ItemType>
class SortedList_DynArr
{
public:
	SortedList_DynArr();  // default constrctor
	SortedList_DynArr(const SortedList_DynArr& x);  // we implement copy constructor with deep copy
	SortedList_DynArr<ItemType>& operator=(SortedList_DynArr<ItemType>& x); // equal sign operator with deep copy
	bool IsThere(ItemType item);  // return true of false to indicate if item is in the list
	void Insert(ItemType item);  // if item is not in the list, insert it into the list
	void Delete(ItemType item);  //  delete item from the list
	void Print();  // Print all the items in the list on screen
	int Length();   // return the number of items in the list
	~SortedList_DynArr();  // programmer should be responsible to deallocate the linked list ***note: I used a static array thus no need to call the delete operator; memory destroyed by default destructor


private:
	ItemType* top = new ItemType[LEN]; //automatically allocate every created object with an array of size 30
	ItemType* listPtr;
	int length;
	int currPos;

};




#endif 