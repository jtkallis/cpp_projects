#include <iostream>
#include "Proj3Aux.h"

using namespace std;


int main(int argc, char *argv[]) {
    string line;
    bool status;
    bool eof;

    do {
	cout << "> ";
	getline(cin, line);
	if (!(eof = cin.eof())) {
	    status = Parse(line);
	}
    } while (!eof);
    return !status;
}