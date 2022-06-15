//
// Created by retretor on 29.05.2022.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H
#include "Card.h"
#include "Deck.h"
#include <deque>
#include <iostream>
#include <vector>

class Hand {
public:
    Hand();
    void Print() const;
    void SetCard(Card* card);

    void SetComboType(int type);
    int GetComboType();

    void FillCards();
    std::vector<std::vector<bool>> GetCards();

    void SetMaxCardCombo(int n);
    int GetMaxCardCombo();
private:
    std::deque<Card*> handDeck;

    //
    std::deque<bool> cardsInCombo;
    //

    std::deque<Card*> play_hand;
    int comboType;

    std::vector<std::vector<bool>> cards;
    void InitializeCards();
    void FillCardsN(Card* card, int n);
    int maxCardCombo;
};


#endif //POKER_HAND_H
