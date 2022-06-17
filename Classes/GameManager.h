//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_GAMEMANAGER_H
#define POKER_GAMEMANAGER_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Table.h"
#include "Hand.h"
#include "Combination.h"
#include "PlayerHuman.h"
#include "PlayerComputer.h"


#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>


class GameManager {
public:
    GameManager();
    ~GameManager();
    void CreatePlayers(Deck* deck);
    void CreateTable(Deck* deck);
    void Result();
    int GetCountOfPlayers() const;
    int SetABet();
    void CreateHand();
    void PlayerHasCombo();
    void SetCountOfPlayers();
    void PrintPlayers() const;
    void PrintTable(int n) const;
private:
    int countOfPlayersHuman, countOfPlayersBots;
    const int maxPlayers = 22;
    const int minBots = 0;
    std::deque<Player*> players;
    Table* table;
    std::deque<Hand*> hand;
};


#endif //POKER_GAMEMANAGER_H
