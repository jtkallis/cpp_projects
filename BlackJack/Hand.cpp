
//File: Hand.cpp
//
//Implementation of Hand class.
//

#include <iostream>
#include "Hand.h"

//constructors
Hand::Hand(){
	
}
void Hand::PushCard(Card tempCard){
	m_hand.push_back(tempCard);
}

int Hand::SizeHand(){
	return m_hand.size();
}

void Hand::PrintHand(){
	for (int i = 0; i < SizeHand(); ++i){
		m_hand[i].OutputCard();
		std::cout<<" ,";
	}
}
int Hand::Value(int score){
	
	for (int i = 0; i < SizeHand(); ++i)
	{

		score = score + m_hand[i].GetBlackjackValue();
		
	}
	return score;
	
}
