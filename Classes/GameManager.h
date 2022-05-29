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
#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>


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
    std::vector<std::vector<std::string>> Combinations_vector{
            {"1R", "0R", "0R", "0R", "0R"}, //HIGH_CARD      +
            {"1R", "1R", "0R", "0R", "0R"}, //PAIR           +
            {"1R", "1R", "2R", "2R", "0R"}, //TWO_PAIR       +
            {"1R", "1R", "1R", "0R", "0R"}, //THREE_OF_A_KIND+
            {"1R", "2R", "3R", "4R", "5R"}, //STRAIGHT       +
            {"0A", "0A", "0A", "0A", "0A"}, //FLUSH          +
            {"1R", "1R", "2R", "2R", "2R"}, //FULL_HOUSE     +
            {"1R", "1R", "1R", "1R", "0R"}, //FOUR_OF_A_KIND +
            {"1A", "2A", "3A", "4A", "5A"}, //STRAIGHT_FLUSH +
            {"6A", "7A", "8A", "9A", "10A"} //ROYAL_FLUSH    +
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
    void CreateHand();
    void PrintHand();
    void PlayerHasCombo();
private:
    int countOfPlayers, maxPlayers = 23;
    std::deque<Player*> players;
    std::deque<Table*> table;
    std::deque<Hand*> hand;
};


#endif //POKER_GAMEMANAGER_H
