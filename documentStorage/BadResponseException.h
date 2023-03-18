#ifndef BADRESPONSEEXCEPTION_H
#define BADRESPONSEEXCEPTION_H
/******************************************************************************
*
* File:    BadResponceException.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Kallis (from a skeleton by John Park)
* Date:    12/09/2014
* Section: 06
* E-mail:  jkallis1@umbc.edu 
*
*   This file contains the definition of the BadResponceException class, which
* creates an object to be thrown as an error message. 
*
******************************************************************************/
#include <string>
using namespace std;


class BadResponseException {

    // ADD YOUR DEFINITION HERE
    // YOU SHOULD EXAMINE CODE WHERE THIS IS CAUGHT (IN DocumentStore.cpp)
    // TO SEE WHAT METHODS ARE BEING CALLED ON THIS CLASS, AND ADD THEM.
    // THEN, WHEN YOU ADD CODE TO THROW THIS EXCEPTION TYPE IN YOUR
    // DOCUMENT CLASS IMPLEMENTATIONS, THAT WILL ALSO DEFINE WHAT DATA
    // AND FUNCTION MEMBERS NEED TO BE ADDED.
	public:
    //-------------------------------------------------------------------------
    // Name: BadResponseException (constructor)
    // PreCondition: noone
    // PostCondition: none
    //-------------------------------------------------------------------------
	BadResponseException();
    //-------------------------------------------------------------------------
    // Name: BadResponseException (constructor)
    // PreCondition: an errormessage
    // PostCondition: initializes the errormessage
    //-------------------------------------------------------------------------
	BadResponseException(string errrormessage);
    //-------------------------------------------------------------------------
    // Name: BadResponseException (constructor)
    // PreCondition: none
    // PostCondition: returns the errormessage
    //-------------------------------------------------------------------------
	string GetMessage();

private:
	string m_error;
};

#endif
