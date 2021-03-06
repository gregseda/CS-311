//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Greg Seda
// Compiler:  g++ compiler
// File type: header file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------
#include <vector>
using namespace std;
typedef int el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  vector<el_t> el;    //vector of the el_t variable named el
    
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t& );
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  void topElem(el_t& );
  
  // ** Must add good comments for each function - See Notes1B

  //PURPOSE: Checks to see if the stack is empty.
  bool isEmpty();
  //PURPOSE: Checks to see if the stack is full.
  bool isFull();
  //PURPOSE: Displays all elements without changing the stack.
  //If the stack is empty, display [ empty ]
  void displayAll();
  //PURPOSE: Empties the stack completely.
  //If the stack is empty, display [ empty ]
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

