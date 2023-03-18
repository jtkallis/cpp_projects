#include "HashAndCompare.h"


using namespace std;

void greeting()
{
	cout<<endl;
	cout<<"Welcome to the Jacobian calculator comparing "<<endl;
	cout<<"ten plays by William Shakespeare"<<endl;
	cout<<"Written by John Kallis"<<endl;
	cout<<"project 5 CMSC 341 - 02 Lupoli"<<endl;
	cout<<"This program will take 10 plays by William Shakespeare"<<endl;
	cout<<"and store them in hash table and calculate a Jacobian"<<endl;
	cout<<"for the words that appear in each play and write the results"<<endl;
	cout<<"to a file results.txt"<<endl;
	cout<<endl;
}
int main(int argc, char * argv[])
{
	greeting();

	//string filePath( argv[1] );

	HashAndCompare hash_and_compare( argv[1] );
	cout<<"test"<<endl;
	hash_and_compare.parse();
	
	


	return 0;
}