//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Abdiel
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
//typedef char el_t;//**
#include "elem.h"
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};             // Dont forget that node is a type
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //**
  //Purpose: returs true if is Empty, otherwide is false. Front and Rear should equal NULL and count =0; 
  bool isEmpty();
    
  //Purpose: Display each element of the list starting from front, enclosed [] followed by endl;
  void displayAll(ofstream&);

  //Purpose: To add element to the front of the linked list. With 2 cases Special case if its going to be the very first node you must create a new node and make Front and Rear point ot it. Put New Num in the Elem field of this new Node. Count gets updated. Reegular Case add a new node at the front and puts NewNum in the Elem field  of this new node. Count is updated. 
  

  void addFront(el_t);
    
  //Purpose: To add element to the the front of the linked list. Special case if it is going to be the very first node you must create a bew node aand  ake front and Rear point ot it. Put newNum in the Elem field of this New node. Count it updated. Regular case add a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated
  void addRear(el_t);

  //Purpose:To dlete the front element of the linked list. error case: if the List is empty, throw an exception.special case: if this is going to make the list empty, give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated.Make sure both Front and Rear both become NULL.regular case:  give back the front node element through OldNum (pass by reference)and also remove the front node. Count is updated.
  
  void deleteFront(el_t&);
    
  //Purpose: To delete the rear element of the linked list     error case: if empty, throw an exception. special case: if this is going to make the list empty, ( when we say removed we mean delete )give back the rear node element through OldNum (pass by reference)and also remove the rear node. Count is updated.Make sure both Front and Rear become NULL regular case: give back the rear node element through OldNum (pass by reference)and also remove the rear node. Count is updated

  void deleteRear(el_t&);
    
  //Purpose: To delete as specific node the ith Node. Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.Special cases: this should simply call deleteFront (I = 1) or deleteRear (I == Count) for some cases.Regular case: will delete the Ith node (I starts out at 1).  Count is updated.
  void deleteIth(int, el_t&);  // calls moveTo

  //Purpose: Insert a node to specific spot Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.Special cases: this should simply call addFront (I == 1) or addRear (I == Count+1) for some cases.Regular case:  will add right before the Ith node.  Count is updated.
    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
