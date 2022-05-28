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
