//======================================================
//HW#: HW2P1 Binary Search
//Name:  Greg Seda
//Compiler:  g++ compiler
//File Type: Binary search implementation file
//======================================================

#include <iostream>
using namespace std;  

//Purpose: searchs the array to see if the user inputted number is in the array
//if the searched number is even, then return -1
//if the searched number is not between 1 and 19, then return -1
//Parameter: pass the array, the inputted number, the first number of the array and the last number of the array.
int binarySearch(int list[], int search, int myFirst, int myLast)
{
  if(search%2 == 0)
    return -1;
  else if(search > 19 || search < 1)
    return -1;
  else
    {
      int middle = (myFirst + myLast)/2;                        //finds the middle postion of the array
      if(search == list[middle]) return middle;                 //if the user input is in the middle of the array, then return the middle position
      else if(search < list[middle]) myLast = middle - 1;       //go to first half
      else if(search > list[middle]) myFirst = middle + 1;      //go to last half
      return binarySearch(list, search, myFirst, myLast);       //returns what position the element is in
    }
}

//Purpose of the program: This is a program that has the user input a number and will search for that number in an array.
//Algorithm: The user enters a number. The program will attempt to search for the number in the array. If it is not found, the program will indicate it. The program will display if it was ound in the array and what position it was in.
int main()
{
  int result;                  //result of the binarySearch function
  int list[10];               //an array with 10 slots
  int myFirst = 0;            //the first position of the array
  int myLast = 9;             //the last position of the array
  int search;                //the user input
  int elements = 1;           //the element loaded into the array
  
  //loads the array with odd numbers
  for(int i = 0; i <= 9; i++)
    {
      list[i] = elements;
      elements = elements + 2;
    }
  
  cout << "Please enter the number you are looking for." << endl;
  cin >> search;
  result = binarySearch(list, search, myFirst, myLast);
  
  //If the use input is not found, then display Search Failed and end the program.
  if(result == -1)
    {
      cout << "Search Failed." << endl;
      return 0;
    }
  //Otherwise the number was found and the program will display the position of the number found.
  else
    {
      cout << "The number was found in position " << result + 1 << endl;
      return 0;
    }


return 0;
}
