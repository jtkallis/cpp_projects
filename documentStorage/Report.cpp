#include <iostream>
#include "Report.h"

using namespace std;

Report::Report(int aID, string author, string title, string textBody)
    : Document(aID, author, textBody), m_title(title) {
}

string Report::GetTitle() {
    return m_title;
}

void Report::DisplayHeader() {
    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Title: " << GetTitle() << endl;
}

Report *Report::CreateResponse(string author, string textBody, int nextID) {

    // STUB:
    //
    // YOU ARE RESPONSIBLE FOR WRITING THE
    // CODE FOR THIS METHOD
    // (until you do, you will continue to get compiler warnings about
    //  "no return statement in function returning non-void"
    throw BadResponseException("cannnot respond to a report");
}
