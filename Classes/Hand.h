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
    ~Hand();
    void Print() const;
    void SetCard(Card* card);
    std::deque<Card*> GetDeck();
    void SetDeck(std::deque<Card*> deck);
    Card::Ranks GetCardRank(int itter) const;
    void SetCardInCombo(int i, bool value);
    bool GetCardInCombo(int i) const;

    void SetPlayHand(std::deque<Card*> hand);

    std::deque<Card*> GetPlayHand();
    void SetComboType(int type);
    int GetComboType();

    void SetMaxCard(Card* card);
    Card* GetMaxCard();

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

    Card* maxCard;

    std::vector<std::vector<bool>> cards;
    void InitializeCards();
    void FillCardsN(Card* card, int n);
    int maxCardCombo;
};


#endif //POKER_HAND_H
