/********************************************************************
HW#: hw3ec.cpp
Your name: Greg Seda
Compiler: g++ compiler
File type: extra credit client program
*************************************************************/

using namespace std;
#include <iostream>
#include "slist.h"


//PURPOSE of the Program: To test the routine that overloads the == operator
//Algorithm/Design: Load two lists with different elements to create cases for testing
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;
  
  //1. 
  cout << counter << endl; counter++;
  cout << "L1 is empty and L2 is empty" << endl;
  L1.displayAll();
  L2.displayAll();
  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;

  //2.
  cout << counter << endl; counter++;
  L2.addRear(1);
  L2.addRear(2);

  cout << "L1 is empty and L2 has 2 elements" << endl;
  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;
  
 //3.
  cout << counter << endl; counter++;
  L2.deleteRear(temp);
  L2.deleteRear(temp);
  L1.addRear(1);
  L1.addRear(2);

  cout << "L1 has 2 elements and L2 is empty" << endl;

  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;

  //4.
  cout << counter << endl; counter++;
  L1.addRear(3);
  L2.addRear(1);
  L2.addRear(2);
  L2.addRear(3);

  cout << "L1 has 1,2,3 and L2 has 1,2,3" << endl;
  
  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;

  //5.
  cout << counter << endl; counter++;
  L2.deleteRear(temp);

  cout << "L1 has 1,2,3 and L2 has 1,2" << endl;
 
  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;

  //6.
  cout << counter << endl; counter++;
  L2.addRear(3);
  L2.addRear(4);

  cout << "L1 has 1,2,3 and L2 has 1,2,3,4" << endl;
 
  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;

  //7.
  cout << counter << endl; counter++;
  L2.deleteRear(temp);
  L2.deleteRear(temp);
  L2.addRear(4);

  cout << "L1 has 1,2,3 and L2 has 1,2,3,4" << endl;
 
  L1.displayAll();
  L2.displayAll();

  if(L1 == L2)
    {cout << "true" << endl << endl;}
  else
    cout << "false" << endl << endl;


  return 0;
}
