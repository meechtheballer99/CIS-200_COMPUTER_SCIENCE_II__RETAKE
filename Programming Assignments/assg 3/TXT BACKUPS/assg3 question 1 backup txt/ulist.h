
#ifndef ULIST_H
#define ULIST_H

template<class ItemType>
struct NodeType
{
	ItemType item;
	NodeType<ItemType>* next;

};

template<class ItemType>
class UList
{
public:
	UList();  // default constrctor
	UList(const UList& x);  // we implement copy constructor with deep copy
	UList<ItemType>& operator=(UList<ItemType>& x); // equal sign operator with deep copy
	void Initiate_First_Element_ifNecessary(ItemType item); // I added this function to check for and make it easier to initiate the first element in a linked list
	bool IsThere(ItemType item);  // return true of false to indicate if item is in the list
	void Insert(ItemType item);  // if item is not in the list, insert it into the list
	void Delete(ItemType item);  //  delete item from the list
	void Print();  // Print all the items in the list on screen
	int Length();   // return the number of items in the list
	~UList();  // programmer should be responsible to deallocate the linked list


private:
	NodeType<ItemType>* listPtr;
	NodeType<ItemType>* top;
	int length;
	int currPos;

};




#endif 