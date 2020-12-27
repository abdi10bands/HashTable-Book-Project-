// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key ="" ; //was -1 // cannot be 0 because 0 is a valid key
  name = "";
  author = "";
  Volume = -1;
}

// initializing constructor to create an el_t object 
el_t::el_t(string akey, string aname,string Aauthor, int avolume)
{
  key = akey; // **sets the key part to the arguemnt passed 
  name = aname; //**sets the name part to the arguemnt names passed.
  author= Aauthor; // sets the author part to the argument passed
  Volume = avolume; //sets the volumr part to the argument passed

}

string el_t::getkey()//------------this was return type int before dont forget
{
  return key; // I addedthis comment returns the key
}
 
void el_t::setkey(string akey)
{
  key = akey;// sets the key
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)//comparing the reciever to the otherOne.
{
  if (key == OtherOne.key) return true; else return false;// what we do is compare the key parts only, not names. Ex A1 and A2 will match, and return true if they match, false is they dont
}
//**overload the != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;//** what we do is compare the key parts only, comparing the reciver to the otherOne  
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << " " << E.name<<" "<<E.author<<" "<<E.Volume;//os sends to the given stream the E.key part , and then I space " " then the name.
  return os;  
}  
