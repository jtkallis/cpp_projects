#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class LCS
{
public:
	//----------------------------------------------
	//Name: LCS (defualt constructor)
	//PreCondition: None
	//Postconditions: None
	//----------------------------------------------	
	LCS();

	//----------------------------------------------
	//Name: LCS (defualt constructor)
	//PreCondition: None
	//Postconditions: None
	//----------------------------------------------
	int findLCS( string X,  string Y, int m, int n);


};
#endif //LCS_H