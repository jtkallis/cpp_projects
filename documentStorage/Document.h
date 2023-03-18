#ifndef DOCUMENT_H
#define DOCUMENT_H
/******************************************************************************
*
* File:    Document.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the Document class, which
* is the base class.  The hierarchy starts with this class. 
*
******************************************************************************/
#include <string>
#include "BadResponseException.h"

class Document {
public:
        //-------------------------------------------------------------------------
    // Name: Document (constructor)
    // PreCondition: noone
    // PostCondition: none.
    //-------------------------------------------------------------------------
    Document();
    //-------------------------------------------------------------------------
    // Name: Document (constructor)
    // PreCondition: noone
    // PostCondition: Initializes the id, author, and textBody Fields.
    //-------------------------------------------------------------------------
    Document(int aID, std::string author, std::string textBody);
    //-------------------------------------------------------------------------
    // Name: GetID
    // PreCondition: noone
    // PostCondition: Returns the int value for the id
    //-------------------------------------------------------------------------
    int GetID();
    //-------------------------------------------------------------------------
    // Name:GetAuthor
    // PreCondition: noone
    // PostCondition: returns a string of the author
    //-------------------------------------------------------------------------
    std::string GetAuthor();
    //-------------------------------------------------------------------------
    // Name: GetBody
    // PreCondition: noone
    // PostCondition: returns a string with the body
    //-------------------------------------------------------------------------
    std::string GetBody();
    //-------------------------------------------------------------------------
    // Name: DisplayBody
    // PreCondition: noone
    // PostCondition: prints the body of text
    //-------------------------------------------------------------------------
    void DisplayBody();
    //-------------------------------------------------------------------------
    // Name: Search
    // PreCondition: the string being searched
    // PostCondition: returns a bool after searching the body
    //-------------------------------------------------------------------------
    bool Search(std::string searchString);

    //-------------------------------------------------------------------------
    // Name: DisplayHeader
    // PreCondition: noone  (virtual method to be overriden in sub classes)
    // PostCondition: none
    //-----------------------------------------------------------------------    
    virtual void DisplayHeader();

    //-------------------------------------------------------------------------
    // Name: CreateResponse
    // PreCondition: noone (pure virtual)
    // PostCondition: returns a new document subclass object. 
    //-------------------------------------------------------------------------
    virtual Document *CreateResponse(std::string author,
     std::string textBody, int nextID)=0;

private:

    int m_ID;


protected:
    std::string m_author;
    std::string m_textBody;
 
};

#endif
