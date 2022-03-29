#include "Casino.h"


void Casino::getPlayerBet()
{
    while (true)
    {
        std::cout << "Please make your bet: ";
        int playerBet;
        std::cin >> playerBet;

        if (std::cin.fail() || playerBet <= 0)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "\nUnfortunately, you entered an incorrect number.  Please try again.\n\n";
        }
        else if (m_playerBet + playerBet > m_playerBank)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "\nYou cannot make a bet more than in your bank.  Please try again.\n\n";
        }
        else
        {
            std::cin.ignore(32767,'\n');
            m_playerBet += playerBet;

            std::cout << std::endl;
            break;
        }
    }
}

void Casino::makePlayerBet()
{
    std::cout << "You have $" << m_playerBank << " in your bank.\n";
    getPlayerBet();
}

void Casino::makePlayerBet(const int bet)
{
    std::cout   << "You have " << m_playerBank << "$ in your bank\n"
                << "The base bet is $" << bet << " before the start of the round.\n\n";
    m_playerBet += bet;
}

bool Casino::checkPlayerBank() const
{
    if (m_playerBank == 0)
    {
        std::cout << "Unfortunately you can't play on. Come to us again.\n\n";
        return true;
    }

    return false;
}

void Casino::reportWin()
{
    m_playerBank += m_playerBet;
    std::cout << "\nYou win! \nYou have " << m_playerBank << "$ in your bank\n";
}

void Casino::reportLose()
{
    m_playerBank -= m_playerBet;
    std::cout << "\nYou lose! \nYou have " << m_playerBank << "$ in your bank\n";
}

void Casino::reportDraw()
{
    std::cout << "\nDraw! \nYou have " << m_playerBank << "$ in your bank\n";
}

bool Casino::playAgain()
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

void Casino::resetCards()
{
    for (auto &card : m_playerCards)
        card = Card();
    for (auto &card : m_dealerCards)
        card = Card();
    m_playerTotal = 0;
    m_dealerTotal = 0;
    m_playerBet = 0;
}

void Casino::printDeck() const
{
    m_deck.printDeck();
}

void Casino::showPlayerCards() const
{
    std::cout << "Your cards:    ";
    for (auto & card : m_playerCards)
        std::cout << card << "  ";
    std::cout << "\nYou have: " << m_playerTotal << " points\n\n";
}

void Casino::showDealerCards() const
{
    std::cout << "Dealer cards:  ";
    for (auto & card : m_dealerCards)
        std::cout << card << "  ";
    std::cout << "\nDealer has: " << m_dealerTotal << " points\n\n";
}

int Casino::getCardIndex() const
{
    return m_deck.getCardIndex();
}

const Card &Casino::dealCard()
{
    return m_deck.dealCard();
}

const Card &Casino::getTopCard() const
{
    return m_deck.getTopCard();
}

void Casino::shuffleDeck()
{
    m_deck.shuffleDeck();
}