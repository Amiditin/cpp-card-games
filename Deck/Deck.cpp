#include "Deck.h"


void Deck::printDeck() const
{
    for (const auto &card : m_deck)
        std::cout << card << ' ';


    std::cout << "\nsize: " << m_deck.size() << "\n";
}

void Deck::shuffleDeck()
{
    for (auto & card : m_deck)
    {
        int swapIndex = getRandomNumber(0, m_deck.size() - 1);
        swapCard(card, m_deck[swapIndex]);
    }
    m_cardIndex = 0;
}

const Card& Deck::getTopCard() const
{
    return m_deck[m_cardIndex];
}

const Card& Deck::dealCard()
{
    return m_deck[m_cardIndex++];
}

int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::swapCard(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void Deck::fillDeck(const int startRank)
{
    for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
        for (int rank = startRank; rank < Card::CardRank::MAX_RANKS; ++rank)
            m_deck.emplace_back(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
}

int Deck::getCardIndex() const
{
    return m_cardIndex;
}
