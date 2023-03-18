#include <iostream>
#include <string>
#include "TechReport.h"

using namespace std;

TechReport::TechReport(int aID, string author, string title, string textBody)
    : Report(aID, author, title, textBody), m_title(title) {
}


void TechReport::DisplayComments(){
  if (m_comments.size()==0){
    cout<<"--No comments yet."<<endl;
  }
  else{
    for (unsigned int i=0;i<m_comments.size(); i++){
      cout<<"Comment "<<i+1<<" by "<<m_comments[i].m_author<<":"<<endl;
      cout<<m_comments[i].m_textBody<<endl;
       }
  }
}
void TechReport::DisplayHeader(){
  cout<<"Document #: "<<GetID()<<endl;
  cout<<"Author: "<<GetAuthor()<<endl;
  cout<<"Title: "<<GetTitle()<<endl;
  DisplayComments();
}
/*bool TechReport::Search(std::string searchString){
  string textBody = GetBody();
  return textBody.find(searchString) != string::npos;

  if(m_comments.size()==0){
  
    return textBody.find(searchString) != string::npos;
  }
  else{
    if(textBody.find(searchString) != string::npos){
      for (unsigned int i = 0; i < m_comments.size(); i++)
      {
        if(m_comments[i].find(searchString) == string::npos){
          return false;}
      }
  }}}

*/




TechReport *TechReport::CreateResponse(string author, string textBody, int nextID){
  Comment *commentPointer;
  commentPointer = new Comment(author, textBody);
  m_comments.push_back(*commentPointer);
  return NULL;
}