#ifndef TECHREPORT_H
#define TECHREPORT_H
/******************************************************************************
*
* File:    TechReport.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the TechReport class, which
* is derived from the Report class.  It inherits many data and function
* members from Report.
*
******************************************************************************/

#include <string>
#include <vector>
#include "Report.h"
#include "BadResponseException.h"

// Following tells compiler that this class exists, and that we will
// define it fully later.  This allows us to refer to Comment in definition
// of TechReport class
class Comment;


class TechReport : public Report {
public:
    //-------------------------------------------------------------------------
    // Name: TechReport (constructor)
    // PreCondition: none.
    // PostCondition: initializes the the title field
    //-------------------------------------------------------------------------
    TechReport(int aID, std::string author, std::string title,
	       std::string textBody);

    //-------------------------------------------------------------------------
    // Name: DisplayHeader.
    // PreCondition: inherits pure virtal method from document.
    // PostCondition: prints the header and loops through the vector for the
    // distribution list.
    //-------------------------------------------------------------------------
    void DisplayHeader();
    //-------------------------------------------------------------------------
    // Name: DisplayBody
    // PreCondition: none.
    // PostCondition:prints the comments
    //-------------------------------------------------------------------------
    void DisplayComments();
    //-------------------------------------------------------------------------
    // Name: Search
    // PreCondition: the string being searched.
    // PostCondition: searches the body and returns a bool for the word 
    //-------------------------------------------------------------------------
    bool Search(std::string searchString);
    //-------------------------------------------------------------------------
    // Name: CreateResponse
    // PreCondition: over-rides the pure virtual method from the document class.
    // PostCondition: creates a new comment object that gets displayed with the 
    // tech report.
    //  returns NULL
    //-------------------------------------------------------------------------
    TechReport *CreateResponse(std::string author, std::string textBody, int nextID);



private:
    std::vector<Comment> m_comments;
    std::string m_title;

};


//-----------------------------------------------------------------------------
// The simple helper class Comment, used by the TechReport class to store
// comments in the report.  (This is a really quick-and-dirty implementation;
// it violates some of our own guidelines, but we wanted to keep it simple.
//    --jyp
//-----------------------------------------------------------------------------
class Comment {
 public:
    std::string m_author;
    std::string m_textBody;

    //-------------------------------------------------------------------------
    // Name: Comment (constructor)
    // PreCondition:  None.
    // PostCondition: Initializes the author and textBody fields
    //-------------------------------------------------------------------------
    Comment(std::string author = "", std::string textBody = "")
	: m_author(author), m_textBody(textBody) {}
};

#endif
