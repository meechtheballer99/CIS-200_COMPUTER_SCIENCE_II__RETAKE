

//Author: Demetrius E Johnson
//Date: 08 April 2021
//Last Modification Date: 08-04-2021
//Purpose: Implement a template class that demonstrates stack implementation

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
class stackADT
{

private:
    NodeType<ItemType>* topPtr; // It points to a singly-linked list
    int length; //tracks the length (number of elements) of the stack
public:
    stackADT();  // default constructor: stackADT is created and empty
    stackADT(const stackADT<ItemType>& x);  // copy constructor: implicitly called for a deep copy
    void MakeEmpty();    // stackADT is made empty; you should deallocate all the nodes of the linked list
    bool IsEmpty();   // test if the stack is empty
    bool IsFull();   // test if the stack is full; assume MAXITEM=5
    int Length();    // return the number of elements in the stack
    void Print();   // print the value of all elements in the stack in the sequence from the top to bottom
    void Push(ItemType x);   // insert x onto the stack   
    void Pop(ItemType& x);  // delete the top element from the stack Precondition: the stack is not empty
    ~stackADT();  // Destructor:  memory for nodes needs to be deallocated

};



#endif // !1



