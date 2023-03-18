#ifndef MEMO_H
#define MEMO_H
/******************************************************************************
*
* File:    Memo.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the Memo class, which
* is derived from the Correspondence class.  It inherits many data and function
* members from Correspondence.
*
******************************************************************************/
#include <string>
#include <vector>
#include "Correspondence.h"
#include "BadResponseException.h"

class Memo : public Correspondence {
public:
    //-------------------------------------------------------------------------
    // Name: Memo (constructor)
    // PreCondition:  None.
    // PostCondition: Initializes the subject, recipientName, and 
    // distributionList fields.
    //-------------------------------------------------------------------------
    Memo(int aID, std::string author, std::string subject,
     std::string recipientName, std::vector<std::string> distributionList,
     std::string textBody);
    //-------------------------------------------------------------------------
    // Name:  GetDistributionList.
    // PreCondition:   None.
    // PostCondition:  returns the distributionlist vector.
    //-------------------------------------------------------------------------
    std::vector<std::string> GetDistributionList();
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
    // PostCondition: creates a new memo object for the response.
    //-------------------------------------------------------------------------
    Memo *CreateResponse(std::string author, std::string textBody, int nextID);

private:
    std::string m_subject;
    std::string m_recipientName;
    std::vector<std::string> m_distributionList;
    //following are for the CreateResponse method
    std::vector<std::string> m_newDistributionList;
    std::string m_newRecipientName;
    std::string m_newAuthor;
    bool flag;


};

#endif