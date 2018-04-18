//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Greg Seda
// Compiler:  g++ 
// File type: header file 
//=======================================================


//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Checks to see if the linked list is empty
  bool isEmpty();
    
  //PURPOSE: Displays all elements in in the linked list.
  //If the linked list is empty, display [ empty ]
  void displayAll();

  //PURPOSE: Adds a new node to the front of the list
  //PARAMETER: pass the element to add to the front
  void addFront(el_t);
    
  //PURPOSE: Adds a new node to the rear of the list
  //PARAMETER: pass the element to add to the rear
  void addRear(el_t);

  //PURPOSE: Deletes the front node of the list
  //PARAMETER: provide variable to be deleted from the front (pass by ref)
  void deleteFront(el_t&);
    
  //PURPOSE: Deletes the rear node of the list
  //PARAMETER: provide variable to be deleted from the rear (pass by ref)
  void deleteRear(el_t&);
    
  //PURPOSE: Delete the node based on the destination element given
  //PARAMETER: pass the destination element and provide the variable to be deleted (pass by ref)
  void deleteIth(int, el_t&);

  //PURPOSE: Add the node based on the destination element given
  //PARAMETER: pass the destination element and prvide the variable to be added
  void addbeforeIth(int, el_t);
    
};
