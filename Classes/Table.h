//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_TABLE_H
#define POKER_TABLE_H
#include "Card.h"
#include "Deck.h"
#include <deque>
#include <iostream>

class Table {
public:
    Table();
    Table(int chip);
    void SetCard(Card* card);
    void Print(int n) const;
    void AddChip(int chip);
    int GetChip() const;
    std::deque<Card*> GetDeck();
    void SetDeck(std::deque<Card*> deck);
private:
    int chip;
    std::deque<Card*> tableDeck;
};


#endif //POKER_TABLE_H
