//johnkallis
//BadResponseException Class
// WRITE MORE STUFF HERE

#include <iostream>
#include <string>
#include "BadResponseException.h"

BadResponseException::BadResponseException(){
	cout<<"something has gone wrong. "<<endl;
}
BadResponseException::BadResponseException(string errormessage){
	m_error = errormessage;
}

string BadResponseException::GetMessage(){
	return m_error;
}


