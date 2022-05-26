//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_TABLE_H
#define POKER_TABLE_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <deque>
#include <iostream>

class Table : public Player {
public:
    Table();
    ~Table();
    Table(int chip);
    void SetCard(Card* card) override;
    void Print() const override;

private:
    std::deque<Card*> tableDeck;
};


#endif //POKER_TABLE_H
