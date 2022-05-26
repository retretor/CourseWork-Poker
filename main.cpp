#include <iostream>
#include "./Classes/Card.h"
#include "./Classes/Deck.h"
#include "./Classes/Player.h"
#include "./Classes/Table.h"
#include "./Classes/GameManager.h"


int main() {
//create players, deck & table
    //std::cout << "How many players will play? ";
    //std::cin >> countOfPlayers;

    Deck deck;
    deck.Shuffle();
    deck.Print();
    std::cout << std::endl;

    GameManager game;
    game.CreatePlayers(3, &deck);
    std::cout << std::endl;

    game.PrintPlayers();
    std::cout << std::endl;


    Table table;
    for(int i = 0; i < 5; i++)
    {
        table.SetCard(deck.TopCard());
        deck.PopCard();
    }
    table.Print();
    std::cout << std::endl;
    std::cout << std::endl;


    deck.Print();
    std::cout << std::endl;

    return 0;
}