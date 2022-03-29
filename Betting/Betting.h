#ifndef BLACKJACK_BETTING_H
#define BLACKJACK_BETTING_H

#include <iostream>

class Betting
{
protected:
    int m_playerBet = 0;
    int m_playerBank = 100;

public:
    explicit Betting(const int playerBank = 100) : m_playerBank(playerBank) {}

    void getPlayerBet();

    void makePlayerBet();

    void makePlayerBet(int bet);

    bool checkPlayerBank() const;
};


#endif //BLACKJACK_BETTING_H
