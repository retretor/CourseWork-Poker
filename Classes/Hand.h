//
// Created by retretor on 29.05.2022.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H
#include "Card.h"
#include "Deck.h"
#include <deque>
#include <iostream>

class Hand {
public:
    Hand();
    ~Hand();
    void Print() const;
    void SetCard(Card* card);
    std::deque<Card*> GetDeck();
private:
    std::deque<Card*> handDeck;
};


#endif //POKER_HAND_H
