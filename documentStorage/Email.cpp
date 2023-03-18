#include <iostream>
#include "Email.h"

using namespace std;

Email::Email(int aID, string author, string subject, string recipientName,
	     string recipientEmail, string textBody)
    : Correspondence(aID, author, textBody, subject, recipientName),
     m_subject(subject), m_recipientName(recipientName),
      m_recipientEmail(recipientEmail){
}

string Email::GetRecipientEmail() {
    return m_recipientEmail;
}

void Email::DisplayHeader(){
    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Subject: " << GetSubject() << endl;
    cout << "Recipient: " << GetRecipientName() << endl;
    cout << "E-mail Address: " << GetRecipientEmail() << endl;
}


Email *Email::CreateResponse(string author, string textBody, int nextID) {

    // STUB:
    //
    // YOU ARE RESPONSIBLE FOR WRITING THE
    // CODE FOR THIS METHOD
    // (until you do, you will continue to get compiler warnings about
    //  "no return statement in function returning non-void"
    Email *emailResponsePointer;
    if(author != m_recipientName){
        throw BadResponseException("You were not the recipient of this email. You cannot respond");
    }
    m_recipientName = m_author;
    m_author = author;
    m_subject = "RE: "+m_subject;
    m_recipientEmail = m_recipientName + "@yoyodyne.com";
    emailResponsePointer = new Email(nextID, m_author, m_subject, m_recipientName, m_recipientEmail, textBody);
    return emailResponsePointer;
    
}
