/****************************************************************
 * File:    Blackjack.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  John Park
 * Date:    3/10/14
 * Section: all
 * E-mail:  park@umbc.edu 
 *
 *   This file contains the declaration for the Blackjack class.
 *   The class manages and implements the mechanics for a multi-player
 *   version of the Blackjack/21 program, including bets.
 *
 ****************************************************************/

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include "Player.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"

//using namespace std;

class Blackjack {
  public:
    /****************************************************************
     * Name: Blackjack
     *   default (no-arg) constructor
     * Preconditions: none.
     * Postconditions:
     *   Sets up a game with one player: "Jane", starting with $100
     ****************************************************************/
    Blackjack();

    /****************************************************************
     * Name: Blackjack
     *   Standard constructor
     * Preconditions:
     *   names -- an array of names specifying the players
     *   numPlayers -- the length of the array "names"
     * Postconditions:
     *   Sets up a game with the specified collection of players
     *   Each player is given a default $100 in funds
     ****************************************************************/
    Blackjack(char *names[], int numPlayers);

    /****************************************************************
     * GetNumPlayers:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the number of players registered for the game
     ****************************************************************/
    int GetNumPlayers();

    /****************************************************************
     * GetPlayerName:
     * Preconditions:
     *   player -- the index of the requested player
     * Postconditions:
     *   Returns: the given player's name
     ****************************************************************/
    char *GetPlayerName(int player);

    /****************************************************************
     * GetPlayerFunds
     *   Return the given player's pool of available funds
     * Preconditions:
     *   player -- the index of the requested player
     * Postconditions:
     *   Returns: The amount of funds the player currently has remaining
     ****************************************************************/
    int GetPlayerFunds(int player);

    /****************************************************************
     * SetPlayerFunds:
     *   Initialize a players funds for betting
     * Preconditions:
     *   player -- the index of the requested player
     *   amt -- the amount of money player's funds should be set to
     * Postconditions:
     *   Sets the given player's pool of funds available for betting
     ****************************************************************/
    void SetPlayerFunds(int player, int amt);

    /****************************************************************
     * SetPlayerBet:
     *   Set how much the player wants to bet in current round.
     * Preconditions:
     *   player -- the index of the requested player
     *   amt -- the amount of money player wants to bet;
     *     must be compared against available funds, and rejected
     *     if funds are insufficient.
     * Postconditions:
     *   amount of bet is recorded for the player
     *   Returns: true if bet is valid; false if insufficient funds.
     ****************************************************************/
    bool SetPlayerBet(int player, int amt);

    /****************************************************************
     * NewDeal:
     *   Deals out cards in preparation for new round
     * Preconditions: none.
     * Postconditions:
     *   Creates a fresh Deck, shuffles it, and deals out 2 cards
     *   to each player and the dealer, going around the circle
     *   one card at a time (like most card games).
     ****************************************************************/
    void NewDeal();

    /****************************************************************
     * OutputPlayerHand:
     *   Displays a player's hand.
     * Preconditions: none.
     *   player -- the index of the requested player
     * Postconditions:
     *   Output the requested player's hand to cout, as a comma-separated
     *   list of cards.  So, it should display something like:
     *   "Ace of Spades, 3 of Diamonds, 5 or Hearts"
     *   Note: just display cards; no label at start, no endl at end.
     ****************************************************************/
    void OutputPlayerHand(int player);

    /****************************************************************
     * OutputDealerHand:
     *   Displays dealer's hand.
     * Preconditions: none.
     * Postconditions:
     *   Output the dealer's hand to cout, hiding the hole card (the
     *   second card).  So, it should display something like:
     *   "Ace of Spades, [hidden card]"
     *   Note: just display cards; no label at start, no endl at end.
     ****************************************************************/
    /*
     * Parameters: none.
     */
    void OutputDealerHand();

    /****************************************************************
     * HitPlayer:
     *   Deal the player another card.
     * Preconditions:
     *   player -- the index of the requested player
     *   Player must not have gone bust earlier; this is a precondition
     *   you are required to check for!
     * Postconditions:
     *   Prints out the new card that was dealt to the player.
     *   Returns: true if player is busted due to new card; false otherwise.
     *   (HINT: it would probably be helpful to record that the player went
     *    bust in some object.)
     ****************************************************************/
    bool HitPlayer(int player);

    /****************************************************************
     * DealerPlay
     *   Loop, continuously dealing cards to the Dealer's hand until she stops
     *   because she has 17 or higher.  Output each card that the dealer is
     *   dealt, and display the resulting hand each round, just like main()
     *   does for the players (must do that in here because main() only sees
     *   final result).
     * Preconditions: none.
     * Postconditions:
     *   Dealer might have gone bust, or might have blackjack (in which
     *   case no cards were taken.)
     ****************************************************************/
    void DealerPlay();

    /****************************************************************
     * SettlePlayerbet:
     *   At end of round, settle bet for given player:
     *   Compare player's hand to dealer's hand, decide who wins,
     *   then settle bet accordingly by updating the player's funds
     *   based on their bet, outputting results.
     *   Should also zero out the bet in preparation for the next round.
     * Preconditions:
     *   player -- the index of the requested player
     * Postconditions:
     *   Updates the player's funds, by adding or subtracting bet.
     *   Print out player's card total (number, "busted", or "blackjack"),
     *     and the winner ("Joe wins" or "Dealer wins" or "tie").
     *     Examples:
     *       "Joe has busted--Dealer wins", or
     *       "Sally has 21--Sally wins", or
     *     or "Sally has blackjack--tie" if dealer also had blackjack.
     *   Clears the bet amount.
     *   Returns: 0  (return value not really used yet)
     ****************************************************************/
    int SettlePlayerBet(int player);

  private:

    /*
     * ADD YOUR DATA MEMBERS HERE
     * NOTE: The following are just examples; replace them with your own
     */

    Deck m_deck;
    std::vector<Player> m_players;
    Player m_dealer;
    Card tempCard;
    //int num1;


};

#endif //BLACKJACK_H

