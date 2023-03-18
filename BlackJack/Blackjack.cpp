//File: Blackjack.cpp
//
//Implementation of Blackjack class.
//
//John Kallis

#include <iostream>
#include <vector>
#include "Blackjack.h"

//Hand.h Player.h and Deck.h and <vector>are included in Blackjak.h
//constructors
//
//Default Blackjack Constructor
Blackjack::Blackjack(){

	Player Jane;
	Deck m_deck;
    Player m_dealer;
    
 

}
//Standard Blackjack Constructor
Blackjack::Blackjack(char *names[], int numPlayers){

    for (int i = 0; i < numPlayers; ++i)
    {
    Player m_players(names[i]);
    }
}

int Blackjack::GetNumPlayers(){
	return m_players.size();
    
}
char *Blackjack::GetPlayerName(int player){
    return m_players[player].GetPlayer();

}

int Blackjack::GetPlayerFunds(int player){
    
    return m_players[player].GetChips();
}

void Blackjack::SetPlayerFunds(int player, int amt){
    m_players[player].SetChips(amt);

}

bool Blackjack::SetPlayerBet(int player, int amt){
    if (amt > m_players[player].GetChips())
    {
        return false;
    }
    else if (amt < 0){
        return false;
    }
    else{
        return true;
    }
}


void Blackjack::NewDeal(){
    Deck m_deck;
    m_deck.Shuffle();
    for (int i = 0; i < GetNumPlayers(); ++i){
            tempCard = m_deck.DealCard();
            m_players[i].AddCard(tempCard);   
    }
    for (int i = 0; i < GetNumPlayers(); ++i){
            tempCard = m_deck.DealCard();
            m_players[i].AddCard(tempCard);   
    }


}

void Blackjack::OutputPlayerHand(int player){
    m_players[player].AttachToHand1();
}

void Blackjack::OutputDealerHand(){
    cout<<"";
}

bool Blackjack::HitPlayer(int player){

    return true;}

    /*
    num1 = m_players[player].m_card.Value(0);
    if (num1 > 21)
    {
        cout<<"Busted"<<endl;
        return false;
    }
    else{
        tempCard = m_deck.DealCard();
        m_players[player].AddCard(tempCard);
        return 
    }
}
*/
void Blackjack::DealerPlay(){
    cout<<"";

}

int Blackjack::SettlePlayerBet(int player){
    return 0;
}
