#include "Domino.h"

int pack[36][2];
int deck[4][9];
int hand[6][18];
char scdeck[8][26];
char schand[36];
int priority[5][18];
int winflag = -1;
int i, j, k;
int numofpl = 0;
int turn;
int mnum;
int mprior;
int ecard;
int available;

void distribute(int p) {
    int rcard;
    int distcount = 0;
    int distplayercount = 0;
    int disthandplace[6] = {0, 0, 0, 0, 0, 0};
    while(distcount < 36)
    {
        rcard = rand();
        rcard = rcard%36;
        if(pack[rcard][0] == -1)
        {
            hand[distplayercount][disthandplace[distplayercount]] = rcard;
            pack[rcard][0] = distplayercount;
            disthandplace[distplayercount]++;
            distplayercount++;
            distplayercount = distplayercount%p;
            distcount++;
        }
    }
}

void displaydeck() {
    std::cout << "THE DECK\n\n";

    for(i = 0; i < 4; i++)
        for(j = 0; j < 9; j++)
        {
            if(deck[i][j] != -1)
            {
                if(deck[i][j]%9 < 4)
                    scdeck[2*i][3*j] = (char)(deck[i][j]%9 + 48 + 6);
                switch (deck[i][j]%9)
                {
                    case 4: scdeck[2*i][3*j] = 'x'; break;
                    case 5: scdeck[2*i][3*j] = 'J'; break;
                    case 6: scdeck[2*i][3*j] = 'Q'; break;
                    case 7: scdeck[2*i][3*j] = 'K'; break;
                    case 8: scdeck[2*i][3*j] = 'T'; break;
                }

                scdeck[2*i][3*j + 1] = (char)pack[deck[i][j]][1];
            }
        }


    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 26; j++)
            if(scdeck[i][j] == 'x')
                std::cout << "10";
            else
                std::cout << scdeck[i][j];
        std::cout << std::endl;
    }
}

int checkplace(int cardnumber) {

    if(deck[cardnumber/9][cardnumber%9] != -1)
    {
        return 0; //ON DECK
    }
    else
    {
        if(cardnumber%9 == 3)
        {
            return 1; //CAN BE PUTTED
        }
        if(cardnumber%9 < 3) //IF IT'S 6
        {
            if(deck[cardnumber/9][cardnumber%9 + 1] != -1)
            {
                return 1; //CAN BE PUTTED
            }
        }
        if(cardnumber%9 > 3)
        {
            if(deck[cardnumber/9][cardnumber%9 - 1] != -1)
            {
                return 1; //CAN BE PUTTED
            }
        }
        return 2; //CAN NOT
    }
}

void displayhand() {
    for(i = 0; i < 18; i++)
        if(hand[0][i] != -1)
        {
            if(hand[0][i]%9 < 4)
                schand[2*i] = (char)(hand[0][i]%9 + 54);

            switch (hand[0][i]%9)
            {
                case 4: schand[2*i] = 'x'; break;
                case 5: schand[2*i] = 'J'; break;
                case 6: schand[2*i] = 'Q'; break;
                case 7: schand[2*i] = 'K'; break;
                case 8: schand[2*i] = 'T'; break;
            }
            schand[2*i + 1] = (char)pack[hand[0][i]][1];
        }
        else
            schand[2*i] = 'z';

    j = 1;

    for(i = 0; i < (36/numofpl)*2; i++)
    {
        if(i%2 == 0)
        {
            std::cout << j <<". ";
            j++;
        }
        if(schand[i] == 'x')
            std::cout << "10";
        else
        if(schand[i] == 'z')
            std::cout << "--";
        else
        if(schand[i-1] != 'z')
            std::cout << schand[i];
        if (i%2 > 0)
        {
            if(checkplace(hand[0][i/2]) == 1)
            {
                std::cout << "*";
            }

            std::cout << std::endl;
        }
    }

}

void playcard(int pcard) {
    for(i = 0; i < 18; i ++)
        if(hand[turn][i] == pcard)
            hand[turn][i] = -1;
    deck[pcard/9][pcard%9] = pcard;
}

