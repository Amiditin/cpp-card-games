cmake_minimum_required(VERSION 3.21)
project(cpp_card_games)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_card_games main.cpp Card/Card.cpp Card/Card.h Deck/Deck.cpp Deck/Deck.h Games/Blackjack/Blackjack.cpp Games/Blackjack/Blackjack.h Errors.h Games/Games.h Betting/Betting.cpp Betting/Betting.h Games/Seka/Seka.cpp Games/Seka/Seka.h Games/Baccarat/Baccarat.cpp Games/Baccarat/Baccarat.h)
