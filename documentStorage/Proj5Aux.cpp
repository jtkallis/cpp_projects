#include <iostream>
#include "DocumentStore.h"
#include "Proj5Aux.h"

using namespace std;

void DisplayCmd(DocumentStore& docStore);
void SearchCmd(DocumentStore& docStore);
void RespondCmd(DocumentStore& docStore);

void DisplayPrompt() {
    cout << endl <<
	"   Document Storage System Menu\n"
	" 1 - Create and store an e-mail\n"
	" 2 - Create and store a memo\n"
	" 3 - Create and store a report\n"
	" 4 - Display a document\n"
	" 5 - List all documents\n"
	" 6 - Locate documents containing a specific word or phrase\n"
	" 7 - Clear the document collection\n"
	" 8 - Create and store a technical report [NEW]\n"
	" 9 - Respond/reply to a document [NEW]\n"
	"99 - Quit\n";
}

bool DoOneCommand(DocumentStore& docStore) {
    bool doExit = false;
    int cmd;

    DisplayPrompt();
    cout << "Enter your choice:\n";
    cin >> cmd;
    cin.ignore();
    switch (cmd) {
    case 1:  // Create and store an e-mail
	docStore.CreateEmail();
	break;
    case 2:  // Create and store a memo
	docStore.CreateMemo();
	break;
    case 3:  // Create and store a report
	docStore.CreateReport();
	break;
    case 4:  // Display a document
	DisplayCmd(docStore);
	break;
    case 5:  // List all active documents
	docStore.ListDocuments();
	break;
    case 6:  // Locate documents containing a specific word or phrase
	SearchCmd(docStore);
	break;
    case 7: // Clear the archive
	docStore.ClearDocuments();
	break;
    case 8:  // Create and store a technical report
	docStore.CreateTechReport();
	break;
    case 9:  // Respond/reply to an existing document
	RespondCmd(docStore);
	break;
    case 99: // Quit
	cout << "Exiting Document Storage System\n";
	doExit = true;
	break;
    default:
	cout << "UNRECOGNIZED COMMAND??\n";
	break;
    }
    return doExit;
}

void DisplayCmd(DocumentStore& docStore) {
    int docID;

    cout << "Enter the document ID:\n";
    cin >> docID;
    docStore.Display(docID);
}

void SearchCmd(DocumentStore& docStore) {
    string queryStr;

    cout << "Get search phrase:\n";
    getline(cin, queryStr);
    docStore.Search(queryStr);
}

void RespondCmd(DocumentStore& docStore) {
    int docID;
    string discard;

    cout << "Enter the document ID:\n";
    cin >> docID;
    getline(cin, discard);  // throw away rest of line w/docID
    docStore.Respond(docID);
}
