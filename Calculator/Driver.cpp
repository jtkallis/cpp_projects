#include <iostream>
#include "Calculate.h"
#include <string>

using namespace std;


/*******************************
//Name: printGreeting
//PreConditions: None
//PostConditions: None
//prints the greeting to the screen
********************************/
void printGreeting ()
{
	cout<<endl;
	cout << "Welcome to the calculator." << endl;
	cout<<endl;
	cout << "writen by John Kallis <jkallis1@umbc.edu>" << endl;
	cout << "for project 2, CMSC 341-02, Lupoli" << endl;
	cout<<endl;
	cout << "This program will take in a file of arithmatic" << endl;
	cout << "and solve the solution and output a new file" << endl;
	cout << "of the solutions. " << endl;
	cout<<endl;
}
//takes a command line argument to be used
//in creating an instance of the Caluate class
//and perform tasks on said class
int main (  int argc, char *argv[] )
{
	//calls the greeting and prints it to the screen
	printGreeting ();

	//converts the command line argument from char* to string
	//to be passed into readFile 
	string inFile(argv[1]);

	//creates an instance of Calculate
	Calculate calculator(inFile);

	//if the file opens
	//readFile parses the data from the input
	//and returns true if the file exists
	if ( calculator.readFile() )
	{
		//push is called with the first position
		//in the 2D vector as the parameters
		//push will then iterate through the 2D vector
		//calling popAndProcess as needed until all of 
		//the information has been processed
		//then writeResults is called to output
		//the results and the program is ended
		calculator.push(0,0);
	}

	//if the file doesn't open
	else
	{ 
		cerr << "readFile returned false. ERROR." << endl;
	}

	return 0;
}

