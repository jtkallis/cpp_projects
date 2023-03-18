//----------------------------------------------
//Name: IntervalHeap.cpp
// Project 4 CMSC 341-02 Lupoli
// John Kallis <jkallis1@umbc.edu>
//implements the IntervalHeap class and 
// LeftRightElment Class
//
// source:
//	http://www.mhhe.com/engcs/compsci/sahni/enrich/c9/interval.pdf
//	the link is an expert from The McGraw Hill Comapinies
//	Data Structures, Algorithms, and Applications in C++
//		by Sartaj Sahni
//----------------------------------------------


#include "IntervalHeap.h"
using namespace std;

//Constructor
IntervalHeap::IntervalHeap(int min, int max, int size, int theSeed) 
{
	
	if( min < 0 )
	{ 	
		minRange = 0;
		maxRange = max + (-min);
		storeMin = min;
		storeMax = max;
		negative=true;
		positive=false;
	}
	else if ( min > 0 )
	{
		minRange = 0;
		maxRange = max - min;
		storeMin = min;
		storeMax = max;
		positive = true;
		negative=false;

	}	
	
	else
	{
		minRange = min;
		maxRange = max;
		negative=false;
		positive= false;
	}
	inputSize = size;
	seed = theSeed;

	int arraySize = ( ( inputSize / 2 ) + ( inputSize % 2 ) + 1 );
	heap = new LeftRightElements [arraySize];
	currentSize = 0;
	newSize = inputSize;
}

//Destructor
IntervalHeap::~IntervalHeap()
{
	delete[] heap;
}

//returns min from interval heap
int IntervalHeap::getMin()
{
       	return heap[1].left;	
}
//returns max from interval heap
int IntervalHeap::getMax()
{
        return heap[1].right;
}

//returns total number of elements in the interval heap 
int IntervalHeap::getSize()
{
	return currentSize;
}

//method that generates random numbers and inserts them in the interval heap
void IntervalHeap::insertRandomNumbers()
{
	int i = 0;
	srand ( seed );
	int r;
	while ( i < inputSize)
	{	
		
		if ( negative == true )
		{	
			r = rand() % maxRange + minRange;
			r = r + storeMin;

			
		}
		else if ( positive == true )
		{
			r = rand() % maxRange + minRange;
			r = r + storeMin;
	
		}
		else
		{
			r = rand() % maxRange + minRange;

		
		}
		insert( r );
	
		
		i++;
	}
}
//method that inserts an element into the interval heap
void IntervalHeap::insert(int n)
{
	if ( currentSize < 2 )
	{
	    if( currentSize ) // currentSize = 1
		{
			if ( n < heap[1].left )
			{
				heap[1].left = n;
			}
			else
			{
				heap[1].right = n;
			}
		}
		else // currentSize = 0
		{
			heap[1].left = n;
			heap[1].right = n;
		}
		currentSize++;
		return;
	}
	int last = ( ( currentSize /  2 ) + ( currentSize % 2 ) );
	bool minHeap; //true if n is inserted into the min heap
	
	if ( currentSize % 2 )//odd
	{
		if ( n < heap[last].left )
		{
			minHeap = true;
		}
		else
		{
			minHeap = false;
		}
	}
	else //even
	{
		last++;
		if ( n <= heap[ last / 2 ].left )
		{
			minHeap = true;
		}
		else
		{
			minHeap = false;
		}
	}

	if ( minHeap ) //if min heap
	{	
		int i = last;
		while ( ( i != 1 ) && ( n < heap[i/2].left ) )
		{
			heap[i].left = heap[i/2].left;
			i/=2;
		}
		heap[i].left = n;
		currentSize++;
		if ( currentSize % 2 ) // odd
		{
			heap[last].right = heap[last].left;
		}
	}
	else //if max heap
	{
		int i = last;
     	while ( ( i != 1 ) && ( n > heap[i/2].right ) )
		{
			heap[i].right = heap[i/2].right;
			i/=2;
		}
		heap[i].right = n;
		currentSize++;
		if ( currentSize % 2 )
		{
			heap[last].left = heap[last].right;
		}
	}
}
//method that deletes min and max iteratively until just 1 element is left
void IntervalHeap::deleteMinMaxIteratively()
{
 	int i = 0;
 	ofstream results ("results.txt");
 	if ( results.is_open() )
 	{
  		results <<"min = "<<storeMin<<" max = "<<storeMax<<" size = "<<inputSize<<" seed = "<<seed<<endl;
		results << endl;
  		results <<"Interval Heap built:"<<endl;
  		printIntervalHeap(results);
  		  
   		while ( i < ( inputSize - 1 ) )
    	{
    	 	if ( i % 2 ) // odd
			{
	 			results <<"after deleting max "<<getMax()<<" : "<<endl;
	 			deleteMax();
	 			newSize--;
	 			printIntervalHeap(results);

	 		}
			
      		else //even and 0
			{
				results <<"after deleting min "<<getMin()<<" : "<<endl;
				deleteMin();
				newSize--;
				printIntervalHeap(results);
	  
			}
      	i++;
   		}
			
    	//exit(0);
    }
    else
    {
    	cerr<<"error unable to write file"<<endl;
    	exit(0);
    }
}

