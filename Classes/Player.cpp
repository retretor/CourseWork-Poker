//
// Created by retretor on 26.05.2022.
//

#include "Player.h"
#define STANDARD_COUNT_OF_CHIPS 1000

Player::Player() : chip(STANDARD_COUNT_OF_CHIPS) {};
Player::Player(int chip) : chip(chip) {};

int Player::GetChip() const {
    return chip;
}
void Player::AddChip(int chip) {
    this->chip += chip;
}
void Player::SetChip(int chip) {
    this->chip = chip;
}

void Player::SetCard(Card* card) {
    playerDeck.push_back(card);
}


void Player::Print() const {
    for(Card* card : playerDeck)
    {
        card->Print();
        std::cout << " ";
    }
}

Player::~Player() {
    for(Card* card : playerDeck)
    {
        delete card;
    }
    playerDeck.clear();
}
