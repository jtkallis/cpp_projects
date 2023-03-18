//File: Hand.h
//
//John Kallis

#ifndef HAND_H
#define HAND_H

#include "Deck.h"
#include "Card.h"


class Hand{

public:
	/*
	Name: Hand
		default constructor
		Preconditons-none
		Postconditions-none??
	*/
	Hand();
	/*
	Precondition: the card that was dealt
	Postconditions:
	adds the card to a vector for a player
	*/
	void PushCard(Card tempCard);

	/*
	SizeHand:
	Preconditions-none
	Postconditions-returns the number of cards in the hand
	*/
	int SizeHand();


	/*
	PrintHand:
	preconditions: none
	postconditions-prints the cards in a players hand
	*/
	void PrintHand();

	/*
	Value:
	preconditons-score(this is wrong i think it should be none)
	0 is the value of score in blackjack. idk how to initialize the 
	correct value
	postconditions-returns the total value of a players hand
	*/
	int Value(int score);

private:
	std::vector<Card> m_hand;
	
};

#endif //Hand