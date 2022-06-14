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
void Hand::InitializeCards() {
    cards.resize(4);
    for(int i = 0; i < 4; i++)
    {
        cards[i].resize(13);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            cards[i][j] = false;
        }
    }
}

void Hand::FillCards() {
    InitializeCards();
    for(Card* card : handDeck)
    {
        switch (card->GetSuit()) {
            case Card::Suits::HEARTS :
                FillCardsN(card, 0);
                break;
            case Card::Suits::DIAMONDS :
                FillCardsN(card, 1);
                break;
            case Card::Suits::CLUBS :
                FillCardsN(card, 2);
                break;
            case Card::Suits::SPADES :
                FillCardsN(card, 3);
                break;
            case Card::NONE:
                break;
        }
    }
}

void Hand::FillCardsN(Card* card, int n) {
    switch (card->GetRank()) {
        case Card::Ranks::TWO :
            cards[n][0] = true;
            break;
        case Card::Ranks::THREE :
            cards[n][1] = true;
            break;
        case Card::Ranks::FOUR :
            cards[n][2] = true;
            break;
        case Card::Ranks::FIVE :
            cards[n][3] = true;
            break;
        case Card::Ranks::SIX :
            cards[n][4] = true;
            break;
        case Card::Ranks::SEVEN :
            cards[n][5] = true;
            break;
        case Card::Ranks::EIGHT :
            cards[n][6] = true;
            break;
        case Card::Ranks::NINE :
            cards[n][7] = true;
            break;
        case Card::Ranks::TEN :
            cards[n][8] = true;
            break;
        case Card::Ranks::JACK :
            cards[n][9] = true;
            break;
        case Card::Ranks::QUEEN :
            cards[n][10] = true;
            break;
        case Card::Ranks::KING :
            cards[n][11] = true;
            break;
        case Card::Ranks::ACE :
            cards[n][12] = true;
            break;
    }
}

std::vector<std::vector<bool>> Hand::GetCards() {
    return cards;
}

int Hand::GetMaxCardCombo() {
    return maxCardCombo;
}

void Hand::SetMaxCardCombo(int n) {
    maxCardCombo = n;
}
