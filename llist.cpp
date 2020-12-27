// Linked List class
//Your name: Abdiel Verdin
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 
#include <fstream>
llist::llist()
{
  //  cout << "... in llist constructor..." << endl;
  Front=NULL;
  Rear=NULL;
  Count=0;

}

llist::~llist()
{ 
  el_t x;
  //  cout << ".... in llist destructor..." << endl;
  while(isEmpty()==false)
    {
      deleteFront(x);
    }
 }

//PURPOSE: To check if the linked list is Empty, returns true if linked list is empty , false if its not.
//PARAMETER: No parameter 
bool llist::isEmpty() {if ((Front==NULL)&&( Rear==NULL)&& (Count==0))return true;
  else
 return false; } // be sure to check all 3 data members

//PURPOSE: Function which dislpays the whole liked list, seperated by [here ]
//PARAMETER: No parameters
void llist::displayAll(ofstream& fout)
 {
   Node*P;
   P=Front;
   //Special case: 
   if(isEmpty())
     { cout<<"[empty]"<<endl;
       // fout<<""<<endl;
     }
   else
     {
       cout<<"";

       //Regular Case:
       //       Node*P; 
       // P=Front;
       while(P!=NULL)//go all the way to the end 
	 {
	   fout<<" "<<P->Elem<<" ";
	   cout<<" "<<P->Elem<<" ";
	   P=P->Next;
	   // cout<<P;

	 }
       cout<<""<<endl;
       fout<<""<<endl;

     }
 }  // be sure to display horizontally in [  ] with
// blanks between elements

  
//PURPOSE: To add an element to the linked list or to create a Linked list 
//PARAMETER: One Parameter being NewNum which is the element being inserted into node
void llist::addRear(el_t NewNum)
 { 
   // Rear->Next
   //Special Case:
   cout<<" In add Rear "<<endl;
   if(isEmpty())//special case 1 for the very first node
     {
       Front = new Node; //front now points to a new node
       Front->Elem=NewNum;//inserting the value into the node
       Rear = Front; // first node meaning front pointer and rear pointer poin to the same node
       Rear->Next = NULL; //Rear-> Next should always be NULL because that us the pointer we are moving to add, we dont want no dangling pointers danger
       Count++;
       // NOW I STARTED A LINKED LIST     
     }
   //Regular Case:
   else
     {
       Rear->Next = new Node; // added a new Node at the end
       Rear = Rear-> Next; // now Rear points to the Next [ |* ] of the new node
       Rear->Elem=NewNum; //now the NewNum gets inserted into the node [ NewNum| * ] 
       Rear->Next= NULL;
       Count++;
     }
  } // comment the 2 cases

//PURPOSE:To add an element to the front of the linked list 
//PARAMETER: New Num which is the element we are adding to the front of the linked list
void llist::addFront(el_t NewNum)
 {
   if(isEmpty())//special case 
     {
       Front = new Node; //front now points to a new node
       Front->Elem=NewNum;//inserting the value into the node
       Rear = Front; // first node meaning front pointer and rear pointer poin to\the same node
       Rear->Next = NULL; //Rear-> Next should always be NULL because that us the \pointer we are moving to add, we dont want no dangling pointers danger
       Count++;
 // NOW I STARTED A LINKED LIST
     }
   else
     {       Node*X; //created a temporary node pointer
       X = new Node; // X now pints to a new Node
       X->Next= NULL; // no danggling pointer
       X->Elem= NewNum; // now we insert the value in the new Node                      f         
       X->Next= Front; // [ NewNum |*- ]---> points to what is the front at the moment  [  |  ]
       Front = X; // now Front points moves to where x is , so now we have a new front
       Count ++;
     }

 } // comment the 2 cases

 //PURPOSE:To delete the first node of the linked list 
//PARAMETER: Oldnum is the value being delted from the linked list, which has to be by reference because we deleting the actual value 
void llist::deleteFront(el_t& OldNum)
 {
   // we have to know the second node to delete the front because that is where we are going to move the Front poiter to
  
   //Error Case:
  if (isEmpty())
    throw Underflow();


   //Special Case: if this is going to make the list empty, give back the front node element through OldNum,
  else if(Front->Next==NULL)
    {
      OldNum = Front->Elem; // the spot in the node where the Elem is at is inserted into OldNum
      delete Front; // deletes the front Node ofcourse after retreaving the value from it
       Front=NULL;
       Rear=NULL;
      Count--;//updated count
    }
   // (pass by reference) and also remove the front node. Count is updated.
  
  else //Regular Case:
    {
      OldNum = Front->Elem; // the spot in the node where the Elem is at is inserted into OldNum
      Node*Second;// Initialize a pointer of the type node named Second
      Second = Front->Next; // Now the pointer second poits to the secodn node in the linked list
      delete Front; // deletes the front Node ofcourse after retreaving the value from it 
      Front = Second; // Now we move the Front Pointer to the second which now becomes our new front
      Count--;
    }
   //Regular Case:give back the front node element through OldNum (pass by reference)
   // and also remove the front node. Count is updated.
   //you c Front=NULL;
 } // comment the 3 cases

