//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include "Card.h"
#include "Deck.h"
#include "Table.h"
#include <deque>
#include <iostream>

class Player {
public:
    Player();
    ~Player();
    Player(int chip);
    int GetChip() const;
    void SetChip(int chip);
    void AddChip(int chip);
    void SetCard(Card* card);
    std::deque<Card*> GetDeck();
    void Print() const;
    void SetABet(int chip, Table* table);
    int GetCombination() const;
    void SetCombination(int c);
    int GetWeight() const;
    void SetWin(bool win);
    bool GetWin() const;

private:
    int chip, combination;
    bool isWin;
    std::deque<Card*> playerDeck;
};


#endif //POKER_PLAYER_H
