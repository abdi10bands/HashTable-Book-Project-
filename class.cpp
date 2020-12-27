// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: **Abdiel Verdin 
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "class.h"
#include<string>
#include <fstream>
//#include <bits/stdc++.h>
htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(string key)
{ //** 
  int total=0;
  string temp="";
  // for(int i = 0; i< key.lenght();i++)
  char item;
  for(int i =0; i<key.length(); i++) 
  {
    item = key[i];
    if(isdigit(item))//ch
      {
	int x=int(item-'0');

	//	cout<<"Value before I ascii it "<<key[i]<<endl;
	//	cout<<"Value after I ascii it "<<x<<endl;
	total+=x;
      }
    else
      {
       
      }

    }
  //   cout<<"The numbers in the string are "<<total<<endl;
  //-----key is the 3 digits entered 
  return total%TSIZE;//----- i added this 

}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  //   cout<<"element key "<<element.getkey();
  int slot = hash(element.getkey());  // hash with the key part
  table[slot].addRear(element);//  ** Note that this means adding the element to a slist in the slot (addRear)
  // cout<<"in slot number "<<slot<<endl;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(string skey)
{ 
 int slot = hash(skey); // hash with skey
 //-------------------- cout<<"the slot number is "<<slot<<endl;
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey);// ** // initialize selement with just the skey
 //----------------- int key = selement.getkey();
 //-------------------cout<<"Selement key "<<key<<endl;
 // slist obj;
 selement= table[slot].search2(selement);// ** // call slist's search2 with selement which returns the found element 
 // ** // return the found element from here (it could be blank)

 return selement; 
 }


// displays the entire table with slot#s too

void htable::displayTable(ofstream& fout)
{
  fout.open("newout.txt");
  for (int i = 0; i < 37; i++)
    { //cout << i << ":" ;   
      table[i].displayAll(fout);//  ** // call slist's displayAll
    }
  fout.close();
}

int htable::deleteIt(el_t element)
{
  // What does this function do , well this functions is supposed to delete an object in the array that holds linked list. Like each slot in the array holds an object or mutiple ojects in one specific array slot. So here our plan is to delete a sepcfic object in the slot. The trick here is that one slot can hace mutiple linked list or none or just one. Here we have to delete .
  //1) so the first thing that happens is that we recieve the element tha only holds the KEy which is the ISBN , and we the first thing we go is send it to get hashed and after hashed we recieve the slot # which we store into "slot" .

  //2) Now that we have the slot number we can call the search fucntions is slist which can return the position in the linked list in that sepcific slot in the table(array). We use the" ." operator . 

  //3) Now that we have the positon we can go ahead and delete it using the DeleteIth function , DeleteIth takes in as arguments  a position and a element, here we have gotten both. SO dleteIth deletes its

  //4) Then we just have to return the slot number to present it to the user and then we good.

  int slot = hash(element.getkey());// so we sent the key to hash 
  int position = table[slot].search(element);//then we send to search function the element , the search function returns the position of the that object "element" in the linked list.
  // cout<<"In slot number "<<slot <<"The position in the linked list returned was "<<position<<endl;//we test it out 
  table[slot].deleteIth(position,element);
  return slot;
 


}


