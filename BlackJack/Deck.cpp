#include <iostream>
#include <cstdlib>
#include "Deck.h"

using namespace std;

/*
 * Default constructor: create a standard deck with 52 cards
 */
Deck::Deck()
    : m_next(0) {
    const enum Suit *allSuits = Card::GetAllSuits();
    const enum Rank *allRanks = Card::GetAllRanks();
    int s, r;

    for (s = 0; allSuits[s] != SUIT_END; s++) {
	for (r = 0; allRanks[r] != RANK_END; r++) {
	    m_cards.push_back(Card(allRanks[r], allSuits[s]));
	}
    }
}

Deck::Deck(Card cards[]) {
}

Deck::Deck(vector<Card> cards) {
}

void Deck::Shuffle() {
    Card tmpC;
    int r;

    for (int n = m_cards.size() - 1; n > 0; n--) {
	// rand == n: card stays put
	r = rand() % (n + 1);
	tmpC = m_cards[r];
	m_cards[r] = m_cards[n];
	m_cards[n] = tmpC;
    }
    m_next = 0;
}

Card Deck::DealCard() {
    // Should really throw exception on out-of-bounds--but students
    // don't know how to handle that yet!
    return(m_cards[m_next++]);
}

int Deck::CardsLeft() {
    return m_cards.size() - m_next;
}

Card Deck::operator[](int index) {
    return m_cards[m_next + index];

}
