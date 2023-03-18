/******************************
Project 3 Random Binary Search Tree
driver.cpp
John Kallis <jkallis1@umbc.edu>
CMSC 341 - 02
Lupoli
3/8/2015
******************************/
#include "BinarySearchTree.h"

/**********************
//Name: printGreeting
//Preconditions: None
//Postconditins: None
**********************/
void printGreeting ()
{
	cout<<endl;
	cout<<"Welcom to the Random Binary Search Tree."<<endl;
	cout<<"Written by John Kallis"<<endl;
	cout<<"project 3 CMSC 341 - 02 Lupoli"<<endl;
	cout<<"This program takes in a file containg"<<endl;
	cout<<"a sequence of numbers and orgainizes"<<endl;
	cout<<"the data into a RBST and outputs the"<<endl;
	cout<<"RBST to the screen."<<endl;
	cout<<endl;
}

int main ( int argc, char *argv[] )
{
	//prints the greeting
	printGreeting();

	//used for holding the value from the input file
	string holdNum;
	//initializing the normal and randomized trees
	BinarySearchTree tree;
	BinarySearchTree randomTree;
	int L;
	//if L is included in the command line 
	if ( argv[2] != NULL )
	{
		//we set in to int L
		string hold( argv[2] );
		L = atoi( hold.c_str( ) );
		cout << "L: "<< L << endl;
	}

	//open the file
	ifstream inFile( argv[1] );

	if ( inFile.is_open() )
	{
		//create the trees
		while ( getline( inFile, holdNum, ' ' ) )
		{
			int value = atoi( holdNum.c_str( ) );
			tree.insert( value );
			//cout<<endl;
			//cout<<"t : "<<endl;
			//t.printTree( );
			//cout<<endl;
			randomTree.randomInsert( value );
			//cout<<endl;
			//cout<<"rt : "<<endl;
			//rt.printTree( );

		}

		//find the heights of the trees
		int heightTree = tree.height();
		int heightRandTree = randomTree.height();


		//write the file results.txt
		ofstream results ("results.txt");

		if ( results.is_open() )
		{
			if (!L)
			{
				results << "Height of normal BST is " << heightTree << endl;
				results << "Height of randomized BST is " << heightRandTree << endl;
				results << endl;
				results << "Level order print of normal BST: " << endl;
				tree.printLevelOrder( heightTree, results);
				results << endl;
				results << "Level order print of randomized BST: " << endl;
				randomTree.printLevelOrder( heightRandTree, results);
				results << endl;
			}
			else
			{
				results << "L is " << heightTree << endl;
				results << "Height of randomized BST is " << heightRandTree << endl;
				results << endl;
				results << "Level order print of normal BST: " << endl;
				tree.printLevelOrder( L, results);
				results << endl;
				results << "Level order print of randomized BST: " << endl;
				randomTree.printLevelOrder( L, results);
				results << endl;
			}

		}
		else { cerr << "Error creating file."<<endl; }
		
	}
	else
	{
		cerr << "ERROR opening file."<<endl;
		exit(0);
	}
	return 0;
}