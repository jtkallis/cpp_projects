/***********************************
/Name: driver.cpp
/Project:  1
/Writen By:  John Kallis
/Created: 11/10/2015
/Email:  jkallis1@umbc.edu
/Description: driver for LCS
/Help: I visited Koninika Patil on 
 11/10 and 11/12 during her office hours
************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <omp.h>
#include <time.h>
using namespace std;

//----------------------------------------------
//Name: printGreeting
//PreCondition: None
//Postconditions: Prints The Greeting
//----------------------------------------------
void printGreeting ()
{
	cout<<endl;
	cout << "Welcome to the Longest Common Subsequence Length Calculator." << endl;
	cout<<endl;
	cout << "writen by John Kallis" << endl;
	cout << "for project 1, CMSC 441, Marron" << endl;
	cout<<endl;
	cout << "This program will take in two .txt files each containing"<<endl;
	cout << "a sequence. You should've already entered these in command line." <<endl;
	cout << "The program will find the LCS for the two sequences" << endl;
	cout<<endl;
}

//----------------------------------------------
//Name: findLCSlength
//PreCondition: string X,  string Y, int m, int n
//		where X,Y are the seqences and m,n are the
//		lengths of those seqences
//Postconditions: returns the length in an int
//----------------------------------------------
int findLCSlength( string X,  string Y, int m, int n)
{
	//incriments m,n by one to account
	//for the zero rows
	m++;
	n++;
	//initialze the 2d array for table
	int C[m][n];
	//fill the first column (vertical) with zeroes
	for (int i = 1; i < m; i++)
	{
		C[i][0]=0;
	}
	//fill the first row (horizontal) with zeroes
	for(int j=0; j < n; j++)
	{
		C[0][j]=0;
	}
	//calls pragma omp
	//double initialTime = omp_get_wtime();
	//#pragma omp parallel
	//{
		//int thread = omp_get_thread_num();
		//cout<<"thread:  "<<thread<<endl;
	clock_t tm;
	tm = clock();

		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if( X[i] == Y[j] )
				{
					C[i][j]= (C[i-1][j-1] + 1);
				}
				else if (C[i-1][j] >= C[i][j-1])
				{
					C[i][j] = C[i-1][j];
				}
				else
				{
					C[i][j]=C[i][j-1];
				}
			}
		}
	//}
		tm=clock() - tm;
		cout<<"time "<<tm<<endl;
	/******PRINTS TABLE*******
	for(int z = 0; z < m; z++)
	{
		for(int q = 0; q < n; q++)
		{
			cout<<C[z][q];
		}
		cout<<endl;
	}****/

	//double finalTime= omp_get_wtime();
	//double totalTime = finalTime - initialTime;
	//cout<<endl;
	//cout<<"Time of computation: "<<totalTime<<endl;
	//cout<<endl;
	//finds the length of the LCS in the
	//bottom right corner of the table
	int LCS_length = C[m-1][n-1];


	return LCS_length;

}

int main ( int argc, char *argv[] )
{
	printGreeting();

	//initializing and assigning variables
	//from the command line arguments
	istringstream hold_m( argv[2]);
	int m;
	hold_m >> m;

	istringstream hold_n( argv[4] );
	int n;
	hold_n >> n;

	ifstream inFile1(argv[1]);
	ifstream inFile2(argv[3]);

	string holdLine1;
	string holdLine2;

	string X;
	string Y;

	//store the first file/sequence in a string or...
	if ( inFile1.is_open() )
	{
		while( getline( inFile1, holdLine1)) {X = holdLine1;}
	}
	//...prints this error message
	else{cerr<<"error file 1"<<endl;}
 	//store the second file/sequence in a string or...
	if ( inFile2.is_open() )
	{
		while( getline( inFile2, holdLine2)){Y = holdLine2;}
	}
	//...prints this error message
	else{cerr<<"error file 2"<<endl;}

	//calls the LCS-length function
	//and stores the value in a variable 
	int length_lcs = findLCSlength(X,Y,m,n);
	cout<<length_lcs<<endl;

	return 0;
}

