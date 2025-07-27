
//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date: 08-04-2021
//Purpose: Implement a template class that demonstrates stack implementation


#include "stackADT.h"

/*  */

template<typename ItemType>
stackADT<ItemType>::stackADT(){

	topPtr = nullptr;
	length = 0;

}  // default constructor: stackADT is created and empty

template<typename ItemType>
stackADT<ItemType>::stackADT(const stackADT<ItemType>& x){

	this->topPtr = new NodeType<ItemType>; // always store the memory address of the first position of the stack
	NodeType<ItemType>* tempPtr = this->topPtr;
	NodeType<ItemType>* copyPtr = x.topPtr;
	this->length = x.length;

	for (int i = 0; i < (length - 1); i++) { //allocate the sufficient number of nodes to copy the passed-in stack. 
										   //do length - 1 since above, the first node was already allocated
	
		tempPtr->next = new NodeType<ItemType>; //create a new node
		tempPtr = tempPtr->next; //move to next node that was just created
	}

	tempPtr->next = nullptr; //assign the end of the stack pointer to NULL so we can track end of the stack easier
	tempPtr = this->topPtr; //set tempPtr to point back to the top of this-> stack for the following loop:

	for (int j = 0; j < length; j++) { //copy the values only of the passed-in stack to this-> stack
									  
		tempPtr->info = copyPtr->info;
		tempPtr = tempPtr->next; //set pointer to point to address of the next node in this-> stack
		copyPtr = copyPtr->next; //set pointer to point to address of the next node in the passed-in stack x

	}

}  // copy constructor: implicitly called for a deep copy

template<typename ItemType>
void stackADT<ItemType>::MakeEmpty(){

	NodeType<ItemType>* tempPtr = this->topPtr; //use this to move along the stack and delete nodes

	for (int i = 0; i < length; i++) { 

		topPtr = topPtr->next; //move the top down the stack
		delete tempPtr; //delete top node
		tempPtr = topPtr; //set tempPtr to point to new top node to be deleted
	}

	topPtr = nullptr; //set top to null since stack is empty
	length = 0; //stack is now empty
	return;
}    // stackADT is made empty{} you should deallocate all the nodes of the linked list

template<typename ItemType>
bool stackADT<ItemType>::IsEmpty(){

	if (length == 0) { return true; }
	else { return false; }


}   // test if the stack is empty

template<typename ItemType>
bool stackADT<ItemType>::IsFull(){

	if (length == 5) { return true; }
	else { return false; }
}   // test if the stack is full{} assume MAXITEM=5

template<typename ItemType>
int stackADT<ItemType>::Length(){

	return length;

}    // return the number of elements in the stack

template<typename ItemType>
void stackADT<ItemType>::Print(){

	NodeType<ItemType>* tempPtr = this->topPtr; //use this to move along the stack and print nodes

	for (int i = 0; i < length; i++) {

		std::cout << tempPtr->info << " "; //print current node
		tempPtr = tempPtr->next; //move to next node to be printed
	}

	return;

}   // print the value of all elements in the stack in the sequence from the top to bottom

template<typename ItemType>
void stackADT<ItemType>::Push(ItemType x){

	if (IsEmpty()) { //execute this case when the stack is empty
	
		topPtr = new NodeType<ItemType>;
		topPtr->info = x;
		topPtr->next = nullptr;
		length++; //new node added
		return;
	}
	if (IsFull()) { //full stack case; do not push value; simply return
		std::cout << "~Unable to push " << x << "onto stack; stack is full~"; 
		return;
	}

	NodeType<ItemType>* tempPtr = topPtr; //use this to store the original first position
	topPtr = new NodeType<ItemType>; // allocate memory for the new node and store the memory address of the new first position of the stack
	topPtr->next = tempPtr; //set new top to point to old top; stack new node atop older node -- this is part of the operation of a stack FILO (first in, last out)
	topPtr->info = x; //assign newly created node its information based on the value to be pushed on the stack (x)
	length++; //new item added ("pushed") to stack (at the top of course!)

	return;
}   // insert x onto the stack   

template<typename ItemType>
void stackADT<ItemType>::Pop(ItemType& x){

	if (IsEmpty()) { return; } //precondition: stack is not empty; if it is empty then exit function

	//stack is Last In First Out; thus we will delete the first position (topPtr) and set topPtr to point to next position - the new top/first position

	NodeType<ItemType>* tempPtr = topPtr; //use this to delete top node
	x = topPtr->info; //set the value of passed in x variable equal to the info stored in the node to be deleted/popped
	topPtr = topPtr->next; //set new top = the next position in the stack
	delete tempPtr; //delete the previous top node which is to be popped (value stored in x, the the node deleted from top of stack)
	length--; //item deleted ("popped") from stack (at the top of course!)

	return;

}  // delete the top element from the stack Precondition: the stack is not empty

template<typename ItemType>
stackADT<ItemType>::~stackADT(){

	NodeType<ItemType>* tempPtr = this->topPtr; //use this to move along the stack and delete nodes

	for (int i = 0; i < length; i++) {

		topPtr = topPtr->next; //move the top down the stack
		delete tempPtr; //delete top node
		tempPtr = topPtr; //set tempPtr to point to new top node to be deleted
	}

}  // Destructor:  memory for nodes needs to be deallocated