//PURPOSE: To delte the last Node of the linked list where the Rear pointer is pointing to 
//PARAMETER: OldNum is a parameter by reference because we are going to grab the value before we delete it
void llist::deleteRear(el_t& OldNum)
{

  //Error case: If its empty, throw exception
  if(isEmpty())
    throw Underflow();
  
  //Special case:  
  else if(Front->Next==NULL)
    {
      OldNum = Rear->Elem;//Inserted rhe value that was in the rear node into Oldnum
      delete Rear;
      Front=NULL;
       Rear=NULL;
      Count--;//updated count
    }
  else
    {
  // Regular case:
      Node*P;//temp pointer
      P=Front;//P starts at front
 
      while(P->Next!=Rear)//stops right before the rear node 
	{
   	  P=P->Next;
	  //OldNum = Rear->Elem;//Inserted rhe value that was in the rear node into Oldnum
	  // cout<<P->Elem;
	}
      //      cout<<P->Elem;
      OldNum = Rear->Elem;//Inserted rhe value that was in the rear node into Oldnum

      delete Rear;
	 
      Rear=P; //Now the rear is what was the second to Last 
      Rear->Next=NULL; //no danggling pointer 
      Count--;
	
    }
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  temp=Front;
  for ( int K = 1; K<=J-1; K++ )
    {
       temp = temp->Next;
    }
}

//PURPOSE: Deletes a node of the choosing and gives back the value in the Node and then deletes it. 
//PARAMETER: int I which is the user chosen node we want to delete, OldNum which is the value in that Node. 
void llist::deleteIth(int I, el_t& OldNum)
 {
   //Error Case: 
   if(( I > Count)|| ( I < 1 ))
     throw OutOfRange();
   //Special Case:
   else if( I==1)// If they want to delete te first call the deleteFront function
   deleteFront(OldNum);
   else if (I == Count) //they want to delete the Rear Node 
   deleteRear(OldNum);
   //Regualar Case:
   else
     {
       int before = I-1;
       int after = I+1;
       Node *P;//created a pointer temporary we will bypass this pointer like in the videos. 
       Node *Q;//Pointer for the Node after
       Node *Ith;//Pointer for the node going to be deleted
       moveTo(before,P);
       moveTo(after,Q);
       moveTo(I,Ith);
   
       OldNum=Ith->Elem;//number gets rerrived from node we deleating
       delete Ith;
       P->Next=Q; //going over the Ith node to point to the Q 
       Count--;
     }
 } // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:Inserts Node if the choosing and a specific value into that node
//PARAMETER: int I, which is where the Node is going to be placed. NewNum is the new Element in that value.
void llist::insertIth(int I, el_t newNum)
 {
   //Erro case:
   if((I > Count+1)|| (I < 1))
     throw OutOfRange();
   //Special case:
   else if( I ==1)
     {
       addFront(newNum);
     }
   else if (I == Count +1)
     {
       addRear(newNum);
     }
   //Regular case:
   else
     {
         int before = I-1;
         int after = I;
         Node *P;//created a pointer temporary we will bypass this pointer like in the videos.
         Node *Q;//Pointer for the Node after
         Node *Ith;//pointer to the Ith node
         moveTo(before,P);//before where we wan to insert
	 moveTo(I,Ith);//moves to where we want to insert
	 moveTo(after,Q);//also moves where we want to insert
	 Ith= new Node; // Ith now pints tho this new node , and created a new node
	 Ith->Elem = newNum;

	 P->Next= Ith;  // P next now points to the new node 
	 Ith->Next = Q; //Ith next now points to this new new node 
         Count ++;
     }


 } // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Copy machine also known as copy constructor , copies from the orginal to the reciever object 
//PARAMETER: Original List being sent to the copy machine 
llist::llist(const llist& Original)
 {
   //  this->'s data members need to be initialized here first
   Front = NULL; Rear = NULL; Count = 0;
   //  this-> object has to be built up by allocating new cells
   //  and copying the values from Original into each cell as we did with 
   //  operator= above. To do this,
   Node* P;  // local pointer for Original
   P = Original.Front ;
   while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
     {
       this->addRear(P->Elem);    //P’s element is added to this->
       P = P->Next;                         // Go to the next node in OtherOne   
     } 
       


 } // use my code

//PURPOSE: Top overlaod the = operator , we teaching the computer to understand what = means when using the linked 
//list, = means gets. We copy One list to another, we have to use overloaded operator because we use pointers
//PARAMETER: LList that is being copied, be reference because we do not want a copy 
llist& llist::operator=(const llist& OtherOne)
//   ^ & because we are returning the reciver object by reference  
 {
   el_t x;
   // First make sure this-> and OtherOne are not the same object.
   // To do this, compare the pointers to the objects .
   if (&OtherOne != this)  // if not the same
     {
       // this-> object has to be emptied first.
       while (! this->isEmpty() )
	 this->deleteRear(x);  
       // this-> object has to be built up by allocating new cells with OtherOne elements (**)
       Node* P;  // local pointer for OtherOne
       P = OtherOne.Front;
       while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	 {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
     }// end of if              
   return *this; 
       

 } // use my code

