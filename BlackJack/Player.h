//File: Player.h
//
//John Kallis

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <iostream>

using namespace std;

class Player{

public:
	/*
	Name:Player
	default (no -arg) constructor
	Preconditions: none
	Postconditions:
		Sets up a player Jane with 100$
	*/
	Player();
	/*
	Name: Blackjack
	standard constructor
	Preconditions:
		names -- an array of names
	Postconditions:
		Sets up each player from an array of names
	*/
	Player(char *names);

	/*
	*GetPlayer:
	Preconditions: *names -- an array of names
	Postconditions: returns the name of a given player
	*/
	char *GetPlayer();

	/*
	GetChips:
		Preconditions: none
		Postconditions:
		returns the amount a given player has left to bet with
	*/
	int GetChips();

	/*
	SetChips:
	Preconditions: the amount of money a player has left in their bank
	Postconditions:
		sets up the new value for the amount of money
	*/
	void SetChips(int amt);

	/*
	GetBet:
	Preconditions: none
	Postconditions:
		returns the value the player wants to bet from the input
	*/
	int GetBet();

	/*
	SetBet:
	Preconditions: The input from GetBet
	Postconditions: 
		sets the bet size that was inputed to the specific player
	*/
	void SetBet(int bet);

	/*
	AddCard:
	Preconditoins:
	The card being dealt
	Postcondtions:
	links the card to the Hand class
	*/
	void AddCard(Card tempCard);

	/*
	AttachtoHand1:
	Preconditoins:
	none
	Postcondtions:
	links the blackjack class to the Hand class
	*/
	void AttachToHand1();

	//void AttachScore();


private:
	char *m_name;
	int m_chips;
	int m_bet;
	Hand m_cards;
	int score;

};
#endif //Player