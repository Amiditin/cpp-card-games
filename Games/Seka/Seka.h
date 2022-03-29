#ifndef BLACKJACK_SEKA_H
#define BLACKJACK_SEKA_H

#include "../../Betting/Betting.h"
#include "../../Deck/Deck.h"


class Seka : public Betting
{
private:
    Deck m_deck;
    int m_playerTotal = 0;
    int m_dealerTotal = 0;
    std::array<Card, 3> m_playerCards;
    std::array<Card, 3> m_dealerCards;

    static int getTotal(std::array<Card, 3> &cards);

    static bool playAgain();

    static char getPlayerChoice();

public:
    explicit Seka(const int playerBank = 100) : Betting(playerBank), m_deck(36) {}

    bool playGame();

    void dealCardToPlayers();

    void showPlayerCards() const;

    void showDealerCards() const;

    void showResultOfWin() const;

    void showResultOfLose() const;

    void showResultOfDraw() const;

};


#endif
