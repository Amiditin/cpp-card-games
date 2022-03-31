#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <array>
#include <vector>
#include <cstdlib>
#include <cassert>

#include "..//Card/Card.h"

class Deck
{
protected:
    std::vector<Card> m_deck;

    int m_cardIndex = 0;

    static int getRandomNumber(int min, int max);

    static void swapCard(Card &card1, Card &card2);

    void fillDeck(int startRank);

    void printDeck() const;

    void shuffleDeck();

    [[nodiscard]] const Card& getTopCard() const;

    [[nodiscard]] int getCardIndex() const;

    const Card& dealCard();

public:
    explicit Deck(const int numberCards = 52)
    {
        int startRank = 0;
        if (numberCards == 36)
            startRank = 4;

        fillDeck(startRank);

        if (numberCards == 104)
            fillDeck(startRank);
    }

};


#endif
