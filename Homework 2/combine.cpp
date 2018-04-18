//=============================================================
//HW#: HW2P2
//Name: Greg Seda
//Compiler Used: g++ compiler
//File Type: combine implementation file
//==============================================================
#include <vector>
#include <iostream>

using namespace std;


//PURPOSE:  combines the two vectors into one vector based on numerical order. 
//PARAMETER: pass the two vectors (L1 and L2) to compare and push into another vecotor (L3) based on the amount the user wants to compare (input)
int combine(vector <int> L1, vector <int> L2, vector <int>& L3, int input)
{
  int a = 0;    //number from vector L1
  int b = 0;    //number from vector L2
  int r = 0;   //number used to push into vector L3
  
  for(int i = 0; i < input; i++)           //compares and pushes each element into vector 3
    {
      if(L1[a] > L2[b])                  //if the number fomr L1 is larger than L2, then push the number from L2 into L3
	{
	  r = L2[b];
	  L3.push_back(r);
	  b++;
	  cout << "comparison" << endl;
 	}
      else
	{
	  r = L1[a];
	  L3.push_back(r);
	  a++;
	  cout << "comparison" << endl;
	}
      
    }
  if(a != L1.size() && b != L2.size())        //if a and b do not equal the sizes of the vectors, then excute the following code
    {
      if(L1[a] > L2[b])                       //if the number fomr L1 is larger than L2, then push the number from L2 into L3
        {
          r = L2[b];
          L3.push_back(r);
          b++;
          cout << "comparison" << endl;
        }
      else
        {
          r = L1[a];
          L3.push_back(r);
          a++;
          cout << "comparison" << endl;
        }
    }
  if(a != L1.size())
    {
      for(int i = a; i < L1.size(); i++)      //pushes number from vector L1 into vector L3
	{
	  r = L1[i];
	  L3.push_back(r);
	}
    }
  if(b != L2.size())
    {
      for(int i = b; i < L2.size(); i++)     //pushes number from vector L2 into vector L3
	{
	      r = L2[i];
	      L3.push_back(r);
	}
    }
}

int main()
{
  vector <int> L1;   //first list of user entered numbers vector
  vector <int> L2;   //second list of user entered numbers vector
  vector <int> L3;   //numbers in L1 and L2 combined
  
  int input;         //comparison input by the user
  int number;        //numbers entered by user to be compared

  cout << "How many numbers would you like to compare?" << endl;
  cin >> input;
  cout << endl;

  cout << "=== List 1 ===" << endl;
  for(int i = 0; i < input; i++)     //pushes the numbers entered by the user into list 1 (L1)
    {
      cout << "Please enter the numbers in increasing order." << endl;
      cin >> number;
      L1.push_back(number);
    }

  cout << "=== List 2 ===" << endl;
  for(int i = 0; i < input; i++)    //pushed the numbers entered by the user into list 2 (L2)
    {
      cout << "Please enter the numbers in increasing order." << endl;
      cin >> number;
      L2.push_back(number);
    }

  combine(L1,L2,L3,input);

  cout << "Numbers in order: " << endl;
  for(int i = 0; i < L3.size(); i++)   //displays the numbers in vector L3 in numerical order
    { cout << L3[i];}
  cout << endl;
  
  return 0;
}
