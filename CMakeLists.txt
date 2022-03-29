cmake_minimum_required(VERSION 3.21)
project(cpp_card_games)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        cpp_card_games
        main.cpp
        Errors.h
        Card/Card.cpp
        Card/Card.h
        Deck/Deck.cpp
        Deck/Deck.h
        Games/Games.cpp
        Games/Games.h
        Games/Casino/Casino.cpp
        Games/Casino/Casino.h
        Games/Casino/Blackjack/Blackjack.cpp
        Games/Casino/Blackjack/Blackjack.h
        Games/Casino/Baccarat/Baccarat.cpp
        Games/Casino/Baccarat/Baccarat.h
        Games/Casino/Seka/Seka.cpp
        Games/Casino/Seka/Seka.h
)
