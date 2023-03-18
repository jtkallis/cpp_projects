#ifndef DOCUMENTSTORE_H
#define DOCUMENTSTORE_H

#include <string>
#include <vector>
#include "Document.h"

class DocumentStore {
public:
    DocumentStore();
    void CreateEmail();
    void CreateMemo();
    void CreateReport();
    void CreateTechReport();
    void Display(int docID);
    void ListDocuments();
    void Search(std::string queryStr);
    void ClearDocuments();
    void Respond(int docID);
private:
    // Used to help generate unique sequential ID #'s for documents
    int m_nextID;

    // Vector used to keep track of our active documents
    std::vector<Document *> m_active;
    // Add other data members below (not here)

    static std::string InputText(const char *prompt);
    static std::string InputMultilineText(const char *prompt);
    static std::vector<std::string> InputTextCollection(const char *prompt);
};

#endif
