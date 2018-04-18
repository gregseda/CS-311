/*=====================================
HW#: HW3P2 slist
Name: Greg Seda
Compiler: g++ compiler
File type: slist header file
=======================================*/

#include "llist.h"

class slist: public llist
{
 
 public:

  slist();   // constructor which is the same as the llist one

  slist(const slist&);  //copy constructor

  slist& operator=(const slist&);  //overloads the = operator

  bool operator==(slist);         //overloads the == operator

  int search(el_t);
  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.
  
  void replace(el_t,  int);
  // go to the Ith node (if I is between 1 and Count) and
  // replace the element there with the new element.
  // If I was an illegal value, throw OutOfRange
};


