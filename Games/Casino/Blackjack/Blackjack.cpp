#include "Blackjack.h"


bool Blackjack::playGame()
{
    resetCards();
    shuffleDeck();

    makePlayerBet();

    dealCardToDealer();
    dealCardToPlayer(2);

    while (true)
    {
        if (getPlayerChoice() == 's')
            break;

        dealCardToPlayer();

        if (m_playerTotal > 21)
        {
            reportLose();

            if (checkPlayerBank())
                return false;

            return playAgain();
        }
    }

    while (m_dealerTotal < 17)
        dealCardToDealer();


    if (m_dealerTotal > 21 || m_playerTotal > m_dealerTotal)
        reportWin();
    else
    {
        reportLose();

        if (checkPlayerBank())
            return false;
    }

    return playAgain();
}

char Blackjack::getPlayerChoice()
{
    std::cout << "Your action: (h) to hit, or (s) to stand: ";
    char choice;

    while (true)
    {
        std::cin >> choice;
        std::cout << std::endl;
        std::cin.ignore(32767,'\n');

        if (choice == 'h' || choice == 's')
            break;

        std::cout << "Incorrect input, please try again. (h) to hit, or (s) to stand: ";
    }

    return choice;
}

void Blackjack::dealCardToPlayer(int count)
{
    for (int index = 0; index < count; ++index)
    {
        std::cout << "The dealer is showing: " << getTopCard() << std::endl;
        m_playerTotal += getTotal(dealCard());
    }
    std::cout << "You have: " << m_playerTotal << " points\n";
}

void Blackjack::dealCardToDealer()
{
    std::cout << "The dealer is showing: " << getTopCard() << std::endl;
    m_dealerTotal += getTotal(dealCard());
    std::cout << "The dealer now has: " << m_dealerTotal << " points\n";
}

int Blackjack::getTotal(const Card &card)
{
    switch (card.getCardRank())
    {
        case Card::RANK_2:		    return 2;
        case Card::RANK_3:		    return 3;
        case Card::RANK_4:		    return 4;
        case Card::RANK_5:		    return 5;
        case Card::RANK_6:		    return 6;
        case Card::RANK_7:		    return 7;
        case Card::RANK_8:		    return 8;
        case Card::RANK_9:		    return 9;
        case Card::RANK_10:
        case Card::RANK_JACK:
        case Card::RANK_QUEEN:
        case Card::RANK_KING:		return 10;
        case Card::RANK_ACE:		return 11;
    }

}
