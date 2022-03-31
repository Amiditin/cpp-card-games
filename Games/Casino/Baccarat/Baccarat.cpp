#include "Baccarat.h"

bool Baccarat::playGame()
{
    if (getCardIndex() > 96)
        shuffleDeck();

    resetCards();

    getPlayerChoice();
    makePlayerBet();

    dealCardToPlayers();

    if (m_playerTotal > 7 || m_dealerTotal > 7)
    {
        showPlayerCards();
        showDealerCards();
        return calculateResult();
    }

    if (m_playerTotal < 6)
        dealThirdCard(m_playerCards, m_playerTotal);


    switch (m_dealerTotal)
    {
        case 0:
        case 1:
        case 2: dealThirdCard(m_dealerCards, m_dealerTotal); break;
        case 3:
            if (getCardValue(m_playerCards[2]) != 8)
                dealThirdCard(m_dealerCards, m_dealerTotal);
            break;
        case 4:
            if (getCardValue(m_playerCards[2]) > 1 && getCardValue(m_playerCards[2]) < 8)
                dealThirdCard(m_dealerCards, m_dealerTotal);
            break;
        case 5:
            if (getCardValue(m_playerCards[2]) < 4 || getCardValue(m_playerCards[2]) > 7)
                dealThirdCard(m_dealerCards, m_dealerTotal);
            break;
        case 6:
            if (getCardValue(m_playerCards[2]) < 6 || getCardValue(m_playerCards[2]) > 7)
                dealThirdCard(m_dealerCards, m_dealerTotal);
            break;
    }

    showPlayerCards();
    showDealerCards();

    return calculateResult();
}

void Baccarat::getPlayerChoice()
{
    std::cout << "Please choose who you want to bet: (p) on player, (d) on dealer, (t) on a tie: ";

    while (true)
    {
        std::cin >> m_choice;
        std::cout << std::endl;
        std::cin.ignore(32767,'\n');

        if (m_choice == 'p' || m_choice == 'd' || m_choice == 't')
            break;

        std::cout << "Incorrect input, please try again. (p) on player, (d) on dealer, (t) on a tie: ";
    }
}

void Baccarat::dealCardToPlayers()
{
    for (int index = 0; index < 4; ++index)
    {
        if (index % 2 == 0)
        {
            m_playerCards[index / 2] = getTopCard();
            m_playerTotal += getCardValue(dealCard());
        }
        else
        {
            m_dealerCards[index / 2] = getTopCard();
            m_dealerTotal += getCardValue(dealCard());
        }
    }
    m_playerTotal %= 10;
    m_dealerTotal %= 10;
}

int Baccarat::getCardValue(const Card &card)
{
    switch (card.getCardRank())
    {
        case Card::RANK_10:
        case Card::RANK_JACK:
        case Card::RANK_QUEEN:
        case Card::RANK_KING:		return 0;
        case Card::RANK_ACE:		return 1;
        case Card::RANK_2:		    return 2;
        case Card::RANK_3:		    return 3;
        case Card::RANK_4:		    return 4;
        case Card::RANK_5:		    return 5;
        case Card::RANK_6:		    return 6;
        case Card::RANK_7:		    return 7;
        case Card::RANK_8:		    return 8;
        case Card::RANK_9:		    return 9;
    }
}

void Baccarat::reportDraw()
{
    m_playerBank += m_playerBet * 9;
    std::cout << "\nYou win! \nYou have $" << m_playerBank << " in your bank\n";
}

bool Baccarat::calculateResult()
{
    switch (m_choice)
    {
        case 'p':
            if (m_playerTotal > m_dealerTotal)
                reportWin();
            else {
                reportLose();
                if(checkPlayerBank())
                    return false;
            }
            break;
        case 'd':
            if (m_playerTotal < m_dealerTotal)
                reportWin();
            else {
                reportLose();
                if(checkPlayerBank())
                    return false;
            }
            break;
        case 't':
            if (m_playerTotal == m_dealerTotal)
                reportDraw();
            else {
                reportLose();
                if(checkPlayerBank())
                    return false;
            }
            break;
    }
    return playAgain();
}

void Baccarat::dealThirdCard(std::array<Card, 3> &cards, int &total)
{
    cards[2] = getTopCard();
    total += getCardValue(dealCard());
    total %= 10;
}

bool Baccarat::playTestGames(int numberTests)
{
    for (int number = 0; number < numberTests; ++number)
    {
        std::cout << "\n\nGame " << number + 1 << std::endl;
        if (getCardIndex() > 96)
            shuffleDeck();

        resetCards();

        dealCardToPlayers();

        if (m_playerTotal > 7 || m_dealerTotal > 7)
        {
            showPlayerCards();
            showDealerCards();

            if (m_playerTotal > m_dealerTotal)
                reportWin();
            else
                reportLose();
            continue;
        }

        if (m_playerTotal < 6)
            dealThirdCard(m_playerCards, m_playerTotal);


        switch (m_dealerTotal)
        {
            case 0:
            case 1:
            case 2: dealThirdCard(m_dealerCards, m_dealerTotal); break;
            case 3:
                if (getCardValue(m_playerCards[2]) != 8)
                    dealThirdCard(m_dealerCards, m_dealerTotal);
                break;
            case 4:
                if (getCardValue(m_playerCards[2]) > 1 && getCardValue(m_playerCards[2]) < 8)
                    dealThirdCard(m_dealerCards, m_dealerTotal);
                break;
            case 5:
                if (getCardValue(m_playerCards[2]) < 4 || getCardValue(m_playerCards[2]) > 7)
                    dealThirdCard(m_dealerCards, m_dealerTotal);
                break;
            case 6:
                if (getCardValue(m_playerCards[2]) < 6 || getCardValue(m_playerCards[2]) > 7)
                    dealThirdCard(m_dealerCards, m_dealerTotal);
                break;
        }

        showPlayerCards();
        showDealerCards();

        if (m_playerTotal > m_dealerTotal)
            reportWin();
        else
            reportLose();

    }
    return false;
}

