#ifndef BLACKJACK_BACCARAT_H
#define BLACKJACK_BACCARAT_H

#include "../../Betting/Betting.h"
#include "../../Deck/Deck.h"


class Baccarat : public Betting
{
private:
    Deck m_deck;
    int m_playerTotal = 0;
    int m_dealerTotal = 0;

public:
    explicit Baccarat(const int playerBank = 100) : Betting(playerBank), m_deck(104) {};

    bool playGame();
};


#endif
