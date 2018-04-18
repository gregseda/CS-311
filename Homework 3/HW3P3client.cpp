//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Greg Seda
//Complier:  g++ compiler
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to a the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
  copiedList.addRear(6);   cout << "added " << 6 << " to rear" << endl;
  copiedList.displayAll();
  cout << "finished" << endl;
}


//PURPOSE of the Program: To test the different functions in the slist and llist implementation files
//Algorithm/Design: load two different lists with different elements to create different cases for testing
int main()
{
  slist L1, L2;    //creates two lists from slist
  int temp;        
  int counter = 1;

 //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << counter << endl; counter++;
  L1.addRear(1);  cout << "added " << 1 << " to rear" << endl;
  L1.addRear(2);  cout << "added " << 2 << " to rear" << endl;
  L1.addRear(3);  cout << "added " << 3 << " to rear" << endl;
  L1.addRear(4);  cout << "added " << 4 << " to rear" << endl;
  L1.addRear(5);  cout << "added " << 5 << " to rear" << endl;
  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << counter << endl; counter++;
  CopyTest(L1);  
  cout << "-- After copytest --- " << endl;
  //3.Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << "-- Testing operator overloading ---" << endl;

  //4.Do L1 = L1;
  cout << counter << endl; counter++;
  L1 = L1;   cout << "tested L1 = L1" << endl;
  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << counter << endl; counter++;
  L1.displayAll();
  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << counter << endl; counter++;
  L2.addRear(7);  cout << "added " << 7 << " to rear" << endl;
  L2.addRear(8);  cout << "added " << 8 << " to rear" << endl;
  L2.addRear(9);  cout << "added " << 9 << " to rear" << endl;
  L2.addRear(10); cout << "added " << 10 << " to rear" << endl;
  //7.Display L2
  cout << counter << endl; counter++;
  L2.displayAll();
  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << counter << endl; counter++;
  L2 = L1;   cout << "tested L2 = L1" << endl;
  //9.Display L2.
  cout << counter << endl; counter++;
  L2.displayAll();
  //10.Remove a rear node from L1. (This should not affect L2).
  cout << counter << endl; counter++;
  L1.deleteRear(temp);   cout << "deleted rear" << endl;
  //11.Display L1.   (L1 is 1,2,3,4)
  cout << counter << endl; counter++;
  L1.displayAll();
  //12.Display L1 again. (4 elements . just to make sure)
  cout << counter << endl; counter++;
  L1.displayAll();
  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << counter << endl; counter++;
  L2.displayAll();

 }//end of program

