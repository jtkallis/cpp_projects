#include "LCS.h"
#include <omp.h>
#include <time.h>
using namespace std;

LCS::LCS(){}

int LCS::findLCS( string X,  string Y, int m, int n)
{
	m++;
	n++;
	int C[m][n];
	for (int i = 1; i < m; i++)
	{
		C[i][0]=0;
	}
	for(int j=0; j < n; j++)
	{
		C[0][j]=0;
	}
	double initialTime = omp_get_wtime();
	#pragma omp parallel
	{
		int thread = omp_get_thread_num();
		cout<<"thread:  "<<thread<<endl;
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
	}

	for(int z = 0; z < m; z++)
	{
		for(int q = 0; q < n; q++)
		{
			cout<<C[z][q];
		}
		cout<<endl;
	}
	double finalTime= omp_get_wtime();
	double totalTime = finalTime - initialTime;
	int LCS_length = C[m-1][n-1];
	return LCS_length;

}