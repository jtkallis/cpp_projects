
#ifndef HASHANDCOMPARE_H
#define HASHANDCOMPARE_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <stdlib.h>



using namespace std;

class HashAndCompare
{
public: 

	HashAndCompare(const char* filePath);
	~HashAndCompare();
	int listDir();
	void parse();
	int hash(string key);



private:

	//holds file names
	vector<string> files;
	
	//holds text split on spaces
	vector<string> KingLear;
	vector<string> AnthonyAndCleo;
	vector<string> Hamlet;
	vector<string> JuliusCaesar;
	vector<string> Othello;
	vector<string> Pericles;
	vector<string> Macbeth;
	vector<string> RomeoJuliet;
	vector<string> Tempest;
	vector<string> TitusAndronicus;

	//holds hash tables
	vector<string> hash_AnthonyAndCleo[];
	vector<string> hash_Hamlet[];
	vector<string> hash_JuliusCaesar[];
	vector<string> hash_KingLear[];
	vector<string> hash_Macbeth[];
	vector<string> hash_Othello[];
	vector<string> hash_Pericles[];
	vector<string> hash_Tempest[];
	vector<string> hash_RomeoJuliet[];
	vector<string> hash_TitusAndronicus[];

	//file path
	const char * m_filePath;
};

#endif //HASHANDCOMPARE