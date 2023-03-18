#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

/******************************************************************************
*
* File:    Correspondence.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the Correspondence class, which
* is derived from the Document class.  It inherits many data and function
* members from Document. It has two child classes, Email and Memo, which
* inherit many data and function members from correspondence.
*
******************************************************************************/

#include <string>
#include "Document.h"

class Correspondence : public Document {
public:
    //-------------------------------------------------------------------------
    // Name: Correspondence (constructor)
    // PreCondition: noone
    // PostCondition: initializes the subject and recipientName fields
    //-------------------------------------------------------------------------
    Correspondence(int aID, std::string author,
		   std::string textBody, std::string subject, std::string recipientName);
        //-------------------------------------------------------------------------
    // Name: GetsSubject
    // PreCondition: noone
    // PostCondition: returns the subject
    //-------------------------------------------------------------------------
    std::string GetSubject();
        //-------------------------------------------------------------------------
    // Name: GetRecipientName
    // PreCondition: noone
    // PostCondition: returns the recipientName
    //-------------------------------------------------------------------------
    std::string GetRecipientName();


private:
	std::string m_subject;
    std::string m_recipientName;

};

#endif
