#include "Klondike.h"

void playKlondike()
{
    int PlayArea[20][7]{ 0 };
    int House[4]{ 0 };
    int c[24]{ 0 };
    int seen[7]{ 1,1,1,1,1,1,1 };
    int NumberOfCards[7]{ 1,2,3,4,5,6,7 };
    int SeenOrNot[20][7]{ 0 };
    int i, j, line = 0, column = 1, k = 1, l, RandomNumber, f = 0, cnt;
    char xod[3] = { 0 };
    char start;

    srand(static_cast<unsigned int>(time(0)));
    PlayArea[0][0] = rand() % 52 + 1;
    while (k != 28)
    {
        RandomNumber = rand() % 52 + 1;
        for (j = 0;j < column;++j)
        {
            for (i = 0;i <= j;++i)
            {
                if (RandomNumber == PlayArea[i][j])
                {
                    f = 1;
                }
            }
        }

        for (i = 0;i < line;++i)
        {
            if (RandomNumber == PlayArea[i][j])
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            k += 1;
            PlayArea[line][column] = RandomNumber;
            line += 1;
            if (line > column)
            {
                line = 0;
                column += 1;
            }
        }
        else
        {
            f = 0;
        }
    }
    for (i = 0;i <= 6;++i)
    {
        for (j = 0;j <= 6;++j)
        {
            if (PlayArea[i][j] != 0)
            {
                if (i < j)
                {
                    SeenOrNot[i][j] = 1;
                }
            }
            std::cout << "  ";
        }
        std::cout << '\n';
    }
    k = 0;
    while (k != 24)
    {
        RandomNumber = rand() % 52 + 1;
        for (j = 0;j <= 6;++j)
        {
            for (i = 0;i <= j;++i)
            {
                if (RandomNumber == PlayArea[i][j])
                {
                    f = 1;
                }
            }
        }
        for (i = 0;i <= k;++i)
        {
            if (RandomNumber == c[i])
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            c[k] = RandomNumber;
            k += 1;
        }
        else
        {
            f = 0;
        }
    }
    std::cout << '\n';
    k = 0;
    l = 23;
    std::cout << "_____________________________________WELCOME TO THE KLONDIKE CARD GAME_______________________________________________\n\n";

    std::cout << "_____________________________TO START THE GAME ENTER ANY SYMBOL AND HAVE A GOOD GAME!;)______________________________\n\n";
    std::cin >> start;
    std::cin.ignore(32767,'\n');
    std::cout << "\n\n\n\n\n\n_____________________________________START_____________________________________\n\n";
    while ( House[0] % 13 != 0 ||
            House[1] % 13 != 0 ||
            House[2] % 13 != 0 ||
            House[3] % 13 != 0 ||
            House[0] == 0 ||
            House[1] == 0 ||
            House[2] == 0 ||
            House[3] == 0)
    {
        std::cout << "\n1.ENTER t-c TO TAKE CARD FROM THE REST CARDS_________________________________________________________________________\n" <<
                       "2.ENTER c-h TO PUT CARD FROM REST CARDS INTO HOUSE___________________________________________________________________\n" <<
                       "3.ENTER c-b, WHERE b IS A NUMBER OF COLUMN, TO PUT THE CARD FROM REST CARDS TO THIS COLUMN___________________________\n" <<
                       "4.ENTER a-h, WHERE a IS A NUMBER OF COLUMN, TO PUT THE CARD FROM THIS COLUMN INTO HOUSE______________________________\n" <<
                       "5.ENTER akb, WHERE a IS A NUMBER OF COLUMN, FROM WHICH WE TAKE CARDS, b IS A NUMBER OF COLUMN IN WHICH WE WANT\nTO PUT CARDS AND k IS A NUMBER OF CARDS, THAT WE TAKE, TO PUT k CARDS FROM COLUMN NUMBER a TO COLUMN NUMBER b\n(a=10; b=11; c=12; d=13)_____________________________________________________________________________________________\n" <<
                       "6.ENTER e TO EXIT____________________________________________________________________________________________________\n";

        for (i = 0;i <= 3;++i)
        {
            if (House[i] == 0)
            {
                std::cout << "___  ";
            }
            else
            {
                switch(House[i]%13)
                {
                    case 1: std::cout << " A"; break;
                    case 10: std::cout << "10"; break;
                    case 11: std::cout << " J"; break;
                    case 12: std::cout << " Q"; break;
                    case 0: std::cout << " K"; break;
                    default: std::cout << " " << House[i] % 13; break;
                }
                switch ((House[i] - 1) / 13)
                {
                    case 0: std::cout << '\4'; break;
                    case 1: std::cout << '\3'; break;
                    case 2: std::cout << '\5'; break;
                    case 3: std::cout << '\6'; break;
                }
                std::cout << "  ";
            }
        }
        for (i = 0;i <= 6;++i)
        {
            if ((seen[i] == 0) && (NumberOfCards[i] != 0))
            {
                SeenOrNot[NumberOfCards[i] - 1][i] = 0;
                seen[i] = 1;
            }
        }
        std::cout << "\n\n";
        if (l < 0)
        {
            std::cout << '\n';
        }
        else
        {
            switch (c[k] % 13)
            {
                case 1: std::cout << " A"; break;
                case 10: std::cout << "10"; break;
                case 11: std::cout << " J"; break;
                case 12: std::cout << " Q"; break;
                case 0: std::cout << " K"; break;
                default: std::cout << " " << c[k] % 13; break;
            }
            switch ((c[k] - 1) / 13)
            {
                case 0: std::cout << '\4'; break;
                case 1: std::cout << '\3'; break;
                case 2: std::cout << '\5'; break;
                case 3: std::cout << '\6'; break;
            }
            std::cout << "  ";
        }
        std::cout <<"Cards left: "<<l+1<< '\n' << '\n';
        std::cout << "_0_  _1_  _2_  _3_  _4_  _5_  _6_" << "\n\n";
        for (i = 0;i <= 19;++i)
        {
            for (j = 0;j <= 6;++j)
            {
                if (PlayArea[i][j] == 0)
                {
                    std::cout << "   ";
                }
                else
                {
                    if (SeenOrNot[i][j] == 1)
                    {
                        std::cout << "///";
                    }
                    else
                    {
                        switch (PlayArea[i][j] % 13)
                        {
                            case 1: std::cout << " A"; break;
                            case 10: std::cout << "10"; break;
                            case 11: std::cout << " J"; break;
                            case 12: std::cout << " Q"; break;
                            case 0: std::cout << " K"; break;
                            default: std::cout << " " << PlayArea[i][j] % 13; break;
                        }
                        switch ((PlayArea[i][j] - 1) / 13)
                        {
                            case 0: std::cout << '\4'; break;
                            case 1: std::cout << '\3'; break;
                            case 2: std::cout << '\5'; break;
                            case 3: std::cout << '\6'; break;
                        }
                    }
                }
                std::cout << "  ";
            }
            std::cout << '\n';
        }

        while (true)
        {
            std::cout << "Your action:";
            std::cin >> xod[0];
            if (xod[0] == 'e')
                return;

            std::cin >> xod[1] >> xod[2];
            std::cin.ignore(32767, '\n');


            if (xod[0] && xod[1] && xod[2])
                break;
            std::cout << "Please try again.\n";
        }

        if ((xod[0] == 't') && (xod[1] == '-') && (xod[2] == 'c'))
        {
            if (k == l)
            {
                k = 0;
            }
            else
            {
                k += 1;
            }
        }
        for (i = 1;i <= 30;++i)
        {
            std::cout << '\n';
        }
        if ((xod[0] == 'c') && (xod[1] == '-') && (xod[2] == 'h'))
        {
            i = (c[k] - 1) / 13;
            if ((House[i] % 13 == c[k] % 13 - 1) || ((House[i] % 13 == 12) && (c[k] % 13 == 0)&&(c[k]!=0)))
            {
                House[i] = c[k];
                c[k] = 0;
                for (j = k;j <= l - 1;++j)
                {
                    c[j] = c[j + 1];
                }
                l -= 1;
            }
            k -= 1;
            if (k == -1)
            {
                k = 1;
            }
        }
        else if ((xod[0] == 'c') && (xod[1] == '-') && ((int)xod[2] >= 48) && ((int)xod[2] <= 54))
        {
            if (((((((c[k] % 13) + 1 == PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13) || ((c[k] % 13) + 1 == 13) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 == 0)))) && (((c[k] >= 1) && (c[k] <= 26) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 52)) || ((PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 26) && (c[k] >= 27) && (c[k] <= 52)))) || ((c[k] % 13 == 0) && (NumberOfCards[(int)xod[2] - 48] == 0)))
            {
                PlayArea[NumberOfCards[(int)xod[2] - 48]][(int)xod[2] - 48] = c[k];
                c[k] = 0;
                seen[(int)xod[2] - 48] += 1;
                NumberOfCards[(int)xod[2] - 48] += 1;
                for (j = k;j <= l - 1;++j)
                {
                    c[j] = c[j + 1];
                }
                l -= 1;
                k -= 1;
                if (k == -1)
                {
                    k = 0;
                }
            }
        }

        if ((int)xod[0] >= 48 &&
            (int)xod[0] <= 54 &&
            (((int)xod[1] >= 49 && (int)xod[1] <= 57) || ((int)xod[1] >= 97 && (int)xod[1] <= 100)) &&
            (int)xod[2] >= 48 &&
            (int)xod[2] <= 54)
        {
            if (((int)xod[1] >= 49) && ((int)xod[1] <= 57))
            {
                if (seen[(int)xod[0] - 48] > (int)xod[1] - 48)
                {
                    if (seen[(int)xod[0] - 48] >= ((int)xod[1] - 48))
                    {
                        if (((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13 + 1 == PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 ||
                            PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13 + 1 == 13 &&
                            PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 == 0) &&
                            ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] >= 1 &&
                            PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] <= 26 &&
                            PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 27 &&
                            PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 52) ||
                            (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 1 &&
                            PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 26 &&
                            PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] >= 27 &&
                            PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] <= 52))) ||
                            (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13 == 0 &&
                            NumberOfCards[(int)xod[2] - 48] == 0))
                        {
                            for (i = 1;i <= (int)xod[1] - 48;++i)
                            {
                                PlayArea[NumberOfCards[(int)xod[2] - 48] - 1 + i][(int)xod[2] - 48] = PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48) + i - 1][(int)xod[0] - 48];
                                PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48) + i - 1][(int)xod[0] - 48] = 0;
                            }
                            seen[(int)xod[0] - 48] -= ((int)xod[1] - 48);
                            seen[(int)xod[2] - 48] += ((int)xod[1] - 48);
                            NumberOfCards[(int)xod[0] - 48] -= ((int)xod[1] - 48);
                            NumberOfCards[(int)xod[2] - 48] += ((int)xod[1] - 48);
                        }
                    }
                }
                else if (seen[(int)xod[0] - 48] == (int)xod[1] - 48)
                {
                    if (seen[(int)xod[0] - 48] >= ((int)xod[1] - 48))
                    {
                        if ((((((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13) + 1 == PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13) + 1 == 13) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 == 0))) && (((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 52)) || ((PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] <= 52)))) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48)][(int)xod[0] - 48] % 13 == 0) && (NumberOfCards[(int)xod[2] - 48] == 0)))
                        {
                            for (i = 1;i <= (int)xod[1] - 48;++i)
                            {
                                PlayArea[NumberOfCards[(int)xod[2] - 48] - 1 + i][(int)xod[2] - 48] = PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48) + i - 1][(int)xod[0] - 48];
                                PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48) + i - 1][(int)xod[0] - 48] = 0;
                            }
                            seen[(int)xod[0] - 48] -= ((int)xod[1] - 48);
                            seen[(int)xod[2] - 48] += ((int)xod[1] - 48);
                            NumberOfCards[(int)xod[0] - 48] -= ((int)xod[1] - 48);
                            NumberOfCards[(int)xod[2] - 48] += ((int)xod[1] - 48);
                            SeenOrNot[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 48) + i - 1][(int)xod[0] - 48] = 0;
                        }
                    }
                }
            }
            if (((int)xod[1] >= 97) && ((int)xod[1] <= 100))
            {
                if (seen[(int)xod[0] - 48] > (int)xod[1] - 87)
                {
                    if (seen[(int)xod[0] - 48] >= ((int)xod[1] - 87))
                    {
                        if (((((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13) + 1 == PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13) + 1 == 13) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 == 0)) && (((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 52)) || ((PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] <= 52)))) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13 == 0) && (NumberOfCards[(int)xod[2] - 48] == 0)))
                        {
                            for (i = 1;i <= (int)xod[1] - 87;++i)
                            {
                                PlayArea[NumberOfCards[(int)xod[2] - 48] - 1 + i][(int)xod[2] - 48] = PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87) + i - 1][(int)xod[0] - 48];
                                PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87) + i - 1][(int)xod[0] - 48] = 0;
                            }
                            seen[(int)xod[0] - 48] -= ((int)xod[1] - 87);
                            seen[(int)xod[2] - 48] += ((int)xod[1] - 87);
                            NumberOfCards[(int)xod[0] - 48] -= ((int)xod[1] - 87);
                            NumberOfCards[(int)xod[2] - 48] += ((int)xod[1] - 87);
                        }
                    }
                }
                else if (seen[(int)xod[0] - 48] == (int)xod[1] - 87)
                {
                    if (seen[(int)xod[0] - 48] >= ((int)xod[1] - 87))
                    {
                        if ((((((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13) + 1 == PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13) + 1 == 13) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] % 13 == 0))) && (((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 52)) || ((PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] >= 1) && (PlayArea[NumberOfCards[(int)xod[2] - 48] - 1][(int)xod[2] - 48] <= 26) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] >= 27) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] <= 52)))) || ((PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87)][(int)xod[0] - 48] % 13 == 0) && (NumberOfCards[(int)xod[2] - 48] == 0)))
                        {
                            for (i = 1;i <= (int)xod[1] - 87;++i)
                            {
                                PlayArea[NumberOfCards[(int)xod[2] - 48] - 1 + i][(int)xod[2] - 48] = PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87) + i - 1][(int)xod[0] - 48];
                                PlayArea[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87) + i - 1][(int)xod[0] - 48] = 0;
                            }
                            seen[(int)xod[0] - 48] -= ((int)xod[1] - 87);
                            seen[(int)xod[2] - 48] += ((int)xod[1] - 87);
                            NumberOfCards[(int)xod[0] - 48] -= ((int)xod[1] - 87);
                            NumberOfCards[(int)xod[2] - 48] += ((int)xod[1] - 87);
                            SeenOrNot[NumberOfCards[(int)xod[0] - 48] - ((int)xod[1] - 87) + i - 1][(int)xod[0] - 48] = 0;
                        }
                    }
                }
            }
        }
        else if (((int)xod[0] >= 48) && ((int)xod[0] <= 54) && (xod[1] == '-') && (xod[2] == 'h'))
        {
            i = (PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48] - 1) / 13;
            if (((House[i] % 13 == PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48] % 13 - 1) || ((House[i] % 13 == 12) && (PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48] % 13 == 0)&& (PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48] != 0))))
            {
                House[i] = PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48];
                PlayArea[NumberOfCards[(int)xod[0] - 48] - 1][(int)xod[0] - 48] = 0;
                if (seen[(int)xod[0] - 48] == 1)
                {
                    seen[(int)xod[0] - 48] -= 1;
                    NumberOfCards[(int)xod[0] - 48] -= 1;
                }
                else
                {
                    seen[(int)xod[0] - 48] -= 1;
                    NumberOfCards[(int)xod[0] - 48] -= 1;
                }
            }
        }

    }
    for (i = 1;i <= 30;++i)
    {
        std::cout << '\n';
    }
    std::cout << "_____________________________________VICTORY_____________________________________"<<"\n";
}