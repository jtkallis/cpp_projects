#include <cstdlib>
#include <iostream>
#include <string>

#include "DocumentStore.h"
#include "Document.h"
#include "Correspondence.h"
#include "Memo.h"
#include "Email.h"
#include "Report.h"
#include "TechReport.h"
#include "BadResponseException.h"

using namespace std;

DocumentStore::DocumentStore() : m_nextID(10001) {}

string DocumentStore::InputText(const char *prompt) {
    string input;

    cout << prompt;
    getline(cin, input);
    return input;
}

string DocumentStore::InputMultilineText(const char *prompt) {
    string input, nextLine;
    bool endSeen = false;

    cout << prompt << "(type END on separate line to stop):\n";
    do {
    getline(cin, nextLine);
    if (nextLine.compare("END") == 0) {
        endSeen = true;
    }
    else {
        input.append(nextLine + "\n");
    }
    } while (!endSeen);
    return input;

}

vector<string> DocumentStore::InputTextCollection(const char *prompt) {
    string nextLine;
    vector<string> collection;
    bool endSeen = false;

    cout << prompt << "(type END on separate line to stop):\n";
    do {
    getline(cin, nextLine);
    if (nextLine.compare("END") == 0) {
        endSeen = true;
    }
    else {
        collection.push_back(nextLine);
    }
    } while (!endSeen);
    return collection;
}

void DocumentStore::CreateMemo() {
    Memo *newMemoPtr;
    string author, subject, recipientName, textBody;
    vector<string> distributionList;

    author = InputText("Enter author:\n");
    subject  = InputText("Enter subject:\n");
    recipientName = InputText("Enter recipient:\n");
    distributionList = InputTextCollection("Enter distribution list ");
    textBody = InputMultilineText("Enter text body ");
    newMemoPtr = new Memo(m_nextID++, author, subject, recipientName,
      distributionList, textBody);
    cout << "Memo #" << newMemoPtr->GetID()  // Verification of ID
     << " entered into documents list.\n";
    m_active.push_back(newMemoPtr);
}

void DocumentStore::CreateEmail(){
    Email *newEmailPtr;
    string author, subject, recipientName, recipientEmail, textBody;

    author = InputText("Enter author:\n");
    subject  = InputText("Enter subject:\n");
    recipientName = InputText("Enter recipient:\n");
    recipientEmail = InputText("Enter recipient's e-mail address:\n");
    textBody = InputMultilineText("Enter text body ");
    newEmailPtr = new Email(m_nextID++, author, subject, recipientName, recipientEmail,
                textBody);
    cout << "E-mail #" << newEmailPtr->GetID()  // Verification of ID
     << " entered into documents list.\n";
    m_active.push_back(newEmailPtr);
}

void DocumentStore::CreateReport(){
    Report *newReportPtr;
    string author, title, textBody;

    author = InputText("Enter author:\n");
    title = InputText("Enter title:\n");
    textBody = InputMultilineText("Enter text body ");
    newReportPtr = new Report(m_nextID++, author, title, textBody);
    cout << "Report #" << newReportPtr->GetID()  // Verification of ID
     << " entered into documents list.\n";
    m_active.push_back(newReportPtr);
}

void DocumentStore::CreateTechReport(){
    Report *newTechReportPtr;
    string author, title, textBody;

    author = InputText("Enter author:\n");
    title = InputText("Enter title:\n");
    textBody = InputMultilineText("Enter text body ");
    newTechReportPtr = new TechReport(m_nextID++, author, title, textBody);
    cout << "Technical Report #" << newTechReportPtr->GetID()  // Verification of ID
     << " entered into documents list.\n";
    m_active.push_back(newTechReportPtr);
}

void DocumentStore::Display(int docID){
    for (unsigned int i = 0; i < m_active.size(); i++) {
    if (m_active[i]->GetID() == docID) {
        m_active[i]->DisplayHeader();
        m_active[i]->DisplayBody();
        return;
    }
    }
    cout << "Document #" << docID << " not found.\n";
}

void DocumentStore::ListDocuments(){
    for (unsigned int i = 0; i < m_active.size(); i++) {
    m_active[i]->DisplayHeader();
    cout << endl;
    }
}

void DocumentStore::Search(string queryStr){
    bool noneFound = true;  // pessimistic assumption

    for (unsigned int i = 0; i < m_active.size(); i++) {
    if (m_active[i]->Search(queryStr)) {
        cout << m_active[i]->GetID() << endl;
        noneFound = false;
    }
    }
    if (noneFound) {
    cout << "No documents found.\n";
    }
}

void DocumentStore::ClearDocuments(){
    for (unsigned int i = 0; i < m_active.size(); i++) {
    // NB: this working correctly depends on polymorphic destructors!
    delete m_active[i];
    m_active[i] = NULL;
    }
    m_active.clear();
    cout << "Document collection has been cleared\n";
}

void DocumentStore::Respond(int docID){
    Document *doc, *newDoc;
    string author, textBody;

    for (unsigned int i = 0; i < m_active.size(); i++) {
    if (m_active[i]->GetID() == docID) {
        doc = m_active[i];
        // Don't bother user with this until we're sure we found the doc
        author = InputText("Enter response author:\n");
        textBody = InputMultilineText("Enter response text body ");
        try {
        newDoc = doc->CreateResponse(author, textBody, m_nextID);
        if (newDoc != NULL) { // for all but TechReport
            cout << "Response #" << newDoc->GetID()
             << " entered into documents list.\n";
            m_active.push_back(newDoc);
            m_nextID++;
        }

        }
        catch (BadResponseException& e) {
        cout << "Respond failed: " << e.GetMessage() << endl;
        }
        return;
    }
    }
    cout << "Document #" << docID << " not found.\n";
}