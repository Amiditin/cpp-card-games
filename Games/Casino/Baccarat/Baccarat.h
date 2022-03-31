#ifndef BLACKJACK_BACCARAT_H
#define BLACKJACK_BACCARAT_H

#include "../Casino.h"


class Baccarat : public Casino
{
private:
    char m_choice = 'p';

    void getPlayerChoice();

    void dealCardToPlayers();

    void dealThirdCard(std::array<Card, 3>& cards, int& total);

    int getCardValue(const Card& card);

    void reportDraw() override;

    bool calculateResult();


public:
    explicit Baccarat(const int playerBank = 100) : Casino(playerBank, 104)
    {
        shuffleDeck();
    };

    bool playGame();

    [[maybe_unused]] bool playTestGames(int numberTests);
};


#endif
