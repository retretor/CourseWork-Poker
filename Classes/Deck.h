//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include "Card.h"

#include <deque>

class Deck {
public:
    Deck();
    ~Deck();
    void Print() const;
    void Shuffle();
    Card* TopCard() const;
    void PopCard();
private:
    std::deque<Card*> deck;
};


#endif //POKER_DECK_H
