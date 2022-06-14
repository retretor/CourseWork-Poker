cmake_minimum_required(VERSION 3.22)
project(Poker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Poker main.cpp Classes/Card.cpp Classes/Card.h Classes/Deck.cpp Classes/Deck.h Classes/Player.cpp Classes/Player.h Classes/PlayerHuman.cpp Classes/PlayerHuman.h Classes/Table.cpp Classes/Table.h Classes/GameManager.cpp Classes/GameManager.h Classes/Hand.cpp Classes/Hand.h Classes/Combination.cpp Classes/Combination.h Classes/Game.cpp Classes/Game.h Classes/PlayerComputer.cpp Classes/PlayerComputer.h)
