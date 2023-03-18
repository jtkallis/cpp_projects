/*
 * CHANGES TO Blackjack.h SPEC:
 *   added new member funcs:
 *     char *GetPlayerName(int)
 *     int GetNumPlayers()
 *     void OutputDealerHand()
 *
 *   HitPlayer() should print out the card that was dealt.
 */
#include <cstdlib>
#include <iostream>
#include "Blackjack.h"

using namespace std;

Blackjack *CreateGame(int argc, char *argv[]);

int ProcessArgs(int argCnt, char *args[], char **&names, int *&funds);
void DoNewDeal(Blackjack &game);
void ProcAllBets(Blackjack &game);
void DoAllPlays(Blackjack &game);
void PlayOnePlayer(Blackjack &game, int player);
void SettleAllPlayers(Blackjack &game);
void ShowAllPlayerFunds(Blackjack &game);
bool QueryAnotherRound();


int main(int argc, char *argv[]) {
    Blackjack *game;
    int round;

    cout << "Welcome to CMSC 202 Blackjack!\n";
    game = CreateGame(argc, argv);


    round = 0;
    do {
	cout << "\nRound " << ++round << ":\n";
	ProcAllBets(*game);
	DoNewDeal(*game);
	DoAllPlays(*game);
	SettleAllPlayers(*game);
	ShowAllPlayerFunds(*game);
    } while (QueryAnotherRound());

    cout << "\nGoodbye!\n";
    return 0;
}


Blackjack *CreateGame(int argc, char *argv[]) {
    char **names;
    int *funds;
    int numPlayers;
    Blackjack *game;

    numPlayers = ProcessArgs(argc - 1, &argv[1], names, funds);
    game = new Blackjack(names, numPlayers);
    for (int p = 0; p < numPlayers; p++) {
	game->SetPlayerFunds(p, funds[p]);
    }
    return game;
}


int ProcessArgs(int argCnt, char *args[], char **&names, int *&funds) {
    int i, p;
    int numRecs = argCnt / 2;

    names = static_cast<char **>(calloc(numRecs, sizeof(char *)));
    funds = static_cast<int *>(calloc(numRecs, sizeof(int)));

    for (p = 0, i = 0; p < numRecs; p++) {
	names[p] = args[i++];
	funds[p] = atoi(args[i++]);
    }
    return p;
}


void ProcAllBets(Blackjack &game) {
    int numPlayers = game.GetNumPlayers();
    int bet;

    for (int p = 0; p < numPlayers; p++) {
        cout << "How much does " << game.GetPlayerName(p) << " bet? ";
	cin >> bet;
	cout << endl;  // For neat scripting
	if (!game.SetPlayerBet(p, bet)) {
	    cout << "Illegal bet--changing to $0\n";
	    game.SetPlayerBet(p, 0);
	}
    }
}


void DoNewDeal(Blackjack &game) {
    int numPlayers = game.GetNumPlayers();

    game.NewDeal();
    cout << "The players' hands:\n";
    for (int p = 0; p < numPlayers; p++) {
	cout << game.GetPlayerName(p) << ": ";
	game.OutputPlayerHand(p);
	cout << endl;
    }
    cout << "Dealer: ";
    game.OutputDealerHand();  // This hides dealer's hole card
    cout << "\n\n";
}


void DoAllPlays(Blackjack &game) {
    int numPlayers = game.GetNumPlayers();
    int p;

    for (p = 0; p < numPlayers; p++) {
	PlayOnePlayer(game, p);
    }
    game.DealerPlay();
}

void PlayOnePlayer(Blackjack &game, int player) {
    char *name = game.GetPlayerName(player);
    string answer;
    bool hit, busted;

    cout << ">>" << name << "'s turn:\n";
    busted = false;
    do {
	cout << "Hand: ";
	game.OutputPlayerHand(player);
	cout << endl;

	cout << name << "'s play: ";
	cin >> answer;
	cout << endl;  // For neat scripting
	answer[0] == 'y' || answer[0] == 'Y';
	hit = (answer[0] == 'h' || answer[0] == 'H');
	if (hit) {
	    busted = game.HitPlayer(player);
	}
    } while (hit && !busted);
    if (busted) {
	cout << "Busted!\n";
    }
    cout << endl;
}

void SettleAllPlayers(Blackjack &game) {
    int numPlayers = game.GetNumPlayers();
    int p;

    for (p = 0; p < numPlayers; p++) {
	game.SettlePlayerBet(p);
	// Above should print out:
	//  Joe has busted--Dealer wins", or "Sally has 15--Dealer loses"
    }
    cout << endl;
}

void ShowAllPlayerFunds(Blackjack &game) {
    int numPlayers = game.GetNumPlayers();
    int p;

    for (p = 0; p < numPlayers; p++) {
	cout << game.GetPlayerName(p) << " now has $"
	     << game.GetPlayerFunds(p) << endl;
    }
    cout << endl;
}

bool QueryAnotherRound() {
    string answer;

    cout << "Another round? ";
    cin >> answer;
    cout << endl;  // For neat scripting
    return answer[0] == 'y' || answer[0] == 'Y';
}
