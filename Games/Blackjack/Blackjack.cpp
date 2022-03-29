#include "Blackjack.h"


bool Blackjack::playGame()
{
    m_playerBet = 0;
    m_playerTotal = 0;
    m_dealerTotal = 0;
    m_deck.shuffleDeck();

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
            showResultOfLose();

            if (checkPlayerBank())
                return false;

            return playAgain();
        }
    }

    while (m_dealerTotal < 17)
        dealCardToDealer();


    if (m_dealerTotal > 21)
    {
        showResultOfWin();

        return playAgain();
    }

    if (m_playerTotal > m_dealerTotal)
        showResultOfWin();

    else
    {
        showResultOfLose();

        if (checkPlayerBank())
            return false;
    }

    return playAgain();
}

char Blackjack::getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
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

bool Blackjack::playAgain()
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

void Blackjack::dealCardToPlayer(int count)
{
    for (int index = 0; index < count; ++index)
    {
        std::cout << "The dealer is showing: " << m_deck.getTopCard() << std::endl;
        m_playerTotal += m_deck.dealCard().getCardValue();
    }
    std::cout << "You have: " << m_playerTotal << " points" << '\n';
}

void Blackjack::dealCardToDealer()
{
    std::cout << "The dealer is showing: " << m_deck.getTopCard() << std::endl;
    m_dealerTotal += m_deck.dealCard().getCardValue();
    std::cout << "The dealer now has: " << m_dealerTotal << " points" << '\n';
}

void Blackjack::showResultOfWin()
{
    std::cout << "\nYou win!\n";
    m_playerBank += m_playerBet;
    std::cout << "You have " << m_playerBank << "$ in your bank\n";
}

void Blackjack::showResultOfLose()
{
    std::cout << "\nYou lose!\n";
    m_playerBank -= m_playerBet;
    std::cout << "You have " << m_playerBank << "$ in your bank\n";
}
