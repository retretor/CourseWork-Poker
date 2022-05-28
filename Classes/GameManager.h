//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_GAMEMANAGER_H
#define POKER_GAMEMANAGER_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Table.h"
#include <deque>
#include <iostream>


class GameManager {
public:
    GameManager();
    ~GameManager();
    void CreatePlayers(int countOfPlayers, Deck* deck);
    void CreateTable(Deck* deck);
    void PrintPlayers() const;
    void PrintTable() const;
    void SayHello();
    int GetCountOfPlayers() const;
private:
    int countOfPlayers, maxPlayers = 23;
    std::deque<Player*> players;
    std::deque<Table*> table;
};


#endif //POKER_GAMEMANAGER_H
