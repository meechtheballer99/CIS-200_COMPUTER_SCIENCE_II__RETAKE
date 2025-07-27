#include "UnsortedList.h"
#include <iostream>

UnsortedList::UnsortedList() { length = 0; currentPos = -1; } // default constructor: lenght=0, currentPos=-1

void UnsortedList::MakeEmpty() { length = 0; }    // let length=0

void UnsortedList::InsertItem(ItemType x){

	if (length == 10) { std::cout << "unable to add item; list is full.\n\n"; }
	else {
		
		values[length] = x;
		length++;

	}

	return;

}   // insert x into the list 

void UnsortedList::DeleteItem(ItemType x){

	for (int i = 0; i < length; i++) {

		if (values[i] == x) { //this will find the first match beginning at start of list //it will not delete more than on items if the item exists more than once in the list

			values[i] = values[length - 1]; //take last item and set it equal to the item to be deleted
			length--; //even if length is 1, the element will be replaced with itself, but when length-- is executed then it won't matter since the list size will now be 0
		}

	}
	return;
}  // delete x from the list

bool UnsortedList::IsFull() { return (length == MAX_ITEMS); }   // test if the list is full

int UnsortedList::LengthIs() { return length; }   // return length

void UnsortedList::RetrieveItem(ItemType& x, bool& found){

	for (int i = 0; i < length; i++) {

		if (values[i] == x) { //this will find the first match beginning at start of list //it will not delete more than on items if the item exists more than once in the list

			found = true;
		
		}
		else { found = false; }
		

	}
	return;

} // retrieve x from the list, the boolean result is stored in found

void UnsortedList::ResetList() { currentPos = -1; }  // currentPos = -1

void UnsortedList::GetNextItem(ItemType& x){

	if (length != 0 && currentPos != 9) { x = values[++currentPos]; } //if currPos == 9, then the next element would be 10, which is invalid range; value array size is 10 == elements 0 - 9.

	return;
}    // get the next element from the list with respect to the currentPos

void UnsortedList::printElement(){

	for (int i = 0; i < length; i++) {

		std::cout << values[i] << " ";
	}

}  // print out the values of all the list elements, separated by a white space 