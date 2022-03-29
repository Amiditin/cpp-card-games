#include "Seka.h"


bool Seka::playGame()
{
    resetCards();
    shuffleDeck();

    makePlayerBet(10);
    dealCardToPlayers();

    m_playerTotal = getTotal(m_playerCards);
    m_dealerTotal = getTotal(m_dealerCards);

    showPlayerCards();

    if (getPlayerChoice() == 'p')
    {
        showDealerCards();
        reportLose();

        if (checkPlayerBank())
            return false;

        return playAgain();
    }

    makePlayerBet();
    showDealerCards();

    if (m_playerTotal < m_dealerTotal)
    {
        reportLose();
        if (checkPlayerBank())
            return false;
    }
    else if (m_playerTotal == m_dealerTotal)
        reportDraw();
    else
        reportWin();

    return playAgain();
}

void Seka::dealCardToPlayers()
{
    for (int index = 0; index < 6; ++index)
    {
        if (index % 2 == 0)
            m_playerCards[index / 2] = getTopCard();
        else
            m_dealerCards[index / 2] = getTopCard();

        dealCard();
    }
}

int Seka::getTotal(std::array<Card, 3> &cards)
{
    Card::CardSuit cardSuit1 = cards[0].getCardSuit();
    Card::CardSuit cardSuit2 = cards[1].getCardSuit();
    Card::CardSuit cardSuit3 = cards[2].getCardSuit();
    Card::CardRank cardRank1 = cards[0].getCardRank();
    Card::CardRank cardRank2 = cards[1].getCardRank();
    Card::CardRank cardRank3 = cards[2].getCardRank();
    int cardValue1 = getCardValue(cards[0]);
    int cardValue2 = getCardValue(cards[1]);
    int cardValue3 = getCardValue(cards[2]);

    if (cardRank1 == cardRank2 && cardRank2 == cardRank3)
        switch (cardRank1)
        {
            case Card::RANK_7:      return 32;
            case Card::RANK_8:      return 33;
            case Card::RANK_9:      return 34;
            case Card::RANK_10:     return 35;
            case Card::RANK_JACK:   return 36;
            case Card::RANK_QUEEN:  return 37;
            case Card::RANK_KING:   return 38;
            case Card::RANK_ACE:    return 39;
            case Card::RANK_6:      return 40;
        }
    else if ((cardValue1 == 11 && cardValue2 == 11) ||
        (cardValue1 == 11 && cardValue3 == 11) ||
        (cardValue2 == 11 && cardValue3 == 11))
        return 22;
    else if (cardSuit1 == cardSuit2 && cardSuit1 == cardSuit3)
        return cardValue1 + cardValue2 + cardValue3;
    else if (cardSuit1 == cardSuit2)
        return cardValue1 + cardValue2;
    else if (cardSuit1 == cardSuit3)
        return cardValue1 + cardValue3;
    else if (cardSuit2 == cardSuit3)
        return cardValue2 + cardValue3;
    else
    {
        if (cardValue1 >= cardValue2 && cardValue1 >= cardValue3)
            return cardValue1;
        else if (cardValue2 >= cardValue3)
            return cardValue2;
        else
            return cardValue3;
    }

    return -2;
}

char Seka::getPlayerChoice() {
    std::cout << "Your action: (p) to pass, or (m) to make a bet: ";
    char choice;

    while (true)
    {
        std::cin >> choice;
        std::cout << std::endl;
        std::cin.ignore(32767,'\n');

        if (choice == 'p' || choice == 'm')
            break;

        std::cout << "Incorrect input, please try again. (p) to pass, or (m) to make a bet: ";
    }

    return choice;
}

bool Seka::checkPlayerBank() const
{
    if (m_playerBank < 10)
    {
        std::cout << "Unfortunately, you can't play any further, since your bank has less than $10. Come to us again.\n\n";
        return true;
    }

    return false;
}

int Seka::getCardValue(const Card &card)
{
    switch (card.getCardRank())
    {
        case Card::RANK_2:		return 2;
        case Card::RANK_3:		return 3;
        case Card::RANK_4:		return 4;
        case Card::RANK_5:		return 5;
        case Card::RANK_6:		return 6;
        case Card::RANK_7:		return 7;
        case Card::RANK_8:		return 8;
        case Card::RANK_9:		return 9;
        case Card::RANK_10:
        case Card::RANK_JACK:
        case Card::RANK_QUEEN:
        case Card::RANK_KING:		return 10;
        case Card::RANK_ACE:		return 11;
    }
    return 0;
}

