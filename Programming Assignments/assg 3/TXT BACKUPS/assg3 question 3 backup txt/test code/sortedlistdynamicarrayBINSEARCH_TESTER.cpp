

#include "sortedlistdynamicarray.h"
#include <iostream>

template<class ItemType>
SortedList_DynArr<ItemType>::SortedList_DynArr(){

	listPtr = top;
	length = 0;
	currPos = 0;

}  // default constructor: dynamically allocate an array with "new" operator


template<class ItemType>
SortedList_DynArr<ItemType>::SortedList_DynArr(const SortedList_DynArr& x){

	
	length = x.length; //set lengths equal
	currPos = 0;

	for (int i = 0; i < length; i++) { //implement deep copy

		top[i] = x.top[i];
	}

}  // we implement copy constructor with deep copy


template<class ItemType>
SortedList_DynArr<ItemType>& SortedList_DynArr<ItemType>::operator=(SortedList_DynArr<ItemType>& x){


	length = x.length; //set lengths equal

	for (int i = 0; i < length; i++) { //implement deep copy

		top[i] = x.top[i];
	}

	return *this;
} // equal sign operator with deep copy


template<class ItemType>
bool SortedList_DynArr<ItemType>::IsThere(ItemType item) {

	//since we are using a dynamic array for a sorted list (in descending order), we will implement binary search
	
	int fromLoc = 0;
	int toLoc = length;
	int middle = (fromLoc + toLoc)/2;

	while (fromLoc < toLoc) {

		if (item == top[middle]) {

			currPos = middle; //use this so that this function indicates where the element was found so it can be used by other functions in this class
			return true;
		}
		if (item < top[middle]) { //smaller items are further down the list for descending order sorted list

			fromLoc = middle;
			middle = (fromLoc + toLoc) / 2;
		}
		if (item > top[middle]) { //larger items are at the top of the list for descending order sorted list


			toLoc = middle;
			middle = (fromLoc + toLoc) / 2;
		}
		
	}

	return false; //if above while loop exits then it means item not found

}  // return true of false to indicate if item is in the list


template<class ItemType>
void SortedList_DynArr<ItemType>::Insert(ItemType item){

	if (length == 0) { //empty list case
	
		top[0] = item;
		length++;
		return;
	
	}
	if (top[length - 1] > item) { //add to end case

		top[length] = item;
		length++;
		return;
	}
	if (!IsThere(item) && (length < 30)) { //insert between case
		int fromLoc = 0;
		int toLoc = length;
		int middle = (fromLoc + toLoc) / 2;
		//simulate binary search to find correct insertion point for item
		while (fromLoc <= toLoc) {

			if ((item < top[middle] && item > top[middle + 1]) || item > top[0]) { //use this if stmnt to see wether item is a value between 2 values in the list; thus we have found the insertion pt
				
				listPtr = top;
				listPtr += length - 1; //point to last element
				ItemType holder;

				for (int i = 0; i < (length - middle); i++) { //shift all elements down and make room for the item to be inserted

					holder = *listPtr;
					listPtr++;
					*listPtr = holder;
					listPtr - 2;
				}

				top[middle + 1] = item; //insert item
				length++;

				return;
			}
			if (item < top[middle]) { //smaller items are further down the list for descending order sorted list

				fromLoc = middle;
				middle = (fromLoc + toLoc) / 2;
			}
			if (item > top[middle]) { //larger items are at the top of the list for descending order sorted list


				toLoc = middle;
				middle = (fromLoc + toLoc) / 2;
			}

		}
	}
	else { return; } //item already in list

}  // if item is not in the list, insert it into the list


template<class ItemType>
void SortedList_DynArr<ItemType>::Delete(ItemType item){


	if (IsThere(item)) {
	
	//isthere sets currentPos where element was found
	
	
				listPtr = top; //point to top
				listPtr += currPos; //point to found element to be deleted
				ItemType holder;

				for (int i = currPos; i < length; i++) { //shift all elements up after deletion of item; deletion item will simply be overwritten

					listPtr++; //advance ptr
					holder = *listPtr; //hold next value
					listPtr--; //go to previous element
					*listPtr = holder; //overwrite prev element
					listPtr++; //move to next element to shift left
				}

				length--;
				return;
	}
}  //  delete item from the list


template<class ItemType>
void SortedList_DynArr<ItemType>::Print(){

	for (int i = 0; i < length; i++) {

		std::cout << top[i] << " ";

	}


}  // Print all the items in the list on screen


template<class ItemType>
int SortedList_DynArr<ItemType>::Length(){

	return length;

}   // return the number of items in the list


template<class ItemType>
SortedList_DynArr<ItemType>::~SortedList_DynArr(){


	delete top;

} //deallocate the dynamic array with “delete” operator




