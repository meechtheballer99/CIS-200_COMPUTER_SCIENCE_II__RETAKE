

//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date: 04-09-2021
//Purpose: Implement a template class that demonstrates queue implementation


#include "queueADT.h"
#include <iostream>


template<typename ItemType>
queueADT<ItemType>::queueADT(){

	front = nullptr;
	rear = nullptr;
	length = 0;


}  // default constructor: queueADT is created and empty

template<typename ItemType>
queueADT<ItemType>::queueADT(const queueADT<ItemType>& x){



	this->front = new NodeType<ItemType>; // always store the memory address of the first position of the queue
	NodeType<ItemType>* tempPtr = this->front;
	NodeType<ItemType>* copyPtr = x.front;
	this->length = x.length; //set lengths equal

	for (int i = 0; i < (length - 1); i++) { //allocate the sufficient number of nodes to copy the passed-in queue. 
										   //do length - 1 since above, the first node was already allocated

		tempPtr->next = new NodeType<ItemType>; //create a new node
		tempPtr = tempPtr->next; //move to next node that was just created
	}

	rear = tempPtr; //set rear ptr equal to the last node of the queue
	tempPtr->next = nullptr; //assign the end of the queue pointer to NULL so we can track end of the queue easier
	tempPtr = this->front; //set tempPtr to point back to the front of this-> queue for the following loop:

	for (int j = 0; j < length; j++) { //copy the info values only (deep copy) of the passed-in queue to this-> queue

		tempPtr->info = copyPtr->info;
		tempPtr = tempPtr->next; //set pointer to point to address of the next node in this-> queue
		copyPtr = copyPtr->next; //set pointer to point to address of the next node in the passed-in queue x

	}


}  // copy constructor: implicitly called for a deep copy

template<typename ItemType>
void queueADT<ItemType>::MakeEmpty(){

	NodeType<ItemType>* tempPtr = this->front; //use this to move along the queue and delete nodes

	for (int i = 0; i < length; i++) {

		front = front->next; //move the front ptr down the queue
		delete tempPtr; //delete front node
		tempPtr = front; //set tempPtr to point to new front node to be deleted
	}

	front = nullptr; //set front to null since queue is empty
	rear = nullptr; //set rear to null since queue is empty
	length = 0; //queue is now empty
	return;

}  // queueADT is made empty{} you should deallocate all the nodes of the linked list

template<typename ItemType>
bool queueADT<ItemType>::IsEmpty(){

	if (length == 0) { return true; }
	else { return false; }

} // test if the queue is empty

template<typename ItemType>
bool queueADT<ItemType>::IsFull(){

	if (length == 5) { return true; }
	else { return false; }

} // test if the queue is full{} assume MAXITEM=5

template<typename ItemType>
int queueADT<ItemType>::Length(){

	return length;

} // return the number of elements in the queue

template<typename ItemType>
void queueADT<ItemType>::Print(){

	NodeType<ItemType>* tempPtr = this->front; //use this to move along the queue and print nodes

	for (int i = 0; i < length; i++) {

		std::cout << tempPtr->info << " "; //print current node
		tempPtr = tempPtr->next; //move to next node to be printed
	}

	return;

} // print the value of all elements in the queue in the sequence from the front to rear

template<typename ItemType>
void queueADT<ItemType>::Enqueue(ItemType x){


	if (IsEmpty()) { //execute this case when the queue is empty

		rear = new NodeType<ItemType>; //create first node
		front = rear; //there is only one node; thus front points to same node as rear
		rear->info = x; //store x value into node
		rear->next = nullptr;
		length++; //new node added to rear
		return;
	}
	if (IsFull()) { //full queue case; do not push value; simply return
		std::cout << "~Unable to insert item " << x << "into queue; queue is full~";
		return;
	}
	 //case: all preconditions met:
	rear->next = new NodeType<ItemType>; //create new node to be added to rear //for queue ADT, items are added to rear, and removed from front
	rear = rear->next; //set new rear
	rear->info = x; //insert the value into the new node
	rear->next = nullptr; //new rear next ptr points to nothing so set it to nullptr
	length++; //new node added; increase length by 1
	return;


}   // insert x to the rear of the queue // Precondition: the queue is not full

template<typename ItemType>
void queueADT<ItemType>::Dequeue(ItemType& x){

	if(IsEmpty()){ 
		
		std::cout << "~queue is empty; no item dequeued...~";
		return; 
	} //precondition: queue is not empty; if it is empty then exit function

	//queue ADT has items enter the rear, and exit from the front (first in, first out --> FIFO)

	NodeType<ItemType>* tempPtr = front; //use this to delete front node
	x = front->info; //set the value of passed in x variable equal to the info stored in the node to be deleted/dequeued
	front = front->next; //set new front = the next position in the queue
	delete tempPtr; //delete the previous front node which is to be dequeued (value stored in x, then the node deleted from front of queue)
	length--; //item deleted ("dequeued")

	return;
}  // delete the element from the front of the queue //Precondition: the queue is not empty

template<typename ItemType>
queueADT<ItemType>::~queueADT(){


	NodeType<ItemType>* tempPtr = this->front; //use this to move along the queue and delete nodes

	for (int i = 0; i < length; i++) {

		front = front->next; //move the front down the queue
		delete tempPtr; //delete front node
		tempPtr = front; //set tempPtr to point to new front node to be deleted
	}

}  // Destructor:  memory for the dynamic array needs to be deallocated