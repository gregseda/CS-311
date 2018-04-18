// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.

// =========================================================
//HW#: HW6 graph
//Your name: Greg Seda
//Complier:  g++ compiler
//File type: Directed Graph client program
//================================================================
  
  using namespace std;

#include <iostream>
#include "dgraph.h"


//Purpose of the Program: To test the header and implementation files with graphs 
//Algorithm/Design:  The program will fill and display a graph, then it will ask the user to enter a vertex to find the out degrees and adjacent ones to a inputted vertex.
int main()
{
  // 0.Declare table object
  dgraph g1;      //graph object
  
  int input = 1;  //user input used to exit the while loops
  char vertex;    //user input of vertex
  int degree = 0;  //used to hold the out degreee returned from the findOutDegree function
  slist L1;       //slist object used to hold the adjacent ones returned from the findAdjacency function


  //1.fillTable()
  g1.fillTable();
  
  //2.displayGraph()
  g1.displayGraph();

  //3.findOutDegree()
  while(input != 0)       //continuously executes the code until the user input is 0
    {
      try
	{
	  cout << "Please enter a vertex to find the out degree:  ";
	  cin >> vertex;
	  cout << endl;
	  
	  degree = g1.findOutDegree(vertex);
	  cout << "Out Degree: " << degree << endl << endl;
	  
	  cout << "Please enter 0 if you want to exit find the out degree(any number other than 0 will continue the program):  ";
	  cin >> input;
	  cout << endl;
	}

      catch (dgraph::BadVertex)
	{cerr << "Vertex is not valid." << endl << endl;}
    }

  input = 1;
  
  //4.findAdjacency()
  while(input != 0)       //continuously executes the code until the user input is 0
    {
      try
	{
	  cout << "Please enter a vertex to find the adjacent ones:  ";
          cin >> vertex;
          cout << endl;

          L1 = g1.findAdjacency(vertex);
          cout << "Adjacent Ones: " << vertex << endl << endl;
	  L1.displayAll();
	  
          cout << "Please enter 0 if you want to exit find the adjacent ones(any number other than 0 will continue the program):  ";
          cin >> input;
          cout << endl;

	}
      catch (dgraph::BadVertex)
        {cerr << "Vertex is not valid." << endl << endl;}
    }
}
