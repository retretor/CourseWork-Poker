//
// Created by retretor on 29.05.2022.
//

#include "Hand.h"

Hand::Hand() {};
Hand::~Hand() {
    for(Card* card : handDeck)
    {
        delete card;
    }
    handDeck.clear();
}

void Hand::Print() const {
    for(Card* card : handDeck)
    {
        card->Print();
        std::cout << " ";
    }
}

void Hand::SetCard(Card *card) {
    handDeck.push_back(card);
}

std::deque<Card *> Hand::GetDeck() {
    return handDeck;
}

Card::Ranks Hand::GetCardRank(int itter) const{
    return handDeck[itter]->GetRank();
}

void Hand::SetCardInCombo(int i, bool value) {
    cardsInCombo[i] = value;
}

bool Hand::GetCardInCombo(int i) const {
    return cardsInCombo[i];
}
void Hand::SetPlayHand(std::deque<Card*> hand) {
    play_hand = hand;
}

std::deque<Card *> Hand::GetPlayHand() {
    return play_hand;
}

void Hand::SetComboType(int type) {
    comboType = type;
}

int Hand::GetComboType() {
    return comboType;
}

void Hand::SetDeck(std::deque<Card*> deck) {
    handDeck = deck;
}

Card *Hand::GetMaxCard() {
    return maxCard;
}

void Hand::SetMaxCard(Card *card) {
    maxCard = card;
}
