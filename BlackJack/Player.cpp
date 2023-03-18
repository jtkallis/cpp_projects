
//File: Player.cpp
//
//Implementation of Player class.
//

#include <iostream>
#include "Player.h"
//#include "Hand.h"
//PLayer constructors
//Default Constructor
Player::Player()
{
	//m_name= "Jane";
	//m_chips = 100;
	//m_bet = 0;
}
//Consstructor with argument
Player::Player(char *names)
{
	m_name = names;
	m_chips = 100;
	m_bet = 0;
}

//Player methods

char *Player::GetPlayer(){
	return m_name;
}

int Player::GetChips(){
	return m_chips; 
}

void Player::SetChips(int amt){
	m_chips = amt;
}

int Player::GetBet(){
	return m_bet;
}

void Player::SetBet(int bet){
	m_bet = bet;
}

void Player::AddCard(Card tempCard){
	m_cards.PushCard(tempCard);
}

void Player::AttachToHand1(){
	m_cards.PrintHand();
}
/*
void Player::AttachScore(){
	m_cards.Value()
}*/