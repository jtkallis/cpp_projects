#include <iostream>
#include "Card.h"

using namespace std;

enum Suit Card::m_allSuits[] = {SPADES, HEARTS, CLUBS, DIAMONDS, SUIT_END};
const char *Card::m_suitNames[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
enum Rank Card::m_allRanks[] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		   JACK, QUEEN, KING, RANK_END};

Card::Card() {
}

Card::Card(enum Rank rank, enum Suit suit)
    : m_rank(rank), m_suit(suit) {
}

enum Rank Card::GetRank() {
    return m_rank;
}

int Card::GetBlackjackValue() {
    int val;

    switch(m_rank) {
    case JACK:
    case QUEEN:
    case KING:
	val = 10;
	break;
    default:
	val = static_cast<int>(m_rank);
    }
    return val;
}

enum Suit Card::GetSuit() {
    return m_suit;
}

void Card::OutputCard() {
    switch(m_rank) {
    case JACK:
	cout << "Jack";
	break;
    case QUEEN:
	cout << "Queen";
	break;
    case KING:
	cout << "King";
	break;
    case ACE:
	cout << "Ace";
	break;
    default:
	cout << m_rank;
	break;
    }
    cout << " of " << m_suitNames[m_suit];
}

