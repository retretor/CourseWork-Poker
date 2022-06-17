//
// Created by retretor on 29.05.2022.
//

#ifndef POKER_COMBINATION_H
#define POKER_COMBINATION_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Table.h"
#include "Hand.h"
#include <deque>
#include <iostream>
#include <vector>
#include <string>


class Combination {
public:
    int ParseCombination(std::vector<std::vector<bool>> deck);
    int GetComboType();
private:
    int ParseRoyalFlush(std::vector<std::vector<bool>> deck);
    int ParseStraightFlush(std::vector<std::vector<bool>> deck);
    int ParseFourOfAKind(std::vector<std::vector<bool>> deck);
    int ParseFullHouse(std::vector<std::vector<bool>> deck);
    int ParseFlush(std::vector<std::vector<bool>> deck);
    int ParseStraight(std::vector<std::vector<bool>> deck);
    int ParseThreeOfAKind(std::vector<std::vector<bool>> deck);
    int ParseTwoPair(std::vector<std::vector<bool>> deck);
    int ParseOnePair(std::vector<std::vector<bool>> deck);
    int ParseHighCard(std::vector<std::vector<bool>> deck);

    int comboType;
    int max_card_in_combo;

};


#endif //POKER_COMBINATION_H
