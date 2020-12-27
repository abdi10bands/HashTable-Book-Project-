
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// ---------------------------------

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:  // these will change depending
           // on the client needs
  string key;      // key
  string name;  // customer name---changed to name of manga
  string author; //author of manga
  int Volume ; //the volume the manga is 
 public:

  el_t();  // to create a blank el_t object   
  el_t(string, string,string, int ); // to create an initialized el_t object - useful for the client, **el_t M('A', 20) teacher said this so its important, this is how you should call them . M is the object Initialized with A and 20.    

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  string getkey(); // only the key part can be accessed by the user of this class.*E.getkey(), says go to el_t object E and rget the key part

  void setkey(string); // only the key part can be accessed by the user of this class.**E.getweight() , says el_t object E and get the weight part


  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);

};
  


