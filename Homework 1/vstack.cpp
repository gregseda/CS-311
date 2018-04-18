//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Greg Seda
//Complier:  g++ compiler
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  Constructor does not have anything to do.
stack::stack()
{  
}
//PURPOSE:  Destructor only has to clear the vector, if there is an error.
stack::~stack()
{ clearIt(); }

//PURPOSE:  checks size of the stack and returns true if empty, false otherwise.
bool stack::isEmpty()
{ if(el.size() == 0) return true; else return false; } 
    
//PURPOSE: always returns false
bool stack::isFull()
{ return false;}
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to the el vector 
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if(isFull()) throw Overflow();
  else{  el.push_back(elem);}}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from the el vector and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
{ if(isEmpty()) throw Underflow(); 
  else{
    elem = el[el.size()-1];
    el.pop_back();}
  
}
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
{ if(isEmpty()) throw Underflow();
  else {elem = el[el.size() - 1];}}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: The loop continously displays each element from the top of the stack until it displays the bottom element 
void stack::displayAll()
{  if (isEmpty()){ cout << "[ empty ]" << endl; }   // if stack is empty, display [ empty ]
  else for (int i= el.size()-1; i>=0; i--)                // displays every element in the stack
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
}
  
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALGORITHM: The loop continously removes each element from the stack, until stack is cleared
 void stack::clearIt()
{
  int i = el.size()-1;                     // i is the index of the top element of the stack  
  if (isEmpty())cout << "[ empty ]" << endl;  // if stack is empty, display [ empty ]
  else for(i; i >=0; i--)                    // removes each element in the stack  
    { pop(el[i]);}
}
 

