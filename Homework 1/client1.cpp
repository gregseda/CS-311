//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Greg Seda
//Complier:  g++ compiler
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "vstack.h"

//Purpose of the program: This is a stack program that calculates post-fix expressions
//Algorithm: The user enters a post-fix expression. The program will attempt to calculate the the expression. If there are errors in the expression, the program will indicate it. The program will display the final result.   
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;

  int result;
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  int num = int(item) - 48; // converts the character to a numerical value
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  // ** 
	  if(num >= 0 && num <= 9)
	    {postfixstack.push(num);}
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      if(item == '+') result = box2 + box1;
	      if(item == '*') result = box2 * box1;
	      
	      postfixstack.push(result);
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "Error has occured: Expression too long" << endl;
	  exit(1);}
      catch (stack::Underflow) // for too few operands
	{cerr << "Error has occured: Too few operands" << endl;
	  exit(1);}
      catch (char const* errorcode) // for invalid item
	{ cerr << "Error has occured: Invalid element" << endl;
	  exit(1);} 
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
 
  postfixstack.pop(result);
  cout << "Result: " << result << endl;

  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  
  if(!postfixstack.isEmpty())
    {cout << "Incomplete expression" << endl;}
     
}// end of the program
