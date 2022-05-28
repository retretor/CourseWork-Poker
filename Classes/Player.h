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
    void Print() const;
    void SetABet(int chip, Table* table);
private:
    int chip;
    std::deque<Card*> playerDeck;
};


#endif //POKER_PLAYER_H
