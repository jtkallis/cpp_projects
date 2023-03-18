//
// YOU ARE FREE TO MODIFY THIS FILE IN ANY WAY THAT YOU WISH
//
#include <string>
#include <iostream>
#include "Correspondence.h"

using namespace std;

Correspondence::Correspondence(int aID, string author,
			       string textBody, string subject, string recipientName)
    : Document(aID, author, textBody),m_subject(subject), m_recipientName(recipientName){

    }

string Correspondence::GetSubject(){
	return m_subject;
	}
string Correspondence::GetRecipientName(){
	return m_recipientName;
	}


