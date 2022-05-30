//
// Created by retretor on 26.05.2022.
//

#include "Player.h"
#define STANDARD_COUNT_OF_CHIPS 1000

Player::Player() : chip(STANDARD_COUNT_OF_CHIPS), combination(0) {};
Player::Player(int chip) : chip(chip), combination(0) {};
Player::~Player() {
    for(Card* card : playerDeck)
    {
        delete card;
    }
    playerDeck.clear();
}

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
    std::cout << "  Chips: " << chip;
}

void Player::SetABet(int chip, Table *table) {
    if(chip > this->chip) throw std::invalid_argument("Too high a bet");
    AddChip(-chip);
    table->AddChip(chip);
}

std::deque<Card *> Player::GetDeck() {
    return playerDeck;
}

int Player::GetCombination() const{
    return combination;
}

void Player::SetCombination(int c) {
    combination = c;
}

int Player::GetWeight() const {
    if(playerDeck[0]->GetRank() > playerDeck[1]->GetRank())
        return playerDeck[0]->GetRank();
    return playerDeck[1]->GetRank();
}


void Player::SetWin(bool win) {
    isWin = win;
}

bool Player::GetWin() const{
    return isWin;
}
