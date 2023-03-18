#include <iostream>
#include <string>
#include <vector>
#include "Memo.h"

using namespace std;

Memo::Memo(int aID, string author, string subject, string recipientName,
	   vector<string> distributionList, string textBody)
    : Correspondence(aID, author, textBody, subject, recipientName),
      m_subject(subject), m_recipientName(recipientName),
      m_distributionList(distributionList) {

}

vector<string> Memo::GetDistributionList() {
    return m_distributionList;
}

void Memo::DisplayHeader(){
    vector<string> distList;

    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Subject: " << GetSubject() << endl;
    cout << "Recipient: " << GetRecipientName() << endl;
    cout << "Distribution List:\n";
    distList =  GetDistributionList();
    for (unsigned int i = 0; i < distList.size(); i++) {
	cout << "  " << distList[i] << endl;
    }
}

Memo *Memo::CreateResponse(string author, string textBody, int nextID) {

    // STUB:
    //
    // YOU ARE RESPONSIBLE FOR WRITING THE
    // CODE FOR THIS METHOD
    // (until you do, you will continue to get compiler warnings about
    //  "no return statement in function returning non-void"
    m_newDistributionList = m_distributionList;
    flag = false;
    for (unsigned int i = 0; i < m_distributionList.size(); i++)
    {
        if(m_distributionList[i] == author){
            flag = true;
            m_newAuthor = author;
            m_newRecipientName = m_author;
            m_newDistributionList[i] = m_recipientName;
            m_subject = "RE: "+m_subject;

        }

    }    
    if (m_recipientName == author){
        flag = true;
        m_newRecipientName = m_recipientName;
        m_newAuthor = author;
        m_subject = "RE: "+m_subject;

    }
    if (!flag){
        throw BadResponseException("You were not a recipient of this memo you cannont respond");
    }
    else{

    /*    for (unsigned int i = 0; i < m_newDistributionList.size(); i++)
    {   cout<<""<<endl;
        cout<<m_newDistributionList[i]<<endl;}*/




    Memo *memoResponsePointer = new Memo(nextID, m_newAuthor, m_subject, m_newRecipientName, m_newDistributionList, textBody);
    return memoResponsePointer;
    }
}
