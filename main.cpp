#include "./Errors.h"
#include "./Games/Games.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));


    while (true)
    {
        std::cout << "Please choose a game:\n"  <<
                     "(1) to Blackjack\n"       <<
                     "(2) to Seka\n"            <<
                     "(3) to Baccarat\n"        <<
                     "(4) to Klondike\n"        <<
                     "(5) to Domino\n"          <<
                     "(0) to Exit\n"            <<
                     "Your choice:";

        int choice = getUserChoice();

        std::cout << "\nLoading...\n\n";

        switch (static_cast<Games>(choice))
        {
            case BLACKJACK: playBlackjack();    continue;
            case SEKA:      playSeka();         continue;
            case BACCARAT:  playBaccarat();     continue;
            case KLONDIKE:  playKlondike();     continue;
            case DOMINO:    playDomino();       continue;
            case MAX_GAMES:
                std::cout << "Exit.\n";
                return 0;
            default:
                std::cout << "ERROR INCORRECT_CHOICE. " << static_cast<Games>(choice) << std::endl;
                return Errors::INCORRECT_CHOICE;
        }
    }
}