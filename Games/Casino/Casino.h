#ifndef CPP_CARD_GAMES_CASINO_H
#define CPP_CARD_GAMES_CASINO_H

#include "../../Deck/Deck.h"

class Casino : public Deck
{
protected:
    std::array<Card, 3> m_playerCards;
    std::array<Card, 3> m_dealerCards;
    int m_playerTotal = 0;
    int m_dealerTotal = 0;
    int m_playerBet = 0;
    int m_playerBank = 100;

    explicit Casino(const int playerBank = 100, const int numberCards = 52) :
        m_playerBank(playerBank),
        Deck(numberCards)
    {}

    void getPlayerBet();

    virtual void makePlayerBet();

    virtual void makePlayerBet(int bet);

    [[nodiscard]] virtual bool checkPlayerBank() const;

    static bool playAgain();

    void reportWin();

    void reportLose();

    virtual void reportDraw();

    void resetCards();

    void showPlayerCards() const;

    void showDealerCards() const;

};


#endif
