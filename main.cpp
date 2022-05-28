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

    try
    {
        Deck deck;
        deck.Shuffle();
        deck.Print();
        std::cout << std::endl;

        GameManager game;
        game.CreatePlayers(game.GetCountOfPlayers(), &deck);
        std::cout << std::endl;

        game.PrintPlayers();
        std::cout << std::endl;


        game.CreateTable(&deck);
        game.PrintTable();
        std::cout << std::endl;
        std::cout << std::endl;


        deck.Print();
        std::cout << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cerr << "Error: ";
        std::cerr << ex.what();
    }
    return 0;
}