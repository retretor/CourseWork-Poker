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
    enum PlayStatus {
        FOLD,
        CHECK,
        RAISE
    };
    Player();
    Player(int chip);
    void AddChip(int chip);
    void SetCard(Card* card);
    std::deque<Card*> GetDeck();
    void Print() const;
    int GetWeight() const;
    void SetWin(bool win);
    bool GetWin() const;


    virtual int SetABet(Table* table, int min_bet) = 0;
    PlayStatus GetPlayStatus() const;
protected:
    int chip;
    bool isWin;
    std::deque<Card*> playerDeck;


    PlayStatus playStatus;
};


#endif //POKER_PLAYER_H
