/***************************************************
HW#: HW6 graph
Name: Greg Seda
Compiler: g++ compiler
File Type: Directed Graph implementation file
************************************************/
#include "dgraph.h"
#include <iostream>
#include <fstream>

using namespace std;


//PURPOSE: Constructor that initialize the variables that will be used in the program
dgraph::dgraph()
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}
//PURPOSE: Destructor that will have nothing done inside it
dgraph::~dgraph()
{
}
//PURPOSE: reads the input file (text.txt) and fills the table accordingly
//ALGORITHM: the while loop will read the inputs from the txt file and continously insert the outDegree and adjacentOnes to the graph, while incrementing the counter
void dgraph::fillTable()
{
  ifstream fin;       //used to read the inputs from the txt file
  el_t X;             //object used for the addRear function
  fin.open("table.txt");

  while(fin >> Gtable[countUsed].vertexName)       //continously inputs from the txt file until there is no more to read from the file
    {
      fin >> Gtable[countUsed].outDegree;

      for(int i = 0;i < Gtable[countUsed].outDegree;i++)    //reads the txt file and inserts the adjacentOnes and adds then calls the addRear function
        {
	  {
	    fin >> X;
	    (Gtable[countUsed].adjacentOnes).addRear(X);
	  }
	  countUsed++;
	}
      fin.close();
    }
  //PURPOSE: displays every used slot in the table
  //ALGORITHM: the for loop continuously displays each vertex, out degree, and adjacent ones until the counter is reached
  void dgraph::displayGraph()
  {
    for(int i = 0; i < countUsed; i++)   //displays each variable until the integer i matches countUsed
      {
	cout << "Vertex: " << Gtable[i].vertexName << endl;
	cout << "Out Degree: " << Gtable[i].outDegree << endl;

	cout << "Adjacent: ";
	(Gtable[i].adjacentOnes).displayAll();
	cout << endl;
      }
  }
  //PURPOSE: finds the out degree of the specific vertex given, if given a vertex that doesn't exist, then it throws it to BadVertex
  //PARAMETERS: char vertex is the given vertex by the user
  //ALGORITHM: the for loop loops until the vertex if found or the integer i matches countUsed
  int dgraph::findOutDegree(char vertex)
  {
    for(int i = 0; i < countUsed; i++)        //loops until the given vertex is found or i matches countUsed
      {
	if(Gtable[i].vertexName == vertex)   //if a vertex name matches the given vertex, the return the out out degree
	  {
	    return (Gtable[i].outDegree);
	  }
      }
    throw BadVertex();
  }
  //PURPOSE: finds the adjacency list based on the given vertex, if given a vertex that doesn't exist, then it throws to BadVertex
  //PARAMETERS: char vertex is the given vertex by the user
  //ALGORITHM: the for loop loops until the vertex is matched or the integer i matches countUsed
  slist dgraph::findAdjacency(char vertex)
  {
    for(int i = 0; i < countUsed; i++)      //loops until the vertex is matched or the integer i matches countUsed
      {
	if(Gtable[i].vertexName == vertex)   //if a vertex name matches the given vertex by the user, then return the adjacentOnes
	  {
	    return (Gtable[i].adjacentOnes);
	  }
      }
    throw BadVertex();
  }

