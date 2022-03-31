#ifndef BLACKJACK_SEKA_H
#define BLACKJACK_SEKA_H

#include "../Casino.h"


class Seka : public Casino
{
private:
    static int getTotal(std::array<Card, 3> &cards);

    static int getCardValue(const Card& card);

    static char getPlayerChoice();

    void dealCardToPlayers();

    [[nodiscard]] bool checkPlayerBank() const override;

    void makePlayerBet() override;

    void makePlayerBet(int bet) override;


public:
    explicit Seka(const int playerBank = 100) : Casino(playerBank, 36) {}

    bool playGame();

    [[maybe_unused]] bool playTestGames(int numberTests);
};


#endif
