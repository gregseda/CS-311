/*===========================================
HW#: HW3P2
Name: Greg Seda 
Compiler: g++ compiler
File Type: slist implementation file
============================================*/

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE: Does nothing, same as the llist constructor
slist::slist()
{
}
//PURPOSE: copy constructor that copies one linked list(Original) to another linked list
//ALGORITHM: the while loop continuously loops until it copies every element in the linked list Orignal
slist::slist(const slist& Original)
{
  this->Front=NULL;
  this->Rear=NULL;
  this->Count=0;

  Node* P;  // local pointer for Original
  P = Original.Front;
  while (P != NULL)  // This uses a loop which repeats until you reach the end of Original. 
    {
      this->addRear(P->Elem);    //P.s element is added to this->
      P = P->Next;               // Go to the next node in Original 
    } 
}
//PURPOSE: Overloads the == operator, so the client can compare linked lists
//ALGORITHM: the while loop continuously loops until it is done comparing the two lists
bool slist::operator==(slist Original)
{
  if(this -> Count != Original.Count)    //If the count both lists do not match, then return false
    {return false;}

  Node* p;      //local pointer for Original
  Node* p2;     //second local pointer for Orignal

  p = this -> Front;
  p2 = Original.Front;
  while(p != NULL)              //this uses a loop which repeats until it is done comparing the two lists
    {
      if(p -> Elem != p2 -> Elem)    //if an element in each list do not match, then return false
	{
	  return false;
	}
      p = p -> Next;
      p2 = p2 -> Next;
    }
  return true;                    //returns true if all of the elements match
}
//PURPOSE:  Overloads the = operator, so the client can make a linked list equal another linked list
//ALGORITHM: the while loop continuosuly copies the elements from one list(OtherOne) into another list
slist& slist:: operator=(const slist& OtherOne)
{
  int x;  //contains the removed element
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells (OtherOne)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P.s element is added to this->
	  P = P->Next;               // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;     //return the result unconditionally
  
}
//PURPOSE: The function will go through the linked list to see if any node contains the given key. 
//if the Key is found, then return the found position
//otherwise return 0
//ALGORITHM: the loop will continuously sift through the list and stop once the Key is found or the entire list has been searched 
int slist:: search(el_t Key)
{
  Node *P;                  //node pointer p
  int position = 1;         //position for the element starts at 1
  P = Front;
  
  while(P != NULL)          //sifts through the linked list to see if the key matches any elements
    {  
      if(P-> Elem == Key)
	{ return position;}
      P=P->Next;
      position++;
    }
  return 0;                //returns 0 if key is not matched
}
//PURPOSE: if I greater than or equal to 1 and less than or equal to Count, then replace the element in the list using the found position
//otherwise throw OutOfRange
//ALGORITHM: the for loop moves the pointer to the found position node
void slist:: replace(el_t newNum, int I)
{
  if(I >= 1 && I <= Count)           //if I is greater than or equal to 1 and less than or equal to Count, then replace the element
    {
      Node *P;                       //node pointer p
      P = Front;
      for (int K = 1; K <= I-1; K++)  //moves the pointer p to the position(I) given
	{ P = P->Next; }
      P -> Elem = newNum;
    }
  else                              //otherwise throw OutOfRange
    {throw OutOfRange();}
}
