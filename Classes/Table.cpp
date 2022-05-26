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

Table::Table() : Player() {

}

Table::Table(int chip) : Player(chip) {

}
void Table::Print() const {
    for(Card* card : tableDeck)
    {
        card->Print();
        std::cout << " ";
    }
}
void Table::SetCard(Card* card) {
    tableDeck.push_back(card);
}