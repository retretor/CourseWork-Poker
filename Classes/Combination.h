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
    std::deque<Card*> ParseCombination(std::deque<Card*> deck);
    int GetComboType();
private:
    int ParseRoyalFlush(std::deque<Card *> deck, int rank);
    int ParseStraightFlush(std::deque<Card *> deck, int rank);
    int ParseFourOfAKind(std::deque<Card *> deck);
    int ParseFullHouse(std::deque<Card *> deck);
    int ParseFlush(std::deque<Card *> deck);
    int ParseFlush(std::deque<Card *> deck, int suit);
    int ParseStraight(std::deque<Card *> deck);
    int ParseThreeOfAKind(std::deque<Card *> deck);
    int ParseTwoPair(std::deque<Card *> deck);
    int ParseOnePair(std::deque<Card *> deck);
    int ParseHighCard(std::deque<Card *> deck);


    std::deque<Card*> combination;

    bool switcher = false;
    int start_rank;
    int comboType;
};


#endif //POKER_COMBINATION_H
