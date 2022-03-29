#ifndef CPP_CARD_GAMES_CASINO_H
#define CPP_CARD_GAMES_CASINO_H

#include "../../Deck/Deck.h"

class Casino
{
private:
    Deck m_deck;

protected:
    std::array<Card, 3> m_playerCards;
    std::array<Card, 3> m_dealerCards;
    int m_playerTotal = 0;
    int m_dealerTotal = 0;
    int m_playerBet = 0;
    int m_playerBank = 100;

    explicit Casino(const int playerBank = 100, const int numberCards = 52) :
        m_playerBank(playerBank),
        m_deck(numberCards)
    {}

    void getPlayerBet();

    void makePlayerBet();

    void makePlayerBet(int bet);

    [[nodiscard]] virtual bool checkPlayerBank() const;

    static bool playAgain();

    void shuffleDeck();

    [[nodiscard]] const Card& getTopCard() const;

    [[nodiscard]] int getCardIndex() const;

    void printDeck() const;

    const Card& dealCard();

    void reportWin();

    void reportLose();

    virtual void reportDraw();

    void resetCards();

    void showPlayerCards() const;

    void showDealerCards() const;

};


#endif
