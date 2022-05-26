cmake_minimum_required(VERSION 3.22)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

add_executable(Poker main.cpp Classes/Card.cpp Classes/Card.h Classes/Deck.cpp Classes/Deck.h Classes/Player.cpp Classes/Player.h)
