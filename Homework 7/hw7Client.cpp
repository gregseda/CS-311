/*****************************************************
HW#: HW7 graph traverse
Name: Greg Seda
Compiler: g++ compiler
File Type: Directed Graph traverse client program
***************************************************/

#include "dgraph.h"


//Purpose of the Program: to test the header and implementation files for graph traversal
//Algorithm/Design:  The program will fill a graph, display it and then traverse through the graph. It will output the order the traversal will go by number.
int main()
{
  slist adjacent;     //adjacent ones
  dgraph graph;      //graph object
  int count = 1;     //counter
  char temp;        //temporary character for the verticies
  stack stk;        //stack object

  graph.fillTable();
  graph.displayGraph();

  graph.visit(count, 'A');
  count++;
  adjacent = graph.findAdjacency('A');

  while(!adjacent.isEmpty())      //continuously executes the code until the adjacent object is empty
    {
      adjacent.deleteRear(temp);
      stk.push(temp);
    }

  cout << "|Initial|-->: " << 'A' << endl;
  stk.displayAll();
  cout << endl;

  while(!stk.isEmpty())        //continuously executes the code until the stack object is empty
    {
      stk.pop(temp);
      if(!graph.isMarked(temp))     //if the vertex has not been marked already execute the following code
	{
	  graph.visit(count,temp);
	  count++;
	  cout << "Visited: " << temp << endl;
	  adjacent = graph.findAdjacency(temp);
	  
	  while(!adjacent.isEmpty())        //continuously loops until the adjacent object is empty
	    {
	      adjacent.deleteRear(temp);
	      stk.push(temp);
	    }
	  cout << "|Updated Stack|" << endl;
	  stk.displayAll();
	}
    }
  graph.displayGraph();
  return 0;
}
