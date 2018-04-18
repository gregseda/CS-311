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
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; // indicate an empty stack 
}
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
  { // nothing to do 
  }
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{ if (top == -1) return true; // indicates top is equal to -1, it is empty
  else return false; }   // indicates the stack has some elements in it
    
//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{ if (top == MAX-1) return true;  // indicates top is greater than MAX-1, it is full
  else return false;}   //  indicates the stack has room for more elements
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if (isFull()) throw Overflow();       // if stack is full, so it shows error message
  else { top++; el[top] = elem; }}      // increments top, makes the new element the top
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
{ if (isEmpty()) throw Underflow();    // if stack is empty, so it shows error message
  else { elem = el[top]; top--;}}      // decrements top, removes top element
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
{ if (isEmpty())throw Underflow();    // if stack is empty, so it shows error message
  else { elem = el[top]; } }          // displays the top element of the stack
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: The loop continously displays each element from the top of the stack until it displays the bottom element 
void stack::displayAll()
{  if (isEmpty()){ cout << "[ empty ]" << endl; }   // if stack is empty, display [ empty ]
  else for (int i=top; i>=0; i--)                // displays every element in the stack
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALGORITHM: The loop continously removes each element from the stack, until stack is cleared
 void stack::clearIt()
{
  int i = top;                             // i is the index of the top element of the stack  
  if (isEmpty())cout << "[ empty ]" << endl;  // if stack is empty, display [ empty ]
  else for(i; i >=0; i--)                    // removes each element in the stack  
    { pop(el[i]);}
    
}
 

