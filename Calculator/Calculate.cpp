//----------------------------------------------
//Name: Calculate.cpp
// Project 2 CMSC 341-02 Lupoli
// John Kallis <jkallis1@umbc.edu>
// implements the calculate class
//----------------------------------------------
#include "Calculate.h"


Calculate::Calculate(string fileName)
	:m_filename(fileName){}

Calculate::~Calculate(){}

bool Calculate::readFile()
{
	//stack priority map definition
	stack_priority["-"] = 1;
	stack_priority["+"] = 1;
	stack_priority["*"] = 2;
	stack_priority["/"] = 2;
	stack_priority["%"] = 2;
	stack_priority["^"] = 4;
	stack_priority["("] = 0;
	stack_priority["$"] = -1;

	//input priority map definition
	input_priority["-"] = 1;
	input_priority["+"] = 1;
	input_priority["*"] = 2;
	input_priority["/"] = 2;
	input_priority["%"] = 2;
	input_priority["^"] = 5;
	input_priority["("] = 6;

	//sets up the stacks
	value.push("$");
	op.push("$");
	priority.push(-1);


	//to be used in outter getline()
	// as second argument
	string holdLine;

	//converts string to c string for
	// outter getline() first argument
	const char* FileName = m_filename.c_str();

	//creates a file stream for input
	ifstream inputFile(FileName);

	//here we parse the file into a 2D vector
	if ( inputFile.is_open() )
	{
		//used to check for an operator
		string operatorTypes = "+-*/^%";
		//used to check for ()
		string brackets = ")(";
		//seperates the file content by line
		while ( getline( inputFile, holdLine, '\n') )
		{
			//holds a line from the file split on spaces
			vector<string> tempExpr;
			//to be used in the getline below 2nd argument
			string holdValue;
			//various counters for error checking
			int countOp = 0;
			int countOpen = 0;
			int countClose = 0;
			int countVal = 0;
			//converts holdLine to ss for inner getline() 1st argument
			stringstream holdExpression(holdLine);

			//splits each line by spaces and places them in tempExpr
			while ( getline(holdExpression, holdValue, ' ') )
			{ 
				//if holdValue is an operator 
				if ( operatorTypes.find( holdValue ) != string::npos )
				{ 
					countOp++;
				}

				//if holdValue is a (
				else if ( holdValue == "(")
				{
					countOpen++;
				}
				//if holdValue is )
				else if ( holdValue == ")")
				{
					countClose++;
				}
				//else holdValue is a number
				else
				{ 
					countVal++;
				}

				//add it to the temp vector
				tempExpr.push_back(holdValue);

			}//closes while (split on spaces)

			//checks for the right amount of paranthses
			if ( countOpen != countClose )
			{
				vector<string> tempExpr;
				tempExpr.push_back( "invalid" );
				all_expressions.push_back( tempExpr );
			}
			//checks for the right amount of opperators
			else if ( countVal != ( countOp + 1 ) )
			{
				vector<string> tempExpr;
				tempExpr.push_back( "invalid" );
				all_expressions.push_back( tempExpr );
			}
			//if both above are false then
			// everything checks out
			else
			{
				all_expressions.push_back(tempExpr);
			}
			//adds tempExpr to all_expressions vector
			

		}//closes while split on line

		//after file is parsed true is returned
		return true;

	}
	//if the file cannot be opened 
	//return false
	else
	{ return false; }

}

void Calculate::push(unsigned int row, unsigned int col)
{
	//to check for an operator
	string operatorTypes = "+-$*/^(%)";
	//to check for brackets
	string brackets = ")(";

	//if there was an error with the input
	if ( all_expressions[row][col] == "invalid" )
	{
		//if we arent at the last one. 
		if ( ( row + 1 ) <= ( all_expressions.size() - 1 ) )
		{ 
			solutions.push_back("invalid");
			push( (row + 1), 0 );
		}
		else
		{
			writeResults();
		}

	}
	//if its an operator
	if ( operatorTypes.find( all_expressions[row][col] ) != string::npos )
	{
		//if its a )
		if ( all_expressions[row][col] == ")")
		{	
			//push it and the popAndProcess
			op.push( all_expressions[row][col] );
			popAndProcess(row,col);

		}

		//else if the priority value is greater then the top of the priority stack
		//add it to the stack along with its value
		else if ( ( input_priority[ all_expressions[row][col] ] ) > ( priority.top() ) )
		{
			//push to op and pri stacks
			op.push( all_expressions[row][col] );
			priority.push( stack_priority[ all_expressions[row][col] ] );

			//if we arent at the end of the row go to the next column
			if ( (col+1) <= ( all_expressions[row].size() - 1 ) )
			{ 	
				push( row, ( col + 1 ) );
			}
			//if we are at the end theres an error because the current element is an operator
			//go to next row if there otherwise write results
			else 
			{
				solutions.push_back("invalid");
				resetStacks();
				if ( ( row + 1 ) <= ( all_expressions.size() - 1 ) )
				{ 
					push( ( row + 1 ), 0 );
				}
				else
				{ 
					writeResults();
					exit(0);
				}

			}
			
		}
		//if the priority value is less then the top of the stack
		//popAndProcess()
		else
		{
			//change the flag to know to stay at the same point
			//in the vector when we come back to push
			lowFlag = true;
			popAndProcess(row,col);
		}
		
	}
	//else its a number
	else
	{
		//push to value stack
		value.push(all_expressions[row][col]);
		//if we arent at the end of the line
		if ( ( col + 1 ) <= ( all_expressions[row].size() - 1 ) )
		{
			push(row, ( col + 1 ) );
		}
		//if we are at the end
		else 
		{
			popAndProcess(row,col);
		}
	}

}//ends push(i,j)

