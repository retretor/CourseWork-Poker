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
    enum Combinations
    {
        HIGH_CARD,
        PAIR,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH,
        ROYAL_FLUSH
    };
    GameManager();
    ~GameManager();
    void CreatePlayers(int countOfPlayers, Deck* deck);
    void CreateTable(Deck* deck);
    void PrintPlayers() const;
    void PrintTable() const;
    void Play();
    void Result();
    void SayHello();
    int GetCountOfPlayers() const;
    void SetABet();
private:
    int countOfPlayers, maxPlayers = 23;
    std::deque<Player*> players;
    std::deque<Table*> table;
};


#endif //POKER_GAMEMANAGER_H
