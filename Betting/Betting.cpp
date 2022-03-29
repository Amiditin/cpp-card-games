#include "Betting.h"

void Betting::getPlayerBet()
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
            break;
        }
    }
}

void Betting::makePlayerBet()
{
    std::cout << "You have $" << m_playerBank << " in your bank. Your current bet is $"<< m_playerBet << ".\n";
    getPlayerBet();
    std::cout << std::endl;
}

void Betting::makePlayerBet(const int bet)
{
    std::cout << "You have " << m_playerBank << "$ in your bank\n";
    std::cout << "The base bet is $" << bet << " before the start of the round.\n";
    m_playerBet += bet;
    std::cout << std::endl;
}

bool Betting::checkPlayerBank() const
{
    if (m_playerBank == 0)
    {
        std::cout << "Unfortunately you can't play on. Come to us again.\n\n";
        return true;
    }

    return false;
}