void Calculate::popAndProcess(unsigned int row, unsigned int col)
{	
	//holds the top of the operator stack
	string holdOperator;
	//for checking for an operator
	string operatorTypes = "+-*/^%" ;


	//  if )
	if ( op.top() == ")" )
	{
		//its popped and we start again
		// ( no priority value )
		op.pop();
		popAndProcess(row,col);
	}
	// if  (
	else if ( op.top() == "(")
	{
		op.pop();
		priority.pop();
		popAndProcess(row,col);
	}
	//else we take the operator from the top
	// if - + / * % ^ 
	else if ( operatorTypes.find( op.top() ) != string::npos )
	{
		//assign variable to top of the stack
		holdOperator = op.top();
		//pop that operator, we dont need it there anymore
		op.pop();
		priority.pop();

		//assign and convert the top two
		//values from value stack to floats
		//then pop the value	
		istringstream holderB( value.top() );
		float valueB;
		holderB >> valueB;
		value.pop();

		istringstream holderA( value.top() );
		float valueA;
		holderA >> valueA;
		value.pop();

		//evaluate
		float answer = 0;
		if ( holdOperator == "+") 	 { answer = ( valueA + valueB ); }
		else if ( holdOperator == "-") { answer = ( valueA - valueB ); }
		else if ( holdOperator == "*") { answer = ( valueA * valueB ); }
		else if ( holdOperator == "/") { answer = ( valueA / valueB ); }
		else if ( holdOperator == "^") { answer = pow( valueA, valueB); }
		else if ( holdOperator == "%") { answer = fmod( valueA, valueB); }

		//change the solution back to a string to push
		ostringstream hold;
		hold << answer;
		string solution(hold.str());
		value.push(solution);
	}

	/////////////////////////////////
//from here we have a solution at the top of the value stack
	////////////////////////////////

	//if we arent at the end of the line
	//**********************************
	if ( ( col + 1 ) <= ( all_expressions[row].size() - 1 ) )
	{	
		//if theres nothing left to solve
		if( op.top() == "$" )
		{
			//if we changed the flag earlier
			if ( lowFlag == true )
			{
				//change it back
				lowFlag = false;
				//go back to the same spot
				push( row, col);
			}
			//if we didnt change the flag
			else
			{
				//go to the next spot
				push( row, ( col + 1 ) );
			}
		}
		//if there is another operator in the stack
		//start popAndProcess from the top to get rid of it
		else
		{
			popAndProcess(row,col);
		}
	}

	//if we are at the end of the line
	//check if there are any more lines
	else if ( ( row + 1 ) <= ( all_expressions.size() - 1 ) )
	{
		//if the operator stack is empty
		//save the result and go to the next row
		if( op.top() == "$" )
		{
			solutions.push_back( value.top() );
			value.pop();
			resetStacks();
			push( ( row + 1 ), 0);
		}
		//if there is anything left in the operator stack
		//start popAndProcess over again
		else
		{
			popAndProcess(row,col);
		}
	}
	//if there are no more lines
	else 
	{
		//if there are no more operators left
		//writeResults
		if( op.top() == "$" )
		{
		solutions.push_back( value.top() );
		value.pop();
		writeResults();
		value.empty();
		op.empty();
		priority.empty();
		exit(0);
		}
		//if theres more in the operator stack
		else
		{ 
			popAndProcess( row, col);
		}
	}

} // end popAndProcess(row,col)

void Calculate::writeResults()
{
	//creates the file to write too
	ofstream results ("results.txt");

	if ( results.is_open() )
	{
		for (unsigned int k = 0; k < solutions.size(); k++)
		{
			//writes each solution to the file on a new line
			results << solutions[k] << endl;
		}
	}
}//end writeResults()

void Calculate::resetStacks()
{
	//empty stacks
	value.empty();
	op.empty();
	priority.empty();
	//reset defaults
	value.push("$");
	op.push("$");
	priority.push(-1);
}