int wincheck() {
    for(i = 0; i < numofpl; i++)
    {
        int ccount = 0;
        for(j = 0; j < 36/numofpl; j++)
        {
            if(hand[i][j] != -1)
                ccount++;
        }
        if(ccount == 0)
            return i;
    }
    return-1;
}

void setpriority(int bot) {
    int typeint[4][2];
    bot = bot-1;
    for(i = 0; i < 4; i++)
    {
        typeint[i][0] = 0;
        typeint[i][1] = 0;
    }

    for(i = 0; i < 36/numofpl; i++)
    {
        if(hand[bot][i]%9 == 0)
        {
            priority[bot][i] = 100;
            typeint[hand[bot][i]/9][0]++;
        }
        else
        if(hand[bot][i]%9 == 8)
        {
            priority[bot][i] = 100;
            typeint[hand[bot][i]/9][1]++;
        }
        else
            priority[bot][i] = hand[bot][i]%9;
    }
    for(i = 0; i < 36; i++)
    {
        if((typeint[i/9][0] > 0)&&(i%9 <= 3))
            priority[bot][i]++;
        if((typeint[1/9][1] > 0)&&(i%9 >= 3))
            priority[bot][i]++;
    }
}

void playDomino() {
    for(i = 0; i < 6; i++)
        for(j = 0; j < 18; j++)
            hand[i][j] = -1;

    while(((numofpl < 2)||(numofpl > 6))||(numofpl == 5))
    {
        system("cls");
        std::cout << "Enter the number of players: ";
        std::cin >> numofpl;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.sync();
        }

    }

    k = 3;
    for(i = 1; i <= 36; i++)
    {
        pack[i-1][0] = -1;
        pack[i-1][1] = k;
        if(i%9 == 0)
        {
            k++;
        }
    }

    for(i = 0; i < 4; i++)
        for(j = 0; j < 9; j++)
            deck[i][j] = -1;

    for(i = 0; i < 8; i++)
        for(j = 0; j < 26; j++)
            scdeck[i][j] = 32;

    distribute(numofpl);

    for(i = 0; i < 18; i++)
        schand[i] = 32;

    for(i = 0; i < numofpl; i++)
    {
        for(j = 0; j < 36/numofpl; j++)
        {
            std::cout << hand[i][j] << " ";
            if(hand[i][j] == 12)
                turn = i;
        }
        std::cout << std::endl;
    }
    std::cout << "Player number " << turn+1 << " starts a game" << std::endl;

    playcard(12);
    system("cls");

    for(k = 1; k < numofpl; k++)
        setpriority(k);


    while(winflag == -1)
    {
        turn = turn%numofpl;
        available = 0;

        for(i = 0; i < 36/numofpl; i++)
            if(checkplace(hand[turn][i]) == 1)
                available++;

        if(available == 0)
            std::cout << "player " << turn+1 << " skips his turn" << std::endl;
        else{
            system("cls");
            displaydeck();
            if(turn == 0)
            {
                displayhand ();
                {
                    std::cout << "Enter the number of card you want to play >> ";
                    while(checkplace(hand[0][ecard]) != 1)
                    {
                        for(j = 0; j < 45; j++)
                            std::cout << "\b";
                        std::cout << "Enter the number of card you want to play >> ";
                        std::cin >> ecard;
                        if(std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.sync();
                        }

                        ecard -= 1;
                    }

                    playcard(hand[0][ecard]);

                    std::cout << "\n\n";
                    system("cls");
                    displaydeck();

                }
            }
            else
            {
                mnum = -1;
                mprior = -1;

                for(i = 0; i < 36/numofpl; i++)
                {
                    if((checkplace(hand[turn][i]) == 1)&&(priority[turn][hand[turn][i]] > mprior))
                    {
                        mprior = priority[turn][hand[turn][i]];
                        mnum = hand[turn][i];
                    }
                }
                playcard(mnum);
                system("cls");
                displaydeck();
            }
        }
        turn++;
        winflag = wincheck();
    }

    std::cout << "\n\nCONGRATULATIONS, PLAYER " << winflag+1 << " WON THE GAME\n\n";
}
