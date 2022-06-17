//
// Created by retretor on 29.05.2022.
//

#include "Hand.h"

Hand::Hand() : comboType(1){};

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

void Hand::SetComboType(int type) {
    comboType = type;
}

int Hand::GetComboType() {
    return comboType;
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
