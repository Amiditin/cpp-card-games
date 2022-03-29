#include <iostream>
#include <ctime>

#include "./Errors.h"

#include "./Deck/Deck.h"
#include "./Games/Games.h"
#include "./Games/Blackjack/Blackjack.h"
#include "./Games/Seka/Seka.h"
#include "./Games/Baccarat/Baccarat.h"

void playBlackjack()
{
    Blackjack blackjack(getUserBank());
    while (blackjack.playGame()) {}
}

void playSeka()
{
    Seka seka(getUserBank());
    while (seka.playGame()) {}
}

void playBaccarat()
{
    Baccarat baccarat;
    while (baccarat.playGame()) {}
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    while (true)
    {
        std::cout << "Please choose a game:\n";
        std::cout << "(1) to Blackjack\n";
        std::cout << "(2) to Seka\n";
        std::cout << "(3) to Baccarat (not working yet)\n";
        std::cout << "(0) to Exit\n";
        std::cout << "Your choice:";

        int choice = getUserChoice();

        std::cout << std::endl;
        std::cout << "Loading...";
        std::cout << std::endl << std::endl;

        switch (static_cast<Games>(choice))
        {
            case BLACKJACK: playBlackjack();    continue;
            case SEKA:      playSeka();         continue;
            case BACCARAT:                      continue;
            case MAX_GAMES:
                std::cout << "Exit.\n";
                return 0;
            default:
                std::cout << "ERROR INCORRECT_CHOICE. " << static_cast<Games>(choice) << std::endl;
                return Errors::INCORRECT_CHOICE;
        }
    }
}