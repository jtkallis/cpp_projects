//----------------------------------------------
//Name: Calculate.h
// Project 2 CMSC 341-02 Lupoli
// John Kallis <jkallis1@umbc.edu>
// defines the calculate class
//----------------------------------------------

#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Calculate {

	
public:

	//----------------------------------------------
	//Name: Calculate ( constructor )
	//PreCondition: a readable file is passed in
	//Postconditions: the file name is stored
	//----------------------------------------------
	Calculate(string fileName);

	//----------------------------------------------
	//Name:~Calculate ( destructor )
	//PreCondition: a readable file is passed in
	//Postconditions: the data from the file is stored
	// into a vector and parsed then outputed to 
	// the designated file.
	//----------------------------------------------
	~Calculate();

	//----------------------------------------------
	//Name: readFile
	//PreCondition: a readable file was passed into
	//	the calculate constructor
	//Postconditions: the data from the file is parsed
	// and stored in a 2D vector. If the file is
	// able to be opened true is returned.
	// otherwise, false.
	//----------------------------------------------
	bool readFile();

	//----------------------------------------------
	//Name: push
	//PreCondition: the current point in the 2D vector
	//Postconditions: None
	//  pushes the current object in the vector onto
	//  its appropriate stack. then calls popAndProcess
	//----------------------------------------------
	void push(unsigned int row, unsigned int col);

	//----------------------------------------------
	//Name: popAndProcess
	//PreCondition: the current point in the 2D vector
	//Postconditions: None
	// pops and process the stacks and stores the 
	// solutions in a vector to be used when
	// the end of the all_expressions vector is reached
	// and writeResults is called
	//----------------------------------------------
	void popAndProcess(unsigned int row, unsigned int col);

	//----------------------------------------------
	//Name: writeResults
	//PreCondition: None
	//Postconditions: None
	// loops throught the solutions vectors and outputs
	// the contents to a text file 'results.txt'
	//----------------------------------------------
	void writeResults();

	//----------------------------------------------
	//Name: resetStacks
	//PreCondition: None
	//Postconditions: None
	// empties out the stacks and resets to default
	//----------------------------------------------
	void resetStacks();


private:

	//rows for index
	unsigned int row;
	//columns for index
	unsigned int col;

	//holds the file name
	string m_filename;
	
	//used to keep index correct
	//when popAndProcess is called 
	bool lowFlag;
	
	//holds the file content
	vector<vector<string> > all_expressions;
	//holds the solutions
	vector<string> solutions;
	
	//stacks and maps
	stack<string> op;
	stack<int> priority;
	stack<string> value;
	map <string, int> stack_priority;
	map <string, int> input_priority;

};

#endif //CALCULATE_H