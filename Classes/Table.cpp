//
// Created by retretor on 26.05.2022.
//

#include "Table.h"
Table::~Table() {
    for(Card* card : tableDeck)
    {
        delete card;
    }
    tableDeck.clear();
}

Table::Table() : chip(0) {
}

Table::Table(int chip) : chip(chip) {

}
void Table::Print() const {
    for(Card* card : tableDeck)
    {
        card->Print();
        std::cout << " ";
    }
    std::cout << "  Chips: " << chip;
    std::cout << std::endl;
}
void Table::SetCard(Card* card) {
    tableDeck.push_back(card);
}

void Table::AddChip(int chip) {
    this->chip += chip;
}

std::deque<Card *> Table::GetDeck() {
    return tableDeck;
}
