//----------------------------------------------
//Name: IntervalHeap.h
// Project 4 CMSC 341-02 Lupoli
// John Kallis <jkallis1@umbc.edu>
// defines the IntervalHeap class and LeftRightElementClass
//----------------------------------------------
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

//class to be used in the heap array

class LeftRightElements
{
public:
	int left; //for min heap mostly
	int right; //for max heap
};

class IntervalHeap
{
private:
	int currentSize;/*total number of elements in the interval heap*/
	LeftRightElements *heap;/*array to maintain heap structure*/
	int inputSize;/*the one that is provided with make run command*/
	int newSize; //used to munipulate inputSize
	bool negative; //if the min is negative
	bool positive; //if min is positive
	int minRange;/*the one that is provided with make run command*/
	int storeMin;//store the real min for later
	int storeMax; //store the real max for later
	int maxRange;/*the one that is provided with make run command*/
	int seed;/*the one that is provided with make run command*/

public:

	//----------------------------------------------
	//Name: IntervalHeap ( constructor )
	//PreCondition: the min,max, size, and seed are
	//	passed in to creat the heap
	//Postconditions: none
	//----------------------------------------------
	IntervalHeap(int min, int max, int size, int seed);

	//----------------------------------------------
	//Name: IntervalHeap ( deconstructor )
	//PreCondition: None
	//Postconditions: deletes the IntervalHeap
	//----------------------------------------------
	~IntervalHeap();

	//----------------------------------------------
	//Name: getMin
	//PreCondition: none
	//Postconditions: returns the heap min
	//----------------------------------------------
	int getMin();

	//----------------------------------------------
	//Name: getMax
	//PreCondition: none
	//Postconditions: returns the heap max
	//----------------------------------------------
	int getMax();

	//----------------------------------------------
	//Name: getSize
	//PreCondition: none
	//Postconditions: returns the current Size of heap
	//----------------------------------------------
	int getSize();

	//----------------------------------------------
	//Name: insertRandomNumbers
	//PreCondition: none
	//Postconditions: generates random numbers based
	//	on the constructor and calls insert method to 
	//	insert random numbers into heap
	//----------------------------------------------
	void insertRandomNumbers();

	//----------------------------------------------
	//Name: insert
	//PreCondition: the element to be inserted
	//Postconditions: the element is inserted into heap
	//----------------------------------------------
	void insert(int element);

	//----------------------------------------------
	//Name: deleteMinMaxIteratively
	//PreCondition: none
	//Postconditions: calls deleteMin and deleteMax
	//	in a loop until only one element is left
	//----------------------------------------------
	void deleteMinMaxIteratively();

	//----------------------------------------------
	//Name: deleteM
	//PreCondition: None
	//Postconditions: deletes the min value and then
	//	pivots the new min to the top
	//----------------------------------------------
	void deleteMin();

	//----------------------------------------------
	//Name: deleteM
	//PreCondition: None
	//Postconditions: deletes the max value and then
	//	pivots the new max to the top
	//----------------------------------------------
	void deleteMax();

	//----------------------------------------------
	//Name: printIntervalHeap
	//PreCondition: ostream out
	//Postconditions: outputs the contents of the heap
	//----------------------------------------------
	void printIntervalHeap(ostream & out);
};
