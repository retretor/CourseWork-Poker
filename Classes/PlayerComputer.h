//
// Created by retretor on 13.06.2022.
//

#ifndef POKER_PLAYERCOMPUTER_H
#define POKER_PLAYERCOMPUTER_H
#include "Player.h"


class PlayerComputer : public Player {
public:
    PlayerComputer() : Player() { playStatus = CHECK;};

    int SetABet(Table* table, int min_bet) override;

private:
    void Raise(Table *table, int chip);
};


#endif //POKER_PLAYERCOMPUTER_H
