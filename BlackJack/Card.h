/****************************************************************
 * File:    Card.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  John Park
 * Date:    3/10/14
 * Section: all
 * E-mail:  park@umbc.edu 
 *
 *   This file contains the declaration for the Card class.
 *   The class implements a playing card.
 *   It is specialized for Blackjack, having a method for returning
 *   the numerical value of the card in a blackjack hand.
 *
 ****************************************************************/

#ifndef CARD_H
#define CARD_H

enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	   JACK, QUEEN, KING, RANK_END};

enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS, SUIT_END};

class Card {
public:
    /****************************************************************
     * Card:
     *   default (no-arg) constructor
     * Preconditions: none.
     * Postconditions: returns a dummy card;
     ****************************************************************/
    Card();

    /****************************************************************
     * Card:
     *   Standard constructor
     * Preconditions:
     *   rank -- specifies desired Rank for card
     *   suit -- specifies desired Suit for card
     * Postconditions: constructs a card with desired Rank and Suit
     ****************************************************************/
    Card(enum Rank rank, enum Suit suit);

    /****************************************************************
     * GetRank:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the Rank of the card
     ****************************************************************/
    enum Rank GetRank();

    /****************************************************************
     * GetSuit:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the Suit of the card
     ****************************************************************/
    enum Suit GetSuit();

    /****************************************************************
     * GetBlackjackValue:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the value of the Card for a Blackjack game;
     *     1-10: face value; Jack, Queen, Kind: 10; Ace: 1
     ****************************************************************/
    int GetBlackjackValue();

    /****************************************************************
     * OutputCard
     *   Display out a nice representation of the card
     * Preconditions: none.
     * Postconditions:
     *   Outputs a human-friendly representation of the card to cout.
     *   It should display something like: "Ace of Spades"
     *   Note: just display card; no labels or leading or trailing spaces
     *     or newlines
     ****************************************************************/
    void OutputCard();

    /****************************************************************
     * GetAllSuits:
     *   NOT INTENDED FOR USE BY STUDENTS
     * Preconditions: none.
     * Postconditions:
     *   Returns: a complete enumeration of all the Suits, plus a
     *     sentinel value at the end, useful for generating a Deck
     ****************************************************************/
    static const enum Suit *GetAllSuits() { return m_allSuits; }

    /****************************************************************
     * GetAllRanks:
     *   NOT INTENDED FOR USE BY STUDENTS
     * Preconditions: none.
     * Postconditions:
     *   Returns: a complete enumeration of all the Ranks, plus a
     *     sentinel value at the end, useful for generating a Deck
     ****************************************************************/
    static const enum Rank *GetAllRanks() { return m_allRanks; }
private:
    enum Rank m_rank;
    enum Suit m_suit;

    static enum Suit m_allSuits[];
    static const char *m_suitNames[];
    static enum Rank m_allRanks[];
};

#endif //CARD_H
