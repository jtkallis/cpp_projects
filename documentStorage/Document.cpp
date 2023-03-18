#include <iostream>
#include "Document.h"

using namespace std;

Document::Document() {
}

Document::Document(int aID, string author, string textBody)
    :m_ID(aID), m_author(author), m_textBody(textBody) {
}

int Document::GetID() {
    return m_ID;
}

void Document::DisplayHeader(){
    cout<<"";
}

string Document::GetAuthor() {
    return m_author;
}

string Document::GetBody() {
    return m_textBody;
}

void Document::DisplayBody()    {
	    cout << "Contents:\n";
    cout << GetBody();
}

bool Document::Search(string searchString){
	string textBody = GetBody();

    return textBody.find(searchString) != string::npos;
}

