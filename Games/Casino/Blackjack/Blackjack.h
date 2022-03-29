#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include "../Casino.h"


class Blackjack : public Casino
{
private:
    static char getPlayerChoice();

    static int getTotal(const Card &card);

    void dealCardToPlayer(int count = 1);

    void dealCardToDealer();

public:
    explicit Blackjack(const int playerBank = 100) : Casino(playerBank) {}

    bool playGame();
};


#endif
