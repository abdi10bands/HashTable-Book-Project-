// Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.


#include "class.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ** Purpose of your program here

int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  string ISBN;    // ** change
  string name;// ** change and add more
  string Author;//Auhtor
  int TheVolume;// The volume
  el_t E;     // blank element

  // File info declared outside switch
  string fname;
  cout << "What is the input file?";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout", ios::out);


  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the table" << endl;
      cout << "3. Search using a key" << endl;
      cout << "4. Add a new entry" << endl;
      cout << "5. Delete an entry" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1: // ** change element parts to yours
	  while (fin >> ISBN)//isbn
	    { fin >> name;
	      fin>> Author;
	      fin>> TheVolume;
	      T.add(el_t(ISBN, name,Author,TheVolume));
	    } 
	  cout << "loaded data..." << endl; 
	  break;

	case 2:
	  T.displayTable(fout); //@@
          break;

	case 3: // ** change key to yours
	  cout << "Enter key to look for: ";
	  cin >> ISBN; 
	  E = T.find(ISBN);
	  if (E == el_t()) /// blank
	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts to yours
          cout << "Enter a key: "; cin >> ISBN;// ISBN
	  cout << "Enter a name: "; cin >> name; // Manga name
	  cout<< "Enter a Author: "; cin >>Author; // Author 
	  cout << "Enter a Volume Number: "; cin>> TheVolume;//Voluem
	  cout << "In Slot: " << T.add(el_t(ISBN, name, Author,TheVolume));
          cout << "  added." << endl;
	  break;
	  
	case 5: // ** change key to yours
          cout << "Enter a key: "; cin >> ISBN;
          cout << "In Slot: " << T.deleteIt(el_t(ISBN,"", "", -1)); //@@
          cout << "  deleted." << endl;
          // ** what happens if the item was not found?
	  break;
	   
	case 6:
	  T.displayTable(fout);
	  cout << "Sent data to newout" << endl; 
	  break;
	  
        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop
  fin.close();
  fout.close();
}

