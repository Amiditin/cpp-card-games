#include "Card.h"


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
        case Card::RANK_JACK:   std::cout << "J"; break;
        case Card::RANK_QUEEN:  std::cout << "Q"; break;
        case Card::RANK_KING:	std::cout << "K"; break;
        case Card::RANK_ACE:	std::cout << "A"; break;
    }
    switch (card.m_suit)
    {
        case Card::SUIT_HEART:	    std::cout << (char)3; break;
        case Card::SUIT_DIAMOND:	std::cout << (char)4; break;
        case Card::SUIT_CLUB:		std::cout << (char)5; break;
        case Card::SUIT_SPADE:	    std::cout << (char)6; break;
    }

    return out;
}

Card::CardSuit Card::getCardSuit()
{
    return m_suit;
}

Card::CardRank Card::getCardRank() const
{
    return m_rank;
}


