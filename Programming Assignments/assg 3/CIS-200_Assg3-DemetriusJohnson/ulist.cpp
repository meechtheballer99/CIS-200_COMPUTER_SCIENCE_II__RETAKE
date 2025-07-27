

#include "ulist.h"
#include <iostream>



template<class ItemType>
UList<ItemType>::UList() {

	listPtr = nullptr;
	top = nullptr;
	length = 0;
	currPos = 0;

}  // default constructor

template<class ItemType>
UList<ItemType>::UList(const UList<ItemType>& x) {
	
	NodeType<ItemType>* copyNodePointer; //use this pointer to go through the nodes of x and assign its item values to the this-> node's item values
	copyNodePointer = x.top; //set the copy pointer equal to the first element in the linked list
	this->length = x.length; //set length in new list equal to passed-in list length
	this->currPos = 0; //set current pos to starting point at element 0

	this->top = new NodeType<ItemType>;  //allocate memory for the first node (element) in the linked list; use this to keep track of the address of the first node of the linked list (the top)
	this->listPtr = this->top;   //set listPtr to point to first element in the list (top)

	for (int i = 0; i < length; i++) {

		this->listPtr->item = copyNodePointer->item; //set the current node's item pointed to by listPtr equal to the current node's item in x
		if (copyNodePointer->next == nullptr) { return; } //use this to exit function since the below statements will not be necessary if next == nullptr, which means we have reached end of list 
													//Also we do not want the listPtr to point to the next node if the next node == nullptr; then it would point at an invalid node w/o memory 
		this->listPtr->next = new NodeType<ItemType>;  //allocate memory for the next node (element) in the linked list
		this->listPtr = this->listPtr->next; //set list pointer equal to the address of the next node (element) in the list
		this->currPos++;
		copyNodePointer = copyNodePointer->next; //set x linked list ptr to point to next node
	}

	this->listPtr->next = nullptr; //make sure to set the last node's next ptr to NULL


} // we implement copy constructor with deep copy

template<class ItemType>
UList<ItemType>& UList<ItemType>::operator=(UList<ItemType>& x) {

	NodeType<ItemType>* copyNodePointer; //use this pointer to go through the nodes of x and assign its item values to the this-> node's item values
	copyNodePointer = x.top; //set the copy pointer equal to the first element in the linked list



	Initiate_First_Element_ifNecessary(copyNodePointer->item); //use this to initialize the first element if necessary
	this->length = x.length; //set length in new list equal to passed-in list length //making sure this statement comes after the above function so that if length == 0 it will execute initiation of first element
	this->listPtr = this->top;   //set listPtr to point to first element in the list (top)
	this->currPos = 0; //set current pos to starting point at element 0

	for (int i = 0; i < length; i++) {

		this->listPtr->item = copyNodePointer->item; //set the current node's item pointed to by listPtr equal to the current node's item in x
		if (copyNodePointer->next == nullptr) { return *this; } //use this to exit function since the below statements will not be necessary if next == nullptr, which means we have reached end of list 
																 //Also we do not want the listPtr to point to the next node if the next node == nullptr; then it would point at an invalid node w/o memory
		if (this->listPtr->next == nullptr) {
			this->listPtr->next = new NodeType<ItemType>;  //allocate memory for the next node (element) in the linked list if necessary
			this->listPtr->next->next = nullptr; //make sure to set the newly created node's next ptr to NULL
		}
		this->listPtr = this->listPtr->next; //set list pointer equal to the address of the next node (element) in the list
		copyNodePointer = copyNodePointer->next; //set x linked list ptr to point to next node
	}

	this->listPtr->next = nullptr; //make sure to set the last node's next ptr to NULL
	return *this; //return reference

}// equal sign operator with deep copy

template<class ItemType>
void UList<ItemType>::Initiate_First_Element_ifNecessary(ItemType item) {


	if (length == 0) { //use this if to initiate THIS list in the case that it is an empty linked list 
																				

		this->top = new NodeType<ItemType>; //allocate first element; keep track of address of the first element
		this->listPtr = this->top;          //set listPtr to point to first element in the list (top)
		this->listPtr->next = nullptr;
		length++;
		currPos = 0;
		this->listPtr->item = item;
	}


}

