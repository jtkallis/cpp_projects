/****************************************************************
 * File:    Deck.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  John Park
 * Date:    3/10/14
 * Section: all
 * E-mail:  park@umbc.edu 
 *
 *   This file contains the declaration for the Deck class.
 *   The class implements a deck of playing cards, including
 *   member functions for initializing, shuffling, and dealing from
 *   a deck.
 *
 ****************************************************************/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    /****************************************************************
     * Name: Deck:
     *   default (no-arg) constructor, intended for typical use
     * Preconditions: none.
     * Postconditions: creates a complete Deck of the standard 52 cards
     ****************************************************************/
    Deck();

    /****************************************************************
     * Card:
     *   Alternative constructor, for creating a Deck from a specific
     *   (likely incomplete) set of cards.
     *   NOT INTENDED FOR USE BY STUDENTS
     * Preconditions:
     *   cards -- an array of Card instances to create Deck from
     * Postconditions: constructs a Deck from the specified Cards
     ****************************************************************/
    Deck(Card cards[]);

    /****************************************************************
     * Card:
     *   Alternative constructor, for creating a Deck from a specific
     *   (likely incomplete) set of cards.
     *   NOT INTENDED FOR USE BY STUDENTS
     * Preconditions:
     *   cards -- a vector of Card instances to create Deck from
     * Postconditions: constructs a Deck from the specified Cards
     ****************************************************************/
    Deck(std::vector<Card> cards);

    /****************************************************************
     * Shuffle:
     *   Shuffles the cards in the deck.
     * Preconditions: none.
     * Postconditions:
     *   The cards in the Deck are reordered randomly
     ****************************************************************/
    void Shuffle();

    /****************************************************************
     * DealCard:
     *   Deals out the next available Card in the Deck
     * Preconditions: there are cards left in the Deck
     *   (Should call CardsLeft() before this, to be safe.)
     * Postconditions:
     *   Returns: the next available card in the Deck.
     *   The returned Card is removed from the Deck.
     ****************************************************************/
    Card DealCard();

    /****************************************************************
     * CardsLeft:
     * Preconditions: none
     * Postconditions:
     *   Returns: the number of playable Cards left in the Deck.
     ****************************************************************/
    int CardsLeft();

private:
    Card operator[](int index);
    std::vector<Card> m_cards;
    int m_next;
};
#endif //DECK_H
