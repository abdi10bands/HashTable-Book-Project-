

#include "slist.h"

const int TSIZE = 41;  //slots ; 

class htable
{
 private:
 slist table[TSIZE]; // each node of slist is el_t 
                          // as defined in elem.h
 int hash(string);  // private hash function

 public:
  htable();
  ~htable();

  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(string); // finds an element based on key and returns it
  void displayTable(ofstream&); // displays the table with slot#s
   int deleteIt(el_t); 

  //displays to file and to the user
};
