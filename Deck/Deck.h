#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <array>
#include <vector>
#include <cstdlib>
#include <cassert>

#include <iostream>

#include "..//Card/Card.h"

class Deck
{
private:
    std::vector<Card> m_deck;

    int m_cardIndex = 0;

    static int getRandomNumber(int min, int max);

    static void swapCard(Card &card1, Card &card2);

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

    void fillDeck(const int startRank)
    {
        for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
            for (int rank = startRank; rank < Card::CardRank::MAX_RANKS; ++rank)
                m_deck.emplace_back(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
    }

    void printDeck() const;

    void shuffleDeck();

    const Card& getTopCard() const;

    const Card& dealCard();
};


#endif
