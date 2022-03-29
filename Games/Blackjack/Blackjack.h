#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include "../../Betting/Betting.h"
#include "../../Deck/Deck.h"


class Blackjack : public Betting
{
private:
    Deck m_deck;
    int m_playerTotal = 0;
    int m_dealerTotal = 0;

    static char getPlayerChoice();

    static bool playAgain();


public:
    explicit Blackjack(const int playerBank = 100) : Betting(playerBank) {}

    void dealCardToPlayer(int count = 1);

    void dealCardToDealer();

    bool playGame();

    void showResultOfWin();

    void showResultOfLose();
};


#endif