//method that deletes min from the interval heap
void IntervalHeap::deleteMin()
{
  int last = ( currentSize / 2 ) + ( currentSize % 2 );
  int newMin;
  if ( currentSize % 2 ) //odd
  {
    newMin = heap[last].left;
    last--;
  }
  else //even
  {
    newMin = heap[last].right;
    heap[last].right = heap[last].right;
  }
  currentSize--;
  int i = 1;
  int k = 2;
  while ( k<=last )
  {
    if ( k < last && heap[k].left > heap[k+1].left )
    {
		k++;
    }
    if ( newMin <= heap[k].left ) break;
    heap[i].left = heap[k].left;
    if ( newMin > heap[k].right )
    {
		swap(newMin, heap[k].right);
    }
    i = k;
    k *= 2;
  }
  if (i==last && currentSize % 2)
    {
      if ( heap[last].right )
      	{heap[last].left = heap[last].right;}
    }
  else
    {
      heap[i].left = newMin;
    }
}
//method that deletes max from the interval heap
void IntervalHeap::deleteMax()
{                     
  int last = ( currentSize / 2 ) + ( currentSize % 2 );
  int newMax;
  if ( currentSize % 2 ) //odd                                                 
    {
      newMax = heap[last].left;
      last--;
    }
  else //even                                                             
    {
      newMax = heap[last].right;
      heap[last].right = heap[last].right;                                                                                                                                           

    }
  currentSize--;
  int i = 1;
  int k = 2;
  while ( k<=last )
    {
      if ( k < last && heap[k].right < heap[k+1].right )
	{
	  k++;
	}
      if ( newMax >= heap[k].right ) break;
      heap[i].right = heap[k].right;
      if ( newMax < heap[k].left )
	{
	  swap(newMax, heap[k].left);
	}
      i = k;
      k *= 2;
    }

  heap[i].right = newMax;

}

//print level order interval heap to results.txt file
void IntervalHeap::printIntervalHeap(ostream & out)
{
	int heapSize = ( ( newSize / 2 ) + ( newSize % 2 ) + 1);
	out<<endl;
	for (int i = 1; i < heapSize; i++)
	{
		
		if ( ( newSize % 2 ) && ( i == ( heapSize - 1 ) ) )
		{	
			out<<heap[i].left<<endl;
		}

		else
		{
			if ( heap[i].left )
			{			out<<heap[i].left;
			}
			if ( heap[i].right && heap[i].left )
			{
				out<<",";
			}
			if ( heap[i].right )
			{
				out<<heap[i].right<<endl;
			}
			if( heap[i].left && !(heap[i].right) )
			  {cout<<endl;}
		}
		
	}
	out<<endl;
}


