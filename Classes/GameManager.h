//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_GAMEMANAGER_H
#define POKER_GAMEMANAGER_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <deque>
#include <iostream>


class GameManager {
public:
    GameManager();
    ~GameManager();
    void CreatePlayers(int countOfPlayers, Deck* deck);
    void PrintPlayers();
private:
    int countOfPlayers;
    std::deque<Player*> players;
};


#endif //POKER_GAMEMANAGER_H
