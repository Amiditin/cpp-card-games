#include <iostream>
#include "Card.h"


int Card::getCardValue() const
{
    switch (m_rank)
    {
        case RANK_2:		return 2;
        case RANK_3:		return 3;
        case RANK_4:		return 4;
        case RANK_5:		return 5;
        case RANK_6:		return 6;
        case RANK_7:		return 7;
        case RANK_8:		return 8;
        case RANK_9:		return 9;
        case RANK_10:
        case RANK_JACK:
        case RANK_QUEEN:
        case RANK_KING:		return 10;
        case RANK_ACE:		return 11;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Card &card) {
    switch (card.m_rank)
    {
        case Card::RANK_2:		std::cout << "2"; break;
        case Card::RANK_3:		std::cout << "3"; break;
        case Card::RANK_4:		std::cout << "4"; break;
        case Card::RANK_5:		std::cout << "5"; break;
        case Card::RANK_6:		std::cout << "6"; break;
        case Card::RANK_7:		std::cout << "7"; break;
        case Card::RANK_8:		std::cout << "8"; break;
        case Card::RANK_9:		std::cout << "9"; break;
        case Card::RANK_10:		std::cout << "10"; break;
        case Card::RANK_JACK:   std::cout << "Jack"; break;
        case Card::RANK_QUEEN:  std::cout << "Queen"; break;
        case Card::RANK_KING:	std::cout << "King"; break;
        case Card::RANK_ACE:	std::cout << "Ace"; break;
    }
    switch (card.m_suit)
    {
        case Card::SUIT_CLUB:		std::cout << " of Clubs"; break;
        case Card::SUIT_DIAMOND:	std::cout << " of Diamonds"; break;
        case Card::SUIT_HEART:	std::cout << " of Hearts"; break;
        case Card::SUIT_SPADE:	std::cout << " of Spades"; break;
    }

    return out;
}

Card::CardSuit Card::getCardSuit()
{
    return m_suit;
}

Card::CardRank Card::getCardRank()
{
    return m_rank;
}


