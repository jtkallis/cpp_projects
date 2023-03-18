//----------------------------------------------
//Name: Driver.cpp
// Project 4 CMSC 341-02 Lupoli
// John Kallis <jkallis1@umbc.edu>
//----------------------------------------------

#include "IntervalHeap.h"

using namespace std;

//prints username and section and greeting
void greeting()
{
	cout<<endl;
	cout<<"Welcome to the Interval Heap Game."<<endl;
	cout<<"Written by John Kallis"<<endl;
	cout<<"project 4 CMSC 341 - 02 Lupoli"<<endl;
	cout<<"This program  will create game with 'players' represented"<<endl;
	cout<<"by random numbers. The game will remove the min and max"<<endl;
	cout<<"values (players) until only one value is left. That player"<<endl;
	cout<<"will be the winner and the program will write the steps"<<endl;
	cout<<"to results.txt file"<<endl;
	cout<<endl;
}
int main(int argc, char * argv[])
{
	greeting();
	//recast command line arguments
	//into ints
	string holdMin( argv[1] );
	int min = atoi( holdMin.c_str( ) );

	string holdMax( argv[2] );
	int max = atoi( holdMax.c_str( ) );

	string holdSize( argv[3] );
	int size = atoi( holdSize.c_str( ) );

	string holdSeed( argv[4] );
	int seed = atoi( holdSeed.c_str( ) );
	

	IntervalHeap interval_Heap(min, max, size, seed);
	//creates the interval heap from random numbers
	interval_Heap.insertRandomNumbers();
	// deletes elements while writing to results.txt
	// until one element is left
	// then the program ends 
	interval_Heap.deleteMinMaxIteratively();

	return 0;
}
