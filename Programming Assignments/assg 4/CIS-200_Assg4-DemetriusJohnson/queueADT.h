

//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date:  04-09-2021
//Purpose: Implement a template class that demonstrates queue implementation

#ifndef STACKADT_H
#define STACKADT_H
#include <iostream>


/*   */



template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};


template<typename ItemType>
class queueADT
{

private:
    NodeType<ItemType>* front; // It points to the front of a singly-linked list //items will enter here
    NodeType<ItemType>* rear; // It points to the end of a singly-linked list    //items will be removed from here
    int length; //use this to easily keep track of the length of the queue

public:
    queueADT();  // default constructor: queueADT is created and empty
    queueADT(const queueADT<ItemType>& x);  // copy constructor: implicitly called for a deep copy
    void MakeEmpty();    // queueADT is made empty; you should deallocate all the nodes of the linked list
    bool IsEmpty();   // test if the queue is empty
    bool IsFull();   // test if the queue is full; assume MAXITEM=5
    int Length();    // return the number of elements in the queue
    void Print();   // print the value of all elements in the queue in the sequence from the front to rear
    void Enqueue(ItemType x);   // insert x to the rear of the queue // Precondition: the queue is not full
    void Dequeue(ItemType& x);  // delete the element from the front of the queue //Precondition: the queue is not empty
    ~queueADT();  // Destructor:  memory for the dynamic array needs to be deallocated

};



#endif // !1



