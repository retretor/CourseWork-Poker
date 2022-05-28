//
// Created by retretor on 26.05.2022.
//

#include "Deck.h"
#include <iostream>
#include <random>
#include <chrono>

Deck::Deck() : deck() {
    for(Card::Ranks r = Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1))
    {
        for(Card::Suits s = Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1))
        {
            deck.push_front(new Card(s, r));
        }
    }
}

Deck::~Deck() {
    for(Card* card : deck)
    {
        delete card;
    }
    deck.clear();
}

void Deck::Print() const {
    std::cout << "Deck is: ";
    for(Card* card : deck)
    {
        card->Print();
        std::cout << " ";
    }
}

void Deck::Shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

Card* Deck::TopCard() const {
    return deck.front();
}

void Deck::PopCard() {
    deck.push_back(deck.front());
    deck.erase(deck.begin());
}