template<class ItemType>
bool UList<ItemType>::IsThere(ItemType item) {

	listPtr = top; //initiate pointer to point to first element in the linked list
	currPos = 0;   //after above statement then, the currPos will be element 0
	while (currPos < length) {

		if (listPtr->item == item) { //check current item

			return true;

		}
		else {

			if (listPtr->next == nullptr) { return false; } //use this to exit function since the below statements will not be necessary if next == nullptr, 
															//which means we have reached end of list and item not found so return false
			listPtr = listPtr->next; //move pointer to next node
			currPos++; //I can use this variable to the advantage that if the function returns true, I will know at what position it returned true since the listPtr will be at the correct/last-checked position
		}
	}
	return false; //if while loop is skipped then default item is not in list so return false
}  // return true or false to indicate if item is in the list

template<class ItemType>
void UList<ItemType>::Insert(ItemType item) {

	if (length == 0) {

		Initiate_First_Element_ifNecessary(item); //use this to initialize the first element if necessary
		return; //exit function since above statement will allocate first element and set its element to item to insert
	}
	if (!IsThere(item) && listPtr->next == nullptr) { //first check if item is not in the list already

		//if item is not in the the list then currPos of the listPtr will be at the last node (who's next* ptr is null); so simply allocate memory for the next* pointer at the current node
		listPtr->next = new NodeType<ItemType>; //create the new node, which will be attached at the end of the list
		listPtr = listPtr->next;
		listPtr->next = nullptr;
		listPtr->item = item;
		length++;
		currPos++; //length and position increase by one when we add an element and move the pointer
	}

	else { return; }//otherwise return; item is already in the list
}  // if item is not in the list, insert it into the list

template<class ItemType>
void UList<ItemType>::Delete(ItemType item) {

	if (!IsThere(item)) { return; } //if item is not in the list, then exit function since there is no need for a delete
	if (currPos == 0) { //the above if function will have returned true; thus execute the following statment knowing currPos of the listPtr will be at the location where the item was found

		top = listPtr->next; //change the top to the next node (second element) which will now become the new top
		delete listPtr; //delete the old top (listPtr is currently pointing to the first element which needs to be deleted)
		listPtr = top; //set listPtr to point to a valid memory location - the new first node of the list
		//currPos is still at element 0
		length--; //a node was deleted
		return; //exit, the function has successfully deleted the proper node

	} //handle the case where the first node is deleted

	else {//for all other cases, use this else branch to delete a node

			//need to use node BEFORE the node to be deleted and then do --> delete listptr->next
			//we need to also set the node BEFORE the node to be deleted to point to the node AFTER the node to be deleted
		int initial_CurrPos = currPos; //store the value stored by currentPos since this is the value at which the item was found from calling IsThere() function
		listPtr = top; //initiate listPtr to start at front of the list
		currPos = 0;
		while (currPos < (initial_CurrPos - 1)) { //use initial_currPos - 1 since we need to set the listPtr to equal to the node BEFORE the node to be deleted

			listPtr = listPtr->next;
			currPos++;
		}

		//**self note: local pointers declared in a function will be destroyed at the end of the function/return but the memory address to which they point at remain - including dynamically allocated memory
		NodeType<ItemType>* node_to_delete = listPtr->next; //the next node must be deleted; thus we will use this pointer to deallocate it
		listPtr->next = listPtr->next->next; //set the next node pointed to by the current node equal to the node AFTER the node that will be deleted
		delete node_to_delete; //delete the node to be deleted
		length--; //reduce length since a node was deleted
	}

	return;
}  //  delete item from the list

template<class ItemType>
void UList<ItemType>::Print() {

	NodeType<ItemType>* copyNodePointer; //use this pointer to move through all nodes and print item
	copyNodePointer = top;
	
	for (int i = 0; i < length; i++) {

		std::cout << copyNodePointer->item << " ";
		copyNodePointer = copyNodePointer->next;
	}

	


}  // Print all the items in the list on screen

template<class ItemType>
int UList<ItemType>::Length() {

	return length;


}   // return the number of items in the list

template<class ItemType>
UList<ItemType>::~UList() {

	listPtr = top;
	currPos = 0;
	for (int i = 0; i < length; i++) {

		top = listPtr->next; //change the top to the next node (second element) which will now become the new top
		delete listPtr; //delete the old top (listPtr is currently pointing to the first element which needs to be deleted)
		listPtr = top; //set listPtr to point to a valid memory location - the new first node of the list
	}

}  // programmer should be responsible to deallocate the linked list




