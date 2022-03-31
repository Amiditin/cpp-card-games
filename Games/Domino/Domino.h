#ifndef CPP_CARD_GAMES_DOMINO_H
#define CPP_CARD_GAMES_DOMINO_H

#include <iostream>
#include <cstdlib>
#include <ctime>

void distribute (int p);

void displaydeck (int pwarning);

int checkplace (int cardnumber);

void displayhand (int phand);

void playcard (int pcard);

int wincheck ();

void setpriority(int bot);

void playDomino();



#endif
