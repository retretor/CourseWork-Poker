//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_PLAYERHUMAN_H
#define POKER_PLAYERHUMAN_H

#include "Player.h"



class PlayerHuman : public Player {
public:
    PlayerHuman() : Player() { playStatus = CHECK;};

    int SetABet(Table* table, int min_bet) override;

private:
    void Raise(Table *table, int chip);
};


#endif //POKER_PLAYERHUMAN_H
