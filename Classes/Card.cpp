//
// Created by retretor on 26.05.2022.
//

#include "Card.h"
#include <iostream>

Card::Card(Suits suit, Ranks rank) : suit(suit), rank(rank) {};

Card::Suits Card::GetSuit() const {
    return suit;
}

Card::Ranks Card::GetRank() const {
    return rank;
}

void Card::Print() const {
    if(rank <= TEN)
        std::cout << rank;
    else if(rank == JACK)
        std::cout << "J";
    else if(rank == QUEEN)
        std::cout << "Q";
    else if(rank == KING)
        std::cout << "K";
    else
        std::cout << "A";

    if(suit == HEARTS)
        std::cout << "H" << " ";
    else if(suit == DIAMONDS)
        std::cout << "D" << " ";
    else if(suit == CLUBS)
        std::cout << "C" << " ";
    else
        std::cout << "S" << " ";
}

bool Card::GetIsOnCombination() {
    return IsOnCombination;
}

void Card::SetIsOnCombination(bool value) {
    IsOnCombination = value;
}

void Card::SetSuit(Card::Suits suit) {
    this->suit = suit;
}

void Card::SetRank(Card::Ranks rank) {
    this->rank = rank;
}
