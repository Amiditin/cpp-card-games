#ifndef BLACKJACK_GAMES_H
#define BLACKJACK_GAMES_H

#include "./Casino/Blackjack/Blackjack.h"
#include "./Casino/Baccarat/Baccarat.h"
#include "./Casino/Seka/Seka.h"
#include "./Klondike/Klondike.h"
#include "./Domino/Domino.h"

enum Games {
    BLACKJACK = 1,
    SEKA,
    BACCARAT,
    KLONDIKE,
    DOMINO,
    MAX_GAMES
};

void playBlackjack();

void playSeka();

void playBaccarat();

int getUserChoice();

int getUserBank();

#endif
