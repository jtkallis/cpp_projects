#ifndef EMAIL_H
#define EMAIL_H
/******************************************************************************
*
* File:    Email.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the Email class, which
* is derived from the Correspondence class.  It inherits many data and function
* members from Correspondence.
*
******************************************************************************/
#include <string>
#include "Correspondence.h"
#include "BadResponseException.h"



class Email : public Correspondence {
public:
    //-------------------------------------------------------------------------
    // Name: Email (constructor)
    // PreCondition: none.
    // PostCondition: initializes the subject recipientName and recipientEmail
    //-------------------------------------------------------------------------
    Email(int aID, std::string author, std::string subject,
	  std::string recipientName, std::string recipientEmail,
	  std::string textBody);
        //-------------------------------------------------------------------------
    // Name: GetRecipientEmail.
    // PreCondition: none
    // PostCondition: returns the recipienets email.
    //-------------------------------------------------------------------------
    std::string GetRecipientEmail();
    //-------------------------------------------------------------------------
    // Name: DisplayHeader.
    // PreCondition: inherits pure virtal method from document.
    // PostCondition: prints the header and loops through the vector for the
    // distribution list.
    //-------------------------------------------------------------------------
    void DisplayHeader();
    //-------------------------------------------------------------------------
    // Name: DisplayBody
    // PreCondition: inherits from document class.
    // PostCondition: prints the body
    //-------------------------------------------------------------------------
    void DisplayBody();
    //-------------------------------------------------------------------------
    // Name: Search
    // PreCondition: the string being searched.
    // PostCondition: searches the body and returns a bool for the word 
    //-------------------------------------------------------------------------
    bool Search(std::string searchString);
    //-------------------------------------------------------------------------
    // Name: CreateResponse
    // PreCondition: over-rides the pure virtual method from the document class.
    // PostCondition: creates a new email object for the response.
    //-------------------------------------------------------------------------
    Email *CreateResponse(std::string author, std::string textBody, int nextID);

private:
    std::string m_subject;
    std::string m_recipientName;
    std::string m_recipientEmail;

};

#endif