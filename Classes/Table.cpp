//
// Created by retretor on 26.05.2022.
//

#include "Table.h"

Table::Table() : chip(0) {
}

Table::Table(int chip) : chip(chip) {

}
void Table::Print(int n) const {
    if(n == 1)
    {
        for(int i = 0; i < 5; i++)
        {
            std::cout << "** ";
        }
        std::cout << std::endl;
        int a;
        std::cout << "If you ready to bet, enter any number: ";
        std::cin >> a;
    }
    else if(n == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            tableDeck[i]->Print();
            std::cout << " ";
        }
        std::cout << "** **" << std::endl;
        int a;
        std::cout << "If you ready to bet, enter any number: ";
        std::cin >> a;
    }
    else if(n == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            tableDeck[i]->Print();
            std::cout << " ";
        }
        std::cout << "**" << std::endl;
        int a;
        std::cout << "If you ready to bet, enter any number: ";
        std::cin >> a;
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            tableDeck[i]->Print();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Chips: " << chip;
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

int Table::GetChip() const {
    return chip;
}

void Table::SetDeck(std::deque<Card *> deck) {
    tableDeck = deck;
}
