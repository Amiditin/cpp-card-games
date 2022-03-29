#include "Seka.h"


bool Seka::playGame()
{
    if (m_playerBank < 10)
    {
        std::cout << "Unfortunately, you can't play any further, since your bank has less than $10. Come to us again.\n\n";
        return false;
    }

    m_playerBet = 0;
    m_deck.shuffleDeck();

    makePlayerBet(10);

    dealCardToPlayers();

    m_playerTotal = getTotal(m_playerCards);
    m_dealerTotal = getTotal(m_dealerCards);

    showPlayerCards();

    if (getPlayerChoice() == 'p')
    {
        showDealerCards();

        m_playerBank -= m_playerBet;
        showResultOfLose();

        if (checkPlayerBank())
            return false;

        return playAgain();
    }

    makePlayerBet();

    showDealerCards();

    if (m_playerTotal > m_dealerTotal)
    {
        m_playerBank += m_playerBet;
        showResultOfWin();
    }
    else if (m_playerTotal < m_dealerTotal)
    {
        m_playerBank -= m_playerBet;
        showResultOfLose();
        if (checkPlayerBank())
            return false;
    }
    else
        showResultOfDraw();

    return playAgain();
}

void Seka::dealCardToPlayers()
{
    for (int index = 0; index < 6; ++index)
    {
        if (index % 2 == 0)
            m_playerCards[index / 2] = m_deck.getTopCard();
        else
            m_dealerCards[index / 2] = m_deck.getTopCard();

        m_deck.dealCard();
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
    int cardValue1 = cards[0].getCardValue();
    int cardValue2 = cards[1].getCardValue();
    int cardValue3 = cards[2].getCardValue();

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

bool Seka::playAgain()
{
    std::cout << "Would you like to play again? (y) to Yes or (n) to No: ";
    while (true)
    {
        char choice;
        std::cin >> choice;
        std::cin.ignore(32767,'\n');

        switch (choice)
        {
            case 'y': std::cout << std::endl; return true;
            case 'n': std::cout << std::endl; return false;
            default:
                std::cout << "Incorrect input, please try again.\n (y) to Yes or (n) to No: ";
                continue;
        }
    }
}

void Seka::showPlayerCards() const
{
    std::cout << "Your cards: | ";
    for (auto & card : m_playerCards)
        std::cout << card << " | ";
    std::cout << std::endl;
    std::cout << "You have: " << m_playerTotal << " points\n\n";
}

void Seka::showDealerCards() const
{
    std::cout << "Dealer cards: | ";
    for (auto & card : m_dealerCards)
        std::cout << card << " | ";
    std::cout << std::endl;
    std::cout << "Dealer has: " << m_dealerTotal << " points\n\n";
}

void Seka::showResultOfWin() const
{
    std::cout << "You win!\n";
    std::cout << "You have " << m_playerBank << "$ in your bank\n\n";
}

void Seka::showResultOfLose() const
{
    std::cout << "You lose!\n";
    std::cout << "You have " << m_playerBank << "$ in your bank\n\n";
}

void Seka::showResultOfDraw() const
{
    std::cout << "Draw! Bets are refunded.\n";
    std::cout << "You have " << m_playerBank << "$ in your bank\n\n";
}

char Seka::getPlayerChoice() {
    std::cout << "(p) to pass, or (m) to make a bet: ";
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

