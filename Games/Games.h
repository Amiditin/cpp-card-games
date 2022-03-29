#ifndef BLACKJACK_GAMES_H
#define BLACKJACK_GAMES_H

#include <iostream>

enum Games {
    BLACKJACK = 1,
    SEKA,
    BACCARAT,
    MAX_GAMES
};

int getUserChoice()
{
    while (true)
    {
        int choice;
        std::cin >> choice;

        if (std::cin.fail() || choice < 0 || choice >= Games::MAX_GAMES)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "\nUnfortunately, you entered an incorrect number.  Please try again.\n\n";
            std::cout << "Please choose a game:\n (1) to Blackjack\n (2) to Something\n (0) to Exit\n Your choice:";
        }
        else
        {
            std::cin.ignore(32767,'\n');

            if (choice == 0)
                return Games::MAX_GAMES;

            return choice;
        }
    }
}

int getUserBank()
{
    std::cout << "How much money do you want to deposit to your bank?\n";

    while (true)
    {
        std::cout << "Please enter the amount: ";
        int bank;
        std::cin >> bank;

        if (std::cin.fail() || bank < 0)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "\nUnfortunately, you entered an incorrect number.  Please try again.\n\n";
        }
        else
        {
            std::cin.ignore(32767,'\n');
            std::cout << std::endl;

            return bank;
        }
    }
}

#endif
