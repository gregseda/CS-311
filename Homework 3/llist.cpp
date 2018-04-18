//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Greg Seda
//Complier:  g++ compiler
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.

//PURSPOSE: Initializes contsructor, Front and Rear = NULL and Count = 0
llist::llist()  
{
  Front = NULL; 
  Rear = NULL;
  Count = 0;
}
//PURPOSE: Destructor destroys every node in the linked list and then displays "calling the llist destructor."
//ALGORITHM: The loop continuously deletes the front of the list until the list is empty
llist::~llist()
{
  while(!isEmpty())
    {
      deleteFront(Front -> Elem);
    }
  cout << "calling the llist destructor" << endl;
}
//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."

//Purpose: checks Front, Rear and Count and returns true if empty, false therwise.
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0)
    { return true;}
  else{
    return false;}
}

//  - return true if Front and Rear are both pointing to NULL and Count is 0.
//  - (all 3 conditions must be checked)

//PURPOSE: calls isEmpty and if true, displays [ empty ].
//         Otherwise, displays the elements vertically.
//ALGORITHM: The loop continuously displays each node from the Front to the Rear of the list.
void llist::displayAll()
{
  Node* p;                         //p is the node pointer 
  p = Front;                       // p is set to the front of the list
  
  if(isEmpty())                     // if list is empty, display [ empty ]
    { cout << "[ empty ]" << endl;}
  else
    {
    cout << "[ ";
    while(p != NULL)                //displays every element in the list
      {
	cout << p -> Elem << " ";
	p = p -> Next;
      }
    cout << "]" << endl;
    }
}
//  - Special case: if the list is empty, display [ empty ] ).
//  - Regular: 
//    displays each element of the list horizontally starting from Front in [ ].

//PURPOSE: calls isEmpty and if true, makes the new node the Front and the Rear
//         otherwise, adds the new node to the Rear of the list
void llist::addRear(el_t NewNum) 
{
  Node* p;         //node pointer p
  p = new Node;    // p is set to the new node
  if(isEmpty())   //if the list is empty, then make the new node the Front and the Rear
     {
       Front = p;
       Rear = p;
       Front -> Elem = NewNum;
       Rear -> Elem = NewNum;
       Count++;
     }
  else             //otherwise make p the new Rear to the list
     {
       Rear -> Next = p;
       Rear = Rear -> Next;
       Rear->Elem = NewNum;
       Rear->Next = NULL;
       Count++;
  }
}
 
/*2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
*/

//PURPOSE: calls isEmpty and if true, makes the new node the Front and Rear.
//         otherwise it makes the new node the Front of the list.
void llist::addFront(el_t NewNum)
{
  if(isEmpty())
    {
      Node* p;                //node pointer p
      p = new Node;           // pointer p is the new node
      Front = p;
      Rear = p;
      Front -> Elem = NewNum;
      Rear -> Elem = NewNum;
      Count++;
    }
  else
    {
      Node* x;               //node pointer x
      x = new Node;          // x is set to the new node
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++;
    }
}
/*
2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;
  */

//PURPOSE: calls isEmpty, if true, then throw Underflow
//         or if count = 1, then delete the Front and set the Front and Rear to NULL
//         otherwise delete the front node of the list. 
void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty())               //if the list is empty, then throw Underflow
    { throw Underflow();}
  else if(Count == 1)        //if the count = 1, then delete the front and set Rear and Front to NULL
    {
      Front -> Elem = OldNum;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else                        //otherwise delete the front node of the list
    {
      OldNum = Front->Elem;
      Node *Second;           //node pointer Second
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
}
/*3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
*/

//PURPOSE: calls isEmpty, if true throw Underflow
//         or if count = 1, then delete the Rear and set Front and Rear to NULL
//         otherwise delete the rear of the list.
//ALGORITHM:
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())                //if the list is empty, then throw Underflow
    { throw Underflow();}
  else if(Count == 1)          //if count = 1, then delete the Rear and Front and Rear are set to NULL
    {
      OldNum = Rear -> Elem;
      delete Rear;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else                         //otherwise delete the rear
    {
      OldNum = Rear->Elem;
      Node *p;                 //node pointer p
      Node *q;                 //node pointer q
      p = Front;               // p is set to Front
      while(p -> Next != NULL) //moves the two pointers to the end of the list
	{
	  q = p;
	  p = p -> Next;
	}
      delete Rear;
      q -> Next = NULL;
      Rear = q;                //make q the Rear
      Count--;
    }
}
/* 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
*/

//PURPOSE: if I is greater than count or less than 1, then throw OutOfRange.
//         if I = 1, then call deleteFront function
//         if I = Count, then call deleteRear function
//         otherwise delete the Ith node
//ALGORITHM: the for loop move the 2 nodes to the Ith node
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1)         //if I is greater than Count or I is less than 1, then throw OutOfRange
    { throw OutOfRange();}
  else if(I == 1)               //if I = 1, then call the deleteFront function
    { deleteFront(OldNum);}  
  else if(I == Count)           //if I = Count, then call the deleteRear function
    { deleteRear(OldNum);}
  else                          //otherwise delete the Ith function
    {
      Node* p;                    //node pointer p
      Node* q;                    //node pointer q
      p = Front;                  //p is set to front
      for (int K = 1; K <= I-1; K++)  //moves p to the Ith node and q to the node before I
	{ q = p;
	  p = p -> Next; }
      q -> Next = p -> Next;  
      delete p;
      Count--;
    }
}
  /*
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
  */


//PURPOSE: if I is greater than Count + 1 or I is less than 1, then throw OutOfRange
//         if I = 1, then call the addFront function
//         if I = Count + 1, then call the addRear function
//         otherwise add the new node before I 
//ALGORITHM:  The loop moves the pointer p to I and q to I - 1
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > Count + 1 || I < 1)              //if I is greater than Count + 1 or I is less than 1, then throw OutOfRange
    { throw OutOfRange();}
  else if(I == 1)                       //if I = 1, then call the addFront function
    { addFront(newNum);}
  else if(I == Count + 1)              //if I = Count + 1, then call the addRear function
    { addRear(newNum);}
  else                                //otherwise add the new node before I
    { 
      Node* p;                       //node pointer p
      Node* q;                      //node pointer q
      p = Front;                     // p is set to Front
      for(int K = 1; K <= I-1; K++)  //moves the p pointer to I and q pointer to I -1
        { q = p;
	  p = p->Next; }
      q -> Next = new Node;          
      q -> Next -> Next = p;
      q = q -> Next;
      q -> Elem = newNum;
      Count++;
    }
}
/*4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
*/
