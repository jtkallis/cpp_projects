
#ifndef REPORT_H
#define REPORT_H
/******************************************************************************
*
* File:    Report.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the Report class, which
* is derived from the Document class.  It inherits many data and function
* members from Document. It also has a sub class, TechReport, which inherits
* many data and function memebers from Report. 
*
******************************************************************************/
#include <string>
#include "Document.h"
#include "BadResponseException.h"


class Report : public Document {
public:
	//-------------------------------------------------------------------------
    // Name: Report (constructor)
    // PreCondition:  None.
    // PostCondition: Initializes the title field.
    //-------------------------------------------------------------------------
    Report(int aID, std::string author, std::string title,
	   std::string textBody);
 	//-------------------------------------------------------------------------
    // Name: GetTitle
    // PreCondition:  None.
    // PostCondition: returns m_title
    //-------------------------------------------------------------------------
    std::string GetTitle();
    //-------------------------------------------------------------------------
    // Name: DisplayHeader.
    // PreCondition:  inherits virtual method from document class.
    // PostCondition: Prints the header
    //-------------------------------------------------------------------------
    void DisplayHeader();
    //-------------------------------------------------------------------------
    // Name: DisplayBody.
    // PreCondition:  inherits method from documant class.
    // PostCondition: Inherits this method from Document class
    //-------------------------------------------------------------------------
    void DisplayBody();
    //-------------------------------------------------------------------------
    // Name: Searh.
    // PreCondition:  The string being searched for.
    // PostCondition: Returns a bool after searching the textBody
    // for the string.
    //-------------------------------------------------------------------------
    bool Search(std::string searchString);
    //-------------------------------------------------------------------------
    // Name: CreateResponse
    // PreCondition:  Over-rides the pure virtual method from the document class
    // PostCondition: creates a new object for the response.
    //-------------------------------------------------------------------------
    Report *CreateResponse(std::string author, std::string textBody, int nextID);

protected:
    std::string m_title;
};

#endif