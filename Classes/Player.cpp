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

void Player::AddChip(int chip) {
    this->chip += chip;
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


std::deque<Card *> Player::GetDeck() {
    return playerDeck;
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



Player::PlayStatus Player::GetPlayStatus() const {
    return playStatus;
}
